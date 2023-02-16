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

#ifndef CINP_CSCN_MIN_VERSION
#define CINP_CSCN_MIN_VERSION 36
#endif

#include "cscn/cscn_v0.hpp"
#include "cscn/cscn_v1.hpp"
#include "cscn/cscn_v10.hpp"
#include "cscn/cscn_v11.hpp"
#include "cscn/cscn_v12.hpp"
#include "cscn/cscn_v13.hpp"
#include "cscn/cscn_v14.hpp"
#include "cscn/cscn_v15.hpp"
#include "cscn/cscn_v16.hpp"
#include "cscn/cscn_v17.hpp"
#include "cscn/cscn_v18.hpp"
#include "cscn/cscn_v19.hpp"
#include "cscn/cscn_v2.hpp"
#include "cscn/cscn_v20.hpp"
#include "cscn/cscn_v21.hpp"
#include "cscn/cscn_v22.hpp"
#include "cscn/cscn_v23.hpp"
#include "cscn/cscn_v24.hpp"
#include "cscn/cscn_v25.hpp"
#include "cscn/cscn_v26.hpp"
#include "cscn/cscn_v27.hpp"
#include "cscn/cscn_v28.hpp"
#include "cscn/cscn_v29.hpp"
#include "cscn/cscn_v3.hpp"
#include "cscn/cscn_v30.hpp"
#include "cscn/cscn_v31.hpp"
#include "cscn/cscn_v32.hpp"
#include "cscn/cscn_v33.hpp"
#include "cscn/cscn_v34.hpp"
#include "cscn/cscn_v35.hpp"
#include "cscn/cscn_v36.hpp"
#include "cscn/cscn_v4.hpp"
#include "cscn/cscn_v5.hpp"
#include "cscn/cscn_v6.hpp"
#include "cscn/cscn_v7.hpp"
#include "cscn/cscn_v8.hpp"
#include "cscn/cscn_v9.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace CINP::CSCN {

using SceneData = std::variant<std::monostate
#if CINP_CSCN_MIN_VERSION <= 0
                               ,
                               v0::SceneDataV0
#endif
#if CINP_CSCN_MIN_VERSION <= 1
                               ,
                               v1::SceneDataV1
#endif
#if CINP_CSCN_MIN_VERSION <= 2
                               ,
                               v2::SceneDataV2
#endif
#if CINP_CSCN_MIN_VERSION <= 3
                               ,
                               v3::SceneDataV3
#endif
#if CINP_CSCN_MIN_VERSION <= 4
                               ,
                               v4::SceneDataV4
#endif
#if CINP_CSCN_MIN_VERSION <= 5
                               ,
                               v5::SceneDataV5
#endif
#if CINP_CSCN_MIN_VERSION <= 6
                               ,
                               v6::SceneDataV6
#endif
#if CINP_CSCN_MIN_VERSION <= 7
                               ,
                               v7::SceneDataV7
#endif
#if CINP_CSCN_MIN_VERSION <= 8
                               ,
                               v8::SceneDataV8
#endif
#if CINP_CSCN_MIN_VERSION <= 9
                               ,
                               v9::SceneDataV9
#endif
#if CINP_CSCN_MIN_VERSION <= 10
                               ,
                               v10::SceneDataV10
#endif
#if CINP_CSCN_MIN_VERSION <= 11
                               ,
                               v11::SceneDataV11
#endif
#if CINP_CSCN_MIN_VERSION <= 12
                               ,
                               v12::SceneDataV12
#endif
#if CINP_CSCN_MIN_VERSION <= 13
                               ,
                               v13::SceneDataV13
#endif
#if CINP_CSCN_MIN_VERSION <= 14
                               ,
                               v14::SceneDataV14
#endif
#if CINP_CSCN_MIN_VERSION <= 15
                               ,
                               v15::SceneDataV15
#endif
#if CINP_CSCN_MIN_VERSION <= 16
                               ,
                               v16::SceneDataV16
#endif
#if CINP_CSCN_MIN_VERSION <= 17
                               ,
                               v17::SceneDataV17
#endif
#if CINP_CSCN_MIN_VERSION <= 18
                               ,
                               v18::SceneDataV18
#endif
#if CINP_CSCN_MIN_VERSION <= 19
                               ,
                               v19::SceneDataV19
#endif
#if CINP_CSCN_MIN_VERSION <= 20
                               ,
                               v20::SceneDataV20
#endif
#if CINP_CSCN_MIN_VERSION <= 21
                               ,
                               v21::SceneDataV21
#endif
#if CINP_CSCN_MIN_VERSION <= 22
                               ,
                               v22::SceneDataV22
#endif
#if CINP_CSCN_MIN_VERSION <= 23
                               ,
                               v23::SceneDataV23
#endif
#if CINP_CSCN_MIN_VERSION <= 24
                               ,
                               v24::SceneDataV24
#endif
#if CINP_CSCN_MIN_VERSION <= 25
                               ,
                               v25::SceneDataV25
#endif
#if CINP_CSCN_MIN_VERSION <= 26
                               ,
                               v26::SceneDataV26
#endif
#if CINP_CSCN_MIN_VERSION <= 27
                               ,
                               v27::SceneDataV27
#endif
#if CINP_CSCN_MIN_VERSION <= 28
                               ,
                               v28::SceneDataV28
#endif
#if CINP_CSCN_MIN_VERSION <= 29
                               ,
                               v29::SceneDataV29
#endif
#if CINP_CSCN_MIN_VERSION <= 30
                               ,
                               v30::SceneDataV30
#endif
#if CINP_CSCN_MIN_VERSION <= 31
                               ,
                               v31::SceneDataV31
#endif
#if CINP_CSCN_MIN_VERSION <= 32
                               ,
                               v32::SceneDataV32
#endif
#if CINP_CSCN_MIN_VERSION <= 33
                               ,
                               v33::SceneDataV33
#endif
#if CINP_CSCN_MIN_VERSION <= 34
                               ,
                               v34::SceneDataV34
#endif
#if CINP_CSCN_MIN_VERSION <= 35
                               ,
                               v35::SceneDataV35
#endif
#if CINP_CSCN_MIN_VERSION <= 36
                               ,
                               v36::SceneDataV36
#endif
                               >;

} // namespace CINP::CSCN

template <> struct Chunk<FourCC::CINP, FourCC::CSCN> {
  using Type = CINP::CSCN::SceneData;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if CINP_CSCN_MIN_VERSION <= 0
    case 0:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v0::SceneDataV0>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v1::SceneDataV1>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v2::SceneDataV2>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v3::SceneDataV3>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 4
    case 4:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v4::SceneDataV4>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 5
    case 5:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v5::SceneDataV5>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v6::SceneDataV6>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 7
    case 7:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v7::SceneDataV7>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 8
    case 8:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v8::SceneDataV8>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 9
    case 9:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v9::SceneDataV9>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 10
    case 10:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v10::SceneDataV10>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 11
    case 11:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v11::SceneDataV11>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 12
    case 12:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v12::SceneDataV12>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 13
    case 13:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v13::SceneDataV13>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 14
    case 14:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v14::SceneDataV14>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 15
    case 15:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v15::SceneDataV15>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 16
    case 16:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v16::SceneDataV16>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 17
    case 17:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v17::SceneDataV17>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 18
    case 18:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v18::SceneDataV18>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 19
    case 19:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v19::SceneDataV19>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 20
    case 20:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v20::SceneDataV20>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 21
    case 21:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v21::SceneDataV21>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 22
    case 22:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v22::SceneDataV22>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 23
    case 23:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v23::SceneDataV23>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 24
    case 24:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v24::SceneDataV24>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 25
    case 25:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v25::SceneDataV25>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 26
    case 26:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v26::SceneDataV26>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 27
    case 27:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v27::SceneDataV27>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 28
    case 28:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v28::SceneDataV28>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 29
    case 29:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v29::SceneDataV29>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 30
    case 30:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v30::SceneDataV30>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 31
    case 31:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v31::SceneDataV31>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 32
    case 32:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v32::SceneDataV32>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 33
    case 33:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v33::SceneDataV33>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 34
    case 34:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v34::SceneDataV34>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 35
    case 35:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v35::SceneDataV35>(buf, b64);
#endif
#if CINP_CSCN_MIN_VERSION <= 36
    case 36:
      return de::Deserializer<Config>::template Parse<
          CINP::CSCN::v36::SceneDataV36>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
