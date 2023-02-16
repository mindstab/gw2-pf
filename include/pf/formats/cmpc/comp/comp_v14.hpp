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

#if CMPC_COMP_MIN_VERSION <= 14

#include "pf/types.hpp"

namespace pf {
namespace cmpc::comp::v14 {
struct PackCompositeBlitRectSetV14 {
  pf::wstring name;
  pf::dword2 size;
  std::vector<pf::byte> rect_index;
  std::vector<pf::dword4> rect_array;
};

struct PackCompositeBoneScaleParamV14 {
  pf::qword name;
  pf::byte flags;
  float max;
  float min;
  pf::float3 rotate;
  pf::float3 scale;
  pf::float3 translate;
};

struct PackCompositeBoneScaleRegionV14 {
  pf::qword name;
  float value;
  std::vector<PackCompositeBoneScaleParamV14> bone;
};

struct PackCompositeMorphWeightV14 {
  pf::qword name;
  float value;
};

struct PackCompositeBoneScaleV14 {
  std::vector<PackCompositeBoneScaleRegionV14> body_region;
  std::vector<PackCompositeMorphWeightV14> morph_weight;
};

struct PackCompositeBoneScaleFileV14 {
  pf::wstring file_name;
};

struct PackCompositeFileDataV14 {
  pf::qword name;
  pf::byte type;
  pf::byte flags;
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
  pf::byte blit_rect_index;
};

struct PackCompositeSkinPatternV14 {
  pf::filename chest;
  pf::filename face;
  pf::filename feet;
  pf::filename hands;
  pf::filename legs;
  pf::filename ears;
};

struct PackCompositeColorV14 {
  pf::byte brightness;
  pf::byte contrast;
  pf::byte hue;
  pf::byte saturation;
  pf::byte lightness;
};

struct PackCompositeVariantComponentV14 {
  pf::qword name_token;
  PackCompositeColorV14 color0;
  PackCompositeColorV14 color1;
  PackCompositeColorV14 color2;
  PackCompositeColorV14 color3;
};

struct PackCompositeVariantV14 {
  pf::qword token;
  pf::dword bone_scale_index;
  std::vector<PackCompositeVariantComponentV14> components;
  PackCompositeColorV14 eye_color;
  PackCompositeColorV14 hair_color;
  PackCompositeColorV14 hair_color2;
  PackCompositeColorV14 pattern_color;
  PackCompositeColorV14 skin_color;
  pf::dword skin_index;
};

struct PackCompositeRaceDataV14 {
  pf::wstring name;
  pf::qword name_token;
  pf::qword base_head_token;
  std::vector<pf::qword> beard;
  std::vector<PackCompositeBoneScaleV14> body_bone_scales;
  std::vector<PackCompositeBoneScaleFileV14> body_bone_scale_files;
  std::vector<pf::qword> ears;
  pf::wstring eye_color_palette;
  std::vector<PackCompositeBoneScaleV14> face_bone_scales;
  std::vector<pf::qword> faces;
  std::vector<PackCompositeFileDataV14> file_data;
  pf::dword flags;
  std::vector<pf::qword> hair_styles;
  pf::wstring hair_color_palette;
  pf::filename skeleton_file;
  std::vector<PackCompositeSkinPatternV14> skin_patterns;
  pf::wstring skin_color_palette;
  pf::wstring skin_pattern_palette;
  pf::byte skin_style_count;
  pf::dword type;
  pf::qword variant_ref_race;
  std::vector<PackCompositeVariantV14> variants;
};

struct PackCompositeV14 {
  std::vector<pf::dword> armor_color_ids;
  std::vector<PackCompositeBlitRectSetV14> blit_rects;
  std::vector<PackCompositeBoneScaleV14> bone_scales;
  std::vector<PackCompositeRaceDataV14> race_sex_data;
  pf::word config_version;
};
} // namespace cmpc::comp::v14

namespace de {
template <typename Reader>
void Read(Reader &reader, cmpc::comp::v14::PackCompositeBlitRectSetV14 &value) {
  reader(value.name);
  reader(value.size);
  reader(value.rect_index);
  reader(value.rect_array);
}

template <typename Reader>
void Read(Reader &reader,
          cmpc::comp::v14::PackCompositeBoneScaleParamV14 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.max);
  reader(value.min);
  reader(value.rotate);
  reader(value.scale);
  reader(value.translate);
}

template <typename Reader>
void Read(Reader &reader,
          cmpc::comp::v14::PackCompositeBoneScaleRegionV14 &value) {
  reader(value.name);
  reader(value.value);
  reader(value.bone);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v14::PackCompositeMorphWeightV14 &value) {
  reader(value.name);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v14::PackCompositeBoneScaleV14 &value) {
  reader(value.body_region);
  reader(value.morph_weight);
}

template <typename Reader>
void Read(Reader &reader,
          cmpc::comp::v14::PackCompositeBoneScaleFileV14 &value) {
  reader(value.file_name);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v14::PackCompositeFileDataV14 &value) {
  reader(value.name);
  reader(value.type);
  reader(value.flags);
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
void Read(Reader &reader, cmpc::comp::v14::PackCompositeSkinPatternV14 &value) {
  reader(value.chest);
  reader(value.face);
  reader(value.feet);
  reader(value.hands);
  reader(value.legs);
  reader(value.ears);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v14::PackCompositeColorV14 &value) {
  reader(value.brightness);
  reader(value.contrast);
  reader(value.hue);
  reader(value.saturation);
  reader(value.lightness);
}

template <typename Reader>
void Read(Reader &reader,
          cmpc::comp::v14::PackCompositeVariantComponentV14 &value) {
  reader(value.name_token);
  reader(value.color0);
  reader(value.color1);
  reader(value.color2);
  reader(value.color3);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v14::PackCompositeVariantV14 &value) {
  reader(value.token);
  reader(value.bone_scale_index);
  reader(value.components);
  reader(value.eye_color);
  reader(value.hair_color);
  reader(value.hair_color2);
  reader(value.pattern_color);
  reader(value.skin_color);
  reader(value.skin_index);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v14::PackCompositeRaceDataV14 &value) {
  reader(value.name);
  reader(value.name_token);
  reader(value.base_head_token);
  reader(value.beard);
  reader(value.body_bone_scales);
  reader(value.body_bone_scale_files);
  reader(value.ears);
  reader(value.eye_color_palette);
  reader(value.face_bone_scales);
  reader(value.faces);
  reader(value.file_data);
  reader(value.flags);
  reader(value.hair_styles);
  reader(value.hair_color_palette);
  reader(value.skeleton_file);
  reader(value.skin_patterns);
  reader(value.skin_color_palette);
  reader(value.skin_pattern_palette);
  reader(value.skin_style_count);
  reader(value.type);
  reader(value.variant_ref_race);
  reader(value.variants);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v14::PackCompositeV14 &value) {
  reader(value.armor_color_ids);
  reader(value.blit_rects);
  reader(value.bone_scales);
  reader(value.race_sex_data);
  reader(value.config_version);
}
} // namespace de

} // namespace pf

#endif
