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

#ifndef MAPC_ZON2_MIN_VERSION
#define MAPC_ZON2_MIN_VERSION 22
#endif

#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"
#include "zon2/zon2_v11.hpp"
#include "zon2/zon2_v12.hpp"
#include "zon2/zon2_v13.hpp"
#include "zon2/zon2_v14.hpp"
#include "zon2/zon2_v15.hpp"
#include "zon2/zon2_v16.hpp"
#include "zon2/zon2_v17.hpp"
#include "zon2/zon2_v18.hpp"
#include "zon2/zon2_v19.hpp"
#include "zon2/zon2_v20.hpp"
#include "zon2/zon2_v21.hpp"
#include "zon2/zon2_v22.hpp"

namespace pf {
namespace mapc::zon2 {

using PackMapZonesV12 = std::variant<std::monostate
#if MAPC_ZON2_MIN_VERSION <= 11
                                     ,
                                     v11::PackMapZonesV12
#endif
#if MAPC_ZON2_MIN_VERSION <= 12
                                     ,
                                     v12::PackMapZonesV13
#endif
#if MAPC_ZON2_MIN_VERSION <= 13
                                     ,
                                     v13::PackMapZonesV14
#endif
#if MAPC_ZON2_MIN_VERSION <= 14
                                     ,
                                     v14::PackMapZonesV15
#endif
#if MAPC_ZON2_MIN_VERSION <= 15
                                     ,
                                     v15::PackMapZonesV16
#endif
#if MAPC_ZON2_MIN_VERSION <= 16
                                     ,
                                     v16::PackMapZonesV17
#endif
#if MAPC_ZON2_MIN_VERSION <= 17
                                     ,
                                     v17::PackMapZonesV18
#endif
#if MAPC_ZON2_MIN_VERSION <= 18
                                     ,
                                     v18::PackMapZonesV19
#endif
#if MAPC_ZON2_MIN_VERSION <= 19
                                     ,
                                     v19::PackMapZonesV20
#endif
#if MAPC_ZON2_MIN_VERSION <= 20
                                     ,
                                     v20::PackMapZonesV21
#endif
#if MAPC_ZON2_MIN_VERSION <= 21
                                     ,
                                     v21::PackMapZonesV22
#endif
#if MAPC_ZON2_MIN_VERSION <= 22
                                     ,
                                     v22::PackMapZonesV23
#endif
                                     >;

} // namespace mapc::zon2

template <> struct Chunk<FourCC::mapc, FourCC::zon2> {
  using Type = mapc::zon2::PackMapZonesV12;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if MAPC_ZON2_MIN_VERSION <= 11
    case 11:
      return de::Deserializer<Config>::template Parse<
          mapc::zon2::v11::PackMapZonesV12>(buf, b64);
#endif
#if MAPC_ZON2_MIN_VERSION <= 12
    case 12:
      return de::Deserializer<Config>::template Parse<
          mapc::zon2::v12::PackMapZonesV13>(buf, b64);
#endif
#if MAPC_ZON2_MIN_VERSION <= 13
    case 13:
      return de::Deserializer<Config>::template Parse<
          mapc::zon2::v13::PackMapZonesV14>(buf, b64);
#endif
#if MAPC_ZON2_MIN_VERSION <= 14
    case 14:
      return de::Deserializer<Config>::template Parse<
          mapc::zon2::v14::PackMapZonesV15>(buf, b64);
#endif
#if MAPC_ZON2_MIN_VERSION <= 15
    case 15:
      return de::Deserializer<Config>::template Parse<
          mapc::zon2::v15::PackMapZonesV16>(buf, b64);
#endif
#if MAPC_ZON2_MIN_VERSION <= 16
    case 16:
      return de::Deserializer<Config>::template Parse<
          mapc::zon2::v16::PackMapZonesV17>(buf, b64);
#endif
#if MAPC_ZON2_MIN_VERSION <= 17
    case 17:
      return de::Deserializer<Config>::template Parse<
          mapc::zon2::v17::PackMapZonesV18>(buf, b64);
#endif
#if MAPC_ZON2_MIN_VERSION <= 18
    case 18:
      return de::Deserializer<Config>::template Parse<
          mapc::zon2::v18::PackMapZonesV19>(buf, b64);
#endif
#if MAPC_ZON2_MIN_VERSION <= 19
    case 19:
      return de::Deserializer<Config>::template Parse<
          mapc::zon2::v19::PackMapZonesV20>(buf, b64);
#endif
#if MAPC_ZON2_MIN_VERSION <= 20
    case 20:
      return de::Deserializer<Config>::template Parse<
          mapc::zon2::v20::PackMapZonesV21>(buf, b64);
#endif
#if MAPC_ZON2_MIN_VERSION <= 21
    case 21:
      return de::Deserializer<Config>::template Parse<
          mapc::zon2::v21::PackMapZonesV22>(buf, b64);
#endif
#if MAPC_ZON2_MIN_VERSION <= 22
    case 22:
      return de::Deserializer<Config>::template Parse<
          mapc::zon2::v22::PackMapZonesV23>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
