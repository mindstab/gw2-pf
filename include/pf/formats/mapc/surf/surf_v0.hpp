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

#if MAPC_SURF_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace mapc::surf::v0 {
struct MapSurfaceMeta {
  pf::word index;
  pf::byte descriptor;
  pf::byte data;
};

struct MapSurfaceChunk {
  std::array<pf::dword, 3> coord;
  std::vector<MapSurfaceMeta> metadata;
  std::vector<pf::byte> type_data;
};

struct MapSurfaces {
  std::vector<MapSurfaceChunk> chunk_data;
  std::vector<pf::qword> type_data;
};
} // namespace mapc::surf::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::surf::v0::MapSurfaceMeta &value) {
  reader(value.index);
  reader(value.descriptor);
  reader(value.data);
}

template <typename Reader>
void Read(Reader &reader, mapc::surf::v0::MapSurfaceChunk &value) {
  reader(value.coord);
  reader(value.metadata);
  reader(value.type_data);
}

template <typename Reader>
void Read(Reader &reader, mapc::surf::v0::MapSurfaces &value) {
  reader(value.chunk_data);
  reader(value.type_data);
}
} // namespace de

} // namespace pf

#endif
