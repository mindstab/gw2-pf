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

#if LOCL_GRFX_MIN_VERSION <= 5

#include "pf/types.hpp"

namespace pf {
namespace locl::grfx::v5 {
struct PrefPackGraphicsCoord2u {
  pf::word x;
  pf::word y;
};

struct PrefPackGraphics {
  pf::byte mode;
  pf::byte preset;
  pf::byte animations;
  pf::byte antialiasing;
  pf::byte cinema;
  pf::byte environment;
  pf::dword flags;
  PrefPackGraphicsCoord2u fullscreen_size;
  pf::byte gamma;
  pf::byte post_proc;
  pf::byte reflection;
  pf::byte refresh;
  pf::byte sampling;
  pf::byte screen_mode;
  pf::byte shader;
  pf::byte shadow;
  pf::byte terrain;
  PrefPackGraphicsCoord2u window_pos;
  PrefPackGraphicsCoord2u window_size;
  pf::byte frame_limit;
  pf::byte lod_distance;
  pf::byte char_limit;
  pf::byte char_quality;
  pf::byte motion_blur;
};
} // namespace locl::grfx::v5

namespace de {
template <typename Reader>
void Read(Reader &reader, locl::grfx::v5::PrefPackGraphicsCoord2u &value) {
  reader(value.x);
  reader(value.y);
}

template <typename Reader>
void Read(Reader &reader, locl::grfx::v5::PrefPackGraphics &value) {
  reader(value.mode);
  reader(value.preset);
  reader(value.animations);
  reader(value.antialiasing);
  reader(value.cinema);
  reader(value.environment);
  reader(value.flags);
  reader(value.fullscreen_size);
  reader(value.gamma);
  reader(value.post_proc);
  reader(value.reflection);
  reader(value.refresh);
  reader(value.sampling);
  reader(value.screen_mode);
  reader(value.shader);
  reader(value.shadow);
  reader(value.terrain);
  reader(value.window_pos);
  reader(value.window_size);
  reader(value.frame_limit);
  reader(value.lod_distance);
  reader(value.char_limit);
  reader(value.char_quality);
  reader(value.motion_blur);
}
} // namespace de

} // namespace pf

#endif
