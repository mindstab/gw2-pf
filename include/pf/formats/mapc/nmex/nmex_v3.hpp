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

#if MAPC_NMEX_MIN_VERSION <= 3

#include "pf/types.hpp"

namespace pf {
namespace mapc::nmex::v3 {
struct PackMapNavMeshChunkExternalV3 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  pf::filename filename;
};

struct PackMapNavMeshMoverV3 {
  pf::dword chunk_index;
  pf::qword map_prop_id;
  std::vector<pf::byte> nav_mesh_data;
  std::vector<pf::byte> coarse_graph_data;
  std::vector<pf::byte> mediator_data;
};

struct PackMapNavMeshExternalV3 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  pf::dword2 chunk_dims;
  std::vector<PackMapNavMeshChunkExternalV3> chunk_array;
  std::vector<PackMapNavMeshMoverV3> dynamic_array;
};
} // namespace mapc::nmex::v3

namespace de {
template <typename Reader>
void Read(Reader &reader,
          mapc::nmex::v3::PackMapNavMeshChunkExternalV3 &value) {
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.filename);
}

template <typename Reader>
void Read(Reader &reader, mapc::nmex::v3::PackMapNavMeshMoverV3 &value) {
  reader(value.chunk_index);
  reader(value.map_prop_id);
  reader(value.nav_mesh_data);
  reader(value.coarse_graph_data);
  reader(value.mediator_data);
}

template <typename Reader>
void Read(Reader &reader, mapc::nmex::v3::PackMapNavMeshExternalV3 &value) {
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.chunk_dims);
  reader(value.chunk_array);
  reader(value.dynamic_array);
}
} // namespace de

} // namespace pf

#endif
