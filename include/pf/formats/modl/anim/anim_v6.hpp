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

#if MODL_ANIM_MIN_VERSION <= 6

#include "pf/types.hpp"

namespace pf {
namespace MODL::ANIM::v6 {
struct ModelVisTrackDataV14 {
  pf::dword bone_index;
  std::vector<float> keys;
};

struct ModelTrackTypeDataV6 {
  pf::byte type;
  pf::dword vector_track_index;
};

struct ModelUVAnimationV6 {
  pf::byte uv_anim_id;
  std::vector<ModelTrackTypeDataV6> uv_transform_data;
};

struct ModelCloudAnimV6 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV6> cloud_track_data;
};

struct ModelMatConstAnimV6 {
  pf::dword mat_index;
  pf::dword const_token;
  pf::dword vector_track_index;
};

struct ModelLightAnimationV6 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV6> light_track_data;
};

struct ModelAnimationDataV14 {
  pf::qword token;
  std::vector<pf::byte> data;
  float move_speed;
  std::vector<ModelVisTrackDataV14> vis_track_data;
  std::vector<ModelUVAnimationV6> uv_anim_data;
  std::vector<ModelCloudAnimV6> cloud_anim;
  std::vector<ModelMatConstAnimV6> mat_const_anim;
  std::vector<pf::word> morph_track_groups;
  std::vector<float> trigger_times;
  std::vector<pf::qword> trigger_tokens;
  std::vector<ModelLightAnimationV6> light_anim_data;
  pf::dword is_additive;
};

struct ModelCompoundAnimationDataV6 {
  pf::qword token;
  pf::qword start;
  pf::qword loop;
  pf::qword end;
};

struct ModelAnimationImportDataV14 {
  pf::filename filename;
  std::vector<pf::qword> sequence_tokens;
};

struct ModelFileAnimationBankV6 {
  std::vector<std::shared_ptr<ModelAnimationDataV14>> animations;
  std::vector<ModelCompoundAnimationDataV6> compound_animations;
  std::vector<pf::qword> fallbacks;
  std::vector<ModelAnimationImportDataV14> imports;
};
} // namespace MODL::ANIM::v6

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v6::ModelVisTrackDataV14 &value) {
  reader(value.bone_index);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v6::ModelTrackTypeDataV6 &value) {
  reader(value.type);
  reader(value.vector_track_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v6::ModelUVAnimationV6 &value) {
  reader(value.uv_anim_id);
  reader(value.uv_transform_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v6::ModelCloudAnimV6 &value) {
  reader(value.bone);
  reader(value.cloud_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v6::ModelMatConstAnimV6 &value) {
  reader(value.mat_index);
  reader(value.const_token);
  reader(value.vector_track_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v6::ModelLightAnimationV6 &value) {
  reader(value.bone);
  reader(value.light_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v6::ModelAnimationDataV14 &value) {
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
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v6::ModelCompoundAnimationDataV6 &value) {
  reader(value.token);
  reader(value.start);
  reader(value.loop);
  reader(value.end);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v6::ModelAnimationImportDataV14 &value) {
  reader(value.filename);
  reader(value.sequence_tokens);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v6::ModelFileAnimationBankV6 &value) {
  reader(value.animations);
  reader(value.compound_animations);
  reader(value.fallbacks);
  reader(value.imports);
}
} // namespace de

} // namespace pf

#endif
