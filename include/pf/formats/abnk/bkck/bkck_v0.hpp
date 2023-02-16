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

#if ABNK_BKCK_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace ABNK::BKCK::v0 {
struct AsndFileDataV0 {
  pf::dword voice_id;
  pf::dword flags;
  pf::dword reserved1;
  pf::dword reserved2;
  float length;
  float offset;
  std::vector<pf::byte> audio_data;
};

struct BankFileDataV0 {
  pf::dword reserved1;
  pf::dword reserved2;
  std::vector<AsndFileDataV0> asnd_file;
};
} // namespace ABNK::BKCK::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, ABNK::BKCK::v0::AsndFileDataV0 &value) {
  reader(value.voice_id);
  reader(value.flags);
  reader(value.reserved1);
  reader(value.reserved2);
  reader(value.length);
  reader(value.offset);
  reader(value.audio_data);
}

template <typename Reader>
void Read(Reader &reader, ABNK::BKCK::v0::BankFileDataV0 &value) {
  reader(value.reserved1);
  reader(value.reserved2);
  reader(value.asnd_file);
}
} // namespace de

} // namespace pf

#endif
