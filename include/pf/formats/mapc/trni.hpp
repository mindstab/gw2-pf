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

#ifndef MAPC_TRNI_MIN_VERSION
#define MAPC_TRNI_MIN_VERSION 3
#endif

#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"
#include "trni/trni_v0.hpp"
#include "trni/trni_v1.hpp"
#include "trni/trni_v2.hpp"
#include "trni/trni_v3.hpp"

namespace pf {
namespace mapc::trni {

using MapTerrainImg = std::variant<std::monostate
#if MAPC_TRNI_MIN_VERSION <= 0
                                   ,
                                   v0::MapTerrainImg
#endif
#if MAPC_TRNI_MIN_VERSION <= 1
                                   ,
                                   v1::MapTerrainImg
#endif
#if MAPC_TRNI_MIN_VERSION <= 2
                                   ,
                                   v2::MapTerrainImg
#endif
#if MAPC_TRNI_MIN_VERSION <= 3
                                   ,
                                   v3::MapTerrainImg
#endif
                                   >;

} // namespace mapc::trni

template <> struct Chunk<FourCC::mapc, FourCC::trni> {
  using Type = mapc::trni::MapTerrainImg;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if MAPC_TRNI_MIN_VERSION <= 0
    case 0:
      return de::Deserializer<Config>::template Parse<
          mapc::trni::v0::MapTerrainImg>(buf, b64);
#endif
#if MAPC_TRNI_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          mapc::trni::v1::MapTerrainImg>(buf, b64);
#endif
#if MAPC_TRNI_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          mapc::trni::v2::MapTerrainImg>(buf, b64);
#endif
#if MAPC_TRNI_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          mapc::trni::v3::MapTerrainImg>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
