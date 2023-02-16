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

#if ARMF_ARMF_MIN_VERSION <= 1

#include "pf/types.hpp"

namespace pf {
namespace ARMF::ARMF::v1 {
struct PackAssetManifestFile {
  pf::dword base_id;
  pf::dword file_id;
  pf::dword size;
  pf::dword flags;
  pf::wstring name;
};

struct PackAssetExtraFile {
  pf::dword base_id;
  pf::dword file_id;
  pf::dword size;
  pf::dword file_type;
};

struct PackAssetRootManifest {
  pf::dword build_id;
  std::vector<PackAssetManifestFile> manifests;
  std::vector<PackAssetExtraFile> extra_files;
};
} // namespace ARMF::ARMF::v1

namespace de {
template <typename Reader>
void Read(Reader &reader, ARMF::ARMF::v1::PackAssetManifestFile &value) {
  reader(value.base_id);
  reader(value.file_id);
  reader(value.size);
  reader(value.flags);
  reader(value.name);
}

template <typename Reader>
void Read(Reader &reader, ARMF::ARMF::v1::PackAssetExtraFile &value) {
  reader(value.base_id);
  reader(value.file_id);
  reader(value.size);
  reader(value.file_type);
}

template <typename Reader>
void Read(Reader &reader, ARMF::ARMF::v1::PackAssetRootManifest &value) {
  reader(value.build_id);
  reader(value.manifests);
  reader(value.extra_files);
}
} // namespace de

} // namespace pf

#endif
