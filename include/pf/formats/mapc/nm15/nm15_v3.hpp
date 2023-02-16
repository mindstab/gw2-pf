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

#if MAPC_NM15_MIN_VERSION <= 3

#include "pf/types.hpp"

namespace pf {
namespace mapc::nm15::v3 {
struct PackMapNavMeshChunkV3 {
  pf::dword chunk_index;
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  std::vector<pf::byte> nav_mesh_data;
  std::vector<pf::byte> coarse_graph_data;
  std::vector<pf::byte> query_mediator_mopp_data;
};
} // namespace mapc::nm15::v3

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::nm15::v3::PackMapNavMeshChunkV3 &value) {
  reader(value.chunk_index);
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.nav_mesh_data);
  reader(value.coarse_graph_data);
  reader(value.query_mediator_mopp_data);
}
} // namespace de

} // namespace pf

#endif
