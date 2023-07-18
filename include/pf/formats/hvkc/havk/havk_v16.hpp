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

#if HVKC_HAVK_MIN_VERSION <= 16

#include "pf/types.hpp"

namespace pf {
namespace hvkC::havk::v16 {
struct PackMapCollideCollisionV16 {
  std::vector<pf::word> indices;
  std::vector<pf::float3> vertices;
  std::vector<pf::word> surfaces;
  PackMoppType mopp_code_data;
};

struct PackMapCollideBlockerV16 {
  std::vector<pf::float3> vertices;
};

struct PackMapCollideAnimationV16 {
  pf::qword sequence;
  std::vector<pf::dword> collision_indices;
  std::vector<pf::dword> blocker_indices;
};

struct PackMapCollideGeometryV16 {
  pf::byte quantized_extents;
  std::vector<pf::dword> animations;
  pf::word nav_mesh_index;
};

struct PackMapCollideModelObsV16 {
  pf::float3 translate;
  pf::dword geometry_index;
};

struct PackMapCollideModelPropV16 {
  pf::qword token;
  pf::qword sequence;
  float scale;
  pf::float3 translate;
  pf::float3 rotate;
  pf::dword geometry_index;
};

struct PackMapCollideModelZoneV16 {
  float scale;
  pf::float3 translate;
  pf::float3 rotate;
  pf::dword geometry_index;
};

struct PackMapCollideWaterVolumeV16 {
  pf::qword guid;
  pf::wstring name;
  pf::dword flags;
  pf::float2 vertical_range;
  std::vector<pf::float2> vertices;
};

struct PackMapCollideV16 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  pf::dword flags;
  float water_surface_z;
  std::vector<PackMapCollideCollisionV16> collisions;
  std::vector<PackMapCollideBlockerV16> blockers;
  std::vector<PackMapCollideAnimationV16> animations;
  std::vector<PackMapCollideGeometryV16> geometries;
  std::vector<PackMapCollideModelObsV16> obs_models;
  std::vector<PackMapCollideModelPropV16> prop_models;
  std::vector<PackMapCollideModelZoneV16> zone_models;
  std::vector<PackMapCollideWaterVolumeV16> water_volumes;
};
} // namespace hvkC::havk::v16

namespace de {
template <typename Reader>
void Read(Reader &reader, hvkC::havk::v16::PackMapCollideCollisionV16 &value) {
  reader(value.indices);
  reader(value.vertices);
  reader(value.surfaces);
  reader(value.mopp_code_data);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v16::PackMapCollideBlockerV16 &value) {
  reader(value.vertices);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v16::PackMapCollideAnimationV16 &value) {
  reader(value.sequence);
  reader(value.collision_indices);
  reader(value.blocker_indices);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v16::PackMapCollideGeometryV16 &value) {
  reader(value.quantized_extents);
  reader(value.animations);
  reader(value.nav_mesh_index);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v16::PackMapCollideModelObsV16 &value) {
  reader(value.translate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v16::PackMapCollideModelPropV16 &value) {
  reader(value.token);
  reader(value.sequence);
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v16::PackMapCollideModelZoneV16 &value) {
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader,
          hvkC::havk::v16::PackMapCollideWaterVolumeV16 &value) {
  reader(value.guid);
  reader(value.name);
  reader(value.flags);
  reader(value.vertical_range);
  reader(value.vertices);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v16::PackMapCollideV16 &value) {
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
