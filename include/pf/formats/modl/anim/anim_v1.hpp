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

#if MODL_ANIM_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace MODL::ANIM::v1 {
struct ModelVisTrackDataV9 {
  pf::dword bone_index;
  std::vector<float> keys;
};

struct ModelUVTransformV1 {
  pf::byte type;
  pf::dword vector_track_index;
};

struct ModelUVAnimationV1 {
  pf::byte uv_anim_id;
  std::vector<ModelUVTransformV1> uv_transform_data;
};

struct ModelAnimationDataV9 {
  pf::qword token;
  std::vector<pf::byte> data;
  float move_speed;
  std::vector<ModelVisTrackDataV9> vis_track_data;
  std::vector<ModelUVAnimationV1> uv_anim_data;
  std::vector<float> trigger_times;
  std::vector<pf::qword> trigger_tokens;
};

struct ModelCompoundAnimationDataV1 {
  pf::qword token;
  pf::qword start;
  pf::qword loop;
  pf::qword end;
};

struct ModelAnimationImportDataV9 {
  pf::filename filename;
  std::vector<pf::qword> sequence_tokens;
};

struct ModelFileAnimationV1 {
  std::vector<std::shared_ptr<ModelAnimationDataV9>> animations;
  std::vector<ModelCompoundAnimationDataV1> compound_animations;
  std::vector<pf::qword> fallbacks;
  std::vector<ModelAnimationImportDataV9> imports;
};
} // namespace MODL::ANIM::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v1::ModelVisTrackDataV9 &value) {
  reader(value.bone_index);
  reader(value.keys);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v1::ModelUVTransformV1 &value) {
  reader(value.type);
  reader(value.vector_track_index);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v1::ModelUVAnimationV1 &value) {
  reader(value.uv_anim_id);
  reader(value.uv_transform_data);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v1::ModelAnimationDataV9 &value) {
  reader(value.token);
  reader(value.data);
  reader(value.move_speed);
  reader(value.vis_track_data);
  reader(value.uv_anim_data);
  reader(value.trigger_times);
  reader(value.trigger_tokens);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v1::ModelCompoundAnimationDataV1 &value) {
  reader(value.token);
  reader(value.start);
  reader(value.loop);
  reader(value.end);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v1::ModelAnimationImportDataV9 &value) {
  reader(value.filename);
  reader(value.sequence_tokens);
}

template <typename Reader>
void Read(Reader &reader, MODL::ANIM::v1::ModelFileAnimationV1 &value) {
  reader(value.animations);
  reader(value.compound_animations);
  reader(value.fallbacks);
  reader(value.imports);
}
} // namespace de

} // namespace pf

#endif
