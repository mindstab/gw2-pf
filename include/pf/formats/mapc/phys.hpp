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

#ifndef MAPC_PHYS_MIN_VERSION
#define MAPC_PHYS_MIN_VERSION 10
#endif

#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"
#include "phys/phys_v1.hpp"
#include "phys/phys_v10.hpp"
#include "phys/phys_v2.hpp"
#include "phys/phys_v3.hpp"
#include "phys/phys_v4.hpp"
#include "phys/phys_v5.hpp"
#include "phys/phys_v6.hpp"
#include "phys/phys_v7.hpp"
#include "phys/phys_v8.hpp"
#include "phys/phys_v9.hpp"

namespace pf {
namespace mapc::phys {

using PackMapPhysics = std::variant<std::monostate
#if MAPC_PHYS_MIN_VERSION <= 1
                                    ,
                                    v1::PackMapPhysicsV1
#endif
#if MAPC_PHYS_MIN_VERSION <= 2
                                    ,
                                    v2::PackMapPhysicsV2
#endif
#if MAPC_PHYS_MIN_VERSION <= 3
                                    ,
                                    v3::PackMapPhysicsV3
#endif
#if MAPC_PHYS_MIN_VERSION <= 4
                                    ,
                                    v4::PackMapPhysicsV4
#endif
#if MAPC_PHYS_MIN_VERSION <= 5
                                    ,
                                    v5::PackMapPhysicsV5
#endif
#if MAPC_PHYS_MIN_VERSION <= 6
                                    ,
                                    v6::PackMapPhysicsV6
#endif
#if MAPC_PHYS_MIN_VERSION <= 7
                                    ,
                                    v7::PackMapPhysicsV7
#endif
#if MAPC_PHYS_MIN_VERSION <= 8
                                    ,
                                    v8::PackMapPhysicsV8
#endif
#if MAPC_PHYS_MIN_VERSION <= 9
                                    ,
                                    v9::PackMapPhysicsV9
#endif
#if MAPC_PHYS_MIN_VERSION <= 10
                                    ,
                                    v10::PackMapPhysicsV10
#endif
                                    >;

} // namespace mapc::phys

template <> struct Chunk<FourCC::mapc, FourCC::phys> {
  using Type = mapc::phys::PackMapPhysics;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if MAPC_PHYS_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          mapc::phys::v1::PackMapPhysicsV1>(buf, b64);
#endif
#if MAPC_PHYS_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          mapc::phys::v2::PackMapPhysicsV2>(buf, b64);
#endif
#if MAPC_PHYS_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          mapc::phys::v3::PackMapPhysicsV3>(buf, b64);
#endif
#if MAPC_PHYS_MIN_VERSION <= 4
    case 4:
      return de::Deserializer<Config>::template Parse<
          mapc::phys::v4::PackMapPhysicsV4>(buf, b64);
#endif
#if MAPC_PHYS_MIN_VERSION <= 5
    case 5:
      return de::Deserializer<Config>::template Parse<
          mapc::phys::v5::PackMapPhysicsV5>(buf, b64);
#endif
#if MAPC_PHYS_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          mapc::phys::v6::PackMapPhysicsV6>(buf, b64);
#endif
#if MAPC_PHYS_MIN_VERSION <= 7
    case 7:
      return de::Deserializer<Config>::template Parse<
          mapc::phys::v7::PackMapPhysicsV7>(buf, b64);
#endif
#if MAPC_PHYS_MIN_VERSION <= 8
    case 8:
      return de::Deserializer<Config>::template Parse<
          mapc::phys::v8::PackMapPhysicsV8>(buf, b64);
#endif
#if MAPC_PHYS_MIN_VERSION <= 9
    case 9:
      return de::Deserializer<Config>::template Parse<
          mapc::phys::v9::PackMapPhysicsV9>(buf, b64);
#endif
#if MAPC_PHYS_MIN_VERSION <= 10
    case 10:
      return de::Deserializer<Config>::template Parse<
          mapc::phys::v10::PackMapPhysicsV10>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
