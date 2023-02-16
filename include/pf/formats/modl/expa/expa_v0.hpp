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

#if MODL_EXPA_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace MODL::EXPA::v0 {
struct ModelFileSnapPointV0 {
  pf::qword bone;
};

struct ModelExpansionEmitterV0 {
  float curl;
  float vortex_size;
};

struct ModelFileExpansionV0 {
  std::vector<ModelFileSnapPointV0> snap_points;
  float snap_point_priority;
  std::vector<ModelExpansionEmitterV0> emitters;
};
} // namespace MODL::EXPA::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::EXPA::v0::ModelFileSnapPointV0 &value) {
  reader(value.bone);
}

template <typename Reader>
void Read(Reader &reader, MODL::EXPA::v0::ModelExpansionEmitterV0 &value) {
  reader(value.curl);
  reader(value.vortex_size);
}

template <typename Reader>
void Read(Reader &reader, MODL::EXPA::v0::ModelFileExpansionV0 &value) {
  reader(value.snap_points);
  reader(value.snap_point_priority);
  reader(value.emitters);
}
} // namespace de

} // namespace pf

#endif
