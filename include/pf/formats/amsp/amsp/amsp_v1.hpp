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

#if AMSP_AMSP_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace AMSP::AMSP::v1 {
struct EnvelopePointDataV1 {
  float offset;
  float value;
};

struct EnvelopeDataV1 {
  std::vector<EnvelopePointDataV1> envelope_point;
  pf::byte offset_type;
  pf::qword offset_parameter;
};

struct RangeDataV1 {
  float max;
  float min;
  pf::byte min2;
};

struct RandomParamDataV1 {
  RangeDataV1 time;
  RangeDataV1 value;
};

struct DynamicParamDataV1 {
  std::shared_ptr<EnvelopeDataV1> envelope_data;
  std::shared_ptr<RandomParamDataV1> random_param_data;
  pf::byte type;
  float value;
};

struct AttenuationDataV1 {
  float cone_inside_angle;
  float cone_outside_angle;
  float cone_outside_volume;
  DynamicParamDataV1 low_pass;
  DynamicParamDataV1 pan3_d;
  DynamicParamDataV1 spread3_d;
  DynamicParamDataV1 volume_a;
};

struct CategoryDataV1 {
  std::shared_ptr<AttenuationDataV1> attenuation;
  pf::dword flags;
  pf::dword max_audible;
  pf::byte max_audible_behavior;
  float mute_fade_time;
  pf::qword name;
  float volume_a;
  float volume_a_threshold;
  float volume_b;
  float volume_b_threshold;
  float volume_change_rate;
  float volume_ducking;
  float volume_ducking_time_attack;
  float volume_ducking_time_release;
  pf::qword volume_group_name;
};

struct VolumeGroupDataV1 {
  pf::dword flags;
  pf::qword name;
  pf::qword parent_name;
  float volume;
};

struct AudioSettingsDataV1 {
  std::vector<CategoryDataV1> category;
  float distance_scale;
  pf::filename voice_bank_file_name;
  std::vector<VolumeGroupDataV1> volume_group;
};

struct HandlerDataV1 {
  std::vector<pf::byte> byte_code;
  pf::dword flags;
  pf::qword name;
};

struct DspDataV1 {
  std::vector<DynamicParamDataV1> param;
  pf::byte type;
};

struct FileNameDataV1 {
  pf::byte audio_type;
  pf::filename file_name;
  pf::qword language;
  float weight;
};

struct MetaSoundDataV1 {
  std::shared_ptr<AttenuationDataV1> attenuation;
  pf::qword category;
  pf::byte channel_mode;
  pf::byte channel_priority;
  DynamicParamDataV1 depth;
  std::vector<DspDataV1> dsp;
  pf::qword end_cue;
  float end_cue_offset;
  float fade_in_time;
  float fade_out_time;
  pf::byte file_iterate_mode;
  std::vector<FileNameDataV1> file_name;
  pf::dword flags;
  RangeDataV1 initial_delay;
  pf::dword loop_count;
  pf::byte loop_mode;
  pf::qword name;
  DynamicParamDataV1 pan;
  DynamicParamDataV1 pitch;
  pf::byte playback_mode;
  RangeDataV1 play_length;
  pf::qword playlist_id;
  pf::byte position_mode;
  pf::float3 position_offset;
  RangeDataV1 position_offset_angle;
  RangeDataV1 position_range;
  RangeDataV1 repeat_count;
  RangeDataV1 repeat_time;
  RangeDataV1 start_time_offset;
  pf::byte repeat_time_from;
  DynamicParamDataV1 volume;
};

struct ScriptRefDataV1 {
  pf::filename file_name;
  pf::qword name;
};

struct TriggerMarkerDataV1 {
  pf::qword cue;
  pf::qword end;
  float time;
  pf::byte type;
};

struct TriggerKeyDataV1 {
  pf::qword name;
  std::vector<TriggerMarkerDataV1> trigger_marker;
};

struct ScriptFileDataV1 {
  std::shared_ptr<AudioSettingsDataV1> audio_settings;
  float fade_in_time;
  pf::dword flags;
  std::vector<HandlerDataV1> handler;
  std::vector<MetaSoundDataV1> meta_sound;
  std::vector<ScriptRefDataV1> script_ref;
  std::vector<TriggerKeyDataV1> trigger_key;
  float volume;
};
} // namespace AMSP::AMSP::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v1::EnvelopePointDataV1 &value) {
  reader(value.offset);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v1::EnvelopeDataV1 &value) {
  reader(value.envelope_point);
  reader(value.offset_type);
  reader(value.offset_parameter);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v1::RangeDataV1 &value) {
  reader(value.max);
  reader(value.min);
  reader(value.min2);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v1::RandomParamDataV1 &value) {
  reader(value.time);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v1::DynamicParamDataV1 &value) {
  reader(value.envelope_data);
  reader(value.random_param_data);
  reader(value.type);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v1::AttenuationDataV1 &value) {
  reader(value.cone_inside_angle);
  reader(value.cone_outside_angle);
  reader(value.cone_outside_volume);
  reader(value.low_pass);
  reader(value.pan3_d);
  reader(value.spread3_d);
  reader(value.volume_a);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v1::CategoryDataV1 &value) {
  reader(value.attenuation);
  reader(value.flags);
  reader(value.max_audible);
  reader(value.max_audible_behavior);
  reader(value.mute_fade_time);
  reader(value.name);
  reader(value.volume_a);
  reader(value.volume_a_threshold);
  reader(value.volume_b);
  reader(value.volume_b_threshold);
  reader(value.volume_change_rate);
  reader(value.volume_ducking);
  reader(value.volume_ducking_time_attack);
  reader(value.volume_ducking_time_release);
  reader(value.volume_group_name);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v1::VolumeGroupDataV1 &value) {
  reader(value.flags);
  reader(value.name);
  reader(value.parent_name);
  reader(value.volume);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v1::AudioSettingsDataV1 &value) {
  reader(value.category);
  reader(value.distance_scale);
  reader(value.voice_bank_file_name);
  reader(value.volume_group);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v1::HandlerDataV1 &value) {
  reader(value.byte_code);
  reader(value.flags);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v1::DspDataV1 &value) {
  reader(value.param);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v1::FileNameDataV1 &value) {
  reader(value.audio_type);
  reader(value.file_name);
  reader(value.language);
  reader(value.weight);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v1::MetaSoundDataV1 &value) {
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
void Read(Reader &reader, AMSP::AMSP::v1::ScriptRefDataV1 &value) {
  reader(value.file_name);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v1::TriggerMarkerDataV1 &value) {
  reader(value.cue);
  reader(value.end);
  reader(value.time);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v1::TriggerKeyDataV1 &value) {
  reader(value.name);
  reader(value.trigger_marker);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v1::ScriptFileDataV1 &value) {
  reader(value.audio_settings);
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
