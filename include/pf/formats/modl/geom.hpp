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

#ifndef MODL_GEOM_MIN_VERSION
#define MODL_GEOM_MIN_VERSION 1
#endif

#include "geom/geom_v0.hpp"
#include "geom/geom_v1.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace MODL::GEOM {

using ModelFileGeometry = std::variant<std::monostate
#if MODL_GEOM_MIN_VERSION <= 0
                                       ,
                                       v0::ModelFileGeometryV0
#endif
#if MODL_GEOM_MIN_VERSION <= 1
                                       ,
                                       v1::ModelFileGeometryV1
#endif
                                       >;

} // namespace MODL::GEOM

template <> struct Chunk<FourCC::MODL, FourCC::GEOM> {
  using Type = MODL::GEOM::ModelFileGeometry;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if MODL_GEOM_MIN_VERSION <= 0
    case 0:
      return de::Deserializer<Config>::template Parse<
          MODL::GEOM::v0::ModelFileGeometryV0>(buf, b64);
#endif
#if MODL_GEOM_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          MODL::GEOM::v1::ModelFileGeometryV1>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
