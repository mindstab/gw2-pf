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

#ifndef LOCL_AUDO_MIN_VERSION
#define LOCL_AUDO_MIN_VERSION 6
#endif

#include "audo/audo_v0.hpp"
#include "audo/audo_v1.hpp"
#include "audo/audo_v2.hpp"
#include "audo/audo_v3.hpp"
#include "audo/audo_v4.hpp"
#include "audo/audo_v5.hpp"
#include "audo/audo_v6.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace locl::audo {

using PrefPackAudio = std::variant<std::monostate
#if LOCL_AUDO_MIN_VERSION <= 0
                                   ,
                                   v0::PrefPackAudio
#endif
#if LOCL_AUDO_MIN_VERSION <= 1
                                   ,
                                   v1::PrefPackAudio
#endif
#if LOCL_AUDO_MIN_VERSION <= 2
                                   ,
                                   v2::PrefPackAudio
#endif
#if LOCL_AUDO_MIN_VERSION <= 3
                                   ,
                                   v3::PrefPackAudio
#endif
#if LOCL_AUDO_MIN_VERSION <= 4
                                   ,
                                   v4::PrefPackAudio
#endif
#if LOCL_AUDO_MIN_VERSION <= 5
                                   ,
                                   v5::PrefPackAudio
#endif
#if LOCL_AUDO_MIN_VERSION <= 6
                                   ,
                                   v6::PrefPackAudio
#endif
                                   >;

} // namespace locl::audo

template <> struct Chunk<FourCC::locl, FourCC::audo> {
  using Type = locl::audo::PrefPackAudio;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if LOCL_AUDO_MIN_VERSION <= 0
    case 0:
      return de::Deserializer<Config>::template Parse<
          locl::audo::v0::PrefPackAudio>(buf, b64);
#endif
#if LOCL_AUDO_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          locl::audo::v1::PrefPackAudio>(buf, b64);
#endif
#if LOCL_AUDO_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          locl::audo::v2::PrefPackAudio>(buf, b64);
#endif
#if LOCL_AUDO_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          locl::audo::v3::PrefPackAudio>(buf, b64);
#endif
#if LOCL_AUDO_MIN_VERSION <= 4
    case 4:
      return de::Deserializer<Config>::template Parse<
          locl::audo::v4::PrefPackAudio>(buf, b64);
#endif
#if LOCL_AUDO_MIN_VERSION <= 5
    case 5:
      return de::Deserializer<Config>::template Parse<
          locl::audo::v5::PrefPackAudio>(buf, b64);
#endif
#if LOCL_AUDO_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          locl::audo::v6::PrefPackAudio>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
