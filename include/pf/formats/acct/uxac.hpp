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

#ifndef ACCT_UXAC_MIN_VERSION
#define ACCT_UXAC_MIN_VERSION 23
#endif

#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"
#include "uxac/uxac_v0.hpp"
#include "uxac/uxac_v1.hpp"
#include "uxac/uxac_v10.hpp"
#include "uxac/uxac_v11.hpp"
#include "uxac/uxac_v12.hpp"
#include "uxac/uxac_v13.hpp"
#include "uxac/uxac_v14.hpp"
#include "uxac/uxac_v15.hpp"
#include "uxac/uxac_v16.hpp"
#include "uxac/uxac_v17.hpp"
#include "uxac/uxac_v18.hpp"
#include "uxac/uxac_v19.hpp"
#include "uxac/uxac_v2.hpp"
#include "uxac/uxac_v20.hpp"
#include "uxac/uxac_v21.hpp"
#include "uxac/uxac_v22.hpp"
#include "uxac/uxac_v23.hpp"
#include "uxac/uxac_v3.hpp"
#include "uxac/uxac_v4.hpp"
#include "uxac/uxac_v5.hpp"
#include "uxac/uxac_v6.hpp"
#include "uxac/uxac_v7.hpp"
#include "uxac/uxac_v8.hpp"
#include "uxac/uxac_v9.hpp"

namespace pf {
namespace acct::uxac {

using PrefPackUxAccount = std::variant<std::monostate
#if ACCT_UXAC_MIN_VERSION <= 0
                                       ,
                                       v0::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 1
                                       ,
                                       v1::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 2
                                       ,
                                       v2::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 3
                                       ,
                                       v3::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 4
                                       ,
                                       v4::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 5
                                       ,
                                       v5::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 6
                                       ,
                                       v6::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 7
                                       ,
                                       v7::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 8
                                       ,
                                       v8::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 9
                                       ,
                                       v9::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 10
                                       ,
                                       v10::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 11
                                       ,
                                       v11::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 12
                                       ,
                                       v12::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 13
                                       ,
                                       v13::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 14
                                       ,
                                       v14::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 15
                                       ,
                                       v15::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 16
                                       ,
                                       v16::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 17
                                       ,
                                       v17::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 18
                                       ,
                                       v18::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 19
                                       ,
                                       v19::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 20
                                       ,
                                       v20::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 21
                                       ,
                                       v21::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 22
                                       ,
                                       v22::PrefPackUxAccount
#endif
#if ACCT_UXAC_MIN_VERSION <= 23
                                       ,
                                       v23::PrefPackUxAccount
#endif
                                       >;

} // namespace acct::uxac

template <> struct Chunk<FourCC::acct, FourCC::uxac> {
  using Type = acct::uxac::PrefPackUxAccount;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if ACCT_UXAC_MIN_VERSION <= 0
    case 0:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v0::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v1::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v2::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v3::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 4
    case 4:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v4::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 5
    case 5:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v5::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v6::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 7
    case 7:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v7::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 8
    case 8:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v8::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 9
    case 9:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v9::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 10
    case 10:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v10::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 11
    case 11:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v11::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 12
    case 12:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v12::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 13
    case 13:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v13::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 14
    case 14:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v14::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 15
    case 15:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v15::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 16
    case 16:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v16::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 17
    case 17:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v17::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 18
    case 18:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v18::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 19
    case 19:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v19::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 20
    case 20:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v20::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 21
    case 21:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v21::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 22
    case 22:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v22::PrefPackUxAccount>(buf, b64);
#endif
#if ACCT_UXAC_MIN_VERSION <= 23
    case 23:
      return de::Deserializer<Config>::template Parse<
          acct::uxac::v23::PrefPackUxAccount>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
