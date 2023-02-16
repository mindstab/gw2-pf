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

#if MAPC_RESO_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace mapc::reso::v1 {
struct PackMapResourceMapNodeItemV1 {
  pf::filename filename;
  pf::dword type;
  pf::qword permutation;
};

struct PackMapResourceMapNodeV1 {
  pf::float3 position;
  pf::dword flags;
  std::vector<PackMapResourceMapNodeItemV1> item_array;
};

struct PackMapResourceMapV1 {
  std::vector<PackMapResourceMapNodeV1> node_array;
};
} // namespace mapc::reso::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::reso::v1::PackMapResourceMapNodeItemV1 &value) {
  reader(value.filename);
  reader(value.type);
  reader(value.permutation);
}

template <typename Reader>
void Read(Reader &reader, mapc::reso::v1::PackMapResourceMapNodeV1 &value) {
  reader(value.position);
  reader(value.flags);
  reader(value.item_array);
}

template <typename Reader>
void Read(Reader &reader, mapc::reso::v1::PackMapResourceMapV1 &value) {
  reader(value.node_array);
}
} // namespace de

} // namespace pf

#endif
