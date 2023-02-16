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

#if ACCT_UXAC_MIN_VERSION <= 9

#include "pf/types.hpp"

namespace pf {
namespace acct::uxac::v9 {
struct PrefPackUxAccount {
  pf::qword flags;
  pf::byte clock_mode;
  pf::word camera_distance;
  pf::byte camera_dolly_sensitivity;
  pf::byte camera_fov;
  pf::byte camera_rotation;
  pf::byte camera_shift;
  pf::byte camera_shift_vertical;
  pf::byte camera_occlusion_detection;
  pf::byte guild_roster_filter;
  pf::byte pvp_server_filter;
  pf::byte team_color_mode;
  pf::byte team_scale_mode;
  pf::word world_map_filter_bits;
  std::vector<pf::dword> achievements;
  pf::byte ground_targeting_mode;
  pf::byte content_direction_mode;
};
} // namespace acct::uxac::v9

namespace de {
template <typename Reader>
void Read(Reader &reader, acct::uxac::v9::PrefPackUxAccount &value) {
  reader(value.flags);
  reader(value.clock_mode);
  reader(value.camera_distance);
  reader(value.camera_dolly_sensitivity);
  reader(value.camera_fov);
  reader(value.camera_rotation);
  reader(value.camera_shift);
  reader(value.camera_shift_vertical);
  reader(value.camera_occlusion_detection);
  reader(value.guild_roster_filter);
  reader(value.pvp_server_filter);
  reader(value.team_color_mode);
  reader(value.team_scale_mode);
  reader(value.world_map_filter_bits);
  reader(value.achievements);
  reader(value.ground_targeting_mode);
  reader(value.content_direction_mode);
}
} // namespace de

} // namespace pf

#endif
