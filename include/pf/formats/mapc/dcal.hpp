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

#ifndef MAPC_DCAL_MIN_VERSION
#define MAPC_DCAL_MIN_VERSION 10
#endif

#include "dcal/dcal_v1.hpp"
#include "dcal/dcal_v10.hpp"
#include "dcal/dcal_v2.hpp"
#include "dcal/dcal_v3.hpp"
#include "dcal/dcal_v4.hpp"
#include "dcal/dcal_v5.hpp"
#include "dcal/dcal_v6.hpp"
#include "dcal/dcal_v7.hpp"
#include "dcal/dcal_v8.hpp"
#include "dcal/dcal_v9.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace mapc::dcal {

using PackMapDecals = std::variant<std::monostate
#if MAPC_DCAL_MIN_VERSION <= 1
                                   ,
                                   v1::PackMapDecalsV1
#endif
#if MAPC_DCAL_MIN_VERSION <= 2
                                   ,
                                   v2::PackMapDecalsV2
#endif
#if MAPC_DCAL_MIN_VERSION <= 3
                                   ,
                                   v3::PackMapDecalsV3
#endif
#if MAPC_DCAL_MIN_VERSION <= 4
                                   ,
                                   v4::PackMapDecalsV4
#endif
#if MAPC_DCAL_MIN_VERSION <= 5
                                   ,
                                   v5::PackMapDecalsV5
#endif
#if MAPC_DCAL_MIN_VERSION <= 6
                                   ,
                                   v6::PackMapDecalsV6
#endif
#if MAPC_DCAL_MIN_VERSION <= 7
                                   ,
                                   v7::PackMapDecalsV7
#endif
#if MAPC_DCAL_MIN_VERSION <= 8
                                   ,
                                   v8::PackMapDecalsV8
#endif
#if MAPC_DCAL_MIN_VERSION <= 9
                                   ,
                                   v9::PackMapDecalsV9
#endif
#if MAPC_DCAL_MIN_VERSION <= 10
                                   ,
                                   v10::PackMapDecalsV10
#endif
                                   >;

} // namespace mapc::dcal

template <> struct Chunk<FourCC::mapc, FourCC::dcal> {
  using Type = mapc::dcal::PackMapDecals;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if MAPC_DCAL_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          mapc::dcal::v1::PackMapDecalsV1>(buf, b64);
#endif
#if MAPC_DCAL_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          mapc::dcal::v2::PackMapDecalsV2>(buf, b64);
#endif
#if MAPC_DCAL_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          mapc::dcal::v3::PackMapDecalsV3>(buf, b64);
#endif
#if MAPC_DCAL_MIN_VERSION <= 4
    case 4:
      return de::Deserializer<Config>::template Parse<
          mapc::dcal::v4::PackMapDecalsV4>(buf, b64);
#endif
#if MAPC_DCAL_MIN_VERSION <= 5
    case 5:
      return de::Deserializer<Config>::template Parse<
          mapc::dcal::v5::PackMapDecalsV5>(buf, b64);
#endif
#if MAPC_DCAL_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          mapc::dcal::v6::PackMapDecalsV6>(buf, b64);
#endif
#if MAPC_DCAL_MIN_VERSION <= 7
    case 7:
      return de::Deserializer<Config>::template Parse<
          mapc::dcal::v7::PackMapDecalsV7>(buf, b64);
#endif
#if MAPC_DCAL_MIN_VERSION <= 8
    case 8:
      return de::Deserializer<Config>::template Parse<
          mapc::dcal::v8::PackMapDecalsV8>(buf, b64);
#endif
#if MAPC_DCAL_MIN_VERSION <= 9
    case 9:
      return de::Deserializer<Config>::template Parse<
          mapc::dcal::v9::PackMapDecalsV9>(buf, b64);
#endif
#if MAPC_DCAL_MIN_VERSION <= 10
    case 10:
      return de::Deserializer<Config>::template Parse<
          mapc::dcal::v10::PackMapDecalsV10>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
