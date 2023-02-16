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

#if PRLT_MFST_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace prlt::mfst::v0 {
struct ContentMapRedirectorV0 {
  pf::dword map_id;
  pf::dword token;
  pf::float3 position;
  float radius;
};

struct ContentMapModelV0 {
  pf::filename filename;
  pf::dword flags;
  pf::dword type;
};

struct ContentMapStartV0 {
  pf::dword token;
  std::vector<ContentMapModelV0> model_array;
  pf::float3 position;
  float radius;
};

struct ContentMapV0 {
  pf::dword map_id;
  std::vector<ContentMapRedirectorV0> map_redirector_array;
  std::vector<ContentMapStartV0> map_start_array;
};

struct ContentPortalManifestV0 {
  std::vector<ContentMapV0> map_array;
};
} // namespace prlt::mfst::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, prlt::mfst::v0::ContentMapRedirectorV0 &value) {
  reader(value.map_id);
  reader(value.token);
  reader(value.position);
  reader(value.radius);
}

template <typename Reader>
void Read(Reader &reader, prlt::mfst::v0::ContentMapModelV0 &value) {
  reader(value.filename);
  reader(value.flags);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, prlt::mfst::v0::ContentMapStartV0 &value) {
  reader(value.token);
  reader(value.model_array);
  reader(value.position);
  reader(value.radius);
}

template <typename Reader>
void Read(Reader &reader, prlt::mfst::v0::ContentMapV0 &value) {
  reader(value.map_id);
  reader(value.map_redirector_array);
  reader(value.map_start_array);
}

template <typename Reader>
void Read(Reader &reader, prlt::mfst::v0::ContentPortalManifestV0 &value) {
  reader(value.map_array);
}
} // namespace de

} // namespace pf

#endif
