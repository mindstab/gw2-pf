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

#if EMOC_ANIM_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace emoc::anim::v1 {
struct PackEmoteTimingV1 {
  pf::fileref model_file_id;
  float blend_in_time;
  float blend_out_time;
  pf::dword duration;
  pf::dword loop_duration;
};

struct PackEmoteAnimationV1 {
  pf::qword token;
  std::vector<PackEmoteTimingV1> timings;
};

struct PackEmoteAnimationsV1 {
  std::vector<PackEmoteAnimationV1> animations;
};
} // namespace emoc::anim::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, emoc::anim::v1::PackEmoteTimingV1 &value) {
  reader(value.model_file_id);
  reader(value.blend_in_time);
  reader(value.blend_out_time);
  reader(value.duration);
  reader(value.loop_duration);
}

template <typename Reader>
void Read(Reader &reader, emoc::anim::v1::PackEmoteAnimationV1 &value) {
  reader(value.token);
  reader(value.timings);
}

template <typename Reader>
void Read(Reader &reader, emoc::anim::v1::PackEmoteAnimationsV1 &value) {
  reader(value.animations);
}
} // namespace de

} // namespace pf

#endif
