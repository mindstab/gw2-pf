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

#if MODL_TOOL_MIN_VERSION <= 9

#include "pf/types.hpp"

namespace pf {
namespace MODL::TOOL::v9 {
struct ModelToolCloudV9 {
  std::vector<pf::cstring> cloud_names;
  std::vector<pf::cstring> emitter_names;
};

struct ModelToolBlitTextureV9 {
  pf::qword blit_id;
  pf::filename filename;
};

struct ModelToolStreakV9 {
  std::vector<pf::cstring> streak_names;
  std::vector<pf::cstring> anchor_names;
};

struct ModelToolLightningV9 {
  std::vector<pf::cstring> system_names;
  std::vector<pf::cstring> bolt_names;
  std::vector<pf::cstring> node_names;
};

struct ModelToolPropertyDataV9 {
  pf::qword id;
  pf::dword type;
  pf::dword merge_index;
  float time;
  pf::qword val;
  pf::filename str_val;
};

struct ModelFileToolV9 {
  pf::qword model_type;
  std::vector<pf::cstring> material_names;
  std::vector<pf::cstring> obstacle_names;
  std::shared_ptr<ModelToolCloudV9> cloud_data;
  std::vector<ModelToolBlitTextureV9> blit_textures;
  std::shared_ptr<ModelToolStreakV9> streak_data;
  std::shared_ptr<ModelToolLightningV9> lightning_data;
  std::vector<pf::qword> permutation_tokens;
  std::vector<ModelToolPropertyDataV9> properties;
};
} // namespace MODL::TOOL::v9

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v9::ModelToolCloudV9 &value) {
  reader(value.cloud_names);
  reader(value.emitter_names);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v9::ModelToolBlitTextureV9 &value) {
  reader(value.blit_id);
  reader(value.filename);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v9::ModelToolStreakV9 &value) {
  reader(value.streak_names);
  reader(value.anchor_names);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v9::ModelToolLightningV9 &value) {
  reader(value.system_names);
  reader(value.bolt_names);
  reader(value.node_names);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v9::ModelToolPropertyDataV9 &value) {
  reader(value.id);
  reader(value.type);
  reader(value.merge_index);
  reader(value.time);
  reader(value.val);
  reader(value.str_val);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v9::ModelFileToolV9 &value) {
  reader(value.model_type);
  reader(value.material_names);
  reader(value.obstacle_names);
  reader(value.cloud_data);
  reader(value.blit_textures);
  reader(value.streak_data);
  reader(value.lightning_data);
  reader(value.permutation_tokens);
  reader(value.properties);
}
} // namespace de

} // namespace pf

#endif
