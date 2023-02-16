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

#if MODL_PRPS_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace MODL::PRPS::v0 {
struct ModelFixedOffsetData {
  pf::qword name;
  pf::qword parent_bone;
  pf::float3 translation;
};

struct ModelPropertyData {
  pf::qword id;
  pf::dword type;
  pf::dword merge_index;
  float time;
  pf::qword val;
  pf::filename str_val;
};

struct ModelFileProperties {
  std::vector<ModelFixedOffsetData> fixed_offset_data;
  std::vector<ModelPropertyData> properties;
};
} // namespace MODL::PRPS::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::PRPS::v0::ModelFixedOffsetData &value) {
  reader(value.name);
  reader(value.parent_bone);
  reader(value.translation);
}

template <typename Reader>
void Read(Reader &reader, MODL::PRPS::v0::ModelPropertyData &value) {
  reader(value.id);
  reader(value.type);
  reader(value.merge_index);
  reader(value.time);
  reader(value.val);
  reader(value.str_val);
}

template <typename Reader>
void Read(Reader &reader, MODL::PRPS::v0::ModelFileProperties &value) {
  reader(value.fixed_offset_data);
  reader(value.properties);
}
} // namespace de

} // namespace pf

#endif
