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

#if MAPC_NMEX_MIN_VERSION <= 2

#include "pf/types.hpp"

namespace pf {
namespace mapc::nmex::v2 {
struct PackMapNavMeshChunkExternalV2 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  pf::filename filename;
};

struct PackMapNavMeshMoverV2 {
  pf::qword map_prop_id;
  std::vector<pf::byte> nav_mesh_data;
  std::vector<pf::byte> coarse_graph_data;
  std::vector<pf::byte> mediator_data;
};

struct PackMapNavMeshExternalV2 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  pf::dword2 chunk_dims;
  std::vector<PackMapNavMeshChunkExternalV2> chunk_array;
  std::vector<PackMapNavMeshMoverV2> dynamic_array;
};
} // namespace mapc::nmex::v2

namespace de {
template <typename Reader>
void Read(Reader &reader,
          mapc::nmex::v2::PackMapNavMeshChunkExternalV2 &value) {
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.filename);
}

template <typename Reader>
void Read(Reader &reader, mapc::nmex::v2::PackMapNavMeshMoverV2 &value) {
  reader(value.map_prop_id);
  reader(value.nav_mesh_data);
  reader(value.coarse_graph_data);
  reader(value.mediator_data);
}

template <typename Reader>
void Read(Reader &reader, mapc::nmex::v2::PackMapNavMeshExternalV2 &value) {
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.chunk_dims);
  reader(value.chunk_array);
  reader(value.dynamic_array);
}
} // namespace de

} // namespace pf

#endif
