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

#if MAPC_BLOC_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace mapc::bloc::v0 {
struct PackMapBlockRecord {
  pf::filename filename;
};

struct PackMapBlock {
  pf::dword2 block_dims;
  std::vector<PackMapBlockRecord> block_record_array;
};
} // namespace mapc::bloc::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::bloc::v0::PackMapBlockRecord &value) {
  reader(value.filename);
}

template <typename Reader>
void Read(Reader &reader, mapc::bloc::v0::PackMapBlock &value) {
  reader(value.block_dims);
  reader(value.block_record_array);
}
} // namespace de

} // namespace pf

#endif
