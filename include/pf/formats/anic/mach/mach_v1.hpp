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

#if ANIC_MACH_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace anic::mach::v1 {
struct PackAnimMachineActionPlayAnimationV1 {
  pf::qword sequence;
  float blend_in_time;
  float blend_out_time;
  pf::dword flags;
};

struct PackAnimMachineActionPlayBlendTreeV1 {
  pf::uuid blend_tree;
  float blend_in_time;
};

struct PackAnimMachineActionPlayBlendTreeAliasV1 {
  pf::qword blend_tree_alias;
  float blend_in_time;
};

struct PackAnimMachineActionSetAnimationOptionsV1 {
  float blend_in_time;
  float blend_out_time;
  pf::dword flags;
};

struct PackAnimMachineActionSetRotationV1 {
  pf::float4 rotation;
};

struct PackAnimMachineActionV1 {
  std::variant<PackAnimMachineActionPlayAnimationV1,
               PackAnimMachineActionPlayBlendTreeV1,
               PackAnimMachineActionPlayBlendTreeAliasV1,
               PackAnimMachineActionSetAnimationOptionsV1,
               PackAnimMachineActionSetRotationV1>
      action_data;
};

struct PackAnimMachineActionBlockV1 {
  std::vector<PackAnimMachineActionV1> actions;
};

struct PackAnimMachineActionVariantV1 {
  pf::qword token;
  std::shared_ptr<PackAnimMachineActionBlockV1> action_block;
};

struct PackAnimMachineActionVariantBlockV1 {
  std::vector<PackAnimMachineActionVariantV1> action_variants;
};

struct PackAnimMachineTransitionVariantV1 {
  pf::qword token;
  std::shared_ptr<PackAnimMachineActionBlockV1> action_block;
};

struct PackAnimMachineTransitionV1 {
  pf::wstring name;
  pf::wstring target_state_name;
  std::shared_ptr<PackAnimMachineActionBlockV1> action_block;
  std::vector<PackAnimMachineTransitionVariantV1> variants;
};

struct PackAnimMachineStateVariantV1 {
  pf::qword token;
  std::shared_ptr<PackAnimMachineActionBlockV1> action_block;
  std::shared_ptr<PackAnimMachineActionVariantBlockV1> action_variant_block;
  std::vector<PackAnimMachineTransitionV1> transitions;
};

struct PackAnimMachineStateV1 {
  pf::wstring name;
  std::shared_ptr<PackAnimMachineActionBlockV1> action_block;
  std::shared_ptr<PackAnimMachineActionVariantBlockV1> action_variant_block;
  std::vector<PackAnimMachineTransitionV1> transitions;
  std::vector<PackAnimMachineStateVariantV1> variants;
};

struct PackAnimMachineV1 {
  std::vector<PackAnimMachineStateV1> states;
};

struct PackAnimModelV1 {
  pf::fileref model_file_id;
  pf::wstring model_file_raw;
  pf::dword machine_index;
  pf::uuid listeners;
};

struct PackAnimMachinesV1 {
  std::vector<PackAnimMachineV1> machines;
  std::vector<PackAnimModelV1> models;
};
} // namespace anic::mach::v1

namespace de {
template <typename Reader>
void Read(Reader &reader,
          anic::mach::v1::PackAnimMachineActionPlayAnimationV1 &value) {
  reader(value.sequence);
  reader(value.blend_in_time);
  reader(value.blend_out_time);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader,
          anic::mach::v1::PackAnimMachineActionPlayBlendTreeV1 &value) {
  reader(value.blend_tree);
  reader(value.blend_in_time);
}

template <typename Reader>
void Read(Reader &reader,
          anic::mach::v1::PackAnimMachineActionPlayBlendTreeAliasV1 &value) {
  reader(value.blend_tree_alias);
  reader(value.blend_in_time);
}

template <typename Reader>
void Read(Reader &reader,
          anic::mach::v1::PackAnimMachineActionSetAnimationOptionsV1 &value) {
  reader(value.blend_in_time);
  reader(value.blend_out_time);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader,
          anic::mach::v1::PackAnimMachineActionSetRotationV1 &value) {
  reader(value.rotation);
}

template <typename Reader>
void Read(Reader &reader, anic::mach::v1::PackAnimMachineActionV1 &value) {
  reader(value.action_data);
}

template <typename Reader>
void Read(Reader &reader, anic::mach::v1::PackAnimMachineActionBlockV1 &value) {
  reader(value.actions);
}

template <typename Reader>
void Read(Reader &reader,
          anic::mach::v1::PackAnimMachineActionVariantV1 &value) {
  reader(value.token);
  reader(value.action_block);
}

template <typename Reader>
void Read(Reader &reader,
          anic::mach::v1::PackAnimMachineActionVariantBlockV1 &value) {
  reader(value.action_variants);
}

template <typename Reader>
void Read(Reader &reader,
          anic::mach::v1::PackAnimMachineTransitionVariantV1 &value) {
  reader(value.token);
  reader(value.action_block);
}

template <typename Reader>
void Read(Reader &reader, anic::mach::v1::PackAnimMachineTransitionV1 &value) {
  reader(value.name);
  reader(value.target_state_name);
  reader(value.action_block);
  reader(value.variants);
}

template <typename Reader>
void Read(Reader &reader,
          anic::mach::v1::PackAnimMachineStateVariantV1 &value) {
  reader(value.token);
  reader(value.action_block);
  reader(value.action_variant_block);
  reader(value.transitions);
}

template <typename Reader>
void Read(Reader &reader, anic::mach::v1::PackAnimMachineStateV1 &value) {
  reader(value.name);
  reader(value.action_block);
  reader(value.action_variant_block);
  reader(value.transitions);
  reader(value.variants);
}

template <typename Reader>
void Read(Reader &reader, anic::mach::v1::PackAnimMachineV1 &value) {
  reader(value.states);
}

template <typename Reader>
void Read(Reader &reader, anic::mach::v1::PackAnimModelV1 &value) {
  reader(value.model_file_id);
  reader(value.model_file_raw);
  reader(value.machine_index);
  reader(value.listeners);
}

template <typename Reader>
void Read(Reader &reader, anic::mach::v1::PackAnimMachinesV1 &value) {
  reader(value.machines);
  reader(value.models);
}
} // namespace de

} // namespace pf

#endif
