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

#if HVKC_HAVK_MIN_VERSION <= 15

#include "pf/types.hpp"

namespace pf {
namespace hvkC::havk::v15 {
struct PackMapCollideCollisionV15 {
  std::vector<pf::word> indices;
  std::vector<pf::float3> vertices;
  std::vector<pf::word> surfaces;
  PackMoppType mopp_code_data;
};

struct PackMapCollideBlockerV15 {
  std::vector<pf::float3> vertices;
};

struct PackMapCollideAnimationV15 {
  pf::qword sequence;
  std::vector<pf::dword> collision_indices;
  std::vector<pf::dword> blocker_indices;
};

struct PackMapCollideGeometryV15 {
  pf::byte quantized_extents;
  std::vector<pf::dword> animations;
  pf::word nav_mesh_index;
};

struct PackMapCollideModelObsV15 {
  pf::float3 translate;
  pf::dword geometry_index;
};

struct PackMapCollideModelPropV15 {
  pf::qword token;
  pf::qword sequence;
  float scale;
  pf::float3 translate;
  pf::float3 rotate;
  pf::dword geometry_index;
};

struct PackMapCollideModelZoneV15 {
  float scale;
  pf::float3 translate;
  pf::float3 rotate;
  pf::dword geometry_index;
};

struct PackMapCollideWaterVolumeV15 {
  pf::qword guid;
  pf::dword flags;
  pf::float2 vertical_range;
  std::vector<pf::float2> vertices;
};

struct PackMapCollideV15 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  pf::dword flags;
  float water_surface_z;
  std::vector<PackMapCollideCollisionV15> collisions;
  std::vector<PackMapCollideBlockerV15> blockers;
  std::vector<PackMapCollideAnimationV15> animations;
  std::vector<PackMapCollideGeometryV15> geometries;
  std::vector<PackMapCollideModelObsV15> obs_models;
  std::vector<PackMapCollideModelPropV15> prop_models;
  std::vector<PackMapCollideModelZoneV15> zone_models;
  std::vector<PackMapCollideWaterVolumeV15> water_volumes;
};
} // namespace hvkC::havk::v15

namespace de {
template <typename Reader>
void Read(Reader &reader, hvkC::havk::v15::PackMapCollideCollisionV15 &value) {
  reader(value.indices);
  reader(value.vertices);
  reader(value.surfaces);
  reader(value.mopp_code_data);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v15::PackMapCollideBlockerV15 &value) {
  reader(value.vertices);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v15::PackMapCollideAnimationV15 &value) {
  reader(value.sequence);
  reader(value.collision_indices);
  reader(value.blocker_indices);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v15::PackMapCollideGeometryV15 &value) {
  reader(value.quantized_extents);
  reader(value.animations);
  reader(value.nav_mesh_index);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v15::PackMapCollideModelObsV15 &value) {
  reader(value.translate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v15::PackMapCollideModelPropV15 &value) {
  reader(value.token);
  reader(value.sequence);
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v15::PackMapCollideModelZoneV15 &value) {
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader,
          hvkC::havk::v15::PackMapCollideWaterVolumeV15 &value) {
  reader(value.guid);
  reader(value.flags);
  reader(value.vertical_range);
  reader(value.vertices);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v15::PackMapCollideV15 &value) {
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.flags);
  reader(value.water_surface_z);
  reader(value.collisions);
  reader(value.blockers);
  reader(value.animations);
  reader(value.geometries);
  reader(value.obs_models);
  reader(value.prop_models);
  reader(value.zone_models);
  reader(value.water_volumes);
}
} // namespace de

} // namespace pf

#endif
