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

#if CINP_CSCN_MIN_VERSION <= 8

#include "pf/types.hpp"

namespace pf {
namespace CINP::CSCN::v8 {
struct PropertyDataV8 {
  pf::byte type;
  pf::qword value;
  pf::filename path_val;
};

struct CurveKeyDataV8 {
  float time;
  float value;
  float in_tangent;
  float out_tangent;
};

struct FlagKeyDataV8 {
  float time;
  float value;
};

struct TriggerKeyDataV8 {
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

struct TrackDataV8 {
  pf::qword name;
  pf::byte type;
  std::vector<CurveKeyDataV8> curve_key;
  std::vector<FlagKeyDataV8> flag_key;
  std::vector<TriggerKeyDataV8> trigger_key;
};

struct TrackGroupDataV8 {
  pf::qword name;
  pf::byte type;
  pf::dword flags;
  std::vector<PropertyDataV8> prop;
  std::vector<TrackDataV8> track;
};

struct SequenceDataV8 {
  pf::qword name;
  float length;
  pf::filename environment_map;
  pf::wstring map;
  pf::wstring client_map;
  std::vector<TrackGroupDataV8> track_group;
};

struct ColorDefDataV8 {
  pf::byte3 color;
  float intensity;
};

struct AmbientLightDataV8 {
  ColorDefDataV8 ambient_ground_color;
  ColorDefDataV8 ambient_sky_color;
  ColorDefDataV8 fill_color;
  ColorDefDataV8 hemispherical_color;
  pf::qword name;
};

struct FileNameRefDataV8 {
  pf::qword name;
  pf::filename file_name;
};

struct ScriptDataV8 {
  pf::qword name;
  std::vector<pf::byte> byte_code;
};

struct TextEntryDataV8 {
  pf::wstring text;
  pf::byte language;
};

struct TextResourceDataV8 {
  pf::qword name;
  pf::dword id;
  std::vector<TextEntryDataV8> text_entry;
};

struct ResourceDataV8 {
  std::vector<AmbientLightDataV8> ambient_light_resource;
  std::vector<FileNameRefDataV8> file_name_ref;
  std::vector<ScriptDataV8> script;
  std::vector<TextResourceDataV8> text_resource;
};

struct SceneDataV8 {
  pf::qword starting_sequence;
  std::vector<SequenceDataV8> sequence;
  ResourceDataV8 resources;
};
} // namespace CINP::CSCN::v8

namespace de {
template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v8::PropertyDataV8 &value) {
  reader(value.type);
  reader(value.value);
  reader(value.path_val);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v8::CurveKeyDataV8 &value) {
  reader(value.time);
  reader(value.value);
  reader(value.in_tangent);
  reader(value.out_tangent);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v8::FlagKeyDataV8 &value) {
  reader(value.time);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v8::TriggerKeyDataV8 &value) {
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
void Read(Reader &reader, CINP::CSCN::v8::TrackDataV8 &value) {
  reader(value.name);
  reader(value.type);
  reader(value.curve_key);
  reader(value.flag_key);
  reader(value.trigger_key);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v8::TrackGroupDataV8 &value) {
  reader(value.name);
  reader(value.type);
  reader(value.flags);
  reader(value.prop);
  reader(value.track);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v8::SequenceDataV8 &value) {
  reader(value.name);
  reader(value.length);
  reader(value.environment_map);
  reader(value.map);
  reader(value.client_map);
  reader(value.track_group);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v8::ColorDefDataV8 &value) {
  reader(value.color);
  reader(value.intensity);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v8::AmbientLightDataV8 &value) {
  reader(value.ambient_ground_color);
  reader(value.ambient_sky_color);
  reader(value.fill_color);
  reader(value.hemispherical_color);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v8::FileNameRefDataV8 &value) {
  reader(value.name);
  reader(value.file_name);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v8::ScriptDataV8 &value) {
  reader(value.name);
  reader(value.byte_code);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v8::TextEntryDataV8 &value) {
  reader(value.text);
  reader(value.language);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v8::TextResourceDataV8 &value) {
  reader(value.name);
  reader(value.id);
  reader(value.text_entry);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v8::ResourceDataV8 &value) {
  reader(value.ambient_light_resource);
  reader(value.file_name_ref);
  reader(value.script);
  reader(value.text_resource);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v8::SceneDataV8 &value) {
  reader(value.starting_sequence);
  reader(value.sequence);
  reader(value.resources);
}
} // namespace de

} // namespace pf

#endif
