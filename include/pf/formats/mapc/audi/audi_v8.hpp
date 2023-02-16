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

#if MAPC_AUDI_MIN_VERSION <= 8

#include "pf/types.hpp"

namespace pf {
namespace mapc::audi::v8 {
struct PackMapAudioRegion {
  pf::dword region_type;
  pf::dword override_mode;
  pf::filename filename_source_day;
  pf::filename filename_ambient_day;
  pf::filename filename_source_night;
  pf::filename filename_ambient_night;
  pf::filename filename_interior;
  float exterior_volume;
  pf::dword priority;
  std::vector<pf::float3> points;
  pf::float3 position;
  pf::float3 orientation;
  float fade_band;
  float height;
  float radius;
  pf::qword guid;
  pf::dword flags;
};

struct PackMapAudioRegionTool {
  pf::wstring annotation;
};

struct PackMapAudioDep {
  pf::filename dependency;
  pf::dword flags;
};

struct MapAudio {
  pf::filename filename_ambient_day_surface;
  pf::filename filename_ambient_day_underwater;
  pf::filename filename_ambient_night_surface;
  pf::filename filename_ambient_night_underwater;
  std::vector<PackMapAudioRegion> audio_regions;
  std::vector<PackMapAudioRegionTool> audio_region_tools;
  std::vector<PackMapAudioDep> audio_dep_array;
};
} // namespace mapc::audi::v8

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::audi::v8::PackMapAudioRegion &value) {
  reader(value.region_type);
  reader(value.override_mode);
  reader(value.filename_source_day);
  reader(value.filename_ambient_day);
  reader(value.filename_source_night);
  reader(value.filename_ambient_night);
  reader(value.filename_interior);
  reader(value.exterior_volume);
  reader(value.priority);
  reader(value.points);
  reader(value.position);
  reader(value.orientation);
  reader(value.fade_band);
  reader(value.height);
  reader(value.radius);
  reader(value.guid);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader, mapc::audi::v8::PackMapAudioRegionTool &value) {
  reader(value.annotation);
}

template <typename Reader>
void Read(Reader &reader, mapc::audi::v8::PackMapAudioDep &value) {
  reader(value.dependency);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader, mapc::audi::v8::MapAudio &value) {
  reader(value.filename_ambient_day_surface);
  reader(value.filename_ambient_day_underwater);
  reader(value.filename_ambient_night_surface);
  reader(value.filename_ambient_night_underwater);
  reader(value.audio_regions);
  reader(value.audio_region_tools);
  reader(value.audio_dep_array);
}
} // namespace de

} // namespace pf

#endif
