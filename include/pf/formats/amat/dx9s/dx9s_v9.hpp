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

#if AMAT_DX9S_MIN_VERSION <= 9

#include "pf/types.hpp"

namespace pf {
namespace AMAT::DX9S::v9 {
struct AmatDx9SamplerV9 {
  pf::dword texture_index;
  std::vector<pf::dword> state;
};

struct AmatDx9ShaderV9 {
  std::vector<pf::dword> shader;
  std::vector<pf::dword> const_registers;
  std::vector<pf::dword> const_tokens;
};

struct AmatDx9EffectV9 {
  pf::qword token;
  std::vector<pf::dword> render_states;
  std::vector<pf::dword> sampler_index;
  pf::dword pixel_shader;
  pf::dword vertex_shader;
  std::vector<pf::dword> tex_gen;
  std::vector<pf::dword> tex_transform;
  pf::dword vs_gen_flags;
  pf::dword pass_flags;
};

struct AmatDx9PassV9 {
  std::vector<std::shared_ptr<AmatDx9EffectV9>> effects;
};

struct AmatDx9TechniqueV9 {
  pf::cstring name;
  std::vector<AmatDx9PassV9> passes;
  pf::word max_ps_version;
  pf::word max_vs_version;
};

struct AmatDx9MaterialV9 {
  std::vector<AmatDx9SamplerV9> samplers;
  std::vector<AmatDx9ShaderV9> shaders;
  std::vector<AmatDx9TechniqueV9> techniques;
};
} // namespace AMAT::DX9S::v9

namespace de {
template <typename Reader>
void Read(Reader &reader, AMAT::DX9S::v9::AmatDx9SamplerV9 &value) {
  reader(value.texture_index);
  reader(value.state);
}

template <typename Reader>
void Read(Reader &reader, AMAT::DX9S::v9::AmatDx9ShaderV9 &value) {
  reader(value.shader);
  reader(value.const_registers);
  reader(value.const_tokens);
}

template <typename Reader>
void Read(Reader &reader, AMAT::DX9S::v9::AmatDx9EffectV9 &value) {
  reader(value.token);
  reader(value.render_states);
  reader(value.sampler_index);
  reader(value.pixel_shader);
  reader(value.vertex_shader);
  reader(value.tex_gen);
  reader(value.tex_transform);
  reader(value.vs_gen_flags);
  reader(value.pass_flags);
}

template <typename Reader>
void Read(Reader &reader, AMAT::DX9S::v9::AmatDx9PassV9 &value) {
  reader(value.effects);
}

template <typename Reader>
void Read(Reader &reader, AMAT::DX9S::v9::AmatDx9TechniqueV9 &value) {
  reader(value.name);
  reader(value.passes);
  reader(value.max_ps_version);
  reader(value.max_vs_version);
}

template <typename Reader>
void Read(Reader &reader, AMAT::DX9S::v9::AmatDx9MaterialV9 &value) {
  reader(value.samplers);
  reader(value.shaders);
  reader(value.techniques);
}
} // namespace de

} // namespace pf

#endif
