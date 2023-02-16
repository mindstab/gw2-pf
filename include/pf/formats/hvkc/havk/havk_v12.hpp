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

#if HVKC_HAVK_MIN_VERSION <= 12

#include "pf/types.hpp"

namespace pf {
namespace hvkC::havk::v12 {
struct PackMapCollideMeshV12 {
  std::vector<pf::word> indices;
  std::vector<pf::float3> vertices;
  std::vector<pf::word> surfaces;
  float mopp_code_scale;
  std::vector<pf::byte> mopp_code_data;
};

struct PackMapCollideMeshRefV12 {
  pf::qword sequence;
  pf::dword mesh_index;
};

struct PackMapCollideGeometryV12 {
  pf::byte quantized_extents;
  std::vector<PackMapCollideMeshRefV12> mesh_refs;
};

struct PackMapCollideModelObsV12 {
  pf::float3 translate;
  pf::dword geometry_index;
};

struct PackMapCollideModelPropV12 {
  pf::qword token;
  pf::qword sequence;
  float scale;
  pf::float3 translate;
  pf::float3 rotate;
  pf::dword geometry_index;
};

struct PackMapCollideModelZoneV12 {
  float scale;
  pf::float3 translate;
  pf::float3 rotate;
  pf::dword geometry_index;
};

struct PackMapCollideAiChunkV12 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  std::vector<pf::byte> nav_mesh_data;
  std::vector<pf::byte> coarse_graph_data;
  std::vector<pf::byte> query_mediator_mopp_data;
};

struct PackMapCollideV12 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  std::vector<PackMapCollideMeshV12> meshes;
  std::vector<PackMapCollideGeometryV12> geometries;
  std::vector<PackMapCollideModelObsV12> obs_models;
  std::vector<PackMapCollideModelPropV12> prop_models;
  std::vector<PackMapCollideModelZoneV12> zone_models;
  pf::dword2 ai_chunk_dims;
  std::vector<PackMapCollideAiChunkV12> ai_chunks;
};
} // namespace hvkC::havk::v12

namespace de {
template <typename Reader>
void Read(Reader &reader, hvkC::havk::v12::PackMapCollideMeshV12 &value) {
  reader(value.indices);
  reader(value.vertices);
  reader(value.surfaces);
  reader(value.mopp_code_scale);
  reader(value.mopp_code_data);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v12::PackMapCollideMeshRefV12 &value) {
  reader(value.sequence);
  reader(value.mesh_index);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v12::PackMapCollideGeometryV12 &value) {
  reader(value.quantized_extents);
  reader(value.mesh_refs);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v12::PackMapCollideModelObsV12 &value) {
  reader(value.translate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v12::PackMapCollideModelPropV12 &value) {
  reader(value.token);
  reader(value.sequence);
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v12::PackMapCollideModelZoneV12 &value) {
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v12::PackMapCollideAiChunkV12 &value) {
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.nav_mesh_data);
  reader(value.coarse_graph_data);
  reader(value.query_mediator_mopp_data);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v12::PackMapCollideV12 &value) {
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.meshes);
  reader(value.geometries);
  reader(value.obs_models);
  reader(value.prop_models);
  reader(value.zone_models);
  reader(value.ai_chunk_dims);
  reader(value.ai_chunks);
}
} // namespace de

} // namespace pf

#endif
