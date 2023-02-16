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

#if MAPC_RIVE_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace mapc::rive::v1 {
struct MapRiverTextureMap {
  float scale;
  float speed_x;
  float speed_y;
  float tiling;
  pf::byte uv_index;
};

struct MapRiverMaterial {
  pf::filename material_file;
  std::vector<pf::filename> texture_files;
  std::vector<pf::dword> constant_tokens;
  std::vector<pf::float4> constant_values;
  std::vector<MapRiverTextureMap> texture_maps;
};

struct MapRiverReach {
  float width;
  float curve_length;
  float curve_percent;
  pf::dword x_tessellation;
  pf::dword2 y_tessellation;
  pf::dword broad_id;
  std::vector<MapRiverMaterial> materials;
};

struct MapRiver {
  pf::qword guid;
  pf::wstring name;
  float x_tiling;
  std::vector<pf::float3> points;
  std::vector<MapRiverReach> reaches;
};

struct PackMapRivers {
  pf::dword flags;
  pf::dword next_broad_id;
  std::vector<MapRiver> rivers;
  PackBroadphaseType broad_phase;
};
} // namespace mapc::rive::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::rive::v1::MapRiverTextureMap &value) {
  reader(value.scale);
  reader(value.speed_x);
  reader(value.speed_y);
  reader(value.tiling);
  reader(value.uv_index);
}

template <typename Reader>
void Read(Reader &reader, mapc::rive::v1::MapRiverMaterial &value) {
  reader(value.material_file);
  reader(value.texture_files);
  reader(value.constant_tokens);
  reader(value.constant_values);
  reader(value.texture_maps);
}

template <typename Reader>
void Read(Reader &reader, mapc::rive::v1::MapRiverReach &value) {
  reader(value.width);
  reader(value.curve_length);
  reader(value.curve_percent);
  reader(value.x_tessellation);
  reader(value.y_tessellation);
  reader(value.broad_id);
  reader(value.materials);
}

template <typename Reader>
void Read(Reader &reader, mapc::rive::v1::MapRiver &value) {
  reader(value.guid);
  reader(value.name);
  reader(value.x_tiling);
  reader(value.points);
  reader(value.reaches);
}

template <typename Reader>
void Read(Reader &reader, mapc::rive::v1::PackMapRivers &value) {
  reader(value.flags);
  reader(value.next_broad_id);
  reader(value.rivers);
  reader(value.broad_phase);
}
} // namespace de

} // namespace pf

#endif
