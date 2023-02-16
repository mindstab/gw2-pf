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

#ifndef AMAT_DX9S_MIN_VERSION
#define AMAT_DX9S_MIN_VERSION 11
#endif

#include "dx9s/dx9s_v0.hpp"
#include "dx9s/dx9s_v1.hpp"
#include "dx9s/dx9s_v10.hpp"
#include "dx9s/dx9s_v11.hpp"
#include "dx9s/dx9s_v2.hpp"
#include "dx9s/dx9s_v3.hpp"
#include "dx9s/dx9s_v4.hpp"
#include "dx9s/dx9s_v5.hpp"
#include "dx9s/dx9s_v6.hpp"
#include "dx9s/dx9s_v7.hpp"
#include "dx9s/dx9s_v8.hpp"
#include "dx9s/dx9s_v9.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace AMAT::DX9S {

using AmatDx9Material = std::variant<std::monostate
#if AMAT_DX9S_MIN_VERSION <= 0
                                     ,
                                     v0::AmatDx9MaterialV0
#endif
#if AMAT_DX9S_MIN_VERSION <= 1
                                     ,
                                     v1::AmatDx9MaterialV1
#endif
#if AMAT_DX9S_MIN_VERSION <= 2
                                     ,
                                     v2::AmatDx9MaterialV2
#endif
#if AMAT_DX9S_MIN_VERSION <= 3
                                     ,
                                     v3::AmatDx9MaterialV3
#endif
#if AMAT_DX9S_MIN_VERSION <= 4
                                     ,
                                     v4::AmatDx9MaterialV4
#endif
#if AMAT_DX9S_MIN_VERSION <= 5
                                     ,
                                     v5::AmatDx9MaterialV5
#endif
#if AMAT_DX9S_MIN_VERSION <= 6
                                     ,
                                     v6::AmatDx9MaterialV6
#endif
#if AMAT_DX9S_MIN_VERSION <= 7
                                     ,
                                     v7::AmatDx9MaterialV7
#endif
#if AMAT_DX9S_MIN_VERSION <= 8
                                     ,
                                     v8::AmatDx9MaterialV8
#endif
#if AMAT_DX9S_MIN_VERSION <= 9
                                     ,
                                     v9::AmatDx9MaterialV9
#endif
#if AMAT_DX9S_MIN_VERSION <= 10
                                     ,
                                     v10::AmatDx9MaterialV10
#endif
#if AMAT_DX9S_MIN_VERSION <= 11
                                     ,
                                     v11::AmatDx9MaterialV11
#endif
                                     >;

} // namespace AMAT::DX9S

template <> struct Chunk<FourCC::AMAT, FourCC::DX9S> {
  using Type = AMAT::DX9S::AmatDx9Material;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if AMAT_DX9S_MIN_VERSION <= 0
    case 0:
      return de::Deserializer<Config>::template Parse<
          AMAT::DX9S::v0::AmatDx9MaterialV0>(buf, b64);
#endif
#if AMAT_DX9S_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          AMAT::DX9S::v1::AmatDx9MaterialV1>(buf, b64);
#endif
#if AMAT_DX9S_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          AMAT::DX9S::v2::AmatDx9MaterialV2>(buf, b64);
#endif
#if AMAT_DX9S_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          AMAT::DX9S::v3::AmatDx9MaterialV3>(buf, b64);
#endif
#if AMAT_DX9S_MIN_VERSION <= 4
    case 4:
      return de::Deserializer<Config>::template Parse<
          AMAT::DX9S::v4::AmatDx9MaterialV4>(buf, b64);
#endif
#if AMAT_DX9S_MIN_VERSION <= 5
    case 5:
      return de::Deserializer<Config>::template Parse<
          AMAT::DX9S::v5::AmatDx9MaterialV5>(buf, b64);
#endif
#if AMAT_DX9S_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          AMAT::DX9S::v6::AmatDx9MaterialV6>(buf, b64);
#endif
#if AMAT_DX9S_MIN_VERSION <= 7
    case 7:
      return de::Deserializer<Config>::template Parse<
          AMAT::DX9S::v7::AmatDx9MaterialV7>(buf, b64);
#endif
#if AMAT_DX9S_MIN_VERSION <= 8
    case 8:
      return de::Deserializer<Config>::template Parse<
          AMAT::DX9S::v8::AmatDx9MaterialV8>(buf, b64);
#endif
#if AMAT_DX9S_MIN_VERSION <= 9
    case 9:
      return de::Deserializer<Config>::template Parse<
          AMAT::DX9S::v9::AmatDx9MaterialV9>(buf, b64);
#endif
#if AMAT_DX9S_MIN_VERSION <= 10
    case 10:
      return de::Deserializer<Config>::template Parse<
          AMAT::DX9S::v10::AmatDx9MaterialV10>(buf, b64);
#endif
#if AMAT_DX9S_MIN_VERSION <= 11
    case 11:
      return de::Deserializer<Config>::template Parse<
          AMAT::DX9S::v11::AmatDx9MaterialV11>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
