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

#ifndef MAPC_HAVK_MIN_VERSION
#define MAPC_HAVK_MIN_VERSION 14
#endif

#include "havk/havk_v10.hpp"
#include "havk/havk_v11.hpp"
#include "havk/havk_v12.hpp"
#include "havk/havk_v13.hpp"
#include "havk/havk_v14.hpp"
#include "havk/havk_v6.hpp"
#include "havk/havk_v7.hpp"
#include "havk/havk_v8.hpp"
#include "havk/havk_v9.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace mapc::havk {

using PackMapCollide = std::variant<std::monostate
#if MAPC_HAVK_MIN_VERSION <= 6
                                    ,
                                    v6::PackMapCollideV6
#endif
#if MAPC_HAVK_MIN_VERSION <= 7
                                    ,
                                    v7::PackMapCollideV7
#endif
#if MAPC_HAVK_MIN_VERSION <= 8
                                    ,
                                    v8::PackMapCollideV8
#endif
#if MAPC_HAVK_MIN_VERSION <= 9
                                    ,
                                    v9::PackMapCollideV9
#endif
#if MAPC_HAVK_MIN_VERSION <= 10
                                    ,
                                    v10::PackMapCollideV10
#endif
#if MAPC_HAVK_MIN_VERSION <= 11
                                    ,
                                    v11::PackMapCollideV11
#endif
#if MAPC_HAVK_MIN_VERSION <= 12
                                    ,
                                    v12::PackMapCollideV12
#endif
#if MAPC_HAVK_MIN_VERSION <= 13
                                    ,
                                    v13::PackMapCollideV13
#endif
#if MAPC_HAVK_MIN_VERSION <= 14
                                    ,
                                    v14::PackMapCollideV14
#endif
                                    >;

} // namespace mapc::havk

template <> struct Chunk<FourCC::mapc, FourCC::havk> {
  using Type = mapc::havk::PackMapCollide;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if MAPC_HAVK_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          mapc::havk::v6::PackMapCollideV6>(buf, b64);
#endif
#if MAPC_HAVK_MIN_VERSION <= 7
    case 7:
      return de::Deserializer<Config>::template Parse<
          mapc::havk::v7::PackMapCollideV7>(buf, b64);
#endif
#if MAPC_HAVK_MIN_VERSION <= 8
    case 8:
      return de::Deserializer<Config>::template Parse<
          mapc::havk::v8::PackMapCollideV8>(buf, b64);
#endif
#if MAPC_HAVK_MIN_VERSION <= 9
    case 9:
      return de::Deserializer<Config>::template Parse<
          mapc::havk::v9::PackMapCollideV9>(buf, b64);
#endif
#if MAPC_HAVK_MIN_VERSION <= 10
    case 10:
      return de::Deserializer<Config>::template Parse<
          mapc::havk::v10::PackMapCollideV10>(buf, b64);
#endif
#if MAPC_HAVK_MIN_VERSION <= 11
    case 11:
      return de::Deserializer<Config>::template Parse<
          mapc::havk::v11::PackMapCollideV11>(buf, b64);
#endif
#if MAPC_HAVK_MIN_VERSION <= 12
    case 12:
      return de::Deserializer<Config>::template Parse<
          mapc::havk::v12::PackMapCollideV12>(buf, b64);
#endif
#if MAPC_HAVK_MIN_VERSION <= 13
    case 13:
      return de::Deserializer<Config>::template Parse<
          mapc::havk::v13::PackMapCollideV13>(buf, b64);
#endif
#if MAPC_HAVK_MIN_VERSION <= 14
    case 14:
      return de::Deserializer<Config>::template Parse<
          mapc::havk::v14::PackMapCollideV14>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
