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

#if MODL_MODL_MIN_VERSION <= 15

#include "pf/types.hpp"

namespace pf {
namespace MODL::MODL::v15 {
struct ModelTextureDataV15 {
  pf::filename filename;
  pf::dword texture_flags;
  pf::qword token;
  pf::qword blit_id;
  pf::byte uv_anim_id;
  pf::byte uv_ps_input_index;
};

struct ModelConstantDataV15 {
  pf::dword name;
  pf::float4 value;
  pf::dword constant_flags;
};

struct ModelMaterialDataV15 {
  pf::filename filename;
  pf::dword material_flags;
  pf::dword sort_order;
  pf::byte tex_coord_count;
  std::vector<ModelTextureDataV15> textures;
  std::vector<ModelConstantDataV15> constants;
};

struct ModelMeshLodDataV15 {
  std::vector<pf::word> indices;
};

struct ModelMeshDataV15 {
  std::vector<ModelMeshLodDataV15> lods;
  PackGrannyMeshType mesh;
  pf::dword flags;
  std::vector<pf::dword> vis_bone_indices;
  std::vector<pf::dword> seam_vert_indices;
};

struct ModelTransformDataV15 {
  pf::dword flags;
  pf::float3 position;
  pf::float4 orientation;
  std::array<pf::float3, 3> scale_shear;
};

struct ModelBoneDataV15 {
  pf::cstring name;
  pf::dword parent_index;
  ModelTransformDataV15 local_transform;
  std::array<pf::float4, 4> inverse_world4x4;
  float lod_error;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
};

struct ModelSkeletonDataV15 {
  pf::cstring name;
  std::vector<ModelBoneDataV15> bones;
  pf::dword lod_type;
};

struct ModelMeshBindingDataV15 {
  std::shared_ptr<pf::byte> mesh;
};

struct ModelModelDataV15 {
  pf::cstring name;
  std::shared_ptr<ModelSkeletonDataV15> skeleton;
  ModelTransformDataV15 initial_placement;
  std::vector<ModelMeshBindingDataV15> mesh_bindings;
  std::vector<pf::dword> bone_flags;
};

struct ModelFloatPropertyDataV15 {
  pf::qword token;
  float value;
};

struct ModelPropertyDataV15 {
  std::vector<pf::qword> bool_tokens;
  std::vector<ModelFloatPropertyDataV15> float_values;
};

struct ModelParticleCloudV15 {
  pf::float3 acceleration;
  pf::qword bone;
  float drag;
  std::vector<pf::dword> emitter_indices;
  pf::dword flags;
  pf::dword material_index;
  std::vector<pf::dword> obstacle_indices;
};

struct ModelParticleCurveV15 {
  pf::byte curve_type;
  std::vector<pf::float2> keys;
};

struct ModelParticleFlipbookV15 {
  pf::byte columns;
  pf::byte count;
  pf::byte flags;
  pf::dword fps;
  pf::byte rows;
  pf::byte start;
};

struct ModelParticleEmitterV15 {
  std::array<pf::float2, 4> acceleration;
  pf::float2 acceleration_dist_range;
  pf::float2 acceleration_dist_speed;
  pf::qword bone;
  pf::float4 color_begin;
  pf::float4 color_end;
  pf::float2 color_period;
  float color_falloff;
  float drag;
  std::shared_ptr<ModelParticleCurveV15> opacity_curve;
  pf::dword opacity_curve_preset;
  pf::dword flags;
  std::shared_ptr<ModelParticleFlipbookV15> flipbook;
  pf::float2 lifetime;
  pf::float2 rotation_change;
  float rotation_drag;
  pf::float2 rotation_initial;
  std::array<pf::float2, 2> scale_change;
  std::array<pf::float2, 2> scale_initial;
  std::shared_ptr<ModelParticleCurveV15> scale_curve;
  pf::dword scale_curve_preset;
  std::array<pf::float2, 4> velocity;
  pf::float2 velocity_dist_range;
  pf::float2 velocity_dist_speed;
  pf::float2 spawn_group_size;
  float spawn_period;
  float spawn_probability;
  pf::float2 spawn_radius;
  pf::byte spawn_shape;
  pf::float2 spawn_wind_emit;
  pf::float2 spawn_wind_speed;
  pf::float4 tex_coord_rect;
  pf::dword vis_bone_index;
};

struct ModelParticleObstacleV15 {
  pf::qword bone;
  float drag_coef;
  pf::dword flags;
  pf::float3 geo_data;
  float gravity_coef;
  pf::byte response;
  pf::byte type;
  pf::dword vis_bone_index;
};

struct ModelCloudDataV15 {
  std::vector<ModelParticleCloudV15> clouds;
  std::vector<ModelParticleEmitterV15> emitters;
  std::vector<ModelParticleObstacleV15> obstacles;
};

struct ModelStreakV15 {
  std::vector<pf::dword> anchor_indices;
  pf::qword bone;
  pf::dword flags;
  pf::dword material_index;
  float spawn_freq;
  float stretch_dist;
  float tex_scale;
  pf::dword vis_bone_index;
};

struct ModelStreakAnchorV15 {
  pf::qword bone;
  pf::dword color;
  float falloff;
  float lifetime;
};

struct ModelStreakDataV15 {
  std::vector<ModelStreakV15> streaks;
  std::vector<ModelStreakAnchorV15> anchors;
};

struct ModelEffectLightV15 {
  pf::qword bone;
  std::array<pf::byte, 4> color;
  pf::float2 ranges;
};

struct ModelLightDataV15 {
  std::vector<ModelEffectLightV15> effect_lights;
};

struct ModelFileDataV15 {
  std::vector<std::shared_ptr<ModelMaterialDataV15>> materials;
  std::vector<std::shared_ptr<ModelMeshDataV15>> meshes;
  std::shared_ptr<ModelModelDataV15> model;
  std::shared_ptr<ModelPropertyDataV15> properties;
  std::shared_ptr<ModelCloudDataV15> cloud_data;
  std::shared_ptr<ModelStreakDataV15> streak_data;
  std::shared_ptr<ModelLightDataV15> light_data;
  std::vector<pf::qword> action_offset_names;
  std::vector<pf::float3> action_offsets;
};
} // namespace MODL::MODL::v15

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelTextureDataV15 &value) {
  reader(value.filename);
  reader(value.texture_flags);
  reader(value.token);
  reader(value.blit_id);
  reader(value.uv_anim_id);
  reader(value.uv_ps_input_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelConstantDataV15 &value) {
  reader(value.name);
  reader(value.value);
  reader(value.constant_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelMaterialDataV15 &value) {
  reader(value.filename);
  reader(value.material_flags);
  reader(value.sort_order);
  reader(value.tex_coord_count);
  reader(value.textures);
  reader(value.constants);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelMeshLodDataV15 &value) {
  reader(value.indices);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelMeshDataV15 &value) {
  reader(value.lods);
  reader(value.mesh);
  reader(value.flags);
  reader(value.vis_bone_indices);
  reader(value.seam_vert_indices);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelTransformDataV15 &value) {
  reader(value.flags);
  reader(value.position);
  reader(value.orientation);
  reader(value.scale_shear);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelBoneDataV15 &value) {
  reader(value.name);
  reader(value.parent_index);
  reader(value.local_transform);
  reader(value.inverse_world4x4);
  reader(value.lod_error);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelSkeletonDataV15 &value) {
  reader(value.name);
  reader(value.bones);
  reader(value.lod_type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelMeshBindingDataV15 &value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelModelDataV15 &value) {
  reader(value.name);
  reader(value.skeleton);
  reader(value.initial_placement);
  reader(value.mesh_bindings);
  reader(value.bone_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelFloatPropertyDataV15 &value) {
  reader(value.token);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelPropertyDataV15 &value) {
  reader(value.bool_tokens);
  reader(value.float_values);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelParticleCloudV15 &value) {
  reader(value.acceleration);
  reader(value.bone);
  reader(value.drag);
  reader(value.emitter_indices);
  reader(value.flags);
  reader(value.material_index);
  reader(value.obstacle_indices);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelParticleCurveV15 &value) {
  reader(value.curve_type);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelParticleFlipbookV15 &value) {
  reader(value.columns);
  reader(value.count);
  reader(value.flags);
  reader(value.fps);
  reader(value.rows);
  reader(value.start);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelParticleEmitterV15 &value) {
  reader(value.acceleration);
  reader(value.acceleration_dist_range);
  reader(value.acceleration_dist_speed);
  reader(value.bone);
  reader(value.color_begin);
  reader(value.color_end);
  reader(value.color_period);
  reader(value.color_falloff);
  reader(value.drag);
  reader(value.opacity_curve);
  reader(value.opacity_curve_preset);
  reader(value.flags);
  reader(value.flipbook);
  reader(value.lifetime);
  reader(value.rotation_change);
  reader(value.rotation_drag);
  reader(value.rotation_initial);
  reader(value.scale_change);
  reader(value.scale_initial);
  reader(value.scale_curve);
  reader(value.scale_curve_preset);
  reader(value.velocity);
  reader(value.velocity_dist_range);
  reader(value.velocity_dist_speed);
  reader(value.spawn_group_size);
  reader(value.spawn_period);
  reader(value.spawn_probability);
  reader(value.spawn_radius);
  reader(value.spawn_shape);
  reader(value.spawn_wind_emit);
  reader(value.spawn_wind_speed);
  reader(value.tex_coord_rect);
  reader(value.vis_bone_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelParticleObstacleV15 &value) {
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
void Read(Reader &reader, MODL::MODL::v15::ModelCloudDataV15 &value) {
  reader(value.clouds);
  reader(value.emitters);
  reader(value.obstacles);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelStreakV15 &value) {
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
void Read(Reader &reader, MODL::MODL::v15::ModelStreakAnchorV15 &value) {
  reader(value.bone);
  reader(value.color);
  reader(value.falloff);
  reader(value.lifetime);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelStreakDataV15 &value) {
  reader(value.streaks);
  reader(value.anchors);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelEffectLightV15 &value) {
  reader(value.bone);
  reader(value.color);
  reader(value.ranges);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelLightDataV15 &value) {
  reader(value.effect_lights);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v15::ModelFileDataV15 &value) {
  reader(value.materials);
  reader(value.meshes);
  reader(value.model);
  reader(value.properties);
  reader(value.cloud_data);
  reader(value.streak_data);
  reader(value.light_data);
  reader(value.action_offset_names);
  reader(value.action_offsets);
}
} // namespace de

} // namespace pf

#endif
