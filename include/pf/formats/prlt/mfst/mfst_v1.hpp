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

#if PRLT_MFST_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace prlt::mfst::v1 {
struct ContentMapRedirectorV1 {
  pf::dword map_id;
  pf::dword token;
  pf::float3 position;
  float radius;
};

struct ContentMapModelV1 {
  pf::filename filename;
  pf::dword flags;
  pf::dword type;
  pf::qword permutation;
};

struct ContentMapStartV1 {
  pf::dword token;
  std::vector<ContentMapModelV1> model_array;
  pf::float3 position;
  float radius;
};

struct ContentMapV1 {
  pf::dword map_id;
  std::vector<ContentMapRedirectorV1> map_redirector_array;
  std::vector<ContentMapStartV1> map_start_array;
};

struct ContentPortalManifestV1 {
  std::vector<ContentMapV1> map_array;
};
} // namespace prlt::mfst::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, prlt::mfst::v1::ContentMapRedirectorV1 &value) {
  reader(value.map_id);
  reader(value.token);
  reader(value.position);
  reader(value.radius);
}

template <typename Reader>
void Read(Reader &reader, prlt::mfst::v1::ContentMapModelV1 &value) {
  reader(value.filename);
  reader(value.flags);
  reader(value.type);
  reader(value.permutation);
}

template <typename Reader>
void Read(Reader &reader, prlt::mfst::v1::ContentMapStartV1 &value) {
  reader(value.token);
  reader(value.model_array);
  reader(value.position);
  reader(value.radius);
}

template <typename Reader>
void Read(Reader &reader, prlt::mfst::v1::ContentMapV1 &value) {
  reader(value.map_id);
  reader(value.map_redirector_array);
  reader(value.map_start_array);
}

template <typename Reader>
void Read(Reader &reader, prlt::mfst::v1::ContentPortalManifestV1 &value) {
  reader(value.map_array);
}
} // namespace de

} // namespace pf

#endif
