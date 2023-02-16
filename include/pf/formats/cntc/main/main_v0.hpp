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

#if CNTC_MAIN_MIN_VERSION <= 0

#include "pf/types.hpp"

namespace pf {
namespace cntc::Main::v0 {
struct PackContentTypeInfo {
  pf::dword guid_offset;
  pf::dword uid_offset;
  pf::dword data_id_offset;
  pf::dword name_offset;
  pf::byte track_references;
};

struct PackContentNamespace {
  pf::wstring name;
  pf::dword domain;
  pf::dword parent_index;
};

struct PackContentIndexEntry {
  pf::dword type;
  pf::dword offset;
  pf::dword namespace_index;
  pf::dword root_index;
};

struct PackContentLocalOffsetFixup {
  pf::dword reloc_offset;
};

struct PackContentExternalOffsetFixup {
  pf::dword reloc_offset;
  pf::dword target_file_index;
};

struct PackContentFileIndexFixup {
  pf::dword reloc_offset;
};

struct PackContentStringIndexFixup {
  pf::dword reloc_offset;
};

struct PackContentTrackedReference {
  pf::dword source_offset;
  pf::dword target_file_index;
  pf::dword target_offset;
};

struct PackContent {
  pf::dword flags;
  std::vector<PackContentTypeInfo> type_infos;
  std::vector<PackContentNamespace> namespaces;
  std::vector<pf::fileref> file_refs;
  std::vector<PackContentIndexEntry> index_entries;
  std::vector<PackContentLocalOffsetFixup> local_offsets;
  std::vector<PackContentExternalOffsetFixup> external_offsets;
  std::vector<PackContentFileIndexFixup> file_indices;
  std::vector<PackContentStringIndexFixup> string_indices;
  std::vector<PackContentTrackedReference> tracked_references;
  std::vector<pf::wstring> strings;
  std::vector<pf::byte> content;
};
} // namespace cntc::Main::v0

namespace de {
template <typename Reader>
void Read(Reader &reader, cntc::Main::v0::PackContentTypeInfo &value) {
  reader(value.guid_offset);
  reader(value.uid_offset);
  reader(value.data_id_offset);
  reader(value.name_offset);
  reader(value.track_references);
}

template <typename Reader>
void Read(Reader &reader, cntc::Main::v0::PackContentNamespace &value) {
  reader(value.name);
  reader(value.domain);
  reader(value.parent_index);
}

template <typename Reader>
void Read(Reader &reader, cntc::Main::v0::PackContentIndexEntry &value) {
  reader(value.type);
  reader(value.offset);
  reader(value.namespace_index);
  reader(value.root_index);
}

template <typename Reader>
void Read(Reader &reader, cntc::Main::v0::PackContentLocalOffsetFixup &value) {
  reader(value.reloc_offset);
}

template <typename Reader>
void Read(Reader &reader,
          cntc::Main::v0::PackContentExternalOffsetFixup &value) {
  reader(value.reloc_offset);
  reader(value.target_file_index);
}

template <typename Reader>
void Read(Reader &reader, cntc::Main::v0::PackContentFileIndexFixup &value) {
  reader(value.reloc_offset);
}

template <typename Reader>
void Read(Reader &reader, cntc::Main::v0::PackContentStringIndexFixup &value) {
  reader(value.reloc_offset);
}

template <typename Reader>
void Read(Reader &reader, cntc::Main::v0::PackContentTrackedReference &value) {
  reader(value.source_offset);
  reader(value.target_file_index);
  reader(value.target_offset);
}

template <typename Reader>
void Read(Reader &reader, cntc::Main::v0::PackContent &value) {
  reader(value.flags);
  reader(value.type_infos);
  reader(value.namespaces);
  reader(value.file_refs);
  reader(value.index_entries);
  reader(value.local_offsets);
  reader(value.external_offsets);
  reader(value.file_indices);
  reader(value.string_indices);
  reader(value.tracked_references);
  reader(value.strings);
  reader(value.content);
}
} // namespace de

} // namespace pf

#endif
