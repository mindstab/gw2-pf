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

#if HVKC_HAVK_MIN_VERSION <= 6

#include "pf/types.hpp"

namespace pf {
namespace hvkC::havk::v6 {
struct PackMapCollideMoppCodeV6 {
  std::vector<pf::byte> cooked_data;
};

struct PackMapCollideMeshSizeV6 {
  float scale;
  pf::dword mopp_code_index;
};

struct PackMapCollideMeshV6 {
  std::vector<pf::word> indices;
  std::vector<pf::float3> vertices;
  std::vector<PackMapCollideMeshSizeV6> sizes;
};

struct PackMapCollideMeshRefV6 {
  pf::qword sequence;
  pf::dword mesh_index;
};

struct PackMapCollideGeometryV6 {
  std::vector<PackMapCollideMeshRefV6> mesh_refs;
};

struct PackMapCollideModelPropV6 {
  pf::qword token;
  pf::qword sequence;
  float scale;
  pf::float3 translate;
  pf::float3 rotate;
  pf::dword geometry_index;
};

struct PackMapCollideModelZoneV6 {
  float scale;
  pf::float3 translate;
  pf::float3 rotate;
  pf::dword geometry_index;
};

struct PackMapCollideV6 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  std::vector<PackMapCollideMoppCodeV6> mopp_codes;
  std::vector<PackMapCollideMeshV6> meshes;
  std::vector<PackMapCollideGeometryV6> geometries;
  std::vector<PackMapCollideModelPropV6> prop_models;
  std::vector<PackMapCollideModelZoneV6> zone_models;
};
} // namespace hvkC::havk::v6

namespace de {
template <typename Reader>
void Read(Reader &reader, hvkC::havk::v6::PackMapCollideMoppCodeV6 &value) {
  reader(value.cooked_data);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v6::PackMapCollideMeshSizeV6 &value) {
  reader(value.scale);
  reader(value.mopp_code_index);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v6::PackMapCollideMeshV6 &value) {
  reader(value.indices);
  reader(value.vertices);
  reader(value.sizes);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v6::PackMapCollideMeshRefV6 &value) {
  reader(value.sequence);
  reader(value.mesh_index);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v6::PackMapCollideGeometryV6 &value) {
  reader(value.mesh_refs);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v6::PackMapCollideModelPropV6 &value) {
  reader(value.token);
  reader(value.sequence);
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v6::PackMapCollideModelZoneV6 &value) {
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, hvkC::havk::v6::PackMapCollideV6 &value) {
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.mopp_codes);
  reader(value.meshes);
  reader(value.geometries);
  reader(value.prop_models);
  reader(value.zone_models);
}
} // namespace de

} // namespace pf

#endif
