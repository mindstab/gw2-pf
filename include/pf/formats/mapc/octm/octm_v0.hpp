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

#if MAPC_OCTM_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace mapc::octm::v0 {
struct MapOcclusionTome {
  pf::dword enable_tome_queries;
  std::vector<pf::byte> tome;
  std::vector<pf::byte> prop_id_map;
  std::vector<pf::byte> reserved;
};
} // namespace mapc::octm::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::octm::v0::MapOcclusionTome &value) {
  reader(value.enable_tome_queries);
  reader(value.tome);
  reader(value.prop_id_map);
  reader(value.reserved);
}
} // namespace de

} // namespace pf

#endif
