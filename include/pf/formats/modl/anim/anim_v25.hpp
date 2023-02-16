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

#if MODL_ANIM_MIN_VERSION <= 25

#include "pf/types.hpp"

namespace pf {
namespace MODL::ANIM::v25 {
struct ModelAnimationLodV25 {
  PackGrannyAnimationTypeV1 data;
  pf::filename file_full;
};

struct ModelVisTrackDataV33 {
  pf::qword bone_token;
  std::vector<float> keys;
};

struct ModelTrackTypeDataV25 {
  pf::byte type;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelUVAnimationV25 {
  pf::dword uv_anim_id;
  std::vector<ModelTrackTypeDataV25> uv_transform_data;
};

struct ModelCloudAnimV25 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV25> cloud_track_data;
};

struct ModelMatConstAnimV25 {
  pf::dword material_id;
  pf::dword const_token;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelLightAnimationV25 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV25> light_track_data;
};

struct ModelAnimPropertyDataV25 {
  pf::qword id;
  pf::dword type;
  float time;
  pf::qword val;
  pf::filename str_val;
};

struct ModelTokenMapAnimV25 {
  pf::qword link_token;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelBoneConstraintAnimV25 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV25> bc_track_data;
};

struct ModelAnchorAnimV25 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV25> anchor_track_data;
};

struct ModelStreakAnimV25 {
  pf::qword bone;
  std::vector<ModelAnchorAnimV25> anchor_anim;
};

struct ModelLightningAnimV25 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV25> lightning_track_data;
};

struct ModelWindAnimationV25 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV25> wind_track_data;
};

struct ModelAnimationDataV33 {
  pf::qword token;
  PackGrannyAnimationTypeV1 data;
  std::shared_ptr<ModelAnimationLodV25> anim_lod;
  float move_speed;
  std::vector<ModelVisTrackDataV33> vis_track_data;
  std::vector<ModelUVAnimationV25> uv_anim_data;
  std::vector<ModelCloudAnimV25> cloud_anim;
  std::vector<ModelMatConstAnimV25> mat_const_anim;
  std::vector<pf::word> morph_track_groups;
  std::vector<float> trigger_times;
  std::vector<pf::qword> trigger_tokens;
  std::vector<ModelLightAnimationV25> light_anim_data;
  pf::dword is_additive;
  pf::dword variant_count;
  std::array<pf::dword, 3> variant_indices;
  std::vector<ModelAnimPropertyDataV25> properties;
  pf::float3 center;
  float radius;
  std::vector<ModelTokenMapAnimV25> token_map_anims;
  std::vector<ModelBoneConstraintAnimV25> bc_anim;
  std::vector<ModelStreakAnimV25> streak_anim;
  std::vector<ModelLightningAnimV25> lightning_anim;
  std::vector<ModelWindAnimationV25> wind_anim_data;
};

struct ModelCompoundAnimationDataV25 {
  pf::qword token;
  pf::qword start;
  pf::qword loop;
  pf::qword end;
};

struct ModelAnimationImportSequenceV25 {
  pf::qword name;
  float duration;
};

struct ModelAnimationImportDataV33 {
  pf::filename filename;
  std::vector<ModelAnimationImportSequenceV25> sequences;
};

struct ModelFileAnimationBankV25 {
  std::vector<std::shared_ptr<ModelAnimationDataV33>> animations;
  std::vector<ModelCompoundAnimationDataV25> compound_animations;
  std::vector<pf::qword> fallbacks;
  std::vector<ModelAnimationImportDataV33> imports;
};

struct ModelFileAnimationV25 {
  std::shared_ptr<ModelFileAnimationBankV25> bank;
  PackGrannyAnimationTypeV1 anim;
};
} // namespace MODL::ANIM::v25

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v25::ModelAnimationLodV25 &value) {
  reader(value.data);
  reader(value.file_full);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v25::ModelVisTrackDataV33 &value) {
  reader(value.bone_token);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v25::ModelTrackTypeDataV25 &value) {
  reader(value.type);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v25::ModelUVAnimationV25 &value) {
  reader(value.uv_anim_id);
  reader(value.uv_transform_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v25::ModelCloudAnimV25 &value) {
  reader(value.bone);
  reader(value.cloud_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v25::ModelMatConstAnimV25 &value) {
  reader(value.material_id);
  reader(value.const_token);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v25::ModelLightAnimationV25 &value) {
  reader(value.bone);
  reader(value.light_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v25::ModelAnimPropertyDataV25 &value) {
  reader(value.id);
  reader(value.type);
  reader(value.time);
  reader(value.val);
  reader(value.str_val);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v25::ModelTokenMapAnimV25 &value) {
  reader(value.link_token);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v25::ModelBoneConstraintAnimV25 &value) {
  reader(value.bone);
  reader(value.bc_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v25::ModelAnchorAnimV25 &value) {
  reader(value.bone);
  reader(value.anchor_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v25::ModelStreakAnimV25 &value) {
  reader(value.bone);
  reader(value.anchor_anim);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v25::ModelLightningAnimV25 &value) {
  reader(value.bone);
  reader(value.lightning_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v25::ModelWindAnimationV25 &value) {
  reader(value.bone);
  reader(value.wind_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v25::ModelAnimationDataV33 &value) {
  reader(value.token);
  reader(value.data);
  reader(value.anim_lod);
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
          MODL::ANIM::v25::ModelCompoundAnimationDataV25 &value) {
  reader(value.token);
  reader(value.start);
  reader(value.loop);
  reader(value.end);
}

template <typename Reader>
void Read(Reader &reader,
          MODL::ANIM::v25::ModelAnimationImportSequenceV25 &value) {
  reader(value.name);
  reader(value.duration);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v25::ModelAnimationImportDataV33 &value) {
  reader(value.filename);
  reader(value.sequences);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v25::ModelFileAnimationBankV25 &value) {
  reader(value.animations);
  reader(value.compound_animations);
  reader(value.fallbacks);
  reader(value.imports);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v25::ModelFileAnimationV25 &value) {
  reader(value.bank);
  reader(value.anim);
}
} // namespace de

} // namespace pf

#endif
