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

#if MODL_MODL_MIN_VERSION <= 3

#include "pf/types.hpp"

namespace pf {
namespace MODL::MODL::v3 {
struct ModelTextureDataV3 {
  pf::filename filename;
  pf::dword texture_flags;
  pf::qword token;
  pf::qword blit_id;
};

struct ModelConstantDataV3 {
  pf::dword name;
  pf::float4 value;
  pf::dword constant_flags;
};

struct ModelMaterialDataV3 {
  pf::filename filename;
  pf::dword material_flags;
  pf::dword sort_order;
  std::vector<ModelTextureDataV3> textures;
  std::vector<ModelConstantDataV3> constants;
};

struct ModelMeshDataV3 {
  PackGrannyMeshType mesh;
};

struct ModelAnimationDataV3 {
  pf::qword token;
  PackGrannyAnimationTypeV0 animation;
};

struct ModelTransformDataV3 {
  pf::dword flags;
  pf::float3 position;
  pf::float4 orientation;
  std::array<pf::float3, 3> scale_shear;
};

struct ModelBoneDataV3 {
  pf::cstring name;
  pf::dword parent_index;
  ModelTransformDataV3 local_transform;
  std::array<pf::float4, 4> inverse_world4x4;
  float lod_error;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
};

struct ModelSkeletonDataV3 {
  pf::cstring name;
  std::vector<ModelBoneDataV3> bones;
  pf::dword lod_type;
};

struct ModelMeshBindingDataV3 {
  std::shared_ptr<pf::byte> mesh;
};

struct ModelModelDataV3 {
  pf::cstring name;
  std::shared_ptr<ModelSkeletonDataV3> skeleton;
  ModelTransformDataV3 initial_placement;
  std::vector<ModelMeshBindingDataV3> mesh_bindings;
};

struct ModelFloatPropertyDataV3 {
  pf::qword token;
  float value;
};

struct ModelPropertyDataV3 {
  std::vector<pf::qword> bool_tokens;
  std::vector<ModelFloatPropertyDataV3> float_values;
};

struct ModelCollisionMeshV3 {
  pf::qword animation_sequence;
  std::vector<pf::float3> vertices;
  std::vector<pf::word> indices;
  std::vector<pf::byte> surfaces;
};

struct ModelCollisionCloudV3 {
  pf::qword animation_sequence;
  std::vector<pf::float3> points;
  pf::byte surface;
};

struct ModelCollisionCubeV3 {
  std::array<pf::float4, 3> transform;
  pf::byte surface;
};

struct ModelCollisionSphereV3 {
  float radius;
  pf::float3 position;
  pf::byte surface;
};

struct ModelCollisionSurfaceV3 {
  std::vector<pf::qword> tokens;
};

struct ModelCollisionDataV3 {
  std::vector<ModelCollisionMeshV3> meshes;
  std::vector<ModelCollisionCloudV3> clouds;
  std::vector<ModelCollisionCubeV3> cubes;
  std::vector<ModelCollisionSphereV3> spheres;
  std::vector<ModelCollisionSurfaceV3> surfaces;
};

struct ModelParticleFlipbookV3 {
  pf::byte columns;
  pf::byte count;
  pf::byte flags;
  pf::dword fps;
  pf::byte rows;
  pf::byte start;
};

struct ModelParticleCloudV3 {
  pf::float3 acceleration;
  pf::qword bone;
  float drag;
  std::vector<pf::dword> emitter_indices;
  std::vector<ModelParticleFlipbookV3> flipbook;
  pf::dword material_index;
  std::vector<pf::dword> obstacle_indices;
  pf::byte opacity_curve_type;
  std::vector<pf::float2> opacity_keys;
  pf::byte scale_curve_type;
  std::vector<pf::float2> scale_keys;
};

struct ModelParticleEmitterV3 {
  std::array<pf::float2, 4> acceleration;
  pf::qword bone;
  pf::float4 color_begin;
  pf::float4 color_end;
  pf::float2 color_period;
  pf::dword flags;
  pf::float2 lifetime;
  pf::float2 rotation_change;
  pf::float2 rotation_initial;
  std::array<pf::float2, 2> scale_change;
  std::array<pf::float2, 2> scale_initial;
  std::array<pf::float2, 4> velocity;
  pf::float2 velocity_dist_range;
  pf::float2 velocity_dist_speed;
  pf::float2 spawn_group_size;
  float spawn_period;
  float spawn_probability;
  pf::float2 spawn_radius;
  pf::byte spawn_shape;
};

struct ModelParticleObstacleV3 {
  pf::qword bone;
  float drag_coef;
  pf::dword flags;
  pf::float3 geo_data;
  float gravity_coef;
  pf::byte response;
  pf::byte type;
};

struct ModelCloudDataV3 {
  std::vector<ModelParticleCloudV3> clouds;
  std::vector<ModelParticleEmitterV3> emitters;
  std::vector<ModelParticleObstacleV3> obstacles;
};

struct ModelFileDataV3 {
  std::vector<std::shared_ptr<ModelMaterialDataV3>> materials;
  std::vector<std::shared_ptr<ModelMeshDataV3>> meshes;
  std::vector<std::shared_ptr<ModelAnimationDataV3>> animations;
  std::shared_ptr<ModelModelDataV3> model;
  std::shared_ptr<ModelPropertyDataV3> properties;
  std::shared_ptr<ModelCollisionDataV3> collision_data;
  std::shared_ptr<ModelCloudDataV3> cloud_data;
};
} // namespace MODL::MODL::v3

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelTextureDataV3 &value) {
  reader(value.filename);
  reader(value.texture_flags);
  reader(value.token);
  reader(value.blit_id);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelConstantDataV3 &value) {
  reader(value.name);
  reader(value.value);
  reader(value.constant_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelMaterialDataV3 &value) {
  reader(value.filename);
  reader(value.material_flags);
  reader(value.sort_order);
  reader(value.textures);
  reader(value.constants);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelMeshDataV3 &value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelAnimationDataV3 &value) {
  reader(value.token);
  reader(value.animation);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelTransformDataV3 &value) {
  reader(value.flags);
  reader(value.position);
  reader(value.orientation);
  reader(value.scale_shear);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelBoneDataV3 &value) {
  reader(value.name);
  reader(value.parent_index);
  reader(value.local_transform);
  reader(value.inverse_world4x4);
  reader(value.lod_error);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelSkeletonDataV3 &value) {
  reader(value.name);
  reader(value.bones);
  reader(value.lod_type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelMeshBindingDataV3 &value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelModelDataV3 &value) {
  reader(value.name);
  reader(value.skeleton);
  reader(value.initial_placement);
  reader(value.mesh_bindings);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelFloatPropertyDataV3 &value) {
  reader(value.token);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelPropertyDataV3 &value) {
  reader(value.bool_tokens);
  reader(value.float_values);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelCollisionMeshV3 &value) {
  reader(value.animation_sequence);
  reader(value.vertices);
  reader(value.indices);
  reader(value.surfaces);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelCollisionCloudV3 &value) {
  reader(value.animation_sequence);
  reader(value.points);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelCollisionCubeV3 &value) {
  reader(value.transform);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelCollisionSphereV3 &value) {
  reader(value.radius);
  reader(value.position);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelCollisionSurfaceV3 &value) {
  reader(value.tokens);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelCollisionDataV3 &value) {
  reader(value.meshes);
  reader(value.clouds);
  reader(value.cubes);
  reader(value.spheres);
  reader(value.surfaces);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelParticleFlipbookV3 &value) {
  reader(value.columns);
  reader(value.count);
  reader(value.flags);
  reader(value.fps);
  reader(value.rows);
  reader(value.start);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelParticleCloudV3 &value) {
  reader(value.acceleration);
  reader(value.bone);
  reader(value.drag);
  reader(value.emitter_indices);
  reader(value.flipbook);
  reader(value.material_index);
  reader(value.obstacle_indices);
  reader(value.opacity_curve_type);
  reader(value.opacity_keys);
  reader(value.scale_curve_type);
  reader(value.scale_keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelParticleEmitterV3 &value) {
  reader(value.acceleration);
  reader(value.bone);
  reader(value.color_begin);
  reader(value.color_end);
  reader(value.color_period);
  reader(value.flags);
  reader(value.lifetime);
  reader(value.rotation_change);
  reader(value.rotation_initial);
  reader(value.scale_change);
  reader(value.scale_initial);
  reader(value.velocity);
  reader(value.velocity_dist_range);
  reader(value.velocity_dist_speed);
  reader(value.spawn_group_size);
  reader(value.spawn_period);
  reader(value.spawn_probability);
  reader(value.spawn_radius);
  reader(value.spawn_shape);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelParticleObstacleV3 &value) {
  reader(value.bone);
  reader(value.drag_coef);
  reader(value.flags);
  reader(value.geo_data);
  reader(value.gravity_coef);
  reader(value.response);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelCloudDataV3 &value) {
  reader(value.clouds);
  reader(value.emitters);
  reader(value.obstacles);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v3::ModelFileDataV3 &value) {
  reader(value.materials);
  reader(value.meshes);
  reader(value.animations);
  reader(value.model);
  reader(value.properties);
  reader(value.collision_data);
  reader(value.cloud_data);
}
} // namespace de

} // namespace pf

#endif
