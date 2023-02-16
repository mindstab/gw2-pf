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

#if CINP_CSCN_MIN_VERSION <= 9

#include "pf/types.hpp"

namespace pf {
namespace CINP::CSCN::v9 {
struct PropertyDataV9 {
  pf::byte type;
  pf::qword value;
  pf::filename path_val;
};

struct CurveKeyDataV9 {
  float time;
  float value;
  float in_tangent;
  float out_tangent;
};

struct FlagKeyDataV9 {
  float time;
  float value;
};

struct TriggerKeyDataV9 {
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

struct TrackDataV9 {
  pf::qword name;
  pf::byte type;
  std::vector<CurveKeyDataV9> curve_key;
  std::vector<FlagKeyDataV9> flag_key;
  std::vector<TriggerKeyDataV9> trigger_key;
};

struct TrackGroupDataV9 {
  pf::qword name;
  pf::byte type;
  pf::dword flags;
  std::vector<PropertyDataV9> prop;
  std::vector<TrackDataV9> track;
};

struct SequenceDataV9 {
  pf::qword name;
  float length;
  pf::filename environment_map;
  pf::wstring map;
  pf::wstring client_map;
  std::vector<TrackGroupDataV9> track_group;
};

struct ColorDefDataV9 {
  pf::byte3 color;
  float intensity;
};

struct AmbientLightDataV9 {
  ColorDefDataV9 ambient_ground_color;
  ColorDefDataV9 ambient_sky_color;
  ColorDefDataV9 fill_color;
  ColorDefDataV9 hemispherical_color;
  pf::qword name;
};

struct FileNameRefDataV9 {
  pf::qword name;
  pf::filename file_name;
};

struct ScriptDataV9 {
  pf::qword name;
  std::vector<pf::byte> byte_code;
};

struct TextEntryDataV9 {
  pf::wstring text;
  pf::byte language;
};

struct TextResourceDataV9 {
  pf::qword name;
  pf::dword id;
  std::vector<TextEntryDataV9> text_entry;
};

struct ResourceDataV9 {
  pf::dword crc;
  std::vector<AmbientLightDataV9> ambient_light_resource;
  std::vector<FileNameRefDataV9> file_name_ref;
  std::vector<ScriptDataV9> script;
  std::vector<TextResourceDataV9> text_resource;
};

struct SceneDataV9 {
  pf::qword starting_sequence;
  std::vector<SequenceDataV9> sequence;
  ResourceDataV9 resources;
};
} // namespace CINP::CSCN::v9

namespace de {
template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v9::PropertyDataV9 &value) {
  reader(value.type);
  reader(value.value);
  reader(value.path_val);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v9::CurveKeyDataV9 &value) {
  reader(value.time);
  reader(value.value);
  reader(value.in_tangent);
  reader(value.out_tangent);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v9::FlagKeyDataV9 &value) {
  reader(value.time);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v9::TriggerKeyDataV9 &value) {
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
void Read(Reader &reader, CINP::CSCN::v9::TrackDataV9 &value) {
  reader(value.name);
  reader(value.type);
  reader(value.curve_key);
  reader(value.flag_key);
  reader(value.trigger_key);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v9::TrackGroupDataV9 &value) {
  reader(value.name);
  reader(value.type);
  reader(value.flags);
  reader(value.prop);
  reader(value.track);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v9::SequenceDataV9 &value) {
  reader(value.name);
  reader(value.length);
  reader(value.environment_map);
  reader(value.map);
  reader(value.client_map);
  reader(value.track_group);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v9::ColorDefDataV9 &value) {
  reader(value.color);
  reader(value.intensity);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v9::AmbientLightDataV9 &value) {
  reader(value.ambient_ground_color);
  reader(value.ambient_sky_color);
  reader(value.fill_color);
  reader(value.hemispherical_color);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v9::FileNameRefDataV9 &value) {
  reader(value.name);
  reader(value.file_name);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v9::ScriptDataV9 &value) {
  reader(value.name);
  reader(value.byte_code);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v9::TextEntryDataV9 &value) {
  reader(value.text);
  reader(value.language);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v9::TextResourceDataV9 &value) {
  reader(value.name);
  reader(value.id);
  reader(value.text_entry);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v9::ResourceDataV9 &value) {
  reader(value.crc);
  reader(value.ambient_light_resource);
  reader(value.file_name_ref);
  reader(value.script);
  reader(value.text_resource);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v9::SceneDataV9 &value) {
  reader(value.starting_sequence);
  reader(value.sequence);
  reader(value.resources);
}
} // namespace de

} // namespace pf

#endif
