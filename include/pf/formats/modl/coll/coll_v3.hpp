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

#if MODL_COLL_MIN_VERSION <= 3

#include "pf/types.hpp"

namespace pf {
namespace MODL::COLL::v3 {
struct ModelCollisionKeyFrameV9 {
  float time;
  pf::float3 position;
  pf::float4 orientation;
};

struct ModelCollisionAnimatedObjectV9 {
  std::vector<pf::dword> shape_indices;
  std::vector<ModelCollisionKeyFrameV9> key_frames;
};

struct ModelCollisionAnimationV9 {
  pf::qword animation;
  std::vector<ModelCollisionAnimatedObjectV9> objects;
};

struct ModelCollisionMeshV9 {
  std::vector<pf::float3> vertices;
  std::vector<pf::word> indices;
  std::vector<pf::byte> surfaces;
};

struct ModelCollisionBoxV9 {
  pf::float3 dimensions;
  pf::float3 position;
  pf::float4 rotation;
  pf::byte surface;
};

struct ModelCollisionSphereV9 {
  float radius;
  pf::float3 position;
  pf::byte surface;
};

struct ModelCollisionCapsuleV9 {
  pf::float3 p0;
  pf::float3 p1;
  float radius;
  pf::byte surface;
};

struct ModelCollisionSurfaceV9 {
  std::vector<pf::qword> tokens;
};

struct ModelFileCollisionV9 {
  std::vector<ModelCollisionAnimationV9> animations;
  std::vector<ModelCollisionMeshV9> meshes;
  std::vector<ModelCollisionBoxV9> boxes;
  std::vector<ModelCollisionSphereV9> spheres;
  std::vector<ModelCollisionCapsuleV9> capsules;
  std::vector<ModelCollisionSurfaceV9> surfaces;
};
} // namespace MODL::COLL::v3

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::COLL::v3::ModelCollisionKeyFrameV9 &value) {
  reader(value.time);
  reader(value.position);
  reader(value.orientation);
}

template <typename Reader>
void Read(Reader &reader,
          MODL::COLL::v3::ModelCollisionAnimatedObjectV9 &value) {
  reader(value.shape_indices);
  reader(value.key_frames);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v3::ModelCollisionAnimationV9 &value) {
  reader(value.animation);
  reader(value.objects);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v3::ModelCollisionMeshV9 &value) {
  reader(value.vertices);
  reader(value.indices);
  reader(value.surfaces);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v3::ModelCollisionBoxV9 &value) {
  reader(value.dimensions);
  reader(value.position);
  reader(value.rotation);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v3::ModelCollisionSphereV9 &value) {
  reader(value.radius);
  reader(value.position);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v3::ModelCollisionCapsuleV9 &value) {
  reader(value.p0);
  reader(value.p1);
  reader(value.radius);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v3::ModelCollisionSurfaceV9 &value) {
  reader(value.tokens);
}

template <typename Reader>
void Read(Reader &reader, MODL::COLL::v3::ModelFileCollisionV9 &value) {
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
