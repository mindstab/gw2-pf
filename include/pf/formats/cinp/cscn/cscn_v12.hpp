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

#if CINP_CSCN_MIN_VERSION <= 12

#include "pf/types.hpp"

namespace pf {
namespace CINP::CSCN::v12 {
struct PropertyDataV12 {
  pf::qword value;
  pf::filename path_val;
  pf::byte type;
};

struct CurveKeyDataV12 {
  float time;
  float value;
  float in_tangent;
  float out_tangent;
};

struct FlagKeyDataV12 {
  float time;
  float value;
};

struct TriggerKeyDataV12 {
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

struct TrackDataV12 {
  pf::qword name;
  std::vector<CurveKeyDataV12> curve_key;
  std::vector<FlagKeyDataV12> flag_key;
  std::vector<TriggerKeyDataV12> trigger_key;
  pf::byte type;
};

struct TrackGroupDataV12 {
  pf::qword name;
  pf::dword flags;
  std::vector<PropertyDataV12> prop;
  std::vector<TrackDataV12> track;
  pf::byte type;
};

struct SequenceDataV12 {
  pf::qword name;
  pf::fileref environment_map;
  pf::wstring map;
  pf::wstring client_map;
  float length;
  std::vector<TrackGroupDataV12> track_group;
};

struct ColorDefDataV12 {
  float intensity;
  pf::byte3 color;
};

struct AmbientLightDataV12 {
  ColorDefDataV12 ambient_ground_color;
  ColorDefDataV12 ambient_sky_color;
  ColorDefDataV12 fill_color;
  ColorDefDataV12 hemispherical_color;
  pf::qword name;
};

struct FileNameRefDataV12 {
  pf::qword name;
  pf::filename file_name;
};

struct ScriptDataV12 {
  pf::qword name;
  std::vector<pf::byte> byte_code;
};

struct TextEntryDataV12 {
  pf::wstring text;
  pf::byte language;
};

struct TextResourceDataV12 {
  pf::qword name;
  pf::dword id;
  std::vector<TextEntryDataV12> text_entry;
};

struct ResourceDataV12 {
  pf::dword crc;
  std::vector<AmbientLightDataV12> ambient_light_resource;
  std::vector<FileNameRefDataV12> file_name_ref;
  std::vector<ScriptDataV12> script;
  std::vector<TextResourceDataV12> text_resource;
};

struct SceneDataV12 {
  pf::qword starting_sequence;
  std::vector<SequenceDataV12> sequence;
  ResourceDataV12 resources;
};
} // namespace CINP::CSCN::v12

namespace de {
template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v12::PropertyDataV12 &value) {
  reader(value.value);
  reader(value.path_val);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v12::CurveKeyDataV12 &value) {
  reader(value.time);
  reader(value.value);
  reader(value.in_tangent);
  reader(value.out_tangent);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v12::FlagKeyDataV12 &value) {
  reader(value.time);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v12::TriggerKeyDataV12 &value) {
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
void Read(Reader &reader, CINP::CSCN::v12::TrackDataV12 &value) {
  reader(value.name);
  reader(value.curve_key);
  reader(value.flag_key);
  reader(value.trigger_key);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v12::TrackGroupDataV12 &value) {
  reader(value.name);
  reader(value.flags);
  reader(value.prop);
  reader(value.track);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v12::SequenceDataV12 &value) {
  reader(value.name);
  reader(value.environment_map);
  reader(value.map);
  reader(value.client_map);
  reader(value.length);
  reader(value.track_group);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v12::ColorDefDataV12 &value) {
  reader(value.intensity);
  reader(value.color);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v12::AmbientLightDataV12 &value) {
  reader(value.ambient_ground_color);
  reader(value.ambient_sky_color);
  reader(value.fill_color);
  reader(value.hemispherical_color);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v12::FileNameRefDataV12 &value) {
  reader(value.name);
  reader(value.file_name);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v12::ScriptDataV12 &value) {
  reader(value.name);
  reader(value.byte_code);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v12::TextEntryDataV12 &value) {
  reader(value.text);
  reader(value.language);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v12::TextResourceDataV12 &value) {
  reader(value.name);
  reader(value.id);
  reader(value.text_entry);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v12::ResourceDataV12 &value) {
  reader(value.crc);
  reader(value.ambient_light_resource);
  reader(value.file_name_ref);
  reader(value.script);
  reader(value.text_resource);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v12::SceneDataV12 &value) {
  reader(value.starting_sequence);
  reader(value.sequence);
  reader(value.resources);
}
} // namespace de

} // namespace pf

#endif
