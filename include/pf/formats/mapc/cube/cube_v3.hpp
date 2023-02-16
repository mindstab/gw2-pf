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

#if MAPC_CUBE_MIN_VERSION <= 3

#include "pf/types.hpp"

namespace pf {
namespace mapc::cube::v3 {
struct PackMapCubeMapSampleV3 {
  pf::float3 position;
  pf::filename filename_day_default;
  pf::filename filename_night_default;
  pf::filename filename_day_script;
  pf::filename filename_night_script;
  pf::qword env_id;
};

struct PackMapCubeMapParamsV3 {
  pf::dword modulate_color;
  float brightness;
  float contrast;
  pf::dword blur_passes;
  pf::wstring env_volume;
};

struct PackMapCubeMapV3 {
  std::vector<PackMapCubeMapSampleV3> sample_array;
  std::vector<PackMapCubeMapParamsV3> params_array;
};
} // namespace mapc::cube::v3

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::cube::v3::PackMapCubeMapSampleV3 &value) {
  reader(value.position);
  reader(value.filename_day_default);
  reader(value.filename_night_default);
  reader(value.filename_day_script);
  reader(value.filename_night_script);
  reader(value.env_id);
}

template <typename Reader>
void Read(Reader &reader, mapc::cube::v3::PackMapCubeMapParamsV3 &value) {
  reader(value.modulate_color);
  reader(value.brightness);
  reader(value.contrast);
  reader(value.blur_passes);
  reader(value.env_volume);
}

template <typename Reader>
void Read(Reader &reader, mapc::cube::v3::PackMapCubeMapV3 &value) {
  reader(value.sample_array);
  reader(value.params_array);
}
} // namespace de

} // namespace pf

#endif
