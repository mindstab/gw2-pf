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

#if MAPC_RESO_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace mapc::reso::v0 {
struct PackMapResourceMapNodeItemV0 {
  pf::filename filename;
  pf::dword type;
};

struct PackMapResourceMapNodeV0 {
  pf::float3 position;
  pf::dword flags;
  std::vector<PackMapResourceMapNodeItemV0> item_array;
};

struct PackMapResourceMapV0 {
  std::vector<PackMapResourceMapNodeV0> node_array;
};
} // namespace mapc::reso::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::reso::v0::PackMapResourceMapNodeItemV0 &value) {
  reader(value.filename);
  reader(value.type);
}

template <typename Reader>
void Read(Reader &reader, mapc::reso::v0::PackMapResourceMapNodeV0 &value) {
  reader(value.position);
  reader(value.flags);
  reader(value.item_array);
}

template <typename Reader>
void Read(Reader &reader, mapc::reso::v0::PackMapResourceMapV0 &value) {
  reader(value.node_array);
}
} // namespace de

} // namespace pf

#endif
