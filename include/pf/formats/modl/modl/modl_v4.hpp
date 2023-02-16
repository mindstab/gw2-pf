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

#if MODL_MODL_MIN_VERSION <= 4

#include "pf/types.hpp"

namespace pf {
namespace MODL::MODL::v4 {
struct ModelTextureDataV4 {
  pf::filename filename;
  pf::dword texture_flags;
  pf::qword token;
  pf::qword blit_id;
};

struct ModelConstantDataV4 {
  pf::dword name;
  pf::float4 value;
  pf::dword constant_flags;
};

struct ModelMaterialDataV4 {
  pf::filename filename;
  pf::dword material_flags;
  pf::dword sort_order;
  std::vector<ModelTextureDataV4> textures;
  std::vector<ModelConstantDataV4> constants;
};

struct ModelMeshDataV4 {
  PackGrannyMeshType mesh;
  std::vector<pf::qword> vis_tokens;
};

struct ModelVisTrackDataV4 {
  pf::qword token;
  std::vector<float> keys;
};

struct ModelAnimationDataV4 {
  pf::qword token;
  PackGrannyAnimationTypeV0 animation;
  float move_speed;
  std::vector<ModelVisTrackDataV4> vis_track_data;
};

struct ModelTransformDataV4 {
  pf::dword flags;
  pf::float3 position;
  pf::float4 orientation;
  std::array<pf::float3, 3> scale_shear;
};

struct ModelBoneDataV4 {
  pf::cstring name;
  pf::dword parent_index;
  ModelTransformDataV4 local_transform;
  std::array<pf::float4, 4> inverse_world4x4;
  float lod_error;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
};

struct ModelSkeletonDataV4 {
  pf::cstring name;
  std::vector<ModelBoneDataV4> bones;
  pf::dword lod_type;
};

struct ModelMeshBindingDataV4 {
  std::shared_ptr<pf::byte> mesh;
};

struct ModelModelDataV4 {
  pf::cstring name;
  std::shared_ptr<ModelSkeletonDataV4> skeleton;
  ModelTransformDataV4 initial_placement;
  std::vector<ModelMeshBindingDataV4> mesh_bindings;
};

struct ModelFloatPropertyDataV4 {
  pf::qword token;
  float value;
};

struct ModelPropertyDataV4 {
  std::vector<pf::qword> bool_tokens;
  std::vector<ModelFloatPropertyDataV4> float_values;
};

struct ModelCollisionMeshV4 {
  pf::qword animation_sequence;
  std::vector<pf::float3> vertices;
  std::vector<pf::word> indices;
  std::vector<pf::byte> surfaces;
};

struct ModelCollisionCloudV4 {
  pf::qword animation_sequence;
  std::vector<pf::float3> points;
  pf::byte surface;
};

struct ModelCollisionCubeV4 {
  std::array<pf::float4, 3> transform;
  pf::byte surface;
};

struct ModelCollisionSphereV4 {
  float radius;
  pf::float3 position;
  pf::byte surface;
};

struct ModelCollisionSurfaceV4 {
  std::vector<pf::qword> tokens;
};

struct ModelCollisionDataV4 {
  std::vector<ModelCollisionMeshV4> meshes;
  std::vector<ModelCollisionCloudV4> clouds;
  std::vector<ModelCollisionCubeV4> cubes;
  std::vector<ModelCollisionSphereV4> spheres;
  std::vector<ModelCollisionSurfaceV4> surfaces;
};

struct ModelParticleFlipbookV4 {
  pf::byte columns;
  pf::byte count;
  pf::byte flags;
  pf::dword fps;
  pf::byte rows;
  pf::byte start;
};

struct ModelParticleCloudV4 {
  pf::float3 acceleration;
  pf::qword bone;
  float drag;
  std::vector<pf::dword> emitter_indices;
  std::vector<ModelParticleFlipbookV4> flipbook;
  pf::dword material_index;
  std::vector<pf::dword> obstacle_indices;
  pf::byte opacity_curve_type;
  std::vector<pf::float2> opacity_keys;
  pf::byte scale_curve_type;
  std::vector<pf::float2> scale_keys;
};

struct ModelParticleEmitterV4 {
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

struct ModelParticleObstacleV4 {
  pf::qword bone;
  float drag_coef;
  pf::dword flags;
  pf::float3 geo_data;
  float gravity_coef;
  pf::byte response;
  pf::byte type;
};

struct ModelCloudDataV4 {
  std::vector<ModelParticleCloudV4> clouds;
  std::vector<ModelParticleEmitterV4> emitters;
  std::vector<ModelParticleObstacleV4> obstacles;
};

struct ModelFileDataV4 {
  std::vector<std::shared_ptr<ModelMaterialDataV4>> materials;
  std::vector<std::shared_ptr<ModelMeshDataV4>> meshes;
  std::vector<std::shared_ptr<ModelAnimationDataV4>> animations;
  std::shared_ptr<ModelModelDataV4> model;
  std::shared_ptr<ModelPropertyDataV4> properties;
  std::shared_ptr<ModelCollisionDataV4> collision_data;
  std::shared_ptr<ModelCloudDataV4> cloud_data;
};
} // namespace MODL::MODL::v4

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelTextureDataV4 &value) {
  reader(value.filename);
  reader(value.texture_flags);
  reader(value.token);
  reader(value.blit_id);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelConstantDataV4 &value) {
  reader(value.name);
  reader(value.value);
  reader(value.constant_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelMaterialDataV4 &value) {
  reader(value.filename);
  reader(value.material_flags);
  reader(value.sort_order);
  reader(value.textures);
  reader(value.constants);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelMeshDataV4 &value) {
  reader(value.mesh);
  reader(value.vis_tokens);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelVisTrackDataV4 &value) {
  reader(value.token);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelAnimationDataV4 &value) {
  reader(value.token);
  reader(value.animation);
  reader(value.move_speed);
  reader(value.vis_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelTransformDataV4 &value) {
  reader(value.flags);
  reader(value.position);
  reader(value.orientation);
  reader(value.scale_shear);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelBoneDataV4 &value) {
  reader(value.name);
  reader(value.parent_index);
  reader(value.local_transform);
  reader(value.inverse_world4x4);
  reader(value.lod_error);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelSkeletonDataV4 &value) {
  reader(value.name);
  reader(value.bones);
  reader(value.lod_type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelMeshBindingDataV4 &value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelModelDataV4 &value) {
  reader(value.name);
  reader(value.skeleton);
  reader(value.initial_placement);
  reader(value.mesh_bindings);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelFloatPropertyDataV4 &value) {
  reader(value.token);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelPropertyDataV4 &value) {
  reader(value.bool_tokens);
  reader(value.float_values);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelCollisionMeshV4 &value) {
  reader(value.animation_sequence);
  reader(value.vertices);
  reader(value.indices);
  reader(value.surfaces);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelCollisionCloudV4 &value) {
  reader(value.animation_sequence);
  reader(value.points);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelCollisionCubeV4 &value) {
  reader(value.transform);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelCollisionSphereV4 &value) {
  reader(value.radius);
  reader(value.position);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelCollisionSurfaceV4 &value) {
  reader(value.tokens);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelCollisionDataV4 &value) {
  reader(value.meshes);
  reader(value.clouds);
  reader(value.cubes);
  reader(value.spheres);
  reader(value.surfaces);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelParticleFlipbookV4 &value) {
  reader(value.columns);
  reader(value.count);
  reader(value.flags);
  reader(value.fps);
  reader(value.rows);
  reader(value.start);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelParticleCloudV4 &value) {
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
void Read(Reader &reader, MODL::MODL::v4::ModelParticleEmitterV4 &value) {
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
void Read(Reader &reader, MODL::MODL::v4::ModelParticleObstacleV4 &value) {
  reader(value.bone);
  reader(value.drag_coef);
  reader(value.flags);
  reader(value.geo_data);
  reader(value.gravity_coef);
  reader(value.response);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelCloudDataV4 &value) {
  reader(value.clouds);
  reader(value.emitters);
  reader(value.obstacles);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v4::ModelFileDataV4 &value) {
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
