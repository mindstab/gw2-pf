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

#if MODL_TOOL_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace MODL::TOOL::v1 {
struct ModelToolCloudV1 {
  std::vector<pf::cstring> cloud_names;
  std::vector<pf::cstring> emitter_names;
  std::vector<pf::cstring> obstacle_names;
};

struct ModelToolMotionV1 {
  pf::qword sequence;
  std::vector<float> keys;
  std::vector<pf::float3> values;
};

struct ModelFileToolV1 {
  std::vector<pf::cstring> material_names;
  std::shared_ptr<ModelToolCloudV1> cloud_data;
  std::vector<ModelToolMotionV1> motions;
};
} // namespace MODL::TOOL::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v1::ModelToolCloudV1 &value) {
  reader(value.cloud_names);
  reader(value.emitter_names);
  reader(value.obstacle_names);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v1::ModelToolMotionV1 &value) {
  reader(value.sequence);
  reader(value.keys);
  reader(value.values);
}

template <typename Reader>
void Read(Reader &reader, MODL::TOOL::v1::ModelFileToolV1 &value) {
  reader(value.material_names);
  reader(value.cloud_data);
  reader(value.motions);
}
} // namespace de

} // namespace pf

#endif
