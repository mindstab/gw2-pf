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

#if MAPC_ZON2_MIN_VERSION <= 12

#include "pf/types.hpp"

namespace pf {
namespace mapc::zon2::v12 {
struct PackMapZoneModelV13 {
  pf::filename filename;
  float probability;
  pf::dword flags;
};

struct PackMapZoneLayerDefV13 {
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
  std::vector<PackMapZoneModelV13> model_array;
  std::shared_ptr<PackMapZoneModelV13> sub_model;
};

struct PackMapZoneDefV13 {
  pf::filename def_filename;
  pf::dword token;
  std::vector<PackMapZoneLayerDefV13> layer_def_array;
  pf::qword time_stamp;
};

struct PackMapZoneEncodingDataV13 {
  pf::word index;
  pf::byte offset;
};

struct PackMapZoneCollideDataV13 {
  float normal_x;
  float normal_y;
  float z_pos;
};

struct PackMapZoneV13 {
  pf::dword zone_flags;
  pf::dword4 vert_rect;
  float water_height;
  pf::byte seed;
  pf::dword def_token;
  pf::float2 range;
  float z_pos;
  std::vector<pf::byte> flags;
  std::vector<PackMapZoneEncodingDataV13> encode_data;
  std::vector<PackMapZoneCollideDataV13> collide_data;
  std::vector<pf::word> offset_data;
  std::vector<pf::float2> vertices;
};

struct PackMapZonesV13 {
  std::vector<PackMapZoneDefV13> zone_def_array;
  std::vector<PackMapZoneV13> zone_array;
};
} // namespace mapc::zon2::v12

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::zon2::v12::PackMapZoneModelV13 &value) {
  reader(value.filename);
  reader(value.probability);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v12::PackMapZoneLayerDefV13 &value) {
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
void Read(Reader &reader, mapc::zon2::v12::PackMapZoneDefV13 &value) {
  reader(value.def_filename);
  reader(value.token);
  reader(value.layer_def_array);
  reader(value.time_stamp);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v12::PackMapZoneEncodingDataV13 &value) {
  reader(value.index);
  reader(value.offset);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v12::PackMapZoneCollideDataV13 &value) {
  reader(value.normal_x);
  reader(value.normal_y);
  reader(value.z_pos);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v12::PackMapZoneV13 &value) {
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
void Read(Reader &reader, mapc::zon2::v12::PackMapZonesV13 &value) {
  reader(value.zone_def_array);
  reader(value.zone_array);
}
} // namespace de

} // namespace pf

#endif
