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

#if CINP_CSCN_MIN_VERSION <= 2

#include "pf/types.hpp"

namespace pf {
namespace CINP::CSCN::v2 {
struct PropertyDataV2 {
  pf::byte type;
  pf::qword value;
  pf::filename path_val;
};

struct CurveKeyDataV2 {
  float time;
  float value;
  float in_tangent;
  float out_tangent;
};

struct FlagKeyDataV2 {
  float time;
  float value;
};

struct TriggerKeyDataV2 {
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

struct TrackDataV2 {
  pf::qword name;
  pf::byte type;
  std::vector<CurveKeyDataV2> curve_key;
  std::vector<FlagKeyDataV2> flag_key;
  std::vector<TriggerKeyDataV2> trigger_key;
};

struct TrackGroupDataV2 {
  pf::qword name;
  pf::byte type;
  pf::dword flags;
  std::vector<PropertyDataV2> prop;
  std::vector<TrackDataV2> track;
};

struct SequenceDataV2 {
  pf::filename environment_map;
  pf::wstring map;
  pf::wstring client_map;
  pf::qword name;
  float length;
  std::vector<TrackGroupDataV2> track_group;
};

struct ColorDefDataV2 {
  pf::byte3 color;
  float intensity;
};

struct AmbientLightDataV2 {
  ColorDefDataV2 ambient_ground_color;
  ColorDefDataV2 ambient_sky_color;
  ColorDefDataV2 fill_color;
  ColorDefDataV2 hemispherical_color;
  pf::qword name;
};

struct ScriptDataV2 {
  pf::qword name;
  std::vector<pf::byte> byte_code;
};

struct TextEntryDataV2 {
  pf::wstring text;
  pf::byte language;
};

struct TextResourceDataV2 {
  pf::qword name;
  std::vector<TextEntryDataV2> text_entry;
};

struct ResourceDataV2 {
  std::vector<AmbientLightDataV2> ambient_light_resource;
  std::vector<ScriptDataV2> script;
  std::vector<TextResourceDataV2> text_resource;
};

struct SceneDataV2 {
  pf::qword starting_sequence;
  std::vector<SequenceDataV2> sequence;
  ResourceDataV2 resources;
};
} // namespace CINP::CSCN::v2

namespace de {
template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v2::PropertyDataV2 &value) {
  reader(value.type);
  reader(value.value);
  reader(value.path_val);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v2::CurveKeyDataV2 &value) {
  reader(value.time);
  reader(value.value);
  reader(value.in_tangent);
  reader(value.out_tangent);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v2::FlagKeyDataV2 &value) {
  reader(value.time);
  reader(value.value);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v2::TriggerKeyDataV2 &value) {
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
void Read(Reader &reader, CINP::CSCN::v2::TrackDataV2 &value) {
  reader(value.name);
  reader(value.type);
  reader(value.curve_key);
  reader(value.flag_key);
  reader(value.trigger_key);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v2::TrackGroupDataV2 &value) {
  reader(value.name);
  reader(value.type);
  reader(value.flags);
  reader(value.prop);
  reader(value.track);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v2::SequenceDataV2 &value) {
  reader(value.environment_map);
  reader(value.map);
  reader(value.client_map);
  reader(value.name);
  reader(value.length);
  reader(value.track_group);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v2::ColorDefDataV2 &value) {
  reader(value.color);
  reader(value.intensity);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v2::AmbientLightDataV2 &value) {
  reader(value.ambient_ground_color);
  reader(value.ambient_sky_color);
  reader(value.fill_color);
  reader(value.hemispherical_color);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v2::ScriptDataV2 &value) {
  reader(value.name);
  reader(value.byte_code);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v2::TextEntryDataV2 &value) {
  reader(value.text);
  reader(value.language);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v2::TextResourceDataV2 &value) {
  reader(value.name);
  reader(value.text_entry);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v2::ResourceDataV2 &value) {
  reader(value.ambient_light_resource);
  reader(value.script);
  reader(value.text_resource);
}

template <typename Reader>
void Read(Reader &reader, CINP::CSCN::v2::SceneDataV2 &value) {
  reader(value.starting_sequence);
  reader(value.sequence);
  reader(value.resources);
}
} // namespace de

} // namespace pf

#endif
