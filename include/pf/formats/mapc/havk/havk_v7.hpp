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

#if MAPC_HAVK_MIN_VERSION <= 7

#include "pf/types.hpp"

namespace pf {
namespace mapc::havk::v7 {
struct PackMapCollideMoppCodeV7 {
  std::vector<pf::byte> cooked_data;
};

struct PackMapCollideMeshSizeV7 {
  float scale;
  pf::dword mopp_code_index;
};

struct PackMapCollideMeshV7 {
  std::vector<pf::word> indices;
  std::vector<pf::float3> vertices;
  std::vector<PackMapCollideMeshSizeV7> sizes;
};

struct PackMapCollideMeshRefV7 {
  pf::qword sequence;
  pf::dword mesh_index;
};

struct PackMapCollideGeometryV7 {
  std::vector<PackMapCollideMeshRefV7> mesh_refs;
};

struct PackMapCollideModelPropV7 {
  pf::qword token;
  pf::qword sequence;
  float scale;
  pf::float3 translate;
  pf::float3 rotate;
  pf::dword geometry_index;
};

struct PackMapCollideModelZoneV7 {
  float scale;
  pf::float3 translate;
  pf::float3 rotate;
  pf::dword geometry_index;
};

struct PackMapCollideAiChunkV7 {
  std::vector<pf::byte> nav_mesh_data;
  std::vector<pf::byte> coarse_graph_data;
};

struct PackMapCollideV7 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  std::vector<PackMapCollideMoppCodeV7> mopp_codes;
  std::vector<PackMapCollideMeshV7> meshes;
  std::vector<PackMapCollideGeometryV7> geometries;
  std::vector<PackMapCollideModelPropV7> prop_models;
  std::vector<PackMapCollideModelZoneV7> zone_models;
  pf::float3 ai_boundary_min;
  pf::float3 ai_boundary_max;
  pf::dword2 ai_chunk_dims;
  std::vector<PackMapCollideAiChunkV7> ai_chunks;
};
} // namespace mapc::havk::v7

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::havk::v7::PackMapCollideMoppCodeV7 &value) {
  reader(value.cooked_data);
}

template <typename Reader>
void Read(Reader &reader, mapc::havk::v7::PackMapCollideMeshSizeV7 &value) {
  reader(value.scale);
  reader(value.mopp_code_index);
}

template <typename Reader>
void Read(Reader &reader, mapc::havk::v7::PackMapCollideMeshV7 &value) {
  reader(value.indices);
  reader(value.vertices);
  reader(value.sizes);
}

template <typename Reader>
void Read(Reader &reader, mapc::havk::v7::PackMapCollideMeshRefV7 &value) {
  reader(value.sequence);
  reader(value.mesh_index);
}

template <typename Reader>
void Read(Reader &reader, mapc::havk::v7::PackMapCollideGeometryV7 &value) {
  reader(value.mesh_refs);
}

template <typename Reader>
void Read(Reader &reader, mapc::havk::v7::PackMapCollideModelPropV7 &value) {
  reader(value.token);
  reader(value.sequence);
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, mapc::havk::v7::PackMapCollideModelZoneV7 &value) {
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, mapc::havk::v7::PackMapCollideAiChunkV7 &value) {
  reader(value.nav_mesh_data);
  reader(value.coarse_graph_data);
}

template <typename Reader>
void Read(Reader &reader, mapc::havk::v7::PackMapCollideV7 &value) {
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.mopp_codes);
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
