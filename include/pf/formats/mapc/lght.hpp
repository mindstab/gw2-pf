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

#ifndef MAPC_LGHT_MIN_VERSION
#define MAPC_LGHT_MIN_VERSION 19
#endif

#include "lght/lght_v1.hpp"
#include "lght/lght_v10.hpp"
#include "lght/lght_v11.hpp"
#include "lght/lght_v12.hpp"
#include "lght/lght_v13.hpp"
#include "lght/lght_v14.hpp"
#include "lght/lght_v15.hpp"
#include "lght/lght_v16.hpp"
#include "lght/lght_v17.hpp"
#include "lght/lght_v18.hpp"
#include "lght/lght_v19.hpp"
#include "lght/lght_v2.hpp"
#include "lght/lght_v3.hpp"
#include "lght/lght_v4.hpp"
#include "lght/lght_v5.hpp"
#include "lght/lght_v6.hpp"
#include "lght/lght_v7.hpp"
#include "lght/lght_v8.hpp"
#include "lght/lght_v9.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace mapc::lght {

using PackMapLights = std::variant<std::monostate
#if MAPC_LGHT_MIN_VERSION <= 1
                                   ,
                                   v1::PackMapLights
#endif
#if MAPC_LGHT_MIN_VERSION <= 2
                                   ,
                                   v2::PackMapLights
#endif
#if MAPC_LGHT_MIN_VERSION <= 3
                                   ,
                                   v3::PackMapLights
#endif
#if MAPC_LGHT_MIN_VERSION <= 4
                                   ,
                                   v4::PackMapLights
#endif
#if MAPC_LGHT_MIN_VERSION <= 5
                                   ,
                                   v5::PackMapLights
#endif
#if MAPC_LGHT_MIN_VERSION <= 6
                                   ,
                                   v6::PackMapLights
#endif
#if MAPC_LGHT_MIN_VERSION <= 7
                                   ,
                                   v7::PackMapLights
#endif
#if MAPC_LGHT_MIN_VERSION <= 8
                                   ,
                                   v8::PackMapLights
#endif
#if MAPC_LGHT_MIN_VERSION <= 9
                                   ,
                                   v9::PackMapLights
#endif
#if MAPC_LGHT_MIN_VERSION <= 10
                                   ,
                                   v10::PackMapLights
#endif
#if MAPC_LGHT_MIN_VERSION <= 11
                                   ,
                                   v11::PackMapLights
#endif
#if MAPC_LGHT_MIN_VERSION <= 12
                                   ,
                                   v12::PackMapLights
#endif
#if MAPC_LGHT_MIN_VERSION <= 13
                                   ,
                                   v13::PackMapLights
#endif
#if MAPC_LGHT_MIN_VERSION <= 14
                                   ,
                                   v14::PackMapLightsV14
#endif
#if MAPC_LGHT_MIN_VERSION <= 15
                                   ,
                                   v15::PackMapLightsV15
#endif
#if MAPC_LGHT_MIN_VERSION <= 16
                                   ,
                                   v16::PackMapLights
#endif
#if MAPC_LGHT_MIN_VERSION <= 17
                                   ,
                                   v17::PackMapLights
#endif
#if MAPC_LGHT_MIN_VERSION <= 18
                                   ,
                                   v18::PackMapLights
#endif
#if MAPC_LGHT_MIN_VERSION <= 19
                                   ,
                                   v19::PackMapLights
#endif
                                   >;

} // namespace mapc::lght

template <> struct Chunk<FourCC::mapc, FourCC::lght> {
  using Type = mapc::lght::PackMapLights;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if MAPC_LGHT_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v1::PackMapLights>(buf, b64);
#endif
#if MAPC_LGHT_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v2::PackMapLights>(buf, b64);
#endif
#if MAPC_LGHT_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v3::PackMapLights>(buf, b64);
#endif
#if MAPC_LGHT_MIN_VERSION <= 4
    case 4:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v4::PackMapLights>(buf, b64);
#endif
#if MAPC_LGHT_MIN_VERSION <= 5
    case 5:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v5::PackMapLights>(buf, b64);
#endif
#if MAPC_LGHT_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v6::PackMapLights>(buf, b64);
#endif
#if MAPC_LGHT_MIN_VERSION <= 7
    case 7:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v7::PackMapLights>(buf, b64);
#endif
#if MAPC_LGHT_MIN_VERSION <= 8
    case 8:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v8::PackMapLights>(buf, b64);
#endif
#if MAPC_LGHT_MIN_VERSION <= 9
    case 9:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v9::PackMapLights>(buf, b64);
#endif
#if MAPC_LGHT_MIN_VERSION <= 10
    case 10:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v10::PackMapLights>(buf, b64);
#endif
#if MAPC_LGHT_MIN_VERSION <= 11
    case 11:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v11::PackMapLights>(buf, b64);
#endif
#if MAPC_LGHT_MIN_VERSION <= 12
    case 12:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v12::PackMapLights>(buf, b64);
#endif
#if MAPC_LGHT_MIN_VERSION <= 13
    case 13:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v13::PackMapLights>(buf, b64);
#endif
#if MAPC_LGHT_MIN_VERSION <= 14
    case 14:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v14::PackMapLightsV14>(buf, b64);
#endif
#if MAPC_LGHT_MIN_VERSION <= 15
    case 15:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v15::PackMapLightsV15>(buf, b64);
#endif
#if MAPC_LGHT_MIN_VERSION <= 16
    case 16:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v16::PackMapLights>(buf, b64);
#endif
#if MAPC_LGHT_MIN_VERSION <= 17
    case 17:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v17::PackMapLights>(buf, b64);
#endif
#if MAPC_LGHT_MIN_VERSION <= 18
    case 18:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v18::PackMapLights>(buf, b64);
#endif
#if MAPC_LGHT_MIN_VERSION <= 19
    case 19:
      return de::Deserializer<Config>::template Parse<
          mapc::lght::v19::PackMapLights>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
