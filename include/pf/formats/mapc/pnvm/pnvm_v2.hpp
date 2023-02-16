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

#if MAPC_PNVM_MIN_VERSION <= 2

#include "pf/types.hpp"

namespace pf {
namespace mapc::pnvm::v2 {
struct PackMapPhysicsNavMeshChunkV2 {
  std::vector<pf::byte> nav_mesh_data;
  std::vector<pf::byte> mediator_mopp_data;
  std::vector<pf::byte> coarse_graph_data;
};

struct PackMapPhysicsNavMeshV2 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  pf::dword2 chunk_dims;
  float erosion_radius;
  std::vector<PackMapPhysicsNavMeshChunkV2> chunk_array;
};
} // namespace mapc::pnvm::v2

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::pnvm::v2::PackMapPhysicsNavMeshChunkV2 &value) {
  reader(value.nav_mesh_data);
  reader(value.mediator_mopp_data);
  reader(value.coarse_graph_data);
}

template <typename Reader>
void Read(Reader &reader, mapc::pnvm::v2::PackMapPhysicsNavMeshV2 &value) {
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.chunk_dims);
  reader(value.erosion_radius);
  reader(value.chunk_array);
}
} // namespace de

} // namespace pf

#endif
