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

#if MAPC_PHYS_MIN_VERSION <= 10

#include "pf/types.hpp"

namespace pf {
namespace mapc::phys::v10 {
struct PackMapPhysicsMeshV10 {
  std::vector<pf::word> index_array;
  std::vector<pf::float3> vertex_array;
  std::vector<pf::byte> mopp_code_data;
};

struct PackMapPhysicsObjectV10 {
  std::shared_ptr<PackMapPhysicsMeshV10> mesh;
  std::vector<pf::byte> scene_file_ptr;
};

struct PackMapPhysicsObjectRefV10 {
  pf::qword sequence;
  pf::dword object_index;
};

struct PackMapPhysicsGeometryV10 {
  pf::wstring file_path;
  pf::byte quantized_extents;
  std::vector<PackMapPhysicsObjectRefV10> obj_ref_array;
  std::vector<pf::word> surface;
};

struct PackMapPhysicsModelPropV10 {
  pf::qword token;
  float scale;
  pf::float3 translate;
  pf::float4 rotate;
  pf::dword geometry_index;
};

struct PackMapPhysicsModelZoneV8 {
  float scale;
  pf::float3 translate;
  pf::float4 rotate;
  pf::dword geometry_index;
};

struct PackMapPhysicsModelObstacleV10 {
  pf::float3 translate;
  pf::dword geometry_index;
};

struct PackMapPhysicsBlockV10 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  std::vector<PackMapPhysicsObjectV10> object_array;
  std::vector<PackMapPhysicsGeometryV10> geometry_array;
  std::vector<PackMapPhysicsModelPropV10> prop_model_array;
  std::vector<PackMapPhysicsModelPropV10> debris_model_array;
  std::vector<PackMapPhysicsModelZoneV8> zone_model_array;
  std::vector<PackMapPhysicsModelObstacleV10> obs_model_array;
};

struct PackMapPhysicsV10 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  std::vector<PackMapPhysicsBlockV10> block_array;
};
} // namespace mapc::phys::v10

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::phys::v10::PackMapPhysicsMeshV10 &value) {
  reader(value.index_array);
  reader(value.vertex_array);
  reader(value.mopp_code_data);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v10::PackMapPhysicsObjectV10 &value) {
  reader(value.mesh);
  reader(value.scene_file_ptr);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v10::PackMapPhysicsObjectRefV10 &value) {
  reader(value.sequence);
  reader(value.object_index);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v10::PackMapPhysicsGeometryV10 &value) {
  reader(value.file_path);
  reader(value.quantized_extents);
  reader(value.obj_ref_array);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v10::PackMapPhysicsModelPropV10 &value) {
  reader(value.token);
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v10::PackMapPhysicsModelZoneV8 &value) {
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::phys::v10::PackMapPhysicsModelObstacleV10 &value) {
  reader(value.translate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v10::PackMapPhysicsBlockV10 &value) {
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
void Read(Reader &reader, mapc::phys::v10::PackMapPhysicsV10 &value) {
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.block_array);
}
} // namespace de

} // namespace pf

#endif
