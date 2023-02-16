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
#include <variant>

#ifndef MAPC_EDIT_MIN_VERSION
#define MAPC_EDIT_MIN_VERSION 16
#endif

#include "edit/edit_v10.hpp"
#include "edit/edit_v11.hpp"
#include "edit/edit_v12.hpp"
#include "edit/edit_v13.hpp"
#include "edit/edit_v14.hpp"
#include "edit/edit_v15.hpp"
#include "edit/edit_v16.hpp"
#include "edit/edit_v3.hpp"
#include "edit/edit_v4.hpp"
#include "edit/edit_v5.hpp"
#include "edit/edit_v6.hpp"
#include "edit/edit_v7.hpp"
#include "edit/edit_v8.hpp"
#include "edit/edit_v9.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace mapc::edit {

using MapEditData = std::variant<std::monostate
#if MAPC_EDIT_MIN_VERSION <= 3
                                 ,
                                 v3::MapEditData
#endif
#if MAPC_EDIT_MIN_VERSION <= 4
                                 ,
                                 v4::MapEditData
#endif
#if MAPC_EDIT_MIN_VERSION <= 5
                                 ,
                                 v5::MapEditData
#endif
#if MAPC_EDIT_MIN_VERSION <= 6
                                 ,
                                 v6::MapEditData
#endif
#if MAPC_EDIT_MIN_VERSION <= 7
                                 ,
                                 v7::MapEditData
#endif
#if MAPC_EDIT_MIN_VERSION <= 8
                                 ,
                                 v8::MapEditData
#endif
#if MAPC_EDIT_MIN_VERSION <= 9
                                 ,
                                 v9::MapEditData
#endif
#if MAPC_EDIT_MIN_VERSION <= 10
                                 ,
                                 v10::MapEditData
#endif
#if MAPC_EDIT_MIN_VERSION <= 11
                                 ,
                                 v11::MapEditData
#endif
#if MAPC_EDIT_MIN_VERSION <= 12
                                 ,
                                 v12::MapEditData
#endif
#if MAPC_EDIT_MIN_VERSION <= 13
                                 ,
                                 v13::MapEditData
#endif
#if MAPC_EDIT_MIN_VERSION <= 14
                                 ,
                                 v14::MapEditData
#endif
#if MAPC_EDIT_MIN_VERSION <= 15
                                 ,
                                 v15::MapEditData
#endif
#if MAPC_EDIT_MIN_VERSION <= 16
                                 ,
                                 v16::MapEditData
#endif
                                 >;

} // namespace mapc::edit

template <> struct Chunk<FourCC::mapc, FourCC::edit> {
  using Type = mapc::edit::MapEditData;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if MAPC_EDIT_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          mapc::edit::v3::MapEditData>(buf, b64);
#endif
#if MAPC_EDIT_MIN_VERSION <= 4
    case 4:
      return de::Deserializer<Config>::template Parse<
          mapc::edit::v4::MapEditData>(buf, b64);
#endif
#if MAPC_EDIT_MIN_VERSION <= 5
    case 5:
      return de::Deserializer<Config>::template Parse<
          mapc::edit::v5::MapEditData>(buf, b64);
#endif
#if MAPC_EDIT_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          mapc::edit::v6::MapEditData>(buf, b64);
#endif
#if MAPC_EDIT_MIN_VERSION <= 7
    case 7:
      return de::Deserializer<Config>::template Parse<
          mapc::edit::v7::MapEditData>(buf, b64);
#endif
#if MAPC_EDIT_MIN_VERSION <= 8
    case 8:
      return de::Deserializer<Config>::template Parse<
          mapc::edit::v8::MapEditData>(buf, b64);
#endif
#if MAPC_EDIT_MIN_VERSION <= 9
    case 9:
      return de::Deserializer<Config>::template Parse<
          mapc::edit::v9::MapEditData>(buf, b64);
#endif
#if MAPC_EDIT_MIN_VERSION <= 10
    case 10:
      return de::Deserializer<Config>::template Parse<
          mapc::edit::v10::MapEditData>(buf, b64);
#endif
#if MAPC_EDIT_MIN_VERSION <= 11
    case 11:
      return de::Deserializer<Config>::template Parse<
          mapc::edit::v11::MapEditData>(buf, b64);
#endif
#if MAPC_EDIT_MIN_VERSION <= 12
    case 12:
      return de::Deserializer<Config>::template Parse<
          mapc::edit::v12::MapEditData>(buf, b64);
#endif
#if MAPC_EDIT_MIN_VERSION <= 13
    case 13:
      return de::Deserializer<Config>::template Parse<
          mapc::edit::v13::MapEditData>(buf, b64);
#endif
#if MAPC_EDIT_MIN_VERSION <= 14
    case 14:
      return de::Deserializer<Config>::template Parse<
          mapc::edit::v14::MapEditData>(buf, b64);
#endif
#if MAPC_EDIT_MIN_VERSION <= 15
    case 15:
      return de::Deserializer<Config>::template Parse<
          mapc::edit::v15::MapEditData>(buf, b64);
#endif
#if MAPC_EDIT_MIN_VERSION <= 16
    case 16:
      return de::Deserializer<Config>::template Parse<
          mapc::edit::v16::MapEditData>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
