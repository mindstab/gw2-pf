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

#if MODL_ANIM_MIN_VERSION <= 22

#include "pf/types.hpp"

namespace pf {
namespace MODL::ANIM::v22 {
struct ModelVisTrackDataV30 {
  pf::qword bone_token;
  std::vector<float> keys;
};

struct ModelTrackTypeDataV22 {
  pf::byte type;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelUVAnimationV22 {
  pf::dword uv_anim_id;
  std::vector<ModelTrackTypeDataV22> uv_transform_data;
};

struct ModelCloudAnimV22 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV22> cloud_track_data;
};

struct ModelMatConstAnimV22 {
  pf::dword material_id;
  pf::dword const_token;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelLightAnimationV22 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV22> light_track_data;
};

struct ModelAnimPropertyDataV22 {
  pf::qword id;
  pf::dword type;
  float time;
  pf::qword val;
  pf::filename str_val;
};

struct ModelTokenMapAnimV22 {
  pf::qword link_token;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelBoneConstraintAnimV22 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV22> bc_track_data;
};

struct ModelAnchorAnimV22 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV22> anchor_track_data;
};

struct ModelStreakAnimV22 {
  pf::qword bone;
  std::vector<ModelAnchorAnimV22> anchor_anim;
};

struct ModelLightningAnimV22 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV22> lightning_track_data;
};

struct ModelWindAnimationV22 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV22> wind_track_data;
};

struct ModelAnimationDataV30 {
  pf::qword token;
  PackGrannyAnimationTypeV0 data;
  float move_speed;
  std::vector<ModelVisTrackDataV30> vis_track_data;
  std::vector<ModelUVAnimationV22> uv_anim_data;
  std::vector<ModelCloudAnimV22> cloud_anim;
  std::vector<ModelMatConstAnimV22> mat_const_anim;
  std::vector<pf::word> morph_track_groups;
  std::vector<float> trigger_times;
  std::vector<pf::qword> trigger_tokens;
  std::vector<ModelLightAnimationV22> light_anim_data;
  pf::dword is_additive;
  pf::dword variant_count;
  std::array<pf::dword, 3> variant_indices;
  std::vector<ModelAnimPropertyDataV22> properties;
  pf::float3 center;
  float radius;
  std::vector<ModelTokenMapAnimV22> token_map_anims;
  std::vector<ModelBoneConstraintAnimV22> bc_anim;
  std::vector<ModelStreakAnimV22> streak_anim;
  std::vector<ModelLightningAnimV22> lightning_anim;
  std::vector<ModelWindAnimationV22> wind_anim_data;
};

struct ModelCompoundAnimationDataV22 {
  pf::qword token;
  pf::qword start;
  pf::qword loop;
  pf::qword end;
};

struct ModelAnimationImportSequenceV22 {
  pf::qword name;
  float duration;
};

struct ModelAnimationImportDataV30 {
  pf::filename filename;
  std::vector<ModelAnimationImportSequenceV22> sequences;
};

struct ModelFileAnimationBankV22 {
  std::vector<std::shared_ptr<ModelAnimationDataV30>> animations;
  std::vector<ModelCompoundAnimationDataV22> compound_animations;
  std::vector<pf::qword> fallbacks;
  std::vector<ModelAnimationImportDataV30> imports;
};
} // namespace MODL::ANIM::v22

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v22::ModelVisTrackDataV30 &value) {
  reader(value.bone_token);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v22::ModelTrackTypeDataV22 &value) {
  reader(value.type);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v22::ModelUVAnimationV22 &value) {
  reader(value.uv_anim_id);
  reader(value.uv_transform_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v22::ModelCloudAnimV22 &value) {
  reader(value.bone);
  reader(value.cloud_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v22::ModelMatConstAnimV22 &value) {
  reader(value.material_id);
  reader(value.const_token);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v22::ModelLightAnimationV22 &value) {
  reader(value.bone);
  reader(value.light_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v22::ModelAnimPropertyDataV22 &value) {
  reader(value.id);
  reader(value.type);
  reader(value.time);
  reader(value.val);
  reader(value.str_val);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v22::ModelTokenMapAnimV22 &value) {
  reader(value.link_token);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v22::ModelBoneConstraintAnimV22 &value) {
  reader(value.bone);
  reader(value.bc_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v22::ModelAnchorAnimV22 &value) {
  reader(value.bone);
  reader(value.anchor_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v22::ModelStreakAnimV22 &value) {
  reader(value.bone);
  reader(value.anchor_anim);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v22::ModelLightningAnimV22 &value) {
  reader(value.bone);
  reader(value.lightning_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v22::ModelWindAnimationV22 &value) {
  reader(value.bone);
  reader(value.wind_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v22::ModelAnimationDataV30 &value) {
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
          MODL::ANIM::v22::ModelCompoundAnimationDataV22 &value) {
  reader(value.token);
  reader(value.start);
  reader(value.loop);
  reader(value.end);
}

template <typename Reader>
void Read(Reader &reader,
          MODL::ANIM::v22::ModelAnimationImportSequenceV22 &value) {
  reader(value.name);
  reader(value.duration);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v22::ModelAnimationImportDataV30 &value) {
  reader(value.filename);
  reader(value.sequences);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v22::ModelFileAnimationBankV22 &value) {
  reader(value.animations);
  reader(value.compound_animations);
  reader(value.fallbacks);
  reader(value.imports);
}
} // namespace de

} // namespace pf

#endif
