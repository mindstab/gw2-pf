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

#if MAPC_ENV_MIN_VERSION <= 77

#include "pf/types.hpp"

namespace pf {
namespace mapc::env::v77 {
struct PackMapEnvDataLightV76 {
  pf::byte3 color;
  float intensity;
  pf::float3 direction;
};

struct PackMapEnvDataLightingV76 {
  std::vector<std::shared_ptr<PackMapEnvDataLightV76>> lights;
  float shadow_influence;
  pf::byte3 backlight_color;
  float backlight_intensity;
};

struct PackMapEnvDataLightingCharV47 {
  float sun_scale;
  float saturation;
  float sun_fill;
  float amb_scale;
  float amb_fill;
  pf::byte flags;
};

struct PackMapEnvDataLightingCharGroupV47 {
  std::vector<PackMapEnvDataLightingCharV47> lighting_char;
};

struct PackMapEnvDataLayerAttributesV76 {
  float brightness;
  float density;
  float haze;
  float light_intensity;
  pf::float2 velocity;
  float fade_width;
  float fade_end;
  pf::dword reserved;
};

struct PackMapEnvDataLayerV76 {
  float altitude;
  float cut_out;
  float depth;
  float extent;
  float scale;
  pf::filename texture;
  std::vector<PackMapEnvDataLayerAttributesV76> attributes;
  pf::wstring name;
  pf::dword reserved;
};

struct PackMapEnvDataCloudsV76 {
  std::vector<PackMapEnvDataLayerV76> layers;
};

struct PackMapEnvDataColoredLightRingsV47 {
  pf::float2 range;
  std::array<float, 6> distances;
  std::array<pf::byte4, 6> light_colors;
  std::array<pf::byte4, 6> shadow_colors;
};

struct PackMapEnvDataEffectExV47 {
  pf::dword dummy;
};

struct PackMapEnvDataEffectV76 {
  pf::byte4 glow;
  pf::byte4 tint_color;
  pf::byte4 tint_target_color;
  float saturation;
  float tint_amount;
  float tint_focus;
  pf::byte4 glow_level;
  float glow_amplify;
  float focal_depth;
  float focal_range;
  float ssao_amount;
  float ssao_brighten;
  float ssao_contrast;
  float ssao_sun_scale;
  pf::dword flags;
  pf::filename clut_texture_path;
  std::shared_ptr<PackMapEnvDataEffectExV47> ext;
};

struct PackMapEnvDataHazeV76 {
  pf::byte4 near_color;
  pf::byte4 far_color;
  pf::float2 dist_range;
  pf::byte4 height_color;
  pf::float2 height_range;
  float depth_cue;
  pf::float2 sun_dir_range;
};

struct PackMapEnvDataPFieldV76 {
  float altitude;
  pf::float2 angle;
  pf::word cluster_count;
  pf::float2 clustering;
  float depth;
  float deviation;
  pf::float2 deviation_speed;
  pf::word extent;
  float fade;
  pf::float3 field_direction;
  pf::word flags;
  pf::float2 lifetime;
  pf::float2 opacity;
  pf::word particle_count;
  pf::float2 period;
  pf::float2 rotation;
  pf::float2 scale_x;
  pf::float2 scale_y;
  pf::dword seed;
  pf::float2 speed;
  pf::dword2 tex_col_row;
  float tex_fps;
  pf::filename tex_path;
  pf::byte type;
  pf::wstring name;
  pf::dword reserved;
};

struct PackMapEnvDataPFieldCutoutV47 {
  pf::wstring name;
  pf::float4 x;
  pf::float4 y;
  pf::float4 z;
};

struct PackMapEnvDataSkyV76 {
  pf::byte flags;
  float day_brightness;
  float day_haze_bottom;
  float day_haze_density;
  float day_haze_falloff;
  float day_light_intensity;
  float day_star_density;
  float night_brightness;
  float night_haze_bottom;
  float night_haze_density;
  float night_haze_falloff;
  float night_light_intensity;
  float night_star_density;
  float vertical_offset;
};

struct PackMapEnvLensFlareAtomV47 {
  pf::dword rows;
  pf::dword columns;
  pf::dword start;
  float fps;
  pf::byte4 color;
  pf::float2 offset;
  pf::float2 scale;
  float base_rotation;
  float camera_rotation;
  pf::byte flags;
};

struct PackMapEnvLensFlareTextureV47 {
  pf::filename texture;
};

struct PackMapEnvDataShaderConstantV47 {
  pf::dword token;
  pf::float4 value;
};

struct PackMapEnvLensFlareV47 {
  std::vector<PackMapEnvLensFlareAtomV47> atoms;
  std::vector<PackMapEnvLensFlareTextureV47> textures;
  pf::filename material;
  pf::float2 fade_band;
  pf::float2 reverse_fade_band;
  float opacity_coeff;
  pf::byte flags;
  std::vector<PackMapEnvDataShaderConstantV47> constants;
};

struct PackMapEnvDataSkyCardAttributesExV47 {
  pf::dword dummy;
};

struct PackMapEnvDataSkyCardAttributesV76 {
  float azimuth;
  float density;
  float haze_density;
  float latitude;
  float light_intensity;
  float min_haze;
  pf::float2 scale;
  float speed;
  pf::filename texture;
  pf::float4 texture_uv;
  float brightness;
  std::shared_ptr<PackMapEnvLensFlareV47> lens_flare;
  std::shared_ptr<PackMapEnvDataSkyCardAttributesExV47> ext;
};

struct PackMapEnvDataShaderTextureV47 {
  pf::filename filename;
  pf::float4 texture_uv;
};

struct PackEnvDataSkyCardAnimationV47 {
  pf::float2 texture_anim_translation;
  pf::float2 texture_anim_scale_range_x;
  pf::float2 texture_anim_scale_range_y;
  pf::float2 texture_anim_scale_speed;
  float texture_anim_rotation;
  pf::dword tex_coords;
};

struct PackMapEnvDataSkycardFlipbookV47 {
  pf::dword rows;
  pf::dword columns;
  pf::dword start;
  pf::dword count;
  float fps;
};

struct PackMapEnvDataSkyCardMaterialV47 {
  pf::filename filename;
  std::vector<PackMapEnvDataShaderConstantV47> constants;
  std::vector<PackMapEnvDataShaderTextureV47> textures;
  PackEnvDataSkyCardAnimationV47 texture_animation;
  PackMapEnvDataSkycardFlipbookV47 flipbook;
};

struct PackMapEnvDataSkyCardExV47 {
  pf::dword dummy;
};

struct PackMapEnvDataSkyCardV76 {
  PackMapEnvDataSkyCardAttributesV76 day;
  PackMapEnvDataSkyCardAttributesV76 night;
  pf::dword flags;
  pf::wstring name;
  pf::float3 location;
  std::shared_ptr<PackMapEnvDataSkyCardMaterialV47> material;
  std::shared_ptr<PackMapEnvDataSkyCardExV47> ext;
};

struct PackMapEnvDataSkyCardsV76 {
  std::vector<PackMapEnvDataSkyCardV76> cards;
};

struct PackMapEnvDataSpawnModelDataV47 {
  pf::dword2 spawn_range;
  pf::dword2 life_span;
  pf::float2 scale_range;
  pf::float2 height_range;
  pf::float2 rot_x_range;
  pf::float2 rot_y_range;
  pf::float2 rot_z_range;
  float probability;
  float delay;
  pf::dword flags;
  pf::qword anim_sequence;
  pf::filename model_file;
  pf::word max_concurrent;
};

struct PackMapEnvDataSpawnListV47 {
  std::vector<PackMapEnvDataSpawnModelDataV47> spawns;
};

struct PackMapEnvDataSpawnGroupsV47 {
  std::vector<PackMapEnvDataSpawnListV47> spawn_groups;
  std::vector<pf::qword> targets;
};

struct PackMapEnvDataWaterV76 {
  pf::dword water_flags;
  float anim_amplitude;
  float anim_choppiness;
  pf::float2 anim_wind;
  float bump_amount;
  float bump_angle0;
  float bump_angle1;
  float bump_scale0;
  float bump_scale1;
  float bump_speed0;
  float bump_speed1;
  float bump_tile0;
  float bump_tile1;
  float pattern_angle;
  float pattern_tile;
  float pattern_speed;
  float pattern_edge;
  pf::byte4 surface_shallow_color;
  pf::byte4 surface_deep_color;
  pf::byte4 pattern_color;
  float surface_fresnel;
  float distort_amount;
  float depth_attenuation;
  pf::filename material_filename;
  std::vector<pf::filename> texture_filenames;
  std::vector<pf::dword> constant_tokens;
  std::vector<pf::float4> constant_values;
  float foam_spawn;
  float foam_dissolve;
  float foam_depth_attenuation;
  pf::byte4 foam_color0;
  pf::byte4 foam_color1;
};

struct PackMapEnvDataWindV76 {
  pf::byte azimuth;
  pf::byte elevation;
  pf::byte noise;
  pf::byte speed;
  pf::byte gust;
  pf::byte gust_freq;
  pf::byte gust_speed;
};

struct PackMapEnvDataAudioV47 {
  pf::qword token;
};

struct PackMapEnvDataBaseEx2V47 {
  pf::dword dummy;
};

struct PackMapEnvDataBaseExV47 {
  std::shared_ptr<PackMapEnvDataBaseEx2V47> ext2;
  float bright_time;
  float dim_time;
  float dark_coeff;
  float dark_exp;
  float dark_min;
  float dark_max;
  float bright_min;
  float bright_max;
  float bright_scale;
  float dark_scale;
  pf::float4 water_reflection_params;
};

struct PackMapEnvDataShapeV47 {
  pf::float3 center;
  float height;
  float fade_horiz_inner;
  float fade_horiz_outer;
  float fade_vertical;
  std::vector<pf::float2> vertex_array;
  pf::byte shape_type;
};

struct PackMapEnvDataLocalV76 {
  std::vector<PackMapEnvDataLightingV76> lighting;
  std::vector<PackMapEnvDataLightingCharGroupV47> lighting_char_groups;
  std::shared_ptr<PackMapEnvDataCloudsV76> clouds;
  std::vector<std::shared_ptr<PackMapEnvDataColoredLightRingsV47>>
      colored_light_rings;
  std::vector<std::shared_ptr<PackMapEnvDataEffectV76>> effect;
  std::vector<std::shared_ptr<PackMapEnvDataHazeV76>> haze;
  std::vector<std::shared_ptr<PackMapEnvDataPFieldV76>> particle_fields;
  std::vector<PackMapEnvDataPFieldCutoutV47> particle_field_cutouts;
  std::shared_ptr<PackMapEnvDataSkyV76> sky;
  std::shared_ptr<PackMapEnvDataSkyCardsV76> sky_cards;
  std::shared_ptr<PackMapEnvDataSpawnGroupsV47> spawns;
  std::vector<std::shared_ptr<PackMapEnvDataWaterV76>> water;
  std::vector<std::shared_ptr<PackMapEnvDataWindV76>> wind;
  std::vector<std::shared_ptr<PackMapEnvDataAudioV47>> audio;
  pf::wstring name;
  std::vector<pf::byte> night_mods;
  pf::qword bind_target;
  pf::dword flags;
  std::shared_ptr<PackMapEnvDataBaseExV47> ext;
  pf::byte type;
  pf::qword guid;
  std::vector<PackMapEnvDataShapeV47> shape_array;
};

struct PackMapEnvDataSkyModeTexV76 {
  pf::filename tex_path_ne;
  pf::filename tex_path_sw;
  pf::filename tex_path_t;
};

struct PackMapEnvDataSkyModeCubeTexV47 {
  pf::filename tex_path_e;
  pf::filename tex_path_w;
  pf::filename tex_path_n;
  pf::filename tex_path_s;
  pf::filename tex_path_b;
  pf::filename tex_path_t;
};

struct PackMapEnvDataGlobalV76 {
  std::vector<PackMapEnvDataLightingV76> lighting;
  std::vector<PackMapEnvDataLightingCharGroupV47> lighting_char_groups;
  std::shared_ptr<PackMapEnvDataCloudsV76> clouds;
  std::vector<std::shared_ptr<PackMapEnvDataColoredLightRingsV47>>
      colored_light_rings;
  std::vector<std::shared_ptr<PackMapEnvDataEffectV76>> effect;
  std::vector<std::shared_ptr<PackMapEnvDataHazeV76>> haze;
  std::vector<std::shared_ptr<PackMapEnvDataPFieldV76>> particle_fields;
  std::vector<PackMapEnvDataPFieldCutoutV47> particle_field_cutouts;
  std::shared_ptr<PackMapEnvDataSkyV76> sky;
  std::shared_ptr<PackMapEnvDataSkyCardsV76> sky_cards;
  std::shared_ptr<PackMapEnvDataSpawnGroupsV47> spawns;
  std::vector<std::shared_ptr<PackMapEnvDataWaterV76>> water;
  std::vector<std::shared_ptr<PackMapEnvDataWindV76>> wind;
  std::vector<std::shared_ptr<PackMapEnvDataAudioV47>> audio;
  pf::wstring name;
  std::vector<pf::byte> night_mods;
  pf::qword bind_target;
  pf::dword flags;
  std::shared_ptr<PackMapEnvDataBaseExV47> ext;
  std::vector<PackMapEnvDataSkyModeTexV76> sky_mode_tex;
  pf::filename star_file;
  std::vector<PackMapEnvDataSkyModeCubeTexV47> sky_mode_cube_tex;
};

struct PackMapEnvDataOverrideV77 {
  std::vector<PackMapEnvDataLightingV76> lighting;
  std::vector<PackMapEnvDataLightingCharGroupV47> lighting_char_groups;
  std::shared_ptr<PackMapEnvDataCloudsV76> clouds;
  std::vector<std::shared_ptr<PackMapEnvDataColoredLightRingsV47>>
      colored_light_rings;
  std::vector<std::shared_ptr<PackMapEnvDataEffectV76>> effect;
  std::vector<std::shared_ptr<PackMapEnvDataHazeV76>> haze;
  std::vector<std::shared_ptr<PackMapEnvDataPFieldV76>> particle_fields;
  std::vector<PackMapEnvDataPFieldCutoutV47> particle_field_cutouts;
  std::shared_ptr<PackMapEnvDataSkyV76> sky;
  std::shared_ptr<PackMapEnvDataSkyCardsV76> sky_cards;
  std::shared_ptr<PackMapEnvDataSpawnGroupsV47> spawns;
  std::vector<std::shared_ptr<PackMapEnvDataWaterV76>> water;
  std::vector<std::shared_ptr<PackMapEnvDataWindV76>> wind;
  std::vector<std::shared_ptr<PackMapEnvDataAudioV47>> audio;
  pf::wstring name;
  std::vector<pf::byte> night_mods;
  pf::qword bind_target;
  pf::dword flags;
  std::shared_ptr<PackMapEnvDataBaseExV47> ext;
  std::vector<PackMapEnvDataSkyModeTexV76> sky_mode_tex;
  pf::filename star_file;
  std::vector<PackMapEnvDataSkyModeCubeTexV47> sky_mode_cube_tex;
  pf::qword token;
  pf::qword guid;
};

struct PackMapEnvironmentV77 {
  std::vector<PackMapEnvDataLocalV76> data_local_array;
  std::shared_ptr<PackMapEnvDataGlobalV76> data_global;
  std::vector<PackMapEnvDataOverrideV77> data_override_array;
};
} // namespace mapc::env::v77

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataLightV76 &value) {
  reader(value.color);
  reader(value.intensity);
  reader(value.direction);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataLightingV76 &value) {
  reader(value.lights);
  reader(value.shadow_influence);
  reader(value.backlight_color);
  reader(value.backlight_intensity);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v77::PackMapEnvDataLightingCharV47 &value) {
  reader(value.sun_scale);
  reader(value.saturation);
  reader(value.sun_fill);
  reader(value.amb_scale);
  reader(value.amb_fill);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v77::PackMapEnvDataLightingCharGroupV47 &value) {
  reader(value.lighting_char);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v77::PackMapEnvDataLayerAttributesV76 &value) {
  reader(value.brightness);
  reader(value.density);
  reader(value.haze);
  reader(value.light_intensity);
  reader(value.velocity);
  reader(value.fade_width);
  reader(value.fade_end);
  reader(value.reserved);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataLayerV76 &value) {
  reader(value.altitude);
  reader(value.cut_out);
  reader(value.depth);
  reader(value.extent);
  reader(value.scale);
  reader(value.texture);
  reader(value.attributes);
  reader(value.name);
  reader(value.reserved);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataCloudsV76 &value) {
  reader(value.layers);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v77::PackMapEnvDataColoredLightRingsV47 &value) {
  reader(value.range);
  reader(value.distances);
  reader(value.light_colors);
  reader(value.shadow_colors);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataEffectExV47 &value) {
  reader(value.dummy);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataEffectV76 &value) {
  reader(value.glow);
  reader(value.tint_color);
  reader(value.tint_target_color);
  reader(value.saturation);
  reader(value.tint_amount);
  reader(value.tint_focus);
  reader(value.glow_level);
  reader(value.glow_amplify);
  reader(value.focal_depth);
  reader(value.focal_range);
  reader(value.ssao_amount);
  reader(value.ssao_brighten);
  reader(value.ssao_contrast);
  reader(value.ssao_sun_scale);
  reader(value.flags);
  reader(value.clut_texture_path);
  reader(value.ext);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataHazeV76 &value) {
  reader(value.near_color);
  reader(value.far_color);
  reader(value.dist_range);
  reader(value.height_color);
  reader(value.height_range);
  reader(value.depth_cue);
  reader(value.sun_dir_range);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataPFieldV76 &value) {
  reader(value.altitude);
  reader(value.angle);
  reader(value.cluster_count);
  reader(value.clustering);
  reader(value.depth);
  reader(value.deviation);
  reader(value.deviation_speed);
  reader(value.extent);
  reader(value.fade);
  reader(value.field_direction);
  reader(value.flags);
  reader(value.lifetime);
  reader(value.opacity);
  reader(value.particle_count);
  reader(value.period);
  reader(value.rotation);
  reader(value.scale_x);
  reader(value.scale_y);
  reader(value.seed);
  reader(value.speed);
  reader(value.tex_col_row);
  reader(value.tex_fps);
  reader(value.tex_path);
  reader(value.type);
  reader(value.name);
  reader(value.reserved);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v77::PackMapEnvDataPFieldCutoutV47 &value) {
  reader(value.name);
  reader(value.x);
  reader(value.y);
  reader(value.z);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataSkyV76 &value) {
  reader(value.flags);
  reader(value.day_brightness);
  reader(value.day_haze_bottom);
  reader(value.day_haze_density);
  reader(value.day_haze_falloff);
  reader(value.day_light_intensity);
  reader(value.day_star_density);
  reader(value.night_brightness);
  reader(value.night_haze_bottom);
  reader(value.night_haze_density);
  reader(value.night_haze_falloff);
  reader(value.night_light_intensity);
  reader(value.night_star_density);
  reader(value.vertical_offset);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvLensFlareAtomV47 &value) {
  reader(value.rows);
  reader(value.columns);
  reader(value.start);
  reader(value.fps);
  reader(value.color);
  reader(value.offset);
  reader(value.scale);
  reader(value.base_rotation);
  reader(value.camera_rotation);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v77::PackMapEnvLensFlareTextureV47 &value) {
  reader(value.texture);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v77::PackMapEnvDataShaderConstantV47 &value) {
  reader(value.token);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvLensFlareV47 &value) {
  reader(value.atoms);
  reader(value.textures);
  reader(value.material);
  reader(value.fade_band);
  reader(value.reverse_fade_band);
  reader(value.opacity_coeff);
  reader(value.flags);
  reader(value.constants);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v77::PackMapEnvDataSkyCardAttributesExV47 &value) {
  reader(value.dummy);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v77::PackMapEnvDataSkyCardAttributesV76 &value) {
  reader(value.azimuth);
  reader(value.density);
  reader(value.haze_density);
  reader(value.latitude);
  reader(value.light_intensity);
  reader(value.min_haze);
  reader(value.scale);
  reader(value.speed);
  reader(value.texture);
  reader(value.texture_uv);
  reader(value.brightness);
  reader(value.lens_flare);
  reader(value.ext);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v77::PackMapEnvDataShaderTextureV47 &value) {
  reader(value.filename);
  reader(value.texture_uv);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v77::PackEnvDataSkyCardAnimationV47 &value) {
  reader(value.texture_anim_translation);
  reader(value.texture_anim_scale_range_x);
  reader(value.texture_anim_scale_range_y);
  reader(value.texture_anim_scale_speed);
  reader(value.texture_anim_rotation);
  reader(value.tex_coords);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v77::PackMapEnvDataSkycardFlipbookV47 &value) {
  reader(value.rows);
  reader(value.columns);
  reader(value.start);
  reader(value.count);
  reader(value.fps);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v77::PackMapEnvDataSkyCardMaterialV47 &value) {
  reader(value.filename);
  reader(value.constants);
  reader(value.textures);
  reader(value.texture_animation);
  reader(value.flipbook);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataSkyCardExV47 &value) {
  reader(value.dummy);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataSkyCardV76 &value) {
  reader(value.day);
  reader(value.night);
  reader(value.flags);
  reader(value.name);
  reader(value.location);
  reader(value.material);
  reader(value.ext);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataSkyCardsV76 &value) {
  reader(value.cards);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v77::PackMapEnvDataSpawnModelDataV47 &value) {
  reader(value.spawn_range);
  reader(value.life_span);
  reader(value.scale_range);
  reader(value.height_range);
  reader(value.rot_x_range);
  reader(value.rot_y_range);
  reader(value.rot_z_range);
  reader(value.probability);
  reader(value.delay);
  reader(value.flags);
  reader(value.anim_sequence);
  reader(value.model_file);
  reader(value.max_concurrent);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataSpawnListV47 &value) {
  reader(value.spawns);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataSpawnGroupsV47 &value) {
  reader(value.spawn_groups);
  reader(value.targets);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataWaterV76 &value) {
  reader(value.water_flags);
  reader(value.anim_amplitude);
  reader(value.anim_choppiness);
  reader(value.anim_wind);
  reader(value.bump_amount);
  reader(value.bump_angle0);
  reader(value.bump_angle1);
  reader(value.bump_scale0);
  reader(value.bump_scale1);
  reader(value.bump_speed0);
  reader(value.bump_speed1);
  reader(value.bump_tile0);
  reader(value.bump_tile1);
  reader(value.pattern_angle);
  reader(value.pattern_tile);
  reader(value.pattern_speed);
  reader(value.pattern_edge);
  reader(value.surface_shallow_color);
  reader(value.surface_deep_color);
  reader(value.pattern_color);
  reader(value.surface_fresnel);
  reader(value.distort_amount);
  reader(value.depth_attenuation);
  reader(value.material_filename);
  reader(value.texture_filenames);
  reader(value.constant_tokens);
  reader(value.constant_values);
  reader(value.foam_spawn);
  reader(value.foam_dissolve);
  reader(value.foam_depth_attenuation);
  reader(value.foam_color0);
  reader(value.foam_color1);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataWindV76 &value) {
  reader(value.azimuth);
  reader(value.elevation);
  reader(value.noise);
  reader(value.speed);
  reader(value.gust);
  reader(value.gust_freq);
  reader(value.gust_speed);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataAudioV47 &value) {
  reader(value.token);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataBaseEx2V47 &value) {
  reader(value.dummy);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataBaseExV47 &value) {
  reader(value.ext2);
  reader(value.bright_time);
  reader(value.dim_time);
  reader(value.dark_coeff);
  reader(value.dark_exp);
  reader(value.dark_min);
  reader(value.dark_max);
  reader(value.bright_min);
  reader(value.bright_max);
  reader(value.bright_scale);
  reader(value.dark_scale);
  reader(value.water_reflection_params);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataShapeV47 &value) {
  reader(value.center);
  reader(value.height);
  reader(value.fade_horiz_inner);
  reader(value.fade_horiz_outer);
  reader(value.fade_vertical);
  reader(value.vertex_array);
  reader(value.shape_type);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataLocalV76 &value) {
  reader(value.lighting);
  reader(value.lighting_char_groups);
  reader(value.clouds);
  reader(value.colored_light_rings);
  reader(value.effect);
  reader(value.haze);
  reader(value.particle_fields);
  reader(value.particle_field_cutouts);
  reader(value.sky);
  reader(value.sky_cards);
  reader(value.spawns);
  reader(value.water);
  reader(value.wind);
  reader(value.audio);
  reader(value.name);
  reader(value.night_mods);
  reader(value.bind_target);
  reader(value.flags);
  reader(value.ext);
  reader(value.type);
  reader(value.guid);
  reader(value.shape_array);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataSkyModeTexV76 &value) {
  reader(value.tex_path_ne);
  reader(value.tex_path_sw);
  reader(value.tex_path_t);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v77::PackMapEnvDataSkyModeCubeTexV47 &value) {
  reader(value.tex_path_e);
  reader(value.tex_path_w);
  reader(value.tex_path_n);
  reader(value.tex_path_s);
  reader(value.tex_path_b);
  reader(value.tex_path_t);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataGlobalV76 &value) {
  reader(value.lighting);
  reader(value.lighting_char_groups);
  reader(value.clouds);
  reader(value.colored_light_rings);
  reader(value.effect);
  reader(value.haze);
  reader(value.particle_fields);
  reader(value.particle_field_cutouts);
  reader(value.sky);
  reader(value.sky_cards);
  reader(value.spawns);
  reader(value.water);
  reader(value.wind);
  reader(value.audio);
  reader(value.name);
  reader(value.night_mods);
  reader(value.bind_target);
  reader(value.flags);
  reader(value.ext);
  reader(value.sky_mode_tex);
  reader(value.star_file);
  reader(value.sky_mode_cube_tex);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvDataOverrideV77 &value) {
  reader(value.lighting);
  reader(value.lighting_char_groups);
  reader(value.clouds);
  reader(value.colored_light_rings);
  reader(value.effect);
  reader(value.haze);
  reader(value.particle_fields);
  reader(value.particle_field_cutouts);
  reader(value.sky);
  reader(value.sky_cards);
  reader(value.spawns);
  reader(value.water);
  reader(value.wind);
  reader(value.audio);
  reader(value.name);
  reader(value.night_mods);
  reader(value.bind_target);
  reader(value.flags);
  reader(value.ext);
  reader(value.sky_mode_tex);
  reader(value.star_file);
  reader(value.sky_mode_cube_tex);
  reader(value.token);
  reader(value.guid);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v77::PackMapEnvironmentV77 &value) {
  reader(value.data_local_array);
  reader(value.data_global);
  reader(value.data_override_array);
}
} // namespace de

} // namespace pf

#endif
