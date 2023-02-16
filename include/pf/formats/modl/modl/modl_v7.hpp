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

#if MODL_MODL_MIN_VERSION <= 7

#include "pf/types.hpp"

namespace pf {
namespace MODL::MODL::v7 {
struct ModelTextureDataV7 {
  pf::filename filename;
  pf::dword texture_flags;
  pf::qword token;
  pf::qword blit_id;
};

struct ModelConstantDataV7 {
  pf::dword name;
  pf::float4 value;
  pf::dword constant_flags;
};

struct ModelMaterialDataV7 {
  pf::filename filename;
  pf::dword material_flags;
  pf::dword sort_order;
  std::vector<ModelTextureDataV7> textures;
  std::vector<ModelConstantDataV7> constants;
};

struct ModelMeshDataV7 {
  PackGrannyMeshType mesh;
  pf::dword flags;
  std::vector<pf::dword> vis_bone_indices;
};

struct ModelVisTrackDataV7 {
  pf::dword bone_index;
  std::vector<float> keys;
};

struct ModelAnimationDataV7 {
  pf::qword token;
  PackGrannyAnimationTypeV0 animation;
  float move_speed;
  std::vector<ModelVisTrackDataV7> vis_track_data;
};

struct ModelAnimationImportDataV7 {
  pf::filename filename;
  std::vector<pf::qword> sequence_tokens;
};

struct ModelTransformDataV7 {
  pf::dword flags;
  pf::float3 position;
  pf::float4 orientation;
  std::array<pf::float3, 3> scale_shear;
};

struct ModelBoneDataV7 {
  pf::cstring name;
  pf::dword parent_index;
  ModelTransformDataV7 local_transform;
  std::array<pf::float4, 4> inverse_world4x4;
  float lod_error;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
};

struct ModelSkeletonDataV7 {
  pf::cstring name;
  std::vector<ModelBoneDataV7> bones;
  pf::dword lod_type;
};

struct ModelMeshBindingDataV7 {
  std::shared_ptr<pf::byte> mesh;
};

struct ModelModelDataV7 {
  pf::cstring name;
  std::shared_ptr<ModelSkeletonDataV7> skeleton;
  ModelTransformDataV7 initial_placement;
  std::vector<ModelMeshBindingDataV7> mesh_bindings;
  std::vector<pf::dword> bone_flags;
};

struct ModelFloatPropertyDataV7 {
  pf::qword token;
  float value;
};

struct ModelPropertyDataV7 {
  std::vector<pf::qword> bool_tokens;
  std::vector<ModelFloatPropertyDataV7> float_values;
};

struct ModelCollisionMeshV7 {
  pf::qword animation_sequence;
  std::vector<pf::float3> vertices;
  std::vector<pf::word> indices;
  std::vector<pf::byte> surfaces;
};

struct ModelCollisionCloudV7 {
  pf::qword animation_sequence;
  std::vector<pf::float3> points;
  pf::byte surface;
};

struct ModelCollisionCubeV7 {
  std::array<pf::float4, 3> transform;
  pf::byte surface;
};

struct ModelCollisionSphereV7 {
  float radius;
  pf::float3 position;
  pf::byte surface;
};

struct ModelCollisionSurfaceV7 {
  std::vector<pf::qword> tokens;
};

struct ModelCollisionDataV7 {
  std::vector<ModelCollisionMeshV7> meshes;
  std::vector<ModelCollisionCloudV7> clouds;
  std::vector<ModelCollisionCubeV7> cubes;
  std::vector<ModelCollisionSphereV7> spheres;
  std::vector<ModelCollisionSurfaceV7> surfaces;
};

struct ModelParticleFlipbookV7 {
  pf::byte columns;
  pf::byte count;
  pf::byte flags;
  pf::dword fps;
  pf::byte rows;
  pf::byte start;
};

struct ModelParticleCloudV7 {
  pf::float3 acceleration;
  pf::qword bone;
  float drag;
  std::vector<pf::dword> emitter_indices;
  pf::dword flags;
  std::vector<ModelParticleFlipbookV7> flipbook;
  pf::dword material_index;
  std::vector<pf::dword> obstacle_indices;
  pf::byte opacity_curve_type;
  std::vector<pf::float2> opacity_keys;
  pf::byte scale_curve_type;
  std::vector<pf::float2> scale_keys;
};

struct ModelParticleEmitterV7 {
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
  pf::dword vis_bone_index;
};

struct ModelParticleObstacleV7 {
  pf::qword bone;
  float drag_coef;
  pf::dword flags;
  pf::float3 geo_data;
  float gravity_coef;
  pf::byte response;
  pf::byte type;
  pf::dword vis_bone_index;
};

struct ModelCloudDataV7 {
  std::vector<ModelParticleCloudV7> clouds;
  std::vector<ModelParticleEmitterV7> emitters;
  std::vector<ModelParticleObstacleV7> obstacles;
};

struct ModelFileDataV7 {
  std::vector<std::shared_ptr<ModelMaterialDataV7>> materials;
  std::vector<std::shared_ptr<ModelMeshDataV7>> meshes;
  std::vector<std::shared_ptr<ModelAnimationDataV7>> animations;
  std::vector<pf::qword> animation_fallbacks;
  std::vector<ModelAnimationImportDataV7> animation_imports;
  std::shared_ptr<ModelModelDataV7> model;
  std::shared_ptr<ModelPropertyDataV7> properties;
  std::shared_ptr<ModelCollisionDataV7> collision_data;
  std::shared_ptr<ModelCloudDataV7> cloud_data;
};
} // namespace MODL::MODL::v7

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelTextureDataV7 &value) {
  reader(value.filename);
  reader(value.texture_flags);
  reader(value.token);
  reader(value.blit_id);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelConstantDataV7 &value) {
  reader(value.name);
  reader(value.value);
  reader(value.constant_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelMaterialDataV7 &value) {
  reader(value.filename);
  reader(value.material_flags);
  reader(value.sort_order);
  reader(value.textures);
  reader(value.constants);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelMeshDataV7 &value) {
  reader(value.mesh);
  reader(value.flags);
  reader(value.vis_bone_indices);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelVisTrackDataV7 &value) {
  reader(value.bone_index);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelAnimationDataV7 &value) {
  reader(value.token);
  reader(value.animation);
  reader(value.move_speed);
  reader(value.vis_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelAnimationImportDataV7 &value) {
  reader(value.filename);
  reader(value.sequence_tokens);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelTransformDataV7 &value) {
  reader(value.flags);
  reader(value.position);
  reader(value.orientation);
  reader(value.scale_shear);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelBoneDataV7 &value) {
  reader(value.name);
  reader(value.parent_index);
  reader(value.local_transform);
  reader(value.inverse_world4x4);
  reader(value.lod_error);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelSkeletonDataV7 &value) {
  reader(value.name);
  reader(value.bones);
  reader(value.lod_type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelMeshBindingDataV7 &value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelModelDataV7 &value) {
  reader(value.name);
  reader(value.skeleton);
  reader(value.initial_placement);
  reader(value.mesh_bindings);
  reader(value.bone_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelFloatPropertyDataV7 &value) {
  reader(value.token);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelPropertyDataV7 &value) {
  reader(value.bool_tokens);
  reader(value.float_values);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelCollisionMeshV7 &value) {
  reader(value.animation_sequence);
  reader(value.vertices);
  reader(value.indices);
  reader(value.surfaces);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelCollisionCloudV7 &value) {
  reader(value.animation_sequence);
  reader(value.points);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelCollisionCubeV7 &value) {
  reader(value.transform);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelCollisionSphereV7 &value) {
  reader(value.radius);
  reader(value.position);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelCollisionSurfaceV7 &value) {
  reader(value.tokens);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelCollisionDataV7 &value) {
  reader(value.meshes);
  reader(value.clouds);
  reader(value.cubes);
  reader(value.spheres);
  reader(value.surfaces);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelParticleFlipbookV7 &value) {
  reader(value.columns);
  reader(value.count);
  reader(value.flags);
  reader(value.fps);
  reader(value.rows);
  reader(value.start);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelParticleCloudV7 &value) {
  reader(value.acceleration);
  reader(value.bone);
  reader(value.drag);
  reader(value.emitter_indices);
  reader(value.flags);
  reader(value.flipbook);
  reader(value.material_index);
  reader(value.obstacle_indices);
  reader(value.opacity_curve_type);
  reader(value.opacity_keys);
  reader(value.scale_curve_type);
  reader(value.scale_keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelParticleEmitterV7 &value) {
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
  reader(value.vis_bone_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelParticleObstacleV7 &value) {
  reader(value.bone);
  reader(value.drag_coef);
  reader(value.flags);
  reader(value.geo_data);
  reader(value.gravity_coef);
  reader(value.response);
  reader(value.type);
  reader(value.vis_bone_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelCloudDataV7 &value) {
  reader(value.clouds);
  reader(value.emitters);
  reader(value.obstacles);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v7::ModelFileDataV7 &value) {
  reader(value.materials);
  reader(value.meshes);
  reader(value.animations);
  reader(value.animation_fallbacks);
  reader(value.animation_imports);
  reader(value.model);
  reader(value.properties);
  reader(value.collision_data);
  reader(value.cloud_data);
}
} // namespace de

} // namespace pf

#endif
