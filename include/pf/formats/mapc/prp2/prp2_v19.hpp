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

#if MAPC_PRP2_MIN_VERSION <= 19

#include "pf/types.hpp"

namespace pf {
namespace mapc::prp2::v19 {
struct PackMapPropObjV19 {
  pf::filename filename;
  std::vector<pf::filename> blit_textures;
  std::vector<pf::dword> const_tokens;
  std::vector<pf::float4> const_values;
  pf::qword guid;
  pf::qword permutation;
  pf::float4 bounds;
  pf::float3 position;
  pf::float3 rotation;
  pf::byte4 color;
  float scale;
  float lod1;
  float lod2;
  pf::dword flags;
  pf::word broad_id;
  pf::word bucket_id;
  pf::byte byte;
  pf::byte sort_layer;
};

struct PackMapPropObjAnimSeqV19 {
  pf::filename filename;
  std::vector<pf::filename> blit_textures;
  std::vector<pf::dword> const_tokens;
  std::vector<pf::float4> const_values;
  pf::qword guid;
  pf::qword permutation;
  pf::float4 bounds;
  pf::float3 position;
  pf::float3 rotation;
  pf::byte4 color;
  float scale;
  float lod1;
  float lod2;
  pf::dword flags;
  pf::word broad_id;
  pf::word bucket_id;
  pf::byte byte;
  pf::byte sort_layer;
  pf::qword anim_sequence;
};

struct PackMapPropTransformV19 {
  pf::float3 position;
  pf::float3 rotation;
  float scale;
};

struct PackMapPropObjInstanceV19 {
  pf::filename filename;
  std::vector<pf::filename> blit_textures;
  std::vector<pf::dword> const_tokens;
  std::vector<pf::float4> const_values;
  pf::qword guid;
  pf::qword permutation;
  pf::float4 bounds;
  pf::float3 position;
  pf::float3 rotation;
  pf::byte4 color;
  float scale;
  float lod1;
  float lod2;
  pf::dword flags;
  pf::word broad_id;
  pf::word bucket_id;
  pf::byte byte;
  pf::byte sort_layer;
  std::vector<PackMapPropTransformV19> transforms;
  std::vector<pf::qword> orig_guid_array;
};

struct PackMapPropObjToolV19 {
  pf::qword guid;
  pf::dword layer_mask;
  pf::byte glom_type;
  std::vector<pf::qword> children;
};

struct PackMapPropObjMetaV19 {
  pf::filename filename;
  std::vector<pf::filename> blit_textures;
  std::vector<pf::dword> const_tokens;
  std::vector<pf::float4> const_values;
  pf::qword guid;
  pf::qword permutation;
  pf::float4 bounds;
  pf::float3 position;
  pf::float3 rotation;
  pf::byte4 color;
  float scale;
  float lod1;
  float lod2;
  pf::dword flags;
  pf::word broad_id;
  pf::word bucket_id;
  pf::byte byte;
  pf::byte sort_layer;
  pf::dword layer_mask;
  pf::byte glom_type;
  pf::qword parent;
  pf::float3 glom_origin;
};

struct PackMapPropObjVolumeV19 {
  pf::qword guid;
  pf::dword layer_mask;
  pf::byte glom_type;
  std::vector<pf::qword> children;
  pf::float3 glom_clip_scale;
  pf::float3 position;
  pf::float3 rotation;
  float scale;
};

struct PackMapPropV19 {
  std::vector<PackMapPropObjV19> prop_array;
  std::vector<PackMapPropObjAnimSeqV19> prop_anim_array;
  std::vector<PackMapPropObjInstanceV19> prop_instance_array;
  std::vector<PackMapPropObjToolV19> prop_tool_array;
  std::vector<PackMapPropObjMetaV19> prop_meta_array;
  std::vector<PackMapPropObjVolumeV19> prop_volume_array;
  PackBroadphaseType broad_phase;
  pf::dword next_broad_id;
};
} // namespace mapc::prp2::v19

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::prp2::v19::PackMapPropObjV19 &value) {
  reader(value.filename);
  reader(value.blit_textures);
  reader(value.const_tokens);
  reader(value.const_values);
  reader(value.guid);
  reader(value.permutation);
  reader(value.bounds);
  reader(value.position);
  reader(value.rotation);
  reader(value.color);
  reader(value.scale);
  reader(value.lod1);
  reader(value.lod2);
  reader(value.flags);
  reader(value.broad_id);
  reader(value.bucket_id);
  reader(value.byte);
  reader(value.sort_layer);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v19::PackMapPropObjAnimSeqV19 &value) {
  reader(value.filename);
  reader(value.blit_textures);
  reader(value.const_tokens);
  reader(value.const_values);
  reader(value.guid);
  reader(value.permutation);
  reader(value.bounds);
  reader(value.position);
  reader(value.rotation);
  reader(value.color);
  reader(value.scale);
  reader(value.lod1);
  reader(value.lod2);
  reader(value.flags);
  reader(value.broad_id);
  reader(value.bucket_id);
  reader(value.byte);
  reader(value.sort_layer);
  reader(value.anim_sequence);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v19::PackMapPropTransformV19 &value) {
  reader(value.position);
  reader(value.rotation);
  reader(value.scale);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v19::PackMapPropObjInstanceV19 &value) {
  reader(value.filename);
  reader(value.blit_textures);
  reader(value.const_tokens);
  reader(value.const_values);
  reader(value.guid);
  reader(value.permutation);
  reader(value.bounds);
  reader(value.position);
  reader(value.rotation);
  reader(value.color);
  reader(value.scale);
  reader(value.lod1);
  reader(value.lod2);
  reader(value.flags);
  reader(value.broad_id);
  reader(value.bucket_id);
  reader(value.byte);
  reader(value.sort_layer);
  reader(value.transforms);
  reader(value.orig_guid_array);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v19::PackMapPropObjToolV19 &value) {
  reader(value.guid);
  reader(value.layer_mask);
  reader(value.glom_type);
  reader(value.children);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v19::PackMapPropObjMetaV19 &value) {
  reader(value.filename);
  reader(value.blit_textures);
  reader(value.const_tokens);
  reader(value.const_values);
  reader(value.guid);
  reader(value.permutation);
  reader(value.bounds);
  reader(value.position);
  reader(value.rotation);
  reader(value.color);
  reader(value.scale);
  reader(value.lod1);
  reader(value.lod2);
  reader(value.flags);
  reader(value.broad_id);
  reader(value.bucket_id);
  reader(value.byte);
  reader(value.sort_layer);
  reader(value.layer_mask);
  reader(value.glom_type);
  reader(value.parent);
  reader(value.glom_origin);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v19::PackMapPropObjVolumeV19 &value) {
  reader(value.guid);
  reader(value.layer_mask);
  reader(value.glom_type);
  reader(value.children);
  reader(value.glom_clip_scale);
  reader(value.position);
  reader(value.rotation);
  reader(value.scale);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v19::PackMapPropV19 &value) {
  reader(value.prop_array);
  reader(value.prop_anim_array);
  reader(value.prop_instance_array);
  reader(value.prop_tool_array);
  reader(value.prop_meta_array);
  reader(value.prop_volume_array);
  reader(value.broad_phase);
  reader(value.next_broad_id);
}
} // namespace de

} // namespace pf

#endif
