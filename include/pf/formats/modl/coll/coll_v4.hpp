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

#if MODL_COLL_MIN_VERSION <= 4

#include "pf/types.hpp"

namespace pf {
namespace MODL::COLL::v4 {
struct ModelCollisionKeyFrameV10 {
  float time;
  pf::float3 position;
  pf::float4 orientation;
};

struct ModelCollisionAnimatedObjectV10 {
  std::vector<pf::dword> shape_indices;
  std::vector<ModelCollisionKeyFrameV10> key_frames;
};

struct ModelCollisionAnimationV10 {
  pf::qword animation;
  std::vector<ModelCollisionAnimatedObjectV10> objects;
  std::vector<pf::float3> target_points;
};

struct ModelCollisionMeshV10 {
  std::vector<pf::float3> vertices;
  std::vector<pf::word> indices;
  std::vector<pf::byte> surfaces;
  std::vector<pf::float3> nav_seed_points;
};

struct ModelCollisionBoxV10 {
  pf::float3 dimensions;
  pf::float3 position;
  pf::float4 rotation;
  pf::byte surface;
};

struct ModelCollisionSphereV10 {
  float radius;
  pf::float3 position;
  pf::byte surface;
};

struct ModelCollisionCapsuleV10 {
  pf::float3 p0;
  pf::float3 p1;
  float radius;
  pf::byte surface;
};

struct ModelCollisionSurfaceV10 {
  std::vector<pf::qword> tokens;
};

struct ModelFileCollisionV10 {
  std::vector<ModelCollisionAnimationV10> animations;
  std::vector<ModelCollisionMeshV10> meshes;
  std::vector<ModelCollisionBoxV10> boxes;
  std::vector<ModelCollisionSphereV10> spheres;
  std::vector<ModelCollisionCapsuleV10> capsules;
  std::vector<ModelCollisionSurfaceV10> surfaces;
};
} // namespace MODL::COLL::v4

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::COLL::v4::ModelCollisionKeyFrameV10 &value) {
  reader(value.time);
  reader(value.position);
  reader(value.orientation);
}

template <typename Reader>
void Read(Reader &reader,
          MODL::COLL::v4::ModelCollisionAnimatedObjectV10 &value) {
  reader(value.shape_indices);
  reader(value.key_frames);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v4::ModelCollisionAnimationV10 &value) {
  reader(value.animation);
  reader(value.objects);
  reader(value.target_points);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v4::ModelCollisionMeshV10 &value) {
  reader(value.vertices);
  reader(value.indices);
  reader(value.surfaces);
  reader(value.nav_seed_points);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v4::ModelCollisionBoxV10 &value) {
  reader(value.dimensions);
  reader(value.position);
  reader(value.rotation);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v4::ModelCollisionSphereV10 &value) {
  reader(value.radius);
  reader(value.position);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v4::ModelCollisionCapsuleV10 &value) {
  reader(value.p0);
  reader(value.p1);
  reader(value.radius);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v4::ModelCollisionSurfaceV10 &value) {
  reader(value.tokens);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v4::ModelFileCollisionV10 &value) {
  reader(value.animations);
  reader(value.meshes);
  reader(value.boxes);
  reader(value.spheres);
  reader(value.capsules);
  reader(value.surfaces);
}
} // namespace de

} // namespace pf

#endif
