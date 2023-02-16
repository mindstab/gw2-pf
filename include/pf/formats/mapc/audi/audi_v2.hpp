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

#if MAPC_AUDI_MIN_VERSION <= 2

#include "pf/types.hpp"

namespace pf {
namespace mapc::audi::v2 {
struct PackMapAudioRegion {
  pf::dword region_type;
  pf::dword override_mode;
  pf::filename filename_source;
  pf::filename filename_ambient;
  pf::filename filename_music;
  std::vector<pf::float3> points;
  pf::float3 position;
  pf::float3 orientation;
  float fade_band;
  float height;
  float radius;
};

struct MapAudio {
  pf::filename global_ambient_script_filename;
  pf::filename global_music_script_filename;
  pf::filename global_ambient_underwater_script_filename;
  pf::filename global_music_underwater_script_filename;
  std::vector<PackMapAudioRegion> audio_regions;
};
} // namespace mapc::audi::v2

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::audi::v2::PackMapAudioRegion &value) {
  reader(value.region_type);
  reader(value.override_mode);
  reader(value.filename_source);
  reader(value.filename_ambient);
  reader(value.filename_music);
  reader(value.points);
  reader(value.position);
  reader(value.orientation);
  reader(value.fade_band);
  reader(value.height);
  reader(value.radius);
}

template <typename Reader>
void Read(Reader &reader, mapc::audi::v2::MapAudio &value) {
  reader(value.global_ambient_script_filename);
  reader(value.global_music_script_filename);
  reader(value.global_ambient_underwater_script_filename);
  reader(value.global_music_underwater_script_filename);
  reader(value.audio_regions);
}
} // namespace de

} // namespace pf

#endif
