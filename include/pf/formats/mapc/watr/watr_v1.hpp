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

#if MAPC_WATR_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace mapc::watr::v1 {
struct PackMapWaterSurfaceV1 {
  pf::qword guid;
  pf::dword water_surface_flags;
  float water_surface_z;
  std::vector<pf::float2> vertices;
};

struct PackMapWaterV1 {
  pf::dword water_flags;
  float water_plane_z;
  std::vector<PackMapWaterSurfaceV1> water_surfaces;
};
} // namespace mapc::watr::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::watr::v1::PackMapWaterSurfaceV1 &value) {
  reader(value.guid);
  reader(value.water_surface_flags);
  reader(value.water_surface_z);
  reader(value.vertices);
}

template <typename Reader>
void Read(Reader &reader, mapc::watr::v1::PackMapWaterV1 &value) {
  reader(value.water_flags);
  reader(value.water_plane_z);
  reader(value.water_surfaces);
}
} // namespace de

} // namespace pf

#endif
