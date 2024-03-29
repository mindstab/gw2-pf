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

#ifndef HVKC_HAVK_MIN_VERSION
#define HVKC_HAVK_MIN_VERSION 16
#endif

#include "havk/havk_v10.hpp"
#include "havk/havk_v11.hpp"
#include "havk/havk_v12.hpp"
#include "havk/havk_v13.hpp"
#include "havk/havk_v14.hpp"
#include "havk/havk_v15.hpp"
#include "havk/havk_v16.hpp"
#include "havk/havk_v6.hpp"
#include "havk/havk_v7.hpp"
#include "havk/havk_v8.hpp"
#include "havk/havk_v9.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace hvkC::havk {

using PackMapCollide = std::variant<std::monostate
#if HVKC_HAVK_MIN_VERSION <= 6
                                    ,
                                    v6::PackMapCollideV6
#endif
#if HVKC_HAVK_MIN_VERSION <= 7
                                    ,
                                    v7::PackMapCollideV7
#endif
#if HVKC_HAVK_MIN_VERSION <= 8
                                    ,
                                    v8::PackMapCollideV8
#endif
#if HVKC_HAVK_MIN_VERSION <= 9
                                    ,
                                    v9::PackMapCollideV9
#endif
#if HVKC_HAVK_MIN_VERSION <= 10
                                    ,
                                    v10::PackMapCollideV10
#endif
#if HVKC_HAVK_MIN_VERSION <= 11
                                    ,
                                    v11::PackMapCollideV11
#endif
#if HVKC_HAVK_MIN_VERSION <= 12
                                    ,
                                    v12::PackMapCollideV12
#endif
#if HVKC_HAVK_MIN_VERSION <= 13
                                    ,
                                    v13::PackMapCollideV13
#endif
#if HVKC_HAVK_MIN_VERSION <= 14
                                    ,
                                    v14::PackMapCollideV14
#endif
#if HVKC_HAVK_MIN_VERSION <= 15
                                    ,
                                    v15::PackMapCollideV15
#endif
#if HVKC_HAVK_MIN_VERSION <= 16
                                    ,
                                    v16::PackMapCollideV16
#endif
                                    >;

} // namespace hvkC::havk

template <> struct Chunk<FourCC::hvkC, FourCC::havk> {
  using Type = hvkC::havk::PackMapCollide;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if HVKC_HAVK_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          hvkC::havk::v6::PackMapCollideV6>(buf, b64);
#endif
#if HVKC_HAVK_MIN_VERSION <= 7
    case 7:
      return de::Deserializer<Config>::template Parse<
          hvkC::havk::v7::PackMapCollideV7>(buf, b64);
#endif
#if HVKC_HAVK_MIN_VERSION <= 8
    case 8:
      return de::Deserializer<Config>::template Parse<
          hvkC::havk::v8::PackMapCollideV8>(buf, b64);
#endif
#if HVKC_HAVK_MIN_VERSION <= 9
    case 9:
      return de::Deserializer<Config>::template Parse<
          hvkC::havk::v9::PackMapCollideV9>(buf, b64);
#endif
#if HVKC_HAVK_MIN_VERSION <= 10
    case 10:
      return de::Deserializer<Config>::template Parse<
          hvkC::havk::v10::PackMapCollideV10>(buf, b64);
#endif
#if HVKC_HAVK_MIN_VERSION <= 11
    case 11:
      return de::Deserializer<Config>::template Parse<
          hvkC::havk::v11::PackMapCollideV11>(buf, b64);
#endif
#if HVKC_HAVK_MIN_VERSION <= 12
    case 12:
      return de::Deserializer<Config>::template Parse<
          hvkC::havk::v12::PackMapCollideV12>(buf, b64);
#endif
#if HVKC_HAVK_MIN_VERSION <= 13
    case 13:
      return de::Deserializer<Config>::template Parse<
          hvkC::havk::v13::PackMapCollideV13>(buf, b64);
#endif
#if HVKC_HAVK_MIN_VERSION <= 14
    case 14:
      return de::Deserializer<Config>::template Parse<
          hvkC::havk::v14::PackMapCollideV14>(buf, b64);
#endif
#if HVKC_HAVK_MIN_VERSION <= 15
    case 15:
      return de::Deserializer<Config>::template Parse<
          hvkC::havk::v15::PackMapCollideV15>(buf, b64);
#endif
#if HVKC_HAVK_MIN_VERSION <= 16
    case 16:
      return de::Deserializer<Config>::template Parse<
          hvkC::havk::v16::PackMapCollideV16>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
