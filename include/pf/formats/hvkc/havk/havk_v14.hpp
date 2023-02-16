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

#if HVKC_HAVK_MIN_VERSION <= 14

#include "pf/types.hpp"

namespace pf {
namespace hvkC::havk::v14 {
struct PackMapCollideCollisionV14 {
  std::vector<pf::word> indices;
  std::vector<pf::float3> vertices;
  std::vector<pf::word> surfaces;
  PackMoppType mopp_code_data;
};

struct PackMapCollideBlockerV14 {
  std::vector<pf::float3> vertices;
};

struct PackMapCollideNavMeshV14 {
  std::vector<pf::byte> nav_mesh;
  std::vector<pf::byte> graph;
  std::vector<pf::byte> mediator;
};

struct PackMapCollideAnimationV14 {
  pf::qword sequence;
  std::vector<pf::dword> collision_indices;
  std::vector<pf::dword> blocker_indices;
};

struct PackMapCollideGeometryV14 {
  pf::byte quantized_extents;
  std::vector<pf::dword> animations;
  pf::word nav_mesh_index;
};

struct PackMapCollideModelObsV14 {
  pf::float3 translate;
  pf::dword geometry_index;
};

struct PackMapCollideModelPropV14 {
  pf::qword token;
  pf::qword sequence;
  float scale;
  pf::float3 translate;
  pf::float3 rotate;
  pf::dword geometry_index;
};

struct PackMapCollideModelZoneV14 {
  float scale;
  pf::float3 translate;
  pf::float3 rotate;
  pf::dword geometry_index;
};

struct PackMapCollideV14 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  std::vector<PackMapCollideCollisionV14> collisions;
  std::vector<PackMapCollideBlockerV14> blockers;
  std::vector<PackMapCollideNavMeshV14> nav_meshes;
  std::vector<PackMapCollideAnimationV14> animations;
  std::vector<PackMapCollideGeometryV14> geometries;
  std::vector<PackMapCollideModelObsV14> obs_models;
  std::vector<PackMapCollideModelPropV14> prop_models;
  std::vector<PackMapCollideModelZoneV14> zone_models;
};
} // namespace hvkC::havk::v14

namespace de {
template <typename Reader>
void Read(Reader &reader, hvkC::havk::v14::PackMapCollideCollisionV14 &value) {
  reader(value.indices);
  reader(value.vertices);
  reader(value.surfaces);
  reader(value.mopp_code_data);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v14::PackMapCollideBlockerV14 &value) {
  reader(value.vertices);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v14::PackMapCollideNavMeshV14 &value) {
  reader(value.nav_mesh);
  reader(value.graph);
  reader(value.mediator);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v14::PackMapCollideAnimationV14 &value) {
  reader(value.sequence);
  reader(value.collision_indices);
  reader(value.blocker_indices);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v14::PackMapCollideGeometryV14 &value) {
  reader(value.quantized_extents);
  reader(value.animations);
  reader(value.nav_mesh_index);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v14::PackMapCollideModelObsV14 &value) {
  reader(value.translate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v14::PackMapCollideModelPropV14 &value) {
  reader(value.token);
  reader(value.sequence);
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v14::PackMapCollideModelZoneV14 &value) {
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v14::PackMapCollideV14 &value) {
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.collisions);
  reader(value.blockers);
  reader(value.nav_meshes);
  reader(value.animations);
  reader(value.geometries);
  reader(value.obs_models);
  reader(value.prop_models);
  reader(value.zone_models);
}
} // namespace de

} // namespace pf

#endif
