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

#if EMOC_ANIM_MIN_VERSION <= 2

#include "pf/types.hpp"

namespace pf {
namespace emoc::anim::v2 {
struct PackEmoteTimingV2 {
  pf::fileref model_file;
  float blend_in;
  float blend_out;
  pf::dword intro_duration;
  pf::dword loop_duration;
  pf::dword outro_duration;
};

struct PackEmoteAnimationV2 {
  pf::qword token;
  std::vector<PackEmoteTimingV2> timing;
};

struct PackEmoteAnimationsV2 {
  std::vector<PackEmoteAnimationV2> animation;
};
} // namespace emoc::anim::v2

namespace de {
template <typename Reader>
void Read(Reader &reader, emoc::anim::v2::PackEmoteTimingV2 &value) {
  reader(value.model_file);
  reader(value.blend_in);
  reader(value.blend_out);
  reader(value.intro_duration);
  reader(value.loop_duration);
  reader(value.outro_duration);
}

template <typename Reader>
void Read(Reader &reader, emoc::anim::v2::PackEmoteAnimationV2 &value) {
  reader(value.token);
  reader(value.timing);
}

template <typename Reader>
void Read(Reader &reader, emoc::anim::v2::PackEmoteAnimationsV2 &value) {
  reader(value.animation);
}
} // namespace de

} // namespace pf

#endif
