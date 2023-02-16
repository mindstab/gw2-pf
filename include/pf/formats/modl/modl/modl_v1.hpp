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

#if MODL_MODL_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace MODL::MODL::v1 {
struct ModelTextureDataV1 {
  pf::filename filename;
  pf::dword texture_flags;
  pf::qword token;
  pf::qword blit_id;
};

struct ModelConstantDataV1 {
  pf::dword name;
  pf::float4 value;
  pf::dword constant_flags;
};

struct ModelMaterialDataV1 {
  pf::filename filename;
  pf::dword material_flags;
  pf::dword sort_order;
  std::vector<ModelTextureDataV1> textures;
  std::vector<ModelConstantDataV1> constants;
};

struct ModelMeshDataV1 {
  PackGrannyMeshType mesh;
};

struct ModelAnimationDataV1 {
  pf::qword token;
  PackGrannyAnimationTypeV0 animation;
};

struct ModelTransformDataV1 {
  pf::dword flags;
  pf::float3 position;
  pf::float4 orientation;
  std::array<pf::float3, 3> scale_shear;
};

struct ModelBoneDataV1 {
  pf::cstring name;
  pf::dword parent_index;
  ModelTransformDataV1 local_transform;
  std::array<pf::float4, 4> inverse_world4x4;
  float lod_error;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
};

struct ModelSkeletonDataV1 {
  pf::cstring name;
  std::vector<ModelBoneDataV1> bones;
  pf::dword lod_type;
};

struct ModelMeshBindingDataV1 {
  std::shared_ptr<pf::byte> mesh;
};

struct ModelModelDataV1 {
  pf::cstring name;
  std::shared_ptr<ModelSkeletonDataV1> skeleton;
  ModelTransformDataV1 initial_placement;
  std::vector<ModelMeshBindingDataV1> mesh_bindings;
};

struct ModelFloatPropertyDataV1 {
  pf::qword token;
  float value;
};

struct ModelPropertyDataV1 {
  std::vector<pf::qword> bool_tokens;
  std::vector<ModelFloatPropertyDataV1> float_values;
};

struct ModelChunkCollisionMeshV1 {
  pf::qword animation_sequence;
  std::vector<pf::float3> vertices;
  std::vector<pf::word> indices;
  std::vector<pf::byte> surfaces;
};

struct ModelChunkCollisionCloudV1 {
  pf::qword animation_sequence;
  std::vector<pf::float3> points;
  pf::byte surface;
};

struct ModelChunkCollisionSurfaceV1 {
  std::vector<pf::qword> tokens;
};

struct ModelChunkCollisionDataV1 {
  std::vector<ModelChunkCollisionMeshV1> meshes;
  std::vector<ModelChunkCollisionCloudV1> clouds;
  std::vector<ModelChunkCollisionSurfaceV1> surfaces;
};

struct ModelFileDataV1 {
  std::vector<std::shared_ptr<ModelMaterialDataV1>> materials;
  std::vector<std::shared_ptr<ModelMeshDataV1>> meshes;
  std::vector<std::shared_ptr<ModelAnimationDataV1>> animations;
  std::shared_ptr<ModelModelDataV1> model;
  std::shared_ptr<ModelPropertyDataV1> properties;
  std::shared_ptr<ModelChunkCollisionDataV1> collision_data;
};
} // namespace MODL::MODL::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::MODL::v1::ModelTextureDataV1 &value) {
  reader(value.filename);
  reader(value.texture_flags);
  reader(value.token);
  reader(value.blit_id);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v1::ModelConstantDataV1 &value) {
  reader(value.name);
  reader(value.value);
  reader(value.constant_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v1::ModelMaterialDataV1 &value) {
  reader(value.filename);
  reader(value.material_flags);
  reader(value.sort_order);
  reader(value.textures);
  reader(value.constants);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v1::ModelMeshDataV1 &value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v1::ModelAnimationDataV1 &value) {
  reader(value.token);
  reader(value.animation);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v1::ModelTransformDataV1 &value) {
  reader(value.flags);
  reader(value.position);
  reader(value.orientation);
  reader(value.scale_shear);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v1::ModelBoneDataV1 &value) {
  reader(value.name);
  reader(value.parent_index);
  reader(value.local_transform);
  reader(value.inverse_world4x4);
  reader(value.lod_error);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v1::ModelSkeletonDataV1 &value) {
  reader(value.name);
  reader(value.bones);
  reader(value.lod_type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v1::ModelMeshBindingDataV1 &value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v1::ModelModelDataV1 &value) {
  reader(value.name);
  reader(value.skeleton);
  reader(value.initial_placement);
  reader(value.mesh_bindings);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v1::ModelFloatPropertyDataV1 &value) {
  reader(value.token);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v1::ModelPropertyDataV1 &value) {
  reader(value.bool_tokens);
  reader(value.float_values);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v1::ModelChunkCollisionMeshV1 &value) {
  reader(value.animation_sequence);
  reader(value.vertices);
  reader(value.indices);
  reader(value.surfaces);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v1::ModelChunkCollisionCloudV1 &value) {
  reader(value.animation_sequence);
  reader(value.points);
  reader(value.surface);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v1::ModelChunkCollisionSurfaceV1 &value) {
  reader(value.tokens);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v1::ModelChunkCollisionDataV1 &value) {
  reader(value.meshes);
  reader(value.clouds);
  reader(value.surfaces);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v1::ModelFileDataV1 &value) {
  reader(value.materials);
  reader(value.meshes);
  reader(value.animations);
  reader(value.model);
  reader(value.properties);
  reader(value.collision_data);
}
} // namespace de

} // namespace pf

#endif
