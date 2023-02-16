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

#if MODL_MODL_MIN_VERSION <= 9

#include "pf/types.hpp"

namespace pf {
namespace MODL::MODL::v9 {
struct ModelTextureDataV9 {
  pf::filename filename;
  pf::dword texture_flags;
  pf::qword token;
  pf::qword blit_id;
  pf::byte uv_anim_id;
  pf::byte uv_ps_input_index;
};

struct ModelConstantDataV9 {
  pf::dword name;
  pf::float4 value;
  pf::dword constant_flags;
};

struct ModelMaterialDataV9 {
  pf::filename filename;
  pf::dword material_flags;
  pf::dword sort_order;
  pf::byte tex_coord_count;
  std::vector<ModelTextureDataV9> textures;
  std::vector<ModelConstantDataV9> constants;
};

struct ModelMeshDataV9 {
  PackGrannyMeshType mesh;
  pf::dword flags;
  std::vector<pf::dword> vis_bone_indices;
};

struct ModelTransformDataV9 {
  pf::dword flags;
  pf::float3 position;
  pf::float4 orientation;
  std::array<pf::float3, 3> scale_shear;
};

struct ModelBoneDataV9 {
  pf::cstring name;
  pf::dword parent_index;
  ModelTransformDataV9 local_transform;
  std::array<pf::float4, 4> inverse_world4x4;
  float lod_error;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
};

struct ModelSkeletonDataV9 {
  pf::cstring name;
  std::vector<ModelBoneDataV9> bones;
  pf::dword lod_type;
};

struct ModelMeshBindingDataV9 {
  std::shared_ptr<pf::byte> mesh;
};

struct ModelModelDataV9 {
  pf::cstring name;
  std::shared_ptr<ModelSkeletonDataV9> skeleton;
  ModelTransformDataV9 initial_placement;
  std::vector<ModelMeshBindingDataV9> mesh_bindings;
  std::vector<pf::dword> bone_flags;
};

struct ModelFloatPropertyDataV9 {
  pf::qword token;
  float value;
};

struct ModelPropertyDataV9 {
  std::vector<pf::qword> bool_tokens;
  std::vector<ModelFloatPropertyDataV9> float_values;
};

struct ModelParticleFlipbookV9 {
  pf::byte columns;
  pf::byte count;
  pf::byte flags;
  pf::dword fps;
  pf::byte rows;
  pf::byte start;
};

struct ModelParticleCloudV9 {
  pf::float3 acceleration;
  pf::qword bone;
  float drag;
  std::vector<pf::dword> emitter_indices;
  pf::dword flags;
  std::vector<ModelParticleFlipbookV9> flipbook;
  pf::dword material_index;
  std::vector<pf::dword> obstacle_indices;
  pf::byte opacity_curve_type;
  std::vector<pf::float2> opacity_keys;
  pf::byte scale_curve_type;
  std::vector<pf::float2> scale_keys;
};

struct ModelParticleEmitterV9 {
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

struct ModelParticleObstacleV9 {
  pf::qword bone;
  float drag_coef;
  pf::dword flags;
  pf::float3 geo_data;
  float gravity_coef;
  pf::byte response;
  pf::byte type;
  pf::dword vis_bone_index;
};

struct ModelCloudDataV9 {
  std::vector<ModelParticleCloudV9> clouds;
  std::vector<ModelParticleEmitterV9> emitters;
  std::vector<ModelParticleObstacleV9> obstacles;
};

struct ModelFileDataV9 {
  std::vector<std::shared_ptr<ModelMaterialDataV9>> materials;
  std::vector<std::shared_ptr<ModelMeshDataV9>> meshes;
  std::shared_ptr<ModelModelDataV9> model;
  std::shared_ptr<ModelPropertyDataV9> properties;
  std::shared_ptr<ModelCloudDataV9> cloud_data;
};
} // namespace MODL::MODL::v9

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::MODL::v9::ModelTextureDataV9 &value) {
  reader(value.filename);
  reader(value.texture_flags);
  reader(value.token);
  reader(value.blit_id);
  reader(value.uv_anim_id);
  reader(value.uv_ps_input_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v9::ModelConstantDataV9 &value) {
  reader(value.name);
  reader(value.value);
  reader(value.constant_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v9::ModelMaterialDataV9 &value) {
  reader(value.filename);
  reader(value.material_flags);
  reader(value.sort_order);
  reader(value.tex_coord_count);
  reader(value.textures);
  reader(value.constants);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v9::ModelMeshDataV9 &value) {
  reader(value.mesh);
  reader(value.flags);
  reader(value.vis_bone_indices);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v9::ModelTransformDataV9 &value) {
  reader(value.flags);
  reader(value.position);
  reader(value.orientation);
  reader(value.scale_shear);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v9::ModelBoneDataV9 &value) {
  reader(value.name);
  reader(value.parent_index);
  reader(value.local_transform);
  reader(value.inverse_world4x4);
  reader(value.lod_error);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v9::ModelSkeletonDataV9 &value) {
  reader(value.name);
  reader(value.bones);
  reader(value.lod_type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v9::ModelMeshBindingDataV9 &value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v9::ModelModelDataV9 &value) {
  reader(value.name);
  reader(value.skeleton);
  reader(value.initial_placement);
  reader(value.mesh_bindings);
  reader(value.bone_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v9::ModelFloatPropertyDataV9 &value) {
  reader(value.token);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v9::ModelPropertyDataV9 &value) {
  reader(value.bool_tokens);
  reader(value.float_values);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v9::ModelParticleFlipbookV9 &value) {
  reader(value.columns);
  reader(value.count);
  reader(value.flags);
  reader(value.fps);
  reader(value.rows);
  reader(value.start);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v9::ModelParticleCloudV9 &value) {
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
void Read(Reader &reader, MODL::MODL::v9::ModelParticleEmitterV9 &value) {
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
void Read(Reader &reader, MODL::MODL::v9::ModelParticleObstacleV9 &value) {
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
void Read(Reader &reader, MODL::MODL::v9::ModelCloudDataV9 &value) {
  reader(value.clouds);
  reader(value.emitters);
  reader(value.obstacles);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v9::ModelFileDataV9 &value) {
  reader(value.materials);
  reader(value.meshes);
  reader(value.model);
  reader(value.properties);
  reader(value.cloud_data);
}
} // namespace de

} // namespace pf

#endif
