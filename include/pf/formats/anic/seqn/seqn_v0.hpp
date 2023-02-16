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

#if ANIC_SEQN_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace anic::seqn::v0 {
struct PackAnimSequenceChargeStageV0 {
  pf::word duration;
  pf::byte ending_charge_level;
};

struct PackAnimSequenceStepActionV0 {
  pf::dword duration;
};

struct PackAnimSequenceStepMoveV0 {
  pf::dword duration;
  pf::float4 move_rotation;
  pf::float4 facing_rotation;
  pf::float2 velocity;
};

struct PackAnimSequenceStepV0 {
  pf::byte type;
  float animation_speed;
  pf::dword flags;
  std::shared_ptr<PackAnimSequenceStepActionV0> action;
  std::shared_ptr<PackAnimSequenceStepMoveV0> move;
};

struct PackAnimSequenceTriggerV0 {
  pf::byte trigger;
  pf::dword time;
  pf::dword flags;
};

struct PackAnimSequenceDataV0 {
  pf::qword token;
  pf::dword flags;
  float blend_in_time;
  float blend_out_time;
  std::vector<PackAnimSequenceChargeStageV0> charge_stages;
  std::vector<PackAnimSequenceStepV0> steps;
  std::vector<PackAnimSequenceTriggerV0> triggers;
};

struct PackAnimSequenceV0 {
  pf::qword sequence;
  std::vector<PackAnimSequenceDataV0> animation_data;
};

struct PackAnimSequencesV0 {
  std::vector<PackAnimSequenceV0> sequences;
};
} // namespace anic::seqn::v0

namespace de {
template <typename Reader>
void Read(Reader &reader,
          anic::seqn::v0::PackAnimSequenceChargeStageV0 &value) {
  reader(value.duration);
  reader(value.ending_charge_level);
}

template <typename Reader>
void Read(Reader &reader, anic::seqn::v0::PackAnimSequenceStepActionV0 &value) {
  reader(value.duration);
}

template <typename Reader>
void Read(Reader &reader, anic::seqn::v0::PackAnimSequenceStepMoveV0 &value) {
  reader(value.duration);
  reader(value.move_rotation);
  reader(value.facing_rotation);
  reader(value.velocity);
}

template <typename Reader>
void Read(Reader &reader, anic::seqn::v0::PackAnimSequenceStepV0 &value) {
  reader(value.type);
  reader(value.animation_speed);
  reader(value.flags);
  reader(value.action);
  reader(value.move);
}

template <typename Reader>
void Read(Reader &reader, anic::seqn::v0::PackAnimSequenceTriggerV0 &value) {
  reader(value.trigger);
  reader(value.time);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader, anic::seqn::v0::PackAnimSequenceDataV0 &value) {
  reader(value.token);
  reader(value.flags);
  reader(value.blend_in_time);
  reader(value.blend_out_time);
  reader(value.charge_stages);
  reader(value.steps);
  reader(value.triggers);
}

template <typename Reader>
void Read(Reader &reader, anic::seqn::v0::PackAnimSequenceV0 &value) {
  reader(value.sequence);
  reader(value.animation_data);
}

template <typename Reader>
void Read(Reader &reader, anic::seqn::v0::PackAnimSequencesV0 &value) {
  reader(value.sequences);
}
} // namespace de

} // namespace pf

#endif
