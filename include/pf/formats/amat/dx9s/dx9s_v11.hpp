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

#if AMAT_DX9S_MIN_VERSION <= 11

#include "pf/types.hpp"

namespace pf {
namespace AMAT::DX9S::v11 {
struct AmatDx9SamplerV11 {
  pf::dword texture_index;
  std::vector<pf::dword> state;
  pf::dword uses_bind_texture;
};

struct AmatDx9ShaderV11 {
  std::vector<pf::dword> shader;
  std::vector<pf::dword> const_registers;
  std::vector<pf::dword> const_tokens;
  pf::word instruction_count;
};

struct AmatDx9EffectV11 {
  pf::qword token;
  std::vector<pf::dword> render_states;
  std::vector<pf::dword> sampler_index;
  pf::dword pixel_shader;
  pf::dword vertex_shader;
  std::vector<pf::dword> tex_gen;
  pf::dword vs_gen_flags;
  pf::dword pass_flags;
};

struct AmatDx9PassV11 {
  std::vector<std::shared_ptr<AmatDx9EffectV11>> effects;
};

struct AmatDx9TechniqueV11 {
  pf::cstring name;
  std::vector<AmatDx9PassV11> passes;
  pf::word max_ps_version;
  pf::word max_vs_version;
};

struct AmatDx9MaterialV11 {
  std::vector<AmatDx9SamplerV11> samplers;
  std::vector<AmatDx9ShaderV11> shaders;
  std::vector<AmatDx9TechniqueV11> techniques;
  pf::dword use_legacy_bind_textures;
};
} // namespace AMAT::DX9S::v11

namespace de {
template <typename Reader>
void Read(Reader &reader, AMAT::DX9S::v11::AmatDx9SamplerV11 &value) {
  reader(value.texture_index);
  reader(value.state);
  reader(value.uses_bind_texture);
}

template <typename Reader>
void Read(Reader &reader, AMAT::DX9S::v11::AmatDx9ShaderV11 &value) {
  reader(value.shader);
  reader(value.const_registers);
  reader(value.const_tokens);
  reader(value.instruction_count);
}

template <typename Reader>
void Read(Reader &reader, AMAT::DX9S::v11::AmatDx9EffectV11 &value) {
  reader(value.token);
  reader(value.render_states);
  reader(value.sampler_index);
  reader(value.pixel_shader);
  reader(value.vertex_shader);
  reader(value.tex_gen);
  reader(value.vs_gen_flags);
  reader(value.pass_flags);
}

template <typename Reader>
void Read(Reader &reader, AMAT::DX9S::v11::AmatDx9PassV11 &value) {
  reader(value.effects);
}

template <typename Reader>
void Read(Reader &reader, AMAT::DX9S::v11::AmatDx9TechniqueV11 &value) {
  reader(value.name);
  reader(value.passes);
  reader(value.max_ps_version);
  reader(value.max_vs_version);
}

template <typename Reader>
void Read(Reader &reader, AMAT::DX9S::v11::AmatDx9MaterialV11 &value) {
  reader(value.samplers);
  reader(value.shaders);
  reader(value.techniques);
  reader(value.use_legacy_bind_textures);
}
} // namespace de

} // namespace pf

#endif
