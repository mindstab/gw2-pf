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

#if MMET_MAIN_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace mMet::Main::v0 {
struct PackMapMetadataMap {
  pf::word map_id;
  pf::byte map_type;
};

struct PackMapMetadata {
  std::vector<PackMapMetadataMap> maps;
};
} // namespace mMet::Main::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, mMet::Main::v0::PackMapMetadataMap &value) {
  reader(value.map_id);
  reader(value.map_type);
}

template <typename Reader>
void Read(Reader &reader, mMet::Main::v0::PackMapMetadata &value) {
  reader(value.maps);
}
} // namespace de

} // namespace pf

#endif
