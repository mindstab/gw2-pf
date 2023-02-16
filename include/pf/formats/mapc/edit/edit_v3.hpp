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

#if MAPC_EDIT_MIN_VERSION <= 3

#include "pf/types.hpp"

namespace pf {
namespace mapc::edit::v3 {
struct MapEditRegion {
  std::vector<pf::wstring> regions;
};

struct MapEditLayers {
  std::vector<pf::byte> layer_states;
};

struct PackMapEditAnnotation {
  pf::wstring name;
  pf::dword flags;
  std::vector<pf::float2> anchors;
};

struct PackMapEditAnnotations {
  std::vector<PackMapEditAnnotation> annotations;
};

struct MapEditCamLocations {
  float attack;
  float rotation;
  pf::float3 position;
  pf::wstring name;
};

struct MapEditData {
  MapEditRegion regions;
  MapEditRegion mini_map_params;
  MapEditLayers layers;
  PackMapEditAnnotations annotations;
  std::vector<MapEditCamLocations> cam_locations;
};
} // namespace mapc::edit::v3

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::edit::v3::MapEditRegion &value) {
  reader(value.regions);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v3::MapEditLayers &value) {
  reader(value.layer_states);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v3::PackMapEditAnnotation &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.anchors);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v3::PackMapEditAnnotations &value) {
  reader(value.annotations);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v3::MapEditCamLocations &value) {
  reader(value.attack);
  reader(value.rotation);
  reader(value.position);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v3::MapEditData &value) {
  reader(value.regions);
  reader(value.mini_map_params);
  reader(value.layers);
  reader(value.annotations);
  reader(value.cam_locations);
}
} // namespace de

} // namespace pf

#endif
