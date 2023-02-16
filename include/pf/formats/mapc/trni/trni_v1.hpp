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

#if MAPC_TRNI_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace mapc::trni::v1 {
struct PagedImageLayerDataV1 {
  pf::dword2 dims;
  pf::dword2 raw_dims;
  pf::dword disk_format;
  pf::dword raw_format;
  pf::dword stripped_format;
};

struct PagedImagePageDataV1 {
  pf::dword layer;
  pf::dword2 coord;
  pf::filename filename;
  pf::dword flags;
  pf::byte4 solid_color;
};

struct PagedImageTableDataV1 {
  std::vector<PagedImageLayerDataV1> layers;
  std::vector<PagedImagePageDataV1> pages;
};

struct PagedImageEmbeddedPageDataV1 {
  pf::dword layer;
  pf::dword2 coord;
  std::vector<pf::byte> raw_data;
  std::vector<pf::byte> compressed_data;
};

struct PagedImageEmbeddedPagesDataV1 {
  std::vector<PagedImageEmbeddedPageDataV1> pages;
};

struct MapTerrainImg {
  std::shared_ptr<PagedImageTableDataV1> table_data;
  std::shared_ptr<PagedImageEmbeddedPagesDataV1> page_data;
};
} // namespace mapc::trni::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::trni::v1::PagedImageLayerDataV1 &value) {
  reader(value.dims);
  reader(value.raw_dims);
  reader(value.disk_format);
  reader(value.raw_format);
  reader(value.stripped_format);
}

template <typename Reader>
void Read(Reader &reader, mapc::trni::v1::PagedImagePageDataV1 &value) {
  reader(value.layer);
  reader(value.coord);
  reader(value.filename);
  reader(value.flags);
  reader(value.solid_color);
}

template <typename Reader>
void Read(Reader &reader, mapc::trni::v1::PagedImageTableDataV1 &value) {
  reader(value.layers);
  reader(value.pages);
}

template <typename Reader>
void Read(Reader &reader, mapc::trni::v1::PagedImageEmbeddedPageDataV1 &value) {
  reader(value.layer);
  reader(value.coord);
  reader(value.raw_data);
  reader(value.compressed_data);
}

template <typename Reader>
void Read(Reader &reader,
          mapc::trni::v1::PagedImageEmbeddedPagesDataV1 &value) {
  reader(value.pages);
}

template <typename Reader>
void Read(Reader &reader, mapc::trni::v1::MapTerrainImg &value) {
  reader(value.table_data);
  reader(value.page_data);
}
} // namespace de

} // namespace pf

#endif
