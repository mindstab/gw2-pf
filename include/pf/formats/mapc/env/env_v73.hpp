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

#if MAPC_ENV_MIN_VERSION <= 73

#include "pf/types.hpp"

namespace pf {
namespace mapc::env::v73 {
struct PackMapEnvDataLightV73 {
  pf::byte3 color;
  float intensity;
  pf::float3 direction;
};

struct PackMapEnvDataLightingV73 {
  std::vector<std::shared_ptr<PackMapEnvDataLightV73>> lights;
  float shadow_influence;
  pf::byte3 backlight_color;
  float backlight_intensity;
};

struct PackMapEnvDataLightingCharV44 {
  float sun_scale;
  float saturation;
  float sun_fill;
  float amb_scale;
  float amb_fill;
  pf::byte flags;
};

struct PackMapEnvDataLightingCharGroupV44 {
  std::vector<PackMapEnvDataLightingCharV44> lighting_char;
};

struct PackMapEnvDataLayerAttributesV73 {
  float brightness;
  float density;
  float haze;
  float light_intensity;
  pf::float2 velocity;
  float fade_width;
  float fade_end;
};

struct PackMapEnvDataLayerV73 {
  float altitude;
  float cut_out;
  float depth;
  float extent;
  float scale;
  pf::filename texture;
  std::vector<PackMapEnvDataLayerAttributesV73> attributes;
  pf::wstring name;
};

struct PackMapEnvDataCloudsV73 {
  std::vector<PackMapEnvDataLayerV73> layers;
};

struct PackMapEnvDataColoredLightRingsV44 {
  pf::float2 range;
  std::array<float, 6> distances;
  std::array<pf::byte4, 6> light_colors;
  std::array<pf::byte4, 6> shadow_colors;
};

struct PackMapEnvDataEffectV73 {
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

struct PackMapEnvDataHazeV73 {
  pf::byte4 near_color;
  pf::byte4 far_color;
  pf::float2 dist_range;
  pf::byte4 height_color;
  pf::float2 height_range;
  float depth_cue;
  pf::float2 sun_dir_range;
};

struct PackMapEnvDataPFieldV73 {
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
};

struct PackMapEnvDataPFieldCutoutV44 {
  pf::wstring name;
  pf::float4 x;
  pf::float4 y;
  pf::float4 z;
};

struct PackMapEnvDataSkyV73 {
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

struct PackMapEnvDataSkyCardAttributesV73 {
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

struct PackMapEnvDataSkyCardV73 {
  PackMapEnvDataSkyCardAttributesV73 day;
  PackMapEnvDataSkyCardAttributesV73 night;
  pf::dword flags;
  pf::wstring name;
};

struct PackMapEnvDataSkyCardsV73 {
  std::vector<PackMapEnvDataSkyCardV73> cards;
};

struct PackMapEnvDataSpawnModelDataV44 {
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

struct PackMapEnvDataSpawnListV44 {
  std::vector<PackMapEnvDataSpawnModelDataV44> spawns;
};

struct PackMapEnvDataSpawnGroupsV44 {
  std::vector<PackMapEnvDataSpawnListV44> spawn_groups;
  std::vector<pf::qword> targets;
};

struct PackMapEnvDataWaterV73 {
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

struct PackMapEnvDataWindV73 {
  pf::byte azimuth;
  pf::byte elevation;
  pf::byte noise;
  pf::byte speed;
  pf::byte gust;
  pf::byte gust_freq;
  pf::byte gust_speed;
};

struct PackMapEnvDataAudioV44 {
  pf::qword token;
};

struct PackMapEnvDataShapeV44 {
  pf::float3 center;
  float height;
  float fade_horiz_inner;
  float fade_horiz_outer;
  float fade_vertical;
  std::vector<pf::float2> vertex_array;
  pf::byte shape_type;
};

struct PackMapEnvDataLocalV73 {
  std::vector<PackMapEnvDataLightingV73> lighting;
  std::vector<PackMapEnvDataLightingCharGroupV44> lighting_char_groups;
  std::shared_ptr<PackMapEnvDataCloudsV73> clouds;
  std::vector<std::shared_ptr<PackMapEnvDataColoredLightRingsV44>>
      colored_light_rings;
  std::vector<std::shared_ptr<PackMapEnvDataEffectV73>> effect;
  std::vector<std::shared_ptr<PackMapEnvDataHazeV73>> haze;
  std::vector<std::shared_ptr<PackMapEnvDataPFieldV73>> particle_fields;
  std::vector<PackMapEnvDataPFieldCutoutV44> particle_field_cutouts;
  std::shared_ptr<PackMapEnvDataSkyV73> sky;
  std::shared_ptr<PackMapEnvDataSkyCardsV73> sky_cards;
  std::shared_ptr<PackMapEnvDataSpawnGroupsV44> spawns;
  std::vector<std::shared_ptr<PackMapEnvDataWaterV73>> water;
  std::vector<std::shared_ptr<PackMapEnvDataWindV73>> wind;
  std::vector<std::shared_ptr<PackMapEnvDataAudioV44>> audio;
  pf::wstring name;
  std::vector<pf::byte> night_mods;
  pf::qword bind_target;
  pf::byte type;
  pf::qword guid;
  std::vector<PackMapEnvDataShapeV44> shape_array;
};

struct PackMapEnvDataSkyModeTexV73 {
  pf::filename tex_path_ne;
  pf::filename tex_path_sw;
  pf::filename tex_path_t;
};

struct PackMapEnvDataGlobalV73 {
  std::vector<PackMapEnvDataLightingV73> lighting;
  std::vector<PackMapEnvDataLightingCharGroupV44> lighting_char_groups;
  std::shared_ptr<PackMapEnvDataCloudsV73> clouds;
  std::vector<std::shared_ptr<PackMapEnvDataColoredLightRingsV44>>
      colored_light_rings;
  std::vector<std::shared_ptr<PackMapEnvDataEffectV73>> effect;
  std::vector<std::shared_ptr<PackMapEnvDataHazeV73>> haze;
  std::vector<std::shared_ptr<PackMapEnvDataPFieldV73>> particle_fields;
  std::vector<PackMapEnvDataPFieldCutoutV44> particle_field_cutouts;
  std::shared_ptr<PackMapEnvDataSkyV73> sky;
  std::shared_ptr<PackMapEnvDataSkyCardsV73> sky_cards;
  std::shared_ptr<PackMapEnvDataSpawnGroupsV44> spawns;
  std::vector<std::shared_ptr<PackMapEnvDataWaterV73>> water;
  std::vector<std::shared_ptr<PackMapEnvDataWindV73>> wind;
  std::vector<std::shared_ptr<PackMapEnvDataAudioV44>> audio;
  pf::wstring name;
  std::vector<pf::byte> night_mods;
  pf::qword bind_target;
  std::vector<PackMapEnvDataSkyModeTexV73> sky_mode_tex;
  pf::filename star_file;
};

struct PackMapEnvironmentV73 {
  std::vector<PackMapEnvDataLocalV73> data_local_array;
  std::shared_ptr<PackMapEnvDataGlobalV73> data_global;
};
} // namespace mapc::env::v73

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataLightV73 &value) {
  reader(value.color);
  reader(value.intensity);
  reader(value.direction);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataLightingV73 &value) {
  reader(value.lights);
  reader(value.shadow_influence);
  reader(value.backlight_color);
  reader(value.backlight_intensity);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v73::PackMapEnvDataLightingCharV44 &value) {
  reader(value.sun_scale);
  reader(value.saturation);
  reader(value.sun_fill);
  reader(value.amb_scale);
  reader(value.amb_fill);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v73::PackMapEnvDataLightingCharGroupV44 &value) {
  reader(value.lighting_char);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v73::PackMapEnvDataLayerAttributesV73 &value) {
  reader(value.brightness);
  reader(value.density);
  reader(value.haze);
  reader(value.light_intensity);
  reader(value.velocity);
  reader(value.fade_width);
  reader(value.fade_end);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataLayerV73 &value) {
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
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataCloudsV73 &value) {
  reader(value.layers);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v73::PackMapEnvDataColoredLightRingsV44 &value) {
  reader(value.range);
  reader(value.distances);
  reader(value.light_colors);
  reader(value.shadow_colors);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataEffectV73 &value) {
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
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataHazeV73 &value) {
  reader(value.near_color);
  reader(value.far_color);
  reader(value.dist_range);
  reader(value.height_color);
  reader(value.height_range);
  reader(value.depth_cue);
  reader(value.sun_dir_range);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataPFieldV73 &value) {
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
          mapc::env::v73::PackMapEnvDataPFieldCutoutV44 &value) {
  reader(value.name);
  reader(value.x);
  reader(value.y);
  reader(value.z);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataSkyV73 &value) {
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
          mapc::env::v73::PackMapEnvDataSkyCardAttributesV73 &value) {
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
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataSkyCardV73 &value) {
  reader(value.day);
  reader(value.night);
  reader(value.flags);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataSkyCardsV73 &value) {
  reader(value.cards);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v73::PackMapEnvDataSpawnModelDataV44 &value) {
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
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataSpawnListV44 &value) {
  reader(value.spawns);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataSpawnGroupsV44 &value) {
  reader(value.spawn_groups);
  reader(value.targets);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataWaterV73 &value) {
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
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataWindV73 &value) {
  reader(value.azimuth);
  reader(value.elevation);
  reader(value.noise);
  reader(value.speed);
  reader(value.gust);
  reader(value.gust_freq);
  reader(value.gust_speed);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataAudioV44 &value) {
  reader(value.token);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataShapeV44 &value) {
  reader(value.center);
  reader(value.height);
  reader(value.fade_horiz_inner);
  reader(value.fade_horiz_outer);
  reader(value.fade_vertical);
  reader(value.vertex_array);
  reader(value.shape_type);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataLocalV73 &value) {
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
  reader(value.type);
  reader(value.guid);
  reader(value.shape_array);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataSkyModeTexV73 &value) {
  reader(value.tex_path_ne);
  reader(value.tex_path_sw);
  reader(value.tex_path_t);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v73::PackMapEnvDataGlobalV73 &value) {
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
  reader(value.sky_mode_tex);
  reader(value.star_file);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v73::PackMapEnvironmentV73 &value) {
  reader(value.data_local_array);
  reader(value.data_global);
}
} // namespace de

} // namespace pf

#endif
