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

#if MODL_TOOL_MIN_VERSION <= 7

#include "pf/types.hpp"

namespace pf {
namespace MODL::TOOL::v7 {
struct ModelToolCloudV7 {
  std::vector<pf::cstring> cloud_names;
  std::vector<pf::cstring> emitter_names;
};

struct ModelToolBlitTextureV7 {
  pf::qword blit_id;
  pf::filename filename;
};

struct ModelToolStreakV7 {
  std::vector<pf::cstring> streak_names;
  std::vector<pf::cstring> anchor_names;
};

struct ModelToolLightningV7 {
  std::vector<pf::cstring> system_names;
  std::vector<pf::cstring> bolt_names;
  std::vector<pf::cstring> node_names;
};

struct ModelFileToolV7 {
  pf::qword model_type;
  std::vector<pf::cstring> material_names;
  std::vector<pf::cstring> obstacle_names;
  std::shared_ptr<ModelToolCloudV7> cloud_data;
  std::vector<ModelToolBlitTextureV7> blit_textures;
  std::shared_ptr<ModelToolStreakV7> streak_data;
  std::shared_ptr<ModelToolLightningV7> lightning_data;
};
} // namespace MODL::TOOL::v7

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v7::ModelToolCloudV7 &value) {
  reader(value.cloud_names);
  reader(value.emitter_names);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v7::ModelToolBlitTextureV7 &value) {
  reader(value.blit_id);
  reader(value.filename);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v7::ModelToolStreakV7 &value) {
  reader(value.streak_names);
  reader(value.anchor_names);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v7::ModelToolLightningV7 &value) {
  reader(value.system_names);
  reader(value.bolt_names);
  reader(value.node_names);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v7::ModelFileToolV7 &value) {
  reader(value.model_type);
  reader(value.material_names);
  reader(value.obstacle_names);
  reader(value.cloud_data);
  reader(value.blit_textures);
  reader(value.streak_data);
  reader(value.lightning_data);
}
} // namespace de

} // namespace pf

#endif
