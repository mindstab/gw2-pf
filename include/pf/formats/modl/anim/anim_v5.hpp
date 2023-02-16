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

#if MODL_ANIM_MIN_VERSION <= 5

#include "pf/types.hpp"

namespace pf {
namespace MODL::ANIM::v5 {
struct ModelVisTrackDataV13 {
  pf::dword bone_index;
  std::vector<float> keys;
};

struct ModelTrackTypeDataV5 {
  pf::byte type;
  pf::dword vector_track_index;
};

struct ModelUVAnimationV5 {
  pf::byte uv_anim_id;
  std::vector<ModelTrackTypeDataV5> uv_transform_data;
};

struct ModelLightAnimationV5 {
  pf::qword bone;
  std::vector<ModelTrackTypeDataV5> light_track_data;
};

struct ModelAnimationDataV13 {
  pf::qword token;
  std::vector<pf::byte> data;
  float move_speed;
  std::vector<ModelVisTrackDataV13> vis_track_data;
  std::vector<ModelUVAnimationV5> uv_anim_data;
  std::vector<pf::word> morph_track_groups;
  std::vector<float> trigger_times;
  std::vector<pf::qword> trigger_tokens;
  std::vector<ModelLightAnimationV5> light_anim_data;
  pf::dword is_additive;
};

struct ModelCompoundAnimationDataV5 {
  pf::qword token;
  pf::qword start;
  pf::qword loop;
  pf::qword end;
};

struct ModelAnimationImportDataV13 {
  pf::filename filename;
  std::vector<pf::qword> sequence_tokens;
};

struct ModelFileAnimationBankV5 {
  std::vector<std::shared_ptr<ModelAnimationDataV13>> animations;
  std::vector<ModelCompoundAnimationDataV5> compound_animations;
  std::vector<pf::qword> fallbacks;
  std::vector<ModelAnimationImportDataV13> imports;
};
} // namespace MODL::ANIM::v5

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v5::ModelVisTrackDataV13 &value) {
  reader(value.bone_index);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v5::ModelTrackTypeDataV5 &value) {
  reader(value.type);
  reader(value.vector_track_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v5::ModelUVAnimationV5 &value) {
  reader(value.uv_anim_id);
  reader(value.uv_transform_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v5::ModelLightAnimationV5 &value) {
  reader(value.bone);
  reader(value.light_track_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v5::ModelAnimationDataV13 &value) {
  reader(value.token);
  reader(value.data);
  reader(value.move_speed);
  reader(value.vis_track_data);
  reader(value.uv_anim_data);
  reader(value.morph_track_groups);
  reader(value.trigger_times);
  reader(value.trigger_tokens);
  reader(value.light_anim_data);
  reader(value.is_additive);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v5::ModelCompoundAnimationDataV5 &value) {
  reader(value.token);
  reader(value.start);
  reader(value.loop);
  reader(value.end);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v5::ModelAnimationImportDataV13 &value) {
  reader(value.filename);
  reader(value.sequence_tokens);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v5::ModelFileAnimationBankV5 &value) {
  reader(value.animations);
  reader(value.compound_animations);
  reader(value.fallbacks);
  reader(value.imports);
}
} // namespace de

} // namespace pf

#endif
