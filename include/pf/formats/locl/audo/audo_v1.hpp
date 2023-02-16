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

#if LOCL_AUDO_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace locl::audo::v1 {
struct PrefPackAudio {
  pf::uuid device_id;
  pf::byte volume_dialog;
  pf::byte volume_effect;
  pf::byte volume_environment;
  pf::byte volume_master;
  pf::byte volume_music;
  pf::byte volume_ui;
  pf::byte voip_ducking;
  pf::byte music_interval;
  pf::byte mix_buffer_size;
  pf::byte output_format;
  pf::byte output_type;
  pf::byte quality;
  pf::byte speaker_mode;
  pf::byte flags;
};
} // namespace locl::audo::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, locl::audo::v1::PrefPackAudio &value) {
  reader(value.device_id);
  reader(value.volume_dialog);
  reader(value.volume_effect);
  reader(value.volume_environment);
  reader(value.volume_master);
  reader(value.volume_music);
  reader(value.volume_ui);
  reader(value.voip_ducking);
  reader(value.music_interval);
  reader(value.mix_buffer_size);
  reader(value.output_format);
  reader(value.output_type);
  reader(value.quality);
  reader(value.speaker_mode);
  reader(value.flags);
}
} // namespace de

} // namespace pf

#endif
