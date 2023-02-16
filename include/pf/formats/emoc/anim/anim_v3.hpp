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

#if EMOC_ANIM_MIN_VERSION <= 3

#include "pf/types.hpp"

namespace pf {
namespace emoc::anim::v3 {
struct PackEmoteTimingV3 {
  pf::fileref model_file;
  float blend_in;
  float blend_out;
  pf::dword intro_duration;
  pf::dword loop_duration;
  pf::dword outro_duration;
  pf::dword start_offset;
};

struct PackEmoteAnimationV3 {
  pf::qword token;
  std::vector<PackEmoteTimingV3> timing;
};

struct PackEmoteAnimationsV3 {
  std::vector<PackEmoteAnimationV3> animation;
};
} // namespace emoc::anim::v3

namespace de {
template <typename Reader>
void Read(Reader &reader, emoc::anim::v3::PackEmoteTimingV3 &value) {
  reader(value.model_file);
  reader(value.blend_in);
  reader(value.blend_out);
  reader(value.intro_duration);
  reader(value.loop_duration);
  reader(value.outro_duration);
  reader(value.start_offset);
}

template <typename Reader>
void Read(Reader &reader, emoc::anim::v3::PackEmoteAnimationV3 &value) {
  reader(value.token);
  reader(value.timing);
}

template <typename Reader>
void Read(Reader &reader, emoc::anim::v3::PackEmoteAnimationsV3 &value) {
  reader(value.animation);
}
} // namespace de

} // namespace pf

#endif
