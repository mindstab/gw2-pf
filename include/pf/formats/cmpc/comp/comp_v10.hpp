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

#if CMPC_COMP_MIN_VERSION <= 10

#include "pf/types.hpp"

namespace pf {
namespace cmpc::comp::v10 {
struct PackCompositeBlitRectSetV10 {
  pf::wstring name;
  pf::dword2 size;
  std::vector<pf::byte> rect_index;
  std::vector<pf::dword4> rect_array;
};

struct PackCompositeFileDataV10 {
  pf::qword name;
  pf::dword type;
  pf::filename mesh_base;
  pf::filename mesh_overlap;
  pf::filename mask_dye1;
  pf::filename mask_dye2;
  pf::filename mask_dye3;
  pf::filename mask_dye4;
  pf::filename mask_cut;
  pf::filename texture_base;
  pf::filename texture_normal;
  pf::dword dye_flags;
  pf::dword hide_flags;
  pf::dword skin_flags;
  pf::dword blit_rect_index;
};

struct PackCompositeSkinPatternV10 {
  pf::filename chest;
  pf::filename face;
  pf::filename feet;
  pf::filename hands;
  pf::filename legs;
  pf::filename ears;
};

struct PackCompositeColorV10 {
  pf::byte brightness;
  pf::byte contrast;
  pf::byte hue;
  pf::byte saturation;
  pf::byte lightness;
};

struct PackCompositeVariantComponentV10 {
  pf::qword name_token;
  PackCompositeColorV10 color0;
  PackCompositeColorV10 color1;
  PackCompositeColorV10 color2;
  PackCompositeColorV10 color3;
};

struct PackCompositeVariantV10 {
  pf::qword token;
  std::vector<PackCompositeVariantComponentV10> components;
  PackCompositeColorV10 hair_color;
  PackCompositeColorV10 hair_color2;
  PackCompositeColorV10 pattern_color;
  PackCompositeColorV10 skin_color;
  pf::dword skin_index;
};

struct PackCompositeRaceDataV10 {
  pf::wstring name;
  pf::qword name_token;
  pf::qword base_head_token;
  std::vector<pf::qword> beard;
  std::vector<pf::qword> ears;
  std::vector<pf::qword> faces;
  std::vector<PackCompositeFileDataV10> file_data;
  pf::dword flags;
  std::vector<pf::qword> hair_styles;
  pf::wstring hair_color_palette;
  pf::filename skeleton_file;
  std::vector<PackCompositeSkinPatternV10> skin_patterns;
  pf::wstring skin_color_palette;
  pf::wstring skin_pattern_palette;
  pf::dword type;
  pf::qword variant_ref_race;
  std::vector<PackCompositeVariantV10> variants;
};

struct PackCompositeV10 {
  std::vector<pf::dword> armor_color_ids;
  std::vector<PackCompositeBlitRectSetV10> blit_rects;
  std::vector<PackCompositeRaceDataV10> race_sex_data;
  pf::word config_version;
};
} // namespace cmpc::comp::v10

namespace de {
template <typename Reader>
void Read(Reader &reader, cmpc::comp::v10::PackCompositeBlitRectSetV10 &value) {
  reader(value.name);
  reader(value.size);
  reader(value.rect_index);
  reader(value.rect_array);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v10::PackCompositeFileDataV10 &value) {
  reader(value.name);
  reader(value.type);
  reader(value.mesh_base);
  reader(value.mesh_overlap);
  reader(value.mask_dye1);
  reader(value.mask_dye2);
  reader(value.mask_dye3);
  reader(value.mask_dye4);
  reader(value.mask_cut);
  reader(value.texture_base);
  reader(value.texture_normal);
  reader(value.dye_flags);
  reader(value.hide_flags);
  reader(value.skin_flags);
  reader(value.blit_rect_index);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v10::PackCompositeSkinPatternV10 &value) {
  reader(value.chest);
  reader(value.face);
  reader(value.feet);
  reader(value.hands);
  reader(value.legs);
  reader(value.ears);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v10::PackCompositeColorV10 &value) {
  reader(value.brightness);
  reader(value.contrast);
  reader(value.hue);
  reader(value.saturation);
  reader(value.lightness);
}

template <typename Reader>
void Read(Reader &reader,
          cmpc::comp::v10::PackCompositeVariantComponentV10 &value) {
  reader(value.name_token);
  reader(value.color0);
  reader(value.color1);
  reader(value.color2);
  reader(value.color3);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v10::PackCompositeVariantV10 &value) {
  reader(value.token);
  reader(value.components);
  reader(value.hair_color);
  reader(value.hair_color2);
  reader(value.pattern_color);
  reader(value.skin_color);
  reader(value.skin_index);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v10::PackCompositeRaceDataV10 &value) {
  reader(value.name);
  reader(value.name_token);
  reader(value.base_head_token);
  reader(value.beard);
  reader(value.ears);
  reader(value.faces);
  reader(value.file_data);
  reader(value.flags);
  reader(value.hair_styles);
  reader(value.hair_color_palette);
  reader(value.skeleton_file);
  reader(value.skin_patterns);
  reader(value.skin_color_palette);
  reader(value.skin_pattern_palette);
  reader(value.type);
  reader(value.variant_ref_race);
  reader(value.variants);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v10::PackCompositeV10 &value) {
  reader(value.armor_color_ids);
  reader(value.blit_rects);
  reader(value.race_sex_data);
  reader(value.config_version);
}
} // namespace de

} // namespace pf

#endif
