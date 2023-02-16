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

#if AMAT_TOOL_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace AMAT::TOOL::v0 {
struct AmatToolConstantV0 {
  pf::dword token;
  pf::wstring display_name;
  pf::float4 default_value;
  pf::dword flags;
  pf::float4 min_value;
  pf::float4 max_value;
};

struct AmatToolTextureV0 {
  pf::wstring tex_name;
  pf::wstring tex_default_file;
  pf::dword flags;
  std::vector<pf::dword> tex_gen;
  std::vector<pf::dword> tex_transform;
};

struct AmatToolParamsV0 {
  pf::wstring description;
  pf::dword flags;
  pf::cstring text;
  pf::byte tex_coord_count;
  pf::byte tex_transform_count;
  std::vector<AmatToolConstantV0> constants;
  std::vector<AmatToolTextureV0> textures;
};
} // namespace AMAT::TOOL::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, AMAT::TOOL::v0::AmatToolConstantV0 &value) {
  reader(value.token);
  reader(value.display_name);
  reader(value.default_value);
  reader(value.flags);
  reader(value.min_value);
  reader(value.max_value);
}

template <typename Reader>
void Read(Reader &reader, AMAT::TOOL::v0::AmatToolTextureV0 &value) {
  reader(value.tex_name);
  reader(value.tex_default_file);
  reader(value.flags);
  reader(value.tex_gen);
  reader(value.tex_transform);
}

template <typename Reader>
void Read(Reader &reader, AMAT::TOOL::v0::AmatToolParamsV0 &value) {
  reader(value.description);
  reader(value.flags);
  reader(value.text);
  reader(value.tex_coord_count);
  reader(value.tex_transform_count);
  reader(value.constants);
  reader(value.textures);
}
} // namespace de

} // namespace pf

#endif
