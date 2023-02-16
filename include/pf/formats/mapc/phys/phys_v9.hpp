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

#if MAPC_PHYS_MIN_VERSION <= 9

#include "pf/types.hpp"

namespace pf {
namespace mapc::phys::v9 {
struct PackMapPhysicsMeshV9 {
  std::vector<pf::word> index_array;
  std::vector<pf::float3> vertex_array;
  std::vector<pf::byte> mopp_code_data;
};

struct PackMapPhysicsObjectV9 {
  std::shared_ptr<PackMapPhysicsMeshV9> mesh;
  std::vector<pf::byte> scene_file_ptr;
};

struct PackMapPhysicsObjectRefV9 {
  pf::qword sequence;
  pf::dword object_index;
};

struct PackMapPhysicsGeometryV9 {
  pf::wstring file_path;
  pf::byte quantized_extents;
  std::vector<PackMapPhysicsObjectRefV9> obj_ref_array;
};

struct PackMapPhysicsModelPropV9 {
  pf::qword token;
  float scale;
  pf::float3 translate;
  pf::float4 rotate;
  pf::dword geometry_index;
};

struct PackMapPhysicsModelZoneV7 {
  float scale;
  pf::float3 translate;
  pf::float4 rotate;
  pf::dword geometry_index;
};

struct PackMapPhysicsModelObstacleV9 {
  pf::float3 translate;
  pf::dword geometry_index;
};

struct PackMapPhysicsBlockV9 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  std::vector<PackMapPhysicsObjectV9> object_array;
  std::vector<PackMapPhysicsGeometryV9> geometry_array;
  std::vector<PackMapPhysicsModelPropV9> prop_model_array;
  std::vector<PackMapPhysicsModelPropV9> debris_model_array;
  std::vector<PackMapPhysicsModelZoneV7> zone_model_array;
  std::vector<PackMapPhysicsModelObstacleV9> obs_model_array;
};

struct PackMapPhysicsV9 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  std::vector<PackMapPhysicsBlockV9> block_array;
};
} // namespace mapc::phys::v9

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::phys::v9::PackMapPhysicsMeshV9 &value) {
  reader(value.index_array);
  reader(value.vertex_array);
  reader(value.mopp_code_data);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v9::PackMapPhysicsObjectV9 &value) {
  reader(value.mesh);
  reader(value.scene_file_ptr);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v9::PackMapPhysicsObjectRefV9 &value) {
  reader(value.sequence);
  reader(value.object_index);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v9::PackMapPhysicsGeometryV9 &value) {
  reader(value.file_path);
  reader(value.quantized_extents);
  reader(value.obj_ref_array);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v9::PackMapPhysicsModelPropV9 &value) {
  reader(value.token);
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v9::PackMapPhysicsModelZoneV7 &value) {
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::phys::v9::PackMapPhysicsModelObstacleV9 &value) {
  reader(value.translate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v9::PackMapPhysicsBlockV9 &value) {
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.object_array);
  reader(value.geometry_array);
  reader(value.prop_model_array);
  reader(value.debris_model_array);
  reader(value.zone_model_array);
  reader(value.obs_model_array);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v9::PackMapPhysicsV9 &value) {
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.block_array);
}
} // namespace de

} // namespace pf

#endif
