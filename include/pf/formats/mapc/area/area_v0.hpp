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

#if MAPC_AREA_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace mapc::area::v0 {
struct PackMapAreaV0 {
  pf::float3 min;
  pf::float3 max;
  pf::float3 internal;
  pf::float3 external;
  pf::dword token;
  pf::dword flags;
};

struct PackMapPortalV0 {
  std::vector<pf::float3> portal_verts;
};

struct PackMapAreasV0 {
  std::vector<PackMapAreaV0> areas;
  std::vector<PackMapPortalV0> portals;
};
} // namespace mapc::area::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::area::v0::PackMapAreaV0 &value) {
  reader(value.min);
  reader(value.max);
  reader(value.internal);
  reader(value.external);
  reader(value.token);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader, mapc::area::v0::PackMapPortalV0 &value) {
  reader(value.portal_verts);
}

template <typename Reader>
void Read(Reader &reader, mapc::area::v0::PackMapAreasV0 &value) {
  reader(value.areas);
  reader(value.portals);
}
} // namespace de

} // namespace pf

#endif
