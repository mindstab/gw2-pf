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

#if MAPC_DCAL_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace mapc::dcal::v1 {
struct PackMapDecalV1 {
  pf::float3 position;
  pf::float3 extents;
  pf::float3 rotation;
  pf::float2 texture_scale;
  pf::float2 texture_offset;
  pf::filename material_filename;
  std::vector<pf::filename> texture_filenames;
  pf::dword flags;
};

struct PackMapDecalsV1 {
  std::vector<PackMapDecalV1> decals;
};
} // namespace mapc::dcal::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::dcal::v1::PackMapDecalV1 &value) {
  reader(value.position);
  reader(value.extents);
  reader(value.rotation);
  reader(value.texture_scale);
  reader(value.texture_offset);
  reader(value.material_filename);
  reader(value.texture_filenames);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader, mapc::dcal::v1::PackMapDecalsV1 &value) {
  reader(value.decals);
}
} // namespace de

} // namespace pf

#endif
