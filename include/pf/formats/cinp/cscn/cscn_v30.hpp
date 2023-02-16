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

#if CINP_CSCN_MIN_VERSION <= 30

#include "pf/types.hpp"

namespace pf {
namespace CINP::CSCN::v30 {
struct PropertyDataV30 {
  pf::qword value;
  pf::filename path_val;
  pf::byte type;
};

struct CurveKeyDataV30 {
  float time;
  float value;
  float in_tangent;
  float out_tangent;
};

struct FlagKeyDataV30 {
  float time;
  float value;
};

struct TriggerKeyDataV30 {
  float time;
  pf::byte flags1;
  pf::byte flags2;
  pf::byte flags3;
  pf::byte flags4;
  pf::qword token1;
  pf::qword token2;
  float value1;
  float value2;
  float value3;
  float value4;
};

struct TrackDataV30 {
  pf::qword name;
  std::vector<CurveKeyDataV30> curve_key;
  std::vector<FlagKeyDataV30> flag_key;
  std::vector<TriggerKeyDataV30> trigger_key;
  pf::byte type;
};

struct TrackGroupDataV30 {
  pf::qword name;
  pf::dword flags;
  std::vector<PropertyDataV30> prop;
  std::vector<TrackDataV30> track;
  pf::byte type;
};

struct SequenceDataV30 {
  pf::qword name;
  pf::qword play_script;
  pf::qword update_script;
  pf::filename environment_map;
  pf::wstring map;
  pf::wstring client_map;
  float length;
  pf::dword flags;
  std::vector<TrackGroupDataV30> track_group;
};

struct ColorDefDataV30 {
  float intensity;
  pf::byte3 color;
};

struct AmbientLightDataV30 {
  ColorDefDataV30 ambient_ground_color;
  ColorDefDataV30 ambient_sky_color;
  ColorDefDataV30 fill_color;
  ColorDefDataV30 hemispherical_color;
  pf::qword name;
};

struct FileNameRefDataV30 {
  pf::qword name;
  pf::filename file_name;
};

struct ScriptDataV30 {
  pf::qword name;
  std::vector<pf::byte> byte_code;
};

struct TextEntryDataV30 {
  pf::wstring text;
  pf::byte language;
};

struct TextResourceDataV30 {
  pf::qword name;
  pf::dword index;
  pf::dword voice_id;
  std::vector<TextEntryDataV30> text_entry;
};

struct ResourceDataV30 {
  pf::dword crc;
  std::vector<AmbientLightDataV30> ambient_light_resource;
  std::vector<FileNameRefDataV30> file_name_ref;
  std::vector<ScriptDataV30> script;
  std::vector<TextResourceDataV30> text_resource;
};

struct SceneDataV30 {
  pf::qword starting_sequence;
  std::vector<SequenceDataV30> sequence;
  ResourceDataV30 resources;
  std::shared_ptr<TrackGroupDataV30> track_group;
};
} // namespace CINP::CSCN::v30

namespace de {
template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v30::PropertyDataV30 &value) {
  reader(value.value);
  reader(value.path_val);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v30::CurveKeyDataV30 &value) {
  reader(value.time);
  reader(value.value);
  reader(value.in_tangent);
  reader(value.out_tangent);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v30::FlagKeyDataV30 &value) {
  reader(value.time);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v30::TriggerKeyDataV30 &value) {
  reader(value.time);
  reader(value.flags1);
  reader(value.flags2);
  reader(value.flags3);
  reader(value.flags4);
  reader(value.token1);
  reader(value.token2);
  reader(value.value1);
  reader(value.value2);
  reader(value.value3);
  reader(value.value4);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v30::TrackDataV30 &value) {
  reader(value.name);
  reader(value.curve_key);
  reader(value.flag_key);
  reader(value.trigger_key);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v30::TrackGroupDataV30 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.prop);
  reader(value.track);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v30::SequenceDataV30 &value) {
  reader(value.name);
  reader(value.play_script);
  reader(value.update_script);
  reader(value.environment_map);
  reader(value.map);
  reader(value.client_map);
  reader(value.length);
  reader(value.flags);
  reader(value.track_group);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v30::ColorDefDataV30 &value) {
  reader(value.intensity);
  reader(value.color);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v30::AmbientLightDataV30 &value) {
  reader(value.ambient_ground_color);
  reader(value.ambient_sky_color);
  reader(value.fill_color);
  reader(value.hemispherical_color);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v30::FileNameRefDataV30 &value) {
  reader(value.name);
  reader(value.file_name);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v30::ScriptDataV30 &value) {
  reader(value.name);
  reader(value.byte_code);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v30::TextEntryDataV30 &value) {
  reader(value.text);
  reader(value.language);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v30::TextResourceDataV30 &value) {
  reader(value.name);
  reader(value.index);
  reader(value.voice_id);
  reader(value.text_entry);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v30::ResourceDataV30 &value) {
  reader(value.crc);
  reader(value.ambient_light_resource);
  reader(value.file_name_ref);
  reader(value.script);
  reader(value.text_resource);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v30::SceneDataV30 &value) {
  reader(value.starting_sequence);
  reader(value.sequence);
  reader(value.resources);
  reader(value.track_group);
}
} // namespace de

} // namespace pf

#endif
