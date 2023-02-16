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

#if MODL_TOOL_MIN_VERSION <= 14

#include "pf/types.hpp"

namespace pf {
namespace MODL::TOOL::v14 {
struct ModelToolCloudV14 {
  std::vector<pf::cstring> cloud_names;
  std::vector<pf::cstring> emitter_names;
};

struct ModelToolBlitTextureV14 {
  pf::qword blit_id;
  pf::fileref filename;
};

struct ModelToolStreakV14 {
  std::vector<pf::cstring> streak_names;
  std::vector<pf::cstring> anchor_names;
};

struct ModelToolLightningV14 {
  std::vector<pf::cstring> system_names;
  std::vector<pf::cstring> bolt_names;
  std::vector<pf::cstring> node_names;
};

struct ModelToolAnimationV14 {
  pf::qword name;
  pf::wstring filename;
  PackGrannyAnimationTypeV0 data;
};

struct ModelSequenceCompressionInfoV14 {
  pf::qword anim_token;
  pf::wstring cmp_group;
  pf::wstring cmp_type;
};

struct ModelFileToolV14 {
  pf::qword model_type;
  std::vector<pf::cstring> material_names;
  std::vector<pf::cstring> obstacle_names;
  std::shared_ptr<ModelToolCloudV14> cloud_data;
  std::vector<ModelToolBlitTextureV14> blit_textures;
  std::shared_ptr<ModelToolStreakV14> streak_data;
  std::shared_ptr<ModelToolLightningV14> lightning_data;
  std::vector<pf::qword> permutation_tokens;
  std::vector<ModelToolAnimationV14> high_lod_animations;
  std::vector<ModelSequenceCompressionInfoV14> compression_infos;
};
} // namespace MODL::TOOL::v14

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v14::ModelToolCloudV14 &value) {
  reader(value.cloud_names);
  reader(value.emitter_names);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v14::ModelToolBlitTextureV14 &value) {
  reader(value.blit_id);
  reader(value.filename);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v14::ModelToolStreakV14 &value) {
  reader(value.streak_names);
  reader(value.anchor_names);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v14::ModelToolLightningV14 &value) {
  reader(value.system_names);
  reader(value.bolt_names);
  reader(value.node_names);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v14::ModelToolAnimationV14 &value) {
  reader(value.name);
  reader(value.filename);
  reader(value.data);
}

template <typename Reader>
void Read(Reader &reader,
          MODL::TOOL::v14::ModelSequenceCompressionInfoV14 &value) {
  reader(value.anim_token);
  reader(value.cmp_group);
  reader(value.cmp_type);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v14::ModelFileToolV14 &value) {
  reader(value.model_type);
  reader(value.material_names);
  reader(value.obstacle_names);
  reader(value.cloud_data);
  reader(value.blit_textures);
  reader(value.streak_data);
  reader(value.lightning_data);
  reader(value.permutation_tokens);
  reader(value.high_lod_animations);
  reader(value.compression_infos);
}
} // namespace de

} // namespace pf

#endif
