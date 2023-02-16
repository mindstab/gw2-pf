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

#if ANIC_CNFG_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace anic::cnfg::v0 {
struct PackAnimAimIKBoneV0 {
  pf::qword bone_token;
  float clamp_angle;
  float weight;
  float smoothing_weight;
};

struct PackAnimAimIKConfigV0 {
  pf::qword name;
  pf::qword bone_eye;
  pf::qword bone_sight;
  pf::qword end_effector;
  float frustum_h_angle;
  float frustum_v_angle;
  float frustum_length;
  float target_velocity_constraint;
  std::vector<PackAnimAimIKBoneV0> bones;
  std::vector<pf::qword> targets;
  pf::byte flags;
};

struct PackAnimIKRaycastTargetV0 {
  pf::dword flags;
  pf::float3 direction;
};

struct PackAnimIKChainV0 {
  pf::qword name;
  pf::float3 smooth_weight;
  float hyper_extension_start;
  float hyper_extension_scale;
  std::vector<pf::qword> bones;
  std::shared_ptr<PackAnimIKRaycastTargetV0> target_raycast_info;
  pf::byte target_mode;
  pf::byte chain_type;
};

struct PackAnimIKChainGroupV0 {
  pf::qword name;
  std::vector<PackAnimIKChainV0> chains;
};

struct PackAnimConfigV0 {
  std::vector<PackAnimAimIKConfigV0> aim_ik_configs;
  std::vector<PackAnimIKChainGroupV0> chain_groups;
};
} // namespace anic::cnfg::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, anic::cnfg::v0::PackAnimAimIKBoneV0 &value) {
  reader(value.bone_token);
  reader(value.clamp_angle);
  reader(value.weight);
  reader(value.smoothing_weight);
}

template <typename Reader>
void Read(Reader &reader, anic::cnfg::v0::PackAnimAimIKConfigV0 &value) {
  reader(value.name);
  reader(value.bone_eye);
  reader(value.bone_sight);
  reader(value.end_effector);
  reader(value.frustum_h_angle);
  reader(value.frustum_v_angle);
  reader(value.frustum_length);
  reader(value.target_velocity_constraint);
  reader(value.bones);
  reader(value.targets);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader, anic::cnfg::v0::PackAnimIKRaycastTargetV0 &value) {
  reader(value.flags);
  reader(value.direction);
}

template <typename Reader>
void Read(Reader &reader, anic::cnfg::v0::PackAnimIKChainV0 &value) {
  reader(value.name);
  reader(value.smooth_weight);
  reader(value.hyper_extension_start);
  reader(value.hyper_extension_scale);
  reader(value.bones);
  reader(value.target_raycast_info);
  reader(value.target_mode);
  reader(value.chain_type);
}

template <typename Reader>
void Read(Reader &reader, anic::cnfg::v0::PackAnimIKChainGroupV0 &value) {
  reader(value.name);
  reader(value.chains);
}

template <typename Reader>
void Read(Reader &reader, anic::cnfg::v0::PackAnimConfigV0 &value) {
  reader(value.aim_ik_configs);
  reader(value.chain_groups);
}
} // namespace de

} // namespace pf

#endif
