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

#if MAPC_AREA_MIN_VERSION <= 2

#include "pf/types.hpp"

namespace pf {
namespace mapc::area::v2 {
struct PackMapAreaPolygonV2 {
  std::vector<pf::float3> points;
  float height;
};

struct PackMapAreaPortalV2 {
  pf::float3 position;
  pf::float3 extents;
  pf::float3 rotation;
};

struct PackMapAreaVolumeV2 {
  std::vector<PackMapAreaPortalV2> portals;
  pf::float3 position;
  pf::float3 extents;
  pf::float3 point_interior;
  pf::float3 point_exterior;
};

struct PackMapAreaV2 {
  pf::qword token;
  pf::byte type;
  pf::byte floor;
  pf::dword flags;
  PackMapAreaPolygonV2 polygon;
  PackMapAreaVolumeV2 volume;
};

struct PackMapAreaToolV2 {
  pf::wstring annotation;
};

struct PackMapAreasV2 {
  std::vector<PackMapAreaV2> areas;
  std::vector<PackMapAreaToolV2> area_tools;
};
} // namespace mapc::area::v2

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::area::v2::PackMapAreaPolygonV2 &value) {
  reader(value.points);
  reader(value.height);
}

template <typename Reader>
void Read(Reader &reader, mapc::area::v2::PackMapAreaPortalV2 &value) {
  reader(value.position);
  reader(value.extents);
  reader(value.rotation);
}

template <typename Reader>
void Read(Reader &reader, mapc::area::v2::PackMapAreaVolumeV2 &value) {
  reader(value.portals);
  reader(value.position);
  reader(value.extents);
  reader(value.point_interior);
  reader(value.point_exterior);
}

template <typename Reader>
void Read(Reader &reader, mapc::area::v2::PackMapAreaV2 &value) {
  reader(value.token);
  reader(value.type);
  reader(value.floor);
  reader(value.flags);
  reader(value.polygon);
  reader(value.volume);
}

template <typename Reader>
void Read(Reader &reader, mapc::area::v2::PackMapAreaToolV2 &value) {
  reader(value.annotation);
}

template <typename Reader>
void Read(Reader &reader, mapc::area::v2::PackMapAreasV2 &value) {
  reader(value.areas);
  reader(value.area_tools);
}
} // namespace de

} // namespace pf

#endif
