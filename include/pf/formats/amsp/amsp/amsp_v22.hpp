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

#if AMSP_AMSP_MIN_VERSION <= 22

#include "pf/types.hpp"

namespace pf {
namespace AMSP::AMSP::v22 {
struct DspDataV22 {
  pf::dword type;
  pf::dword flags;
  std::vector<float> property;
};

struct BussDynamicDataV22 {
  pf::qword name;
  pf::dword flags;
  float volume;
  std::vector<DspDataV22> dsp;
};

struct BussDataV22 {
  pf::qword name;
  pf::dword flags;
  pf::qword output;
  std::shared_ptr<BussDynamicDataV22> dynamic_data;
};

struct EnvelopePointDataV22 {
  float offset;
  float value;
};

struct EnvelopeDataV22 {
  pf::qword offset_parameter;
  std::vector<EnvelopePointDataV22> envelope_point;
  pf::byte offset_type;
};

struct RangeDataV22 {
  float max;
  float min;
  pf::byte min2;
};

struct RandomParamDataV22 {
  RangeDataV22 time;
  RangeDataV22 value;
};

struct DynamicParamDataV22 {
  std::shared_ptr<EnvelopeDataV22> envelope_data;
  std::shared_ptr<RandomParamDataV22> random_param_data;
  float value;
  pf::byte type;
};

struct AttenuationDataV22 {
  float doppler;
  DynamicParamDataV22 low_pass;
  DynamicParamDataV22 high_pass;
  DynamicParamDataV22 pan3_d;
  DynamicParamDataV22 reverb;
  DynamicParamDataV22 spread3_d;
  DynamicParamDataV22 volume_a;
  DynamicParamDataV22 volume_b;
};

struct CategoryDynamicDataV22 {
  pf::qword name;
  float volume;
  float non_focus_gain;
  float low_pass;
  float high_pass;
  float reverb_direct;
  float reverb_room;
  pf::dword flags;
};

struct CategoryDataV22 {
  pf::qword name;
  pf::qword volume_group_name;
  pf::qword output_buss_name;
  std::shared_ptr<AttenuationDataV22> attenuation;
  std::shared_ptr<CategoryDynamicDataV22> dynamic_data;
  float mute_fade_time;
  pf::dword flags;
  pf::dword max_audible;
  pf::byte max_audible_behavior;
};

struct MusicConditionDataV22 {
  pf::qword name;
  pf::dword flags;
  std::vector<pf::byte> byte_code;
};

struct FileNameDataV22 {
  pf::qword condition;
  pf::qword language;
  float volume;
  float weight;
  pf::filename file_name;
  pf::byte audio_type;
};

struct MusicPlaylistDataV22 {
  pf::qword category;
  pf::qword name;
  pf::qword primary_playlist_id;
  pf::qword secondary_playlist_id;
  std::vector<FileNameDataV22> file_name;
  float fade_in_time;
  float fade_out_time;
  pf::dword flags;
  RangeDataV22 initial_silence;
  RangeDataV22 interval_silence;
  RangeDataV22 max_play_length;
  DynamicParamDataV22 volume;
  pf::byte file_iterate_mode;
};

struct ReverbDataV22 {
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
  float echo_delay;
  float echo_decay_ratio;
  float echo_wet_mix;
  float echo_dry_mix;
};

struct SnapshotDataV22 {
  pf::qword name;
  float blend_in_time;
  float blend_out_time;
  pf::dword flags;
  std::vector<BussDynamicDataV22> buss;
  std::vector<CategoryDynamicDataV22> category;
  pf::byte priority;
};

struct AudioSettingsDataV22 {
  pf::qword default_snapshot;
  pf::qword effects_buss;
  float distance_scale;
  float doppler_scale;
  float focus_transition;
  std::vector<BussDataV22> buss;
  std::vector<CategoryDataV22> category;
  std::vector<MusicConditionDataV22> music_condition;
  std::vector<MusicPlaylistDataV22> music_playlist;
  std::vector<ReverbDataV22> reverb;
  std::vector<SnapshotDataV22> snapshot;
  pf::filename bank_index_file_name;
  pf::filename bank_script_file_name;
  pf::filename music_script_file_name;
};

struct HandlerDataV22 {
  pf::qword name;
  pf::dword flags;
  std::vector<pf::byte> byte_code;
};

struct MetaSoundDataV22 {
  pf::qword category;
  pf::qword end_cue;
  pf::qword name;
  pf::qword offset_bone;
  pf::qword playlist_id;
  std::vector<DspDataV22> dsp;
  std::shared_ptr<AttenuationDataV22> attenuation;
  std::vector<FileNameDataV22> file_name;
  float channel_fade_in;
  float channel_fade_out;
  float end_cue_offset;
  float fade_in_time;
  float fade_out_time;
  pf::float3 position_offset;
  pf::dword channel_max;
  pf::dword flags;
  pf::dword loop_count;
  DynamicParamDataV22 depth;
  DynamicParamDataV22 pan;
  DynamicParamDataV22 pitch;
  DynamicParamDataV22 pitch_ms;
  DynamicParamDataV22 volume;
  DynamicParamDataV22 volume_ms;
  RangeDataV22 initial_delay;
  RangeDataV22 play_length;
  RangeDataV22 position_offset_angle;
  RangeDataV22 position_range;
  RangeDataV22 repeat_count;
  RangeDataV22 repeat_time;
  RangeDataV22 start_time_offset;
  pf::byte channel_mode;
  pf::byte channel_priority;
  pf::byte file_iterate_mode;
  pf::byte loop_mode;
  pf::byte music_priority;
  pf::byte playback_mode;
  pf::byte position_mode;
  pf::byte repeat_time_from;
};

struct ScriptRefDataV22 {
  pf::qword name;
  pf::filename file_name;
};

struct TriggerMarkerDataV22 {
  pf::qword cue;
  pf::qword end;
  float time;
  pf::byte type;
};

struct TriggerKeyDataV22 {
  pf::qword name;
  std::vector<TriggerMarkerDataV22> trigger_marker;
};

struct ScriptFileDataV22 {
  pf::qword music_cue;
  pf::qword reverb_override;
  pf::qword snapshot;
  std::shared_ptr<AudioSettingsDataV22> audio_settings;
  std::vector<HandlerDataV22> handler;
  std::vector<MetaSoundDataV22> meta_sound;
  std::vector<ScriptRefDataV22> script_ref;
  std::vector<TriggerKeyDataV22> trigger_key;
  pf::dword flags;
  pf::dword sound_pool_count;
  float fade_in_time;
  float sound_pool_delay;
  float volume;
  pf::byte music_cue_priority;
};
} // namespace AMSP::AMSP::v22

namespace de {
template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::DspDataV22 &value) {
  reader(value.type);
  reader(value.flags);
  reader(value.property);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::BussDynamicDataV22 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.volume);
  reader(value.dsp);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::BussDataV22 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.output);
  reader(value.dynamic_data);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::EnvelopePointDataV22 &value) {
  reader(value.offset);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::EnvelopeDataV22 &value) {
  reader(value.offset_parameter);
  reader(value.envelope_point);
  reader(value.offset_type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::RangeDataV22 &value) {
  reader(value.max);
  reader(value.min);
  reader(value.min2);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::RandomParamDataV22 &value) {
  reader(value.time);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::DynamicParamDataV22 &value) {
  reader(value.envelope_data);
  reader(value.random_param_data);
  reader(value.value);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::AttenuationDataV22 &value) {
  reader(value.doppler);
  reader(value.low_pass);
  reader(value.high_pass);
  reader(value.pan3_d);
  reader(value.reverb);
  reader(value.spread3_d);
  reader(value.volume_a);
  reader(value.volume_b);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::CategoryDynamicDataV22 &value) {
  reader(value.name);
  reader(value.volume);
  reader(value.non_focus_gain);
  reader(value.low_pass);
  reader(value.high_pass);
  reader(value.reverb_direct);
  reader(value.reverb_room);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::CategoryDataV22 &value) {
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
void Read(Reader &reader, AMSP::AMSP::v22::MusicConditionDataV22 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.byte_code);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::FileNameDataV22 &value) {
  reader(value.condition);
  reader(value.language);
  reader(value.volume);
  reader(value.weight);
  reader(value.file_name);
  reader(value.audio_type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::MusicPlaylistDataV22 &value) {
  reader(value.category);
  reader(value.name);
  reader(value.primary_playlist_id);
  reader(value.secondary_playlist_id);
  reader(value.file_name);
  reader(value.fade_in_time);
  reader(value.fade_out_time);
  reader(value.flags);
  reader(value.initial_silence);
  reader(value.interval_silence);
  reader(value.max_play_length);
  reader(value.volume);
  reader(value.file_iterate_mode);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::ReverbDataV22 &value) {
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
  reader(value.echo_delay);
  reader(value.echo_decay_ratio);
  reader(value.echo_wet_mix);
  reader(value.echo_dry_mix);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::SnapshotDataV22 &value) {
  reader(value.name);
  reader(value.blend_in_time);
  reader(value.blend_out_time);
  reader(value.flags);
  reader(value.buss);
  reader(value.category);
  reader(value.priority);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::AudioSettingsDataV22 &value) {
  reader(value.default_snapshot);
  reader(value.effects_buss);
  reader(value.distance_scale);
  reader(value.doppler_scale);
  reader(value.focus_transition);
  reader(value.buss);
  reader(value.category);
  reader(value.music_condition);
  reader(value.music_playlist);
  reader(value.reverb);
  reader(value.snapshot);
  reader(value.bank_index_file_name);
  reader(value.bank_script_file_name);
  reader(value.music_script_file_name);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::HandlerDataV22 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.byte_code);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::MetaSoundDataV22 &value) {
  reader(value.category);
  reader(value.end_cue);
  reader(value.name);
  reader(value.offset_bone);
  reader(value.playlist_id);
  reader(value.dsp);
  reader(value.attenuation);
  reader(value.file_name);
  reader(value.channel_fade_in);
  reader(value.channel_fade_out);
  reader(value.end_cue_offset);
  reader(value.fade_in_time);
  reader(value.fade_out_time);
  reader(value.position_offset);
  reader(value.channel_max);
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
void Read(Reader &reader, AMSP::AMSP::v22::ScriptRefDataV22 &value) {
  reader(value.name);
  reader(value.file_name);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::TriggerMarkerDataV22 &value) {
  reader(value.cue);
  reader(value.end);
  reader(value.time);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::TriggerKeyDataV22 &value) {
  reader(value.name);
  reader(value.trigger_marker);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v22::ScriptFileDataV22 &value) {
  reader(value.music_cue);
  reader(value.reverb_override);
  reader(value.snapshot);
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
