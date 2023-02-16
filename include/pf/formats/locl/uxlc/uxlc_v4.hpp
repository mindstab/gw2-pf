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

#if LOCL_UXLC_MIN_VERSION <= 4

#include "pf/types.hpp"

namespace pf {
namespace locl::uxlc::v4 {
struct PrefPackUxLocal {
  pf::byte flags;
  pf::cstring cligate_name;
  pf::byte game_datacenter;
  pf::byte password_version;
  std::vector<pf::byte> password_hash;
  pf::wstring email;
  pf::wstring provider;
  pf::byte language_text;
  pf::byte language_audio;
  pf::byte territory;
  pf::byte ui_scale;
  pf::byte achievement_sort_order;
  pf::byte ach_watch_list_sort_order;
};
} // namespace locl::uxlc::v4

namespace de {
template <typename Reader>
void Read(Reader &reader, locl::uxlc::v4::PrefPackUxLocal &value) {
  reader(value.flags);
  reader(value.cligate_name);
  reader(value.game_datacenter);
  reader(value.password_version);
  reader(value.password_hash);
  reader(value.email);
  reader(value.provider);
  reader(value.language_text);
  reader(value.language_audio);
  reader(value.territory);
  reader(value.ui_scale);
  reader(value.achievement_sort_order);
  reader(value.ach_watch_list_sort_order);
}
} // namespace de

} // namespace pf

#endif
