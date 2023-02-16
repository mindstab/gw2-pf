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

#if MAPC_DCAL_MIN_VERSION <= 10

#include "pf/types.hpp"

namespace pf {
namespace mapc::dcal::v10 {
struct PackMapDecalVertexV9 {
  pf::float3 position;
  pf::float3 normal;
  pf::float3 tangent;
  pf::float3 bitangent;
};

struct PackMapDecalV10 {
  pf::float3 position;
  pf::float3 extents;
  pf::float3 rotation;
  pf::float2 texture_scale_uv0;
  pf::float2 texture_offset_uv0;
  pf::float2 texture_scale_uv1;
  pf::float2 texture_offset_uv1;
  pf::float2 grid_size;
  pf::filename material_filename;
  std::vector<pf::filename> texture_filenames;
  pf::dword flags;
  pf::float2 anim_translation;
  pf::float2 anim_scale_range_x;
  pf::float2 anim_scale_range_y;
  pf::float2 anim_scale_speed;
  float anim_rotation;
  float surface_bias;
  std::vector<pf::dword> constant_tokens;
  std::vector<pf::float4> constant_values;
  std::vector<PackMapDecalVertexV9> vertices;
  std::vector<pf::word> indices;
  std::vector<pf::qword> prop_ids;
  pf::byte projection;
  pf::qword surface_id;
  pf::qword id;
};

struct PackMapDecalsV10 {
  std::vector<PackMapDecalV10> decals;
};
} // namespace mapc::dcal::v10

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::dcal::v10::PackMapDecalVertexV9 &value) {
  reader(value.position);
  reader(value.normal);
  reader(value.tangent);
  reader(value.bitangent);
}

template <typename Reader>
void Read(Reader &reader, mapc::dcal::v10::PackMapDecalV10 &value) {
  reader(value.position);
  reader(value.extents);
  reader(value.rotation);
  reader(value.texture_scale_uv0);
  reader(value.texture_offset_uv0);
  reader(value.texture_scale_uv1);
  reader(value.texture_offset_uv1);
  reader(value.grid_size);
  reader(value.material_filename);
  reader(value.texture_filenames);
  reader(value.flags);
  reader(value.anim_translation);
  reader(value.anim_scale_range_x);
  reader(value.anim_scale_range_y);
  reader(value.anim_scale_speed);
  reader(value.anim_rotation);
  reader(value.surface_bias);
  reader(value.constant_tokens);
  reader(value.constant_values);
  reader(value.vertices);
  reader(value.indices);
  reader(value.prop_ids);
  reader(value.projection);
  reader(value.surface_id);
  reader(value.id);
}

template <typename Reader>
void Read(Reader &reader, mapc::dcal::v10::PackMapDecalsV10 &value) {
  reader(value.decals);
}
} // namespace de

} // namespace pf

#endif
