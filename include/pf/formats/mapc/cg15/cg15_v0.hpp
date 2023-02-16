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

#if MAPC_CG15_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace mapc::cg15::v0 {
struct PackMapCoarseNavGraphNodeV0 {
  pf::dword material_id;
  pf::float3 bottom_left_bound;
  pf::float3 top_right_bound;
  pf::float3 centroid;
  std::vector<pf::dword> faces;
};

struct PackMapCoarseNavGraphConnectionEdgeV0 {
  pf::float3 edge_start;
  pf::float3 edge_end;
};

struct PackMapCoarseNavGraphConnectionV0 {
  pf::dword target_section_uid;
  pf::dword target_node_index;
  std::vector<PackMapCoarseNavGraphConnectionEdgeV0> edges;
};

struct PackMapCoarseNavGraphNodeConnectionsV0 {
  pf::dword node_index;
  std::vector<PackMapCoarseNavGraphConnectionV0> connections;
};

struct PackMapCoarseNavGraphSectionV0 {
  pf::dword section_uid;
  std::vector<PackMapCoarseNavGraphNodeV0> nodes;
  std::vector<PackMapCoarseNavGraphNodeConnectionsV0> node_connections;
};

struct PackMapCoarseNavGraphV0 {
  std::vector<PackMapCoarseNavGraphSectionV0> sections;
};
} // namespace mapc::cg15::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::cg15::v0::PackMapCoarseNavGraphNodeV0 &value) {
  reader(value.material_id);
  reader(value.bottom_left_bound);
  reader(value.top_right_bound);
  reader(value.centroid);
  reader(value.faces);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::cg15::v0::PackMapCoarseNavGraphConnectionEdgeV0 &value) {
  reader(value.edge_start);
  reader(value.edge_end);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::cg15::v0::PackMapCoarseNavGraphConnectionV0 &value) {
  reader(value.target_section_uid);
  reader(value.target_node_index);
  reader(value.edges);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::cg15::v0::PackMapCoarseNavGraphNodeConnectionsV0 &value) {
  reader(value.node_index);
  reader(value.connections);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::cg15::v0::PackMapCoarseNavGraphSectionV0 &value) {
  reader(value.section_uid);
  reader(value.nodes);
  reader(value.node_connections);
}

template <typename Reader>
void Read(Reader &reader, mapc::cg15::v0::PackMapCoarseNavGraphV0 &value) {
  reader(value.sections);
}
} // namespace de

} // namespace pf

#endif
