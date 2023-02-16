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

#if MPSD_SHAD_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace mpsd::shad::v0 {
struct PackMapShadowTileV0 {
  pf::dword compression_mode;
  std::vector<pf::byte> bytes;
};

struct PackMapShadowV0 {
  pf::dword2 shadow_dims;
  pf::dword2 tile_dims;
  std::vector<PackMapShadowTileV0> tiles;
  std::array<float, 16> world_to_shadow;
  pf::float2 s;
  pf::float2 t;
  pf::float2 u;
};
} // namespace mpsd::shad::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, mpsd::shad::v0::PackMapShadowTileV0 &value) {
  reader(value.compression_mode);
  reader(value.bytes);
}

template <typename Reader>
void Read(Reader &reader, mpsd::shad::v0::PackMapShadowV0 &value) {
  reader(value.shadow_dims);
  reader(value.tile_dims);
  reader(value.tiles);
  reader(value.world_to_shadow);
  reader(value.s);
  reader(value.t);
  reader(value.u);
}
} // namespace de

} // namespace pf

#endif
