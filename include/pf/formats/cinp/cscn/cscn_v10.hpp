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

#if CINP_CSCN_MIN_VERSION <= 10

#include "pf/types.hpp"

namespace pf {
namespace CINP::CSCN::v10 {
struct PropertyDataV10 {
  pf::byte type;
  pf::qword value;
  pf::filename path_val;
};

struct CurveKeyDataV10 {
  float time;
  float value;
  float in_tangent;
  float out_tangent;
};

struct FlagKeyDataV10 {
  float time;
  float value;
};

struct TriggerKeyDataV10 {
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

struct TrackDataV10 {
  pf::qword name;
  pf::byte type;
  std::vector<CurveKeyDataV10> curve_key;
  std::vector<FlagKeyDataV10> flag_key;
  std::vector<TriggerKeyDataV10> trigger_key;
};

struct TrackGroupDataV10 {
  pf::qword name;
  pf::byte type;
  pf::dword flags;
  std::vector<PropertyDataV10> prop;
  std::vector<TrackDataV10> track;
};

struct SequenceDataV10 {
  pf::qword name;
  float length;
  pf::filename environment_map;
  pf::wstring map;
  pf::wstring client_map;
  std::vector<TrackGroupDataV10> track_group;
};

struct ColorDefDataV10 {
  pf::byte3 color;
  float intensity;
};

struct AmbientLightDataV10 {
  ColorDefDataV10 ambient_ground_color;
  ColorDefDataV10 ambient_sky_color;
  ColorDefDataV10 fill_color;
  ColorDefDataV10 hemispherical_color;
  pf::qword name;
};

struct FileNameRefDataV10 {
  pf::qword name;
  pf::filename file_name;
};

struct ScriptDataV10 {
  pf::qword name;
  std::vector<pf::byte> byte_code;
};

struct TextEntryDataV10 {
  pf::wstring text;
  pf::byte language;
};

struct TextResourceDataV10 {
  pf::qword name;
  pf::dword id;
  std::vector<TextEntryDataV10> text_entry;
};

struct ResourceDataV10 {
  pf::dword crc;
  std::vector<AmbientLightDataV10> ambient_light_resource;
  std::vector<FileNameRefDataV10> file_name_ref;
  std::vector<ScriptDataV10> script;
  std::vector<TextResourceDataV10> text_resource;
};

struct SceneDataV10 {
  pf::qword starting_sequence;
  std::vector<SequenceDataV10> sequence;
  ResourceDataV10 resources;
};
} // namespace CINP::CSCN::v10

namespace de {
template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v10::PropertyDataV10 &value) {
  reader(value.type);
  reader(value.value);
  reader(value.path_val);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v10::CurveKeyDataV10 &value) {
  reader(value.time);
  reader(value.value);
  reader(value.in_tangent);
  reader(value.out_tangent);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v10::FlagKeyDataV10 &value) {
  reader(value.time);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v10::TriggerKeyDataV10 &value) {
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
void Read(Reader &reader, CINP::CSCN::v10::TrackDataV10 &value) {
  reader(value.name);
  reader(value.type);
  reader(value.curve_key);
  reader(value.flag_key);
  reader(value.trigger_key);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v10::TrackGroupDataV10 &value) {
  reader(value.name);
  reader(value.type);
  reader(value.flags);
  reader(value.prop);
  reader(value.track);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v10::SequenceDataV10 &value) {
  reader(value.name);
  reader(value.length);
  reader(value.environment_map);
  reader(value.map);
  reader(value.client_map);
  reader(value.track_group);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v10::ColorDefDataV10 &value) {
  reader(value.color);
  reader(value.intensity);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v10::AmbientLightDataV10 &value) {
  reader(value.ambient_ground_color);
  reader(value.ambient_sky_color);
  reader(value.fill_color);
  reader(value.hemispherical_color);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v10::FileNameRefDataV10 &value) {
  reader(value.name);
  reader(value.file_name);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v10::ScriptDataV10 &value) {
  reader(value.name);
  reader(value.byte_code);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v10::TextEntryDataV10 &value) {
  reader(value.text);
  reader(value.language);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v10::TextResourceDataV10 &value) {
  reader(value.name);
  reader(value.id);
  reader(value.text_entry);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v10::ResourceDataV10 &value) {
  reader(value.crc);
  reader(value.ambient_light_resource);
  reader(value.file_name_ref);
  reader(value.script);
  reader(value.text_resource);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v10::SceneDataV10 &value) {
  reader(value.starting_sequence);
  reader(value.sequence);
  reader(value.resources);
}
} // namespace de

} // namespace pf

#endif
