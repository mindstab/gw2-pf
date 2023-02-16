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

#if MODL_ANIM_MIN_VERSION <= 18

#include "pf/types.hpp"

namespace pf {
namespace MODL::ANIM::v18 {
struct ModelVisTrackDataV26 {
  pf::qword bone_token;
  std::vector<float> keys;
};

struct ModelTrackTypeDataV18 {
  pf::byte type;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelUVAnimationV18 {
  pf::dword uv_anim_id;
  std::vector<ModelTrackTypeDataV18> uv_transform_data;
};

struct ModelCloudAnimV18 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV18> cloud_track_data;
};

struct ModelMatConstAnimV18 {
  pf::dword material_id;
  pf::dword const_token;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelLightAnimationV18 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV18> light_track_data;
};

struct ModelAnimPropertyDataV18 {
  pf::qword id;
  pf::dword type;
  float time;
  pf::qword val;
  pf::filename str_val;
};

struct ModelTokenMapAnimV18 {
  pf::qword link_token;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelBoneConstraintAnimV18 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV18> bc_track_data;
};

struct ModelAnchorAnimV18 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV18> anchor_track_data;
};

struct ModelStreakAnimV18 {
  pf::qword bone;
  std::vector<ModelAnchorAnimV18> anchor_anim;
};

struct ModelAnimationDataV26 {
  pf::qword token;
  PackGrannyAnimationTypeV0 data;
  float move_speed;
  std::vector<ModelVisTrackDataV26> vis_track_data;
  std::vector<ModelUVAnimationV18> uv_anim_data;
  std::vector<ModelCloudAnimV18> cloud_anim;
  std::vector<ModelMatConstAnimV18> mat_const_anim;
  std::vector<pf::word> morph_track_groups;
  std::vector<float> trigger_times;
  std::vector<pf::qword> trigger_tokens;
  std::vector<ModelLightAnimationV18> light_anim_data;
  pf::dword is_additive;
  pf::dword variant_count;
  std::array<pf::dword, 3> variant_indices;
  std::vector<ModelAnimPropertyDataV18> properties;
  pf::float3 center;
  float radius;
  std::vector<ModelTokenMapAnimV18> token_map_anims;
  std::vector<ModelBoneConstraintAnimV18> bc_anim;
  std::vector<ModelStreakAnimV18> streak_anim;
};

struct ModelCompoundAnimationDataV18 {
  pf::qword token;
  pf::qword start;
  pf::qword loop;
  pf::qword end;
};

struct ModelAnimationImportSequenceV18 {
  pf::qword name;
  float duration;
};

struct ModelAnimationImportDataV26 {
  pf::filename filename;
  std::vector<ModelAnimationImportSequenceV18> sequences;
};

struct ModelFileAnimationBankV18 {
  std::vector<std::shared_ptr<ModelAnimationDataV26>> animations;
  std::vector<ModelCompoundAnimationDataV18> compound_animations;
  std::vector<pf::qword> fallbacks;
  std::vector<ModelAnimationImportDataV26> imports;
};
} // namespace MODL::ANIM::v18

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v18::ModelVisTrackDataV26 &value) {
  reader(value.bone_token);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v18::ModelTrackTypeDataV18 &value) {
  reader(value.type);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v18::ModelUVAnimationV18 &value) {
  reader(value.uv_anim_id);
  reader(value.uv_transform_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v18::ModelCloudAnimV18 &value) {
  reader(value.bone);
  reader(value.cloud_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v18::ModelMatConstAnimV18 &value) {
  reader(value.material_id);
  reader(value.const_token);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v18::ModelLightAnimationV18 &value) {
  reader(value.bone);
  reader(value.light_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v18::ModelAnimPropertyDataV18 &value) {
  reader(value.id);
  reader(value.type);
  reader(value.time);
  reader(value.val);
  reader(value.str_val);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v18::ModelTokenMapAnimV18 &value) {
  reader(value.link_token);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v18::ModelBoneConstraintAnimV18 &value) {
  reader(value.bone);
  reader(value.bc_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v18::ModelAnchorAnimV18 &value) {
  reader(value.bone);
  reader(value.anchor_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v18::ModelStreakAnimV18 &value) {
  reader(value.bone);
  reader(value.anchor_anim);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v18::ModelAnimationDataV26 &value) {
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
          MODL::ANIM::v18::ModelCompoundAnimationDataV18 &value) {
  reader(value.token);
  reader(value.start);
  reader(value.loop);
  reader(value.end);
}

template <typename Reader>
void Read(Reader &reader,
          MODL::ANIM::v18::ModelAnimationImportSequenceV18 &value) {
  reader(value.name);
  reader(value.duration);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v18::ModelAnimationImportDataV26 &value) {
  reader(value.filename);
  reader(value.sequences);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v18::ModelFileAnimationBankV18 &value) {
  reader(value.animations);
  reader(value.compound_animations);
  reader(value.fallbacks);
  reader(value.imports);
}
} // namespace de

} // namespace pf

#endif
