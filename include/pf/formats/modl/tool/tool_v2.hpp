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

#if MODL_TOOL_MIN_VERSION <= 2

#include "pf/types.hpp"

namespace pf {
namespace MODL::TOOL::v2 {
struct ModelToolCloudV2 {
  std::vector<pf::cstring> cloud_names;
  std::vector<pf::cstring> emitter_names;
  std::vector<pf::cstring> obstacle_names;
};

struct ModelToolMotionV2 {
  pf::qword sequence;
  std::vector<float> keys;
  std::vector<pf::float3> values;
};

struct ModelToolBlitTextureV2 {
  pf::qword blit_id;
  pf::filename filename;
};

struct ModelFileToolV2 {
  std::vector<pf::cstring> material_names;
  std::shared_ptr<ModelToolCloudV2> cloud_data;
  std::vector<ModelToolMotionV2> motions;
  std::vector<ModelToolBlitTextureV2> blit_textures;
};
} // namespace MODL::TOOL::v2

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v2::ModelToolCloudV2 &value) {
  reader(value.cloud_names);
  reader(value.emitter_names);
  reader(value.obstacle_names);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v2::ModelToolMotionV2 &value) {
  reader(value.sequence);
  reader(value.keys);
  reader(value.values);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v2::ModelToolBlitTextureV2 &value) {
  reader(value.blit_id);
  reader(value.filename);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v2::ModelFileToolV2 &value) {
  reader(value.material_names);
  reader(value.cloud_data);
  reader(value.motions);
  reader(value.blit_textures);
}
} // namespace de

} // namespace pf

#endif
