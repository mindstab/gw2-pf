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

#if MODL_MODL_MIN_VERSION <= 66

#include "pf/types.hpp"

namespace pf {
namespace MODL::MODL::v66 {
struct ModelTextureDataV66 {
  pf::filename filename;
  pf::dword texture_flags;
  pf::qword token;
  pf::qword blit_id;
  pf::dword uv_anim_id;
  pf::byte uv_ps_input_index;
};

struct ModelConstantDataV66 {
  pf::dword name;
  pf::float4 value;
  pf::dword constant_flags;
};

struct ModelMatConstLinkV66 {
  pf::qword link_token;
  pf::dword constant_token;
};

struct ModelUVTransLinkV66 {
  pf::qword link_token;
  pf::dword uv_anim_id;
  pf::byte type;
};

struct ModelMaterialTexTransformV66 {
  pf::dword flags;
  pf::byte uv_index;
  pf::byte columns;
  pf::byte rows;
  pf::word count;
  float fps;
  pf::float2 scroll;
  pf::float2 scroll_freq;
  pf::float2 scale;
  pf::float2 scale_freq;
  float rotate;
  float rotate2;
};

struct ModelMaterialDataV66 {
  pf::qword token;
  pf::dword material_id;
  pf::filename filename;
  pf::dword material_flags;
  pf::dword sort_order;
  std::vector<ModelTextureDataV66> textures;
  std::vector<ModelConstantDataV66> constants;
  std::vector<ModelMatConstLinkV66> mat_const_links;
  std::vector<ModelUVTransLinkV66> uv_trans_links;
  std::vector<ModelMaterialTexTransformV66> tex_transforms;
  pf::byte tex_coord_count;
  pf::dword sort_layer;
};

struct ModelPermutationDataV66 {
  pf::qword token;
  std::vector<std::shared_ptr<ModelMaterialDataV66>> materials;
};

struct ModelParticleCloudV66 {
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

struct ModelParticleCurveV66 {
  pf::byte curve_type;
  std::vector<pf::float2> keys;
};

struct ModelParticleFlipbookV66 {
  pf::byte columns;
  pf::byte count;
  float fps;
  pf::byte rows;
  pf::byte start;
};

struct ModelMatrix43V66 {
  pf::float4 x;
  pf::float4 y;
  pf::float4 z;
};

struct ModelParticleEmitterV66 {
  std::array<pf::float2, 4> acceleration;
  pf::float2 acceleration_dist_range;
  pf::float2 acceleration_dist_speed;
  pf::dword affinity;
  pf::float3 alignment_dir;
  pf::qword bone;
  pf::float4 color_begin;
  pf::float4 color_end;
  float color_period;
  pf::float2 color_falloff;
  float drag;
  pf::dword emitter_flags;
  float offset;
  std::shared_ptr<ModelParticleCurveV66> opacity_curve;
  pf::dword opacity_curve_preset;
  pf::dword flags;
  std::shared_ptr<ModelParticleFlipbookV66> flipbook;
  pf::float2 lifetime;
  pf::float2 rotation_change;
  float rotation_drag;
  pf::float2 rotation_initial;
  std::array<pf::float2, 2> scale_change;
  std::array<pf::float2, 2> scale_initial;
  std::shared_ptr<ModelParticleCurveV66> scale_curve;
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
  std::shared_ptr<ModelMatrix43V66> transform;
  pf::byte wind_influence;
  pf::byte alignment_type;
  pf::byte spawn_shape;
};

struct ModelCloudDataV66 {
  std::vector<ModelParticleCloudV66> clouds;
  std::vector<ModelParticleEmitterV66> emitters;
};

struct ModelObstacleDataV66 {
  pf::dword affinity;
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
  std::shared_ptr<ModelMatrix43V66> transform;
};

struct ModelStreakV66 {
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

struct ModelStreakAnchorV66 {
  pf::qword bone;
  pf::dword color_start;
  pf::dword color_end;
  float falloff;
  float lifetime;
  pf::dword flags;
  float tex_v;
};

struct ModelStreakDataV66 {
  std::vector<ModelStreakV66> streaks;
  std::vector<ModelStreakAnchorV66> anchors;
};

struct ModelEffectLightV66 {
  pf::qword bone;
  std::array<pf::byte, 3> color;
  float far_distance;
  float intensity;
  float near_distance;
};

struct ModelLightDataV66 {
  std::vector<ModelEffectLightV66> effect_lights;
};

struct ModelClothBoneWeightV66 {
  pf::qword token;
  pf::byte weight;
};

struct ModelClothMeshGroupV66 {
  std::vector<ModelClothBoneWeightV66> weights;
};

struct ModelClothGroupBindingV66 {
  pf::qword stripped_token;
  pf::cstring bone_name;
  pf::float3 obb_min;
  pf::float3 obb_max;
};

struct ModelClothSoftLockV66 {
  pf::byte weight;
  pf::word vert_index;
};

struct ModelClothConstraintV66 {
  pf::word distance;
  pf::word relationship;
  pf::word vert_index_a;
  pf::word vert_index_b;
};

struct ModelClothDataV66 {
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
  std::vector<ModelClothMeshGroupV66> groups;
  std::vector<ModelClothGroupBindingV66> group_bindings;
  std::vector<ModelClothSoftLockV66> soft_locks;
  std::vector<ModelClothConstraintV66> lod0_constraints;
  std::vector<ModelClothConstraintV66> lod1_constraints;
  std::vector<pf::word> lod1_indices;
  std::vector<pf::float3> barycentric_coords;
  std::vector<pf::word> barycentric_indices;
  std::vector<pf::dword> obstacle_indices;
  pf::word lock_count;
  std::vector<pf::dword> locked_normals;
  std::vector<pf::dword> locked_tanegents;
  std::vector<pf::dword> locked_bitangents;
  pf::word lod1_vertex_count;
  pf::byte flags;
  pf::byte rigidness;
  float translate_weight;
  pf::qword vis_bone;
};

struct ModelEffectWindV66 {
  pf::qword bone;
  float far_distance;
  float intensity;
  float near_distance;
};

struct ModelWindDataV66 {
  std::vector<ModelEffectWindV66> effect_wind;
};

struct ModelLightningSystemV66 {
  pf::qword bone;
  std::vector<pf::word> bolt_indices;
  pf::dword flags;
  pf::dword fvf;
  pf::dword material_index;
};

struct ModelLightningBoltV66 {
  pf::qword bone;
  std::vector<pf::word> node_indices;
  std::array<pf::dword, 3> color_begin;
  std::array<pf::dword, 3> color_end;
  float color_period;
  pf::float2 color_falloff;
  pf::dword flags;
  std::shared_ptr<ModelParticleFlipbookV66> flipbook;
  float fps;
  float frequency;
  pf::dword group_max;
  pf::dword group_min;
  float probability;
  pf::float2 lifetime;
  pf::word num_segments;
  pf::float2 opacity;
  pf::byte opacity_preset;
  float tex_offset;
  pf::float2 tex_range;
  float tex_scale;
  float tex_speed;
  pf::byte thickness_preset;
  pf::float2 thickness_range;
  pf::byte type;
  float variance;
  pf::byte variance_preset;
  float noise;
};

struct ModelLightningNodeV66 {
  pf::qword bone;
  std::vector<pf::word> children_indices;
  pf::dword flags;
  float probability;
  pf::float2 radius;
  pf::byte shape;
  float update_pos;
};

struct ModelLightningDataV66 {
  std::vector<ModelLightningSystemV66> systems;
  std::vector<ModelLightningBoltV66> bolts;
  std::vector<ModelLightningNodeV66> nodes;
};

struct ModelSoftBodyDataV66 {
  pf::dword material_index;
  pf::dword flags;
  pf::dword vertex_fvf;
  std::vector<pf::byte> vert_bytes;
  std::vector<pf::word> indices;
  std::vector<pf::qword> bones;
};

struct ModelBoneOffsetDataV66 {
  pf::qword bone;
  pf::float3 translation;
  pf::float4 rotation;
  std::array<pf::float4, 3> bone_inverse_offset;
};

struct ModelBoundingSphereV66 {
  pf::float3 center;
  float radius;
};

struct ModelFileDataV66 {
  std::vector<ModelPermutationDataV66> permutations;
  std::shared_ptr<ModelCloudDataV66> cloud_data;
  std::vector<ModelObstacleDataV66> obstacles;
  std::shared_ptr<ModelStreakDataV66> streak_data;
  std::shared_ptr<ModelLightDataV66> light_data;
  std::vector<ModelClothDataV66> cloth_data;
  std::shared_ptr<ModelWindDataV66> wind_data;
  std::vector<pf::qword> action_offset_names;
  std::vector<pf::float3> action_offsets;
  std::array<float, 2> lod_override;
  pf::filename sound_script;
  std::shared_ptr<ModelLightningDataV66> lightning_data;
  std::vector<ModelSoftBodyDataV66> soft_body_data;
  std::vector<ModelBoneOffsetDataV66> bone_offset_data;
  std::shared_ptr<ModelBoundingSphereV66> bounding_sphere;
};
} // namespace MODL::MODL::v66

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelTextureDataV66 &value) {
  reader(value.filename);
  reader(value.texture_flags);
  reader(value.token);
  reader(value.blit_id);
  reader(value.uv_anim_id);
  reader(value.uv_ps_input_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelConstantDataV66 &value) {
  reader(value.name);
  reader(value.value);
  reader(value.constant_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelMatConstLinkV66 &value) {
  reader(value.link_token);
  reader(value.constant_token);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelUVTransLinkV66 &value) {
  reader(value.link_token);
  reader(value.uv_anim_id);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader,
          MODL::MODL::v66::ModelMaterialTexTransformV66 &value) {
  reader(value.flags);
  reader(value.uv_index);
  reader(value.columns);
  reader(value.rows);
  reader(value.count);
  reader(value.fps);
  reader(value.scroll);
  reader(value.scroll_freq);
  reader(value.scale);
  reader(value.scale_freq);
  reader(value.rotate);
  reader(value.rotate2);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelMaterialDataV66 &value) {
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
  reader(value.sort_layer);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelPermutationDataV66 &value) {
  reader(value.token);
  reader(value.materials);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelParticleCloudV66 &value) {
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
void Read(Reader &reader, MODL::MODL::v66::ModelParticleCurveV66 &value) {
  reader(value.curve_type);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelParticleFlipbookV66 &value) {
  reader(value.columns);
  reader(value.count);
  reader(value.fps);
  reader(value.rows);
  reader(value.start);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelMatrix43V66 &value) {
  reader(value.x);
  reader(value.y);
  reader(value.z);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelParticleEmitterV66 &value) {
  reader(value.acceleration);
  reader(value.acceleration_dist_range);
  reader(value.acceleration_dist_speed);
  reader(value.affinity);
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
void Read(Reader &reader, MODL::MODL::v66::ModelCloudDataV66 &value) {
  reader(value.clouds);
  reader(value.emitters);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelObstacleDataV66 &value) {
  reader(value.affinity);
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
void Read(Reader &reader, MODL::MODL::v66::ModelStreakV66 &value) {
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
void Read(Reader &reader, MODL::MODL::v66::ModelStreakAnchorV66 &value) {
  reader(value.bone);
  reader(value.color_start);
  reader(value.color_end);
  reader(value.falloff);
  reader(value.lifetime);
  reader(value.flags);
  reader(value.tex_v);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelStreakDataV66 &value) {
  reader(value.streaks);
  reader(value.anchors);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelEffectLightV66 &value) {
  reader(value.bone);
  reader(value.color);
  reader(value.far_distance);
  reader(value.intensity);
  reader(value.near_distance);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelLightDataV66 &value) {
  reader(value.effect_lights);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelClothBoneWeightV66 &value) {
  reader(value.token);
  reader(value.weight);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelClothMeshGroupV66 &value) {
  reader(value.weights);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelClothGroupBindingV66 &value) {
  reader(value.stripped_token);
  reader(value.bone_name);
  reader(value.obb_min);
  reader(value.obb_max);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelClothSoftLockV66 &value) {
  reader(value.weight);
  reader(value.vert_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelClothConstraintV66 &value) {
  reader(value.distance);
  reader(value.relationship);
  reader(value.vert_index_a);
  reader(value.vert_index_b);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelClothDataV66 &value) {
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
  reader(value.group_bindings);
  reader(value.soft_locks);
  reader(value.lod0_constraints);
  reader(value.lod1_constraints);
  reader(value.lod1_indices);
  reader(value.barycentric_coords);
  reader(value.barycentric_indices);
  reader(value.obstacle_indices);
  reader(value.lock_count);
  reader(value.locked_normals);
  reader(value.locked_tanegents);
  reader(value.locked_bitangents);
  reader(value.lod1_vertex_count);
  reader(value.flags);
  reader(value.rigidness);
  reader(value.translate_weight);
  reader(value.vis_bone);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelEffectWindV66 &value) {
  reader(value.bone);
  reader(value.far_distance);
  reader(value.intensity);
  reader(value.near_distance);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelWindDataV66 &value) {
  reader(value.effect_wind);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelLightningSystemV66 &value) {
  reader(value.bone);
  reader(value.bolt_indices);
  reader(value.flags);
  reader(value.fvf);
  reader(value.material_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelLightningBoltV66 &value) {
  reader(value.bone);
  reader(value.node_indices);
  reader(value.color_begin);
  reader(value.color_end);
  reader(value.color_period);
  reader(value.color_falloff);
  reader(value.flags);
  reader(value.flipbook);
  reader(value.fps);
  reader(value.frequency);
  reader(value.group_max);
  reader(value.group_min);
  reader(value.probability);
  reader(value.lifetime);
  reader(value.num_segments);
  reader(value.opacity);
  reader(value.opacity_preset);
  reader(value.tex_offset);
  reader(value.tex_range);
  reader(value.tex_scale);
  reader(value.tex_speed);
  reader(value.thickness_preset);
  reader(value.thickness_range);
  reader(value.type);
  reader(value.variance);
  reader(value.variance_preset);
  reader(value.noise);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelLightningNodeV66 &value) {
  reader(value.bone);
  reader(value.children_indices);
  reader(value.flags);
  reader(value.probability);
  reader(value.radius);
  reader(value.shape);
  reader(value.update_pos);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelLightningDataV66 &value) {
  reader(value.systems);
  reader(value.bolts);
  reader(value.nodes);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelSoftBodyDataV66 &value) {
  reader(value.material_index);
  reader(value.flags);
  reader(value.vertex_fvf);
  reader(value.vert_bytes);
  reader(value.indices);
  reader(value.bones);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelBoneOffsetDataV66 &value) {
  reader(value.bone);
  reader(value.translation);
  reader(value.rotation);
  reader(value.bone_inverse_offset);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelBoundingSphereV66 &value) {
  reader(value.center);
  reader(value.radius);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v66::ModelFileDataV66 &value) {
  reader(value.permutations);
  reader(value.cloud_data);
  reader(value.obstacles);
  reader(value.streak_data);
  reader(value.light_data);
  reader(value.cloth_data);
  reader(value.wind_data);
  reader(value.action_offset_names);
  reader(value.action_offsets);
  reader(value.lod_override);
  reader(value.sound_script);
  reader(value.lightning_data);
  reader(value.soft_body_data);
  reader(value.bone_offset_data);
  reader(value.bounding_sphere);
}
} // namespace de

} // namespace pf

#endif
