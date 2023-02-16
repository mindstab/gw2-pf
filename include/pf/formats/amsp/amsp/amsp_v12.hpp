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

#if AMSP_AMSP_MIN_VERSION <= 12

#include "pf/types.hpp"

namespace pf {
namespace AMSP::AMSP::v12 {
struct DspDataV12 {
  pf::dword type;
  pf::dword flags;
  std::vector<float> property;
};

struct BussDynamicDataV12 {
  pf::qword name;
  pf::dword flags;
  float volume;
  std::vector<DspDataV12> dsp;
};

struct BussDataV12 {
  pf::qword name;
  pf::dword flags;
  pf::qword output;
  std::shared_ptr<BussDynamicDataV12> dynamic_data;
};

struct EnvelopePointDataV12 {
  float offset;
  float value;
};

struct EnvelopeDataV12 {
  pf::qword offset_parameter;
  std::vector<EnvelopePointDataV12> envelope_point;
  pf::byte offset_type;
};

struct RangeDataV12 {
  float max;
  float min;
  pf::byte min2;
};

struct RandomParamDataV12 {
  RangeDataV12 time;
  RangeDataV12 value;
};

struct DynamicParamDataV12 {
  std::shared_ptr<EnvelopeDataV12> envelope_data;
  std::shared_ptr<RandomParamDataV12> random_param_data;
  float value;
  pf::byte type;
};

struct AttenuationDataV12 {
  float cone_inside_angle;
  float cone_outside_angle;
  float cone_outside_volume;
  DynamicParamDataV12 low_pass;
  DynamicParamDataV12 pan3_d;
  DynamicParamDataV12 spread3_d;
  DynamicParamDataV12 volume_a;
  DynamicParamDataV12 volume_b;
};

struct CategoryDynamicDataV12 {
  pf::qword name;
  float volume;
  float non_focus_gain;
  float low_pass;
  float reverb_direct;
  float reverb_room;
  pf::dword flags;
};

struct CategoryDataV12 {
  pf::qword name;
  pf::qword volume_group_name;
  pf::qword output_buss_name;
  std::shared_ptr<AttenuationDataV12> attenuation;
  std::shared_ptr<CategoryDynamicDataV12> dynamic_data;
  float mute_fade_time;
  pf::dword flags;
  pf::dword max_audible;
  pf::byte max_audible_behavior;
};

struct ReverbDataV12 {
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

struct SnapshotDataV12 {
  pf::qword name;
  float blend_in_time;
  float blend_out_time;
  pf::dword flags;
  std::vector<BussDynamicDataV12> buss;
  std::vector<CategoryDynamicDataV12> category;
};

struct AudioSettingsDataV12 {
  pf::qword default_snapshot;
  pf::qword effects_buss;
  float distance_scale;
  float focus_transition;
  std::vector<BussDataV12> buss;
  std::vector<CategoryDataV12> category;
  std::vector<ReverbDataV12> reverb;
  std::vector<SnapshotDataV12> snapshot;
  pf::filename bank_index_file_name;
  pf::filename bank_script_file_name;
  pf::filename music_script_file_name;
};

struct HandlerDataV12 {
  pf::qword name;
  pf::dword flags;
  std::vector<pf::byte> byte_code;
};

struct FileNameDataV12 {
  pf::qword language;
  float weight;
  pf::filename file_name;
  pf::byte audio_type;
};

struct MetaSoundDataV12 {
  pf::qword category;
  pf::qword end_cue;
  pf::qword name;
  pf::qword offset_bone;
  pf::qword playlist_id;
  std::vector<DspDataV12> dsp;
  std::shared_ptr<AttenuationDataV12> attenuation;
  std::vector<FileNameDataV12> file_name;
  float end_cue_offset;
  float fade_in_time;
  float fade_out_time;
  pf::float3 position_offset;
  pf::dword flags;
  pf::dword loop_count;
  DynamicParamDataV12 depth;
  DynamicParamDataV12 pan;
  DynamicParamDataV12 pitch;
  DynamicParamDataV12 pitch_ms;
  DynamicParamDataV12 volume;
  DynamicParamDataV12 volume_ms;
  RangeDataV12 initial_delay;
  RangeDataV12 play_length;
  RangeDataV12 position_offset_angle;
  RangeDataV12 position_range;
  RangeDataV12 repeat_count;
  RangeDataV12 repeat_time;
  RangeDataV12 start_time_offset;
  pf::byte channel_mode;
  pf::byte channel_priority;
  pf::byte file_iterate_mode;
  pf::byte loop_mode;
  pf::byte music_priority;
  pf::byte playback_mode;
  pf::byte position_mode;
  pf::byte repeat_time_from;
};

struct ScriptRefDataV12 {
  pf::qword name;
  pf::filename file_name;
};

struct TriggerMarkerDataV12 {
  pf::qword cue;
  pf::qword end;
  float time;
  pf::byte type;
};

struct TriggerKeyDataV12 {
  pf::qword name;
  std::vector<TriggerMarkerDataV12> trigger_marker;
};

struct ScriptFileDataV12 {
  pf::qword music_cue;
  std::shared_ptr<AudioSettingsDataV12> audio_settings;
  std::vector<HandlerDataV12> handler;
  std::vector<MetaSoundDataV12> meta_sound;
  std::vector<ScriptRefDataV12> script_ref;
  std::vector<TriggerKeyDataV12> trigger_key;
  pf::dword flags;
  pf::dword sound_pool_count;
  float fade_in_time;
  float sound_pool_delay;
  float volume;
  pf::byte music_cue_priority;
};
} // namespace AMSP::AMSP::v12

namespace de {
template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v12::DspDataV12 &value) {
  reader(value.type);
  reader(value.flags);
  reader(value.property);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v12::BussDynamicDataV12 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.volume);
  reader(value.dsp);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v12::BussDataV12 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.output);
  reader(value.dynamic_data);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v12::EnvelopePointDataV12 &value) {
  reader(value.offset);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v12::EnvelopeDataV12 &value) {
  reader(value.offset_parameter);
  reader(value.envelope_point);
  reader(value.offset_type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v12::RangeDataV12 &value) {
  reader(value.max);
  reader(value.min);
  reader(value.min2);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v12::RandomParamDataV12 &value) {
  reader(value.time);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v12::DynamicParamDataV12 &value) {
  reader(value.envelope_data);
  reader(value.random_param_data);
  reader(value.value);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v12::AttenuationDataV12 &value) {
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
void Read(Reader &reader, AMSP::AMSP::v12::CategoryDynamicDataV12 &value) {
  reader(value.name);
  reader(value.volume);
  reader(value.non_focus_gain);
  reader(value.low_pass);
  reader(value.reverb_direct);
  reader(value.reverb_room);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v12::CategoryDataV12 &value) {
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
void Read(Reader &reader, AMSP::AMSP::v12::ReverbDataV12 &value) {
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
void Read(Reader &reader, AMSP::AMSP::v12::SnapshotDataV12 &value) {
  reader(value.name);
  reader(value.blend_in_time);
  reader(value.blend_out_time);
  reader(value.flags);
  reader(value.buss);
  reader(value.category);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v12::AudioSettingsDataV12 &value) {
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
  reader(value.music_script_file_name);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v12::HandlerDataV12 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.byte_code);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v12::FileNameDataV12 &value) {
  reader(value.language);
  reader(value.weight);
  reader(value.file_name);
  reader(value.audio_type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v12::MetaSoundDataV12 &value) {
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
void Read(Reader &reader, AMSP::AMSP::v12::ScriptRefDataV12 &value) {
  reader(value.name);
  reader(value.file_name);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v12::TriggerMarkerDataV12 &value) {
  reader(value.cue);
  reader(value.end);
  reader(value.time);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v12::TriggerKeyDataV12 &value) {
  reader(value.name);
  reader(value.trigger_marker);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v12::ScriptFileDataV12 &value) {
  reader(value.music_cue);
  reader(value.audio_settings);
  reader(value.handler);
  reader(value.meta_sound);
  reader(value.script_ref);
  reader(value.trigger_key);
  reader(value.flags);
  reader(value.sound_pool_count);
  reader(value.fade_in_time);
  reader(value.sound_pool_delay);
  reader(value.volume);
  reader(value.music_cue_priority);
}
} // namespace de

} // namespace pf

#endif
