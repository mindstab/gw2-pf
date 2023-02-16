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

#if MODL_ROOT_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace MODL::ROOT::v1 {
struct ModelRootMotionV1 {
  pf::qword sequence;
  std::vector<float> keys;
  std::vector<pf::float3> pos_values;
  std::vector<pf::float4> quat_values;
};

struct ModelFileRootMotionV1 {
  std::vector<ModelRootMotionV1> root_motions;
};
} // namespace MODL::ROOT::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::ROOT::v1::ModelRootMotionV1 &value) {
  reader(value.sequence);
  reader(value.keys);
  reader(value.pos_values);
  reader(value.quat_values);
}

template <typename Reader>
void Read(Reader &reader, MODL::ROOT::v1::ModelFileRootMotionV1 &value) {
  reader(value.root_motions);
}
} // namespace de

} // namespace pf

#endif
