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

#ifndef LOCL_UXLC_MIN_VERSION
#define LOCL_UXLC_MIN_VERSION 7
#endif

#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"
#include "uxlc/uxlc_v0.hpp"
#include "uxlc/uxlc_v1.hpp"
#include "uxlc/uxlc_v2.hpp"
#include "uxlc/uxlc_v3.hpp"
#include "uxlc/uxlc_v4.hpp"
#include "uxlc/uxlc_v5.hpp"
#include "uxlc/uxlc_v6.hpp"
#include "uxlc/uxlc_v7.hpp"

namespace pf {
namespace locl::uxlc {

using PrefPackUxLocal = std::variant<std::monostate
#if LOCL_UXLC_MIN_VERSION <= 0
                                     ,
                                     v0::PrefPackUxLocal
#endif
#if LOCL_UXLC_MIN_VERSION <= 1
                                     ,
                                     v1::PrefPackUxLocal
#endif
#if LOCL_UXLC_MIN_VERSION <= 2
                                     ,
                                     v2::PrefPackUxLocal
#endif
#if LOCL_UXLC_MIN_VERSION <= 3
                                     ,
                                     v3::PrefPackUxLocal
#endif
#if LOCL_UXLC_MIN_VERSION <= 4
                                     ,
                                     v4::PrefPackUxLocal
#endif
#if LOCL_UXLC_MIN_VERSION <= 5
                                     ,
                                     v5::PrefPackUxLocal
#endif
#if LOCL_UXLC_MIN_VERSION <= 6
                                     ,
                                     v6::PrefPackUxLocal
#endif
#if LOCL_UXLC_MIN_VERSION <= 7
                                     ,
                                     v7::PrefPackUxLocal
#endif
                                     >;

} // namespace locl::uxlc

template <> struct Chunk<FourCC::locl, FourCC::uxlc> {
  using Type = locl::uxlc::PrefPackUxLocal;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if LOCL_UXLC_MIN_VERSION <= 0
    case 0:
      return de::Deserializer<Config>::template Parse<
          locl::uxlc::v0::PrefPackUxLocal>(buf, b64);
#endif
#if LOCL_UXLC_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          locl::uxlc::v1::PrefPackUxLocal>(buf, b64);
#endif
#if LOCL_UXLC_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          locl::uxlc::v2::PrefPackUxLocal>(buf, b64);
#endif
#if LOCL_UXLC_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          locl::uxlc::v3::PrefPackUxLocal>(buf, b64);
#endif
#if LOCL_UXLC_MIN_VERSION <= 4
    case 4:
      return de::Deserializer<Config>::template Parse<
          locl::uxlc::v4::PrefPackUxLocal>(buf, b64);
#endif
#if LOCL_UXLC_MIN_VERSION <= 5
    case 5:
      return de::Deserializer<Config>::template Parse<
          locl::uxlc::v5::PrefPackUxLocal>(buf, b64);
#endif
#if LOCL_UXLC_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          locl::uxlc::v6::PrefPackUxLocal>(buf, b64);
#endif
#if LOCL_UXLC_MIN_VERSION <= 7
    case 7:
      return de::Deserializer<Config>::template Parse<
          locl::uxlc::v7::PrefPackUxLocal>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
