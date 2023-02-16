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

#if AMSP_AMSP_MIN_VERSION <= 3

#include "pf/types.hpp"

namespace pf {
namespace AMSP::AMSP::v3 {
struct VolumeGroupDataV3 {
  pf::qword name;
  pf::qword parent_name;
  pf::dword flags;
  float volume;
};

struct EnvelopePointDataV3 {
  float offset;
  float value;
};

struct EnvelopeDataV3 {
  pf::qword offset_parameter;
  std::vector<EnvelopePointDataV3> envelope_point;
  pf::byte offset_type;
};

struct RangeDataV3 {
  float max;
  float min;
  pf::byte min2;
};

struct RandomParamDataV3 {
  RangeDataV3 time;
  RangeDataV3 value;
};

struct DynamicParamDataV3 {
  std::shared_ptr<EnvelopeDataV3> envelope_data;
  std::shared_ptr<RandomParamDataV3> random_param_data;
  float value;
  pf::byte type;
};

struct AttenuationDataV3 {
  float cone_inside_angle;
  float cone_outside_angle;
  float cone_outside_volume;
  DynamicParamDataV3 low_pass;
  DynamicParamDataV3 pan3_d;
  DynamicParamDataV3 spread3_d;
  DynamicParamDataV3 volume_a;
};

struct CategoryDataV3 {
  pf::qword name;
  pf::qword volume_group_name;
  std::shared_ptr<AttenuationDataV3> attenuation;
  float mute_fade_time;
  float volume_a;
  float volume_a_threshold;
  float volume_b;
  float volume_b_threshold;
  float volume_change_rate;
  float volume_ducking;
  float volume_ducking_time_attack;
  float volume_ducking_time_release;
  pf::dword flags;
  pf::dword max_audible;
  pf::byte max_audible_behavior;
};

struct AudioSettingsDataV3 {
  std::vector<VolumeGroupDataV3> volume_group;
  std::vector<CategoryDataV3> category;
  float distance_scale;
  pf::filename voice_bank_file_name;
};

struct HandlerDataV3 {
  pf::qword name;
  pf::dword flags;
  std::vector<pf::byte> byte_code;
};

struct DspDataV3 {
  std::vector<DynamicParamDataV3> param;
  pf::byte type;
};

struct FileNameDataV3 {
  pf::qword language;
  float weight;
  pf::filename file_name;
  pf::byte audio_type;
};

struct MetaSoundDataV3 {
  pf::qword category;
  pf::qword end_cue;
  pf::qword name;
  pf::qword playlist_id;
  std::vector<DspDataV3> dsp;
  std::shared_ptr<AttenuationDataV3> attenuation;
  std::vector<FileNameDataV3> file_name;
  float end_cue_offset;
  float fade_in_time;
  float fade_out_time;
  pf::float3 position_offset;
  pf::dword flags;
  pf::dword loop_count;
  DynamicParamDataV3 depth;
  DynamicParamDataV3 pan;
  DynamicParamDataV3 pitch;
  DynamicParamDataV3 pitch_ms;
  DynamicParamDataV3 volume;
  DynamicParamDataV3 volume_ms;
  RangeDataV3 initial_delay;
  RangeDataV3 play_length;
  RangeDataV3 position_offset_angle;
  RangeDataV3 position_range;
  RangeDataV3 repeat_count;
  RangeDataV3 repeat_time;
  RangeDataV3 start_time_offset;
  pf::byte channel_mode;
  pf::byte channel_priority;
  pf::byte file_iterate_mode;
  pf::byte loop_mode;
  pf::byte playback_mode;
  pf::byte position_mode;
  pf::byte repeat_time_from;
};

struct ScriptRefDataV3 {
  pf::qword name;
  pf::filename file_name;
};

struct TriggerMarkerDataV3 {
  pf::qword cue;
  pf::qword end;
  float time;
  pf::byte type;
};

struct TriggerKeyDataV3 {
  pf::qword name;
  std::vector<TriggerMarkerDataV3> trigger_marker;
};

struct ScriptFileDataV3 {
  pf::qword music_cue;
  pf::qword end_cue;
  std::shared_ptr<AudioSettingsDataV3> audio_settings;
  std::vector<HandlerDataV3> handler;
  std::vector<MetaSoundDataV3> meta_sound;
  std::vector<ScriptRefDataV3> script_ref;
  std::vector<TriggerKeyDataV3> trigger_key;
  pf::dword flags;
  float fade_in_time;
  float volume;
};
} // namespace AMSP::AMSP::v3

namespace de {
template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v3::VolumeGroupDataV3 &value) {
  reader(value.name);
  reader(value.parent_name);
  reader(value.flags);
  reader(value.volume);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v3::EnvelopePointDataV3 &value) {
  reader(value.offset);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v3::EnvelopeDataV3 &value) {
  reader(value.offset_parameter);
  reader(value.envelope_point);
  reader(value.offset_type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v3::RangeDataV3 &value) {
  reader(value.max);
  reader(value.min);
  reader(value.min2);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v3::RandomParamDataV3 &value) {
  reader(value.time);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v3::DynamicParamDataV3 &value) {
  reader(value.envelope_data);
  reader(value.random_param_data);
  reader(value.value);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v3::AttenuationDataV3 &value) {
  reader(value.cone_inside_angle);
  reader(value.cone_outside_angle);
  reader(value.cone_outside_volume);
  reader(value.low_pass);
  reader(value.pan3_d);
  reader(value.spread3_d);
  reader(value.volume_a);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v3::CategoryDataV3 &value) {
  reader(value.name);
  reader(value.volume_group_name);
  reader(value.attenuation);
  reader(value.mute_fade_time);
  reader(value.volume_a);
  reader(value.volume_a_threshold);
  reader(value.volume_b);
  reader(value.volume_b_threshold);
  reader(value.volume_change_rate);
  reader(value.volume_ducking);
  reader(value.volume_ducking_time_attack);
  reader(value.volume_ducking_time_release);
  reader(value.flags);
  reader(value.max_audible);
  reader(value.max_audible_behavior);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v3::AudioSettingsDataV3 &value) {
  reader(value.volume_group);
  reader(value.category);
  reader(value.distance_scale);
  reader(value.voice_bank_file_name);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v3::HandlerDataV3 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.byte_code);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v3::DspDataV3 &value) {
  reader(value.param);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v3::FileNameDataV3 &value) {
  reader(value.language);
  reader(value.weight);
  reader(value.file_name);
  reader(value.audio_type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v3::MetaSoundDataV3 &value) {
  reader(value.category);
  reader(value.end_cue);
  reader(value.name);
  reader(value.playlist_id);
  reader(value.dsp);
  reader(value.attenuation);
  reader(value.file_name);
  reader(value.end_cue_offset);
  reader(value.fade_in_time);
  reader(value.fade_out_time);
  reader(value.position_offset);
  reader(value.flags);
  reader(value.loop_count);
  reader(value.depth);
  reader(value.pan);
  reader(value.pitch);
  reader(value.pitch_ms);
  reader(value.volume);
  reader(value.volume_ms);
  reader(value.initial_delay);
  reader(value.play_length);
  reader(value.position_offset_angle);
  reader(value.position_range);
  reader(value.repeat_count);
  reader(value.repeat_time);
  reader(value.start_time_offset);
  reader(value.channel_mode);
  reader(value.channel_priority);
  reader(value.file_iterate_mode);
  reader(value.loop_mode);
  reader(value.playback_mode);
  reader(value.position_mode);
  reader(value.repeat_time_from);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v3::ScriptRefDataV3 &value) {
  reader(value.name);
  reader(value.file_name);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v3::TriggerMarkerDataV3 &value) {
  reader(value.cue);
  reader(value.end);
  reader(value.time);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v3::TriggerKeyDataV3 &value) {
  reader(value.name);
  reader(value.trigger_marker);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v3::ScriptFileDataV3 &value) {
  reader(value.music_cue);
  reader(value.end_cue);
  reader(value.audio_settings);
  reader(value.handler);
  reader(value.meta_sound);
  reader(value.script_ref);
  reader(value.trigger_key);
  reader(value.flags);
  reader(value.fade_in_time);
  reader(value.volume);
}
} // namespace de

} // namespace pf

#endif
