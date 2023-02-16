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

#if ASND_ASND_MIN_VERSION <= 2

#include "pf/types.hpp"

namespace pf {
namespace ASND::ASND::v2 {
struct ReservedWaveformDataV2 {
  pf::dword reserved1;
  pf::dword reserved2;
  pf::dword reserved3;
  pf::dword reserved4;
};

struct WaveformDataV2 {
  float length;
  float offset;
  std::shared_ptr<ReservedWaveformDataV2> reserved_data;
  pf::dword reserved1;
  pf::dword reserved2;
  pf::dword crc;
  pf::dword num_samples;
  pf::dword loop_start;
  pf::dword loop_end;
  pf::dword flags;
  pf::byte format;
  pf::byte reserved3;
  pf::byte reserved4;
  pf::byte reserved5;
  pf::byte num_channels;
  pf::byte reserved6;
  pf::byte reserved7;
  pf::byte reserved8;
  std::vector<pf::byte> audio_data;
  std::vector<pf::byte> other_data;
};
} // namespace ASND::ASND::v2

namespace de {
template <typename Reader>
void Read(Reader &reader, ASND::ASND::v2::ReservedWaveformDataV2 &value) {
  reader(value.reserved1);
  reader(value.reserved2);
  reader(value.reserved3);
  reader(value.reserved4);
}

template <typename Reader>
void Read(Reader &reader, ASND::ASND::v2::WaveformDataV2 &value) {
  reader(value.length);
  reader(value.offset);
  reader(value.reserved_data);
  reader(value.reserved1);
  reader(value.reserved2);
  reader(value.crc);
  reader(value.num_samples);
  reader(value.loop_start);
  reader(value.loop_end);
  reader(value.flags);
  reader(value.format);
  reader(value.reserved3);
  reader(value.reserved4);
  reader(value.reserved5);
  reader(value.num_channels);
  reader(value.reserved6);
  reader(value.reserved7);
  reader(value.reserved8);
  reader(value.audio_data);
  reader(value.other_data);
}
} // namespace de

} // namespace pf

#endif
