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

#if MODL_MODL_MIN_VERSION <= 54

#include "pf/types.hpp"

namespace pf {
namespace MODL::MODL::v54 {
struct ModelTextureDataV54 {
  pf::filename filename;
  pf::dword texture_flags;
  pf::qword token;
  pf::qword blit_id;
  pf::dword uv_anim_id;
  pf::byte uv_ps_input_index;
};

struct ModelConstantDataV54 {
  pf::dword name;
  pf::float4 value;
  pf::dword constant_flags;
};

struct ModelMatConstLinkV54 {
  pf::qword link_token;
  pf::dword constant_token;
};

struct ModelUVTransLinkV54 {
  pf::qword link_token;
  pf::dword uv_anim_id;
  pf::byte type;
};

struct ModelMaterialTexTransformV54 {
  pf::byte random;
  pf::byte uv_index;
  pf::byte columns;
  pf::byte rows;
  pf::word count;
  float fps;
  pf::float2 scroll;
};

struct ModelMaterialDataV54 {
  pf::qword token;
  pf::dword material_id;
  pf::filename filename;
  pf::dword material_flags;
  pf::dword sort_order;
  std::vector<ModelTextureDataV54> textures;
  std::vector<ModelConstantDataV54> constants;
  std::vector<ModelMatConstLinkV54> mat_const_links;
  std::vector<ModelUVTransLinkV54> uv_trans_links;
  std::vector<ModelMaterialTexTransformV54> tex_transforms;
  pf::byte tex_coord_count;
};

struct ModelPermutationDataV54 {
  pf::qword token;
  std::vector<std::shared_ptr<ModelMaterialDataV54>> materials;
};

struct ModelMeshLodDataV54 {
  std::vector<pf::word> indices;
};

struct ModelMeshMorphVertV54 {
  pf::word index;
  pf::float3 vector;
};

struct ModelMeshMorphTargetV54 {
  std::vector<ModelMeshMorphVertV54> positions;
  std::vector<ModelMeshMorphVertV54> normals;
  pf::qword mesh;
};

struct GrBoundData {
  pf::float3 center;
  pf::float3 box_extent;
  float sphere_radius;
};

struct ModelMeshDataV54 {
  pf::qword vis_bone;
  std::vector<ModelMeshLodDataV54> lods;
  std::vector<ModelMeshMorphTargetV54> morph_targets;
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

struct ModelTransformDataV54 {
  pf::dword flags;
  pf::float3 position;
  pf::float4 orientation;
  std::array<pf::float3, 3> scale_shear;
};

struct ModelBoneDataV54 {
  pf::cstring name;
  pf::dword parent_index;
  ModelTransformDataV54 local_transform;
  std::array<pf::float4, 4> inverse_world4x4;
  float lod_error;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
};

struct ModelBoneSymmetryV54 {
  pf::qword bone_left;
  pf::qword bone_right;
};

struct ModelSkeletonDataV54 {
  pf::cstring name;
  std::vector<ModelBoneDataV54> bones;
  pf::dword lod_type;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
  std::vector<ModelBoneSymmetryV54> bone_symmetries;
};

struct ModelMeshBindingDataV54 {
  std::shared_ptr<pf::byte> mesh;
};

struct ModelTrackMaskV54 {
  PackGrannyTrackMaskType track_mask;
  pf::qword token;
};

struct ModelModelDataV54 {
  pf::cstring name;
  std::shared_ptr<ModelSkeletonDataV54> skeleton;
  ModelTransformDataV54 initial_placement;
  std::vector<ModelMeshBindingDataV54> mesh_bindings;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
  std::vector<pf::dword> bone_flags;
  std::vector<pf::dword> emitter_bones;
  std::vector<ModelTrackMaskV54> track_masks;
  pf::float3 center;
  float radius;
};

struct ModelPropertyDataV54 {
  pf::qword id;
  pf::dword type;
  pf::dword merge_index;
  float time;
  pf::qword val;
  pf::filename str_val;
};

struct ModelParticleCloudV54 {
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

struct ModelParticleCurveV54 {
  pf::byte curve_type;
  std::vector<pf::float2> keys;
};

struct ModelParticleFlipbookV54 {
  pf::byte columns;
  pf::byte count;
  float fps;
  pf::byte rows;
  pf::byte start;
};

struct ModelMatrix43V54 {
  pf::float4 x;
  pf::float4 y;
  pf::float4 z;
};

struct ModelParticleEmitterV54 {
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
  std::shared_ptr<ModelParticleCurveV54> opacity_curve;
  pf::dword opacity_curve_preset;
  pf::dword flags;
  std::shared_ptr<ModelParticleFlipbookV54> flipbook;
  pf::float2 lifetime;
  pf::float2 rotation_change;
  float rotation_drag;
  pf::float2 rotation_initial;
  std::array<pf::float2, 2> scale_change;
  std::array<pf::float2, 2> scale_initial;
  std::shared_ptr<ModelParticleCurveV54> scale_curve;
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
  std::shared_ptr<ModelMatrix43V54> transform;
  pf::byte wind_influence;
  pf::byte alignment_type;
  pf::byte spawn_shape;
};

struct ModelCloudDataV54 {
  std::vector<ModelParticleCloudV54> clouds;
  std::vector<ModelParticleEmitterV54> emitters;
};

struct ModelObstacleDataV54 {
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
  std::shared_ptr<ModelMatrix43V54> transform;
};

struct ModelStreakV54 {
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

struct ModelStreakAnchorV54 {
  pf::qword bone;
  pf::dword color_start;
  pf::dword color_end;
  float falloff;
  float lifetime;
  pf::dword flags;
  float tex_v;
};

struct ModelStreakDataV54 {
  std::vector<ModelStreakV54> streaks;
  std::vector<ModelStreakAnchorV54> anchors;
};

struct ModelEffectLightV54 {
  pf::qword bone;
  std::array<pf::byte, 3> color;
  float far_distance;
  float intensity;
  float near_distance;
};

struct ModelLightDataV54 {
  std::vector<ModelEffectLightV54> effect_lights;
};

struct ModelClothBoneWeightV54 {
  pf::qword token;
  pf::byte weight;
};

struct ModelClothMeshGroupV54 {
  std::vector<ModelClothBoneWeightV54> weights;
};

struct ModelClothSoftLockV54 {
  pf::byte weight;
  pf::word vert_index;
};

struct ModelClothConstraintV54 {
  pf::word distance;
  pf::word relationship;
  pf::word vert_index_a;
  pf::word vert_index_b;
};

struct ModelClothDataV54 {
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
  std::vector<ModelClothMeshGroupV54> groups;
  std::vector<ModelClothSoftLockV54> soft_locks;
  std::vector<ModelClothConstraintV54> lod0_constraints;
  std::vector<ModelClothConstraintV54> lod1_constraints;
  std::vector<pf::word> lod1_indices;
  std::vector<pf::float3> barycentric_coords;
  std::vector<pf::word> barycentric_indices;
  std::vector<pf::dword> obstacle_indices;
  pf::word lock_count;
  pf::word lod1_vertex_count;
  pf::byte flags;
  pf::byte rigidness;
};

struct ModelLightningSystemV54 {
  pf::qword bone;
  std::vector<pf::word> bolt_indices;
  pf::dword flags;
  pf::dword fvf;
  pf::dword material_index;
};

struct ModelLightningBoltV54 {
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

struct ModelLightningNodeV54 {
  pf::qword bone;
  std::vector<pf::word> children_indices;
  pf::dword flags;
  float probability;
  pf::float2 radius;
  pf::byte shape;
  float update_pos;
};

struct ModelLightningDataV54 {
  std::vector<ModelLightningSystemV54> systems;
  std::vector<ModelLightningBoltV54> bolts;
  std::vector<ModelLightningNodeV54> nodes;
};

struct ModelBoneConstraintLinkV54 {
  float angle;
  float azimuth;
  pf::float2 distance;
  pf::qword token;
};

struct ModelBoneConstraintV54 {
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
  std::vector<ModelBoneConstraintLinkV54> links;
  pf::float2 distance_outer;
  float distance_outer_strength;
  pf::byte distance_outer_type;
  pf::float2 twist;
  float twist_strength;
  pf::byte twist_type;
};

struct ModelSoftBodyDataV54 {
  pf::dword material_index;
  pf::dword flags;
  pf::dword vertex_fvf;
  std::vector<pf::byte> vert_bytes;
  std::vector<pf::word> indices;
  std::vector<pf::qword> bones;
};

struct ModelBoneOffsetDataV54 {
  pf::qword bone;
  pf::float3 translation;
  pf::float4 rotation;
};

struct ModelFileDataV54 {
  std::vector<ModelPermutationDataV54> permutations;
  std::vector<std::shared_ptr<ModelMeshDataV54>> meshes;
  std::shared_ptr<ModelModelDataV54> model;
  std::vector<ModelPropertyDataV54> properties;
  std::shared_ptr<ModelCloudDataV54> cloud_data;
  std::vector<ModelObstacleDataV54> obstacles;
  std::shared_ptr<ModelStreakDataV54> streak_data;
  std::shared_ptr<ModelLightDataV54> light_data;
  std::vector<ModelClothDataV54> cloth_data;
  std::vector<pf::qword> action_offset_names;
  std::vector<pf::float3> action_offsets;
  std::array<float, 2> lod_override;
  pf::filename sound_script;
  std::shared_ptr<ModelLightningDataV54> lightning_data;
  std::vector<ModelBoneConstraintV54> bone_constraints;
  std::vector<ModelSoftBodyDataV54> soft_body_data;
  std::vector<ModelBoneOffsetDataV54> bone_offset_data;
};
} // namespace MODL::MODL::v54

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelTextureDataV54 &value) {
  reader(value.filename);
  reader(value.texture_flags);
  reader(value.token);
  reader(value.blit_id);
  reader(value.uv_anim_id);
  reader(value.uv_ps_input_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelConstantDataV54 &value) {
  reader(value.name);
  reader(value.value);
  reader(value.constant_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelMatConstLinkV54 &value) {
  reader(value.link_token);
  reader(value.constant_token);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelUVTransLinkV54 &value) {
  reader(value.link_token);
  reader(value.uv_anim_id);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader,
          MODL::MODL::v54::ModelMaterialTexTransformV54 &value) {
  reader(value.random);
  reader(value.uv_index);
  reader(value.columns);
  reader(value.rows);
  reader(value.count);
  reader(value.fps);
  reader(value.scroll);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelMaterialDataV54 &value) {
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
void Read(Reader &reader, MODL::MODL::v54::ModelPermutationDataV54 &value) {
  reader(value.token);
  reader(value.materials);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelMeshLodDataV54 &value) {
  reader(value.indices);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelMeshMorphVertV54 &value) {
  reader(value.index);
  reader(value.vector);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelMeshMorphTargetV54 &value) {
  reader(value.positions);
  reader(value.normals);
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::GrBoundData &value) {
  reader(value.center);
  reader(value.box_extent);
  reader(value.sphere_radius);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelMeshDataV54 &value) {
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
void Read(Reader &reader, MODL::MODL::v54::ModelTransformDataV54 &value) {
  reader(value.flags);
  reader(value.position);
  reader(value.orientation);
  reader(value.scale_shear);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelBoneDataV54 &value) {
  reader(value.name);
  reader(value.parent_index);
  reader(value.local_transform);
  reader(value.inverse_world4x4);
  reader(value.lod_error);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelBoneSymmetryV54 &value) {
  reader(value.bone_left);
  reader(value.bone_right);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelSkeletonDataV54 &value) {
  reader(value.name);
  reader(value.bones);
  reader(value.lod_type);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
  reader(value.bone_symmetries);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelMeshBindingDataV54 &value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelTrackMaskV54 &value) {
  reader(value.track_mask);
  reader(value.token);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelModelDataV54 &value) {
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
void Read(Reader &reader, MODL::MODL::v54::ModelPropertyDataV54 &value) {
  reader(value.id);
  reader(value.type);
  reader(value.merge_index);
  reader(value.time);
  reader(value.val);
  reader(value.str_val);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelParticleCloudV54 &value) {
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
void Read(Reader &reader, MODL::MODL::v54::ModelParticleCurveV54 &value) {
  reader(value.curve_type);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelParticleFlipbookV54 &value) {
  reader(value.columns);
  reader(value.count);
  reader(value.fps);
  reader(value.rows);
  reader(value.start);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelMatrix43V54 &value) {
  reader(value.x);
  reader(value.y);
  reader(value.z);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelParticleEmitterV54 &value) {
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
void Read(Reader &reader, MODL::MODL::v54::ModelCloudDataV54 &value) {
  reader(value.clouds);
  reader(value.emitters);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelObstacleDataV54 &value) {
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
void Read(Reader &reader, MODL::MODL::v54::ModelStreakV54 &value) {
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
void Read(Reader &reader, MODL::MODL::v54::ModelStreakAnchorV54 &value) {
  reader(value.bone);
  reader(value.color_start);
  reader(value.color_end);
  reader(value.falloff);
  reader(value.lifetime);
  reader(value.flags);
  reader(value.tex_v);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelStreakDataV54 &value) {
  reader(value.streaks);
  reader(value.anchors);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelEffectLightV54 &value) {
  reader(value.bone);
  reader(value.color);
  reader(value.far_distance);
  reader(value.intensity);
  reader(value.near_distance);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelLightDataV54 &value) {
  reader(value.effect_lights);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelClothBoneWeightV54 &value) {
  reader(value.token);
  reader(value.weight);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelClothMeshGroupV54 &value) {
  reader(value.weights);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelClothSoftLockV54 &value) {
  reader(value.weight);
  reader(value.vert_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelClothConstraintV54 &value) {
  reader(value.distance);
  reader(value.relationship);
  reader(value.vert_index_a);
  reader(value.vert_index_b);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelClothDataV54 &value) {
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
void Read(Reader &reader, MODL::MODL::v54::ModelLightningSystemV54 &value) {
  reader(value.bone);
  reader(value.bolt_indices);
  reader(value.flags);
  reader(value.fvf);
  reader(value.material_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelLightningBoltV54 &value) {
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
void Read(Reader &reader, MODL::MODL::v54::ModelLightningNodeV54 &value) {
  reader(value.bone);
  reader(value.children_indices);
  reader(value.flags);
  reader(value.probability);
  reader(value.radius);
  reader(value.shape);
  reader(value.update_pos);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelLightningDataV54 &value) {
  reader(value.systems);
  reader(value.bolts);
  reader(value.nodes);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelBoneConstraintLinkV54 &value) {
  reader(value.angle);
  reader(value.azimuth);
  reader(value.distance);
  reader(value.token);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelBoneConstraintV54 &value) {
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
void Read(Reader &reader, MODL::MODL::v54::ModelSoftBodyDataV54 &value) {
  reader(value.material_index);
  reader(value.flags);
  reader(value.vertex_fvf);
  reader(value.vert_bytes);
  reader(value.indices);
  reader(value.bones);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelBoneOffsetDataV54 &value) {
  reader(value.bone);
  reader(value.translation);
  reader(value.rotation);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v54::ModelFileDataV54 &value) {
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
}
} // namespace de

} // namespace pf

#endif
