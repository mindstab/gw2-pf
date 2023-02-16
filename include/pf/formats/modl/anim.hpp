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

#ifndef MODL_ANIM_MIN_VERSION
#define MODL_ANIM_MIN_VERSION 25
#endif

#include "anim/anim_v0.hpp"
#include "anim/anim_v1.hpp"
#include "anim/anim_v10.hpp"
#include "anim/anim_v11.hpp"
#include "anim/anim_v12.hpp"
#include "anim/anim_v13.hpp"
#include "anim/anim_v14.hpp"
#include "anim/anim_v15.hpp"
#include "anim/anim_v16.hpp"
#include "anim/anim_v17.hpp"
#include "anim/anim_v18.hpp"
#include "anim/anim_v19.hpp"
#include "anim/anim_v2.hpp"
#include "anim/anim_v20.hpp"
#include "anim/anim_v21.hpp"
#include "anim/anim_v22.hpp"
#include "anim/anim_v23.hpp"
#include "anim/anim_v24.hpp"
#include "anim/anim_v25.hpp"
#include "anim/anim_v3.hpp"
#include "anim/anim_v4.hpp"
#include "anim/anim_v5.hpp"
#include "anim/anim_v6.hpp"
#include "anim/anim_v7.hpp"
#include "anim/anim_v8.hpp"
#include "anim/anim_v9.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace MODL::ANIM {

using ModelFileAnimation = std::variant<std::monostate
#if MODL_ANIM_MIN_VERSION <= 0
                                        ,
                                        v0::ModelFileAnimationV0
#endif
#if MODL_ANIM_MIN_VERSION <= 1
                                        ,
                                        v1::ModelFileAnimationV1
#endif
#if MODL_ANIM_MIN_VERSION <= 2
                                        ,
                                        v2::ModelFileAnimationBankV2
#endif
#if MODL_ANIM_MIN_VERSION <= 3
                                        ,
                                        v3::ModelFileAnimationBankV3
#endif
#if MODL_ANIM_MIN_VERSION <= 4
                                        ,
                                        v4::ModelFileAnimationBankV4
#endif
#if MODL_ANIM_MIN_VERSION <= 5
                                        ,
                                        v5::ModelFileAnimationBankV5
#endif
#if MODL_ANIM_MIN_VERSION <= 6
                                        ,
                                        v6::ModelFileAnimationBankV6
#endif
#if MODL_ANIM_MIN_VERSION <= 7
                                        ,
                                        v7::ModelFileAnimationBankV7
#endif
#if MODL_ANIM_MIN_VERSION <= 8
                                        ,
                                        v8::ModelFileAnimationBankV8
#endif
#if MODL_ANIM_MIN_VERSION <= 9
                                        ,
                                        v9::ModelFileAnimationBankV9
#endif
#if MODL_ANIM_MIN_VERSION <= 10
                                        ,
                                        v10::ModelFileAnimationBankV10
#endif
#if MODL_ANIM_MIN_VERSION <= 11
                                        ,
                                        v11::ModelFileAnimationBankV11
#endif
#if MODL_ANIM_MIN_VERSION <= 12
                                        ,
                                        v12::ModelFileAnimationBankV12
#endif
#if MODL_ANIM_MIN_VERSION <= 13
                                        ,
                                        v13::ModelFileAnimationBankV13
#endif
#if MODL_ANIM_MIN_VERSION <= 14
                                        ,
                                        v14::ModelFileAnimationBankV14
#endif
#if MODL_ANIM_MIN_VERSION <= 15
                                        ,
                                        v15::ModelFileAnimationBankV15
#endif
#if MODL_ANIM_MIN_VERSION <= 16
                                        ,
                                        v16::ModelFileAnimationBankV16
#endif
#if MODL_ANIM_MIN_VERSION <= 17
                                        ,
                                        v17::ModelFileAnimationBankV17
#endif
#if MODL_ANIM_MIN_VERSION <= 18
                                        ,
                                        v18::ModelFileAnimationBankV18
#endif
#if MODL_ANIM_MIN_VERSION <= 19
                                        ,
                                        v19::ModelFileAnimationBankV19
#endif
#if MODL_ANIM_MIN_VERSION <= 20
                                        ,
                                        v20::ModelFileAnimationBankV20
#endif
#if MODL_ANIM_MIN_VERSION <= 21
                                        ,
                                        v21::ModelFileAnimationBankV21
#endif
#if MODL_ANIM_MIN_VERSION <= 22
                                        ,
                                        v22::ModelFileAnimationBankV22
#endif
#if MODL_ANIM_MIN_VERSION <= 23
                                        ,
                                        v23::ModelFileAnimationBankV23
#endif
#if MODL_ANIM_MIN_VERSION <= 24
                                        ,
                                        v24::ModelFileAnimationV24
#endif
#if MODL_ANIM_MIN_VERSION <= 25
                                        ,
                                        v25::ModelFileAnimationV25
#endif
                                        >;

} // namespace MODL::ANIM

template <> struct Chunk<FourCC::MODL, FourCC::ANIM> {
  using Type = MODL::ANIM::ModelFileAnimation;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if MODL_ANIM_MIN_VERSION <= 0
    case 0:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v0::ModelFileAnimationV0>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v1::ModelFileAnimationV1>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v2::ModelFileAnimationBankV2>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v3::ModelFileAnimationBankV3>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 4
    case 4:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v4::ModelFileAnimationBankV4>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 5
    case 5:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v5::ModelFileAnimationBankV5>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v6::ModelFileAnimationBankV6>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 7
    case 7:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v7::ModelFileAnimationBankV7>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 8
    case 8:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v8::ModelFileAnimationBankV8>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 9
    case 9:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v9::ModelFileAnimationBankV9>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 10
    case 10:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v10::ModelFileAnimationBankV10>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 11
    case 11:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v11::ModelFileAnimationBankV11>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 12
    case 12:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v12::ModelFileAnimationBankV12>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 13
    case 13:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v13::ModelFileAnimationBankV13>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 14
    case 14:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v14::ModelFileAnimationBankV14>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 15
    case 15:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v15::ModelFileAnimationBankV15>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 16
    case 16:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v16::ModelFileAnimationBankV16>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 17
    case 17:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v17::ModelFileAnimationBankV17>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 18
    case 18:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v18::ModelFileAnimationBankV18>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 19
    case 19:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v19::ModelFileAnimationBankV19>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 20
    case 20:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v20::ModelFileAnimationBankV20>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 21
    case 21:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v21::ModelFileAnimationBankV21>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 22
    case 22:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v22::ModelFileAnimationBankV22>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 23
    case 23:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v23::ModelFileAnimationBankV23>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 24
    case 24:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v24::ModelFileAnimationV24>(buf, b64);
#endif
#if MODL_ANIM_MIN_VERSION <= 25
    case 25:
      return de::Deserializer<Config>::template Parse<
          MODL::ANIM::v25::ModelFileAnimationV25>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
