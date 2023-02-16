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

#if ACCT_DLOG_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace acct::dlog::v0 {
struct PrefPackDialogEntry {
  pf::byte flags;
  pf::word left;
  pf::word right;
  pf::word top;
  pf::word bottom;
};

struct PrefPackDialog {
  std::vector<PrefPackDialogEntry> entry_array;
};
} // namespace acct::dlog::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, acct::dlog::v0::PrefPackDialogEntry &value) {
  reader(value.flags);
  reader(value.left);
  reader(value.right);
  reader(value.top);
  reader(value.bottom);
}

template <typename Reader>
void Read(Reader &reader, acct::dlog::v0::PrefPackDialog &value) {
  reader(value.entry_array);
}
} // namespace de

} // namespace pf

#endif
