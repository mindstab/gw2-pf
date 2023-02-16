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

#if MODL_COLL_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace MODL::COLL::v1 {
struct ModelCollisionMeshV1 {
  std::vector<pf::qword> animation_sequences;
  std::vector<pf::float3> vertices;
  std::vector<pf::word> indices;
  std::vector<pf::byte> surfaces;
};

struct ModelCollisionCloudV1 {
  pf::qword animation_sequence;
  std::vector<pf::float3> points;
  pf::byte surface;
};

struct ModelCollisionCubeV1 {
  std::array<pf::float4, 3> transform;
  pf::byte surface;
};

struct ModelCollisionSphereV1 {
  float radius;
  pf::float3 position;
  pf::byte surface;
};

struct ModelCollisionSurfaceV1 {
  std::vector<pf::qword> tokens;
};

struct ModelFileCollisionV1 {
  std::vector<ModelCollisionMeshV1> meshes;
  std::vector<ModelCollisionCloudV1> clouds;
  std::vector<ModelCollisionCubeV1> cubes;
  std::vector<ModelCollisionSphereV1> spheres;
  std::vector<ModelCollisionSurfaceV1> surfaces;
};
} // namespace MODL::COLL::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::COLL::v1::ModelCollisionMeshV1 &value) {
  reader(value.animation_sequences);
  reader(value.vertices);
  reader(value.indices);
  reader(value.surfaces);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v1::ModelCollisionCloudV1 &value) {
  reader(value.animation_sequence);
  reader(value.points);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v1::ModelCollisionCubeV1 &value) {
  reader(value.transform);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v1::ModelCollisionSphereV1 &value) {
  reader(value.radius);
  reader(value.position);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v1::ModelCollisionSurfaceV1 &value) {
  reader(value.tokens);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v1::ModelFileCollisionV1 &value) {
  reader(value.meshes);
  reader(value.clouds);
  reader(value.cubes);
  reader(value.spheres);
  reader(value.surfaces);
}
} // namespace de

} // namespace pf

#endif
