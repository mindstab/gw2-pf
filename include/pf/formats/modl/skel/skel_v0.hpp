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

#if MODL_SKEL_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace MODL::SKEL::v0 {
struct ModelTransformData {
  pf::dword flags;
  pf::float3 position;
  pf::float4 orientation;
  std::array<pf::float3, 3> scale_shear;
};

struct ModelBoneData {
  pf::cstring name;
  pf::dword parent_index;
  ModelTransformData local_transform;
  std::array<pf::float4, 4> inverse_world4x4;
  float lod_error;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
};

struct ModelGrannySkeletonV0 {
  pf::cstring name;
  std::vector<ModelBoneData> bones;
  pf::dword lod_type;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
};

struct ModelMeshBindingData {
  std::shared_ptr<pf::byte> mesh;
};

struct ModelGrannyModelV0 {
  pf::cstring name;
  std::shared_ptr<ModelGrannySkeletonV0> skeleton;
  ModelTransformData initial_placement;
  std::vector<ModelMeshBindingData> mesh_bindings;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
};

struct ModelBoneConstraintLinkV62 {
  float angle;
  float azimuth;
  pf::float2 distance;
  pf::qword token;
};

struct ModelBoneConstraintV62 {
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
  std::vector<ModelBoneConstraintLinkV62> links;
  pf::float2 distance_outer;
  float distance_outer_strength;
  pf::byte distance_outer_type;
  pf::float2 twist;
  float twist_strength;
  pf::byte twist_type;
};

struct ModelBoneSymmetryV62 {
  pf::qword bone_left;
  pf::qword bone_right;
};

struct ModelTrackMaskV62 {
  PackGrannyTrackMaskType data;
  pf::qword token;
};

struct ModelSkeletonDataV62 {
  std::shared_ptr<ModelGrannyModelV0> granny_model;
  std::vector<ModelBoneConstraintV62> bone_constraints;
  std::vector<pf::dword> bone_flags;
  std::vector<ModelBoneSymmetryV62> bone_symmetries;
  std::vector<pf::dword> emitter_bones;
  std::vector<ModelTrackMaskV62> track_masks;
};

struct ModelFileSkeletonV0 {
  std::shared_ptr<ModelSkeletonDataV62> skeleton_data;
  pf::filename file_reference;
};
} // namespace MODL::SKEL::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::SKEL::v0::ModelTransformData &value) {
  reader(value.flags);
  reader(value.position);
  reader(value.orientation);
  reader(value.scale_shear);
}

template <typename Reader>
void Read(Reader &reader, MODL::SKEL::v0::ModelBoneData &value) {
  reader(value.name);
  reader(value.parent_index);
  reader(value.local_transform);
  reader(value.inverse_world4x4);
  reader(value.lod_error);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
}

template <typename Reader>
void Read(Reader &reader, MODL::SKEL::v0::ModelGrannySkeletonV0 &value) {
  reader(value.name);
  reader(value.bones);
  reader(value.lod_type);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
}

template <typename Reader>
void Read(Reader &reader, MODL::SKEL::v0::ModelMeshBindingData &value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::SKEL::v0::ModelGrannyModelV0 &value) {
  reader(value.name);
  reader(value.skeleton);
  reader(value.initial_placement);
  reader(value.mesh_bindings);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
}

template <typename Reader>
void Read(Reader &reader, MODL::SKEL::v0::ModelBoneConstraintLinkV62 &value) {
  reader(value.angle);
  reader(value.azimuth);
  reader(value.distance);
  reader(value.token);
}

template <typename Reader>
void Read(Reader &reader, MODL::SKEL::v0::ModelBoneConstraintV62 &value) {
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
void Read(Reader &reader, MODL::SKEL::v0::ModelBoneSymmetryV62 &value) {
  reader(value.bone_left);
  reader(value.bone_right);
}

template <typename Reader>
void Read(Reader &reader, MODL::SKEL::v0::ModelTrackMaskV62 &value) {
  reader(value.data);
  reader(value.token);
}

template <typename Reader>
void Read(Reader &reader, MODL::SKEL::v0::ModelSkeletonDataV62 &value) {
  reader(value.granny_model);
  reader(value.bone_constraints);
  reader(value.bone_flags);
  reader(value.bone_symmetries);
  reader(value.emitter_bones);
  reader(value.track_masks);
}

template <typename Reader>
void Read(Reader &reader, MODL::SKEL::v0::ModelFileSkeletonV0 &value) {
  reader(value.skeleton_data);
  reader(value.file_reference);
}
} // namespace de

} // namespace pf

#endif
