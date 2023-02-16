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

#if MODL_EXPA_MIN_VERSION <= 2

#include "pf/types.hpp"

namespace pf {
namespace MODL::EXPA::v2 {
struct ModelFileSnapPointV2 {
  pf::qword bone;
  pf::qword shape;
};

struct ModelExpansionEmitterV2 {
  float curl;
  float vortex_size;
  pf::dword curl_quality;
  pf::dword curl_flags;
  float field_scale;
};

struct ModelFileExpansionV2 {
  std::vector<ModelFileSnapPointV2> snap_points;
  float snap_point_priority;
  std::vector<ModelExpansionEmitterV2> emitters;
};
} // namespace MODL::EXPA::v2

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::EXPA::v2::ModelFileSnapPointV2 &value) {
  reader(value.bone);
  reader(value.shape);
}

template <typename Reader>
void Read(Reader &reader, MODL::EXPA::v2::ModelExpansionEmitterV2 &value) {
  reader(value.curl);
  reader(value.vortex_size);
  reader(value.curl_quality);
  reader(value.curl_flags);
  reader(value.field_scale);
}

template <typename Reader>
void Read(Reader &reader, MODL::EXPA::v2::ModelFileExpansionV2 &value) {
  reader(value.snap_points);
  reader(value.snap_point_priority);
  reader(value.emitters);
}
} // namespace de

} // namespace pf

#endif
