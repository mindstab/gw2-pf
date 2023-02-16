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

#if TXTV_VARI_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace txtV::vari::v0 {
struct TextPackVariant {
  pf::dword text_id;
  std::vector<pf::dword> variant_text_ids;
};

struct TextPackVariants {
  std::vector<TextPackVariant> variants;
};
} // namespace txtV::vari::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, txtV::vari::v0::TextPackVariant &value) {
  reader(value.text_id);
  reader(value.variant_text_ids);
}

template <typename Reader>
void Read(Reader &reader, txtV::vari::v0::TextPackVariants &value) {
  reader(value.variants);
}
} // namespace de

} // namespace pf

#endif
