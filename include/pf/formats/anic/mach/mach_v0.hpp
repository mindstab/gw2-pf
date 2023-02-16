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

#if ANIC_MACH_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace anic::mach::v0 {
struct PackAnimMachineActionPlayAnimationV0 {
  pf::qword sequence;
  float blend_in_time;
  float blend_out_time;
  pf::dword flags;
};

struct PackAnimMachineActionPlayBlendTreeV0 {
  pf::uuid blend_tree;
  float blend_in_time;
};

struct PackAnimMachineActionPlayBlendTreeAliasV0 {
  pf::qword blend_tree_alias;
  float blend_in_time;
};

struct PackAnimMachineActionSetAnimationOptionsV0 {
  float blend_in_time;
  float blend_out_time;
  pf::dword flags;
};

struct PackAnimMachineActionSetRotationV0 {
  pf::float4 rotation;
};

struct PackAnimMachineActionV0 {
  std::variant<PackAnimMachineActionPlayAnimationV0,
               PackAnimMachineActionPlayBlendTreeV0,
               PackAnimMachineActionPlayBlendTreeAliasV0,
               PackAnimMachineActionSetAnimationOptionsV0,
               PackAnimMachineActionSetRotationV0>
      action_data;
};

struct PackAnimMachineActionBlockV0 {
  std::vector<PackAnimMachineActionV0> actions;
};

struct PackAnimMachineActionVariantV0 {
  pf::qword token;
  std::shared_ptr<PackAnimMachineActionBlockV0> action_block;
};

struct PackAnimMachineActionVariantBlockV0 {
  std::vector<PackAnimMachineActionVariantV0> action_variants;
};

struct PackAnimMachineTransitionVariantV0 {
  pf::qword token;
  std::shared_ptr<PackAnimMachineActionBlockV0> action_block;
};

struct PackAnimMachineTransitionV0 {
  pf::wstring name;
  pf::wstring target_state_name;
  std::shared_ptr<PackAnimMachineActionBlockV0> action_block;
  std::vector<PackAnimMachineTransitionVariantV0> variants;
};

struct PackAnimMachineStateVariantV0 {
  pf::qword token;
  std::shared_ptr<PackAnimMachineActionBlockV0> action_block;
  std::shared_ptr<PackAnimMachineActionVariantBlockV0> action_variant_block;
  std::vector<PackAnimMachineTransitionV0> transitions;
};

struct PackAnimMachineStateV0 {
  pf::wstring name;
  std::shared_ptr<PackAnimMachineActionBlockV0> action_block;
  std::shared_ptr<PackAnimMachineActionVariantBlockV0> action_variant_block;
  std::vector<PackAnimMachineTransitionV0> transitions;
  std::vector<PackAnimMachineStateVariantV0> variants;
};

struct PackAnimMachineV0 {
  std::vector<PackAnimMachineStateV0> states;
};

struct PackAnimModelV0 {
  pf::fileref model_file_id;
  pf::wstring model_file_raw;
  pf::dword machine_index;
};

struct PackAnimMachinesV0 {
  std::vector<PackAnimMachineV0> machines;
  std::vector<PackAnimModelV0> models;
};
} // namespace anic::mach::v0

namespace de {
template <typename Reader>
void Read(Reader &reader,
          anic::mach::v0::PackAnimMachineActionPlayAnimationV0 &value) {
  reader(value.sequence);
  reader(value.blend_in_time);
  reader(value.blend_out_time);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader,
          anic::mach::v0::PackAnimMachineActionPlayBlendTreeV0 &value) {
  reader(value.blend_tree);
  reader(value.blend_in_time);
}

template <typename Reader>
void Read(Reader &reader,
          anic::mach::v0::PackAnimMachineActionPlayBlendTreeAliasV0 &value) {
  reader(value.blend_tree_alias);
  reader(value.blend_in_time);
}

template <typename Reader>
void Read(Reader &reader,
          anic::mach::v0::PackAnimMachineActionSetAnimationOptionsV0 &value) {
  reader(value.blend_in_time);
  reader(value.blend_out_time);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader,
          anic::mach::v0::PackAnimMachineActionSetRotationV0 &value) {
  reader(value.rotation);
}

template <typename Reader>
void Read(Reader &reader, anic::mach::v0::PackAnimMachineActionV0 &value) {
  reader(value.action_data);
}

template <typename Reader>
void Read(Reader &reader, anic::mach::v0::PackAnimMachineActionBlockV0 &value) {
  reader(value.actions);
}

template <typename Reader>
void Read(Reader &reader,
          anic::mach::v0::PackAnimMachineActionVariantV0 &value) {
  reader(value.token);
  reader(value.action_block);
}

template <typename Reader>
void Read(Reader &reader,
          anic::mach::v0::PackAnimMachineActionVariantBlockV0 &value) {
  reader(value.action_variants);
}

template <typename Reader>
void Read(Reader &reader,
          anic::mach::v0::PackAnimMachineTransitionVariantV0 &value) {
  reader(value.token);
  reader(value.action_block);
}

template <typename Reader>
void Read(Reader &reader, anic::mach::v0::PackAnimMachineTransitionV0 &value) {
  reader(value.name);
  reader(value.target_state_name);
  reader(value.action_block);
  reader(value.variants);
}

template <typename Reader>
void Read(Reader &reader,
          anic::mach::v0::PackAnimMachineStateVariantV0 &value) {
  reader(value.token);
  reader(value.action_block);
  reader(value.action_variant_block);
  reader(value.transitions);
}

template <typename Reader>
void Read(Reader &reader, anic::mach::v0::PackAnimMachineStateV0 &value) {
  reader(value.name);
  reader(value.action_block);
  reader(value.action_variant_block);
  reader(value.transitions);
  reader(value.variants);
}

template <typename Reader>
void Read(Reader &reader, anic::mach::v0::PackAnimMachineV0 &value) {
  reader(value.states);
}

template <typename Reader>
void Read(Reader &reader, anic::mach::v0::PackAnimModelV0 &value) {
  reader(value.model_file_id);
  reader(value.model_file_raw);
  reader(value.machine_index);
}

template <typename Reader>
void Read(Reader &reader, anic::mach::v0::PackAnimMachinesV0 &value) {
  reader(value.machines);
  reader(value.models);
}
} // namespace de

} // namespace pf

#endif
