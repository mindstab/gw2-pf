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

#if MAPC_LGHT_MIN_VERSION <= 4

#include "pf/types.hpp"

namespace pf {
namespace mapc::lght::v4 {
struct PackMapLight {
  pf::float3 position;
  pf::byte3 color;
  float intensity;
  float near_distance;
  float far_distance;
  pf::dword flags;
};

struct PackMapCurve {
  float gust;
  float gust_freq;
  float noise;
  float phase;
  float offset;
  float amplitude;
  pf::dword curve_type;
};

struct PackMapLightgroups {
  pf::qword guid;
  std::vector<PackMapLight> lights;
  std::vector<PackMapCurve> curves;
};

struct PackMapLights {
  std::vector<PackMapLightgroups> lights;
};
} // namespace mapc::lght::v4

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::lght::v4::PackMapLight &value) {
  reader(value.position);
  reader(value.color);
  reader(value.intensity);
  reader(value.near_distance);
  reader(value.far_distance);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader, mapc::lght::v4::PackMapCurve &value) {
  reader(value.gust);
  reader(value.gust_freq);
  reader(value.noise);
  reader(value.phase);
  reader(value.offset);
  reader(value.amplitude);
  reader(value.curve_type);
}

template <typename Reader>
void Read(Reader &reader, mapc::lght::v4::PackMapLightgroups &value) {
  reader(value.guid);
  reader(value.lights);
  reader(value.curves);
}

template <typename Reader>
void Read(Reader &reader, mapc::lght::v4::PackMapLights &value) {
  reader(value.lights);
}
} // namespace de

} // namespace pf

#endif
