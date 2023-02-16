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

#if MAPC_LGHT_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace mapc::lght::v1 {
struct PackMapLight {
  pf::dword type;
  pf::float3 position;
  float elevation;
  float azimuth;
  pf::byte3 color;
  float intensity;
  float near_distance;
  float far_distance;
};

struct PackMapLights {
  std::vector<PackMapLight> lights;
};
} // namespace mapc::lght::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::lght::v1::PackMapLight &value) {
  reader(value.type);
  reader(value.position);
  reader(value.elevation);
  reader(value.azimuth);
  reader(value.color);
  reader(value.intensity);
  reader(value.near_distance);
  reader(value.far_distance);
}

template <typename Reader>
void Read(Reader &reader, mapc::lght::v1::PackMapLights &value) {
  reader(value.lights);
}
} // namespace de

} // namespace pf

#endif
