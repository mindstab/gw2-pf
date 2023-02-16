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

#ifndef MODL_GR2S_MIN_VERSION
#define MODL_GR2S_MIN_VERSION 4
#endif

#include "gr2s/gr2s_v0.hpp"
#include "gr2s/gr2s_v1.hpp"
#include "gr2s/gr2s_v2.hpp"
#include "gr2s/gr2s_v3.hpp"
#include "gr2s/gr2s_v4.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace MODL::GR2S {

using ModelFileGr2s = std::variant<std::monostate
#if MODL_GR2S_MIN_VERSION <= 0
                                   ,
                                   v0::ModelFileGr2sV0
#endif
#if MODL_GR2S_MIN_VERSION <= 1
                                   ,
                                   v1::ModelFileGr2sV1
#endif
#if MODL_GR2S_MIN_VERSION <= 2
                                   ,
                                   v2::ModelFileGr2sV2
#endif
#if MODL_GR2S_MIN_VERSION <= 3
                                   ,
                                   v3::ModelFileGr2sV3
#endif
#if MODL_GR2S_MIN_VERSION <= 4
                                   ,
                                   v4::ModelFileGr2sV4
#endif
                                   >;

} // namespace MODL::GR2S

template <> struct Chunk<FourCC::MODL, FourCC::GR2S> {
  using Type = MODL::GR2S::ModelFileGr2s;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if MODL_GR2S_MIN_VERSION <= 0
    case 0:
      return de::Deserializer<Config>::template Parse<
          MODL::GR2S::v0::ModelFileGr2sV0>(buf, b64);
#endif
#if MODL_GR2S_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          MODL::GR2S::v1::ModelFileGr2sV1>(buf, b64);
#endif
#if MODL_GR2S_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          MODL::GR2S::v2::ModelFileGr2sV2>(buf, b64);
#endif
#if MODL_GR2S_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          MODL::GR2S::v3::ModelFileGr2sV3>(buf, b64);
#endif
#if MODL_GR2S_MIN_VERSION <= 4
    case 4:
      return de::Deserializer<Config>::template Parse<
          MODL::GR2S::v4::ModelFileGr2sV4>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
