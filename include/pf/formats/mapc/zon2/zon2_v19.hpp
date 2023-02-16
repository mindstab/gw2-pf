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

#if MAPC_ZON2_MIN_VERSION <= 19

#include "pf/types.hpp"

namespace pf {
namespace mapc::zon2::v19 {
struct PackMapZoneModelV20 {
  pf::filename filename;
  float probability;
  pf::dword flags;
  pf::float3 hsl_offset;
  std::array<pf::byte, 2> z_offsets;
};

struct PackMapZoneLayerDefV20 {
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
  std::array<pf::float2, 3> hsl_ranges;
  float instance_scale_jitter;
  pf::byte noise;
  pf::dword layer_flags;
  pf::filename materialname;
  std::vector<PackMapZoneModelV20> model_array;
  std::shared_ptr<PackMapZoneModelV20> sub_model;
};

struct PackMapZonePageV8 {
  std::vector<pf::byte> flags;
  pf::dword2 chunk_coord;
  pf::byte seed;
  std::vector<pf::dword> paint_flags;
};

struct PackMapZonePageTableV8 {
  std::vector<PackMapZonePageV8> page_array;
  pf::dword flags;
};

struct PackMapZoneDefV20 {
  pf::filename def_filename;
  pf::dword token;
  std::vector<PackMapZoneLayerDefV20> layer_def_array;
  pf::qword time_stamp;
  std::shared_ptr<PackMapZonePageTableV8> page_table;
};

struct PackMapZoneEncodingDataV20 {
  pf::word index;
  pf::byte offset;
};

struct PackMapZoneCollideDataV20 {
  float normal_x;
  float normal_y;
  float z_pos;
};

struct PackMapZoneV20 {
  pf::dword zone_flags;
  pf::dword4 vert_rect;
  float water_height;
  pf::byte seed;
  pf::dword def_token;
  pf::float2 range;
  float z_pos;
  std::vector<pf::byte> flags;
  std::vector<PackMapZoneEncodingDataV20> encode_data;
  std::vector<PackMapZoneCollideDataV20> collide_data;
  std::vector<pf::word> offset_data;
  std::vector<pf::float2> vertices;
  pf::word broad_id;
};

struct PackMapZonesV20 {
  std::vector<PackMapZoneDefV20> zone_def_array;
  std::vector<PackMapZoneV20> zone_array;
  PackBroadphaseType broad_phase;
  pf::word max_broad_id;
};
} // namespace mapc::zon2::v19

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::zon2::v19::PackMapZoneModelV20 &value) {
  reader(value.filename);
  reader(value.probability);
  reader(value.flags);
  reader(value.hsl_offset);
  reader(value.z_offsets);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v19::PackMapZoneLayerDefV20 &value) {
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
  reader(value.hsl_ranges);
  reader(value.instance_scale_jitter);
  reader(value.noise);
  reader(value.layer_flags);
  reader(value.materialname);
  reader(value.model_array);
  reader(value.sub_model);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v19::PackMapZonePageV8 &value) {
  reader(value.flags);
  reader(value.chunk_coord);
  reader(value.seed);
  reader(value.paint_flags);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v19::PackMapZonePageTableV8 &value) {
  reader(value.page_array);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v19::PackMapZoneDefV20 &value) {
  reader(value.def_filename);
  reader(value.token);
  reader(value.layer_def_array);
  reader(value.time_stamp);
  reader(value.page_table);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v19::PackMapZoneEncodingDataV20 &value) {
  reader(value.index);
  reader(value.offset);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v19::PackMapZoneCollideDataV20 &value) {
  reader(value.normal_x);
  reader(value.normal_y);
  reader(value.z_pos);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v19::PackMapZoneV20 &value) {
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
  reader(value.broad_id);
}

template <typename Reader>
void Read(Reader &reader, mapc::zon2::v19::PackMapZonesV20 &value) {
  reader(value.zone_def_array);
  reader(value.zone_array);
  reader(value.broad_phase);
  reader(value.max_broad_id);
}
} // namespace de

} // namespace pf

#endif
