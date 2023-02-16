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

#if MODL_COLL_MIN_VERSION <= 2

#include "pf/types.hpp"

namespace pf {
namespace MODL::COLL::v2 {
struct ModelCollisionMeshV8 {
  std::vector<pf::qword> animation_sequences;
  std::vector<pf::float3> vertices;
  std::vector<pf::word> indices;
  std::vector<pf::byte> surfaces;
};

struct ModelCollisionCloudV8 {
  pf::qword animation_sequence;
  std::vector<pf::float3> points;
  pf::byte surface;
};

struct ModelCollisionCubeV8 {
  std::array<pf::float4, 3> transform;
  pf::byte surface;
};

struct ModelCollisionSphereV8 {
  float radius;
  pf::float3 position;
  pf::byte surface;
};

struct ModelCollisionCapsuleV8 {
  pf::float3 p0;
  pf::float3 p1;
  float radius;
  pf::byte surface;
};

struct ModelCollisionSurfaceV8 {
  std::vector<pf::qword> tokens;
};

struct ModelFileCollisionV8 {
  std::vector<ModelCollisionMeshV8> meshes;
  std::vector<ModelCollisionCloudV8> clouds;
  std::vector<ModelCollisionCubeV8> cubes;
  std::vector<ModelCollisionSphereV8> spheres;
  std::vector<ModelCollisionCapsuleV8> capsules;
  std::vector<ModelCollisionSurfaceV8> surfaces;
};
} // namespace MODL::COLL::v2

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::COLL::v2::ModelCollisionMeshV8 &value) {
  reader(value.animation_sequences);
  reader(value.vertices);
  reader(value.indices);
  reader(value.surfaces);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v2::ModelCollisionCloudV8 &value) {
  reader(value.animation_sequence);
  reader(value.points);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v2::ModelCollisionCubeV8 &value) {
  reader(value.transform);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v2::ModelCollisionSphereV8 &value) {
  reader(value.radius);
  reader(value.position);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v2::ModelCollisionCapsuleV8 &value) {
  reader(value.p0);
  reader(value.p1);
  reader(value.radius);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v2::ModelCollisionSurfaceV8 &value) {
  reader(value.tokens);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v2::ModelFileCollisionV8 &value) {
  reader(value.meshes);
  reader(value.clouds);
  reader(value.cubes);
  reader(value.spheres);
  reader(value.capsules);
  reader(value.surfaces);
}
} // namespace de

} // namespace pf

#endif
