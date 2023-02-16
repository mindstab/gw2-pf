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

#if MAPC_OCC_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace mapc::occ::v0 {
struct MapOcclusion {
  pf::dword token;
  pf::dword flags;
  std::vector<pf::float3> vertices;
  pf::wstring name;
};

struct MapOcclusions {
  std::vector<MapOcclusion> occlusions;
};
} // namespace mapc::occ::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::occ::v0::MapOcclusion &value) {
  reader(value.token);
  reader(value.flags);
  reader(value.vertices);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, mapc::occ::v0::MapOcclusions &value) {
  reader(value.occlusions);
}
} // namespace de

} // namespace pf

#endif
