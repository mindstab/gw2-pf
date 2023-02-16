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

#if MAPC_ENV_MIN_VERSION <= 64

#include "pf/types.hpp"

namespace pf {
namespace mapc::env::v64 {
struct PackMapEnvDataLightV64 {
  pf::byte3 color;
  float intensity;
  pf::float3 direction;
};

struct PackMapEnvDataLightingV64 {
  std::vector<std::shared_ptr<PackMapEnvDataLightV64>> lights;
};

struct PackMapEnvDataLightingCharV35 {
  float sun_scale;
  float saturation;
  float sun_fill;
  float amb_scale;
  float amb_fill;
  pf::byte flags;
};

struct PackMapEnvDataLightingCharGroupV35 {
  std::vector<PackMapEnvDataLightingCharV35> lighting_char;
};

struct PackMapEnvDataLayerAttributesV64 {
  float brightness;
  float density;
  float haze;
  float light_intensity;
  pf::float2 velocity;
  float fade_width;
  float fade_end;
};

struct PackMapEnvDataLayerV64 {
  float altitude;
  float cut_out;
  float depth;
  float extent;
  float scale;
  pf::filename texture;
  std::vector<PackMapEnvDataLayerAttributesV64> attributes;
  pf::wstring name;
};

struct PackMapEnvDataCloudsV64 {
  std::vector<PackMapEnvDataLayerV64> layers;
};

struct PackMapEnvDataColoredLightRingsV35 {
  pf::float2 range;
  std::array<float, 6> distances;
  std::array<pf::byte4, 6> light_colors;
  std::array<pf::byte4, 6> shadow_colors;
};

struct PackMapEnvDataEffectV64 {
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
  pf::float2 flattening_range;
  pf::float2 flattening_character_range;
};

struct PackMapEnvDataHazeV64 {
  pf::byte4 near_color;
  pf::byte4 far_color;
  pf::float2 dist_range;
  pf::byte4 height_color;
  pf::float2 height_range;
  float depth_cue;
  pf::float2 sun_dir_range;
};

struct PackMapEnvDataPFieldV64 {
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
  pf::word tex_fps;
  pf::filename tex_path;
  pf::byte type;
  pf::wstring name;
};

struct PackMapEnvDataPFieldCutoutV35 {
  pf::wstring name;
  pf::float4 x;
  pf::float4 y;
  pf::float4 z;
};

struct PackMapEnvDataSkyV64 {
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

struct PackMapEnvDataSkyCardAttributesV64 {
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
};

struct PackMapEnvDataSkyCardV64 {
  PackMapEnvDataSkyCardAttributesV64 day;
  PackMapEnvDataSkyCardAttributesV64 night;
  pf::dword flags;
  pf::wstring name;
};

struct PackMapEnvDataSkyCardsV64 {
  std::vector<PackMapEnvDataSkyCardV64> cards;
};

struct PackMapEnvDataSpawnModelDataV35 {
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
  pf::filename model_file;
  pf::word max_concurrent;
};

struct PackMapEnvDataSpawnListV35 {
  std::vector<PackMapEnvDataSpawnModelDataV35> spawns;
};

struct PackMapEnvDataSpawnGroupsV35 {
  std::vector<PackMapEnvDataSpawnListV35> spawn_groups;
  std::vector<pf::qword> targets;
};

struct PackMapEnvDataWaterV64 {
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

struct PackMapEnvDataWindV64 {
  pf::byte azimuth;
  pf::byte elevation;
  pf::byte noise;
  pf::byte speed;
  pf::byte gust;
  pf::byte gust_freq;
  pf::byte gust_speed;
};

struct PackMapEnvDataLocalV64 {
  std::vector<PackMapEnvDataLightingV64> lighting;
  std::vector<PackMapEnvDataLightingCharGroupV35> lighting_char_groups;
  std::shared_ptr<PackMapEnvDataCloudsV64> clouds;
  std::vector<std::shared_ptr<PackMapEnvDataColoredLightRingsV35>>
      colored_light_rings;
  std::vector<std::shared_ptr<PackMapEnvDataEffectV64>> effect;
  std::vector<std::shared_ptr<PackMapEnvDataHazeV64>> haze;
  std::vector<std::shared_ptr<PackMapEnvDataPFieldV64>> particle_fields;
  std::vector<PackMapEnvDataPFieldCutoutV35> particle_field_cutouts;
  std::shared_ptr<PackMapEnvDataSkyV64> sky;
  std::shared_ptr<PackMapEnvDataSkyCardsV64> sky_cards;
  std::shared_ptr<PackMapEnvDataSpawnGroupsV35> spawns;
  std::vector<std::shared_ptr<PackMapEnvDataWaterV64>> water;
  std::vector<std::shared_ptr<PackMapEnvDataWindV64>> wind;
  pf::wstring name;
  std::vector<pf::byte> night_mods;
  pf::qword bind_target;
  pf::float3 center;
  pf::float2 z_range;
  float fade_horiz_inner;
  float fade_horiz_outer;
  float fade_vertical;
  pf::byte type;
  std::vector<pf::float2> vertex_array;
  pf::qword guid;
};

struct PackMapEnvDataSkyModeTexV64 {
  pf::filename tex_path_ne;
  pf::filename tex_path_sw;
  pf::filename tex_path_t;
};

struct PackMapEnvDataGlobalV64 {
  std::vector<PackMapEnvDataLightingV64> lighting;
  std::vector<PackMapEnvDataLightingCharGroupV35> lighting_char_groups;
  std::shared_ptr<PackMapEnvDataCloudsV64> clouds;
  std::vector<std::shared_ptr<PackMapEnvDataColoredLightRingsV35>>
      colored_light_rings;
  std::vector<std::shared_ptr<PackMapEnvDataEffectV64>> effect;
  std::vector<std::shared_ptr<PackMapEnvDataHazeV64>> haze;
  std::vector<std::shared_ptr<PackMapEnvDataPFieldV64>> particle_fields;
  std::vector<PackMapEnvDataPFieldCutoutV35> particle_field_cutouts;
  std::shared_ptr<PackMapEnvDataSkyV64> sky;
  std::shared_ptr<PackMapEnvDataSkyCardsV64> sky_cards;
  std::shared_ptr<PackMapEnvDataSpawnGroupsV35> spawns;
  std::vector<std::shared_ptr<PackMapEnvDataWaterV64>> water;
  std::vector<std::shared_ptr<PackMapEnvDataWindV64>> wind;
  pf::wstring name;
  std::vector<pf::byte> night_mods;
  pf::qword bind_target;
  std::vector<PackMapEnvDataSkyModeTexV64> sky_mode_tex;
  pf::filename star_file;
};

struct PackMapEnvironmentV64 {
  std::vector<PackMapEnvDataLocalV64> data_local_array;
  std::shared_ptr<PackMapEnvDataGlobalV64> data_global;
};
} // namespace mapc::env::v64

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::env::v64::PackMapEnvDataLightV64 &value) {
  reader(value.color);
  reader(value.intensity);
  reader(value.direction);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v64::PackMapEnvDataLightingV64 &value) {
  reader(value.lights);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v64::PackMapEnvDataLightingCharV35 &value) {
  reader(value.sun_scale);
  reader(value.saturation);
  reader(value.sun_fill);
  reader(value.amb_scale);
  reader(value.amb_fill);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v64::PackMapEnvDataLightingCharGroupV35 &value) {
  reader(value.lighting_char);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v64::PackMapEnvDataLayerAttributesV64 &value) {
  reader(value.brightness);
  reader(value.density);
  reader(value.haze);
  reader(value.light_intensity);
  reader(value.velocity);
  reader(value.fade_width);
  reader(value.fade_end);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v64::PackMapEnvDataLayerV64 &value) {
  reader(value.altitude);
  reader(value.cut_out);
  reader(value.depth);
  reader(value.extent);
  reader(value.scale);
  reader(value.texture);
  reader(value.attributes);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v64::PackMapEnvDataCloudsV64 &value) {
  reader(value.layers);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v64::PackMapEnvDataColoredLightRingsV35 &value) {
  reader(value.range);
  reader(value.distances);
  reader(value.light_colors);
  reader(value.shadow_colors);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v64::PackMapEnvDataEffectV64 &value) {
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
  reader(value.flattening_range);
  reader(value.flattening_character_range);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v64::PackMapEnvDataHazeV64 &value) {
  reader(value.near_color);
  reader(value.far_color);
  reader(value.dist_range);
  reader(value.height_color);
  reader(value.height_range);
  reader(value.depth_cue);
  reader(value.sun_dir_range);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v64::PackMapEnvDataPFieldV64 &value) {
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
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v64::PackMapEnvDataPFieldCutoutV35 &value) {
  reader(value.name);
  reader(value.x);
  reader(value.y);
  reader(value.z);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v64::PackMapEnvDataSkyV64 &value) {
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
void Read(Reader &reader,
          mapc::env::v64::PackMapEnvDataSkyCardAttributesV64 &value) {
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
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v64::PackMapEnvDataSkyCardV64 &value) {
  reader(value.day);
  reader(value.night);
  reader(value.flags);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v64::PackMapEnvDataSkyCardsV64 &value) {
  reader(value.cards);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v64::PackMapEnvDataSpawnModelDataV35 &value) {
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
  reader(value.model_file);
  reader(value.max_concurrent);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v64::PackMapEnvDataSpawnListV35 &value) {
  reader(value.spawns);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v64::PackMapEnvDataSpawnGroupsV35 &value) {
  reader(value.spawn_groups);
  reader(value.targets);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v64::PackMapEnvDataWaterV64 &value) {
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
void Read(Reader &reader, mapc::env::v64::PackMapEnvDataWindV64 &value) {
  reader(value.azimuth);
  reader(value.elevation);
  reader(value.noise);
  reader(value.speed);
  reader(value.gust);
  reader(value.gust_freq);
  reader(value.gust_speed);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v64::PackMapEnvDataLocalV64 &value) {
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
  reader(value.name);
  reader(value.night_mods);
  reader(value.bind_target);
  reader(value.center);
  reader(value.z_range);
  reader(value.fade_horiz_inner);
  reader(value.fade_horiz_outer);
  reader(value.fade_vertical);
  reader(value.type);
  reader(value.vertex_array);
  reader(value.guid);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v64::PackMapEnvDataSkyModeTexV64 &value) {
  reader(value.tex_path_ne);
  reader(value.tex_path_sw);
  reader(value.tex_path_t);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v64::PackMapEnvDataGlobalV64 &value) {
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
  reader(value.name);
  reader(value.night_mods);
  reader(value.bind_target);
  reader(value.sky_mode_tex);
  reader(value.star_file);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v64::PackMapEnvironmentV64 &value) {
  reader(value.data_local_array);
  reader(value.data_global);
}
} // namespace de

} // namespace pf

#endif
