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

#if MAPC_SURF_MIN_VERSION <= 2

#include "pf/types.hpp"

namespace pf {
namespace mapc::surf::v2 {
struct MapSurfaceAttribute {
  pf::qword id;
  pf::qword sound;
  pf::dword flags;
};

struct MapSurfaceAttributeTool {
  pf::wstring name;
  pf::wstring category;
  pf::byte4 color;
};

struct MapSurfaceOverride {
  pf::qword surface_id;
  std::vector<pf::dword> bit_array;
};

struct MapSurfaceTerrainOverride {
  pf::dword2 chunk_coord;
  std::vector<MapSurfaceOverride> override_array;
};

struct MapSurfacePropOverride {
  pf::qword prop_id;
  std::vector<MapSurfaceOverride> override_array;
};

struct MapSurfaces {
  std::vector<MapSurfaceAttribute> attribute_data;
  std::vector<MapSurfaceAttributeTool> tool_data;
  std::vector<MapSurfaceTerrainOverride> terrain_array;
  std::vector<MapSurfacePropOverride> prop_array;
};
} // namespace mapc::surf::v2

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::surf::v2::MapSurfaceAttribute &value) {
  reader(value.id);
  reader(value.sound);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader, mapc::surf::v2::MapSurfaceAttributeTool &value) {
  reader(value.name);
  reader(value.category);
  reader(value.color);
}

template <typename Reader>
void Read(Reader &reader, mapc::surf::v2::MapSurfaceOverride &value) {
  reader(value.surface_id);
  reader(value.bit_array);
}

template <typename Reader>
void Read(Reader &reader, mapc::surf::v2::MapSurfaceTerrainOverride &value) {
  reader(value.chunk_coord);
  reader(value.override_array);
}

template <typename Reader>
void Read(Reader &reader, mapc::surf::v2::MapSurfacePropOverride &value) {
  reader(value.prop_id);
  reader(value.override_array);
}

template <typename Reader>
void Read(Reader &reader, mapc::surf::v2::MapSurfaces &value) {
  reader(value.attribute_data);
  reader(value.tool_data);
  reader(value.terrain_array);
  reader(value.prop_array);
}
} // namespace de

} // namespace pf

#endif
