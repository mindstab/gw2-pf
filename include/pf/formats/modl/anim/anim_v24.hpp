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

#if MODL_ANIM_MIN_VERSION <= 24

#include "pf/types.hpp"

namespace pf {
namespace MODL::ANIM::v24 {
struct ModelAnimationLodV24 {
  PackGrannyAnimationTypeV0 data;
  pf::filename file_full;
};

struct ModelVisTrackDataV32 {
  pf::qword bone_token;
  std::vector<float> keys;
};

struct ModelTrackTypeDataV24 {
  pf::byte type;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelUVAnimationV24 {
  pf::dword uv_anim_id;
  std::vector<ModelTrackTypeDataV24> uv_transform_data;
};

struct ModelCloudAnimV24 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV24> cloud_track_data;
};

struct ModelMatConstAnimV24 {
  pf::dword material_id;
  pf::dword const_token;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelLightAnimationV24 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV24> light_track_data;
};

struct ModelAnimPropertyDataV24 {
  pf::qword id;
  pf::dword type;
  float time;
  pf::qword val;
  pf::filename str_val;
};

struct ModelTokenMapAnimV24 {
  pf::qword link_token;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelBoneConstraintAnimV24 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV24> bc_track_data;
};

struct ModelAnchorAnimV24 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV24> anchor_track_data;
};

struct ModelStreakAnimV24 {
  pf::qword bone;
  std::vector<ModelAnchorAnimV24> anchor_anim;
};

struct ModelLightningAnimV24 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV24> lightning_track_data;
};

struct ModelWindAnimationV24 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV24> wind_track_data;
};

struct ModelAnimationDataV32 {
  pf::qword token;
  PackGrannyAnimationTypeV0 data;
  std::shared_ptr<ModelAnimationLodV24> anim_lod;
  float move_speed;
  std::vector<ModelVisTrackDataV32> vis_track_data;
  std::vector<ModelUVAnimationV24> uv_anim_data;
  std::vector<ModelCloudAnimV24> cloud_anim;
  std::vector<ModelMatConstAnimV24> mat_const_anim;
  std::vector<pf::word> morph_track_groups;
  std::vector<float> trigger_times;
  std::vector<pf::qword> trigger_tokens;
  std::vector<ModelLightAnimationV24> light_anim_data;
  pf::dword is_additive;
  pf::dword variant_count;
  std::array<pf::dword, 3> variant_indices;
  std::vector<ModelAnimPropertyDataV24> properties;
  pf::float3 center;
  float radius;
  std::vector<ModelTokenMapAnimV24> token_map_anims;
  std::vector<ModelBoneConstraintAnimV24> bc_anim;
  std::vector<ModelStreakAnimV24> streak_anim;
  std::vector<ModelLightningAnimV24> lightning_anim;
  std::vector<ModelWindAnimationV24> wind_anim_data;
};

struct ModelCompoundAnimationDataV24 {
  pf::qword token;
  pf::qword start;
  pf::qword loop;
  pf::qword end;
};

struct ModelAnimationImportSequenceV24 {
  pf::qword name;
  float duration;
};

struct ModelAnimationImportDataV32 {
  pf::filename filename;
  std::vector<ModelAnimationImportSequenceV24> sequences;
};

struct ModelFileAnimationBankV24 {
  std::vector<std::shared_ptr<ModelAnimationDataV32>> animations;
  std::vector<ModelCompoundAnimationDataV24> compound_animations;
  std::vector<pf::qword> fallbacks;
  std::vector<ModelAnimationImportDataV32> imports;
};

struct ModelFileAnimationV24 {
  std::shared_ptr<ModelFileAnimationBankV24> bank;
  PackGrannyAnimationTypeV0 anim;
};
} // namespace MODL::ANIM::v24

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v24::ModelAnimationLodV24 &value) {
  reader(value.data);
  reader(value.file_full);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v24::ModelVisTrackDataV32 &value) {
  reader(value.bone_token);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v24::ModelTrackTypeDataV24 &value) {
  reader(value.type);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v24::ModelUVAnimationV24 &value) {
  reader(value.uv_anim_id);
  reader(value.uv_transform_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v24::ModelCloudAnimV24 &value) {
  reader(value.bone);
  reader(value.cloud_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v24::ModelMatConstAnimV24 &value) {
  reader(value.material_id);
  reader(value.const_token);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v24::ModelLightAnimationV24 &value) {
  reader(value.bone);
  reader(value.light_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v24::ModelAnimPropertyDataV24 &value) {
  reader(value.id);
  reader(value.type);
  reader(value.time);
  reader(value.val);
  reader(value.str_val);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v24::ModelTokenMapAnimV24 &value) {
  reader(value.link_token);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v24::ModelBoneConstraintAnimV24 &value) {
  reader(value.bone);
  reader(value.bc_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v24::ModelAnchorAnimV24 &value) {
  reader(value.bone);
  reader(value.anchor_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v24::ModelStreakAnimV24 &value) {
  reader(value.bone);
  reader(value.anchor_anim);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v24::ModelLightningAnimV24 &value) {
  reader(value.bone);
  reader(value.lightning_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v24::ModelWindAnimationV24 &value) {
  reader(value.bone);
  reader(value.wind_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v24::ModelAnimationDataV32 &value) {
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
          MODL::ANIM::v24::ModelCompoundAnimationDataV24 &value) {
  reader(value.token);
  reader(value.start);
  reader(value.loop);
  reader(value.end);
}

template <typename Reader>
void Read(Reader &reader,
          MODL::ANIM::v24::ModelAnimationImportSequenceV24 &value) {
  reader(value.name);
  reader(value.duration);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v24::ModelAnimationImportDataV32 &value) {
  reader(value.filename);
  reader(value.sequences);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v24::ModelFileAnimationBankV24 &value) {
  reader(value.animations);
  reader(value.compound_animations);
  reader(value.fallbacks);
  reader(value.imports);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v24::ModelFileAnimationV24 &value) {
  reader(value.bank);
  reader(value.anim);
}
} // namespace de

} // namespace pf

#endif
