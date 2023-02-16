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

#ifndef CMPC_COMP_MIN_VERSION
#define CMPC_COMP_MIN_VERSION 19
#endif

#include "comp/comp_v0.hpp"
#include "comp/comp_v1.hpp"
#include "comp/comp_v10.hpp"
#include "comp/comp_v11.hpp"
#include "comp/comp_v12.hpp"
#include "comp/comp_v13.hpp"
#include "comp/comp_v14.hpp"
#include "comp/comp_v15.hpp"
#include "comp/comp_v16.hpp"
#include "comp/comp_v17.hpp"
#include "comp/comp_v18.hpp"
#include "comp/comp_v19.hpp"
#include "comp/comp_v2.hpp"
#include "comp/comp_v3.hpp"
#include "comp/comp_v4.hpp"
#include "comp/comp_v5.hpp"
#include "comp/comp_v6.hpp"
#include "comp/comp_v7.hpp"
#include "comp/comp_v8.hpp"
#include "comp/comp_v9.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace cmpc::comp {

using PackComposite = std::variant<std::monostate
#if CMPC_COMP_MIN_VERSION <= 0
                                   ,
                                   v0::PackCompositeV0
#endif
#if CMPC_COMP_MIN_VERSION <= 1
                                   ,
                                   v1::PackCompositeV1
#endif
#if CMPC_COMP_MIN_VERSION <= 2
                                   ,
                                   v2::PackCompositeV2
#endif
#if CMPC_COMP_MIN_VERSION <= 3
                                   ,
                                   v3::PackCompositeV3
#endif
#if CMPC_COMP_MIN_VERSION <= 4
                                   ,
                                   v4::PackCompositeV4
#endif
#if CMPC_COMP_MIN_VERSION <= 5
                                   ,
                                   v5::PackCompositeV5
#endif
#if CMPC_COMP_MIN_VERSION <= 6
                                   ,
                                   v6::PackCompositeV6
#endif
#if CMPC_COMP_MIN_VERSION <= 7
                                   ,
                                   v7::PackCompositeV7
#endif
#if CMPC_COMP_MIN_VERSION <= 8
                                   ,
                                   v8::PackCompositeV8
#endif
#if CMPC_COMP_MIN_VERSION <= 9
                                   ,
                                   v9::PackCompositeV9
#endif
#if CMPC_COMP_MIN_VERSION <= 10
                                   ,
                                   v10::PackCompositeV10
#endif
#if CMPC_COMP_MIN_VERSION <= 11
                                   ,
                                   v11::PackCompositeV11
#endif
#if CMPC_COMP_MIN_VERSION <= 12
                                   ,
                                   v12::PackCompositeV12
#endif
#if CMPC_COMP_MIN_VERSION <= 13
                                   ,
                                   v13::PackCompositeV13
#endif
#if CMPC_COMP_MIN_VERSION <= 14
                                   ,
                                   v14::PackCompositeV14
#endif
#if CMPC_COMP_MIN_VERSION <= 15
                                   ,
                                   v15::PackCompositeV15
#endif
#if CMPC_COMP_MIN_VERSION <= 16
                                   ,
                                   v16::PackCompositeV16
#endif
#if CMPC_COMP_MIN_VERSION <= 17
                                   ,
                                   v17::PackCompositeV17
#endif
#if CMPC_COMP_MIN_VERSION <= 18
                                   ,
                                   v18::PackCompositeV18
#endif
#if CMPC_COMP_MIN_VERSION <= 19
                                   ,
                                   v19::PackCompositeV19
#endif
                                   >;

} // namespace cmpc::comp

template <> struct Chunk<FourCC::cmpc, FourCC::comp> {
  using Type = cmpc::comp::PackComposite;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if CMPC_COMP_MIN_VERSION <= 0
    case 0:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v0::PackCompositeV0>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v1::PackCompositeV1>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v2::PackCompositeV2>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v3::PackCompositeV3>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 4
    case 4:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v4::PackCompositeV4>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 5
    case 5:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v5::PackCompositeV5>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v6::PackCompositeV6>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 7
    case 7:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v7::PackCompositeV7>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 8
    case 8:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v8::PackCompositeV8>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 9
    case 9:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v9::PackCompositeV9>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 10
    case 10:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v10::PackCompositeV10>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 11
    case 11:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v11::PackCompositeV11>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 12
    case 12:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v12::PackCompositeV12>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 13
    case 13:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v13::PackCompositeV13>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 14
    case 14:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v14::PackCompositeV14>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 15
    case 15:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v15::PackCompositeV15>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 16
    case 16:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v16::PackCompositeV16>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 17
    case 17:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v17::PackCompositeV17>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 18
    case 18:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v18::PackCompositeV18>(buf, b64);
#endif
#if CMPC_COMP_MIN_VERSION <= 19
    case 19:
      return de::Deserializer<Config>::template Parse<
          cmpc::comp::v19::PackCompositeV19>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
