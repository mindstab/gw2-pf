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

#if CHAR_UXCH_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace char ::uxch::v1 {
  struct PrefPackUxChar {
    pf::byte flags;
    pf::word inventory_bag_state;
    std::array<pf::word, 8> dye_favorites;
  };
} // namespace char::uxch::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, char ::uxch::v1::PrefPackUxChar &value) {
  reader(value.flags);
  reader(value.inventory_bag_state);
  reader(value.dye_favorites);
}
} // namespace de

} // namespace pf

#endif
