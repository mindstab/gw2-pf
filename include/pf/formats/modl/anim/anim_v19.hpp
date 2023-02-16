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

#if MODL_ANIM_MIN_VERSION <= 19

#include "pf/types.hpp"

namespace pf {
namespace MODL::ANIM::v19 {
struct ModelVisTrackDataV27 {
  pf::qword bone_token;
  std::vector<float> keys;
};

struct ModelTrackTypeDataV19 {
  pf::byte type;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelUVAnimationV19 {
  pf::dword uv_anim_id;
  std::vector<ModelTrackTypeDataV19> uv_transform_data;
};

struct ModelCloudAnimV19 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV19> cloud_track_data;
};

struct ModelMatConstAnimV19 {
  pf::dword material_id;
  pf::dword const_token;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelLightAnimationV19 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV19> light_track_data;
};

struct ModelAnimPropertyDataV19 {
  pf::qword id;
  pf::dword type;
  float time;
  pf::qword val;
  pf::filename str_val;
};

struct ModelTokenMapAnimV19 {
  pf::qword link_token;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelBoneConstraintAnimV19 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV19> bc_track_data;
};

struct ModelAnchorAnimV19 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV19> anchor_track_data;
};

struct ModelStreakAnimV19 {
  pf::qword bone;
  std::vector<ModelAnchorAnimV19> anchor_anim;
};

struct ModelAnimationDataV27 {
  pf::qword token;
  PackGrannyAnimationTypeV0 data;
  float move_speed;
  std::vector<ModelVisTrackDataV27> vis_track_data;
  std::vector<ModelUVAnimationV19> uv_anim_data;
  std::vector<ModelCloudAnimV19> cloud_anim;
  std::vector<ModelMatConstAnimV19> mat_const_anim;
  std::vector<pf::word> morph_track_groups;
  std::vector<float> trigger_times;
  std::vector<pf::qword> trigger_tokens;
  std::vector<ModelLightAnimationV19> light_anim_data;
  pf::dword is_additive;
  pf::dword variant_count;
  std::array<pf::dword, 3> variant_indices;
  std::vector<ModelAnimPropertyDataV19> properties;
  pf::float3 center;
  float radius;
  std::vector<ModelTokenMapAnimV19> token_map_anims;
  std::vector<ModelBoneConstraintAnimV19> bc_anim;
  std::vector<ModelStreakAnimV19> streak_anim;
};

struct ModelCompoundAnimationDataV19 {
  pf::qword token;
  pf::qword start;
  pf::qword loop;
  pf::qword end;
};

struct ModelAnimationImportSequenceV19 {
  pf::qword name;
  float duration;
};

struct ModelAnimationImportDataV27 {
  pf::filename filename;
  std::vector<ModelAnimationImportSequenceV19> sequences;
};

struct ModelFileAnimationBankV19 {
  std::vector<std::shared_ptr<ModelAnimationDataV27>> animations;
  std::vector<ModelCompoundAnimationDataV19> compound_animations;
  std::vector<pf::qword> fallbacks;
  std::vector<ModelAnimationImportDataV27> imports;
  pf::filename model_reference;
};
} // namespace MODL::ANIM::v19

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v19::ModelVisTrackDataV27 &value) {
  reader(value.bone_token);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v19::ModelTrackTypeDataV19 &value) {
  reader(value.type);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v19::ModelUVAnimationV19 &value) {
  reader(value.uv_anim_id);
  reader(value.uv_transform_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v19::ModelCloudAnimV19 &value) {
  reader(value.bone);
  reader(value.cloud_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v19::ModelMatConstAnimV19 &value) {
  reader(value.material_id);
  reader(value.const_token);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v19::ModelLightAnimationV19 &value) {
  reader(value.bone);
  reader(value.light_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v19::ModelAnimPropertyDataV19 &value) {
  reader(value.id);
  reader(value.type);
  reader(value.time);
  reader(value.val);
  reader(value.str_val);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v19::ModelTokenMapAnimV19 &value) {
  reader(value.link_token);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v19::ModelBoneConstraintAnimV19 &value) {
  reader(value.bone);
  reader(value.bc_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v19::ModelAnchorAnimV19 &value) {
  reader(value.bone);
  reader(value.anchor_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v19::ModelStreakAnimV19 &value) {
  reader(value.bone);
  reader(value.anchor_anim);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v19::ModelAnimationDataV27 &value) {
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
}

template <typename Reader>
void Read(Reader &reader,
          MODL::ANIM::v19::ModelCompoundAnimationDataV19 &value) {
  reader(value.token);
  reader(value.start);
  reader(value.loop);
  reader(value.end);
}

template <typename Reader>
void Read(Reader &reader,
          MODL::ANIM::v19::ModelAnimationImportSequenceV19 &value) {
  reader(value.name);
  reader(value.duration);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v19::ModelAnimationImportDataV27 &value) {
  reader(value.filename);
  reader(value.sequences);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v19::ModelFileAnimationBankV19 &value) {
  reader(value.animations);
  reader(value.compound_animations);
  reader(value.fallbacks);
  reader(value.imports);
  reader(value.model_reference);
}
} // namespace de

} // namespace pf

#endif
