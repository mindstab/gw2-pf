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

#if AMSP_AMSP_MIN_VERSION <= 8

#include "pf/types.hpp"

namespace pf {
namespace AMSP::AMSP::v8 {
struct DspDataV8 {
  pf::dword type;
  pf::dword flags;
  std::vector<float> property;
};

struct BussDynamicDataV8 {
  pf::qword name;
  pf::dword flags;
  float volume;
  std::vector<DspDataV8> dsp;
};

struct BussDataV8 {
  pf::qword name;
  pf::dword flags;
  pf::qword output;
  std::shared_ptr<BussDynamicDataV8> dynamic_data;
};

struct EnvelopePointDataV8 {
  float offset;
  float value;
};

struct EnvelopeDataV8 {
  pf::qword offset_parameter;
  std::vector<EnvelopePointDataV8> envelope_point;
  pf::byte offset_type;
};

struct RangeDataV8 {
  float max;
  float min;
  pf::byte min2;
};

struct RandomParamDataV8 {
  RangeDataV8 time;
  RangeDataV8 value;
};

struct DynamicParamDataV8 {
  std::shared_ptr<EnvelopeDataV8> envelope_data;
  std::shared_ptr<RandomParamDataV8> random_param_data;
  float value;
  pf::byte type;
};

struct AttenuationDataV8 {
  float cone_inside_angle;
  float cone_outside_angle;
  float cone_outside_volume;
  DynamicParamDataV8 low_pass;
  DynamicParamDataV8 pan3_d;
  DynamicParamDataV8 spread3_d;
  DynamicParamDataV8 volume_a;
  DynamicParamDataV8 volume_b;
};

struct CategoryDynamicDataV8 {
  pf::qword name;
  float volume;
  float non_focus_gain;
  float low_pass;
  float reverb_direct;
  float reverb_room;
  pf::dword flags;
};

struct CategoryDataV8 {
  pf::qword name;
  pf::qword volume_group_name;
  pf::qword output_buss_name;
  std::shared_ptr<AttenuationDataV8> attenuation;
  std::shared_ptr<CategoryDynamicDataV8> dynamic_data;
  float mute_fade_time;
  pf::dword flags;
  pf::dword max_audible;
  pf::byte max_audible_behavior;
};

struct ReverbDataV8 {
  pf::qword name;
  pf::dword flags;
  float room;
  float room_hf;
  float room_lf;
  float decay_time;
  float decay_hf_ratio;
  float reflections;
  float reflections_delay;
  float reverb;
  float reverb_delay;
  float reference_hf;
  float reference_lf;
  float diffusion;
  float density;
};

struct SnapshotDataV8 {
  pf::qword name;
  float blend_in_time;
  float blend_out_time;
  pf::dword flags;
  std::vector<BussDynamicDataV8> buss;
  std::vector<CategoryDynamicDataV8> category;
};

struct AudioSettingsDataV8 {
  pf::qword default_snapshot;
  pf::qword effects_buss;
  float distance_scale;
  float focus_transition;
  std::vector<BussDataV8> buss;
  std::vector<CategoryDataV8> category;
  std::vector<ReverbDataV8> reverb;
  std::vector<SnapshotDataV8> snapshot;
  pf::filename bank_index_file_name;
  pf::filename bank_script_file_name;
};

struct HandlerDataV8 {
  pf::qword name;
  pf::dword flags;
  std::vector<pf::byte> byte_code;
};

struct FileNameDataV8 {
  pf::qword language;
  float weight;
  pf::filename file_name;
  pf::byte audio_type;
};

struct MetaSoundDataV8 {
  pf::qword category;
  pf::qword end_cue;
  pf::qword name;
  pf::qword offset_bone;
  pf::qword playlist_id;
  std::vector<DspDataV8> dsp;
  std::shared_ptr<AttenuationDataV8> attenuation;
  std::vector<FileNameDataV8> file_name;
  float end_cue_offset;
  float fade_in_time;
  float fade_out_time;
  pf::float3 position_offset;
  pf::dword flags;
  pf::dword loop_count;
  DynamicParamDataV8 depth;
  DynamicParamDataV8 pan;
  DynamicParamDataV8 pitch;
  DynamicParamDataV8 pitch_ms;
  DynamicParamDataV8 volume;
  DynamicParamDataV8 volume_ms;
  RangeDataV8 initial_delay;
  RangeDataV8 play_length;
  RangeDataV8 position_offset_angle;
  RangeDataV8 position_range;
  RangeDataV8 repeat_count;
  RangeDataV8 repeat_time;
  RangeDataV8 start_time_offset;
  pf::byte channel_mode;
  pf::byte channel_priority;
  pf::byte file_iterate_mode;
  pf::byte loop_mode;
  pf::byte music_priority;
  pf::byte playback_mode;
  pf::byte position_mode;
  pf::byte repeat_time_from;
};

struct ScriptRefDataV8 {
  pf::qword name;
  pf::filename file_name;
};

struct TriggerMarkerDataV8 {
  pf::qword cue;
  pf::qword end;
  float time;
  pf::byte type;
};

struct TriggerKeyDataV8 {
  pf::qword name;
  std::vector<TriggerMarkerDataV8> trigger_marker;
};

struct ScriptFileDataV8 {
  pf::qword music_cue;
  pf::qword end_cue;
  std::shared_ptr<AudioSettingsDataV8> audio_settings;
  std::vector<HandlerDataV8> handler;
  std::vector<MetaSoundDataV8> meta_sound;
  std::vector<ScriptRefDataV8> script_ref;
  std::vector<TriggerKeyDataV8> trigger_key;
  pf::dword flags;
  float fade_in_time;
  float volume;
};
} // namespace AMSP::AMSP::v8

namespace de {
template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::DspDataV8 &value) {
  reader(value.type);
  reader(value.flags);
  reader(value.property);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::BussDynamicDataV8 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.volume);
  reader(value.dsp);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::BussDataV8 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.output);
  reader(value.dynamic_data);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::EnvelopePointDataV8 &value) {
  reader(value.offset);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::EnvelopeDataV8 &value) {
  reader(value.offset_parameter);
  reader(value.envelope_point);
  reader(value.offset_type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::RangeDataV8 &value) {
  reader(value.max);
  reader(value.min);
  reader(value.min2);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::RandomParamDataV8 &value) {
  reader(value.time);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::DynamicParamDataV8 &value) {
  reader(value.envelope_data);
  reader(value.random_param_data);
  reader(value.value);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::AttenuationDataV8 &value) {
  reader(value.cone_inside_angle);
  reader(value.cone_outside_angle);
  reader(value.cone_outside_volume);
  reader(value.low_pass);
  reader(value.pan3_d);
  reader(value.spread3_d);
  reader(value.volume_a);
  reader(value.volume_b);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::CategoryDynamicDataV8 &value) {
  reader(value.name);
  reader(value.volume);
  reader(value.non_focus_gain);
  reader(value.low_pass);
  reader(value.reverb_direct);
  reader(value.reverb_room);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::CategoryDataV8 &value) {
  reader(value.name);
  reader(value.volume_group_name);
  reader(value.output_buss_name);
  reader(value.attenuation);
  reader(value.dynamic_data);
  reader(value.mute_fade_time);
  reader(value.flags);
  reader(value.max_audible);
  reader(value.max_audible_behavior);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::ReverbDataV8 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.room);
  reader(value.room_hf);
  reader(value.room_lf);
  reader(value.decay_time);
  reader(value.decay_hf_ratio);
  reader(value.reflections);
  reader(value.reflections_delay);
  reader(value.reverb);
  reader(value.reverb_delay);
  reader(value.reference_hf);
  reader(value.reference_lf);
  reader(value.diffusion);
  reader(value.density);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::SnapshotDataV8 &value) {
  reader(value.name);
  reader(value.blend_in_time);
  reader(value.blend_out_time);
  reader(value.flags);
  reader(value.buss);
  reader(value.category);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::AudioSettingsDataV8 &value) {
  reader(value.default_snapshot);
  reader(value.effects_buss);
  reader(value.distance_scale);
  reader(value.focus_transition);
  reader(value.buss);
  reader(value.category);
  reader(value.reverb);
  reader(value.snapshot);
  reader(value.bank_index_file_name);
  reader(value.bank_script_file_name);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::HandlerDataV8 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.byte_code);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::FileNameDataV8 &value) {
  reader(value.language);
  reader(value.weight);
  reader(value.file_name);
  reader(value.audio_type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::MetaSoundDataV8 &value) {
  reader(value.category);
  reader(value.end_cue);
  reader(value.name);
  reader(value.offset_bone);
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
  reader(value.music_priority);
  reader(value.playback_mode);
  reader(value.position_mode);
  reader(value.repeat_time_from);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::ScriptRefDataV8 &value) {
  reader(value.name);
  reader(value.file_name);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::TriggerMarkerDataV8 &value) {
  reader(value.cue);
  reader(value.end);
  reader(value.time);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::TriggerKeyDataV8 &value) {
  reader(value.name);
  reader(value.trigger_marker);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v8::ScriptFileDataV8 &value) {
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
