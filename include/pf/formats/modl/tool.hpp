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

#ifndef MODL_TOOL_MIN_VERSION
#define MODL_TOOL_MIN_VERSION 16
#endif

#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"
#include "tool/tool_v0.hpp"
#include "tool/tool_v1.hpp"
#include "tool/tool_v10.hpp"
#include "tool/tool_v11.hpp"
#include "tool/tool_v12.hpp"
#include "tool/tool_v13.hpp"
#include "tool/tool_v14.hpp"
#include "tool/tool_v15.hpp"
#include "tool/tool_v16.hpp"
#include "tool/tool_v2.hpp"
#include "tool/tool_v3.hpp"
#include "tool/tool_v4.hpp"
#include "tool/tool_v5.hpp"
#include "tool/tool_v6.hpp"
#include "tool/tool_v7.hpp"
#include "tool/tool_v8.hpp"
#include "tool/tool_v9.hpp"

namespace pf {
namespace MODL::TOOL {

using ModelFileTool = std::variant<std::monostate
#if MODL_TOOL_MIN_VERSION <= 0
                                   ,
                                   v0::ModelFileToolV0
#endif
#if MODL_TOOL_MIN_VERSION <= 1
                                   ,
                                   v1::ModelFileToolV1
#endif
#if MODL_TOOL_MIN_VERSION <= 2
                                   ,
                                   v2::ModelFileToolV2
#endif
#if MODL_TOOL_MIN_VERSION <= 3
                                   ,
                                   v3::ModelFileToolV3
#endif
#if MODL_TOOL_MIN_VERSION <= 4
                                   ,
                                   v4::ModelFileToolV4
#endif
#if MODL_TOOL_MIN_VERSION <= 5
                                   ,
                                   v5::ModelFileToolV5
#endif
#if MODL_TOOL_MIN_VERSION <= 6
                                   ,
                                   v6::ModelFileToolV6
#endif
#if MODL_TOOL_MIN_VERSION <= 7
                                   ,
                                   v7::ModelFileToolV7
#endif
#if MODL_TOOL_MIN_VERSION <= 8
                                   ,
                                   v8::ModelFileToolV8
#endif
#if MODL_TOOL_MIN_VERSION <= 9
                                   ,
                                   v9::ModelFileToolV9
#endif
#if MODL_TOOL_MIN_VERSION <= 10
                                   ,
                                   v10::ModelFileToolV10
#endif
#if MODL_TOOL_MIN_VERSION <= 11
                                   ,
                                   v11::ModelFileToolV11
#endif
#if MODL_TOOL_MIN_VERSION <= 12
                                   ,
                                   v12::ModelFileToolV12
#endif
#if MODL_TOOL_MIN_VERSION <= 13
                                   ,
                                   v13::ModelFileToolV13
#endif
#if MODL_TOOL_MIN_VERSION <= 14
                                   ,
                                   v14::ModelFileToolV14
#endif
#if MODL_TOOL_MIN_VERSION <= 15
                                   ,
                                   v15::ModelFileToolV15
#endif
#if MODL_TOOL_MIN_VERSION <= 16
                                   ,
                                   v16::ModelFileToolV16
#endif
                                   >;

} // namespace MODL::TOOL

template <> struct Chunk<FourCC::MODL, FourCC::TOOL> {
  using Type = MODL::TOOL::ModelFileTool;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if MODL_TOOL_MIN_VERSION <= 0
    case 0:
      return de::Deserializer<Config>::template Parse<
          MODL::TOOL::v0::ModelFileToolV0>(buf, b64);
#endif
#if MODL_TOOL_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          MODL::TOOL::v1::ModelFileToolV1>(buf, b64);
#endif
#if MODL_TOOL_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          MODL::TOOL::v2::ModelFileToolV2>(buf, b64);
#endif
#if MODL_TOOL_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          MODL::TOOL::v3::ModelFileToolV3>(buf, b64);
#endif
#if MODL_TOOL_MIN_VERSION <= 4
    case 4:
      return de::Deserializer<Config>::template Parse<
          MODL::TOOL::v4::ModelFileToolV4>(buf, b64);
#endif
#if MODL_TOOL_MIN_VERSION <= 5
    case 5:
      return de::Deserializer<Config>::template Parse<
          MODL::TOOL::v5::ModelFileToolV5>(buf, b64);
#endif
#if MODL_TOOL_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          MODL::TOOL::v6::ModelFileToolV6>(buf, b64);
#endif
#if MODL_TOOL_MIN_VERSION <= 7
    case 7:
      return de::Deserializer<Config>::template Parse<
          MODL::TOOL::v7::ModelFileToolV7>(buf, b64);
#endif
#if MODL_TOOL_MIN_VERSION <= 8
    case 8:
      return de::Deserializer<Config>::template Parse<
          MODL::TOOL::v8::ModelFileToolV8>(buf, b64);
#endif
#if MODL_TOOL_MIN_VERSION <= 9
    case 9:
      return de::Deserializer<Config>::template Parse<
          MODL::TOOL::v9::ModelFileToolV9>(buf, b64);
#endif
#if MODL_TOOL_MIN_VERSION <= 10
    case 10:
      return de::Deserializer<Config>::template Parse<
          MODL::TOOL::v10::ModelFileToolV10>(buf, b64);
#endif
#if MODL_TOOL_MIN_VERSION <= 11
    case 11:
      return de::Deserializer<Config>::template Parse<
          MODL::TOOL::v11::ModelFileToolV11>(buf, b64);
#endif
#if MODL_TOOL_MIN_VERSION <= 12
    case 12:
      return de::Deserializer<Config>::template Parse<
          MODL::TOOL::v12::ModelFileToolV12>(buf, b64);
#endif
#if MODL_TOOL_MIN_VERSION <= 13
    case 13:
      return de::Deserializer<Config>::template Parse<
          MODL::TOOL::v13::ModelFileToolV13>(buf, b64);
#endif
#if MODL_TOOL_MIN_VERSION <= 14
    case 14:
      return de::Deserializer<Config>::template Parse<
          MODL::TOOL::v14::ModelFileToolV14>(buf, b64);
#endif
#if MODL_TOOL_MIN_VERSION <= 15
    case 15:
      return de::Deserializer<Config>::template Parse<
          MODL::TOOL::v15::ModelFileToolV15>(buf, b64);
#endif
#if MODL_TOOL_MIN_VERSION <= 16
    case 16:
      return de::Deserializer<Config>::template Parse<
          MODL::TOOL::v16::ModelFileToolV16>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
