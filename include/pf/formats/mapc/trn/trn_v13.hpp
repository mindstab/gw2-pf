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

#if MAPC_TRN_MIN_VERSION <= 13

#include "pf/types.hpp"

namespace pf {
namespace mapc::trn::v13 {
struct PackMapTerrainChunkV13 {
  pf::dword chunk_flags;
  std::vector<pf::byte> tile_table_array;
};

struct PackMapTerrainConstV13 {
  pf::dword token_name;
  pf::float4 value;
};

struct PackMapTerrainTexV13 {
  pf::dword token_name;
  pf::dword flags;
  pf::filename filename;
  pf::dword2 flags2;
  pf::dword layer;
};

struct PackMapTerrainMaterialV13 {
  pf::filename material_file;
  pf::dword fvf;
  std::vector<pf::dword> const_index_array;
  std::vector<pf::dword> tex_index_array;
};

struct PackMapTerrainChunkUVDataV13 {
  pf::float2 translation;
  pf::float2 x_scale_range;
  pf::float2 y_scale_range;
  pf::float2 scale_speed;
  float rotation;
};

struct PackMapTerrrainChunkMaterialV13 {
  std::array<pf::byte, 3> tiling;
  PackMapTerrainMaterialV13 hi_res_material;
  PackMapTerrainMaterialV13 lo_res_material;
  PackMapTerrainMaterialV13 fader_material;
  std::shared_ptr<PackMapTerrainChunkUVDataV13> uv_data;
};

struct PackMapTerrainMaterialsV13 {
  pf::filename paged_image;
  std::vector<PackMapTerrainConstV13> const_array;
  std::vector<PackMapTerrainTexV13> tex_file_array;
  std::vector<PackMapTerrrainChunkMaterialV13> materials;
  pf::float2 mid_fade;
  pf::float2 far_fade;
};

struct PackMapTerrainV13 {
  pf::dword2 dims;
  float swap_distance;
  std::vector<float> height_map_array;
  std::vector<pf::dword> tile_flag_array;
  std::vector<PackMapTerrainChunkV13> chunk_array;
  std::shared_ptr<PackMapTerrainMaterialsV13> materials;
  std::vector<pf::qword> type_array;
};
} // namespace mapc::trn::v13

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::trn::v13::PackMapTerrainChunkV13 &value) {
  reader(value.chunk_flags);
  reader(value.tile_table_array);
}

template <typename Reader>
void Read(Reader &reader, mapc::trn::v13::PackMapTerrainConstV13 &value) {
  reader(value.token_name);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, mapc::trn::v13::PackMapTerrainTexV13 &value) {
  reader(value.token_name);
  reader(value.flags);
  reader(value.filename);
  reader(value.flags2);
  reader(value.layer);
}

template <typename Reader>
void Read(Reader &reader, mapc::trn::v13::PackMapTerrainMaterialV13 &value) {
  reader(value.material_file);
  reader(value.fvf);
  reader(value.const_index_array);
  reader(value.tex_index_array);
}

template <typename Reader>
void Read(Reader &reader, mapc::trn::v13::PackMapTerrainChunkUVDataV13 &value) {
  reader(value.translation);
  reader(value.x_scale_range);
  reader(value.y_scale_range);
  reader(value.scale_speed);
  reader(value.rotation);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::trn::v13::PackMapTerrrainChunkMaterialV13 &value) {
  reader(value.tiling);
  reader(value.hi_res_material);
  reader(value.lo_res_material);
  reader(value.fader_material);
  reader(value.uv_data);
}

template <typename Reader>
void Read(Reader &reader, mapc::trn::v13::PackMapTerrainMaterialsV13 &value) {
  reader(value.paged_image);
  reader(value.const_array);
  reader(value.tex_file_array);
  reader(value.materials);
  reader(value.mid_fade);
  reader(value.far_fade);
}

template <typename Reader>
void Read(Reader &reader, mapc::trn::v13::PackMapTerrainV13 &value) {
  reader(value.dims);
  reader(value.swap_distance);
  reader(value.height_map_array);
  reader(value.tile_flag_array);
  reader(value.chunk_array);
  reader(value.materials);
  reader(value.type_array);
}
} // namespace de

} // namespace pf

#endif
