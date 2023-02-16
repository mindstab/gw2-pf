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

#if MAPC_ZON2_MIN_VERSION <= 13

#include "pf/types.hpp"

namespace pf {
namespace mapc::zon2::v13 {
struct PackMapZoneModelV14 {
  pf::filename filename;
  float probability;
  pf::dword flags;
};

struct PackMapZoneLayerDefV14 {
  pf::byte type;
  pf::byte height;
  pf::byte width;
  pf::byte radius_ground;
  pf::byte sort_group;
  pf::byte tiling;
  pf::float2 scale_range;
  float probability;
  pf::float2 fade_range;
  std::array<pf::float2, 3> rot_range;
  pf::byte noise;
  pf::dword layer_flags;
  std::vector<PackMapZoneModelV14> model_array;
  std::shared_ptr<PackMapZoneModelV14> sub_model;
};

struct PackMapZonePageV2 {
  std::vector<pf::byte> flags;
  pf::dword2 chunk_coord;
  pf::byte seed;
  std::vector<pf::dword> paint_flags;
};

struct PackMapZonePageTableV2 {
  std::vector<PackMapZonePageV2> page_array;
  pf::dword flags;
};

struct PackMapZoneDefV14 {
  pf::filename def_filename;
  pf::dword token;
  std::vector<PackMapZoneLayerDefV14> layer_def_array;
  pf::qword time_stamp;
  std::shared_ptr<PackMapZonePageTableV2> page_table;
};

struct PackMapZoneEncodingDataV14 {
  pf::word index;
  pf::byte offset;
};

struct PackMapZoneCollideDataV14 {
  float normal_x;
  float normal_y;
  float z_pos;
};

struct PackMapZoneV14 {
  pf::dword zone_flags;
  pf::dword4 vert_rect;
  float water_height;
  pf::byte seed;
  pf::dword def_token;
  pf::float2 range;
  float z_pos;
  std::vector<pf::byte> flags;
  std::vector<PackMapZoneEncodingDataV14> encode_data;
  std::vector<PackMapZoneCollideDataV14> collide_data;
  std::vector<pf::word> offset_data;
  std::vector<pf::float2> vertices;
};

struct PackMapZonesV14 {
  std::vector<PackMapZoneDefV14> zone_def_array;
  std::vector<PackMapZoneV14> zone_array;
};
} // namespace mapc::zon2::v13

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::zon2::v13::PackMapZoneModelV14 &value) {
  reader(value.filename);
  reader(value.probability);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v13::PackMapZoneLayerDefV14 &value) {
  reader(value.type);
  reader(value.height);
  reader(value.width);
  reader(value.radius_ground);
  reader(value.sort_group);
  reader(value.tiling);
  reader(value.scale_range);
  reader(value.probability);
  reader(value.fade_range);
  reader(value.rot_range);
  reader(value.noise);
  reader(value.layer_flags);
  reader(value.model_array);
  reader(value.sub_model);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v13::PackMapZonePageV2 &value) {
  reader(value.flags);
  reader(value.chunk_coord);
  reader(value.seed);
  reader(value.paint_flags);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v13::PackMapZonePageTableV2 &value) {
  reader(value.page_array);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v13::PackMapZoneDefV14 &value) {
  reader(value.def_filename);
  reader(value.token);
  reader(value.layer_def_array);
  reader(value.time_stamp);
  reader(value.page_table);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v13::PackMapZoneEncodingDataV14 &value) {
  reader(value.index);
  reader(value.offset);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v13::PackMapZoneCollideDataV14 &value) {
  reader(value.normal_x);
  reader(value.normal_y);
  reader(value.z_pos);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v13::PackMapZoneV14 &value) {
  reader(value.zone_flags);
  reader(value.vert_rect);
  reader(value.water_height);
  reader(value.seed);
  reader(value.def_token);
  reader(value.range);
  reader(value.z_pos);
  reader(value.flags);
  reader(value.encode_data);
  reader(value.collide_data);
  reader(value.offset_data);
  reader(value.vertices);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v13::PackMapZonesV14 &value) {
  reader(value.zone_def_array);
  reader(value.zone_array);
}
} // namespace de

} // namespace pf

#endif
