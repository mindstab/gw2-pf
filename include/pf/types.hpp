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

#include <array>
#include <memory>
#include <string>
#include <vector>
#include <cstdint>

namespace pf {

using byte = std::uint8_t;
using byte3 = std::array<byte, 3>;
using byte4 = std::array<byte, 4>;

using word = std::uint16_t;
using word3 = std::array<word, 3>;

using dword = std::uint32_t;
using dword2 = std::array<dword, 2>;
using dword4 = std::array<dword, 4>;

using qword = std::uint64_t;

using float2 = std::array<float, 2>;
using float3 = std::array<float, 3>;
using float4 = std::array<float, 4>;

using uuid = std::array<byte, 16>;

static_assert(sizeof(char16_t) == 2);
using cstring = std::basic_string<char>;
using wstring = std::basic_string<char16_t>;

using filename = wstring;
using fileref = filename;

// external data

struct PackGrannyAnimationTypeV0 {
  std::vector<byte> animation;
};

struct PackGrannyAnimationTypeV1 {
  std::vector<byte> animation;
  std::vector<dword> pointers;
};

struct PackGrannyTrackMaskType {
  std::vector<byte> track_mask;
};

struct PackGrannyMirrorSpecType {
  std::vector<byte> mirror_spec;
};

struct PackGrannyMeshType {
  std::vector<byte> mesh;
};

struct PackVertexType {
  dword fvf;
  std::vector<byte> vertices;
};

struct PackBroadphaseType {
  std::vector<byte> broadphase_data;
};

struct PackMoppType {
  std::vector<byte> mopp_code_data;
};

namespace de {

template <typename Reader>
void Read(Reader& reader, PackGrannyAnimationTypeV0& value) {
  reader(value.animation);
}

template <typename Reader>
void Read(Reader& reader, PackGrannyAnimationTypeV1& value) {
  reader(value.animation);
  reader(value.pointers);
}

template <typename Reader>
void Read(Reader& reader, PackGrannyTrackMaskType& value) {
  reader(value.track_mask);
}

template <typename Reader>
void Read(Reader& reader, PackGrannyMirrorSpecType& value) {
  reader(value.mirror_spec);
}

template <typename Reader>
void Read(Reader& reader, PackGrannyMeshType& value) {
  reader(value.mesh);
}

template <typename Reader>
void Read(Reader& reader, PackVertexType& value) {
  reader(value.fvf);
  reader(value.vertices);
}

template <typename Reader>
void Read(Reader& reader, PackBroadphaseType& value) {
  reader(value.broadphase_data);
}

template <typename Reader>
void Read(Reader& reader, PackMoppType& value) {
  reader(value.mopp_code_data);
}
}  // namespace de

}  // namespace pf
