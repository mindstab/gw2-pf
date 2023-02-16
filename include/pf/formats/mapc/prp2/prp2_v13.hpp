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

#if MAPC_PRP2_MIN_VERSION <= 13

#include "pf/types.hpp"

namespace pf {
namespace mapc::prp2::v13 {
struct PackMapPropObjV13 {
  pf::filename filename;
  std::vector<pf::filename> blit_textures;
  pf::qword guid;
  pf::float3 position;
  pf::float3 rotation;
  pf::byte4 color;
  float scale;
  float lod1;
  float lod2;
  pf::dword flags;
  pf::word broad_id;
  pf::byte byte;
};

struct PackMapPropObjAnimSeqV13 {
  pf::filename filename;
  std::vector<pf::filename> blit_textures;
  pf::qword guid;
  pf::float3 position;
  pf::float3 rotation;
  pf::byte4 color;
  float scale;
  float lod1;
  float lod2;
  pf::dword flags;
  pf::word broad_id;
  pf::byte byte;
  pf::qword anim_sequence;
};

struct PackMapPropObjToolV13 {
  pf::qword guid;
  pf::dword layer_mask;
  pf::byte glom_type;
  std::vector<pf::qword> children;
};

struct PackMapPropObjMetaV13 {
  pf::filename filename;
  std::vector<pf::filename> blit_textures;
  pf::qword guid;
  pf::float3 position;
  pf::float3 rotation;
  pf::byte4 color;
  float scale;
  float lod1;
  float lod2;
  pf::dword flags;
  pf::word broad_id;
  pf::byte byte;
  pf::dword layer_mask;
  pf::byte glom_type;
  pf::qword parent;
  pf::float3 glom_origin;
};

struct PackMapPropObjVolumeV13 {
  pf::qword guid;
  pf::dword layer_mask;
  pf::byte glom_type;
  std::vector<pf::qword> children;
  pf::float3 glom_clip_scale;
  pf::float3 position;
  pf::float3 rotation;
  float scale;
};

struct PackMapPropV13 {
  std::vector<PackMapPropObjV13> prop_array;
  std::vector<PackMapPropObjAnimSeqV13> prop_anim_array;
  std::vector<PackMapPropObjToolV13> prop_tool_array;
  std::vector<PackMapPropObjMetaV13> prop_meta_array;
  std::vector<PackMapPropObjVolumeV13> prop_volume_array;
  PackBroadphaseType broad_phase;
  pf::dword next_broad_id;
};
} // namespace mapc::prp2::v13

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::prp2::v13::PackMapPropObjV13 &value) {
  reader(value.filename);
  reader(value.blit_textures);
  reader(value.guid);
  reader(value.position);
  reader(value.rotation);
  reader(value.color);
  reader(value.scale);
  reader(value.lod1);
  reader(value.lod2);
  reader(value.flags);
  reader(value.broad_id);
  reader(value.byte);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v13::PackMapPropObjAnimSeqV13 &value) {
  reader(value.filename);
  reader(value.blit_textures);
  reader(value.guid);
  reader(value.position);
  reader(value.rotation);
  reader(value.color);
  reader(value.scale);
  reader(value.lod1);
  reader(value.lod2);
  reader(value.flags);
  reader(value.broad_id);
  reader(value.byte);
  reader(value.anim_sequence);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v13::PackMapPropObjToolV13 &value) {
  reader(value.guid);
  reader(value.layer_mask);
  reader(value.glom_type);
  reader(value.children);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v13::PackMapPropObjMetaV13 &value) {
  reader(value.filename);
  reader(value.blit_textures);
  reader(value.guid);
  reader(value.position);
  reader(value.rotation);
  reader(value.color);
  reader(value.scale);
  reader(value.lod1);
  reader(value.lod2);
  reader(value.flags);
  reader(value.broad_id);
  reader(value.byte);
  reader(value.layer_mask);
  reader(value.glom_type);
  reader(value.parent);
  reader(value.glom_origin);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v13::PackMapPropObjVolumeV13 &value) {
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
void Read(Reader &reader, mapc::prp2::v13::PackMapPropV13 &value) {
  reader(value.prop_array);
  reader(value.prop_anim_array);
  reader(value.prop_tool_array);
  reader(value.prop_meta_array);
  reader(value.prop_volume_array);
  reader(value.broad_phase);
  reader(value.next_broad_id);
}
} // namespace de

} // namespace pf

#endif
