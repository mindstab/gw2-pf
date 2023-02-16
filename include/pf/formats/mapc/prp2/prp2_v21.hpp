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

#if MAPC_PRP2_MIN_VERSION <= 21

#include "pf/types.hpp"

namespace pf {
namespace mapc::prp2::v21 {
struct PackMapPropConstantV18 {
  pf::dword token;
  pf::float4 constant;
  pf::dword submodel;
};

struct PackMapPropObjV21 {
  pf::filename filename;
  std::vector<pf::filename> blit_textures;
  std::vector<PackMapPropConstantV18> constants;
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
  pf::dword reserved;
  pf::word broad_id;
  pf::word bucket_id;
  pf::byte byte;
  pf::byte sort_layer;
};

struct PackMapPropObjAnimSeqV21 {
  pf::filename filename;
  std::vector<pf::filename> blit_textures;
  std::vector<PackMapPropConstantV18> constants;
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
  pf::dword reserved;
  pf::word broad_id;
  pf::word bucket_id;
  pf::byte byte;
  pf::byte sort_layer;
  pf::qword anim_sequence;
};

struct PackMapPropTransformV21 {
  pf::float3 position;
  pf::float3 rotation;
  float scale;
};

struct PackMapPropObjInstanceV21 {
  pf::filename filename;
  std::vector<pf::filename> blit_textures;
  std::vector<PackMapPropConstantV18> constants;
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
  pf::dword reserved;
  pf::word broad_id;
  pf::word bucket_id;
  pf::byte byte;
  pf::byte sort_layer;
  std::vector<PackMapPropTransformV21> transforms;
  std::vector<pf::qword> orig_guid_array;
};

struct PackMapPropObjToolV21 {
  pf::qword guid;
  pf::dword layer_mask;
  pf::byte glom_type;
  std::vector<pf::qword> children;
};

struct PackMapPropObjMetaV21 {
  pf::filename filename;
  std::vector<pf::filename> blit_textures;
  std::vector<PackMapPropConstantV18> constants;
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
  pf::dword reserved;
  pf::word broad_id;
  pf::word bucket_id;
  pf::byte byte;
  pf::byte sort_layer;
  pf::dword layer_mask;
  pf::byte glom_type;
  pf::qword parent;
  pf::float3 glom_origin;
};

struct PackMapPropObjVolumeV21 {
  pf::qword guid;
  pf::dword layer_mask;
  pf::byte glom_type;
  std::vector<pf::qword> children;
  pf::float3 glom_clip_scale;
  pf::float3 position;
  pf::float3 rotation;
  float scale;
};

struct PackMapPropV21 {
  std::vector<PackMapPropObjV21> prop_array;
  std::vector<PackMapPropObjAnimSeqV21> prop_anim_array;
  std::vector<PackMapPropObjInstanceV21> prop_instance_array;
  std::vector<PackMapPropObjToolV21> prop_tool_array;
  std::vector<PackMapPropObjMetaV21> prop_meta_array;
  std::vector<PackMapPropObjVolumeV21> prop_volume_array;
  pf::wstring reserved;
  PackBroadphaseType broad_phase;
  pf::dword next_broad_id;
};
} // namespace mapc::prp2::v21

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::prp2::v21::PackMapPropConstantV18 &value) {
  reader(value.token);
  reader(value.constant);
  reader(value.submodel);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v21::PackMapPropObjV21 &value) {
  reader(value.filename);
  reader(value.blit_textures);
  reader(value.constants);
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
  reader(value.reserved);
  reader(value.broad_id);
  reader(value.bucket_id);
  reader(value.byte);
  reader(value.sort_layer);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v21::PackMapPropObjAnimSeqV21 &value) {
  reader(value.filename);
  reader(value.blit_textures);
  reader(value.constants);
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
  reader(value.reserved);
  reader(value.broad_id);
  reader(value.bucket_id);
  reader(value.byte);
  reader(value.sort_layer);
  reader(value.anim_sequence);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v21::PackMapPropTransformV21 &value) {
  reader(value.position);
  reader(value.rotation);
  reader(value.scale);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v21::PackMapPropObjInstanceV21 &value) {
  reader(value.filename);
  reader(value.blit_textures);
  reader(value.constants);
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
  reader(value.reserved);
  reader(value.broad_id);
  reader(value.bucket_id);
  reader(value.byte);
  reader(value.sort_layer);
  reader(value.transforms);
  reader(value.orig_guid_array);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v21::PackMapPropObjToolV21 &value) {
  reader(value.guid);
  reader(value.layer_mask);
  reader(value.glom_type);
  reader(value.children);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v21::PackMapPropObjMetaV21 &value) {
  reader(value.filename);
  reader(value.blit_textures);
  reader(value.constants);
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
  reader(value.reserved);
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
void Read(Reader &reader, mapc::prp2::v21::PackMapPropObjVolumeV21 &value) {
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
void Read(Reader &reader, mapc::prp2::v21::PackMapPropV21 &value) {
  reader(value.prop_array);
  reader(value.prop_anim_array);
  reader(value.prop_instance_array);
  reader(value.prop_tool_array);
  reader(value.prop_meta_array);
  reader(value.prop_volume_array);
  reader(value.reserved);
  reader(value.broad_phase);
  reader(value.next_broad_id);
}
} // namespace de

} // namespace pf

#endif
