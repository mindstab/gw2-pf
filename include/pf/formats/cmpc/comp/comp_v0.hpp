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

#if CMPC_COMP_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace cmpc::comp::v0 {
struct PackCompositeBlitRectSetV0 {
  pf::wstring name;
  pf::dword2 size;
  std::vector<pf::dword> rect_index;
  std::vector<pf::dword4> rect_array;
};

struct PackCompositeFileDataV0 {
  pf::qword name;
  pf::dword type;
  pf::filename mesh_base;
  pf::filename mesh_overlap;
  pf::filename mask_cloth_skin;
  pf::filename mask_leather;
  pf::filename mask_metal;
  pf::filename mask_glow;
  pf::filename texture_base;
  pf::filename texture_normal;
  pf::dword hide_flags;
  pf::dword skin_flags;
  pf::dword blit_rect_index;
};

struct PackCompositeSkinPatternV0 {
  pf::filename chest;
  pf::filename face;
  pf::filename feet;
  pf::filename hands;
  pf::filename legs;
};

struct PackCompositeColorV0 {
  pf::byte brightness;
  pf::byte contrast;
  pf::byte hue;
  pf::byte saturation;
  pf::byte lightness;
};

struct PackCompositeVariantComponentV0 {
  pf::qword name_token;
  PackCompositeColorV0 cloth_color;
  PackCompositeColorV0 leather_color;
  PackCompositeColorV0 metal_color;
};

struct PackCompositeVariantV0 {
  std::vector<PackCompositeVariantComponentV0> components;
  PackCompositeColorV0 hair_color;
  PackCompositeColorV0 pattern_color;
  PackCompositeColorV0 skin_color;
  pf::dword skin_index;
};

struct PackCompositeRaceDataV0 {
  pf::wstring name;
  pf::qword name_token;
  std::vector<pf::qword> ears;
  std::vector<pf::qword> faces;
  std::vector<PackCompositeFileDataV0> file_data;
  std::vector<pf::qword> hair_styles;
  pf::filename skeleton_file;
  std::vector<PackCompositeSkinPatternV0> skin_patterns;
  pf::dword type;
  pf::qword variant_ref_race;
  std::vector<PackCompositeVariantV0> variants;
};

struct PackCompositeV0 {
  std::vector<PackCompositeBlitRectSetV0> blit_rects;
  std::vector<PackCompositeRaceDataV0> race_sex_data;
};
} // namespace cmpc::comp::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, cmpc::comp::v0::PackCompositeBlitRectSetV0 &value) {
  reader(value.name);
  reader(value.size);
  reader(value.rect_index);
  reader(value.rect_array);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v0::PackCompositeFileDataV0 &value) {
  reader(value.name);
  reader(value.type);
  reader(value.mesh_base);
  reader(value.mesh_overlap);
  reader(value.mask_cloth_skin);
  reader(value.mask_leather);
  reader(value.mask_metal);
  reader(value.mask_glow);
  reader(value.texture_base);
  reader(value.texture_normal);
  reader(value.hide_flags);
  reader(value.skin_flags);
  reader(value.blit_rect_index);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v0::PackCompositeSkinPatternV0 &value) {
  reader(value.chest);
  reader(value.face);
  reader(value.feet);
  reader(value.hands);
  reader(value.legs);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v0::PackCompositeColorV0 &value) {
  reader(value.brightness);
  reader(value.contrast);
  reader(value.hue);
  reader(value.saturation);
  reader(value.lightness);
}

template <typename Reader>
void Read(Reader &reader,
          cmpc::comp::v0::PackCompositeVariantComponentV0 &value) {
  reader(value.name_token);
  reader(value.cloth_color);
  reader(value.leather_color);
  reader(value.metal_color);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v0::PackCompositeVariantV0 &value) {
  reader(value.components);
  reader(value.hair_color);
  reader(value.pattern_color);
  reader(value.skin_color);
  reader(value.skin_index);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v0::PackCompositeRaceDataV0 &value) {
  reader(value.name);
  reader(value.name_token);
  reader(value.ears);
  reader(value.faces);
  reader(value.file_data);
  reader(value.hair_styles);
  reader(value.skeleton_file);
  reader(value.skin_patterns);
  reader(value.type);
  reader(value.variant_ref_race);
  reader(value.variants);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v0::PackCompositeV0 &value) {
  reader(value.blit_rects);
  reader(value.race_sex_data);
}
} // namespace de

} // namespace pf

#endif
