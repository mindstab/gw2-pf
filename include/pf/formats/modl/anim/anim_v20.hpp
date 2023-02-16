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

#if MODL_ANIM_MIN_VERSION <= 20

#include "pf/types.hpp"

namespace pf {
namespace MODL::ANIM::v20 {
struct ModelVisTrackDataV28 {
  pf::qword bone_token;
  std::vector<float> keys;
};

struct ModelTrackTypeDataV20 {
  pf::byte type;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelUVAnimationV20 {
  pf::dword uv_anim_id;
  std::vector<ModelTrackTypeDataV20> uv_transform_data;
};

struct ModelCloudAnimV20 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV20> cloud_track_data;
};

struct ModelMatConstAnimV20 {
  pf::dword material_id;
  pf::dword const_token;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelLightAnimationV20 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV20> light_track_data;
};

struct ModelAnimPropertyDataV20 {
  pf::qword id;
  pf::dword type;
  float time;
  pf::qword val;
  pf::filename str_val;
};

struct ModelTokenMapAnimV20 {
  pf::qword link_token;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelBoneConstraintAnimV20 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV20> bc_track_data;
};

struct ModelAnchorAnimV20 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV20> anchor_track_data;
};

struct ModelStreakAnimV20 {
  pf::qword bone;
  std::vector<ModelAnchorAnimV20> anchor_anim;
};

struct ModelLightningAnimV20 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV20> lightning_track_data;
};

struct ModelAnimationDataV28 {
  pf::qword token;
  PackGrannyAnimationTypeV0 data;
  float move_speed;
  std::vector<ModelVisTrackDataV28> vis_track_data;
  std::vector<ModelUVAnimationV20> uv_anim_data;
  std::vector<ModelCloudAnimV20> cloud_anim;
  std::vector<ModelMatConstAnimV20> mat_const_anim;
  std::vector<pf::word> morph_track_groups;
  std::vector<float> trigger_times;
  std::vector<pf::qword> trigger_tokens;
  std::vector<ModelLightAnimationV20> light_anim_data;
  pf::dword is_additive;
  pf::dword variant_count;
  std::array<pf::dword, 3> variant_indices;
  std::vector<ModelAnimPropertyDataV20> properties;
  pf::float3 center;
  float radius;
  std::vector<ModelTokenMapAnimV20> token_map_anims;
  std::vector<ModelBoneConstraintAnimV20> bc_anim;
  std::vector<ModelStreakAnimV20> streak_anim;
  std::vector<ModelLightningAnimV20> lightning_anim;
};

struct ModelCompoundAnimationDataV20 {
  pf::qword token;
  pf::qword start;
  pf::qword loop;
  pf::qword end;
};

struct ModelAnimationImportSequenceV20 {
  pf::qword name;
  float duration;
};

struct ModelAnimationImportDataV28 {
  pf::filename filename;
  std::vector<ModelAnimationImportSequenceV20> sequences;
};

struct ModelFileAnimationBankV20 {
  std::vector<std::shared_ptr<ModelAnimationDataV28>> animations;
  std::vector<ModelCompoundAnimationDataV20> compound_animations;
  std::vector<pf::qword> fallbacks;
  std::vector<ModelAnimationImportDataV28> imports;
  pf::filename model_reference;
};
} // namespace MODL::ANIM::v20

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v20::ModelVisTrackDataV28 &value) {
  reader(value.bone_token);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v20::ModelTrackTypeDataV20 &value) {
  reader(value.type);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v20::ModelUVAnimationV20 &value) {
  reader(value.uv_anim_id);
  reader(value.uv_transform_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v20::ModelCloudAnimV20 &value) {
  reader(value.bone);
  reader(value.cloud_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v20::ModelMatConstAnimV20 &value) {
  reader(value.material_id);
  reader(value.const_token);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v20::ModelLightAnimationV20 &value) {
  reader(value.bone);
  reader(value.light_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v20::ModelAnimPropertyDataV20 &value) {
  reader(value.id);
  reader(value.type);
  reader(value.time);
  reader(value.val);
  reader(value.str_val);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v20::ModelTokenMapAnimV20 &value) {
  reader(value.link_token);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v20::ModelBoneConstraintAnimV20 &value) {
  reader(value.bone);
  reader(value.bc_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v20::ModelAnchorAnimV20 &value) {
  reader(value.bone);
  reader(value.anchor_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v20::ModelStreakAnimV20 &value) {
  reader(value.bone);
  reader(value.anchor_anim);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v20::ModelLightningAnimV20 &value) {
  reader(value.bone);
  reader(value.lightning_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v20::ModelAnimationDataV28 &value) {
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
}

template <typename Reader>
void Read(Reader &reader,
          MODL::ANIM::v20::ModelCompoundAnimationDataV20 &value) {
  reader(value.token);
  reader(value.start);
  reader(value.loop);
  reader(value.end);
}

template <typename Reader>
void Read(Reader &reader,
          MODL::ANIM::v20::ModelAnimationImportSequenceV20 &value) {
  reader(value.name);
  reader(value.duration);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v20::ModelAnimationImportDataV28 &value) {
  reader(value.filename);
  reader(value.sequences);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v20::ModelFileAnimationBankV20 &value) {
  reader(value.animations);
  reader(value.compound_animations);
  reader(value.fallbacks);
  reader(value.imports);
  reader(value.model_reference);
}
} // namespace de

} // namespace pf

#endif
