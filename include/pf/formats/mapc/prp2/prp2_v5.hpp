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

#if MAPC_PRP2_MIN_VERSION <= 5

#include "pf/types.hpp"

namespace pf {
namespace mapc::prp2::v5 {
struct PackMapPropObjV5 {
  pf::filename filename;
  pf::qword guid;
  pf::float3 position;
  pf::float3 rotation;
  float scale;
  pf::word lod1;
  pf::word lod2;
  pf::dword flags;
  pf::byte byte;
};

struct PackMapPropObjAnimSeqV5 {
  pf::filename filename;
  pf::qword guid;
  pf::float3 position;
  pf::float3 rotation;
  float scale;
  pf::word lod1;
  pf::word lod2;
  pf::dword flags;
  pf::byte byte;
  pf::qword anim_sequence;
};

struct PackMapPropObjToolV5 {
  pf::qword guid;
  pf::dword layer_mask;
  pf::float3 glom_origin;
  pf::float3 glom_clip_scale;
  pf::qword glom_target_id;
  pf::byte glom_type;
};

struct PackMapPropV5 {
  std::vector<PackMapPropObjV5> prop_array;
  std::vector<PackMapPropObjAnimSeqV5> prop_anim_array;
  std::vector<PackMapPropObjToolV5> prop_tool_array;
};
} // namespace mapc::prp2::v5

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::prp2::v5::PackMapPropObjV5 &value) {
  reader(value.filename);
  reader(value.guid);
  reader(value.position);
  reader(value.rotation);
  reader(value.scale);
  reader(value.lod1);
  reader(value.lod2);
  reader(value.flags);
  reader(value.byte);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v5::PackMapPropObjAnimSeqV5 &value) {
  reader(value.filename);
  reader(value.guid);
  reader(value.position);
  reader(value.rotation);
  reader(value.scale);
  reader(value.lod1);
  reader(value.lod2);
  reader(value.flags);
  reader(value.byte);
  reader(value.anim_sequence);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v5::PackMapPropObjToolV5 &value) {
  reader(value.guid);
  reader(value.layer_mask);
  reader(value.glom_origin);
  reader(value.glom_clip_scale);
  reader(value.glom_target_id);
  reader(value.glom_type);
}

template <typename Reader>
void Read(Reader &reader, mapc::prp2::v5::PackMapPropV5 &value) {
  reader(value.prop_array);
  reader(value.prop_anim_array);
  reader(value.prop_tool_array);
}
} // namespace de

} // namespace pf

#endif
