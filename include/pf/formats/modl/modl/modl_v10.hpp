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

#if MODL_MODL_MIN_VERSION <= 10

#include "pf/types.hpp"

namespace pf {
namespace MODL::MODL::v10 {
struct ModelTextureDataV10 {
  pf::filename filename;
  pf::dword texture_flags;
  pf::qword token;
  pf::qword blit_id;
  pf::byte uv_anim_id;
  pf::byte uv_ps_input_index;
};

struct ModelConstantDataV10 {
  pf::dword name;
  pf::float4 value;
  pf::dword constant_flags;
};

struct ModelMaterialDataV10 {
  pf::filename filename;
  pf::dword material_flags;
  pf::dword sort_order;
  pf::byte tex_coord_count;
  std::vector<ModelTextureDataV10> textures;
  std::vector<ModelConstantDataV10> constants;
};

struct ModelMeshDataV10 {
  PackGrannyMeshType mesh;
  pf::dword flags;
  std::vector<pf::dword> vis_bone_indices;
};

struct ModelTransformDataV10 {
  pf::dword flags;
  pf::float3 position;
  pf::float4 orientation;
  std::array<pf::float3, 3> scale_shear;
};

struct ModelBoneDataV10 {
  pf::cstring name;
  pf::dword parent_index;
  ModelTransformDataV10 local_transform;
  std::array<pf::float4, 4> inverse_world4x4;
  float lod_error;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
};

struct ModelSkeletonDataV10 {
  pf::cstring name;
  std::vector<ModelBoneDataV10> bones;
  pf::dword lod_type;
};

struct ModelMeshBindingDataV10 {
  std::shared_ptr<pf::byte> mesh;
};

struct ModelModelDataV10 {
  pf::cstring name;
  std::shared_ptr<ModelSkeletonDataV10> skeleton;
  ModelTransformDataV10 initial_placement;
  std::vector<ModelMeshBindingDataV10> mesh_bindings;
  std::vector<pf::dword> bone_flags;
};

struct ModelFloatPropertyDataV10 {
  pf::qword token;
  float value;
};

struct ModelPropertyDataV10 {
  std::vector<pf::qword> bool_tokens;
  std::vector<ModelFloatPropertyDataV10> float_values;
};

struct ModelParticleFlipbookV10 {
  pf::byte columns;
  pf::byte count;
  pf::byte flags;
  pf::dword fps;
  pf::byte rows;
  pf::byte start;
};

struct ModelParticleCloudV10 {
  pf::float3 acceleration;
  pf::qword bone;
  float drag;
  std::vector<pf::dword> emitter_indices;
  pf::dword flags;
  std::vector<ModelParticleFlipbookV10> flipbook;
  pf::dword material_index;
  std::vector<pf::dword> obstacle_indices;
  pf::byte opacity_curve_type;
  std::vector<pf::float2> opacity_keys;
  pf::byte scale_curve_type;
  std::vector<pf::float2> scale_keys;
};

struct ModelParticleEmitterV10 {
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

struct ModelParticleObstacleV10 {
  pf::qword bone;
  float drag_coef;
  pf::dword flags;
  pf::float3 geo_data;
  float gravity_coef;
  pf::byte response;
  pf::byte type;
  pf::dword vis_bone_index;
};

struct ModelCloudDataV10 {
  std::vector<ModelParticleCloudV10> clouds;
  std::vector<ModelParticleEmitterV10> emitters;
  std::vector<ModelParticleObstacleV10> obstacles;
};

struct ModelStreakV10 {
  std::vector<pf::dword> anchor_indices;
  pf::qword bone;
  pf::dword flags;
  pf::dword material_index;
  float spawn_freq;
  float stretch_dist;
  float tex_scale;
  pf::dword vis_bone_index;
};

struct ModelStreakAnchorV10 {
  pf::qword bone;
  pf::dword color;
  float falloff;
  float lifetime;
};

struct ModelStreakDataV10 {
  std::vector<ModelStreakV10> streaks;
  std::vector<ModelStreakAnchorV10> anchors;
};

struct ModelFileDataV10 {
  std::vector<std::shared_ptr<ModelMaterialDataV10>> materials;
  std::vector<std::shared_ptr<ModelMeshDataV10>> meshes;
  std::shared_ptr<ModelModelDataV10> model;
  std::shared_ptr<ModelPropertyDataV10> properties;
  std::shared_ptr<ModelCloudDataV10> cloud_data;
  std::shared_ptr<ModelStreakDataV10> streak_data;
};
} // namespace MODL::MODL::v10

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::MODL::v10::ModelTextureDataV10 &value) {
  reader(value.filename);
  reader(value.texture_flags);
  reader(value.token);
  reader(value.blit_id);
  reader(value.uv_anim_id);
  reader(value.uv_ps_input_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v10::ModelConstantDataV10 &value) {
  reader(value.name);
  reader(value.value);
  reader(value.constant_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v10::ModelMaterialDataV10 &value) {
  reader(value.filename);
  reader(value.material_flags);
  reader(value.sort_order);
  reader(value.tex_coord_count);
  reader(value.textures);
  reader(value.constants);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v10::ModelMeshDataV10 &value) {
  reader(value.mesh);
  reader(value.flags);
  reader(value.vis_bone_indices);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v10::ModelTransformDataV10 &value) {
  reader(value.flags);
  reader(value.position);
  reader(value.orientation);
  reader(value.scale_shear);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v10::ModelBoneDataV10 &value) {
  reader(value.name);
  reader(value.parent_index);
  reader(value.local_transform);
  reader(value.inverse_world4x4);
  reader(value.lod_error);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v10::ModelSkeletonDataV10 &value) {
  reader(value.name);
  reader(value.bones);
  reader(value.lod_type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v10::ModelMeshBindingDataV10 &value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v10::ModelModelDataV10 &value) {
  reader(value.name);
  reader(value.skeleton);
  reader(value.initial_placement);
  reader(value.mesh_bindings);
  reader(value.bone_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v10::ModelFloatPropertyDataV10 &value) {
  reader(value.token);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v10::ModelPropertyDataV10 &value) {
  reader(value.bool_tokens);
  reader(value.float_values);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v10::ModelParticleFlipbookV10 &value) {
  reader(value.columns);
  reader(value.count);
  reader(value.flags);
  reader(value.fps);
  reader(value.rows);
  reader(value.start);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v10::ModelParticleCloudV10 &value) {
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
void Read(Reader &reader, MODL::MODL::v10::ModelParticleEmitterV10 &value) {
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
void Read(Reader &reader, MODL::MODL::v10::ModelParticleObstacleV10 &value) {
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
void Read(Reader &reader, MODL::MODL::v10::ModelCloudDataV10 &value) {
  reader(value.clouds);
  reader(value.emitters);
  reader(value.obstacles);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v10::ModelStreakV10 &value) {
  reader(value.anchor_indices);
  reader(value.bone);
  reader(value.flags);
  reader(value.material_index);
  reader(value.spawn_freq);
  reader(value.stretch_dist);
  reader(value.tex_scale);
  reader(value.vis_bone_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v10::ModelStreakAnchorV10 &value) {
  reader(value.bone);
  reader(value.color);
  reader(value.falloff);
  reader(value.lifetime);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v10::ModelStreakDataV10 &value) {
  reader(value.streaks);
  reader(value.anchors);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v10::ModelFileDataV10 &value) {
  reader(value.materials);
  reader(value.meshes);
  reader(value.model);
  reader(value.properties);
  reader(value.cloud_data);
  reader(value.streak_data);
}
} // namespace de

} // namespace pf

#endif
