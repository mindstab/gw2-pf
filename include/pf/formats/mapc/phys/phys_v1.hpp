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

#if MAPC_PHYS_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace mapc::phys::v1 {
struct PackMapPhysicsShapeDataV1 {
  float scale;
  std::vector<pf::byte> game_data_ptr;
};

struct PackMapPhysicsGeometryV1 {
  std::vector<pf::dword> shape_data_index_array;
};

struct PackMapPhysicsModelPropV1 {
  pf::dword2 token;
  float scale;
  pf::float3 translate;
  pf::float3 rotate;
  pf::dword geometry_index;
};

struct PackMapPhysicsV1 {
  pf::float3 bounds_min;
  pf::float3 bounds_max;
  std::vector<PackMapPhysicsShapeDataV1> shape_array;
  std::vector<PackMapPhysicsGeometryV1> geometry_array;
  std::vector<PackMapPhysicsModelPropV1> prop_model_array;
};
} // namespace mapc::phys::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::phys::v1::PackMapPhysicsShapeDataV1 &value) {
  reader(value.scale);
  reader(value.game_data_ptr);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v1::PackMapPhysicsGeometryV1 &value) {
  reader(value.shape_data_index_array);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v1::PackMapPhysicsModelPropV1 &value) {
  reader(value.token);
  reader(value.scale);
  reader(value.translate);
  reader(value.rotate);
  reader(value.geometry_index);
}

template <typename Reader>
void Read(Reader &reader, mapc::phys::v1::PackMapPhysicsV1 &value) {
  reader(value.bounds_min);
  reader(value.bounds_max);
  reader(value.shape_array);
  reader(value.geometry_array);
  reader(value.prop_model_array);
}
} // namespace de

} // namespace pf

#endif
