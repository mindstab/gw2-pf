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

#if CDHS_CDHS_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace CDHS::CDHS::v1 {
struct PackVsGenParams {
  pf::byte point_wind_count;
  pf::byte light_point_count;
  pf::byte light_spot_count;
  pf::byte tex_trans_count;
  pf::byte haze_mode;
  pf::word flags;
};

struct PackVertexShaderKey {
  PackVsGenParams vs_gen_params;
  pf::dword vertex_format;
  pf::dword tex_gen_count;
  std::array<pf::dword, 14> tex_gen;
  pf::dword vs_version;
};

struct PackShaderCache {
  std::vector<PackVertexShaderKey> data;
};
} // namespace CDHS::CDHS::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, CDHS::CDHS::v1::PackVsGenParams &value) {
  reader(value.point_wind_count);
  reader(value.light_point_count);
  reader(value.light_spot_count);
  reader(value.tex_trans_count);
  reader(value.haze_mode);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader, CDHS::CDHS::v1::PackVertexShaderKey &value) {
  reader(value.vs_gen_params);
  reader(value.vertex_format);
  reader(value.tex_gen_count);
  reader(value.tex_gen);
  reader(value.vs_version);
}

template <typename Reader>
void Read(Reader &reader, CDHS::CDHS::v1::PackShaderCache &value) {
  reader(value.data);
}
} // namespace de

} // namespace pf

#endif
