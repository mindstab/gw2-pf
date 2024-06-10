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

#ifndef AMSP_AMSP_MIN_VERSION
#define AMSP_AMSP_MIN_VERSION 32
#endif

#include "amsp/amsp_v0.hpp"
#include "amsp/amsp_v1.hpp"
#include "amsp/amsp_v10.hpp"
#include "amsp/amsp_v11.hpp"
#include "amsp/amsp_v12.hpp"
#include "amsp/amsp_v13.hpp"
#include "amsp/amsp_v14.hpp"
#include "amsp/amsp_v15.hpp"
#include "amsp/amsp_v16.hpp"
#include "amsp/amsp_v17.hpp"
#include "amsp/amsp_v18.hpp"
#include "amsp/amsp_v19.hpp"
#include "amsp/amsp_v2.hpp"
#include "amsp/amsp_v20.hpp"
#include "amsp/amsp_v21.hpp"
#include "amsp/amsp_v22.hpp"
#include "amsp/amsp_v23.hpp"
#include "amsp/amsp_v24.hpp"
#include "amsp/amsp_v25.hpp"
#include "amsp/amsp_v26.hpp"
#include "amsp/amsp_v27.hpp"
#include "amsp/amsp_v28.hpp"
#include "amsp/amsp_v29.hpp"
#include "amsp/amsp_v3.hpp"
#include "amsp/amsp_v30.hpp"
#include "amsp/amsp_v31.hpp"
#include "amsp/amsp_v32.hpp"
#include "amsp/amsp_v4.hpp"
#include "amsp/amsp_v5.hpp"
#include "amsp/amsp_v6.hpp"
#include "amsp/amsp_v7.hpp"
#include "amsp/amsp_v8.hpp"
#include "amsp/amsp_v9.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace AMSP::AMSP {

using ScriptFileData = std::variant<std::monostate
#if AMSP_AMSP_MIN_VERSION <= 0
                                    ,
                                    v0::ScriptFileDataV0
#endif
#if AMSP_AMSP_MIN_VERSION <= 1
                                    ,
                                    v1::ScriptFileDataV1
#endif
#if AMSP_AMSP_MIN_VERSION <= 2
                                    ,
                                    v2::ScriptFileDataV2
#endif
#if AMSP_AMSP_MIN_VERSION <= 3
                                    ,
                                    v3::ScriptFileDataV3
#endif
#if AMSP_AMSP_MIN_VERSION <= 4
                                    ,
                                    v4::ScriptFileDataV4
#endif
#if AMSP_AMSP_MIN_VERSION <= 5
                                    ,
                                    v5::ScriptFileDataV5
#endif
#if AMSP_AMSP_MIN_VERSION <= 6
                                    ,
                                    v6::ScriptFileDataV6
#endif
#if AMSP_AMSP_MIN_VERSION <= 7
                                    ,
                                    v7::ScriptFileDataV7
#endif
#if AMSP_AMSP_MIN_VERSION <= 8
                                    ,
                                    v8::ScriptFileDataV8
#endif
#if AMSP_AMSP_MIN_VERSION <= 9
                                    ,
                                    v9::ScriptFileDataV9
#endif
#if AMSP_AMSP_MIN_VERSION <= 10
                                    ,
                                    v10::ScriptFileDataV10
#endif
#if AMSP_AMSP_MIN_VERSION <= 11
                                    ,
                                    v11::ScriptFileDataV11
#endif
#if AMSP_AMSP_MIN_VERSION <= 12
                                    ,
                                    v12::ScriptFileDataV12
#endif
#if AMSP_AMSP_MIN_VERSION <= 13
                                    ,
                                    v13::ScriptFileDataV13
#endif
#if AMSP_AMSP_MIN_VERSION <= 14
                                    ,
                                    v14::ScriptFileDataV14
#endif
#if AMSP_AMSP_MIN_VERSION <= 15
                                    ,
                                    v15::ScriptFileDataV15
#endif
#if AMSP_AMSP_MIN_VERSION <= 16
                                    ,
                                    v16::ScriptFileDataV16
#endif
#if AMSP_AMSP_MIN_VERSION <= 17
                                    ,
                                    v17::ScriptFileDataV17
#endif
#if AMSP_AMSP_MIN_VERSION <= 18
                                    ,
                                    v18::ScriptFileDataV18
#endif
#if AMSP_AMSP_MIN_VERSION <= 19
                                    ,
                                    v19::ScriptFileDataV19
#endif
#if AMSP_AMSP_MIN_VERSION <= 20
                                    ,
                                    v20::ScriptFileDataV20
#endif
#if AMSP_AMSP_MIN_VERSION <= 21
                                    ,
                                    v21::ScriptFileDataV21
#endif
#if AMSP_AMSP_MIN_VERSION <= 22
                                    ,
                                    v22::ScriptFileDataV22
#endif
#if AMSP_AMSP_MIN_VERSION <= 23
                                    ,
                                    v23::ScriptFileDataV23
#endif
#if AMSP_AMSP_MIN_VERSION <= 24
                                    ,
                                    v24::ScriptFileDataV24
#endif
#if AMSP_AMSP_MIN_VERSION <= 25
                                    ,
                                    v25::ScriptFileDataV25
#endif
#if AMSP_AMSP_MIN_VERSION <= 26
                                    ,
                                    v26::ScriptFileDataV26
#endif
#if AMSP_AMSP_MIN_VERSION <= 27
                                    ,
                                    v27::ScriptFileDataV27
#endif
#if AMSP_AMSP_MIN_VERSION <= 28
                                    ,
                                    v28::ScriptFileDataV28
#endif
#if AMSP_AMSP_MIN_VERSION <= 29
                                    ,
                                    v29::ScriptFileDataV29
#endif
#if AMSP_AMSP_MIN_VERSION <= 30
                                    ,
                                    v30::ScriptFileDataV30
#endif
#if AMSP_AMSP_MIN_VERSION <= 31
                                    ,
                                    v31::ScriptFileDataV31
#endif
#if AMSP_AMSP_MIN_VERSION <= 32
                                    ,
                                    v32::ScriptFileDataV32
#endif
                                    >;

} // namespace AMSP::AMSP

template <> struct Chunk<FourCC::AMSP, FourCC::AMSP> {
  using Type = AMSP::AMSP::ScriptFileData;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if AMSP_AMSP_MIN_VERSION <= 0
    case 0:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v0::ScriptFileDataV0>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v1::ScriptFileDataV1>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v2::ScriptFileDataV2>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v3::ScriptFileDataV3>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 4
    case 4:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v4::ScriptFileDataV4>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 5
    case 5:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v5::ScriptFileDataV5>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v6::ScriptFileDataV6>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 7
    case 7:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v7::ScriptFileDataV7>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 8
    case 8:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v8::ScriptFileDataV8>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 9
    case 9:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v9::ScriptFileDataV9>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 10
    case 10:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v10::ScriptFileDataV10>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 11
    case 11:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v11::ScriptFileDataV11>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 12
    case 12:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v12::ScriptFileDataV12>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 13
    case 13:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v13::ScriptFileDataV13>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 14
    case 14:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v14::ScriptFileDataV14>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 15
    case 15:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v15::ScriptFileDataV15>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 16
    case 16:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v16::ScriptFileDataV16>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 17
    case 17:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v17::ScriptFileDataV17>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 18
    case 18:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v18::ScriptFileDataV18>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 19
    case 19:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v19::ScriptFileDataV19>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 20
    case 20:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v20::ScriptFileDataV20>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 21
    case 21:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v21::ScriptFileDataV21>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 22
    case 22:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v22::ScriptFileDataV22>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 23
    case 23:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v23::ScriptFileDataV23>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 24
    case 24:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v24::ScriptFileDataV24>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 25
    case 25:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v25::ScriptFileDataV25>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 26
    case 26:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v26::ScriptFileDataV26>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 27
    case 27:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v27::ScriptFileDataV27>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 28
    case 28:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v28::ScriptFileDataV28>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 29
    case 29:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v29::ScriptFileDataV29>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 30
    case 30:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v30::ScriptFileDataV30>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 31
    case 31:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v31::ScriptFileDataV31>(buf, b64);
#endif
#if AMSP_AMSP_MIN_VERSION <= 32
    case 32:
      return de::Deserializer<Config>::template Parse<
          AMSP::AMSP::v32::ScriptFileDataV32>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
