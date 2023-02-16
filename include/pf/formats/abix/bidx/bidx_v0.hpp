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

#if ABIX_BIDX_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace ABIX::BIDX::v0 {
struct BankFileNameDataV0 {
  pf::filename file_name;
};

struct BankLanguageDataV0 {
  std::vector<BankFileNameDataV0> bank_file_name;
};

struct BankIndexDataV0 {
  std::vector<BankLanguageDataV0> bank_language;
};
} // namespace ABIX::BIDX::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, ABIX::BIDX::v0::BankFileNameDataV0 &value) {
  reader(value.file_name);
}

template <typename Reader>
void Read(Reader &reader, ABIX::BIDX::v0::BankLanguageDataV0 &value) {
  reader(value.bank_file_name);
}

template <typename Reader>
void Read(Reader &reader, ABIX::BIDX::v0::BankIndexDataV0 &value) {
  reader(value.bank_language);
}
} // namespace de

} // namespace pf

#endif
