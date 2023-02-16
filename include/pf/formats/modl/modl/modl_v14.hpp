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

#if MODL_MODL_MIN_VERSION <= 14

#include "pf/types.hpp"

namespace pf {
namespace MODL::MODL::v14 {
struct ModelTextureDataV14 {
  pf::filename filename;
  pf::dword texture_flags;
  pf::qword token;
  pf::qword blit_id;
  pf::byte uv_anim_id;
  pf::byte uv_ps_input_index;
};

struct ModelConstantDataV14 {
  pf::dword name;
  pf::float4 value;
  pf::dword constant_flags;
};

struct ModelMaterialDataV14 {
  pf::filename filename;
  pf::dword material_flags;
  pf::dword sort_order;
  pf::byte tex_coord_count;
  std::vector<ModelTextureDataV14> textures;
  std::vector<ModelConstantDataV14> constants;
};

struct ModelMeshDataV14 {
  PackGrannyMeshType mesh;
  pf::dword flags;
  std::vector<pf::dword> vis_bone_indices;
  std::vector<pf::dword> seam_vert_indices;
  std::vector<pf::qword> action_offset_names;
  std::vector<pf::float3> action_offsets;
};

struct ModelTransformDataV14 {
  pf::dword flags;
  pf::float3 position;
  pf::float4 orientation;
  std::array<pf::float3, 3> scale_shear;
};

struct ModelBoneDataV14 {
  pf::cstring name;
  pf::dword parent_index;
  ModelTransformDataV14 local_transform;
  std::array<pf::float4, 4> inverse_world4x4;
  float lod_error;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
};

struct ModelSkeletonDataV14 {
  pf::cstring name;
  std::vector<ModelBoneDataV14> bones;
  pf::dword lod_type;
};

struct ModelMeshBindingDataV14 {
  std::shared_ptr<pf::byte> mesh;
};

struct ModelModelDataV14 {
  pf::cstring name;
  std::shared_ptr<ModelSkeletonDataV14> skeleton;
  ModelTransformDataV14 initial_placement;
  std::vector<ModelMeshBindingDataV14> mesh_bindings;
  std::vector<pf::dword> bone_flags;
};

struct ModelFloatPropertyDataV14 {
  pf::qword token;
  float value;
};

struct ModelPropertyDataV14 {
  std::vector<pf::qword> bool_tokens;
  std::vector<ModelFloatPropertyDataV14> float_values;
};

struct ModelParticleCloudV14 {
  pf::float3 acceleration;
  pf::qword bone;
  float drag;
  std::vector<pf::dword> emitter_indices;
  pf::dword flags;
  pf::dword material_index;
  std::vector<pf::dword> obstacle_indices;
};

struct ModelParticleCurveV14 {
  pf::byte curve_type;
  std::vector<pf::float2> keys;
};

struct ModelParticleFlipbookV14 {
  pf::byte columns;
  pf::byte count;
  pf::byte flags;
  pf::dword fps;
  pf::byte rows;
  pf::byte start;
};

struct ModelParticleEmitterV14 {
  std::array<pf::float2, 4> acceleration;
  pf::float2 acceleration_dist_range;
  pf::float2 acceleration_dist_speed;
  pf::qword bone;
  pf::float4 color_begin;
  pf::float4 color_end;
  pf::float2 color_period;
  float color_falloff;
  float drag;
  std::shared_ptr<ModelParticleCurveV14> opacity_curve;
  pf::dword opacity_curve_preset;
  pf::dword flags;
  std::shared_ptr<ModelParticleFlipbookV14> flipbook;
  pf::float2 lifetime;
  pf::float2 rotation_change;
  float rotation_drag;
  pf::float2 rotation_initial;
  std::array<pf::float2, 2> scale_change;
  std::array<pf::float2, 2> scale_initial;
  std::shared_ptr<ModelParticleCurveV14> scale_curve;
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

struct ModelParticleObstacleV14 {
  pf::qword bone;
  float drag_coef;
  pf::dword flags;
  pf::float3 geo_data;
  float gravity_coef;
  pf::byte response;
  pf::byte type;
  pf::dword vis_bone_index;
};

struct ModelCloudDataV14 {
  std::vector<ModelParticleCloudV14> clouds;
  std::vector<ModelParticleEmitterV14> emitters;
  std::vector<ModelParticleObstacleV14> obstacles;
};

struct ModelStreakV14 {
  std::vector<pf::dword> anchor_indices;
  pf::qword bone;
  pf::dword flags;
  pf::dword material_index;
  float spawn_freq;
  float stretch_dist;
  float tex_scale;
  pf::dword vis_bone_index;
};

struct ModelStreakAnchorV14 {
  pf::qword bone;
  pf::dword color;
  float falloff;
  float lifetime;
};

struct ModelStreakDataV14 {
  std::vector<ModelStreakV14> streaks;
  std::vector<ModelStreakAnchorV14> anchors;
};

struct ModelFileDataV14 {
  std::vector<std::shared_ptr<ModelMaterialDataV14>> materials;
  std::vector<std::shared_ptr<ModelMeshDataV14>> meshes;
  std::shared_ptr<ModelModelDataV14> model;
  std::shared_ptr<ModelPropertyDataV14> properties;
  std::shared_ptr<ModelCloudDataV14> cloud_data;
  std::shared_ptr<ModelStreakDataV14> streak_data;
};
} // namespace MODL::MODL::v14

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::MODL::v14::ModelTextureDataV14 &value) {
  reader(value.filename);
  reader(value.texture_flags);
  reader(value.token);
  reader(value.blit_id);
  reader(value.uv_anim_id);
  reader(value.uv_ps_input_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v14::ModelConstantDataV14 &value) {
  reader(value.name);
  reader(value.value);
  reader(value.constant_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v14::ModelMaterialDataV14 &value) {
  reader(value.filename);
  reader(value.material_flags);
  reader(value.sort_order);
  reader(value.tex_coord_count);
  reader(value.textures);
  reader(value.constants);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v14::ModelMeshDataV14 &value) {
  reader(value.mesh);
  reader(value.flags);
  reader(value.vis_bone_indices);
  reader(value.seam_vert_indices);
  reader(value.action_offset_names);
  reader(value.action_offsets);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v14::ModelTransformDataV14 &value) {
  reader(value.flags);
  reader(value.position);
  reader(value.orientation);
  reader(value.scale_shear);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v14::ModelBoneDataV14 &value) {
  reader(value.name);
  reader(value.parent_index);
  reader(value.local_transform);
  reader(value.inverse_world4x4);
  reader(value.lod_error);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v14::ModelSkeletonDataV14 &value) {
  reader(value.name);
  reader(value.bones);
  reader(value.lod_type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v14::ModelMeshBindingDataV14 &value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v14::ModelModelDataV14 &value) {
  reader(value.name);
  reader(value.skeleton);
  reader(value.initial_placement);
  reader(value.mesh_bindings);
  reader(value.bone_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v14::ModelFloatPropertyDataV14 &value) {
  reader(value.token);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v14::ModelPropertyDataV14 &value) {
  reader(value.bool_tokens);
  reader(value.float_values);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v14::ModelParticleCloudV14 &value) {
  reader(value.acceleration);
  reader(value.bone);
  reader(value.drag);
  reader(value.emitter_indices);
  reader(value.flags);
  reader(value.material_index);
  reader(value.obstacle_indices);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v14::ModelParticleCurveV14 &value) {
  reader(value.curve_type);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v14::ModelParticleFlipbookV14 &value) {
  reader(value.columns);
  reader(value.count);
  reader(value.flags);
  reader(value.fps);
  reader(value.rows);
  reader(value.start);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v14::ModelParticleEmitterV14 &value) {
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
void Read(Reader &reader, MODL::MODL::v14::ModelParticleObstacleV14 &value) {
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
void Read(Reader &reader, MODL::MODL::v14::ModelCloudDataV14 &value) {
  reader(value.clouds);
  reader(value.emitters);
  reader(value.obstacles);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v14::ModelStreakV14 &value) {
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
void Read(Reader &reader, MODL::MODL::v14::ModelStreakAnchorV14 &value) {
  reader(value.bone);
  reader(value.color);
  reader(value.falloff);
  reader(value.lifetime);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v14::ModelStreakDataV14 &value) {
  reader(value.streaks);
  reader(value.anchors);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v14::ModelFileDataV14 &value) {
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
