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

#if MODL_MODL_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace MODL::MODL::v0 {
struct ModelTextureDataV0 {
  pf::filename filename;
  pf::dword texture_flags;
  pf::qword token;
  pf::qword blit_id;
};

struct ModelConstantDataV0 {
  pf::dword name;
  pf::float4 value;
  pf::dword constant_flags;
};

struct ModelMaterialDataV0 {
  pf::filename filename;
  pf::dword material_flags;
  pf::dword sort_order;
  std::vector<ModelTextureDataV0> textures;
  std::vector<ModelConstantDataV0> constants;
};

struct ModelMeshDataV0 {
  PackGrannyMeshType mesh;
};

struct ModelAnimationDataV0 {
  pf::qword token;
  PackGrannyAnimationTypeV0 animation;
};

struct ModelTransformDataV0 {
  pf::dword flags;
  pf::float3 position;
  pf::float4 orientation;
  std::array<pf::float3, 3> scale_shear;
};

struct ModelBoneDataV0 {
  pf::cstring name;
  pf::dword parent_index;
  ModelTransformDataV0 local_transform;
  std::array<pf::float4, 4> inverse_world4x4;
  float lod_error;
  std::shared_ptr<pf::byte> extended_data_type;
  std::shared_ptr<pf::byte> extended_data_object;
};

struct ModelSkeletonDataV0 {
  pf::cstring name;
  std::vector<ModelBoneDataV0> bones;
  pf::dword lod_type;
};

struct ModelMeshBindingDataV0 {
  std::shared_ptr<pf::byte> mesh;
};

struct ModelModelDataV0 {
  pf::cstring name;
  std::shared_ptr<ModelSkeletonDataV0> skeleton;
  ModelTransformDataV0 initial_placement;
  std::vector<ModelMeshBindingDataV0> mesh_bindings;
};

struct ModelFloatPropertyDataV0 {
  pf::qword token;
  float value;
};

struct ModelPropertyDataV0 {
  std::vector<pf::qword> bool_tokens;
  std::vector<ModelFloatPropertyDataV0> float_values;
};

struct ModelFileDataV0 {
  std::vector<std::shared_ptr<ModelMaterialDataV0>> materials;
  std::vector<std::shared_ptr<ModelMeshDataV0>> meshes;
  std::vector<std::shared_ptr<ModelAnimationDataV0>> animations;
  std::shared_ptr<ModelModelDataV0> model;
  std::shared_ptr<ModelPropertyDataV0> properties;
};
} // namespace MODL::MODL::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, MODL::MODL::v0::ModelTextureDataV0 &value) {
  reader(value.filename);
  reader(value.texture_flags);
  reader(value.token);
  reader(value.blit_id);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v0::ModelConstantDataV0 &value) {
  reader(value.name);
  reader(value.value);
  reader(value.constant_flags);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v0::ModelMaterialDataV0 &value) {
  reader(value.filename);
  reader(value.material_flags);
  reader(value.sort_order);
  reader(value.textures);
  reader(value.constants);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v0::ModelMeshDataV0 &value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v0::ModelAnimationDataV0 &value) {
  reader(value.token);
  reader(value.animation);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v0::ModelTransformDataV0 &value) {
  reader(value.flags);
  reader(value.position);
  reader(value.orientation);
  reader(value.scale_shear);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v0::ModelBoneDataV0 &value) {
  reader(value.name);
  reader(value.parent_index);
  reader(value.local_transform);
  reader(value.inverse_world4x4);
  reader(value.lod_error);
  reader(value.extended_data_type);
  reader(value.extended_data_object);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v0::ModelSkeletonDataV0 &value) {
  reader(value.name);
  reader(value.bones);
  reader(value.lod_type);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v0::ModelMeshBindingDataV0 &value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v0::ModelModelDataV0 &value) {
  reader(value.name);
  reader(value.skeleton);
  reader(value.initial_placement);
  reader(value.mesh_bindings);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v0::ModelFloatPropertyDataV0 &value) {
  reader(value.token);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v0::ModelPropertyDataV0 &value) {
  reader(value.bool_tokens);
  reader(value.float_values);
}

template <typename Reader>
void Read(Reader &reader, MODL::MODL::v0::ModelFileDataV0 &value) {
  reader(value.materials);
  reader(value.meshes);
  reader(value.animations);
  reader(value.model);
  reader(value.properties);
}
} // namespace de

} // namespace pf

#endif
