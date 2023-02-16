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

#if MAPC_RIVE_MIN_VERSION <= 5

#include "pf/types.hpp"

namespace pf {
namespace mapc::rive::v5 {
struct PackMapRiverProperty {
  pf::dword type;
  pf::qword val;
  pf::filename str_val;
};

struct MapRiverReach {
  std::vector<PackMapRiverProperty> properties;
};

struct MapRiver {
  pf::qword guid;
  pf::wstring name;
  std::vector<PackMapRiverProperty> properties;
  std::vector<pf::float3> points;
  std::vector<MapRiverReach> reaches;
};

struct PackMapRivers {
  std::vector<MapRiver> rivers;
};
} // namespace mapc::rive::v5

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::rive::v5::PackMapRiverProperty &value) {
  reader(value.type);
  reader(value.val);
  reader(value.str_val);
}

template <typename Reader>
void Read(Reader &reader, mapc::rive::v5::MapRiverReach &value) {
  reader(value.properties);
}

template <typename Reader>
void Read(Reader &reader, mapc::rive::v5::MapRiver &value) {
  reader(value.guid);
  reader(value.name);
  reader(value.properties);
  reader(value.points);
  reader(value.reaches);
}

template <typename Reader>
void Read(Reader &reader, mapc::rive::v5::PackMapRivers &value) {
  reader(value.rivers);
}
} // namespace de

} // namespace pf

#endif
