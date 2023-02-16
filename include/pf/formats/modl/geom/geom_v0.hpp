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

#if MODL_GEOM_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace MODL::GEOM::v0 {
struct ModelMeshMorphVertV65 {
  pf::word index;
  pf::float3 vector;
};

struct ModelMeshMorphTargetV65 {
  std::vector<ModelMeshMorphVertV65> positions;
  std::vector<ModelMeshMorphVertV65> normals;
  pf::qword mesh;
};

struct GrBoundData {
  pf::float3 center;
  pf::float3 box_extent;
  float sphere_radius;
};

struct ModelMeshVertexDataV0 {
  pf::dword vertex_count;
  PackVertexType mesh;
};

struct ModelMeshIndexDataV0 {
  std::vector<pf::word> indices;
};

struct ModelMeshGeometryV0 {
  ModelMeshVertexDataV0 verts;
  ModelMeshIndexDataV0 indices;
  std::vector<ModelMeshIndexDataV0> lods;
};

struct ModelMeshDataV65 {
  pf::qword vis_bone;
  std::vector<ModelMeshMorphTargetV65> morph_targets;
  pf::dword flags;
  std::vector<pf::dword> seam_vert_indices;
  pf::qword mesh_name;
  pf::float3 min_bound;
  pf::float3 max_bound;
  std::vector<GrBoundData> bounds;
  pf::dword material_index;
  pf::cstring material_name;
  std::vector<pf::cstring> bone_names;
  std::shared_ptr<ModelMeshGeometryV0> geometry;
};

struct ModelFileGeometryV0 {
  std::vector<std::shared_ptr<ModelMeshDataV65>> meshes;
};
} // namespace MODL::GEOM::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::GEOM::v0::ModelMeshMorphVertV65 &value) {
  reader(value.index);
  reader(value.vector);
}

template <typename Reader>
void Read(Reader &reader, MODL::GEOM::v0::ModelMeshMorphTargetV65 &value) {
  reader(value.positions);
  reader(value.normals);
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::GEOM::v0::GrBoundData &value) {
  reader(value.center);
  reader(value.box_extent);
  reader(value.sphere_radius);
}

template <typename Reader>
void Read(Reader &reader, MODL::GEOM::v0::ModelMeshVertexDataV0 &value) {
  reader(value.vertex_count);
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::GEOM::v0::ModelMeshIndexDataV0 &value) {
  reader(value.indices);
}

template <typename Reader>
void Read(Reader &reader, MODL::GEOM::v0::ModelMeshGeometryV0 &value) {
  reader(value.verts);
  reader(value.indices);
  reader(value.lods);
}

template <typename Reader>
void Read(Reader &reader, MODL::GEOM::v0::ModelMeshDataV65 &value) {
  reader(value.vis_bone);
  reader(value.morph_targets);
  reader(value.flags);
  reader(value.seam_vert_indices);
  reader(value.mesh_name);
  reader(value.min_bound);
  reader(value.max_bound);
  reader(value.bounds);
  reader(value.material_index);
  reader(value.material_name);
  reader(value.bone_names);
  reader(value.geometry);
}

template <typename Reader>
void Read(Reader &reader, MODL::GEOM::v0::ModelFileGeometryV0 &value) {
  reader(value.meshes);
}
} // namespace de

} // namespace pf

#endif
