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

#if AMSP_AMSP_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace AMSP::AMSP::v0 {
struct HandlerDataV0 {
  std::vector<pf::byte> byte_code;
  pf::dword flags;
  pf::qword name;
};

struct EnvelopePointDataV0 {
  float offset;
  float value;
};

struct EnvelopeDataV0 {
  std::vector<EnvelopePointDataV0> envelope_point;
  pf::byte offset_type;
  pf::qword offset_parameter;
};

struct RangeDataV0 {
  float max;
  float min;
  pf::byte min2;
};

struct RandomParamDataV0 {
  RangeDataV0 time;
  RangeDataV0 value;
};

struct DynamicParamDataV0 {
  std::shared_ptr<EnvelopeDataV0> envelope_data;
  std::shared_ptr<RandomParamDataV0> random_param_data;
  pf::byte type;
  float value;
};

struct AttenuationDataV0 {
  float cone_inside_angle;
  float cone_outside_angle;
  float cone_outside_volume;
  DynamicParamDataV0 low_pass;
  DynamicParamDataV0 pan3_d;
  DynamicParamDataV0 spread3_d;
  DynamicParamDataV0 volume_a;
};

struct DspDataV0 {
  std::vector<DynamicParamDataV0> param;
  pf::byte type;
};

struct FileNameDataV0 {
  pf::byte audio_type;
  pf::filename file_name;
  pf::qword language;
  float weight;
};

struct MetaSoundDataV0 {
  std::shared_ptr<AttenuationDataV0> attenuation;
  pf::qword category;
  pf::byte channel_mode;
  pf::byte channel_priority;
  DynamicParamDataV0 depth;
  std::vector<DspDataV0> dsp;
  pf::qword end_cue;
  float end_cue_offset;
  float fade_in_time;
  float fade_out_time;
  pf::byte file_iterate_mode;
  std::vector<FileNameDataV0> file_name;
  pf::dword flags;
  RangeDataV0 initial_delay;
  pf::dword loop_count;
  pf::byte loop_mode;
  pf::qword name;
  DynamicParamDataV0 pan;
  DynamicParamDataV0 pitch;
  pf::byte playback_mode;
  RangeDataV0 play_length;
  pf::qword playlist_id;
  pf::byte position_mode;
  pf::float3 position_offset;
  RangeDataV0 position_offset_angle;
  RangeDataV0 position_range;
  RangeDataV0 repeat_count;
  RangeDataV0 repeat_time;
  RangeDataV0 start_time_offset;
  pf::byte repeat_time_from;
  DynamicParamDataV0 volume;
};

struct ScriptRefDataV0 {
  pf::filename file_name;
  pf::qword name;
};

struct TriggerMarkerDataV0 {
  pf::qword cue;
  pf::qword end;
  float time;
  pf::byte type;
};

struct TriggerKeyDataV0 {
  pf::qword name;
  std::vector<TriggerMarkerDataV0> trigger_marker;
};

struct ScriptFileDataV0 {
  float fade_in_time;
  pf::dword flags;
  std::vector<HandlerDataV0> handler;
  std::vector<MetaSoundDataV0> meta_sound;
  std::vector<ScriptRefDataV0> script_ref;
  std::vector<TriggerKeyDataV0> trigger_key;
  float volume;
};
} // namespace AMSP::AMSP::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v0::HandlerDataV0 &value) {
  reader(value.byte_code);
  reader(value.flags);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v0::EnvelopePointDataV0 &value) {
  reader(value.offset);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v0::EnvelopeDataV0 &value) {
  reader(value.envelope_point);
  reader(value.offset_type);
  reader(value.offset_parameter);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v0::RangeDataV0 &value) {
  reader(value.max);
  reader(value.min);
  reader(value.min2);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v0::RandomParamDataV0 &value) {
  reader(value.time);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v0::DynamicParamDataV0 &value) {
  reader(value.envelope_data);
  reader(value.random_param_data);
  reader(value.type);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v0::AttenuationDataV0 &value) {
  reader(value.cone_inside_angle);
  reader(value.cone_outside_angle);
  reader(value.cone_outside_volume);
  reader(value.low_pass);
  reader(value.pan3_d);
  reader(value.spread3_d);
  reader(value.volume_a);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v0::DspDataV0 &value) {
  reader(value.param);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v0::FileNameDataV0 &value) {
  reader(value.audio_type);
  reader(value.file_name);
  reader(value.language);
  reader(value.weight);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v0::MetaSoundDataV0 &value) {
  reader(value.attenuation);
  reader(value.category);
  reader(value.channel_mode);
  reader(value.channel_priority);
  reader(value.depth);
  reader(value.dsp);
  reader(value.end_cue);
  reader(value.end_cue_offset);
  reader(value.fade_in_time);
  reader(value.fade_out_time);
  reader(value.file_iterate_mode);
  reader(value.file_name);
  reader(value.flags);
  reader(value.initial_delay);
  reader(value.loop_count);
  reader(value.loop_mode);
  reader(value.name);
  reader(value.pan);
  reader(value.pitch);
  reader(value.playback_mode);
  reader(value.play_length);
  reader(value.playlist_id);
  reader(value.position_mode);
  reader(value.position_offset);
  reader(value.position_offset_angle);
  reader(value.position_range);
  reader(value.repeat_count);
  reader(value.repeat_time);
  reader(value.start_time_offset);
  reader(value.repeat_time_from);
  reader(value.volume);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v0::ScriptRefDataV0 &value) {
  reader(value.file_name);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v0::TriggerMarkerDataV0 &value) {
  reader(value.cue);
  reader(value.end);
  reader(value.time);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v0::TriggerKeyDataV0 &value) {
  reader(value.name);
  reader(value.trigger_marker);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v0::ScriptFileDataV0 &value) {
  reader(value.fade_in_time);
  reader(value.flags);
  reader(value.handler);
  reader(value.meta_sound);
  reader(value.script_ref);
  reader(value.trigger_key);
  reader(value.volume);
}
} // namespace de

} // namespace pf

#endif
