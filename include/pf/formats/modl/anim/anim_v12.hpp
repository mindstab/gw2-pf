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

#if MODL_ANIM_MIN_VERSION <= 12

#include "pf/types.hpp"

namespace pf {
namespace MODL::ANIM::v12 {
struct ModelVisTrackDataV20 {
  pf::dword bone_index;
  std::vector<float> keys;
};

struct ModelTrackTypeDataV12 {
  pf::byte type;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelUVAnimationV12 {
  pf::dword uv_anim_id;
  std::vector<ModelTrackTypeDataV12> uv_transform_data;
};

struct ModelCloudAnimV12 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV12> cloud_track_data;
};

struct ModelMatConstAnimV12 {
  pf::dword mat_index;
  pf::dword const_token;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelLightAnimationV12 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV12> light_track_data;
};

struct ModelAnimPropertyDataV12 {
  pf::qword id;
  pf::dword type;
  pf::qword val;
  pf::filename str_val;
};

struct ModelTokenMapAnimV12 {
  pf::qword link_token;
  pf::dword track_group_index;
  pf::dword vector_track_index;
  pf::float4 initial_value;
};

struct ModelAnimationDataV20 {
  pf::qword token;
  std::vector<pf::byte> data;
  float move_speed;
  std::vector<ModelVisTrackDataV20> vis_track_data;
  std::vector<ModelUVAnimationV12> uv_anim_data;
  std::vector<ModelCloudAnimV12> cloud_anim;
  std::vector<ModelMatConstAnimV12> mat_const_anim;
  std::vector<pf::word> morph_track_groups;
  std::vector<float> trigger_times;
  std::vector<pf::qword> trigger_tokens;
  std::vector<ModelLightAnimationV12> light_anim_data;
  pf::dword is_additive;
  pf::dword variant_count;
  std::array<pf::dword, 3> variant_indices;
  std::vector<ModelAnimPropertyDataV12> properties;
  pf::float3 center;
  float radius;
  std::vector<ModelTokenMapAnimV12> token_map_anims;
};

struct ModelCompoundAnimationDataV12 {
  pf::qword token;
  pf::qword start;
  pf::qword loop;
  pf::qword end;
};

struct ModelAnimationImportDataV20 {
  pf::filename filename;
  std::vector<pf::qword> sequence_tokens;
};

struct ModelFileAnimationBankV12 {
  std::vector<std::shared_ptr<ModelAnimationDataV20>> animations;
  std::vector<ModelCompoundAnimationDataV12> compound_animations;
  std::vector<pf::qword> fallbacks;
  std::vector<ModelAnimationImportDataV20> imports;
};
} // namespace MODL::ANIM::v12

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v12::ModelVisTrackDataV20 &value) {
  reader(value.bone_index);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v12::ModelTrackTypeDataV12 &value) {
  reader(value.type);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v12::ModelUVAnimationV12 &value) {
  reader(value.uv_anim_id);
  reader(value.uv_transform_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v12::ModelCloudAnimV12 &value) {
  reader(value.bone);
  reader(value.cloud_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v12::ModelMatConstAnimV12 &value) {
  reader(value.mat_index);
  reader(value.const_token);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v12::ModelLightAnimationV12 &value) {
  reader(value.bone);
  reader(value.light_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v12::ModelAnimPropertyDataV12 &value) {
  reader(value.id);
  reader(value.type);
  reader(value.val);
  reader(value.str_val);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v12::ModelTokenMapAnimV12 &value) {
  reader(value.link_token);
  reader(value.track_group_index);
  reader(value.vector_track_index);
  reader(value.initial_value);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v12::ModelAnimationDataV20 &value) {
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
}

template <typename Reader>
void Read(Reader &reader,
          MODL::ANIM::v12::ModelCompoundAnimationDataV12 &value) {
  reader(value.token);
  reader(value.start);
  reader(value.loop);
  reader(value.end);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v12::ModelAnimationImportDataV20 &value) {
  reader(value.filename);
  reader(value.sequence_tokens);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v12::ModelFileAnimationBankV12 &value) {
  reader(value.animations);
  reader(value.compound_animations);
  reader(value.fallbacks);
  reader(value.imports);
}
} // namespace de

} // namespace pf

#endif
