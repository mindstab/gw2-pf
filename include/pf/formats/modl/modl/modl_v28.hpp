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

#if MODL_MODL_MIN_VERSION <= 28

#include "pf/types.hpp"

namespace pf {
namespace MODL::MODL::v28 {
struct ModelTextureDataV28 {
  pf::filename filename;
  pf::dword texture_flags;
  pf::qword token;
  pf::qword blit_id;
  pf::byte uv_anim_id;
  pf::byte uv_ps_input_index;
};

struct ModelConstantDataV28 {
  pf::dword name;
  pf::float4 value;
  pf::dword constant_flags;
};

struct ModelMaterialDataV28 {
  pf::filename filename;
  pf::dword material_flags;
  pf::dword sort_order;
  pf::byte tex_coord_count;
  std::vector<ModelTextureDataV28> textures;
  std::vector<ModelConstantDataV28> constants;
};

struct ModelMeshLodDataV28 {
  std::vector<pf::word> indices;
};

struct ModelMeshMorphTargetV28 {
  std::vector<pf::word> position_indices;
  std::vector<pf::float3> positions;
  std::vector<pf::word> normal_indices;
  std::vector<pf::float3> normals;
  pf::cstring mesh_name;
};

struct ModelMeshDataV28 {
  std::vector<ModelMeshLodDataV28> lods;
  std::vector<ModelMeshMorphTargetV28> morph_targets;
  PackGrannyMeshType mesh;
  pf::dword flags;
  std::vector<pf::dword> vis_bone_indices;
  std::vector<pf::dword> seam_vert_indices;
  pf::qword mesh_name;
  pf::float3 min_bound;
  pf::float3 max_bound;
};

struct ModelTransformDataV28 {
  pf::dword flags;
  pf::float3 position;
  pf::float4 orientation;
  std::array<pf::float3, 3> scale_shear;
};

struct ModelBoneDataV28 {
  pf::cstring name;
  pf::dword parent_index;
  ModelTransformDataV28 local_transform;
  std::array<pf::float4, 4> inverse_world4x4;
  float lod_error;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
};

struct ModelSkeletonDataV28 {
  pf::cstring name;
  std::vector<ModelBoneDataV28> bones;
  pf::dword lod_type;
};

struct ModelMeshBindingDataV28 {
  std::shared_ptr<pf::byte> mesh;
};

struct ModelTrackMaskV28 {
  PackGrannyTrackMaskType track_mask;
  pf::qword token;
};

struct ModelModelDataV28 {
  pf::cstring name;
  std::shared_ptr<ModelSkeletonDataV28> skeleton;
  ModelTransformDataV28 initial_placement;
  std::vector<ModelMeshBindingDataV28> mesh_bindings;
  std::vector<pf::dword> bone_flags;
  std::vector<pf::dword> emitter_bones;
  std::vector<ModelTrackMaskV28> track_masks;
  std::vector<pf::byte> skeleton_hash;
  pf::float3 center;
  float radius;
};

struct ModelPropertyDataV28 {
  pf::qword id;
  pf::dword type;
  pf::dword merge_index;
  pf::qword val;
  pf::filename str_val;
};

struct ModelParticleCloudV28 {
  pf::float3 acceleration;
  pf::qword bone;
  float drag;
  std::vector<pf::dword> emitter_indices;
  pf::dword flags;
  pf::dword material_index;
  std::vector<pf::dword> obstacle_indices;
  pf::float3 velocity;
};

struct ModelParticleCurveV28 {
  pf::byte curve_type;
  std::vector<pf::float2> keys;
};

struct ModelParticleFlipbookV28 {
  pf::byte columns;
  pf::byte count;
  float fps;
  pf::byte rows;
  pf::byte start;
};

struct ModelParticleEmitterV28 {
  std::array<pf::float2, 4> acceleration;
  pf::float2 acceleration_dist_range;
  pf::float2 acceleration_dist_speed;
  pf::byte alignment_type;
  pf::float3 alignment_dir;
  pf::qword bone;
  pf::float4 color_begin;
  pf::float4 color_end;
  float color_period;
  pf::float2 color_falloff;
  float drag;
  pf::dword emitter_flags;
  std::shared_ptr<ModelParticleCurveV28> opacity_curve;
  pf::dword opacity_curve_preset;
  pf::dword flags;
  std::shared_ptr<ModelParticleFlipbookV28> flipbook;
  pf::float2 lifetime;
  pf::float2 rotation_change;
  float rotation_drag;
  pf::float2 rotation_initial;
  std::array<pf::float2, 2> scale_change;
  std::array<pf::float2, 2> scale_initial;
  std::shared_ptr<ModelParticleCurveV28> scale_curve;
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
  pf::byte wind_influence;
};

struct ModelCloudDataV28 {
  std::vector<ModelParticleCloudV28> clouds;
  std::vector<ModelParticleEmitterV28> emitters;
};

struct ModelObstacleDataV28 {
  pf::qword bone;
  float drag_coef;
  pf::dword flags;
  pf::float3 geo_data;
  float gravity_coef;
  pf::byte response;
  pf::byte type;
  pf::dword vis_bone_index;
};

struct ModelStreakV28 {
  pf::float3 acceleration;
  std::vector<pf::dword> anchor_indices;
  pf::qword bone;
  pf::dword flags;
  float jitter;
  pf::dword material_index;
  float noise;
  float spawn_dist;
  float stretch_dist;
  float tex_scale;
  pf::dword vis_bone_index;
  float wind;
};

struct ModelStreakAnchorV28 {
  pf::qword bone;
  pf::dword color;
  float falloff;
  float lifetime;
};

struct ModelStreakDataV28 {
  std::vector<ModelStreakV28> streaks;
  std::vector<ModelStreakAnchorV28> anchors;
};

struct ModelEffectLightV28 {
  pf::qword bone;
  std::array<pf::byte, 3> color;
  float far_distance;
  float intensity;
  float near_distance;
  pf::dword vis_bone_index;
};

struct ModelLightDataV28 {
  std::vector<ModelEffectLightV28> effect_lights;
};

struct ModelClothBoneWeightV28 {
  pf::qword token;
  pf::byte weight;
};

struct ModelClothMeshGroupV28 {
  std::vector<ModelClothBoneWeightV28> weights;
};

struct ModelClothConstraintV28 {
  pf::word vert_index_a;
  pf::word vert_index_b;
  float distance;
};

struct ModelClothDataV28 {
  pf::dword material_index;
  pf::byte flags;
  float gravity;
  float weight;
  float wind;
  pf::byte rigidness;
  PackVertexType mesh;
  std::vector<pf::word> indices;
  pf::word lock_count;
  std::vector<ModelClothMeshGroupV28> groups;
  std::vector<pf::byte> soft_locks;
  std::vector<ModelClothConstraintV28> lod0_constraints;
  std::vector<ModelClothConstraintV28> lod1_constraints;
  pf::word lod1_vertex_count;
  std::vector<pf::word> lod1_indices;
  std::vector<pf::float3> barycentric_coords;
  std::vector<pf::word> barycentric_indices;
};

struct ModelFileDataV28 {
  std::vector<std::shared_ptr<ModelMaterialDataV28>> materials;
  std::vector<std::shared_ptr<ModelMeshDataV28>> meshes;
  std::shared_ptr<ModelModelDataV28> model;
  std::vector<ModelPropertyDataV28> properties;
  std::shared_ptr<ModelCloudDataV28> cloud_data;
  std::vector<ModelObstacleDataV28> obstacles;
  std::shared_ptr<ModelStreakDataV28> streak_data;
  std::shared_ptr<ModelLightDataV28> light_data;
  std::vector<ModelClothDataV28> cloth_data;
  std::vector<pf::qword> action_offset_names;
  std::vector<pf::float3> action_offsets;
  std::array<float, 2> lod_override;
  pf::filename sound_script;
};
} // namespace MODL::MODL::v28

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelTextureDataV28 &value) {
  reader(value.filename);
  reader(value.texture_flags);
  reader(value.token);
  reader(value.blit_id);
  reader(value.uv_anim_id);
  reader(value.uv_ps_input_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelConstantDataV28 &value) {
  reader(value.name);
  reader(value.value);
  reader(value.constant_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelMaterialDataV28 &value) {
  reader(value.filename);
  reader(value.material_flags);
  reader(value.sort_order);
  reader(value.tex_coord_count);
  reader(value.textures);
  reader(value.constants);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelMeshLodDataV28 &value) {
  reader(value.indices);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelMeshMorphTargetV28 &value) {
  reader(value.position_indices);
  reader(value.positions);
  reader(value.normal_indices);
  reader(value.normals);
  reader(value.mesh_name);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelMeshDataV28 &value) {
  reader(value.lods);
  reader(value.morph_targets);
  reader(value.mesh);
  reader(value.flags);
  reader(value.vis_bone_indices);
  reader(value.seam_vert_indices);
  reader(value.mesh_name);
  reader(value.min_bound);
  reader(value.max_bound);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelTransformDataV28 &value) {
  reader(value.flags);
  reader(value.position);
  reader(value.orientation);
  reader(value.scale_shear);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelBoneDataV28 &value) {
  reader(value.name);
  reader(value.parent_index);
  reader(value.local_transform);
  reader(value.inverse_world4x4);
  reader(value.lod_error);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelSkeletonDataV28 &value) {
  reader(value.name);
  reader(value.bones);
  reader(value.lod_type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelMeshBindingDataV28 &value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelTrackMaskV28 &value) {
  reader(value.track_mask);
  reader(value.token);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelModelDataV28 &value) {
  reader(value.name);
  reader(value.skeleton);
  reader(value.initial_placement);
  reader(value.mesh_bindings);
  reader(value.bone_flags);
  reader(value.emitter_bones);
  reader(value.track_masks);
  reader(value.skeleton_hash);
  reader(value.center);
  reader(value.radius);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelPropertyDataV28 &value) {
  reader(value.id);
  reader(value.type);
  reader(value.merge_index);
  reader(value.val);
  reader(value.str_val);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelParticleCloudV28 &value) {
  reader(value.acceleration);
  reader(value.bone);
  reader(value.drag);
  reader(value.emitter_indices);
  reader(value.flags);
  reader(value.material_index);
  reader(value.obstacle_indices);
  reader(value.velocity);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelParticleCurveV28 &value) {
  reader(value.curve_type);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelParticleFlipbookV28 &value) {
  reader(value.columns);
  reader(value.count);
  reader(value.fps);
  reader(value.rows);
  reader(value.start);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelParticleEmitterV28 &value) {
  reader(value.acceleration);
  reader(value.acceleration_dist_range);
  reader(value.acceleration_dist_speed);
  reader(value.alignment_type);
  reader(value.alignment_dir);
  reader(value.bone);
  reader(value.color_begin);
  reader(value.color_end);
  reader(value.color_period);
  reader(value.color_falloff);
  reader(value.drag);
  reader(value.emitter_flags);
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
  reader(value.wind_influence);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelCloudDataV28 &value) {
  reader(value.clouds);
  reader(value.emitters);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelObstacleDataV28 &value) {
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
void Read(Reader &reader, MODL::MODL::v28::ModelStreakV28 &value) {
  reader(value.acceleration);
  reader(value.anchor_indices);
  reader(value.bone);
  reader(value.flags);
  reader(value.jitter);
  reader(value.material_index);
  reader(value.noise);
  reader(value.spawn_dist);
  reader(value.stretch_dist);
  reader(value.tex_scale);
  reader(value.vis_bone_index);
  reader(value.wind);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelStreakAnchorV28 &value) {
  reader(value.bone);
  reader(value.color);
  reader(value.falloff);
  reader(value.lifetime);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelStreakDataV28 &value) {
  reader(value.streaks);
  reader(value.anchors);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelEffectLightV28 &value) {
  reader(value.bone);
  reader(value.color);
  reader(value.far_distance);
  reader(value.intensity);
  reader(value.near_distance);
  reader(value.vis_bone_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelLightDataV28 &value) {
  reader(value.effect_lights);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelClothBoneWeightV28 &value) {
  reader(value.token);
  reader(value.weight);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelClothMeshGroupV28 &value) {
  reader(value.weights);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelClothConstraintV28 &value) {
  reader(value.vert_index_a);
  reader(value.vert_index_b);
  reader(value.distance);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelClothDataV28 &value) {
  reader(value.material_index);
  reader(value.flags);
  reader(value.gravity);
  reader(value.weight);
  reader(value.wind);
  reader(value.rigidness);
  reader(value.mesh);
  reader(value.indices);
  reader(value.lock_count);
  reader(value.groups);
  reader(value.soft_locks);
  reader(value.lod0_constraints);
  reader(value.lod1_constraints);
  reader(value.lod1_vertex_count);
  reader(value.lod1_indices);
  reader(value.barycentric_coords);
  reader(value.barycentric_indices);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v28::ModelFileDataV28 &value) {
  reader(value.materials);
  reader(value.meshes);
  reader(value.model);
  reader(value.properties);
  reader(value.cloud_data);
  reader(value.obstacles);
  reader(value.streak_data);
  reader(value.light_data);
  reader(value.cloth_data);
  reader(value.action_offset_names);
  reader(value.action_offsets);
  reader(value.lod_override);
  reader(value.sound_script);
}
} // namespace de

} // namespace pf

#endif
