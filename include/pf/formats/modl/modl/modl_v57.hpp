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

#if MODL_MODL_MIN_VERSION <= 57

#include "pf/types.hpp"

namespace pf {
namespace MODL::MODL::v57 {
struct ModelTextureDataV57 {
  pf::filename filename;
  pf::dword texture_flags;
  pf::qword token;
  pf::qword blit_id;
  pf::dword uv_anim_id;
  pf::byte uv_ps_input_index;
};

struct ModelConstantDataV57 {
  pf::dword name;
  pf::float4 value;
  pf::dword constant_flags;
};

struct ModelMatConstLinkV57 {
  pf::qword link_token;
  pf::dword constant_token;
};

struct ModelUVTransLinkV57 {
  pf::qword link_token;
  pf::dword uv_anim_id;
  pf::byte type;
};

struct ModelMaterialTexTransformV57 {
  pf::byte random;
  pf::byte uv_index;
  pf::byte columns;
  pf::byte rows;
  pf::word count;
  float fps;
  pf::float2 scroll;
};

struct ModelMaterialDataV57 {
  pf::qword token;
  pf::dword material_id;
  pf::filename filename;
  pf::dword material_flags;
  pf::dword sort_order;
  std::vector<ModelTextureDataV57> textures;
  std::vector<ModelConstantDataV57> constants;
  std::vector<ModelMatConstLinkV57> mat_const_links;
  std::vector<ModelUVTransLinkV57> uv_trans_links;
  std::vector<ModelMaterialTexTransformV57> tex_transforms;
  pf::byte tex_coord_count;
};

struct ModelPermutationDataV57 {
  pf::qword token;
  std::vector<std::shared_ptr<ModelMaterialDataV57>> materials;
};

struct ModelMeshLodDataV57 {
  std::vector<pf::word> indices;
};

struct ModelMeshMorphVertV57 {
  pf::word index;
  pf::float3 vector;
};

struct ModelMeshMorphTargetV57 {
  std::vector<ModelMeshMorphVertV57> positions;
  std::vector<ModelMeshMorphVertV57> normals;
  pf::qword mesh;
};

struct GrBoundData {
  pf::float3 center;
  pf::float3 box_extent;
  float sphere_radius;
};

struct ModelMeshDataV57 {
  pf::qword vis_bone;
  std::vector<ModelMeshLodDataV57> lods;
  std::vector<ModelMeshMorphTargetV57> morph_targets;
  PackGrannyMeshType mesh;
  pf::dword flags;
  std::vector<pf::dword> seam_vert_indices;
  pf::qword mesh_name;
  pf::float3 min_bound;
  pf::float3 max_bound;
  std::vector<GrBoundData> bounds;
  pf::dword material_index;
  pf::cstring material_name;
};

struct ModelTransformDataV57 {
  pf::dword flags;
  pf::float3 position;
  pf::float4 orientation;
  std::array<pf::float3, 3> scale_shear;
};

struct ModelBoneDataV57 {
  pf::cstring name;
  pf::dword parent_index;
  ModelTransformDataV57 local_transform;
  std::array<pf::float4, 4> inverse_world4x4;
  float lod_error;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
};

struct ModelBoneSymmetryV57 {
  pf::qword bone_left;
  pf::qword bone_right;
};

struct ModelSkeletonDataV57 {
  pf::cstring name;
  std::vector<ModelBoneDataV57> bones;
  pf::dword lod_type;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
  std::vector<ModelBoneSymmetryV57> bone_symmetries;
};

struct ModelMeshBindingDataV57 {
  std::shared_ptr<pf::byte> mesh;
};

struct ModelTrackMaskV57 {
  PackGrannyTrackMaskType track_mask;
  pf::qword token;
};

struct ModelModelDataV57 {
  pf::cstring name;
  std::shared_ptr<ModelSkeletonDataV57> skeleton;
  ModelTransformDataV57 initial_placement;
  std::vector<ModelMeshBindingDataV57> mesh_bindings;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
  std::vector<pf::dword> bone_flags;
  std::vector<pf::dword> emitter_bones;
  std::vector<ModelTrackMaskV57> track_masks;
  pf::float3 center;
  float radius;
};

struct ModelPropertyDataV57 {
  pf::qword id;
  pf::dword type;
  pf::dword merge_index;
  float time;
  pf::qword val;
  pf::filename str_val;
};

struct ModelParticleCloudV57 {
  pf::float3 acceleration;
  pf::qword bone;
  float drag;
  std::vector<pf::dword> emitter_indices;
  pf::dword fvf;
  pf::dword flags;
  pf::dword material_index;
  std::vector<pf::dword> obstacle_indices;
  pf::float3 velocity;
};

struct ModelParticleCurveV57 {
  pf::byte curve_type;
  std::vector<pf::float2> keys;
};

struct ModelParticleFlipbookV57 {
  pf::byte columns;
  pf::byte count;
  float fps;
  pf::byte rows;
  pf::byte start;
};

struct ModelMatrix43V57 {
  pf::float4 x;
  pf::float4 y;
  pf::float4 z;
};

struct ModelParticleEmitterV57 {
  std::array<pf::float2, 4> acceleration;
  pf::float2 acceleration_dist_range;
  pf::float2 acceleration_dist_speed;
  pf::float3 alignment_dir;
  pf::qword bone;
  pf::float4 color_begin;
  pf::float4 color_end;
  float color_period;
  pf::float2 color_falloff;
  float drag;
  pf::dword emitter_flags;
  float offset;
  std::shared_ptr<ModelParticleCurveV57> opacity_curve;
  pf::dword opacity_curve_preset;
  pf::dword flags;
  std::shared_ptr<ModelParticleFlipbookV57> flipbook;
  pf::float2 lifetime;
  pf::float2 rotation_change;
  float rotation_drag;
  pf::float2 rotation_initial;
  std::array<pf::float2, 2> scale_change;
  std::array<pf::float2, 2> scale_initial;
  std::shared_ptr<ModelParticleCurveV57> scale_curve;
  pf::dword scale_curve_preset;
  std::array<pf::float2, 4> velocity;
  pf::float2 velocity_dist_range;
  pf::float2 velocity_dist_speed;
  pf::float2 velocity_inherit;
  pf::float2 spawn_group_size;
  float spawn_period;
  float spawn_probability;
  pf::float2 spawn_radius;
  pf::float2 spawn_wind_emit;
  pf::float2 spawn_wind_speed;
  pf::float4 tex_coord_rect;
  std::shared_ptr<ModelMatrix43V57> transform;
  pf::byte wind_influence;
  pf::byte alignment_type;
  pf::byte spawn_shape;
};

struct ModelCloudDataV57 {
  std::vector<ModelParticleCloudV57> clouds;
  std::vector<ModelParticleEmitterV57> emitters;
};

struct ModelObstacleDataV57 {
  pf::qword bone;
  pf::byte type;
  pf::byte response;
  pf::dword flags;
  float drag_coef;
  float gravity_coef;
  float length;
  float width;
  float height;
  float radius;
  std::shared_ptr<ModelMatrix43V57> transform;
};

struct ModelStreakV57 {
  pf::float3 acceleration;
  pf::float3 velocity;
  std::vector<pf::dword> anchor_indices;
  pf::qword bone;
  pf::dword flags;
  float jitter;
  pf::dword material_index;
  float noise;
  float spawn_dist;
  float tex_scale;
  float wind;
};

struct ModelStreakAnchorV57 {
  pf::qword bone;
  pf::dword color_start;
  pf::dword color_end;
  float falloff;
  float lifetime;
  pf::dword flags;
  float tex_v;
};

struct ModelStreakDataV57 {
  std::vector<ModelStreakV57> streaks;
  std::vector<ModelStreakAnchorV57> anchors;
};

struct ModelEffectLightV57 {
  pf::qword bone;
  std::array<pf::byte, 3> color;
  float far_distance;
  float intensity;
  float near_distance;
};

struct ModelLightDataV57 {
  std::vector<ModelEffectLightV57> effect_lights;
};

struct ModelClothBoneWeightV57 {
  pf::qword token;
  pf::byte weight;
};

struct ModelClothMeshGroupV57 {
  std::vector<ModelClothBoneWeightV57> weights;
};

struct ModelClothSoftLockV57 {
  pf::byte weight;
  pf::word vert_index;
};

struct ModelClothConstraintV57 {
  pf::word distance;
  pf::word relationship;
  pf::word vert_index_a;
  pf::word vert_index_b;
};

struct ModelClothDataV57 {
  pf::dword material_index;
  float drag;
  float gravity;
  float compressibility;
  float slack;
  float stretchiness;
  float weight;
  float wind;
  PackVertexType mesh;
  std::vector<pf::word> indices;
  std::vector<ModelClothMeshGroupV57> groups;
  std::vector<ModelClothSoftLockV57> soft_locks;
  std::vector<ModelClothConstraintV57> lod0_constraints;
  std::vector<ModelClothConstraintV57> lod1_constraints;
  std::vector<pf::word> lod1_indices;
  std::vector<pf::float3> barycentric_coords;
  std::vector<pf::word> barycentric_indices;
  std::vector<pf::dword> obstacle_indices;
  pf::word lock_count;
  pf::word lod1_vertex_count;
  pf::byte flags;
  pf::byte rigidness;
};

struct ModelLightningSystemV57 {
  pf::qword bone;
  std::vector<pf::word> bolt_indices;
  pf::dword flags;
  pf::dword fvf;
  pf::dword material_index;
};

struct ModelLightningBoltV57 {
  pf::qword bone;
  std::vector<pf::word> node_indices;
  std::array<pf::dword, 3> color_begin;
  std::array<pf::dword, 3> color_end;
  float color_period;
  pf::float2 color_falloff;
  pf::dword flags;
  float fps;
  float probability;
  pf::float2 lifetime;
  pf::word num_segments;
  pf::float2 opacity;
  pf::byte opacity_preset;
  float period;
  float tex_offset;
  float tex_scale;
  float tex_speed;
  float thickness;
  pf::byte thickness_preset;
  pf::byte type;
  float variance;
  pf::byte variance_preset;
  float noise;
};

struct ModelLightningNodeV57 {
  pf::qword bone;
  std::vector<pf::word> children_indices;
  pf::dword flags;
  float probability;
  pf::float2 radius;
  pf::byte shape;
  float update_pos;
};

struct ModelLightningDataV57 {
  std::vector<ModelLightningSystemV57> systems;
  std::vector<ModelLightningBoltV57> bolts;
  std::vector<ModelLightningNodeV57> nodes;
};

struct ModelBoneConstraintLinkV57 {
  float angle;
  float azimuth;
  pf::float2 distance;
  pf::qword token;
};

struct ModelBoneConstraintV57 {
  pf::qword token;
  pf::word flags;
  float twist_offset;
  float anim_blend;
  float drag;
  float ellipse_ratio;
  float gravity;
  float collision_radius;
  float wind;
  pf::float2 angle;
  float angle_strength;
  pf::byte angle_type;
  pf::float2 distance_inner;
  float distance_inner_strength;
  pf::byte distance_inner_type;
  std::vector<ModelBoneConstraintLinkV57> links;
  pf::float2 distance_outer;
  float distance_outer_strength;
  pf::byte distance_outer_type;
  pf::float2 twist;
  float twist_strength;
  pf::byte twist_type;
};

struct ModelSoftBodyDataV57 {
  pf::dword material_index;
  pf::dword flags;
  pf::dword vertex_fvf;
  std::vector<pf::byte> vert_bytes;
  std::vector<pf::word> indices;
  std::vector<pf::qword> bones;
};

struct ModelBoneOffsetDataV57 {
  pf::qword bone;
  pf::float3 translation;
  pf::float4 rotation;
  std::array<pf::float4, 3> bone_inverse_offset;
};

struct ModelFixedOffsetDataV57 {
  pf::qword name;
  pf::qword parent_bone;
  pf::float3 translation;
};

struct ModelFileDataV57 {
  std::vector<ModelPermutationDataV57> permutations;
  std::vector<std::shared_ptr<ModelMeshDataV57>> meshes;
  std::shared_ptr<ModelModelDataV57> model;
  std::vector<ModelPropertyDataV57> properties;
  std::shared_ptr<ModelCloudDataV57> cloud_data;
  std::vector<ModelObstacleDataV57> obstacles;
  std::shared_ptr<ModelStreakDataV57> streak_data;
  std::shared_ptr<ModelLightDataV57> light_data;
  std::vector<ModelClothDataV57> cloth_data;
  std::vector<pf::qword> action_offset_names;
  std::vector<pf::float3> action_offsets;
  std::array<float, 2> lod_override;
  pf::filename sound_script;
  std::shared_ptr<ModelLightningDataV57> lightning_data;
  std::vector<ModelBoneConstraintV57> bone_constraints;
  std::vector<ModelSoftBodyDataV57> soft_body_data;
  std::vector<ModelBoneOffsetDataV57> bone_offset_data;
  std::vector<ModelFixedOffsetDataV57> fixed_offset_data;
  pf::filename model_reference;
};
} // namespace MODL::MODL::v57

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelTextureDataV57 &value) {
  reader(value.filename);
  reader(value.texture_flags);
  reader(value.token);
  reader(value.blit_id);
  reader(value.uv_anim_id);
  reader(value.uv_ps_input_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelConstantDataV57 &value) {
  reader(value.name);
  reader(value.value);
  reader(value.constant_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelMatConstLinkV57 &value) {
  reader(value.link_token);
  reader(value.constant_token);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelUVTransLinkV57 &value) {
  reader(value.link_token);
  reader(value.uv_anim_id);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader,
          MODL::MODL::v57::ModelMaterialTexTransformV57 &value) {
  reader(value.random);
  reader(value.uv_index);
  reader(value.columns);
  reader(value.rows);
  reader(value.count);
  reader(value.fps);
  reader(value.scroll);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelMaterialDataV57 &value) {
  reader(value.token);
  reader(value.material_id);
  reader(value.filename);
  reader(value.material_flags);
  reader(value.sort_order);
  reader(value.textures);
  reader(value.constants);
  reader(value.mat_const_links);
  reader(value.uv_trans_links);
  reader(value.tex_transforms);
  reader(value.tex_coord_count);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelPermutationDataV57 &value) {
  reader(value.token);
  reader(value.materials);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelMeshLodDataV57 &value) {
  reader(value.indices);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelMeshMorphVertV57 &value) {
  reader(value.index);
  reader(value.vector);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelMeshMorphTargetV57 &value) {
  reader(value.positions);
  reader(value.normals);
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::GrBoundData &value) {
  reader(value.center);
  reader(value.box_extent);
  reader(value.sphere_radius);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelMeshDataV57 &value) {
  reader(value.vis_bone);
  reader(value.lods);
  reader(value.morph_targets);
  reader(value.mesh);
  reader(value.flags);
  reader(value.seam_vert_indices);
  reader(value.mesh_name);
  reader(value.min_bound);
  reader(value.max_bound);
  reader(value.bounds);
  reader(value.material_index);
  reader(value.material_name);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelTransformDataV57 &value) {
  reader(value.flags);
  reader(value.position);
  reader(value.orientation);
  reader(value.scale_shear);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelBoneDataV57 &value) {
  reader(value.name);
  reader(value.parent_index);
  reader(value.local_transform);
  reader(value.inverse_world4x4);
  reader(value.lod_error);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelBoneSymmetryV57 &value) {
  reader(value.bone_left);
  reader(value.bone_right);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelSkeletonDataV57 &value) {
  reader(value.name);
  reader(value.bones);
  reader(value.lod_type);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
  reader(value.bone_symmetries);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelMeshBindingDataV57 &value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelTrackMaskV57 &value) {
  reader(value.track_mask);
  reader(value.token);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelModelDataV57 &value) {
  reader(value.name);
  reader(value.skeleton);
  reader(value.initial_placement);
  reader(value.mesh_bindings);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
  reader(value.bone_flags);
  reader(value.emitter_bones);
  reader(value.track_masks);
  reader(value.center);
  reader(value.radius);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelPropertyDataV57 &value) {
  reader(value.id);
  reader(value.type);
  reader(value.merge_index);
  reader(value.time);
  reader(value.val);
  reader(value.str_val);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelParticleCloudV57 &value) {
  reader(value.acceleration);
  reader(value.bone);
  reader(value.drag);
  reader(value.emitter_indices);
  reader(value.fvf);
  reader(value.flags);
  reader(value.material_index);
  reader(value.obstacle_indices);
  reader(value.velocity);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelParticleCurveV57 &value) {
  reader(value.curve_type);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelParticleFlipbookV57 &value) {
  reader(value.columns);
  reader(value.count);
  reader(value.fps);
  reader(value.rows);
  reader(value.start);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelMatrix43V57 &value) {
  reader(value.x);
  reader(value.y);
  reader(value.z);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelParticleEmitterV57 &value) {
  reader(value.acceleration);
  reader(value.acceleration_dist_range);
  reader(value.acceleration_dist_speed);
  reader(value.alignment_dir);
  reader(value.bone);
  reader(value.color_begin);
  reader(value.color_end);
  reader(value.color_period);
  reader(value.color_falloff);
  reader(value.drag);
  reader(value.emitter_flags);
  reader(value.offset);
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
  reader(value.velocity_inherit);
  reader(value.spawn_group_size);
  reader(value.spawn_period);
  reader(value.spawn_probability);
  reader(value.spawn_radius);
  reader(value.spawn_wind_emit);
  reader(value.spawn_wind_speed);
  reader(value.tex_coord_rect);
  reader(value.transform);
  reader(value.wind_influence);
  reader(value.alignment_type);
  reader(value.spawn_shape);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelCloudDataV57 &value) {
  reader(value.clouds);
  reader(value.emitters);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelObstacleDataV57 &value) {
  reader(value.bone);
  reader(value.type);
  reader(value.response);
  reader(value.flags);
  reader(value.drag_coef);
  reader(value.gravity_coef);
  reader(value.length);
  reader(value.width);
  reader(value.height);
  reader(value.radius);
  reader(value.transform);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelStreakV57 &value) {
  reader(value.acceleration);
  reader(value.velocity);
  reader(value.anchor_indices);
  reader(value.bone);
  reader(value.flags);
  reader(value.jitter);
  reader(value.material_index);
  reader(value.noise);
  reader(value.spawn_dist);
  reader(value.tex_scale);
  reader(value.wind);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelStreakAnchorV57 &value) {
  reader(value.bone);
  reader(value.color_start);
  reader(value.color_end);
  reader(value.falloff);
  reader(value.lifetime);
  reader(value.flags);
  reader(value.tex_v);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelStreakDataV57 &value) {
  reader(value.streaks);
  reader(value.anchors);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelEffectLightV57 &value) {
  reader(value.bone);
  reader(value.color);
  reader(value.far_distance);
  reader(value.intensity);
  reader(value.near_distance);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelLightDataV57 &value) {
  reader(value.effect_lights);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelClothBoneWeightV57 &value) {
  reader(value.token);
  reader(value.weight);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelClothMeshGroupV57 &value) {
  reader(value.weights);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelClothSoftLockV57 &value) {
  reader(value.weight);
  reader(value.vert_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelClothConstraintV57 &value) {
  reader(value.distance);
  reader(value.relationship);
  reader(value.vert_index_a);
  reader(value.vert_index_b);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelClothDataV57 &value) {
  reader(value.material_index);
  reader(value.drag);
  reader(value.gravity);
  reader(value.compressibility);
  reader(value.slack);
  reader(value.stretchiness);
  reader(value.weight);
  reader(value.wind);
  reader(value.mesh);
  reader(value.indices);
  reader(value.groups);
  reader(value.soft_locks);
  reader(value.lod0_constraints);
  reader(value.lod1_constraints);
  reader(value.lod1_indices);
  reader(value.barycentric_coords);
  reader(value.barycentric_indices);
  reader(value.obstacle_indices);
  reader(value.lock_count);
  reader(value.lod1_vertex_count);
  reader(value.flags);
  reader(value.rigidness);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelLightningSystemV57 &value) {
  reader(value.bone);
  reader(value.bolt_indices);
  reader(value.flags);
  reader(value.fvf);
  reader(value.material_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelLightningBoltV57 &value) {
  reader(value.bone);
  reader(value.node_indices);
  reader(value.color_begin);
  reader(value.color_end);
  reader(value.color_period);
  reader(value.color_falloff);
  reader(value.flags);
  reader(value.fps);
  reader(value.probability);
  reader(value.lifetime);
  reader(value.num_segments);
  reader(value.opacity);
  reader(value.opacity_preset);
  reader(value.period);
  reader(value.tex_offset);
  reader(value.tex_scale);
  reader(value.tex_speed);
  reader(value.thickness);
  reader(value.thickness_preset);
  reader(value.type);
  reader(value.variance);
  reader(value.variance_preset);
  reader(value.noise);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelLightningNodeV57 &value) {
  reader(value.bone);
  reader(value.children_indices);
  reader(value.flags);
  reader(value.probability);
  reader(value.radius);
  reader(value.shape);
  reader(value.update_pos);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelLightningDataV57 &value) {
  reader(value.systems);
  reader(value.bolts);
  reader(value.nodes);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelBoneConstraintLinkV57 &value) {
  reader(value.angle);
  reader(value.azimuth);
  reader(value.distance);
  reader(value.token);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelBoneConstraintV57 &value) {
  reader(value.token);
  reader(value.flags);
  reader(value.twist_offset);
  reader(value.anim_blend);
  reader(value.drag);
  reader(value.ellipse_ratio);
  reader(value.gravity);
  reader(value.collision_radius);
  reader(value.wind);
  reader(value.angle);
  reader(value.angle_strength);
  reader(value.angle_type);
  reader(value.distance_inner);
  reader(value.distance_inner_strength);
  reader(value.distance_inner_type);
  reader(value.links);
  reader(value.distance_outer);
  reader(value.distance_outer_strength);
  reader(value.distance_outer_type);
  reader(value.twist);
  reader(value.twist_strength);
  reader(value.twist_type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelSoftBodyDataV57 &value) {
  reader(value.material_index);
  reader(value.flags);
  reader(value.vertex_fvf);
  reader(value.vert_bytes);
  reader(value.indices);
  reader(value.bones);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelBoneOffsetDataV57 &value) {
  reader(value.bone);
  reader(value.translation);
  reader(value.rotation);
  reader(value.bone_inverse_offset);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelFixedOffsetDataV57 &value) {
  reader(value.name);
  reader(value.parent_bone);
  reader(value.translation);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v57::ModelFileDataV57 &value) {
  reader(value.permutations);
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
  reader(value.lightning_data);
  reader(value.bone_constraints);
  reader(value.soft_body_data);
  reader(value.bone_offset_data);
  reader(value.fixed_offset_data);
  reader(value.model_reference);
}
} // namespace de

} // namespace pf

#endif
