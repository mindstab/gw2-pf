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

#if MAPC_SHOR_MIN_VERSION <= 2

#include "pf/types.hpp"

namespace pf {
namespace mapc::shor::v2 {
struct MapShoreChain {
  float offset;
  float opacity;
  float animation_speed;
  pf::float2 edge_size;
  pf::dword flags;
  std::vector<pf::float2> points;
  pf::filename material_filename;
  std::vector<pf::filename> texture_filenames;
  float rest_time;
  std::array<pf::float2, 4> fade_ranges;
};

struct MapShore {
  std::vector<MapShoreChain> chains;
};
} // namespace mapc::shor::v2

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::shor::v2::MapShoreChain &value) {
  reader(value.offset);
  reader(value.opacity);
  reader(value.animation_speed);
  reader(value.edge_size);
  reader(value.flags);
  reader(value.points);
  reader(value.material_filename);
  reader(value.texture_filenames);
  reader(value.rest_time);
  reader(value.fade_ranges);
}

template <typename Reader>
void Read(Reader &reader, mapc::shor::v2::MapShore &value) {
  reader(value.chains);
}
} // namespace de

} // namespace pf

#endif
