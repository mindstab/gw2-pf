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

#if MODL_ANIM_MIN_VERSION <= 21

#include "pf/types.hpp"

namespace pf {
namespace MODL::ANIM::v21 {
struct ModelVisTrackDataV29 {
  pf::qword bone_token;
  std::vector<float> keys;
};

struct ModelTrackTypeDataV21 {
  pf::byte type;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelUVAnimationV21 {
  pf::dword uv_anim_id;
  std::vector<ModelTrackTypeDataV21> uv_transform_data;
};

struct ModelCloudAnimV21 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV21> cloud_track_data;
};

struct ModelMatConstAnimV21 {
  pf::dword material_id;
  pf::dword const_token;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelLightAnimationV21 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV21> light_track_data;
};

struct ModelAnimPropertyDataV21 {
  pf::qword id;
  pf::dword type;
  float time;
  pf::qword val;
  pf::filename str_val;
};

struct ModelTokenMapAnimV21 {
  pf::qword link_token;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelBoneConstraintAnimV21 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV21> bc_track_data;
};

struct ModelAnchorAnimV21 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV21> anchor_track_data;
};

struct ModelStreakAnimV21 {
  pf::qword bone;
  std::vector<ModelAnchorAnimV21> anchor_anim;
};

struct ModelLightningAnimV21 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV21> lightning_track_data;
};

struct ModelWindAnimationV21 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV21> wind_track_data;
};

struct ModelAnimationDataV29 {
  pf::qword token;
  PackGrannyAnimationTypeV0 data;
  float move_speed;
  std::vector<ModelVisTrackDataV29> vis_track_data;
  std::vector<ModelUVAnimationV21> uv_anim_data;
  std::vector<ModelCloudAnimV21> cloud_anim;
  std::vector<ModelMatConstAnimV21> mat_const_anim;
  std::vector<pf::word> morph_track_groups;
  std::vector<float> trigger_times;
  std::vector<pf::qword> trigger_tokens;
  std::vector<ModelLightAnimationV21> light_anim_data;
  pf::dword is_additive;
  pf::dword variant_count;
  std::array<pf::dword, 3> variant_indices;
  std::vector<ModelAnimPropertyDataV21> properties;
  pf::float3 center;
  float radius;
  std::vector<ModelTokenMapAnimV21> token_map_anims;
  std::vector<ModelBoneConstraintAnimV21> bc_anim;
  std::vector<ModelStreakAnimV21> streak_anim;
  std::vector<ModelLightningAnimV21> lightning_anim;
  std::vector<ModelWindAnimationV21> wind_anim_data;
};

struct ModelCompoundAnimationDataV21 {
  pf::qword token;
  pf::qword start;
  pf::qword loop;
  pf::qword end;
};

struct ModelAnimationImportSequenceV21 {
  pf::qword name;
  float duration;
};

struct ModelAnimationImportDataV29 {
  pf::filename filename;
  std::vector<ModelAnimationImportSequenceV21> sequences;
};

struct ModelFileAnimationBankV21 {
  std::vector<std::shared_ptr<ModelAnimationDataV29>> animations;
  std::vector<ModelCompoundAnimationDataV21> compound_animations;
  std::vector<pf::qword> fallbacks;
  std::vector<ModelAnimationImportDataV29> imports;
  pf::filename model_reference;
};
} // namespace MODL::ANIM::v21

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v21::ModelVisTrackDataV29 &value) {
  reader(value.bone_token);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v21::ModelTrackTypeDataV21 &value) {
  reader(value.type);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v21::ModelUVAnimationV21 &value) {
  reader(value.uv_anim_id);
  reader(value.uv_transform_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v21::ModelCloudAnimV21 &value) {
  reader(value.bone);
  reader(value.cloud_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v21::ModelMatConstAnimV21 &value) {
  reader(value.material_id);
  reader(value.const_token);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v21::ModelLightAnimationV21 &value) {
  reader(value.bone);
  reader(value.light_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v21::ModelAnimPropertyDataV21 &value) {
  reader(value.id);
  reader(value.type);
  reader(value.time);
  reader(value.val);
  reader(value.str_val);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v21::ModelTokenMapAnimV21 &value) {
  reader(value.link_token);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v21::ModelBoneConstraintAnimV21 &value) {
  reader(value.bone);
  reader(value.bc_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v21::ModelAnchorAnimV21 &value) {
  reader(value.bone);
  reader(value.anchor_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v21::ModelStreakAnimV21 &value) {
  reader(value.bone);
  reader(value.anchor_anim);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v21::ModelLightningAnimV21 &value) {
  reader(value.bone);
  reader(value.lightning_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v21::ModelWindAnimationV21 &value) {
  reader(value.bone);
  reader(value.wind_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v21::ModelAnimationDataV29 &value) {
  reader(value.token);
  reader(value.data);
  reader(value.move_speed);
  reader(value.vis_track_data);
  reader(value.uv_anim_data);
  reader(value.cloud_anim);
  reader(value.mat_const_anim);
  reader(value.morph_track_groups);
  reader(value.trigger_times);
  reader(value.trigger_tokens);
  reader(value.light_anim_data);
  reader(value.is_additive);
  reader(value.variant_count);
  reader(value.variant_indices);
  reader(value.properties);
  reader(value.center);
  reader(value.radius);
  reader(value.token_map_anims);
  reader(value.bc_anim);
  reader(value.streak_anim);
  reader(value.lightning_anim);
  reader(value.wind_anim_data);
}

template <typename Reader>
void Read(Reader &reader,
          MODL::ANIM::v21::ModelCompoundAnimationDataV21 &value) {
  reader(value.token);
  reader(value.start);
  reader(value.loop);
  reader(value.end);
}

template <typename Reader>
void Read(Reader &reader,
          MODL::ANIM::v21::ModelAnimationImportSequenceV21 &value) {
  reader(value.name);
  reader(value.duration);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v21::ModelAnimationImportDataV29 &value) {
  reader(value.filename);
  reader(value.sequences);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v21::ModelFileAnimationBankV21 &value) {
  reader(value.animations);
  reader(value.compound_animations);
  reader(value.fallbacks);
  reader(value.imports);
  reader(value.model_reference);
}
} // namespace de

} // namespace pf

#endif
