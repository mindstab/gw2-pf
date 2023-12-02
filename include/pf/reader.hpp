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

#include <bit>
#include <expected>
#include <span>

#include "pf/config.hpp"
#include "pf/de/error.hpp"
#include "pf/packfile.hpp"

namespace pf {

template <FourCC FileType, typename Config = cfg::Config>
struct Reader {
  [[nodiscard]] static Result<Reader> From(
      std::span<const std::byte> buf) noexcept {
    if (buf.size() < sizeof(FileHeader)) {
      return std::unexpected{Error::kInvalidHeaderSize};
    }

    Reader r(buf);
    if (r.header_->magic != FileHeader::kPackFileMagic) {
      return std::unexpected{Error::kInvalidFileType};
    }
    if (r.header_->file_type != FileType) {
      return std::unexpected{Error::kInvalidFileType};
    }
    if (r.header_->reserved > 0) {
      return std::unexpected{Error::kInvalidFileType};
    }
    if (r.header_->header_size != sizeof(FileHeader)) {
      return std::unexpected{Error::kInvalidHeaderSize};
    }

    return r;
  }

  template <FourCC ChunkType,
            concepts::Chunk<Config> Type = Chunk<FileType, ChunkType>>
  [[nodiscard]] de::Result<typename Type::Type> Chunk() const {
    auto it = std::next(buf_.begin(), header_->header_size);
    do {
      const auto size = std::distance(it, buf_.end());
      if (size < sizeof(ChunkHeader)) {
        break;
      }

      auto hdr = std::bit_cast<const ChunkHeader*>(&*it);
      if (hdr->header_size != sizeof(ChunkHeader)) {
        return std::unexpected{de::Error::kInvalidHeaderSize};
      }

      if (hdr->chunk_type == ChunkType) {
        std::advance(it, hdr->header_size);
        return Type::template Parse<Config>(
            hdr->version,
            std::span(it, hdr->fixup_offset ? hdr->fixup_offset
                                            : (hdr->next_chunk_offset -
                                               offsetof(ChunkHeader, version))),
            Has64BitPointers());
      }

      if (size < hdr->next_chunk_offset + offsetof(ChunkHeader, version)) {
        return std::unexpected{de::Error::kTruncatedHeader};
      }

      std::advance(it, hdr->next_chunk_offset + offsetof(ChunkHeader, version));
    } while (it != buf_.end());

    return std::unexpected{de::Error::kChunkNotFound};
  }

  [[nodiscard]] bool Has64BitPointers() const {
    constexpr auto kIs64BitFlag = (1 << 2);
    return (header_->flags & kIs64BitFlag) == kIs64BitFlag;
  }

 private:
  Reader(std::span<const std::byte> buf) noexcept : buf_(buf) {
    header_ = std::bit_cast<const FileHeader*>(buf_.data());
  }

  std::span<const std::byte> buf_;
  const FileHeader* header_;
};

}  // namespace pf