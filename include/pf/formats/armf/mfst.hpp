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

#ifndef ARMF_MFST_MIN_VERSION
#define ARMF_MFST_MIN_VERSION 6
#endif

#include "mfst/mfst_v0.hpp"
#include "mfst/mfst_v1.hpp"
#include "mfst/mfst_v2.hpp"
#include "mfst/mfst_v3.hpp"
#include "mfst/mfst_v4.hpp"
#include "mfst/mfst_v5.hpp"
#include "mfst/mfst_v6.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace ARMF::MFST {

using PackAssetManifest = std::variant<std::monostate
#if ARMF_MFST_MIN_VERSION <= 0
                                       ,
                                       v0::PackAssetManifestV0
#endif
#if ARMF_MFST_MIN_VERSION <= 1
                                       ,
                                       v1::PackAssetManifestV1
#endif
#if ARMF_MFST_MIN_VERSION <= 2
                                       ,
                                       v2::PackAssetManifestV2
#endif
#if ARMF_MFST_MIN_VERSION <= 3
                                       ,
                                       v3::PackAssetManifestV3
#endif
#if ARMF_MFST_MIN_VERSION <= 4
                                       ,
                                       v4::PackAssetManifestV4
#endif
#if ARMF_MFST_MIN_VERSION <= 5
                                       ,
                                       v5::PackAssetManifestV5
#endif
#if ARMF_MFST_MIN_VERSION <= 6
                                       ,
                                       v6::PackAssetManifest
#endif
                                       >;

} // namespace ARMF::MFST

template <> struct Chunk<FourCC::ARMF, FourCC::MFST> {
  using Type = ARMF::MFST::PackAssetManifest;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if ARMF_MFST_MIN_VERSION <= 0
    case 0:
      return de::Deserializer<Config>::template Parse<
          ARMF::MFST::v0::PackAssetManifestV0>(buf, b64);
#endif
#if ARMF_MFST_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          ARMF::MFST::v1::PackAssetManifestV1>(buf, b64);
#endif
#if ARMF_MFST_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          ARMF::MFST::v2::PackAssetManifestV2>(buf, b64);
#endif
#if ARMF_MFST_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          ARMF::MFST::v3::PackAssetManifestV3>(buf, b64);
#endif
#if ARMF_MFST_MIN_VERSION <= 4
    case 4:
      return de::Deserializer<Config>::template Parse<
          ARMF::MFST::v4::PackAssetManifestV4>(buf, b64);
#endif
#if ARMF_MFST_MIN_VERSION <= 5
    case 5:
      return de::Deserializer<Config>::template Parse<
          ARMF::MFST::v5::PackAssetManifestV5>(buf, b64);
#endif
#if ARMF_MFST_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          ARMF::MFST::v6::PackAssetManifest>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
