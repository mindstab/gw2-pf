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

#if MAPC_ENV_MIN_VERSION <= 46

#include "pf/types.hpp"

namespace pf {
namespace mapc::env::v46 {
struct PackMapEnvDataLightV46 {
  pf::byte3 color;
  float intensity;
  pf::float3 direction;
};

struct PackMapEnvDataLightingV46 {
  std::vector<std::shared_ptr<PackMapEnvDataLightV46>> lights;
};

struct PackMapEnvDataLightingCharV17 {
  float sun_scale;
  float saturation;
  float sun_fill;
  float amb_scale;
  float amb_fill;
  pf::byte flags;
};

struct PackMapEnvDataLayerAttributesV46 {
  float brightness;
  float density;
  float haze;
  float light_intensity;
  pf::float2 velocity;
  float fade_width;
  float fade_end;
};

struct PackMapEnvDataLayerV46 {
  float altitude;
  float cut_out;
  float depth;
  float extent;
  float scale;
  pf::filename texture;
  std::vector<PackMapEnvDataLayerAttributesV46> attributes;
  pf::wstring name;
};

struct PackMapEnvDataCloudsV46 {
  std::vector<PackMapEnvDataLayerV46> layers;
};

struct PackMapEnvDataColoredLightRingsV17 {
  pf::float2 range;
  std::array<pf::byte4, 6> colors;
  std::array<float, 6> distances;
};

struct PackMapEnvDataEffectV46 {
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
};

struct PackMapEnvDataHazeV46 {
  pf::byte4 dist_color;
  pf::float2 dist_range;
  pf::byte4 height_color;
  pf::float2 height_range;
  float depth_cue;
};

struct PackMapEnvDataPFieldV46 {
  float altitude;
  pf::float2 angle;
  float depth;
  float deviation;
  pf::word extent;
  float fade;
  pf::float3 field_direction;
  pf::byte flags;
  pf::float2 opacity;
  pf::word particle_count;
  pf::float2 rotation;
  pf::float2 scale_x;
  pf::float2 scale_y;
  pf::float2 speed;
  pf::dword2 tex_col_row;
  pf::word tex_fps;
  pf::filename tex_path;
  pf::byte type;
  pf::wstring name;
};

struct PackMapEnvDataPFieldCutoutV17 {
  pf::wstring name;
  pf::float4 x;
  pf::float4 y;
  pf::float4 z;
};

struct PackMapEnvDataSkyV46 {
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
};

struct PackMapEnvDataSkyCardAttributesV46 {
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

struct PackMapEnvDataSkyCardV46 {
  PackMapEnvDataSkyCardAttributesV46 day;
  PackMapEnvDataSkyCardAttributesV46 night;
  pf::dword flags;
  pf::wstring name;
};

struct PackMapEnvDataSkyCardsV46 {
  std::vector<PackMapEnvDataSkyCardV46> cards;
};

struct PackMapEnvDataWaterV46 {
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
};

struct PackMapEnvDataWindV46 {
  pf::byte azimuth;
  pf::byte elevation;
  pf::byte noise;
  pf::byte speed;
  pf::byte gust;
  pf::byte gust_freq;
};

struct PackMapEnvDataLocalV46 {
  std::vector<PackMapEnvDataLightingV46> lighting;
  std::vector<PackMapEnvDataLightingCharV17> lighting_char;
  std::shared_ptr<PackMapEnvDataCloudsV46> clouds;
  std::vector<std::shared_ptr<PackMapEnvDataColoredLightRingsV17>>
      colored_light_rings;
  std::vector<std::shared_ptr<PackMapEnvDataEffectV46>> effect;
  std::vector<std::shared_ptr<PackMapEnvDataHazeV46>> haze;
  std::vector<std::shared_ptr<PackMapEnvDataPFieldV46>> particle_fields;
  std::vector<PackMapEnvDataPFieldCutoutV17> particle_field_cutouts;
  std::shared_ptr<PackMapEnvDataSkyV46> sky;
  std::shared_ptr<PackMapEnvDataSkyCardsV46> sky_cards;
  std::vector<std::shared_ptr<PackMapEnvDataWaterV46>> water;
  std::vector<std::shared_ptr<PackMapEnvDataWindV46>> wind;
  pf::wstring name;
  std::vector<pf::byte> night_mods;
  pf::float3 center;
  pf::float2 z_range;
  float fade_horiz_inner;
  float fade_horiz_outer;
  float fade_vertical;
  pf::byte type;
  std::vector<pf::float2> vertex_array;
  pf::qword guid;
};

struct PackMapEnvDataSkyModeTexV46 {
  pf::filename tex_path_ne;
  pf::filename tex_path_sw;
  pf::filename tex_path_t;
};

struct PackMapEnvDataGlobalV46 {
  std::vector<PackMapEnvDataLightingV46> lighting;
  std::vector<PackMapEnvDataLightingCharV17> lighting_char;
  std::shared_ptr<PackMapEnvDataCloudsV46> clouds;
  std::vector<std::shared_ptr<PackMapEnvDataColoredLightRingsV17>>
      colored_light_rings;
  std::vector<std::shared_ptr<PackMapEnvDataEffectV46>> effect;
  std::vector<std::shared_ptr<PackMapEnvDataHazeV46>> haze;
  std::vector<std::shared_ptr<PackMapEnvDataPFieldV46>> particle_fields;
  std::vector<PackMapEnvDataPFieldCutoutV17> particle_field_cutouts;
  std::shared_ptr<PackMapEnvDataSkyV46> sky;
  std::shared_ptr<PackMapEnvDataSkyCardsV46> sky_cards;
  std::vector<std::shared_ptr<PackMapEnvDataWaterV46>> water;
  std::vector<std::shared_ptr<PackMapEnvDataWindV46>> wind;
  pf::wstring name;
  std::vector<pf::byte> night_mods;
  std::vector<PackMapEnvDataSkyModeTexV46> sky_mode_tex;
  pf::filename star_file;
};

struct PackMapEnvironmentV46 {
  std::vector<PackMapEnvDataLocalV46> data_local_array;
  std::shared_ptr<PackMapEnvDataGlobalV46> data_global;
};
} // namespace mapc::env::v46

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::env::v46::PackMapEnvDataLightV46 &value) {
  reader(value.color);
  reader(value.intensity);
  reader(value.direction);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v46::PackMapEnvDataLightingV46 &value) {
  reader(value.lights);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v46::PackMapEnvDataLightingCharV17 &value) {
  reader(value.sun_scale);
  reader(value.saturation);
  reader(value.sun_fill);
  reader(value.amb_scale);
  reader(value.amb_fill);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v46::PackMapEnvDataLayerAttributesV46 &value) {
  reader(value.brightness);
  reader(value.density);
  reader(value.haze);
  reader(value.light_intensity);
  reader(value.velocity);
  reader(value.fade_width);
  reader(value.fade_end);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v46::PackMapEnvDataLayerV46 &value) {
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
void Read(Reader &reader, mapc::env::v46::PackMapEnvDataCloudsV46 &value) {
  reader(value.layers);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v46::PackMapEnvDataColoredLightRingsV17 &value) {
  reader(value.range);
  reader(value.colors);
  reader(value.distances);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v46::PackMapEnvDataEffectV46 &value) {
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
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v46::PackMapEnvDataHazeV46 &value) {
  reader(value.dist_color);
  reader(value.dist_range);
  reader(value.height_color);
  reader(value.height_range);
  reader(value.depth_cue);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v46::PackMapEnvDataPFieldV46 &value) {
  reader(value.altitude);
  reader(value.angle);
  reader(value.depth);
  reader(value.deviation);
  reader(value.extent);
  reader(value.fade);
  reader(value.field_direction);
  reader(value.flags);
  reader(value.opacity);
  reader(value.particle_count);
  reader(value.rotation);
  reader(value.scale_x);
  reader(value.scale_y);
  reader(value.speed);
  reader(value.tex_col_row);
  reader(value.tex_fps);
  reader(value.tex_path);
  reader(value.type);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v46::PackMapEnvDataPFieldCutoutV17 &value) {
  reader(value.name);
  reader(value.x);
  reader(value.y);
  reader(value.z);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v46::PackMapEnvDataSkyV46 &value) {
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
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v46::PackMapEnvDataSkyCardAttributesV46 &value) {
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
void Read(Reader &reader, mapc::env::v46::PackMapEnvDataSkyCardV46 &value) {
  reader(value.day);
  reader(value.night);
  reader(value.flags);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v46::PackMapEnvDataSkyCardsV46 &value) {
  reader(value.cards);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v46::PackMapEnvDataWaterV46 &value) {
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
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v46::PackMapEnvDataWindV46 &value) {
  reader(value.azimuth);
  reader(value.elevation);
  reader(value.noise);
  reader(value.speed);
  reader(value.gust);
  reader(value.gust_freq);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v46::PackMapEnvDataLocalV46 &value) {
  reader(value.lighting);
  reader(value.lighting_char);
  reader(value.clouds);
  reader(value.colored_light_rings);
  reader(value.effect);
  reader(value.haze);
  reader(value.particle_fields);
  reader(value.particle_field_cutouts);
  reader(value.sky);
  reader(value.sky_cards);
  reader(value.water);
  reader(value.wind);
  reader(value.name);
  reader(value.night_mods);
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
void Read(Reader &reader, mapc::env::v46::PackMapEnvDataSkyModeTexV46 &value) {
  reader(value.tex_path_ne);
  reader(value.tex_path_sw);
  reader(value.tex_path_t);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v46::PackMapEnvDataGlobalV46 &value) {
  reader(value.lighting);
  reader(value.lighting_char);
  reader(value.clouds);
  reader(value.colored_light_rings);
  reader(value.effect);
  reader(value.haze);
  reader(value.particle_fields);
  reader(value.particle_field_cutouts);
  reader(value.sky);
  reader(value.sky_cards);
  reader(value.water);
  reader(value.wind);
  reader(value.name);
  reader(value.night_mods);
  reader(value.sky_mode_tex);
  reader(value.star_file);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v46::PackMapEnvironmentV46 &value) {
  reader(value.data_local_array);
  reader(value.data_global);
}
} // namespace de

} // namespace pf

#endif
