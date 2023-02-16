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

#if AMSP_AMSP_MIN_VERSION <= 5

#include "pf/types.hpp"

namespace pf {
namespace AMSP::AMSP::v5 {
struct EnvelopePointDataV5 {
  float offset;
  float value;
};

struct EnvelopeDataV5 {
  pf::qword offset_parameter;
  std::vector<EnvelopePointDataV5> envelope_point;
  pf::byte offset_type;
};

struct RangeDataV5 {
  float max;
  float min;
  pf::byte min2;
};

struct RandomParamDataV5 {
  RangeDataV5 time;
  RangeDataV5 value;
};

struct DynamicParamDataV5 {
  std::shared_ptr<EnvelopeDataV5> envelope_data;
  std::shared_ptr<RandomParamDataV5> random_param_data;
  float value;
  pf::byte type;
};

struct AttenuationDataV5 {
  float cone_inside_angle;
  float cone_outside_angle;
  float cone_outside_volume;
  DynamicParamDataV5 low_pass;
  DynamicParamDataV5 pan3_d;
  DynamicParamDataV5 spread3_d;
  DynamicParamDataV5 volume_a;
};

struct CategoryDataV5 {
  pf::qword name;
  pf::qword volume_group_name;
  std::shared_ptr<AttenuationDataV5> attenuation;
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

struct DspDataV5 {
  pf::dword type;
  pf::dword flags;
  std::vector<float> property;
};

struct BussDataV5 {
  pf::qword name;
  pf::qword output;
  pf::dword flags;
  std::vector<DspDataV5> dsp;
  float volume;
};

struct SnapshotDataV5 {
  pf::qword name;
  float blend_in_time;
  float blend_out_time;
  pf::dword flags;
  std::vector<BussDataV5> buss;
};

struct AudioSettingsDataV5 {
  pf::qword default_buss;
  pf::qword effects_buss;
  float distance_scale;
  std::vector<CategoryDataV5> category;
  std::vector<SnapshotDataV5> snapshot;
  pf::filename bank_index_file_name;
  pf::filename bank_script_file_name;
};

struct HandlerDataV5 {
  pf::qword name;
  pf::dword flags;
  std::vector<pf::byte> byte_code;
};

struct FileNameDataV5 {
  pf::qword language;
  float weight;
  pf::filename file_name;
  pf::byte audio_type;
};

struct MetaSoundDataV5 {
  pf::qword category;
  pf::qword end_cue;
  pf::qword name;
  pf::qword playlist_id;
  std::vector<DspDataV5> dsp;
  std::shared_ptr<AttenuationDataV5> attenuation;
  std::vector<FileNameDataV5> file_name;
  float end_cue_offset;
  float fade_in_time;
  float fade_out_time;
  pf::float3 position_offset;
  pf::dword flags;
  pf::dword loop_count;
  DynamicParamDataV5 depth;
  DynamicParamDataV5 pan;
  DynamicParamDataV5 pitch;
  DynamicParamDataV5 pitch_ms;
  DynamicParamDataV5 volume;
  DynamicParamDataV5 volume_ms;
  RangeDataV5 initial_delay;
  RangeDataV5 play_length;
  RangeDataV5 position_offset_angle;
  RangeDataV5 position_range;
  RangeDataV5 repeat_count;
  RangeDataV5 repeat_time;
  RangeDataV5 start_time_offset;
  pf::byte channel_mode;
  pf::byte channel_priority;
  pf::byte file_iterate_mode;
  pf::byte loop_mode;
  pf::byte playback_mode;
  pf::byte position_mode;
  pf::byte repeat_time_from;
};

struct ScriptRefDataV5 {
  pf::qword name;
  pf::filename file_name;
};

struct TriggerMarkerDataV5 {
  pf::qword cue;
  pf::qword end;
  float time;
  pf::byte type;
};

struct TriggerKeyDataV5 {
  pf::qword name;
  std::vector<TriggerMarkerDataV5> trigger_marker;
};

struct ScriptFileDataV5 {
  pf::qword music_cue;
  pf::qword end_cue;
  std::shared_ptr<AudioSettingsDataV5> audio_settings;
  std::vector<HandlerDataV5> handler;
  std::vector<MetaSoundDataV5> meta_sound;
  std::vector<ScriptRefDataV5> script_ref;
  std::vector<TriggerKeyDataV5> trigger_key;
  pf::dword flags;
  float fade_in_time;
  float volume;
};
} // namespace AMSP::AMSP::v5

namespace de {
template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v5::EnvelopePointDataV5 &value) {
  reader(value.offset);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v5::EnvelopeDataV5 &value) {
  reader(value.offset_parameter);
  reader(value.envelope_point);
  reader(value.offset_type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v5::RangeDataV5 &value) {
  reader(value.max);
  reader(value.min);
  reader(value.min2);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v5::RandomParamDataV5 &value) {
  reader(value.time);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v5::DynamicParamDataV5 &value) {
  reader(value.envelope_data);
  reader(value.random_param_data);
  reader(value.value);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v5::AttenuationDataV5 &value) {
  reader(value.cone_inside_angle);
  reader(value.cone_outside_angle);
  reader(value.cone_outside_volume);
  reader(value.low_pass);
  reader(value.pan3_d);
  reader(value.spread3_d);
  reader(value.volume_a);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v5::CategoryDataV5 &value) {
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
void Read(Reader &reader, AMSP::AMSP::v5::DspDataV5 &value) {
  reader(value.type);
  reader(value.flags);
  reader(value.property);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v5::BussDataV5 &value) {
  reader(value.name);
  reader(value.output);
  reader(value.flags);
  reader(value.dsp);
  reader(value.volume);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v5::SnapshotDataV5 &value) {
  reader(value.name);
  reader(value.blend_in_time);
  reader(value.blend_out_time);
  reader(value.flags);
  reader(value.buss);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v5::AudioSettingsDataV5 &value) {
  reader(value.default_buss);
  reader(value.effects_buss);
  reader(value.distance_scale);
  reader(value.category);
  reader(value.snapshot);
  reader(value.bank_index_file_name);
  reader(value.bank_script_file_name);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v5::HandlerDataV5 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.byte_code);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v5::FileNameDataV5 &value) {
  reader(value.language);
  reader(value.weight);
  reader(value.file_name);
  reader(value.audio_type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v5::MetaSoundDataV5 &value) {
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
void Read(Reader &reader, AMSP::AMSP::v5::ScriptRefDataV5 &value) {
  reader(value.name);
  reader(value.file_name);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v5::TriggerMarkerDataV5 &value) {
  reader(value.cue);
  reader(value.end);
  reader(value.time);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v5::TriggerKeyDataV5 &value) {
  reader(value.name);
  reader(value.trigger_marker);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v5::ScriptFileDataV5 &value) {
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
