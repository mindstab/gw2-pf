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

#if AMSP_AMSP_MIN_VERSION <= 24

#include "pf/types.hpp"

namespace pf {
namespace AMSP::AMSP::v24 {
struct DspDataV24 {
  pf::dword type;
  pf::dword flags;
  std::vector<float> property;
};

struct BussDynamicDataV24 {
  pf::qword name;
  pf::dword flags;
  float volume;
  std::vector<DspDataV24> dsp;
};

struct BussDataV24 {
  pf::qword name;
  pf::dword flags;
  pf::qword output;
  std::shared_ptr<BussDynamicDataV24> dynamic_data;
};

struct EnvelopePointDataV24 {
  float offset;
  float value;
};

struct EnvelopeDataV24 {
  pf::qword offset_parameter;
  std::vector<EnvelopePointDataV24> envelope_point;
  pf::byte offset_type;
};

struct RangeDataV24 {
  float max;
  float min;
  pf::byte min2;
};

struct RandomParamDataV24 {
  RangeDataV24 time;
  RangeDataV24 value;
};

struct DynamicParamDataV24 {
  std::shared_ptr<EnvelopeDataV24> envelope_data;
  std::shared_ptr<RandomParamDataV24> random_param_data;
  float value;
  pf::byte type;
};

struct AttenuationDataV24 {
  float doppler;
  DynamicParamDataV24 low_pass;
  DynamicParamDataV24 high_pass;
  DynamicParamDataV24 pan3_d;
  DynamicParamDataV24 reverb;
  DynamicParamDataV24 spread3_d;
  DynamicParamDataV24 volume_a;
  DynamicParamDataV24 volume_b;
};

struct CategoryDynamicDataV24 {
  pf::qword name;
  float volume;
  float non_focus_gain;
  float low_pass;
  float high_pass;
  float reverb_direct;
  float reverb_room;
  pf::dword flags;
};

struct CategoryDataV24 {
  pf::qword name;
  pf::qword volume_group_name;
  pf::qword output_buss_name;
  std::shared_ptr<AttenuationDataV24> attenuation;
  std::shared_ptr<CategoryDynamicDataV24> dynamic_data;
  float mute_fade_time;
  pf::dword flags;
  pf::dword max_audible;
  pf::byte max_audible_behavior;
};

struct MusicConditionDataV24 {
  pf::qword name;
  pf::dword flags;
  std::vector<pf::byte> byte_code;
};

struct FileNameDataV24 {
  pf::qword condition;
  pf::qword language;
  float volume;
  float weight;
  pf::filename file_name;
  pf::byte audio_type;
  pf::byte note_base;
  pf::byte note_min;
  pf::byte note_max;
};

struct MusicPlaylistDataV24 {
  pf::qword category;
  pf::qword name;
  pf::qword primary_playlist_id;
  pf::qword secondary_playlist_id;
  std::vector<FileNameDataV24> file_name;
  float fade_in_time;
  float fade_out_time;
  pf::dword flags;
  RangeDataV24 initial_silence;
  RangeDataV24 interval_silence;
  RangeDataV24 max_play_length;
  DynamicParamDataV24 volume;
  pf::byte file_iterate_mode;
};

struct ReverbDataV24 {
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

struct SnapshotDataV24 {
  pf::qword name;
  float blend_in_time;
  float blend_out_time;
  pf::dword flags;
  std::vector<BussDynamicDataV24> buss;
  std::vector<CategoryDynamicDataV24> category;
  pf::byte priority;
};

struct AudioSettingsDataV24 {
  pf::qword default_snapshot;
  pf::qword effects_buss;
  float distance_scale;
  float doppler_scale;
  float focus_transition;
  std::vector<BussDataV24> buss;
  std::vector<CategoryDataV24> category;
  std::vector<MusicConditionDataV24> music_condition;
  std::vector<MusicPlaylistDataV24> music_playlist;
  std::vector<ReverbDataV24> reverb;
  std::vector<SnapshotDataV24> snapshot;
  pf::filename bank_index_file_name;
  pf::filename bank_script_file_name;
  pf::filename music_script_file_name;
};

struct HandlerDataV24 {
  pf::qword name;
  pf::dword flags;
  std::vector<pf::byte> byte_code;
};

struct MetaSoundDataV24 {
  pf::qword category;
  pf::qword end_cue;
  pf::qword name;
  pf::qword offset_bone;
  pf::qword playlist_id;
  std::vector<DspDataV24> dsp;
  std::shared_ptr<AttenuationDataV24> attenuation;
  std::vector<FileNameDataV24> file_name;
  float channel_fade_in;
  float channel_fade_out;
  float end_cue_offset;
  float fade_in_time;
  float fade_out_time;
  pf::float3 position_offset;
  pf::dword channel_max;
  pf::dword flags;
  pf::dword loop_count;
  DynamicParamDataV24 depth;
  DynamicParamDataV24 pan;
  DynamicParamDataV24 pitch;
  DynamicParamDataV24 pitch_ms;
  DynamicParamDataV24 volume;
  DynamicParamDataV24 volume_ms;
  RangeDataV24 initial_delay;
  RangeDataV24 play_length;
  RangeDataV24 position_offset_angle;
  RangeDataV24 position_range;
  RangeDataV24 repeat_count;
  RangeDataV24 repeat_time;
  RangeDataV24 start_time_offset;
  pf::byte channel_mode;
  pf::byte channel_priority;
  pf::byte file_iterate_mode;
  pf::byte loop_mode;
  pf::byte music_priority;
  pf::byte playback_mode;
  pf::byte position_mode;
  pf::byte repeat_time_from;
};

struct ScriptRefDataV24 {
  pf::qword name;
  pf::filename file_name;
};

struct TriggerMarkerDataV24 {
  pf::qword cue;
  pf::qword end;
  float time;
  pf::byte type;
};

struct TriggerKeyDataV24 {
  pf::qword name;
  std::vector<TriggerMarkerDataV24> trigger_marker;
};

struct ScriptFileDataV24 {
  pf::qword music_cue;
  pf::qword reverb_override;
  pf::qword snapshot;
  std::shared_ptr<AudioSettingsDataV24> audio_settings;
  std::vector<HandlerDataV24> handler;
  std::vector<MetaSoundDataV24> meta_sound;
  std::vector<ScriptRefDataV24> script_ref;
  std::vector<TriggerKeyDataV24> trigger_key;
  pf::dword flags;
  pf::dword sound_pool_count;
  float fade_in_time;
  float sound_pool_delay;
  float volume;
  pf::byte music_cue_priority;
  pf::byte music_mute_priority;
};
} // namespace AMSP::AMSP::v24

namespace de {
template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v24::DspDataV24 &value) {
  reader(value.type);
  reader(value.flags);
  reader(value.property);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v24::BussDynamicDataV24 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.volume);
  reader(value.dsp);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v24::BussDataV24 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.output);
  reader(value.dynamic_data);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v24::EnvelopePointDataV24 &value) {
  reader(value.offset);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v24::EnvelopeDataV24 &value) {
  reader(value.offset_parameter);
  reader(value.envelope_point);
  reader(value.offset_type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v24::RangeDataV24 &value) {
  reader(value.max);
  reader(value.min);
  reader(value.min2);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v24::RandomParamDataV24 &value) {
  reader(value.time);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v24::DynamicParamDataV24 &value) {
  reader(value.envelope_data);
  reader(value.random_param_data);
  reader(value.value);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v24::AttenuationDataV24 &value) {
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
void Read(Reader &reader, AMSP::AMSP::v24::CategoryDynamicDataV24 &value) {
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
void Read(Reader &reader, AMSP::AMSP::v24::CategoryDataV24 &value) {
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
void Read(Reader &reader, AMSP::AMSP::v24::MusicConditionDataV24 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.byte_code);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v24::FileNameDataV24 &value) {
  reader(value.condition);
  reader(value.language);
  reader(value.volume);
  reader(value.weight);
  reader(value.file_name);
  reader(value.audio_type);
  reader(value.note_base);
  reader(value.note_min);
  reader(value.note_max);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v24::MusicPlaylistDataV24 &value) {
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
void Read(Reader &reader, AMSP::AMSP::v24::ReverbDataV24 &value) {
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
void Read(Reader &reader, AMSP::AMSP::v24::SnapshotDataV24 &value) {
  reader(value.name);
  reader(value.blend_in_time);
  reader(value.blend_out_time);
  reader(value.flags);
  reader(value.buss);
  reader(value.category);
  reader(value.priority);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v24::AudioSettingsDataV24 &value) {
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
void Read(Reader &reader, AMSP::AMSP::v24::HandlerDataV24 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.byte_code);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v24::MetaSoundDataV24 &value) {
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
void Read(Reader &reader, AMSP::AMSP::v24::ScriptRefDataV24 &value) {
  reader(value.name);
  reader(value.file_name);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v24::TriggerMarkerDataV24 &value) {
  reader(value.cue);
  reader(value.end);
  reader(value.time);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v24::TriggerKeyDataV24 &value) {
  reader(value.name);
  reader(value.trigger_marker);
}

template <typename Reader>
void Read(Reader &reader, AMSP::AMSP::v24::ScriptFileDataV24 &value) {
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
  reader(value.music_mute_priority);
}
} // namespace de

} // namespace pf

#endif
