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

#ifndef MAPC_TRN_MIN_VERSION
#define MAPC_TRN_MIN_VERSION 14
#endif

#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"
#include "trn/trn_v10.hpp"
#include "trn/trn_v11.hpp"
#include "trn/trn_v12.hpp"
#include "trn/trn_v13.hpp"
#include "trn/trn_v14.hpp"

namespace pf {
namespace mapc::trn {

using PackMapTerrain = std::variant<std::monostate
#if MAPC_TRN_MIN_VERSION <= 10
                                    ,
                                    v10::PackMapTerrainV10
#endif
#if MAPC_TRN_MIN_VERSION <= 11
                                    ,
                                    v11::PackMapTerrainV11
#endif
#if MAPC_TRN_MIN_VERSION <= 12
                                    ,
                                    v12::PackMapTerrainV12
#endif
#if MAPC_TRN_MIN_VERSION <= 13
                                    ,
                                    v13::PackMapTerrainV13
#endif
#if MAPC_TRN_MIN_VERSION <= 14
                                    ,
                                    v14::PackMapTerrainV14
#endif
                                    >;

} // namespace mapc::trn

template <> struct Chunk<FourCC::mapc, FourCC::trn> {
  using Type = mapc::trn::PackMapTerrain;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if MAPC_TRN_MIN_VERSION <= 10
    case 10:
      return de::Deserializer<Config>::template Parse<
          mapc::trn::v10::PackMapTerrainV10>(buf, b64);
#endif
#if MAPC_TRN_MIN_VERSION <= 11
    case 11:
      return de::Deserializer<Config>::template Parse<
          mapc::trn::v11::PackMapTerrainV11>(buf, b64);
#endif
#if MAPC_TRN_MIN_VERSION <= 12
    case 12:
      return de::Deserializer<Config>::template Parse<
          mapc::trn::v12::PackMapTerrainV12>(buf, b64);
#endif
#if MAPC_TRN_MIN_VERSION <= 13
    case 13:
      return de::Deserializer<Config>::template Parse<
          mapc::trn::v13::PackMapTerrainV13>(buf, b64);
#endif
#if MAPC_TRN_MIN_VERSION <= 14
    case 14:
      return de::Deserializer<Config>::template Parse<
          mapc::trn::v14::PackMapTerrainV14>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
