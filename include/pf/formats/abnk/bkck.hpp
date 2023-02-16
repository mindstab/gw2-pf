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

#include <expected>
#include <variant>

#ifndef ABNK_BKCK_MIN_VERSION
#define ABNK_BKCK_MIN_VERSION 2
#endif

#include "bkck/bkck_v0.hpp"
#include "bkck/bkck_v1.hpp"
#include "bkck/bkck_v2.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace ABNK::BKCK {

using BankFileData = std::variant<std::monostate
#if ABNK_BKCK_MIN_VERSION <= 0
                                  ,
                                  v0::BankFileDataV0
#endif
#if ABNK_BKCK_MIN_VERSION <= 1
                                  ,
                                  v1::BankFileDataV1
#endif
#if ABNK_BKCK_MIN_VERSION <= 2
                                  ,
                                  v2::BankFileDataV2
#endif
                                  >;

} // namespace ABNK::BKCK

template <> struct Chunk<FourCC::ABNK, FourCC::BKCK> {
  using Type = ABNK::BKCK::BankFileData;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if ABNK_BKCK_MIN_VERSION <= 0
    case 0:
      return de::Deserializer<Config>::template Parse<
          ABNK::BKCK::v0::BankFileDataV0>(buf, b64);
#endif
#if ABNK_BKCK_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          ABNK::BKCK::v1::BankFileDataV1>(buf, b64);
#endif
#if ABNK_BKCK_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          ABNK::BKCK::v2::BankFileDataV2>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
