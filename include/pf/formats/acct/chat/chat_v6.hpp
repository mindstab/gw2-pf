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

#if ACCT_CHAT_MIN_VERSION <= 6

#include "pf/types.hpp"

namespace pf {
namespace acct::chat::v6 {
struct PrefPackChatTab {
  pf::byte target_channel;
  pf::qword channel_mask;
  pf::wstring name;
  pf::byte flags;
};

struct PrefPackChat {
  pf::byte flags;
  pf::byte filter_level;
  pf::byte text_size;
  pf::byte selected;
  std::vector<PrefPackChatTab> tabs;
  pf::word width;
  pf::word height;
  std::vector<pf::dword4> guild_channel_mappings;
};
} // namespace acct::chat::v6

namespace de {
template <typename Reader>
void Read(Reader &reader, acct::chat::v6::PrefPackChatTab &value) {
  reader(value.target_channel);
  reader(value.channel_mask);
  reader(value.name);
  reader(value.flags);
}

template <typename Reader>
void Read(Reader &reader, acct::chat::v6::PrefPackChat &value) {
  reader(value.flags);
  reader(value.filter_level);
  reader(value.text_size);
  reader(value.selected);
  reader(value.tabs);
  reader(value.width);
  reader(value.height);
  reader(value.guild_channel_mappings);
}
} // namespace de

} // namespace pf

#endif
