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

#if MAPC_ENV_MIN_VERSION <= 34

#include "pf/types.hpp"

namespace pf {
namespace mapc::env::v34 {
struct PackMapEnvDataLightV34 {
  pf::byte3 color;
  float intensity;
  pf::float3 direction;
};

struct PackMapEnvDataLightingV34 {
  std::vector<std::shared_ptr<PackMapEnvDataLightV34>> lights;
};

struct PackMapEnvDataLayerAttributesV34 {
  float density;
  float haze;
  float light_intensity;
  pf::float2 velocity;
};

struct PackMapEnvDataLayerV34 {
  float altitude;
  float cut_out;
  float depth;
  float scale;
  pf::filename texture;
  std::vector<PackMapEnvDataLayerAttributesV34> attributes;
  pf::wstring name;
};

struct PackMapEnvDataCloudsV34 {
  std::vector<PackMapEnvDataLayerV34> layers;
};

struct PackMapEnvDataEffectV34 {
  pf::byte4 glow;
  pf::byte4 tint_color;
  pf::byte4 tint_target_color;
  float saturation;
  float tint_amount;
  float tint_focus;
  pf::byte4 glow_level;
  float glow_amplify;
};

struct PackMapEnvDataHazeV34 {
  pf::byte4 dist_color;
  pf::float2 dist_range;
  pf::byte4 height_color;
  pf::float2 height_range;
  float depth_cue;
};

struct PackMapEnvDataPFieldV34 {
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

struct PackMapEnvDataSkyV34 {
  pf::byte flags;
  float day_haze_bottom;
  float day_haze_density;
  float day_haze_falloff;
  float day_light_intensity;
  float day_star_density;
  float night_haze_bottom;
  float night_haze_density;
  float night_haze_falloff;
  float night_light_intensity;
  float night_star_density;
};

struct PackMapEnvDataSkyCardAttributesV34 {
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
};

struct PackMapEnvDataSkyCardV34 {
  PackMapEnvDataSkyCardAttributesV34 day;
  PackMapEnvDataSkyCardAttributesV34 night;
  pf::wstring name;
};

struct PackMapEnvDataSkyCardsV34 {
  std::vector<PackMapEnvDataSkyCardV34> cards;
};

struct PackMapEnvDataWaterV34 {
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
  pf::filename bump_texture;
  pf::filename pattern_texture;
};

struct PackMapEnvDataWindV34 {
  pf::byte azimuth;
  pf::byte elevation;
  pf::byte noise;
  pf::byte speed;
  pf::byte gust;
  pf::byte gust_freq;
};

struct PackMapEnvDataLocalV34 {
  std::vector<PackMapEnvDataLightingV34> lighting;
  std::shared_ptr<PackMapEnvDataCloudsV34> clouds;
  std::vector<std::shared_ptr<PackMapEnvDataEffectV34>> effect;
  std::vector<std::shared_ptr<PackMapEnvDataHazeV34>> haze;
  std::vector<std::shared_ptr<PackMapEnvDataPFieldV34>> particle_fields;
  std::shared_ptr<PackMapEnvDataSkyV34> sky;
  std::shared_ptr<PackMapEnvDataSkyCardsV34> sky_cards;
  std::vector<std::shared_ptr<PackMapEnvDataWaterV34>> water;
  std::vector<std::shared_ptr<PackMapEnvDataWindV34>> wind;
  pf::wstring name;
  pf::float3 center;
  pf::float2 z_range;
  float fade_horiz_inner;
  float fade_horiz_outer;
  float fade_vertical;
  pf::byte type;
  std::vector<pf::float2> vertex_array;
};

struct PackMapEnvDataSkyModeTexV34 {
  pf::filename tex_path_ne;
  pf::filename tex_path_sw;
  pf::filename tex_path_t;
};

struct PackMapEnvDataGlobalV34 {
  std::vector<PackMapEnvDataLightingV34> lighting;
  std::shared_ptr<PackMapEnvDataCloudsV34> clouds;
  std::vector<std::shared_ptr<PackMapEnvDataEffectV34>> effect;
  std::vector<std::shared_ptr<PackMapEnvDataHazeV34>> haze;
  std::vector<std::shared_ptr<PackMapEnvDataPFieldV34>> particle_fields;
  std::shared_ptr<PackMapEnvDataSkyV34> sky;
  std::shared_ptr<PackMapEnvDataSkyCardsV34> sky_cards;
  std::vector<std::shared_ptr<PackMapEnvDataWaterV34>> water;
  std::vector<std::shared_ptr<PackMapEnvDataWindV34>> wind;
  pf::wstring name;
  std::vector<PackMapEnvDataSkyModeTexV34> sky_mode_tex;
  pf::filename star_file;
};

struct PackMapEnvironmentV34 {
  std::vector<PackMapEnvDataLocalV34> data_local_array;
  std::shared_ptr<PackMapEnvDataGlobalV34> data_global;
};
} // namespace mapc::env::v34

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::env::v34::PackMapEnvDataLightV34 &value) {
  reader(value.color);
  reader(value.intensity);
  reader(value.direction);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v34::PackMapEnvDataLightingV34 &value) {
  reader(value.lights);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v34::PackMapEnvDataLayerAttributesV34 &value) {
  reader(value.density);
  reader(value.haze);
  reader(value.light_intensity);
  reader(value.velocity);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v34::PackMapEnvDataLayerV34 &value) {
  reader(value.altitude);
  reader(value.cut_out);
  reader(value.depth);
  reader(value.scale);
  reader(value.texture);
  reader(value.attributes);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v34::PackMapEnvDataCloudsV34 &value) {
  reader(value.layers);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v34::PackMapEnvDataEffectV34 &value) {
  reader(value.glow);
  reader(value.tint_color);
  reader(value.tint_target_color);
  reader(value.saturation);
  reader(value.tint_amount);
  reader(value.tint_focus);
  reader(value.glow_level);
  reader(value.glow_amplify);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v34::PackMapEnvDataHazeV34 &value) {
  reader(value.dist_color);
  reader(value.dist_range);
  reader(value.height_color);
  reader(value.height_range);
  reader(value.depth_cue);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v34::PackMapEnvDataPFieldV34 &value) {
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
void Read(Reader &reader, mapc::env::v34::PackMapEnvDataSkyV34 &value) {
  reader(value.flags);
  reader(value.day_haze_bottom);
  reader(value.day_haze_density);
  reader(value.day_haze_falloff);
  reader(value.day_light_intensity);
  reader(value.day_star_density);
  reader(value.night_haze_bottom);
  reader(value.night_haze_density);
  reader(value.night_haze_falloff);
  reader(value.night_light_intensity);
  reader(value.night_star_density);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::env::v34::PackMapEnvDataSkyCardAttributesV34 &value) {
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
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v34::PackMapEnvDataSkyCardV34 &value) {
  reader(value.day);
  reader(value.night);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v34::PackMapEnvDataSkyCardsV34 &value) {
  reader(value.cards);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v34::PackMapEnvDataWaterV34 &value) {
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
  reader(value.bump_texture);
  reader(value.pattern_texture);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v34::PackMapEnvDataWindV34 &value) {
  reader(value.azimuth);
  reader(value.elevation);
  reader(value.noise);
  reader(value.speed);
  reader(value.gust);
  reader(value.gust_freq);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v34::PackMapEnvDataLocalV34 &value) {
  reader(value.lighting);
  reader(value.clouds);
  reader(value.effect);
  reader(value.haze);
  reader(value.particle_fields);
  reader(value.sky);
  reader(value.sky_cards);
  reader(value.water);
  reader(value.wind);
  reader(value.name);
  reader(value.center);
  reader(value.z_range);
  reader(value.fade_horiz_inner);
  reader(value.fade_horiz_outer);
  reader(value.fade_vertical);
  reader(value.type);
  reader(value.vertex_array);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v34::PackMapEnvDataSkyModeTexV34 &value) {
  reader(value.tex_path_ne);
  reader(value.tex_path_sw);
  reader(value.tex_path_t);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v34::PackMapEnvDataGlobalV34 &value) {
  reader(value.lighting);
  reader(value.clouds);
  reader(value.effect);
  reader(value.haze);
  reader(value.particle_fields);
  reader(value.sky);
  reader(value.sky_cards);
  reader(value.water);
  reader(value.wind);
  reader(value.name);
  reader(value.sky_mode_tex);
  reader(value.star_file);
}

template <typename Reader>
void Read(Reader &reader, mapc::env::v34::PackMapEnvironmentV34 &value) {
  reader(value.data_local_array);
  reader(value.data_global);
}
} // namespace de

} // namespace pf

#endif
