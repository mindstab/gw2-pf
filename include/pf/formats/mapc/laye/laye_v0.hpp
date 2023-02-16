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

#if MAPC_LAYE_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace mapc::laye::v0 {
struct PackMapLayerProp {
  pf::qword guid;
  std::vector<pf::dword> layer_ids;
};

struct PackMapLayer {
  pf::dword layer_id;
  std::vector<pf::dword4> meta_data;
};

struct PackMapLayers {
  std::vector<PackMapLayerProp> props;
  std::vector<PackMapLayer> layers;
};
} // namespace mapc::laye::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::laye::v0::PackMapLayerProp &value) {
  reader(value.guid);
  reader(value.layer_ids);
}

template <typename Reader>
void Read(Reader &reader, mapc::laye::v0::PackMapLayer &value) {
  reader(value.layer_id);
  reader(value.meta_data);
}

template <typename Reader>
void Read(Reader &reader, mapc::laye::v0::PackMapLayers &value) {
  reader(value.props);
  reader(value.layers);
}
} // namespace de

} // namespace pf

#endif
