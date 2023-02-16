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

#if CMPC_COMP_MIN_VERSION <= 17

#include "pf/types.hpp"

namespace pf {
namespace cmpc::comp::v17 {
struct PackCompositeBlitRectSetV17 {
  pf::wstring name;
  pf::dword2 size;
  std::vector<pf::byte> rect_index;
  std::vector<pf::dword4> rect_array;
};

struct PackCompositeBoneScaleParamV17 {
  pf::qword name;
  pf::byte flags;
  float max;
  float min;
  pf::float3 rotate;
  pf::float3 scale;
  pf::float3 translate;
};

struct PackCompositeBoneScaleRegionV17 {
  pf::qword name;
  float value;
  std::vector<PackCompositeBoneScaleParamV17> bone;
};

struct PackCompositeMorphWeightV17 {
  pf::qword name;
  float value;
};

struct PackCompositeBoneScaleV17 {
  std::vector<PackCompositeBoneScaleRegionV17> body_region;
  std::vector<PackCompositeMorphWeightV17> morph_weight;
};

struct PackCompositeBoneScaleFileV17 {
  pf::wstring file_name;
};

struct PackCompositeFileDataV17 {
  pf::qword name;
  pf::byte type;
  pf::byte flags;
  pf::fileref mesh_base;
  pf::fileref mesh_overlap;
  pf::fileref mask_dye1;
  pf::fileref mask_dye2;
  pf::fileref mask_dye3;
  pf::fileref mask_dye4;
  pf::fileref mask_cut;
  pf::fileref texture_base;
  pf::fileref texture_normal;
  pf::dword dye_flags;
  pf::dword hide_flags;
  pf::dword skin_flags;
  pf::byte blit_rect_index;
};

struct PackCompositeSkinPatternV17 {
  pf::fileref chest;
  pf::fileref face;
  pf::fileref feet;
  pf::fileref hands;
  pf::fileref legs;
  pf::fileref ears;
};

struct PackCompositeSkinStyleV17 {
  pf::qword chest;
  pf::qword feet;
  pf::qword hands;
  pf::qword legs;
};

struct PackCompositeColorV17 {
  pf::byte brightness;
  pf::byte contrast;
  pf::byte hue;
  pf::byte saturation;
  pf::byte lightness;
};

struct PackCompositeVariantComponentV17 {
  pf::qword name_token;
  PackCompositeColorV17 color0;
  PackCompositeColorV17 color1;
  PackCompositeColorV17 color2;
  PackCompositeColorV17 color3;
};

struct PackCompositeVariantV17 {
  pf::qword token;
  pf::dword bone_scale_index;
  std::vector<PackCompositeVariantComponentV17> components;
  PackCompositeColorV17 eye_color;
  PackCompositeColorV17 hair_color;
  PackCompositeColorV17 hair_color2;
  PackCompositeColorV17 pattern_color;
  PackCompositeColorV17 skin_color;
  pf::dword skin_index;
};

struct PackCompositeAnimOverrideV17 {
  pf::qword anim_role;
  pf::fileref filepath;
};

struct PackCompositeRaceDataV17 {
  pf::wstring name;
  pf::qword name_token;
  pf::qword base_head_token;
  std::vector<pf::qword> beard;
  std::vector<PackCompositeBoneScaleV17> body_bone_scales;
  std::vector<PackCompositeBoneScaleFileV17> body_bone_scale_files;
  std::vector<pf::qword> ears;
  pf::wstring eye_color_palette;
  std::vector<PackCompositeBoneScaleV17> face_bone_scales;
  std::vector<pf::qword> faces;
  std::vector<PackCompositeFileDataV17> file_data;
  pf::dword flags;
  std::vector<pf::qword> hair_styles;
  pf::wstring hair_color_palette;
  pf::fileref skeleton_file;
  std::vector<PackCompositeSkinPatternV17> skin_patterns;
  pf::wstring skin_color_palette;
  pf::wstring skin_pattern_palette;
  std::vector<PackCompositeSkinStyleV17> skin_styles;
  pf::dword type;
  pf::qword variant_ref_race;
  std::vector<PackCompositeVariantV17> variants;
  std::vector<PackCompositeAnimOverrideV17> anim_overrides;
};

struct PackCompositeV17 {
  std::vector<pf::dword> armor_color_ids;
  std::vector<PackCompositeBlitRectSetV17> blit_rects;
  std::vector<PackCompositeBoneScaleV17> bone_scales;
  std::vector<PackCompositeRaceDataV17> race_sex_data;
  pf::word config_version;
};
} // namespace cmpc::comp::v17

namespace de {
template <typename Reader>
void Read(Reader &reader, cmpc::comp::v17::PackCompositeBlitRectSetV17 &value) {
  reader(value.name);
  reader(value.size);
  reader(value.rect_index);
  reader(value.rect_array);
}

template <typename Reader>
void Read(Reader &reader,
          cmpc::comp::v17::PackCompositeBoneScaleParamV17 &value) {
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
          cmpc::comp::v17::PackCompositeBoneScaleRegionV17 &value) {
  reader(value.name);
  reader(value.value);
  reader(value.bone);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v17::PackCompositeMorphWeightV17 &value) {
  reader(value.name);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v17::PackCompositeBoneScaleV17 &value) {
  reader(value.body_region);
  reader(value.morph_weight);
}

template <typename Reader>
void Read(Reader &reader,
          cmpc::comp::v17::PackCompositeBoneScaleFileV17 &value) {
  reader(value.file_name);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v17::PackCompositeFileDataV17 &value) {
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
void Read(Reader &reader, cmpc::comp::v17::PackCompositeSkinPatternV17 &value) {
  reader(value.chest);
  reader(value.face);
  reader(value.feet);
  reader(value.hands);
  reader(value.legs);
  reader(value.ears);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v17::PackCompositeSkinStyleV17 &value) {
  reader(value.chest);
  reader(value.feet);
  reader(value.hands);
  reader(value.legs);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v17::PackCompositeColorV17 &value) {
  reader(value.brightness);
  reader(value.contrast);
  reader(value.hue);
  reader(value.saturation);
  reader(value.lightness);
}

template <typename Reader>
void Read(Reader &reader,
          cmpc::comp::v17::PackCompositeVariantComponentV17 &value) {
  reader(value.name_token);
  reader(value.color0);
  reader(value.color1);
  reader(value.color2);
  reader(value.color3);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v17::PackCompositeVariantV17 &value) {
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
void Read(Reader &reader,
          cmpc::comp::v17::PackCompositeAnimOverrideV17 &value) {
  reader(value.anim_role);
  reader(value.filepath);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v17::PackCompositeRaceDataV17 &value) {
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
  reader(value.skin_styles);
  reader(value.type);
  reader(value.variant_ref_race);
  reader(value.variants);
  reader(value.anim_overrides);
}

template <typename Reader>
void Read(Reader &reader, cmpc::comp::v17::PackCompositeV17 &value) {
  reader(value.armor_color_ids);
  reader(value.blit_rects);
  reader(value.bone_scales);
  reader(value.race_sex_data);
  reader(value.config_version);
}
} // namespace de

} // namespace pf

#endif
