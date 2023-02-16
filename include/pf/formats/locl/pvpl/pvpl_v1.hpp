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

#if LOCL_PVPL_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace locl::pvpl::v1 {
struct PrefPackPvpFilter {
  pf::dword flags_disallowed;
  pf::dword flags_required;
  std::vector<pf::dword> maps_disallowed;
  std::vector<pf::dword> maps_required;
  pf::dword score_limit_range;
  pf::wstring name;
  pf::word reserved_slots_range;
  pf::word respawn_time_range;
  pf::word time_limit_range;
  pf::byte team_size_range;
  pf::byte min_player_range;
};

struct PrefPackPvp {
  std::vector<pf::dword4> favorites;
  std::vector<pf::dword4> recently_played;
  std::vector<PrefPackPvpFilter> filters;
};
} // namespace locl::pvpl::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, locl::pvpl::v1::PrefPackPvpFilter &value) {
  reader(value.flags_disallowed);
  reader(value.flags_required);
  reader(value.maps_disallowed);
  reader(value.maps_required);
  reader(value.score_limit_range);
  reader(value.name);
  reader(value.reserved_slots_range);
  reader(value.respawn_time_range);
  reader(value.time_limit_range);
  reader(value.team_size_range);
  reader(value.min_player_range);
}

template <typename Reader>
void Read(Reader &reader, locl::pvpl::v1::PrefPackPvp &value) {
  reader(value.favorites);
  reader(value.recently_played);
  reader(value.filters);
}
} // namespace de

} // namespace pf

#endif
