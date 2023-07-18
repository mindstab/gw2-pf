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

#ifndef LOCL_GRFX_MIN_VERSION
#define LOCL_GRFX_MIN_VERSION 10
#endif

#include "grfx/grfx_v0.hpp"
#include "grfx/grfx_v1.hpp"
#include "grfx/grfx_v10.hpp"
#include "grfx/grfx_v2.hpp"
#include "grfx/grfx_v3.hpp"
#include "grfx/grfx_v4.hpp"
#include "grfx/grfx_v5.hpp"
#include "grfx/grfx_v6.hpp"
#include "grfx/grfx_v7.hpp"
#include "grfx/grfx_v8.hpp"
#include "grfx/grfx_v9.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace locl::grfx {

using PrefPackGraphics = std::variant<std::monostate
#if LOCL_GRFX_MIN_VERSION <= 0
                                      ,
                                      v0::PrefPackGraphics
#endif
#if LOCL_GRFX_MIN_VERSION <= 1
                                      ,
                                      v1::PrefPackGraphics
#endif
#if LOCL_GRFX_MIN_VERSION <= 2
                                      ,
                                      v2::PrefPackGraphics
#endif
#if LOCL_GRFX_MIN_VERSION <= 3
                                      ,
                                      v3::PrefPackGraphics
#endif
#if LOCL_GRFX_MIN_VERSION <= 4
                                      ,
                                      v4::PrefPackGraphics
#endif
#if LOCL_GRFX_MIN_VERSION <= 5
                                      ,
                                      v5::PrefPackGraphics
#endif
#if LOCL_GRFX_MIN_VERSION <= 6
                                      ,
                                      v6::PrefPackGraphics
#endif
#if LOCL_GRFX_MIN_VERSION <= 7
                                      ,
                                      v7::PrefPackGraphics
#endif
#if LOCL_GRFX_MIN_VERSION <= 8
                                      ,
                                      v8::PrefPackGraphics
#endif
#if LOCL_GRFX_MIN_VERSION <= 9
                                      ,
                                      v9::PrefPackGraphics
#endif
#if LOCL_GRFX_MIN_VERSION <= 10
                                      ,
                                      v10::PrefPackGraphics
#endif
                                      >;

} // namespace locl::grfx

template <> struct Chunk<FourCC::locl, FourCC::grfx> {
  using Type = locl::grfx::PrefPackGraphics;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if LOCL_GRFX_MIN_VERSION <= 0
    case 0:
      return de::Deserializer<Config>::template Parse<
          locl::grfx::v0::PrefPackGraphics>(buf, b64);
#endif
#if LOCL_GRFX_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          locl::grfx::v1::PrefPackGraphics>(buf, b64);
#endif
#if LOCL_GRFX_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          locl::grfx::v2::PrefPackGraphics>(buf, b64);
#endif
#if LOCL_GRFX_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          locl::grfx::v3::PrefPackGraphics>(buf, b64);
#endif
#if LOCL_GRFX_MIN_VERSION <= 4
    case 4:
      return de::Deserializer<Config>::template Parse<
          locl::grfx::v4::PrefPackGraphics>(buf, b64);
#endif
#if LOCL_GRFX_MIN_VERSION <= 5
    case 5:
      return de::Deserializer<Config>::template Parse<
          locl::grfx::v5::PrefPackGraphics>(buf, b64);
#endif
#if LOCL_GRFX_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          locl::grfx::v6::PrefPackGraphics>(buf, b64);
#endif
#if LOCL_GRFX_MIN_VERSION <= 7
    case 7:
      return de::Deserializer<Config>::template Parse<
          locl::grfx::v7::PrefPackGraphics>(buf, b64);
#endif
#if LOCL_GRFX_MIN_VERSION <= 8
    case 8:
      return de::Deserializer<Config>::template Parse<
          locl::grfx::v8::PrefPackGraphics>(buf, b64);
#endif
#if LOCL_GRFX_MIN_VERSION <= 9
    case 9:
      return de::Deserializer<Config>::template Parse<
          locl::grfx::v9::PrefPackGraphics>(buf, b64);
#endif
#if LOCL_GRFX_MIN_VERSION <= 10
    case 10:
      return de::Deserializer<Config>::template Parse<
          locl::grfx::v10::PrefPackGraphics>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
