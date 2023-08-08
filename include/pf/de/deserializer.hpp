/*
MIT License

Copyright (c) 2023 mindstab <zeropolyz@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <concepts>
#include <expected>
#include <memory>
#include <optional>
#include <span>
#include <string>
#include <vector>
#include <cstring>

#include "pf/de/error.hpp"
#include "pf/types.hpp"

namespace pf::de {

template <typename Config>
class Deserializer {
 public:
  template <typename Type>
  [[nodiscard]] static Result<Type> Parse(std::span<const std::byte> buf,
                                          bool b64) {
    Deserializer de{buf, 0, b64};
    Type value = {};
    de(value);
    if (de.error_) {
      return std::unexpected(*de.error_);
    }
    return value;
  }

  template <typename Type>
  void operator()(Type& value) {
    if constexpr (Config::CHECK_FOR_ERRORS) {
      if (error_) {
        return;
      }
    }
    Read(value);
  }

 private:
  Deserializer(std::span<const std::byte> buf, size_t position,
               bool b64) noexcept
      : buf_(buf), position_(position), b64_(b64) {}

  template <typename Type>
  void Read(Type& value) noexcept
    requires(std::integral<Type> || std::floating_point<Type>)
  {
    auto _ = ParseNumber(value);
  }

  template <typename Type>
  void Read(std::vector<Type>& value) {
    uint32_t size = 0;
    if (!ParseNumber(size)) {
      return;
    }

    if constexpr (Config::CHECK_FOR_ERRORS) {
      if (size > Config::MAX_VECTOR_SIZE) {
        error_ = Error::kVecSizeOutOfRange;
        return;
      }
    }

    size_t offset = 0;
    if (!ParseOffset(offset)) {
      return;
    }

    if constexpr (Config::CHECK_FOR_ERRORS) {
      if (size > 0 && offset == 0 || size == 0 && offset > 0) {
        error_ = Error::kVecInvalidSizeOffset;
        return;
      }
    }

    if (size == 0) {
      return;
    }

    if constexpr (std::is_arithmetic_v<Type> || std::is_enum_v<Type>) {
      const auto size_in_bytes = sizeof(Type) * size;
      if constexpr (Config::CHECK_FOR_ERRORS) {
        if (offset + size_in_bytes > buf_.size()) {
          error_ = Error::kReadOutOfRange;
          return;
        }
      }
      value.resize(size);
      std::memcpy(value.data(), std::next(buf_.data(), offset), size_in_bytes);
    } else {
      value.reserve(size);
      Deserializer de{buf_, offset, b64_};
      for (auto i = 0; i < size; i++) {
        Type out_value{};
        de(out_value);
        if constexpr (Config::CHECK_FOR_ERRORS) {
          if (de.error_) {
            error_.swap(de.error_);
            return;
          }
        }
        value.emplace_back(std::move(out_value));
      }
    }
  }

  template <typename Type, size_t Size>
  void Read(std::array<Type, Size>& value) {
    if constexpr (std::is_arithmetic_v<Type> || std::is_enum_v<Type>) {
      constexpr auto kSizeInBytes = sizeof(Type) * Size;
      if constexpr (Config::CHECK_FOR_ERRORS) {
        if (position_ + kSizeInBytes > buf_.size()) {
          error_ = Error::kReadOutOfRange;
          return;
        }
      }
      std::memcpy(value.data(), std::next(buf_.data(), position_),
                  kSizeInBytes);
      position_ += kSizeInBytes;
    } else {
      for (auto i = 0; i < Size; i++) {
        if constexpr (Config::CHECK_FOR_ERRORS) {
          if (error_) {
            return;
          }
        }
        Read(value[i]);
      }
    }
  }

  template <typename Type>
  void Read(std::shared_ptr<Type>& value) {
    size_t offset = 0;
    if (!ParseOffset(offset)) {
      return;
    }

    if (offset != 0) {
      Deserializer de{buf_, offset, b64_};
      Type out_value{};
      de(out_value);
      if constexpr (Config::CHECK_FOR_ERRORS) {
        if (de.error_) {
          error_.swap(de.error_);
          return;
        }
      }
      value = std::make_shared<Type>(std::move(out_value));
    }
  }

  template <std::integral Type>
  void Read(std::basic_string<Type>& value) {
    size_t offset = 0;
    if (!ParseOffset(offset)) {
      return;
    }

    if (offset != 0) {
      auto string_buf = buf_.subspan(offset);
      size_t index = 0;
      do {
        if constexpr (Config::CHECK_FOR_ERRORS) {
          if (index > string_buf.size()) {
            error_ = Error::kReadOutOfRange;
            return;
          }
          if (index > Config::MAX_STRING_SIZE) {
            error_ = Error::kStringSizeOutOfRange;
            return;
          }
        }

        auto ch = *std::bit_cast<Type*>(std::next(string_buf.data(), index));
        if (ch == Type{}) {
          break;
        }
        value.push_back(ch);
        index += sizeof(Type);
      } while (true);
    }
  }

  template <typename... Types>
  void Read(std::variant<Types...>& value) {
    uint32_t index = 0;
    if (!ParseNumber(index)) {
      return;
    }

    if constexpr (Config::CHECK_FOR_ERRORS) {
      if (index > std::variant_size_v<std::variant<Types...>>) {
        error_ = Error::kVariantIndexOutOfRange;
        return;
      }
    }

    size_t offset = 0;
    if (!ParseOffset(offset)) {
      return;
    }

    index++;
    (([&]() { return (index--) == 0; }()
          ? false
          : (TryReadVariant<Types>(index, offset, value), true)) &&
     ...);
  }

  template <typename Type>
  void Read(Type& value)
    requires(std::is_class_v<Type>)
  {
    using pf::de::Read;
    Read(*this, value);
  }

  template <typename Type>
  [[nodiscard]] bool ParseNumber(Type& out_value) noexcept
    requires(std::integral<Type> || std::floating_point<Type>)
  {
    if constexpr (Config::CHECK_FOR_ERRORS) {
      if (position_ + sizeof(Type) > buf_.size()) {
        error_ = Error::kReadOutOfRange;
        return false;
      }
    }
    out_value = *std::bit_cast<Type*>(std::next(buf_.data(), position_));

    position_ += sizeof(Type);
    return true;
  }

  [[nodiscard]] bool ParseOffset(size_t& out_offset) noexcept {
    if (b64_) {
      if constexpr (Config::CHECK_FOR_ERRORS) {
        if (position_ + sizeof(int64_t) > buf_.size()) {
          error_ = Error::kReadOutOfRange;
          return false;
        }
      }
      auto offset = *std::bit_cast<int64_t*>(std::next(buf_.data(), position_));
      if (offset != 0) {
        out_offset = offset + position_;
      }
      if constexpr (Config::CHECK_FOR_ERRORS) {
        if (out_offset >= buf_.size()) {
          error_ = Error::kReadOutOfRange;
          return false;
        }
      }
      position_ += sizeof(int64_t);
    } else {
      if constexpr (Config::CHECK_FOR_ERRORS) {
        if (position_ + sizeof(int32_t) > buf_.size()) {
          error_ = Error::kReadOutOfRange;
          return false;
        }
      }
      auto offset = *std::bit_cast<int32_t*>(std::next(buf_.data(), position_));
      if (offset != 0) {
        out_offset = position_ + offset;
      }
      if constexpr (Config::CHECK_FOR_ERRORS) {
        if (out_offset >= buf_.size()) {
          error_ = Error::kReadOutOfRange;
          return false;
        }
      }
      position_ += sizeof(int32_t);
    }
    return true;
  }

  template <typename Type>
  void TryReadVariant(uint32_t index, size_t offset, auto& value) {
    if (index == 0) {
      Deserializer de{buf_, offset, b64_};
      Type out_value{};
      de(out_value);
      if constexpr (Config::CHECK_FOR_ERRORS) {
        if (de.error_) {
          error_.swap(de.error_);
          return;
        }
      }
      value = out_value;
    }
  }

  std::span<const std::byte> buf_;
  size_t position_;
  bool b64_;
  std::optional<Error> error_;
};

}  // namespace pf::de
