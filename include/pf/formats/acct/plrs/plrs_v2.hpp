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

#if ACCT_PLRS_MIN_VERSION <= 2

#include "pf/types.hpp"

namespace pf {
namespace acct::plrs::v2 {
struct PrefPackPlayerSummary {
  pf::dword awesome_points;
  pf::byte legendary_items;
  pf::byte map_progress;
  pf::dword pvp_glory;
  pf::byte story_complete;
  pf::dword wvw_kills;
  pf::dword char_select_medal_dirty_bits;
  pf::dword addiction_play_time_seconds;
  pf::dword addiction_time_stamp_seconds_utc2001;
  pf::byte ach_daily_complete_count;
  pf::dword ach_daily_expiration_time_stamp_seconds_utc2001;
  pf::byte ach_monthly_complete_count;
  pf::dword ach_monthly_expiration_time_stamp_seconds_utc2001;
  std::array<pf::byte, 3> ach_living_world_complete_count;
  std::array<pf::dword, 3> ach_living_world_category_id;
  pf::dword ach_unlocked_reward_bits;
};
} // namespace acct::plrs::v2

namespace de {
template <typename Reader>
void Read(Reader &reader, acct::plrs::v2::PrefPackPlayerSummary &value) {
  reader(value.awesome_points);
  reader(value.legendary_items);
  reader(value.map_progress);
  reader(value.pvp_glory);
  reader(value.story_complete);
  reader(value.wvw_kills);
  reader(value.char_select_medal_dirty_bits);
  reader(value.addiction_play_time_seconds);
  reader(value.addiction_time_stamp_seconds_utc2001);
  reader(value.ach_daily_complete_count);
  reader(value.ach_daily_expiration_time_stamp_seconds_utc2001);
  reader(value.ach_monthly_complete_count);
  reader(value.ach_monthly_expiration_time_stamp_seconds_utc2001);
  reader(value.ach_living_world_complete_count);
  reader(value.ach_living_world_category_id);
  reader(value.ach_unlocked_reward_bits);
}
} // namespace de

} // namespace pf

#endif
