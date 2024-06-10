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

#if MAPC_LGHT_MIN_VERSION <= 19

#include "pf/types.hpp"

namespace pf {
namespace mapc::lght::v19 {
struct PackMapLight {
  pf::float3 position;
  pf::byte3 color;
  float intensity;
  float near_distance;
  float far_distance;
  pf::dword flags;
};

struct PackMapCurve {
  float gust;
  float gust_freq;
  float noise;
  float phase;
  float offset;
  float amplitude;
  pf::dword curve_type;
};

struct PackMapPointLightgroups {
  pf::qword guid;
  std::vector<PackMapLight> lights;
  std::vector<PackMapCurve> curves;
  pf::word broad_id;
};

struct PackMapPortalData {
  float fade_camera;
  float fade_light;
  float lighten;
  float darken;
};

struct PackMapPortalLight {
  pf::qword guid;
  std::vector<pf::float3> points;
  std::vector<PackMapPortalData> portal_data;
  pf::word broad_id;
};

struct PackMapSpotShadow {
  pf::filename shadow_filename;
};

struct PackMapSpotLod {
  float distance;
  pf::dword flags;
  pf::dword light_flags;
  pf::byte3 color;
  float intensity;
  float near_dist;
  float far_dist;
  float inner_angle;
  float outer_angle;
};

struct PackMapSpotLight {
  pf::float3 position;
  pf::byte3 color;
  float intensity;
  float near_distance;
  float far_distance;
  pf::dword flags;
  pf::float3 direction;
  pf::float3 up_direction;
  float inner_angle;
  float outer_angle;
  pf::filename texture_name;
  std::shared_ptr<PackMapSpotShadow> shadow_data;
  std::array<PackMapSpotLod, 2> lod_data;
};

struct PackMapSpotLightgroups {
  pf::qword guid;
  std::vector<PackMapSpotLight> lights;
  std::vector<PackMapCurve> curves;
  pf::word broad_id;
};

struct PackMapVolumeImage {
  pf::filename filename;
  pf::dword2 dims;
  pf::dword format;
  std::vector<pf::byte> image;
};

struct PackMapVolumeLight {
  pf::qword guid;
  pf::float3 position;
  pf::float3 extents;
  pf::float3 rotation;
  pf::float2 intensities;
  pf::float4 pack;
  pf::wstring name;
  std::vector<pf::float3> flood_points;
  pf::dword flags;
  std::vector<PackMapVolumeImage> images;
  pf::word broad_id;
};

struct PackMapLights {
  std::vector<PackMapPointLightgroups> point_lights;
  std::vector<PackMapPortalLight> portal_lights;
  std::vector<PackMapSpotLightgroups> spot_lights;
  std::vector<PackMapVolumeLight> volume_lights;
  PackBroadphaseType broad_phase;
  pf::word max_broad_id;
  pf::dword max_light_vs_constants;
};
} // namespace mapc::lght::v19

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::lght::v19::PackMapLight &value) {
  reader(value.position);
  reader(value.color);
  reader(value.intensity);
  reader(value.near_distance);
  reader(value.far_distance);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader, mapc::lght::v19::PackMapCurve &value) {
  reader(value.gust);
  reader(value.gust_freq);
  reader(value.noise);
  reader(value.phase);
  reader(value.offset);
  reader(value.amplitude);
  reader(value.curve_type);
}

template <typename Reader>
void Read(Reader &reader, mapc::lght::v19::PackMapPointLightgroups &value) {
  reader(value.guid);
  reader(value.lights);
  reader(value.curves);
  reader(value.broad_id);
}

template <typename Reader>
void Read(Reader &reader, mapc::lght::v19::PackMapPortalData &value) {
  reader(value.fade_camera);
  reader(value.fade_light);
  reader(value.lighten);
  reader(value.darken);
}

template <typename Reader>
void Read(Reader &reader, mapc::lght::v19::PackMapPortalLight &value) {
  reader(value.guid);
  reader(value.points);
  reader(value.portal_data);
  reader(value.broad_id);
}

template <typename Reader>
void Read(Reader &reader, mapc::lght::v19::PackMapSpotShadow &value) {
  reader(value.shadow_filename);
}

template <typename Reader>
void Read(Reader &reader, mapc::lght::v19::PackMapSpotLod &value) {
  reader(value.distance);
  reader(value.flags);
  reader(value.light_flags);
  reader(value.color);
  reader(value.intensity);
  reader(value.near_dist);
  reader(value.far_dist);
  reader(value.inner_angle);
  reader(value.outer_angle);
}

template <typename Reader>
void Read(Reader &reader, mapc::lght::v19::PackMapSpotLight &value) {
  reader(value.position);
  reader(value.color);
  reader(value.intensity);
  reader(value.near_distance);
  reader(value.far_distance);
  reader(value.flags);
  reader(value.direction);
  reader(value.up_direction);
  reader(value.inner_angle);
  reader(value.outer_angle);
  reader(value.texture_name);
  reader(value.shadow_data);
  reader(value.lod_data);
}

template <typename Reader>
void Read(Reader &reader, mapc::lght::v19::PackMapSpotLightgroups &value) {
  reader(value.guid);
  reader(value.lights);
  reader(value.curves);
  reader(value.broad_id);
}

template <typename Reader>
void Read(Reader &reader, mapc::lght::v19::PackMapVolumeImage &value) {
  reader(value.filename);
  reader(value.dims);
  reader(value.format);
  reader(value.image);
}

template <typename Reader>
void Read(Reader &reader, mapc::lght::v19::PackMapVolumeLight &value) {
  reader(value.guid);
  reader(value.position);
  reader(value.extents);
  reader(value.rotation);
  reader(value.intensities);
  reader(value.pack);
  reader(value.name);
  reader(value.flood_points);
  reader(value.flags);
  reader(value.images);
  reader(value.broad_id);
}

template <typename Reader>
void Read(Reader &reader, mapc::lght::v19::PackMapLights &value) {
  reader(value.point_lights);
  reader(value.portal_lights);
  reader(value.spot_lights);
  reader(value.volume_lights);
  reader(value.broad_phase);
  reader(value.max_broad_id);
  reader(value.max_light_vs_constants);
}
} // namespace de

} // namespace pf

#endif
