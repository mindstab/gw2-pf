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

#ifndef MAPC_PNVM_MIN_VERSION
#define MAPC_PNVM_MIN_VERSION 2
#endif

#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"
#include "pnvm/pnvm_v0.hpp"
#include "pnvm/pnvm_v1.hpp"
#include "pnvm/pnvm_v2.hpp"

namespace pf {
namespace mapc::pnvm {

using PackMapPhysicsNavMesh = std::variant<std::monostate
#if MAPC_PNVM_MIN_VERSION <= 0
                                           ,
                                           v0::PackMapPhysicsNavMeshV0
#endif
#if MAPC_PNVM_MIN_VERSION <= 1
                                           ,
                                           v1::PackMapPhysicsNavMeshV1
#endif
#if MAPC_PNVM_MIN_VERSION <= 2
                                           ,
                                           v2::PackMapPhysicsNavMeshV2
#endif
                                           >;

} // namespace mapc::pnvm

template <> struct Chunk<FourCC::mapc, FourCC::pnvm> {
  using Type = mapc::pnvm::PackMapPhysicsNavMesh;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if MAPC_PNVM_MIN_VERSION <= 0
    case 0:
      return de::Deserializer<Config>::template Parse<
          mapc::pnvm::v0::PackMapPhysicsNavMeshV0>(buf, b64);
#endif
#if MAPC_PNVM_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          mapc::pnvm::v1::PackMapPhysicsNavMeshV1>(buf, b64);
#endif
#if MAPC_PNVM_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          mapc::pnvm::v2::PackMapPhysicsNavMeshV2>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
