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

#ifndef MAPC_PRP2_MIN_VERSION
#define MAPC_PRP2_MIN_VERSION 21
#endif

#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"
#include "prp2/prp2_v10.hpp"
#include "prp2/prp2_v11.hpp"
#include "prp2/prp2_v12.hpp"
#include "prp2/prp2_v13.hpp"
#include "prp2/prp2_v14.hpp"
#include "prp2/prp2_v15.hpp"
#include "prp2/prp2_v16.hpp"
#include "prp2/prp2_v17.hpp"
#include "prp2/prp2_v18.hpp"
#include "prp2/prp2_v19.hpp"
#include "prp2/prp2_v20.hpp"
#include "prp2/prp2_v21.hpp"
#include "prp2/prp2_v3.hpp"
#include "prp2/prp2_v4.hpp"
#include "prp2/prp2_v5.hpp"
#include "prp2/prp2_v6.hpp"
#include "prp2/prp2_v7.hpp"
#include "prp2/prp2_v8.hpp"
#include "prp2/prp2_v9.hpp"

namespace pf {
namespace mapc::prp2 {

using PackMapProp = std::variant<std::monostate
#if MAPC_PRP2_MIN_VERSION <= 3
                                 ,
                                 v3::PackMapPropV3
#endif
#if MAPC_PRP2_MIN_VERSION <= 4
                                 ,
                                 v4::PackMapPropV4
#endif
#if MAPC_PRP2_MIN_VERSION <= 5
                                 ,
                                 v5::PackMapPropV5
#endif
#if MAPC_PRP2_MIN_VERSION <= 6
                                 ,
                                 v6::PackMapPropV6
#endif
#if MAPC_PRP2_MIN_VERSION <= 7
                                 ,
                                 v7::PackMapPropV7
#endif
#if MAPC_PRP2_MIN_VERSION <= 8
                                 ,
                                 v8::PackMapPropV8
#endif
#if MAPC_PRP2_MIN_VERSION <= 9
                                 ,
                                 v9::PackMapPropV9
#endif
#if MAPC_PRP2_MIN_VERSION <= 10
                                 ,
                                 v10::PackMapPropV10
#endif
#if MAPC_PRP2_MIN_VERSION <= 11
                                 ,
                                 v11::PackMapPropV11
#endif
#if MAPC_PRP2_MIN_VERSION <= 12
                                 ,
                                 v12::PackMapPropV12
#endif
#if MAPC_PRP2_MIN_VERSION <= 13
                                 ,
                                 v13::PackMapPropV13
#endif
#if MAPC_PRP2_MIN_VERSION <= 14
                                 ,
                                 v14::PackMapPropV14
#endif
#if MAPC_PRP2_MIN_VERSION <= 15
                                 ,
                                 v15::PackMapPropV15
#endif
#if MAPC_PRP2_MIN_VERSION <= 16
                                 ,
                                 v16::PackMapPropV16
#endif
#if MAPC_PRP2_MIN_VERSION <= 17
                                 ,
                                 v17::PackMapPropV17
#endif
#if MAPC_PRP2_MIN_VERSION <= 18
                                 ,
                                 v18::PackMapPropV18
#endif
#if MAPC_PRP2_MIN_VERSION <= 19
                                 ,
                                 v19::PackMapPropV19
#endif
#if MAPC_PRP2_MIN_VERSION <= 20
                                 ,
                                 v20::PackMapPropV20
#endif
#if MAPC_PRP2_MIN_VERSION <= 21
                                 ,
                                 v21::PackMapPropV21
#endif
                                 >;

} // namespace mapc::prp2

template <> struct Chunk<FourCC::mapc, FourCC::prp2> {
  using Type = mapc::prp2::PackMapProp;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if MAPC_PRP2_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v3::PackMapPropV3>(buf, b64);
#endif
#if MAPC_PRP2_MIN_VERSION <= 4
    case 4:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v4::PackMapPropV4>(buf, b64);
#endif
#if MAPC_PRP2_MIN_VERSION <= 5
    case 5:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v5::PackMapPropV5>(buf, b64);
#endif
#if MAPC_PRP2_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v6::PackMapPropV6>(buf, b64);
#endif
#if MAPC_PRP2_MIN_VERSION <= 7
    case 7:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v7::PackMapPropV7>(buf, b64);
#endif
#if MAPC_PRP2_MIN_VERSION <= 8
    case 8:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v8::PackMapPropV8>(buf, b64);
#endif
#if MAPC_PRP2_MIN_VERSION <= 9
    case 9:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v9::PackMapPropV9>(buf, b64);
#endif
#if MAPC_PRP2_MIN_VERSION <= 10
    case 10:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v10::PackMapPropV10>(buf, b64);
#endif
#if MAPC_PRP2_MIN_VERSION <= 11
    case 11:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v11::PackMapPropV11>(buf, b64);
#endif
#if MAPC_PRP2_MIN_VERSION <= 12
    case 12:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v12::PackMapPropV12>(buf, b64);
#endif
#if MAPC_PRP2_MIN_VERSION <= 13
    case 13:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v13::PackMapPropV13>(buf, b64);
#endif
#if MAPC_PRP2_MIN_VERSION <= 14
    case 14:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v14::PackMapPropV14>(buf, b64);
#endif
#if MAPC_PRP2_MIN_VERSION <= 15
    case 15:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v15::PackMapPropV15>(buf, b64);
#endif
#if MAPC_PRP2_MIN_VERSION <= 16
    case 16:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v16::PackMapPropV16>(buf, b64);
#endif
#if MAPC_PRP2_MIN_VERSION <= 17
    case 17:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v17::PackMapPropV17>(buf, b64);
#endif
#if MAPC_PRP2_MIN_VERSION <= 18
    case 18:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v18::PackMapPropV18>(buf, b64);
#endif
#if MAPC_PRP2_MIN_VERSION <= 19
    case 19:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v19::PackMapPropV19>(buf, b64);
#endif
#if MAPC_PRP2_MIN_VERSION <= 20
    case 20:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v20::PackMapPropV20>(buf, b64);
#endif
#if MAPC_PRP2_MIN_VERSION <= 21
    case 21:
      return de::Deserializer<Config>::template Parse<
          mapc::prp2::v21::PackMapPropV21>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
