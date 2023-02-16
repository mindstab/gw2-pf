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

#if PIMG_PGTB_MIN_VERSION <= 2

#include "pf/types.hpp"

namespace pf {
namespace PIMG::PGTB::v2 {
struct PagedImageLayerDataV2 {
  pf::dword2 dims;
  pf::dword2 raw_dims;
  pf::dword disk_format;
  pf::dword raw_format;
  pf::dword stripped_format;
};

struct PagedImagePageDataV2 {
  pf::dword layer;
  pf::dword2 coord;
  pf::filename filename;
  pf::dword flags;
  pf::byte4 solid_color;
};

struct PagedImageTableDataV2 {
  std::vector<PagedImageLayerDataV2> layers;
  std::vector<PagedImagePageDataV2> pages;
  pf::dword flags;
};
} // namespace PIMG::PGTB::v2

namespace de {
template <typename Reader>
void Read(Reader &reader, PIMG::PGTB::v2::PagedImageLayerDataV2 &value) {
  reader(value.dims);
  reader(value.raw_dims);
  reader(value.disk_format);
  reader(value.raw_format);
  reader(value.stripped_format);
}

template <typename Reader>
void Read(Reader &reader, PIMG::PGTB::v2::PagedImagePageDataV2 &value) {
  reader(value.layer);
  reader(value.coord);
  reader(value.filename);
  reader(value.flags);
  reader(value.solid_color);
}

template <typename Reader>
void Read(Reader &reader, PIMG::PGTB::v2::PagedImageTableDataV2 &value) {
  reader(value.layers);
  reader(value.pages);
  reader(value.flags);
}
} // namespace de

} // namespace pf

#endif
