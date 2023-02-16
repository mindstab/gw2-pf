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

#if AMAT_BGFX_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace AMAT::BGFX::v0 {
struct AmatGfxShaderConstant {
  pf::dword token;
};

struct AmatGfxSamplerConstant {
  pf::qword token;
  pf::dword state_index;
  pf::dword texture_index;
  pf::dword texture_slot;
};

struct AmatGfxShaderBinary {
  std::vector<pf::byte> data;
  std::vector<AmatGfxShaderConstant> constants;
  std::vector<AmatGfxSamplerConstant> samplers;
};

struct AmatGfxShader {
  pf::dword is_pixel_shader;
  AmatGfxShaderBinary dx_shader;
  AmatGfxShaderBinary osx_shader;
};

struct AmatGfxSamplerState {
  pf::dword state;
};

struct AmatGfxVertexShaderVariant {
  pf::dword variant;
  pf::dword vertex_shader_index;
};

struct AmatGfxEffect {
  pf::qword token;
  pf::qword render_state;
  pf::dword shader_pass_flags;
  pf::dword pixel_shader_index;
  std::vector<AmatGfxVertexShaderVariant> vertex_shader_variants;
};

struct AmatGfxPass {
  std::vector<AmatGfxEffect> effects;
};

struct AmatGfxTechnique {
  pf::dword quality;
  std::vector<AmatGfxPass> passes;
};

struct AmatGfxMaterial {
  std::vector<AmatGfxShader> shaders;
  std::vector<AmatGfxSamplerState> samplers;
  std::vector<AmatGfxTechnique> techniques;
};
} // namespace AMAT::BGFX::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, AMAT::BGFX::v0::AmatGfxShaderConstant &value) {
  reader(value.token);
}

template <typename Reader>
void Read(Reader &reader, AMAT::BGFX::v0::AmatGfxSamplerConstant &value) {
  reader(value.token);
  reader(value.state_index);
  reader(value.texture_index);
  reader(value.texture_slot);
}

template <typename Reader>
void Read(Reader &reader, AMAT::BGFX::v0::AmatGfxShaderBinary &value) {
  reader(value.data);
  reader(value.constants);
  reader(value.samplers);
}

template <typename Reader>
void Read(Reader &reader, AMAT::BGFX::v0::AmatGfxShader &value) {
  reader(value.is_pixel_shader);
  reader(value.dx_shader);
  reader(value.osx_shader);
}

template <typename Reader>
void Read(Reader &reader, AMAT::BGFX::v0::AmatGfxSamplerState &value) {
  reader(value.state);
}

template <typename Reader>
void Read(Reader &reader, AMAT::BGFX::v0::AmatGfxVertexShaderVariant &value) {
  reader(value.variant);
  reader(value.vertex_shader_index);
}

template <typename Reader>
void Read(Reader &reader, AMAT::BGFX::v0::AmatGfxEffect &value) {
  reader(value.token);
  reader(value.render_state);
  reader(value.shader_pass_flags);
  reader(value.pixel_shader_index);
  reader(value.vertex_shader_variants);
}

template <typename Reader>
void Read(Reader &reader, AMAT::BGFX::v0::AmatGfxPass &value) {
  reader(value.effects);
}

template <typename Reader>
void Read(Reader &reader, AMAT::BGFX::v0::AmatGfxTechnique &value) {
  reader(value.quality);
  reader(value.passes);
}

template <typename Reader>
void Read(Reader &reader, AMAT::BGFX::v0::AmatGfxMaterial &value) {
  reader(value.shaders);
  reader(value.samplers);
  reader(value.techniques);
}
} // namespace de

} // namespace pf

#endif
