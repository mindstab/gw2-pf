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

#if MAPC_PHYS_MIN_VERSION <= 7

#include "pf/types.hpp"

namespace pf {
namespace mapc::phys::v7 {
struct PackMapPhysicsMeshV7 {
  std::vector<pf::word> index_array;
  std::vector<pf::float3> vertex_array;
  std::vector<pf::byte> mopp_code_data;
};

struct SceneBoxShapeV7 {
  pf::float3 dimensions;
  pf::float3 position;
  pf::float4 rotation;
};

struct SceneSphereShapeV7 {
  pf::float3 center;
  float radius;
};

struct SceneCapsuleShapeV7 {
  pf::float3 p0;
  pf::float3 p1;
  float radius;
};

struct SceneMeshShapeV7 {
  std::vector<pf::word> indices;
  std::vector<pf::float3> vertices;
  pf::float4 mopp_info;
  std::vector<pf::byte> mopp_bytes;
};

struct SceneFilePhysicsV7 {
  std::vector<SceneBoxShapeV7> boxes;
  std::vector<SceneSphereShapeV7> spheres;
  std::vector<SceneCapsuleShapeV7> capsules;
  std::vector<SceneMeshShapeV7> meshes;
};

struct ScenePathNodeV6 {
  pf::float3 position;
  pf::float4 rotation;
  pf::dword flags;
  float smoothing;
  pf::byte singlesided;
};

struct ScenePathV6 {
  std::vector<pf::qword> properties;
  std::vector<ScenePathNodeV6> points;
  pf::byte closed;
};

struct SceneEdgeV6 {
  std::array<pf::dword, 2> indices;
  std::vector<pf::dword> triangles;
};

struct SceneGameMeshV6 {
  std::vector<pf::word> indices;
  std::vector<pf::float3> vertices;
  std::vector<SceneEdgeV6> edges;
  pf::float4 mopp_info;
  std::vector<pf::byte> mopp_bytes;
  std::vector<pf::byte> surfaces;
};

struct SceneGameSurfaceV6 {
  std::vector<pf::qword> tokens;
};

struct SceneFileGameV6 {
  std::vector<ScenePathV6> paths;
  std::vector<SceneGameMeshV6> meshes;
  std::vector<SceneGameSurfaceV6> surfaces;
};

struct PackMapPhysicsObjectV7 {
  std::shared_ptr<PackMapPhysicsMeshV7> mesh;
  std::shared_ptr<SceneFilePhysicsV7> physics;
  std::shared_ptr<SceneFileGameV6> game;
};

struct PackMapPhysicsObjectRefV7 {
  pf::qword sequence;
  pf::dword object_index;
};

struct PackMapPhysicsGeometryV7 {
  pf::wstring file_path;
  pf::byte quantized_extents;
  std::vector<PackMapPhysicsObjectRefV7> obj_ref_array;
};

struct PackMapPhysicsModelPropV7 {
  pf::qword token;
  float scale;
  pf::float3 translate;
  pf::float4 rotate;
  pf::dword geometry_index;
};

struct PackMapPhysicsModelZoneV5 {
  float scale;
  pf::float3 translate;
  pf::float4 rotate;
  pf::dword geometry_index;
};

struct PackMapPhysicsModelObstacleV7 {
  pf::float3 translate;
  pf::dword geometry_index;
};

struct PackMapPhysicsBlockV7 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  std::vector<PackMapPhysicsObjectV7> object_array;
  std::vector<PackMapPhysicsGeometryV7> geometry_array;
  std::vector<PackMapPhysicsModelPropV7> prop_model_array;
  std::vector<PackMapPhysicsModelZoneV5> zone_model_array;
  std::vector<PackMapPhysicsModelObstacleV7> obs_model_array;
};

struct PackMapPhysicsV7 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  std::vector<PackMapPhysicsBlockV7> block_array;
};
} // namespace mapc::phys::v7

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::PackMapPhysicsMeshV7 &value) {
  reader(value.index_array);
  reader(value.vertex_array);
  reader(value.mopp_code_data);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::SceneBoxShapeV7 &value) {
  reader(value.dimensions);
  reader(value.position);
  reader(value.rotation);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::SceneSphereShapeV7 &value) {
  reader(value.center);
  reader(value.radius);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::SceneCapsuleShapeV7 &value) {
  reader(value.p0);
  reader(value.p1);
  reader(value.radius);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::SceneMeshShapeV7 &value) {
  reader(value.indices);
  reader(value.vertices);
  reader(value.mopp_info);
  reader(value.mopp_bytes);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::SceneFilePhysicsV7 &value) {
  reader(value.boxes);
  reader(value.spheres);
  reader(value.capsules);
  reader(value.meshes);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::ScenePathNodeV6 &value) {
  reader(value.position);
  reader(value.rotation);
  reader(value.flags);
  reader(value.smoothing);
  reader(value.singlesided);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::ScenePathV6 &value) {
  reader(value.properties);
  reader(value.points);
  reader(value.closed);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::SceneEdgeV6 &value) {
  reader(value.indices);
  reader(value.triangles);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::SceneGameMeshV6 &value) {
  reader(value.indices);
  reader(value.vertices);
  reader(value.edges);
  reader(value.mopp_info);
  reader(value.mopp_bytes);
  reader(value.surfaces);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::SceneGameSurfaceV6 &value) {
  reader(value.tokens);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::SceneFileGameV6 &value) {
  reader(value.paths);
  reader(value.meshes);
  reader(value.surfaces);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::PackMapPhysicsObjectV7 &value) {
  reader(value.mesh);
  reader(value.physics);
  reader(value.game);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::PackMapPhysicsObjectRefV7 &value) {
  reader(value.sequence);
  reader(value.object_index);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::PackMapPhysicsGeometryV7 &value) {
  reader(value.file_path);
  reader(value.quantized_extents);
  reader(value.obj_ref_array);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::PackMapPhysicsModelPropV7 &value) {
  reader(value.token);
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::PackMapPhysicsModelZoneV5 &value) {
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::phys::v7::PackMapPhysicsModelObstacleV7 &value) {
  reader(value.translate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::PackMapPhysicsBlockV7 &value) {
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.object_array);
  reader(value.geometry_array);
  reader(value.prop_model_array);
  reader(value.zone_model_array);
  reader(value.obs_model_array);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v7::PackMapPhysicsV7 &value) {
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.block_array);
}
} // namespace de

} // namespace pf

#endif
