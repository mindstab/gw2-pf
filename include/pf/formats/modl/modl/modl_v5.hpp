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

#if MODL_MODL_MIN_VERSION <= 5

#include "pf/types.hpp"

namespace pf {
namespace MODL::MODL::v5 {
struct ModelTextureDataV5 {
  pf::filename filename;
  pf::dword texture_flags;
  pf::qword token;
  pf::qword blit_id;
};

struct ModelConstantDataV5 {
  pf::dword name;
  pf::float4 value;
  pf::dword constant_flags;
};

struct ModelMaterialDataV5 {
  pf::filename filename;
  pf::dword material_flags;
  pf::dword sort_order;
  std::vector<ModelTextureDataV5> textures;
  std::vector<ModelConstantDataV5> constants;
};

struct ModelMeshDataV5 {
  PackGrannyMeshType mesh;
  pf::dword flags;
  std::vector<pf::qword> vis_tokens;
};

struct ModelVisTrackDataV5 {
  pf::qword token;
  std::vector<float> keys;
};

struct ModelAnimationDataV5 {
  pf::qword token;
  PackGrannyAnimationTypeV0 animation;
  float move_speed;
  std::vector<ModelVisTrackDataV5> vis_track_data;
};

struct ModelTransformDataV5 {
  pf::dword flags;
  pf::float3 position;
  pf::float4 orientation;
  std::array<pf::float3, 3> scale_shear;
};

struct ModelBoneDataV5 {
  pf::cstring name;
  pf::dword parent_index;
  ModelTransformDataV5 local_transform;
  std::array<pf::float4, 4> inverse_world4x4;
  float lod_error;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
};

struct ModelSkeletonDataV5 {
  pf::cstring name;
  std::vector<ModelBoneDataV5> bones;
  pf::dword lod_type;
};

struct ModelMeshBindingDataV5 {
  std::shared_ptr<pf::byte> mesh;
};

struct ModelModelDataV5 {
  pf::cstring name;
  std::shared_ptr<ModelSkeletonDataV5> skeleton;
  ModelTransformDataV5 initial_placement;
  std::vector<ModelMeshBindingDataV5> mesh_bindings;
};

struct ModelFloatPropertyDataV5 {
  pf::qword token;
  float value;
};

struct ModelPropertyDataV5 {
  std::vector<pf::qword> bool_tokens;
  std::vector<ModelFloatPropertyDataV5> float_values;
};

struct ModelCollisionMeshV5 {
  pf::qword animation_sequence;
  std::vector<pf::float3> vertices;
  std::vector<pf::word> indices;
  std::vector<pf::byte> surfaces;
};

struct ModelCollisionCloudV5 {
  pf::qword animation_sequence;
  std::vector<pf::float3> points;
  pf::byte surface;
};

struct ModelCollisionCubeV5 {
  std::array<pf::float4, 3> transform;
  pf::byte surface;
};

struct ModelCollisionSphereV5 {
  float radius;
  pf::float3 position;
  pf::byte surface;
};

struct ModelCollisionSurfaceV5 {
  std::vector<pf::qword> tokens;
};

struct ModelCollisionDataV5 {
  std::vector<ModelCollisionMeshV5> meshes;
  std::vector<ModelCollisionCloudV5> clouds;
  std::vector<ModelCollisionCubeV5> cubes;
  std::vector<ModelCollisionSphereV5> spheres;
  std::vector<ModelCollisionSurfaceV5> surfaces;
};

struct ModelParticleFlipbookV5 {
  pf::byte columns;
  pf::byte count;
  pf::byte flags;
  pf::dword fps;
  pf::byte rows;
  pf::byte start;
};

struct ModelParticleCloudV5 {
  pf::float3 acceleration;
  pf::qword bone;
  float drag;
  std::vector<pf::dword> emitter_indices;
  pf::dword flags;
  std::vector<ModelParticleFlipbookV5> flipbook;
  pf::dword material_index;
  std::vector<pf::dword> obstacle_indices;
  pf::byte opacity_curve_type;
  std::vector<pf::float2> opacity_keys;
  pf::byte scale_curve_type;
  std::vector<pf::float2> scale_keys;
};

struct ModelParticleEmitterV5 {
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

struct ModelParticleObstacleV5 {
  pf::qword bone;
  float drag_coef;
  pf::dword flags;
  pf::float3 geo_data;
  float gravity_coef;
  pf::byte response;
  pf::byte type;
};

struct ModelCloudDataV5 {
  std::vector<ModelParticleCloudV5> clouds;
  std::vector<ModelParticleEmitterV5> emitters;
  std::vector<ModelParticleObstacleV5> obstacles;
};

struct ModelFileDataV5 {
  std::vector<std::shared_ptr<ModelMaterialDataV5>> materials;
  std::vector<std::shared_ptr<ModelMeshDataV5>> meshes;
  std::vector<std::shared_ptr<ModelAnimationDataV5>> animations;
  std::shared_ptr<ModelModelDataV5> model;
  std::shared_ptr<ModelPropertyDataV5> properties;
  std::shared_ptr<ModelCollisionDataV5> collision_data;
  std::shared_ptr<ModelCloudDataV5> cloud_data;
};
} // namespace MODL::MODL::v5

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelTextureDataV5 &value) {
  reader(value.filename);
  reader(value.texture_flags);
  reader(value.token);
  reader(value.blit_id);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelConstantDataV5 &value) {
  reader(value.name);
  reader(value.value);
  reader(value.constant_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelMaterialDataV5 &value) {
  reader(value.filename);
  reader(value.material_flags);
  reader(value.sort_order);
  reader(value.textures);
  reader(value.constants);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelMeshDataV5 &value) {
  reader(value.mesh);
  reader(value.flags);
  reader(value.vis_tokens);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelVisTrackDataV5 &value) {
  reader(value.token);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelAnimationDataV5 &value) {
  reader(value.token);
  reader(value.animation);
  reader(value.move_speed);
  reader(value.vis_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelTransformDataV5 &value) {
  reader(value.flags);
  reader(value.position);
  reader(value.orientation);
  reader(value.scale_shear);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelBoneDataV5 &value) {
  reader(value.name);
  reader(value.parent_index);
  reader(value.local_transform);
  reader(value.inverse_world4x4);
  reader(value.lod_error);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelSkeletonDataV5 &value) {
  reader(value.name);
  reader(value.bones);
  reader(value.lod_type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelMeshBindingDataV5 &value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelModelDataV5 &value) {
  reader(value.name);
  reader(value.skeleton);
  reader(value.initial_placement);
  reader(value.mesh_bindings);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelFloatPropertyDataV5 &value) {
  reader(value.token);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelPropertyDataV5 &value) {
  reader(value.bool_tokens);
  reader(value.float_values);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelCollisionMeshV5 &value) {
  reader(value.animation_sequence);
  reader(value.vertices);
  reader(value.indices);
  reader(value.surfaces);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelCollisionCloudV5 &value) {
  reader(value.animation_sequence);
  reader(value.points);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelCollisionCubeV5 &value) {
  reader(value.transform);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelCollisionSphereV5 &value) {
  reader(value.radius);
  reader(value.position);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelCollisionSurfaceV5 &value) {
  reader(value.tokens);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelCollisionDataV5 &value) {
  reader(value.meshes);
  reader(value.clouds);
  reader(value.cubes);
  reader(value.spheres);
  reader(value.surfaces);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelParticleFlipbookV5 &value) {
  reader(value.columns);
  reader(value.count);
  reader(value.flags);
  reader(value.fps);
  reader(value.rows);
  reader(value.start);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelParticleCloudV5 &value) {
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
void Read(Reader &reader, MODL::MODL::v5::ModelParticleEmitterV5 &value) {
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
void Read(Reader &reader, MODL::MODL::v5::ModelParticleObstacleV5 &value) {
  reader(value.bone);
  reader(value.drag_coef);
  reader(value.flags);
  reader(value.geo_data);
  reader(value.gravity_coef);
  reader(value.response);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelCloudDataV5 &value) {
  reader(value.clouds);
  reader(value.emitters);
  reader(value.obstacles);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v5::ModelFileDataV5 &value) {
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
