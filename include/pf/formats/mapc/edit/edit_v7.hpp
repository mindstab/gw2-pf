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

#if MAPC_EDIT_MIN_VERSION <= 7

#include "pf/types.hpp"

namespace pf {
namespace mapc::edit::v7 {
struct MapEditLayers {
  std::array<pf::dword, 31> layer_prop_count;
  std::array<pf::byte, 31> layer_states;
};

struct PackMapEditAnnotation {
  pf::wstring name;
  pf::dword flags;
  std::vector<pf::float2> anchors;
  pf::float2 z_range;
};

struct PackMapEditAnnotations {
  std::vector<PackMapEditAnnotation> annotations;
};

struct PackMapEditDirtyChunks {
  pf::dword dirty_flags;
  pf::dword2 chunk_coord;
};

struct MapEditCamLocations {
  float attack;
  float rotation;
  pf::float3 position;
  pf::wstring name;
};

struct MapEditData {
  MapEditLayers layers;
  PackMapEditAnnotations annotations;
  std::vector<PackMapEditDirtyChunks> dirty_chunks;
  std::vector<MapEditCamLocations> cam_locations;
  std::vector<PackMapEditDirtyChunks> flood_points;
};
} // namespace mapc::edit::v7

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::edit::v7::MapEditLayers &value) {
  reader(value.layer_prop_count);
  reader(value.layer_states);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v7::PackMapEditAnnotation &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.anchors);
  reader(value.z_range);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v7::PackMapEditAnnotations &value) {
  reader(value.annotations);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v7::PackMapEditDirtyChunks &value) {
  reader(value.dirty_flags);
  reader(value.chunk_coord);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v7::MapEditCamLocations &value) {
  reader(value.attack);
  reader(value.rotation);
  reader(value.position);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v7::MapEditData &value) {
  reader(value.layers);
  reader(value.annotations);
  reader(value.dirty_chunks);
  reader(value.cam_locations);
  reader(value.flood_points);
}
} // namespace de

} // namespace pf

#endif
