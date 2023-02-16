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

#if MAPC_TLFS_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace mapc::tlfs::v0 {
struct PackMapToolFsFileV0 {
  pf::fileref filename;
  pf::qword time;
  std::vector<pf::byte> data_ptr;
};

struct PackMapToolFsV0 {
  std::vector<PackMapToolFsFileV0> file_ptr;
};
} // namespace mapc::tlfs::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::tlfs::v0::PackMapToolFsFileV0 &value) {
  reader(value.filename);
  reader(value.time);
  reader(value.data_ptr);
}

template <typename Reader>
void Read(Reader &reader, mapc::tlfs::v0::PackMapToolFsV0 &value) {
  reader(value.file_ptr);
}
} // namespace de

} // namespace pf

#endif
