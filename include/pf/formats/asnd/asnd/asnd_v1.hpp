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

#if ASND_ASND_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace ASND::ASND::v1 {
struct WaveformDataV1 {
  float length;
  float offset;
  pf::dword crc;
  pf::dword num_samples;
  pf::dword loop_start;
  pf::dword loop_end;
  pf::dword flags;
  pf::byte format;
  pf::byte note_base;
  pf::byte note_high;
  pf::byte note_low;
  pf::byte num_channels;
  pf::byte reserved1;
  pf::byte reserved2;
  pf::byte reserved3;
  std::vector<pf::byte> audio_data;
  std::vector<pf::byte> other_data;
};
} // namespace ASND::ASND::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, ASND::ASND::v1::WaveformDataV1 &value) {
  reader(value.length);
  reader(value.offset);
  reader(value.crc);
  reader(value.num_samples);
  reader(value.loop_start);
  reader(value.loop_end);
  reader(value.flags);
  reader(value.format);
  reader(value.note_base);
  reader(value.note_high);
  reader(value.note_low);
  reader(value.num_channels);
  reader(value.reserved1);
  reader(value.reserved2);
  reader(value.reserved3);
  reader(value.audio_data);
  reader(value.other_data);
}
} // namespace de

} // namespace pf

#endif
