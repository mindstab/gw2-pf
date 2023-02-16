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

#if CINP_CSCN_MIN_VERSION <= 17

#include "pf/types.hpp"

namespace pf {
namespace CINP::CSCN::v17 {
struct PropertyDataV17 {
  pf::qword value;
  pf::filename path_val;
  pf::byte type;
};

struct CurveKeyDataV17 {
  float time;
  float value;
  float in_tangent;
  float out_tangent;
};

struct FlagKeyDataV17 {
  float time;
  float value;
};

struct TriggerKeyDataV17 {
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

struct TrackDataV17 {
  pf::qword name;
  std::vector<CurveKeyDataV17> curve_key;
  std::vector<FlagKeyDataV17> flag_key;
  std::vector<TriggerKeyDataV17> trigger_key;
  pf::byte type;
};

struct TrackGroupDataV17 {
  pf::qword name;
  pf::dword flags;
  std::vector<PropertyDataV17> prop;
  std::vector<TrackDataV17> track;
  pf::byte type;
};

struct SequenceDataV17 {
  pf::qword name;
  pf::filename environment_map;
  pf::wstring map;
  pf::wstring client_map;
  pf::qword update_script;
  float length;
  std::vector<TrackGroupDataV17> track_group;
};

struct ColorDefDataV17 {
  float intensity;
  pf::byte3 color;
};

struct AmbientLightDataV17 {
  ColorDefDataV17 ambient_ground_color;
  ColorDefDataV17 ambient_sky_color;
  ColorDefDataV17 fill_color;
  ColorDefDataV17 hemispherical_color;
  pf::qword name;
};

struct FileNameRefDataV17 {
  pf::qword name;
  pf::filename file_name;
};

struct ScriptDataV17 {
  pf::qword name;
  std::vector<pf::byte> byte_code;
};

struct TextEntryDataV17 {
  pf::wstring text;
  pf::byte language;
};

struct TextResourceDataV17 {
  pf::qword name;
  pf::dword id;
  pf::dword voice_id;
  std::vector<TextEntryDataV17> text_entry;
};

struct ResourceDataV17 {
  pf::dword crc;
  std::vector<AmbientLightDataV17> ambient_light_resource;
  std::vector<FileNameRefDataV17> file_name_ref;
  std::vector<ScriptDataV17> script;
  std::vector<TextResourceDataV17> text_resource;
};

struct SceneDataV17 {
  pf::qword starting_sequence;
  std::vector<SequenceDataV17> sequence;
  ResourceDataV17 resources;
};
} // namespace CINP::CSCN::v17

namespace de {
template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v17::PropertyDataV17 &value) {
  reader(value.value);
  reader(value.path_val);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v17::CurveKeyDataV17 &value) {
  reader(value.time);
  reader(value.value);
  reader(value.in_tangent);
  reader(value.out_tangent);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v17::FlagKeyDataV17 &value) {
  reader(value.time);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v17::TriggerKeyDataV17 &value) {
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
void Read(Reader &reader, CINP::CSCN::v17::TrackDataV17 &value) {
  reader(value.name);
  reader(value.curve_key);
  reader(value.flag_key);
  reader(value.trigger_key);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v17::TrackGroupDataV17 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.prop);
  reader(value.track);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v17::SequenceDataV17 &value) {
  reader(value.name);
  reader(value.environment_map);
  reader(value.map);
  reader(value.client_map);
  reader(value.update_script);
  reader(value.length);
  reader(value.track_group);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v17::ColorDefDataV17 &value) {
  reader(value.intensity);
  reader(value.color);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v17::AmbientLightDataV17 &value) {
  reader(value.ambient_ground_color);
  reader(value.ambient_sky_color);
  reader(value.fill_color);
  reader(value.hemispherical_color);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v17::FileNameRefDataV17 &value) {
  reader(value.name);
  reader(value.file_name);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v17::ScriptDataV17 &value) {
  reader(value.name);
  reader(value.byte_code);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v17::TextEntryDataV17 &value) {
  reader(value.text);
  reader(value.language);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v17::TextResourceDataV17 &value) {
  reader(value.name);
  reader(value.id);
  reader(value.voice_id);
  reader(value.text_entry);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v17::ResourceDataV17 &value) {
  reader(value.crc);
  reader(value.ambient_light_resource);
  reader(value.file_name_ref);
  reader(value.script);
  reader(value.text_resource);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v17::SceneDataV17 &value) {
  reader(value.starting_sequence);
  reader(value.sequence);
  reader(value.resources);
}
} // namespace de

} // namespace pf

#endif
