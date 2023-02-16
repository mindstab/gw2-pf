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

#if MAPC_ENV_MIN_VERSION <= 75

#include "pf/types.hpp"

namespace pf {
namespace mapc::env::v75 {
struct PackMapEnvDataLightV75 {
  pf::byte3 color;
  float intensity;
  pf::float3 direction;
};

struct PackMapEnvDataLightingV75 {
  std::vector<std::shared_ptr<PackMapEnvDataLightV75>> lights;
  float shadow_influence;
  pf::byte3 backlight_color;
  float backlight_intensity;
};

struct PackMapEnvDataLightingCharV46 {
  float sun_scale;
  float saturation;
  float sun_fill;
  float amb_scale;
  float amb_fill;
  pf::byte flags;
};

struct PackMapEnvDataLightingCharGroupV46 {
  std::vector<PackMapEnvDataLightingCharV46> lighting_char;
};

struct PackMapEnvDataLayerAttributesV75 {
  float brightness;
  float density;
  float haze;
  float light_intensity;
  pf::float2 velocity;
  float fade_width;
  float fade_end;
  pf::dword reserved;
};

struct PackMapEnvDataLayerV75 {
  float altitude;
  float cut_out;
  float depth;
  float extent;
  float scale;
  pf::filename texture;
  std::vector<PackMapEnvDataLayerAttributesV75> attributes;
  pf::wstring name;
  pf::dword reserved;
};

struct PackMapEnvDataCloudsV75 {
  std::vector<PackMapEnvDataLayerV75> layers;
};

struct PackMapEnvDataColoredLightRingsV46 {
  pf::float2 range;
  std::array<float, 6> distances;
  std::array<pf::byte4, 6> light_colors;
  std::array<pf::byte4, 6> shadow_colors;
};

struct PackMapEnvDataEffectExV46 {
  pf::dword dummy;
};

struct PackMapEnvDataEffectV75 {
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
  std::shared_ptr<PackMapEnvDataEffectExV46> ext;
};

struct PackMapEnvDataHazeV75 {
  pf::byte4 near_color;
  pf::byte4 far_color;
  pf::float2 dist_range;
  pf::byte4 height_color;
  pf::float2 height_range;
  float depth_cue;
  pf::float2 sun_dir_range;
};

struct PackMapEnvDataPFieldV75 {
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

struct PackMapEnvDataPFieldCutoutV46 {
  pf::wstring name;
  pf::float4 x;
  pf::float4 y;
  pf::float4 z;
};

struct PackMapEnvDataSkyV75 {
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

struct PackMapEnvLensFlareAtomV46 {
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

struct PackMapEnvLensFlareTextureV46 {
  pf::filename texture;
};

struct PackMapEnvDataShaderConstantV46 {
  pf::dword token;
  pf::float4 value;
};

struct PackMapEnvLensFlareV46 {
  std::vector<PackMapEnvLensFlareAtomV46> atoms;
  std::vector<PackMapEnvLensFlareTextureV46> textures;
  pf::filename material;
  pf::float2 fade_band;
  pf::float2 reverse_fade_band;
  float opacity_coeff;
  pf::byte flags;
  std::vector<PackMapEnvDataShaderConstantV46> constants;
};

struct PackMapEnvDataSkyCardAttributesExV46 {
  pf::dword dummy;
};

struct PackMapEnvDataSkyCardAttributesV75 {
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
  std::shared_ptr<PackMapEnvLensFlareV46> lens_flare;
  std::shared_ptr<PackMapEnvDataSkyCardAttributesExV46> ext;
};

struct PackMapEnvDataShaderTextureV46 {
  pf::filename filename;
  pf::float4 texture_uv;
};

struct PackEnvDataSkyCardAnimationV46 {
  pf::float2 texture_anim_translation;
  pf::float2 texture_anim_scale_range_x;
  pf::float2 texture_anim_scale_range_y;
  pf::float2 texture_anim_scale_speed;
  float texture_anim_rotation;
  pf::dword tex_coords;
};

struct PackMapEnvDataSkycardFlipbookV46 {
  pf::dword rows;
  pf::dword columns;
  pf::dword start;
  pf::dword count;
  float fps;
};

struct PackMapEnvDataSkyCardMaterialV46 {
  pf::filename filename;
  std::vector<PackMapEnvDataShaderConstantV46> constants;
  std::vector<PackMapEnvDataShaderTextureV46> textures;
  PackEnvDataSkyCardAnimationV46 texture_animation;
  PackMapEnvDataSkycardFlipbookV46 flipbook;
};

struct PackMapEnvDataSkyCardExV46 {
  pf::dword dummy;
};

struct PackMapEnvDataSkyCardV75 {
  PackMapEnvDataSkyCardAttributesV75 day;
  PackMapEnvDataSkyCardAttributesV75 night;
  pf::dword flags;
  pf::wstring name;
  pf::float3 location;
  std::shared_ptr<PackMapEnvDataSkyCardMaterialV46> material;
  std::shared_ptr<PackMapEnvDataSkyCardExV46> ext;
};

struct PackMapEnvDataSkyCardsV75 {
  std::vector<PackMapEnvDataSkyCardV75> cards;
};

struct PackMapEnvDataSpawnModelDataV46 {
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

struct PackMapEnvDataSpawnListV46 {
  std::vector<PackMapEnvDataSpawnModelDataV46> spawns;
};

struct PackMapEnvDataSpawnGroupsV46 {
  std::vector<PackMapEnvDataSpawnListV46> spawn_groups;
  std::vector<pf::qword> targets;
};

struct PackMapEnvDataWaterV75 {
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

struct PackMapEnvDataWindV75 {
  pf::byte azimuth;
  pf::byte elevation;
  pf::byte noise;
  pf::byte speed;
  pf::byte gust;
  pf::byte gust_freq;
  pf::byte gust_speed;
};

struct PackMapEnvDataAudioV46 {
  pf::qword token;
};

struct PackMapEnvDataBaseEx2V46 {
  pf::dword dummy;
};

struct PackMapEnvDataBaseExV46 {
  std::shared_ptr<PackMapEnvDataBaseEx2V46> ext2;
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

struct PackMapEnvDataShapeV46 {
  pf::float3 center;
  float height;
  float fade_horiz_inner;
  float fade_horiz_outer;
  float fade_vertical;
  std::vector<pf::float2> vertex_array;
  pf::byte shape_type;
};

struct PackMapEnvDataLocalV75 {
  std::vector<PackMapEnvDataLightingV75> lighting;
  std::vector<PackMapEnvDataLightingCharGroupV46> lighting_char_groups;
  std::shared_ptr<PackMapEnvDataCloudsV75> clouds;
  std::vector<std::shared_ptr<PackMapEnvDataColoredLightRingsV46>>
      colored_light_rings;
  std::vector<std::shared_ptr<PackMapEnvDataEffectV75>> effect;
  std::vector<std::shared_ptr<PackMapEnvDataHazeV75>> haze;
  std::vector<std::shared_ptr<PackMapEnvDataPFieldV75>> particle_fields;
  std::vector<PackMapEnvDataPFieldCutoutV46> particle_field_cutouts;
  std::shared_ptr<PackMapEnvDataSkyV75> sky;
  std::shared_ptr<PackMapEnvDataSkyCardsV75> sky_cards;
  std::shared_ptr<PackMapEnvDataSpawnGroupsV46> spawns;
  std::vector<std::shared_ptr<PackMapEnvDataWaterV75>> water;
  std::vector<std::shared_ptr<PackMapEnvDataWindV75>> wind;
  std::vector<std::shared_ptr<PackMapEnvDataAudioV46>> audio;
  pf::wstring name;
  std::vector<pf::byte> night_mods;
  pf::qword bind_target;
  pf::dword flags;
  std::shared_ptr<PackMapEnvDataBaseExV46> ext;
  pf::byte type;
  pf::qword guid;
  std::vector<PackMapEnvDataShapeV46> shape_array;
};

struct PackMapEnvDataSkyModeTexV75 {
  pf::filename tex_path_ne;
  pf::filename tex_path_sw;
  pf::filename tex_path_t;
};

struct PackMapEnvDataGlobalV75 {
  std::vector<PackMapEnvDataLightingV75> lighting;
  std::vector<PackMapEnvDataLightingCharGroupV46> lighting_char_groups;
  std::shared_ptr<PackMapEnvDataCloudsV75> clouds;
  std::vector<std::shared_ptr<PackMapEnvDataColoredLightRingsV46>>
      colored_light_rings;
  std::vector<std::shared_ptr<PackMapEnvDataEffectV75>> effect;
  std::vector<std::shared_ptr<PackMapEnvDataHazeV75>> haze;
  std::vector<std::shared_ptr<PackMapEnvDataPFieldV75>> particle_fields;
  std::vector<PackMapEnvDataPFieldCutoutV46> particle_field_cutouts;
  std::shared_ptr<PackMapEnvDataSkyV75> sky;
  std::shared_ptr<PackMapEnvDataSkyCardsV75> sky_cards;
  std::shared_ptr<PackMapEnvDataSpawnGroupsV46> spawns;
  std::vector<std::shared_ptr<PackMapEnvDataWaterV75>> water;
  std::vector<std::shared_ptr<PackMapEnvDataWindV75>> wind;
  std::vector<std::shared_ptr<PackMapEnvDataAudioV46>> audio;
  pf::wstring name;
  std::vector<pf::byte> night_mods;
  pf::qword bind_target;
  pf::dword flags;
  std::shared_ptr<PackMapEnvDataBaseExV46> ext;
  std::vector<PackMapEnvDataSkyModeTexV75> sky_mode_tex;
  pf::filename star_file;
};

struct PackMapEnvironmentV75 {
  std::vector<PackMapEnvDataLocalV75> data_local_array;
  std::shared_ptr<PackMapEnvDataGlobalV75> data_global;
};
} // namespace mapc::env::v75

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataLightV75 &value) {
  reader(value.color);
  reader(value.intensity);
  reader(value.direction);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataLightingV75 &value) {
  reader(value.lights);
  reader(value.shadow_influence);
  reader(value.backlight_color);
  reader(value.backlight_intensity);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v75::PackMapEnvDataLightingCharV46 &value) {
  reader(value.sun_scale);
  reader(value.saturation);
  reader(value.sun_fill);
  reader(value.amb_scale);
  reader(value.amb_fill);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v75::PackMapEnvDataLightingCharGroupV46 &value) {
  reader(value.lighting_char);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v75::PackMapEnvDataLayerAttributesV75 &value) {
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
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataLayerV75 &value) {
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
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataCloudsV75 &value) {
  reader(value.layers);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v75::PackMapEnvDataColoredLightRingsV46 &value) {
  reader(value.range);
  reader(value.distances);
  reader(value.light_colors);
  reader(value.shadow_colors);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataEffectExV46 &value) {
  reader(value.dummy);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataEffectV75 &value) {
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
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataHazeV75 &value) {
  reader(value.near_color);
  reader(value.far_color);
  reader(value.dist_range);
  reader(value.height_color);
  reader(value.height_range);
  reader(value.depth_cue);
  reader(value.sun_dir_range);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataPFieldV75 &value) {
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
          mapc::env::v75::PackMapEnvDataPFieldCutoutV46 &value) {
  reader(value.name);
  reader(value.x);
  reader(value.y);
  reader(value.z);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataSkyV75 &value) {
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
void Read(Reader &reader, mapc::env::v75::PackMapEnvLensFlareAtomV46 &value) {
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
          mapc::env::v75::PackMapEnvLensFlareTextureV46 &value) {
  reader(value.texture);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v75::PackMapEnvDataShaderConstantV46 &value) {
  reader(value.token);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v75::PackMapEnvLensFlareV46 &value) {
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
          mapc::env::v75::PackMapEnvDataSkyCardAttributesExV46 &value) {
  reader(value.dummy);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v75::PackMapEnvDataSkyCardAttributesV75 &value) {
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
          mapc::env::v75::PackMapEnvDataShaderTextureV46 &value) {
  reader(value.filename);
  reader(value.texture_uv);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v75::PackEnvDataSkyCardAnimationV46 &value) {
  reader(value.texture_anim_translation);
  reader(value.texture_anim_scale_range_x);
  reader(value.texture_anim_scale_range_y);
  reader(value.texture_anim_scale_speed);
  reader(value.texture_anim_rotation);
  reader(value.tex_coords);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v75::PackMapEnvDataSkycardFlipbookV46 &value) {
  reader(value.rows);
  reader(value.columns);
  reader(value.start);
  reader(value.count);
  reader(value.fps);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v75::PackMapEnvDataSkyCardMaterialV46 &value) {
  reader(value.filename);
  reader(value.constants);
  reader(value.textures);
  reader(value.texture_animation);
  reader(value.flipbook);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataSkyCardExV46 &value) {
  reader(value.dummy);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataSkyCardV75 &value) {
  reader(value.day);
  reader(value.night);
  reader(value.flags);
  reader(value.name);
  reader(value.location);
  reader(value.material);
  reader(value.ext);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataSkyCardsV75 &value) {
  reader(value.cards);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v75::PackMapEnvDataSpawnModelDataV46 &value) {
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
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataSpawnListV46 &value) {
  reader(value.spawns);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataSpawnGroupsV46 &value) {
  reader(value.spawn_groups);
  reader(value.targets);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataWaterV75 &value) {
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
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataWindV75 &value) {
  reader(value.azimuth);
  reader(value.elevation);
  reader(value.noise);
  reader(value.speed);
  reader(value.gust);
  reader(value.gust_freq);
  reader(value.gust_speed);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataAudioV46 &value) {
  reader(value.token);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataBaseEx2V46 &value) {
  reader(value.dummy);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataBaseExV46 &value) {
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
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataShapeV46 &value) {
  reader(value.center);
  reader(value.height);
  reader(value.fade_horiz_inner);
  reader(value.fade_horiz_outer);
  reader(value.fade_vertical);
  reader(value.vertex_array);
  reader(value.shape_type);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataLocalV75 &value) {
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
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataSkyModeTexV75 &value) {
  reader(value.tex_path_ne);
  reader(value.tex_path_sw);
  reader(value.tex_path_t);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v75::PackMapEnvDataGlobalV75 &value) {
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
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v75::PackMapEnvironmentV75 &value) {
  reader(value.data_local_array);
  reader(value.data_global);
}
} // namespace de

} // namespace pf

#endif
