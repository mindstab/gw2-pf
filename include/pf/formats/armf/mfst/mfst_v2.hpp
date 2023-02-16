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

#if ARMF_MFST_MIN_VERSION <= 2

#include "pf/types.hpp"

namespace pf {
namespace ARMF::MFST::v2 {
struct PackAssetManifestRecordV2 {
  pf::dword base_id;
  pf::dword file_id;
  pf::dword size;
};

struct PackAssetManifestStreamV2 {
  pf::dword parent_base_id;
  pf::dword stream_base_id;
};

struct PackAssetManifestV2 {
  pf::dword build_id;
  std::vector<PackAssetManifestRecordV2> records;
  std::vector<PackAssetManifestStreamV2> streams;
  std::vector<PackAssetManifestRecordV2> no_delta_records;
};
} // namespace ARMF::MFST::v2

namespace de {
template <typename Reader>
void Read(Reader &reader, ARMF::MFST::v2::PackAssetManifestRecordV2 &value) {
  reader(value.base_id);
  reader(value.file_id);
  reader(value.size);
}

template <typename Reader>
void Read(Reader &reader, ARMF::MFST::v2::PackAssetManifestStreamV2 &value) {
  reader(value.parent_base_id);
  reader(value.stream_base_id);
}

template <typename Reader>
void Read(Reader &reader, ARMF::MFST::v2::PackAssetManifestV2 &value) {
  reader(value.build_id);
  reader(value.records);
  reader(value.streams);
  reader(value.no_delta_records);
}
} // namespace de

} // namespace pf

#endif
