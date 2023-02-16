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

#if MAPC_HAVK_MIN_VERSION <= 8

#include "pf/types.hpp"

namespace pf {
namespace mapc::havk::v8 {
struct PackMapCollideMeshV8 {
  std::vector<pf::word> indices;
  std::vector<pf::float3> vertices;
  float mopp_code_scale;
  std::vector<pf::byte> mopp_code_data;
};

struct PackMapCollideMeshRefV8 {
  pf::qword sequence;
  pf::dword mesh_index;
};

struct PackMapCollideGeometryV8 {
  std::vector<PackMapCollideMeshRefV8> mesh_refs;
};

struct PackMapCollideModelPropV8 {
  pf::qword token;
  pf::qword sequence;
  float scale;
  pf::float3 translate;
  pf::float3 rotate;
  pf::dword geometry_index;
};

struct PackMapCollideModelZoneV8 {
  float scale;
  pf::float3 translate;
  pf::float3 rotate;
  pf::dword geometry_index;
};

struct PackMapCollideAiChunkV8 {
  std::vector<pf::byte> nav_mesh_data;
  std::vector<pf::byte> coarse_graph_data;
};

struct PackMapCollideV8 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  std::vector<PackMapCollideMeshV8> meshes;
  std::vector<PackMapCollideGeometryV8> geometries;
  std::vector<PackMapCollideModelPropV8> prop_models;
  std::vector<PackMapCollideModelZoneV8> zone_models;
  pf::float3 ai_boundary_min;
  pf::float3 ai_boundary_max;
  pf::dword2 ai_chunk_dims;
  std::vector<PackMapCollideAiChunkV8> ai_chunks;
};
} // namespace mapc::havk::v8

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::havk::v8::PackMapCollideMeshV8 &value) {
  reader(value.indices);
  reader(value.vertices);
  reader(value.mopp_code_scale);
  reader(value.mopp_code_data);
}

template <typename Reader>
void Read(Reader &reader, mapc::havk::v8::PackMapCollideMeshRefV8 &value) {
  reader(value.sequence);
  reader(value.mesh_index);
}

template <typename Reader>
void Read(Reader &reader, mapc::havk::v8::PackMapCollideGeometryV8 &value) {
  reader(value.mesh_refs);
}

template <typename Reader>
void Read(Reader &reader, mapc::havk::v8::PackMapCollideModelPropV8 &value) {
  reader(value.token);
  reader(value.sequence);
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, mapc::havk::v8::PackMapCollideModelZoneV8 &value) {
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, mapc::havk::v8::PackMapCollideAiChunkV8 &value) {
  reader(value.nav_mesh_data);
  reader(value.coarse_graph_data);
}

template <typename Reader>
void Read(Reader &reader, mapc::havk::v8::PackMapCollideV8 &value) {
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.meshes);
  reader(value.geometries);
  reader(value.prop_models);
  reader(value.zone_models);
  reader(value.ai_boundary_min);
  reader(value.ai_boundary_max);
  reader(value.ai_chunk_dims);
  reader(value.ai_chunks);
}
} // namespace de

} // namespace pf

#endif
