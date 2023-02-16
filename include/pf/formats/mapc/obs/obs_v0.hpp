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

#if MAPC_OBS_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace mapc::obs::v0 {
struct PackMapEditCollision {
  pf::dword token;
  pf::dword flags;
  std::vector<pf::float3> bottm_vertices;
  std::vector<pf::float3> top_vertices;
};

struct MapObstacles {
  std::vector<PackMapEditCollision> obstacles;
};
} // namespace mapc::obs::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, mapc::obs::v0::PackMapEditCollision &value) {
  reader(value.token);
  reader(value.flags);
  reader(value.bottm_vertices);
  reader(value.top_vertices);
}

template <typename Reader>
void Read(Reader &reader, mapc::obs::v0::MapObstacles &value) {
  reader(value.obstacles);
}
} // namespace de

} // namespace pf

#endif
