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

#if MAPC_EDIT_MIN_VERSION <= 14

#include "pf/types.hpp"

namespace pf {
namespace mapc::edit::v14 {
struct MapEditLayerItem {
  pf::qword guid;
  pf::dword module_id;
  std::vector<pf::dword> layer_flags;
};

struct MapEditLayers {
  std::vector<pf::byte> layer_states;
  std::vector<pf::wstring> layer_names;
  std::vector<pf::dword> layer_ids;
  std::vector<MapEditLayerItem> items;
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

struct PackMapEditSurfacePoly {
  pf::wstring name;
  pf::dword surface_type;
  std::vector<pf::float2> vertices;
  pf::float2 range;
};

struct PackMapEditSurfaceRoadNode {
  pf::float3 position;
  float radius;
};

struct PackMapEditSurfaceRoad {
  pf::wstring name;
  pf::dword surface_type;
  std::vector<PackMapEditSurfaceRoadNode> nodes;
};

struct PackMapEditNavMeshData {
  std::vector<PackMapEditDirtyChunks> flood_points;
  std::vector<PackMapEditSurfacePoly> surface_polys;
  std::vector<PackMapEditSurfaceRoad> surface_roads;
};

struct MapEditSnapPoint {
  pf::qword guid;
  pf::dword module_id;
  pf::dword flags;
  pf::float3 position;
  pf::float3 rotation;
  float scale;
};

struct MapEditData {
  MapEditLayers layers;
  PackMapEditAnnotations annotations;
  std::vector<PackMapEditDirtyChunks> dirty_chunks;
  std::vector<MapEditCamLocations> cam_locations;
  PackMapEditNavMeshData nav_mesh_data;
  std::vector<MapEditSnapPoint> snap_points;
  pf::wstring map_home;
  pf::byte home_save;
  pf::wstring reserved;
};
} // namespace mapc::edit::v14

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::edit::v14::MapEditLayerItem &value) {
  reader(value.guid);
  reader(value.module_id);
  reader(value.layer_flags);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v14::MapEditLayers &value) {
  reader(value.layer_states);
  reader(value.layer_names);
  reader(value.layer_ids);
  reader(value.items);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v14::PackMapEditAnnotation &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.anchors);
  reader(value.z_range);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v14::PackMapEditAnnotations &value) {
  reader(value.annotations);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v14::PackMapEditDirtyChunks &value) {
  reader(value.dirty_flags);
  reader(value.chunk_coord);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v14::MapEditCamLocations &value) {
  reader(value.attack);
  reader(value.rotation);
  reader(value.position);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v14::PackMapEditSurfacePoly &value) {
  reader(value.name);
  reader(value.surface_type);
  reader(value.vertices);
  reader(value.range);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v14::PackMapEditSurfaceRoadNode &value) {
  reader(value.position);
  reader(value.radius);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v14::PackMapEditSurfaceRoad &value) {
  reader(value.name);
  reader(value.surface_type);
  reader(value.nodes);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v14::PackMapEditNavMeshData &value) {
  reader(value.flood_points);
  reader(value.surface_polys);
  reader(value.surface_roads);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v14::MapEditSnapPoint &value) {
  reader(value.guid);
  reader(value.module_id);
  reader(value.flags);
  reader(value.position);
  reader(value.rotation);
  reader(value.scale);
}

template <typename Reader>
void Read(Reader &reader, mapc::edit::v14::MapEditData &value) {
  reader(value.layers);
  reader(value.annotations);
  reader(value.dirty_chunks);
  reader(value.cam_locations);
  reader(value.nav_mesh_data);
  reader(value.snap_points);
  reader(value.map_home);
  reader(value.home_save);
  reader(value.reserved);
}
} // namespace de

} // namespace pf

#endif
