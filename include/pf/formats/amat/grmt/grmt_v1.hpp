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

#if AMAT_GRMT_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace AMAT::GRMT::v1 {
struct AmatGrV1 {
  pf::byte tex_array_range;
  pf::byte tex_count;
  pf::byte tex_transform_range;
  pf::byte sort_order;
  pf::dword flags;
  pf::dword tex_type;
  std::array<pf::dword, 4> texture_masks;
};
} // namespace AMAT::GRMT::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, AMAT::GRMT::v1::AmatGrV1 &value) {
  reader(value.tex_array_range);
  reader(value.tex_count);
  reader(value.tex_transform_range);
  reader(value.sort_order);
  reader(value.flags);
  reader(value.tex_type);
  reader(value.texture_masks);
}
} // namespace de

} // namespace pf

#endif
