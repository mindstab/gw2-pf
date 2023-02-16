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

#include <expected>

#include "pf/magic.hpp"

namespace pf {

struct FileHeader {
  static constexpr uint16_t kPackFileMagic = details::Magic("PF");

  uint16_t magic = kPackFileMagic;
  uint16_t flags = 0;
  uint16_t reserved = 0;
  uint16_t header_size = sizeof(FileHeader);
  FourCC file_type;
};

static_assert(sizeof(FileHeader) == 12);

struct ChunkHeader {
  FourCC chunk_type;
  uint32_t next_chunk_offset;
  uint16_t version;
  uint16_t header_size;
  uint32_t fixup_offset;
};

static_assert(sizeof(ChunkHeader) == 16);

enum class Error {
  kInvalidFileType,
  kInvalidHeaderSize,
  kInvalidVersion,
};

template <typename T>
using Result = std::expected<T, Error>;

}  // namespace pf
