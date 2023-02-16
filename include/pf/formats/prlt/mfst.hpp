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

#ifndef PRLT_MFST_MIN_VERSION
#define PRLT_MFST_MIN_VERSION 2
#endif

#include "mfst/mfst_v0.hpp"
#include "mfst/mfst_v1.hpp"
#include "mfst/mfst_v2.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace prlt::mfst {

using ContentPortalManifest = std::variant<std::monostate
#if PRLT_MFST_MIN_VERSION <= 0
                                           ,
                                           v0::ContentPortalManifestV0
#endif
#if PRLT_MFST_MIN_VERSION <= 1
                                           ,
                                           v1::ContentPortalManifestV1
#endif
#if PRLT_MFST_MIN_VERSION <= 2
                                           ,
                                           v2::ContentPortalManifest
#endif
                                           >;

} // namespace prlt::mfst

template <> struct Chunk<FourCC::prlt, FourCC::mfst> {
  using Type = prlt::mfst::ContentPortalManifest;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if PRLT_MFST_MIN_VERSION <= 0
    case 0:
      return de::Deserializer<Config>::template Parse<
          prlt::mfst::v0::ContentPortalManifestV0>(buf, b64);
#endif
#if PRLT_MFST_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          prlt::mfst::v1::ContentPortalManifestV1>(buf, b64);
#endif
#if PRLT_MFST_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          prlt::mfst::v2::ContentPortalManifest>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
