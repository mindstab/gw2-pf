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

#if MODL_MODL_MIN_VERSION <= 37

#include "pf/types.hpp"

namespace pf {
namespace MODL::MODL::v37 {
struct ModelTextureDataV37 {
  pf::filename filename;
  pf::dword texture_flags;
  pf::qword token;
  pf::qword blit_id;
  pf::dword uv_anim_id;
  pf::byte uv_ps_input_index;
};

struct ModelConstantDataV37 {
  pf::dword name;
  pf::float4 value;
  pf::dword constant_flags;
};

struct ModelMatConstLinkV37 {
  pf::qword link_token;
  pf::dword constant_token;
};

struct ModelUVTransLinkV37 {
  pf::qword link_token;
  pf::dword uv_anim_id;
  pf::byte type;
};

struct ModelMaterialDataV37 {
  pf::filename filename;
  pf::dword material_flags;
  pf::dword sort_order;
  pf::byte tex_coord_count;
  std::vector<ModelTextureDataV37> textures;
  std::vector<ModelConstantDataV37> constants;
  std::vector<ModelMatConstLinkV37> mat_const_links;
  std::vector<ModelUVTransLinkV37> uv_trans_links;
};

struct ModelMeshLodDataV37 {
  std::vector<pf::word> indices;
};

struct ModelMeshMorphTargetV37 {
  std::vector<pf::word> position_indices;
  std::vector<pf::float3> positions;
  std::vector<pf::word> normal_indices;
  std::vector<pf::float3> normals;
  pf::cstring mesh_name;
};

struct ModelMeshDataV37 {
  pf::qword vis_bone;
  std::vector<ModelMeshLodDataV37> lods;
  std::vector<ModelMeshMorphTargetV37> morph_targets;
  PackGrannyMeshType mesh;
  pf::dword flags;
  std::vector<pf::dword> seam_vert_indices;
  pf::qword mesh_name;
  pf::float3 min_bound;
  pf::float3 max_bound;
};

struct ModelTransformDataV37 {
  pf::dword flags;
  pf::float3 position;
  pf::float4 orientation;
  std::array<pf::float3, 3> scale_shear;
};

struct ModelBoneDataV37 {
  pf::cstring name;
  pf::dword parent_index;
  ModelTransformDataV37 local_transform;
  std::array<pf::float4, 4> inverse_world4x4;
  float lod_error;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
};

struct ModelSkeletonDataV37 {
  pf::cstring name;
  std::vector<ModelBoneDataV37> bones;
  pf::dword lod_type;
};

struct ModelMeshBindingDataV37 {
  std::shared_ptr<pf::byte> mesh;
};

struct ModelTrackMaskV37 {
  PackGrannyTrackMaskType track_mask;
  pf::qword token;
};

struct ModelModelDataV37 {
  pf::cstring name;
  std::shared_ptr<ModelSkeletonDataV37> skeleton;
  ModelTransformDataV37 initial_placement;
  std::vector<ModelMeshBindingDataV37> mesh_bindings;
  std::vector<pf::dword> bone_flags;
  std::vector<pf::dword> emitter_bones;
  std::vector<ModelTrackMaskV37> track_masks;
  pf::float3 center;
  float radius;
};

struct ModelPropertyDataV37 {
  pf::qword id;
  pf::dword type;
  pf::dword merge_index;
  float time;
  pf::qword val;
  pf::filename str_val;
};

struct ModelParticleCloudV37 {
  pf::float3 acceleration;
  pf::qword bone;
  float drag;
  std::vector<pf::dword> emitter_indices;
  pf::dword flags;
  pf::dword material_index;
  std::vector<pf::dword> obstacle_indices;
  pf::float3 velocity;
};

struct ModelParticleCurveV37 {
  pf::byte curve_type;
  std::vector<pf::float2> keys;
};

struct ModelParticleFlipbookV37 {
  pf::byte columns;
  pf::byte count;
  float fps;
  pf::byte rows;
  pf::byte start;
};

struct ModelParticleEmitterV37 {
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
  std::shared_ptr<ModelParticleCurveV37> opacity_curve;
  pf::dword opacity_curve_preset;
  pf::dword flags;
  std::shared_ptr<ModelParticleFlipbookV37> flipbook;
  pf::float2 lifetime;
  pf::float2 rotation_change;
  float rotation_drag;
  pf::float2 rotation_initial;
  std::array<pf::float2, 2> scale_change;
  std::array<pf::float2, 2> scale_initial;
  std::shared_ptr<ModelParticleCurveV37> scale_curve;
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
  pf::byte wind_influence;
};

struct ModelCloudDataV37 {
  std::vector<ModelParticleCloudV37> clouds;
  std::vector<ModelParticleEmitterV37> emitters;
};

struct ModelObstacleDataV37 {
  pf::qword bone;
  float drag_coef;
  pf::dword flags;
  pf::float3 geo_data;
  float gravity_coef;
  pf::byte response;
  pf::byte type;
};

struct ModelStreakV37 {
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

struct ModelStreakAnchorV37 {
  pf::qword bone;
  pf::dword color;
  float falloff;
  float lifetime;
  pf::dword flags;
  float tex_v;
};

struct ModelStreakDataV37 {
  std::vector<ModelStreakV37> streaks;
  std::vector<ModelStreakAnchorV37> anchors;
};

struct ModelEffectLightV37 {
  pf::qword bone;
  std::array<pf::byte, 3> color;
  float far_distance;
  float intensity;
  float near_distance;
};

struct ModelLightDataV37 {
  std::vector<ModelEffectLightV37> effect_lights;
};

struct ModelClothBoneWeightV37 {
  pf::qword token;
  pf::byte weight;
};

struct ModelClothMeshGroupV37 {
  std::vector<ModelClothBoneWeightV37> weights;
};

struct ModelClothConstraintV37 {
  pf::word vert_index_a;
  pf::word vert_index_b;
  float distance;
};

struct ModelClothObstacleV37 {
  pf::qword bone;
  pf::byte type;
};

struct ModelClothDataV37 {
  pf::dword material_index;
  pf::byte flags;
  float gravity;
  float weight;
  float wind;
  pf::byte rigidness;
  PackVertexType mesh;
  std::vector<pf::word> indices;
  pf::word lock_count;
  std::vector<ModelClothMeshGroupV37> groups;
  std::vector<pf::byte> soft_locks;
  std::vector<ModelClothConstraintV37> lod0_constraints;
  std::vector<ModelClothConstraintV37> lod1_constraints;
  pf::word lod1_vertex_count;
  std::vector<pf::word> lod1_indices;
  std::vector<pf::float3> barycentric_coords;
  std::vector<pf::word> barycentric_indices;
  std::vector<ModelClothObstacleV37> obstacles;
};

struct ModelLightningSystemV37 {
  std::vector<pf::word> bolt_indices;
  pf::dword flags;
  pf::dword material_index;
};

struct ModelLightningBoltV37 {
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

struct ModelLightningNodeV37 {
  pf::qword bone;
  std::vector<pf::word> children_indices;
  pf::dword flags;
  float probability;
  float radius;
  pf::byte shape;
  float update_pos;
};

struct ModelLightningDataV37 {
  std::vector<ModelLightningSystemV37> systems;
  std::vector<ModelLightningBoltV37> bolts;
  std::vector<ModelLightningNodeV37> nodes;
};

struct ModelBoneConstraintLinkV37 {
  float angle;
  float azimuth;
  pf::float2 distance;
  pf::qword token;
};

struct ModelBoneConstraintV37 {
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
  std::vector<ModelBoneConstraintLinkV37> links;
  pf::float2 distance_outer;
  float distance_outer_strength;
  pf::byte distance_outer_type;
  pf::float2 twist;
  float twist_strength;
  pf::byte twist_type;
};

struct ModelFileDataV37 {
  std::vector<std::shared_ptr<ModelMaterialDataV37>> materials;
  std::vector<std::shared_ptr<ModelMeshDataV37>> meshes;
  std::shared_ptr<ModelModelDataV37> model;
  std::vector<ModelPropertyDataV37> properties;
  std::shared_ptr<ModelCloudDataV37> cloud_data;
  std::vector<ModelObstacleDataV37> obstacles;
  std::shared_ptr<ModelStreakDataV37> streak_data;
  std::shared_ptr<ModelLightDataV37> light_data;
  std::vector<ModelClothDataV37> cloth_data;
  std::vector<pf::qword> action_offset_names;
  std::vector<pf::float3> action_offsets;
  std::array<float, 2> lod_override;
  pf::filename sound_script;
  std::shared_ptr<ModelLightningDataV37> lightning_data;
  std::vector<ModelBoneConstraintV37> bone_constraints;
};
} // namespace MODL::MODL::v37

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelTextureDataV37 &value) {
  reader(value.filename);
  reader(value.texture_flags);
  reader(value.token);
  reader(value.blit_id);
  reader(value.uv_anim_id);
  reader(value.uv_ps_input_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelConstantDataV37 &value) {
  reader(value.name);
  reader(value.value);
  reader(value.constant_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelMatConstLinkV37 &value) {
  reader(value.link_token);
  reader(value.constant_token);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelUVTransLinkV37 &value) {
  reader(value.link_token);
  reader(value.uv_anim_id);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelMaterialDataV37 &value) {
  reader(value.filename);
  reader(value.material_flags);
  reader(value.sort_order);
  reader(value.tex_coord_count);
  reader(value.textures);
  reader(value.constants);
  reader(value.mat_const_links);
  reader(value.uv_trans_links);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelMeshLodDataV37 &value) {
  reader(value.indices);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelMeshMorphTargetV37 &value) {
  reader(value.position_indices);
  reader(value.positions);
  reader(value.normal_indices);
  reader(value.normals);
  reader(value.mesh_name);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelMeshDataV37 &value) {
  reader(value.vis_bone);
  reader(value.lods);
  reader(value.morph_targets);
  reader(value.mesh);
  reader(value.flags);
  reader(value.seam_vert_indices);
  reader(value.mesh_name);
  reader(value.min_bound);
  reader(value.max_bound);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelTransformDataV37 &value) {
  reader(value.flags);
  reader(value.position);
  reader(value.orientation);
  reader(value.scale_shear);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelBoneDataV37 &value) {
  reader(value.name);
  reader(value.parent_index);
  reader(value.local_transform);
  reader(value.inverse_world4x4);
  reader(value.lod_error);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelSkeletonDataV37 &value) {
  reader(value.name);
  reader(value.bones);
  reader(value.lod_type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelMeshBindingDataV37 &value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelTrackMaskV37 &value) {
  reader(value.track_mask);
  reader(value.token);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelModelDataV37 &value) {
  reader(value.name);
  reader(value.skeleton);
  reader(value.initial_placement);
  reader(value.mesh_bindings);
  reader(value.bone_flags);
  reader(value.emitter_bones);
  reader(value.track_masks);
  reader(value.center);
  reader(value.radius);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelPropertyDataV37 &value) {
  reader(value.id);
  reader(value.type);
  reader(value.merge_index);
  reader(value.time);
  reader(value.val);
  reader(value.str_val);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelParticleCloudV37 &value) {
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
void Read(Reader &reader, MODL::MODL::v37::ModelParticleCurveV37 &value) {
  reader(value.curve_type);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelParticleFlipbookV37 &value) {
  reader(value.columns);
  reader(value.count);
  reader(value.fps);
  reader(value.rows);
  reader(value.start);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelParticleEmitterV37 &value) {
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
  reader(value.wind_influence);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelCloudDataV37 &value) {
  reader(value.clouds);
  reader(value.emitters);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelObstacleDataV37 &value) {
  reader(value.bone);
  reader(value.drag_coef);
  reader(value.flags);
  reader(value.geo_data);
  reader(value.gravity_coef);
  reader(value.response);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelStreakV37 &value) {
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
void Read(Reader &reader, MODL::MODL::v37::ModelStreakAnchorV37 &value) {
  reader(value.bone);
  reader(value.color);
  reader(value.falloff);
  reader(value.lifetime);
  reader(value.flags);
  reader(value.tex_v);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelStreakDataV37 &value) {
  reader(value.streaks);
  reader(value.anchors);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelEffectLightV37 &value) {
  reader(value.bone);
  reader(value.color);
  reader(value.far_distance);
  reader(value.intensity);
  reader(value.near_distance);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelLightDataV37 &value) {
  reader(value.effect_lights);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelClothBoneWeightV37 &value) {
  reader(value.token);
  reader(value.weight);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelClothMeshGroupV37 &value) {
  reader(value.weights);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelClothConstraintV37 &value) {
  reader(value.vert_index_a);
  reader(value.vert_index_b);
  reader(value.distance);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelClothObstacleV37 &value) {
  reader(value.bone);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelClothDataV37 &value) {
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
  reader(value.obstacles);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelLightningSystemV37 &value) {
  reader(value.bolt_indices);
  reader(value.flags);
  reader(value.material_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelLightningBoltV37 &value) {
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
void Read(Reader &reader, MODL::MODL::v37::ModelLightningNodeV37 &value) {
  reader(value.bone);
  reader(value.children_indices);
  reader(value.flags);
  reader(value.probability);
  reader(value.radius);
  reader(value.shape);
  reader(value.update_pos);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelLightningDataV37 &value) {
  reader(value.systems);
  reader(value.bolts);
  reader(value.nodes);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelBoneConstraintLinkV37 &value) {
  reader(value.angle);
  reader(value.azimuth);
  reader(value.distance);
  reader(value.token);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v37::ModelBoneConstraintV37 &value) {
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
void Read(Reader &reader, MODL::MODL::v37::ModelFileDataV37 &value) {
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
  reader(value.lightning_data);
  reader(value.bone_constraints);
}
} // namespace de

} // namespace pf

#endif
