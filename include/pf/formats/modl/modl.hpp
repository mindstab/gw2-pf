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

#ifndef MODL_MODL_MIN_VERSION
#define MODL_MODL_MIN_VERSION 66
#endif

#include "modl/modl_v0.hpp"
#include "modl/modl_v1.hpp"
#include "modl/modl_v10.hpp"
#include "modl/modl_v11.hpp"
#include "modl/modl_v12.hpp"
#include "modl/modl_v13.hpp"
#include "modl/modl_v14.hpp"
#include "modl/modl_v15.hpp"
#include "modl/modl_v16.hpp"
#include "modl/modl_v17.hpp"
#include "modl/modl_v18.hpp"
#include "modl/modl_v19.hpp"
#include "modl/modl_v2.hpp"
#include "modl/modl_v20.hpp"
#include "modl/modl_v21.hpp"
#include "modl/modl_v22.hpp"
#include "modl/modl_v23.hpp"
#include "modl/modl_v24.hpp"
#include "modl/modl_v25.hpp"
#include "modl/modl_v26.hpp"
#include "modl/modl_v27.hpp"
#include "modl/modl_v28.hpp"
#include "modl/modl_v29.hpp"
#include "modl/modl_v3.hpp"
#include "modl/modl_v30.hpp"
#include "modl/modl_v31.hpp"
#include "modl/modl_v32.hpp"
#include "modl/modl_v33.hpp"
#include "modl/modl_v34.hpp"
#include "modl/modl_v35.hpp"
#include "modl/modl_v36.hpp"
#include "modl/modl_v37.hpp"
#include "modl/modl_v38.hpp"
#include "modl/modl_v39.hpp"
#include "modl/modl_v4.hpp"
#include "modl/modl_v40.hpp"
#include "modl/modl_v41.hpp"
#include "modl/modl_v42.hpp"
#include "modl/modl_v43.hpp"
#include "modl/modl_v44.hpp"
#include "modl/modl_v45.hpp"
#include "modl/modl_v46.hpp"
#include "modl/modl_v47.hpp"
#include "modl/modl_v48.hpp"
#include "modl/modl_v49.hpp"
#include "modl/modl_v5.hpp"
#include "modl/modl_v50.hpp"
#include "modl/modl_v51.hpp"
#include "modl/modl_v52.hpp"
#include "modl/modl_v53.hpp"
#include "modl/modl_v54.hpp"
#include "modl/modl_v55.hpp"
#include "modl/modl_v56.hpp"
#include "modl/modl_v57.hpp"
#include "modl/modl_v58.hpp"
#include "modl/modl_v59.hpp"
#include "modl/modl_v6.hpp"
#include "modl/modl_v60.hpp"
#include "modl/modl_v61.hpp"
#include "modl/modl_v62.hpp"
#include "modl/modl_v63.hpp"
#include "modl/modl_v64.hpp"
#include "modl/modl_v65.hpp"
#include "modl/modl_v66.hpp"
#include "modl/modl_v7.hpp"
#include "modl/modl_v8.hpp"
#include "modl/modl_v9.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace MODL::MODL {

using ModelFileData = std::variant<std::monostate
#if MODL_MODL_MIN_VERSION <= 0
                                   ,
                                   v0::ModelFileDataV0
#endif
#if MODL_MODL_MIN_VERSION <= 1
                                   ,
                                   v1::ModelFileDataV1
#endif
#if MODL_MODL_MIN_VERSION <= 2
                                   ,
                                   v2::ModelFileDataV2
#endif
#if MODL_MODL_MIN_VERSION <= 3
                                   ,
                                   v3::ModelFileDataV3
#endif
#if MODL_MODL_MIN_VERSION <= 4
                                   ,
                                   v4::ModelFileDataV4
#endif
#if MODL_MODL_MIN_VERSION <= 5
                                   ,
                                   v5::ModelFileDataV5
#endif
#if MODL_MODL_MIN_VERSION <= 6
                                   ,
                                   v6::ModelFileDataV6
#endif
#if MODL_MODL_MIN_VERSION <= 7
                                   ,
                                   v7::ModelFileDataV7
#endif
#if MODL_MODL_MIN_VERSION <= 8
                                   ,
                                   v8::ModelFileDataV8
#endif
#if MODL_MODL_MIN_VERSION <= 9
                                   ,
                                   v9::ModelFileDataV9
#endif
#if MODL_MODL_MIN_VERSION <= 10
                                   ,
                                   v10::ModelFileDataV10
#endif
#if MODL_MODL_MIN_VERSION <= 11
                                   ,
                                   v11::ModelFileDataV11
#endif
#if MODL_MODL_MIN_VERSION <= 12
                                   ,
                                   v12::ModelFileDataV12
#endif
#if MODL_MODL_MIN_VERSION <= 13
                                   ,
                                   v13::ModelFileDataV13
#endif
#if MODL_MODL_MIN_VERSION <= 14
                                   ,
                                   v14::ModelFileDataV14
#endif
#if MODL_MODL_MIN_VERSION <= 15
                                   ,
                                   v15::ModelFileDataV15
#endif
#if MODL_MODL_MIN_VERSION <= 16
                                   ,
                                   v16::ModelFileDataV16
#endif
#if MODL_MODL_MIN_VERSION <= 17
                                   ,
                                   v17::ModelFileDataV17
#endif
#if MODL_MODL_MIN_VERSION <= 18
                                   ,
                                   v18::ModelFileDataV18
#endif
#if MODL_MODL_MIN_VERSION <= 19
                                   ,
                                   v19::ModelFileDataV19
#endif
#if MODL_MODL_MIN_VERSION <= 20
                                   ,
                                   v20::ModelFileDataV20
#endif
#if MODL_MODL_MIN_VERSION <= 21
                                   ,
                                   v21::ModelFileDataV21
#endif
#if MODL_MODL_MIN_VERSION <= 22
                                   ,
                                   v22::ModelFileDataV22
#endif
#if MODL_MODL_MIN_VERSION <= 23
                                   ,
                                   v23::ModelFileDataV23
#endif
#if MODL_MODL_MIN_VERSION <= 24
                                   ,
                                   v24::ModelFileDataV24
#endif
#if MODL_MODL_MIN_VERSION <= 25
                                   ,
                                   v25::ModelFileDataV25
#endif
#if MODL_MODL_MIN_VERSION <= 26
                                   ,
                                   v26::ModelFileDataV26
#endif
#if MODL_MODL_MIN_VERSION <= 27
                                   ,
                                   v27::ModelFileDataV27
#endif
#if MODL_MODL_MIN_VERSION <= 28
                                   ,
                                   v28::ModelFileDataV28
#endif
#if MODL_MODL_MIN_VERSION <= 29
                                   ,
                                   v29::ModelFileDataV29
#endif
#if MODL_MODL_MIN_VERSION <= 30
                                   ,
                                   v30::ModelFileDataV30
#endif
#if MODL_MODL_MIN_VERSION <= 31
                                   ,
                                   v31::ModelFileDataV31
#endif
#if MODL_MODL_MIN_VERSION <= 32
                                   ,
                                   v32::ModelFileDataV32
#endif
#if MODL_MODL_MIN_VERSION <= 33
                                   ,
                                   v33::ModelFileDataV33
#endif
#if MODL_MODL_MIN_VERSION <= 34
                                   ,
                                   v34::ModelFileDataV34
#endif
#if MODL_MODL_MIN_VERSION <= 35
                                   ,
                                   v35::ModelFileDataV35
#endif
#if MODL_MODL_MIN_VERSION <= 36
                                   ,
                                   v36::ModelFileDataV36
#endif
#if MODL_MODL_MIN_VERSION <= 37
                                   ,
                                   v37::ModelFileDataV37
#endif
#if MODL_MODL_MIN_VERSION <= 38
                                   ,
                                   v38::ModelFileDataV38
#endif
#if MODL_MODL_MIN_VERSION <= 39
                                   ,
                                   v39::ModelFileDataV39
#endif
#if MODL_MODL_MIN_VERSION <= 40
                                   ,
                                   v40::ModelFileDataV40
#endif
#if MODL_MODL_MIN_VERSION <= 41
                                   ,
                                   v41::ModelFileDataV41
#endif
#if MODL_MODL_MIN_VERSION <= 42
                                   ,
                                   v42::ModelFileDataV42
#endif
#if MODL_MODL_MIN_VERSION <= 43
                                   ,
                                   v43::ModelFileDataV43
#endif
#if MODL_MODL_MIN_VERSION <= 44
                                   ,
                                   v44::ModelFileDataV44
#endif
#if MODL_MODL_MIN_VERSION <= 45
                                   ,
                                   v45::ModelFileDataV45
#endif
#if MODL_MODL_MIN_VERSION <= 46
                                   ,
                                   v46::ModelFileDataV46
#endif
#if MODL_MODL_MIN_VERSION <= 47
                                   ,
                                   v47::ModelFileDataV47
#endif
#if MODL_MODL_MIN_VERSION <= 48
                                   ,
                                   v48::ModelFileDataV48
#endif
#if MODL_MODL_MIN_VERSION <= 49
                                   ,
                                   v49::ModelFileDataV49
#endif
#if MODL_MODL_MIN_VERSION <= 50
                                   ,
                                   v50::ModelFileDataV50
#endif
#if MODL_MODL_MIN_VERSION <= 51
                                   ,
                                   v51::ModelFileDataV51
#endif
#if MODL_MODL_MIN_VERSION <= 52
                                   ,
                                   v52::ModelFileDataV52
#endif
#if MODL_MODL_MIN_VERSION <= 53
                                   ,
                                   v53::ModelFileDataV53
#endif
#if MODL_MODL_MIN_VERSION <= 54
                                   ,
                                   v54::ModelFileDataV54
#endif
#if MODL_MODL_MIN_VERSION <= 55
                                   ,
                                   v55::ModelFileDataV55
#endif
#if MODL_MODL_MIN_VERSION <= 56
                                   ,
                                   v56::ModelFileDataV56
#endif
#if MODL_MODL_MIN_VERSION <= 57
                                   ,
                                   v57::ModelFileDataV57
#endif
#if MODL_MODL_MIN_VERSION <= 58
                                   ,
                                   v58::ModelFileDataV58
#endif
#if MODL_MODL_MIN_VERSION <= 59
                                   ,
                                   v59::ModelFileDataV59
#endif
#if MODL_MODL_MIN_VERSION <= 60
                                   ,
                                   v60::ModelFileDataV60
#endif
#if MODL_MODL_MIN_VERSION <= 61
                                   ,
                                   v61::ModelFileDataV61
#endif
#if MODL_MODL_MIN_VERSION <= 62
                                   ,
                                   v62::ModelFileDataV62
#endif
#if MODL_MODL_MIN_VERSION <= 63
                                   ,
                                   v63::ModelFileDataV63
#endif
#if MODL_MODL_MIN_VERSION <= 64
                                   ,
                                   v64::ModelFileDataV64
#endif
#if MODL_MODL_MIN_VERSION <= 65
                                   ,
                                   v65::ModelFileDataV65
#endif
#if MODL_MODL_MIN_VERSION <= 66
                                   ,
                                   v66::ModelFileDataV66
#endif
                                   >;

} // namespace MODL::MODL

template <> struct Chunk<FourCC::MODL, FourCC::MODL> {
  using Type = MODL::MODL::ModelFileData;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if MODL_MODL_MIN_VERSION <= 0
    case 0:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v0::ModelFileDataV0>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 1
    case 1:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v1::ModelFileDataV1>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 2
    case 2:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v2::ModelFileDataV2>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 3
    case 3:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v3::ModelFileDataV3>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 4
    case 4:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v4::ModelFileDataV4>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 5
    case 5:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v5::ModelFileDataV5>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 6
    case 6:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v6::ModelFileDataV6>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 7
    case 7:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v7::ModelFileDataV7>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 8
    case 8:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v8::ModelFileDataV8>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 9
    case 9:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v9::ModelFileDataV9>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 10
    case 10:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v10::ModelFileDataV10>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 11
    case 11:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v11::ModelFileDataV11>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 12
    case 12:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v12::ModelFileDataV12>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 13
    case 13:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v13::ModelFileDataV13>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 14
    case 14:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v14::ModelFileDataV14>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 15
    case 15:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v15::ModelFileDataV15>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 16
    case 16:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v16::ModelFileDataV16>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 17
    case 17:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v17::ModelFileDataV17>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 18
    case 18:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v18::ModelFileDataV18>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 19
    case 19:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v19::ModelFileDataV19>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 20
    case 20:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v20::ModelFileDataV20>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 21
    case 21:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v21::ModelFileDataV21>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 22
    case 22:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v22::ModelFileDataV22>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 23
    case 23:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v23::ModelFileDataV23>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 24
    case 24:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v24::ModelFileDataV24>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 25
    case 25:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v25::ModelFileDataV25>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 26
    case 26:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v26::ModelFileDataV26>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 27
    case 27:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v27::ModelFileDataV27>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 28
    case 28:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v28::ModelFileDataV28>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 29
    case 29:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v29::ModelFileDataV29>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 30
    case 30:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v30::ModelFileDataV30>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 31
    case 31:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v31::ModelFileDataV31>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 32
    case 32:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v32::ModelFileDataV32>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 33
    case 33:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v33::ModelFileDataV33>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 34
    case 34:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v34::ModelFileDataV34>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 35
    case 35:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v35::ModelFileDataV35>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 36
    case 36:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v36::ModelFileDataV36>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 37
    case 37:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v37::ModelFileDataV37>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 38
    case 38:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v38::ModelFileDataV38>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 39
    case 39:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v39::ModelFileDataV39>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 40
    case 40:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v40::ModelFileDataV40>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 41
    case 41:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v41::ModelFileDataV41>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 42
    case 42:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v42::ModelFileDataV42>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 43
    case 43:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v43::ModelFileDataV43>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 44
    case 44:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v44::ModelFileDataV44>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 45
    case 45:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v45::ModelFileDataV45>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 46
    case 46:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v46::ModelFileDataV46>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 47
    case 47:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v47::ModelFileDataV47>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 48
    case 48:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v48::ModelFileDataV48>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 49
    case 49:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v49::ModelFileDataV49>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 50
    case 50:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v50::ModelFileDataV50>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 51
    case 51:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v51::ModelFileDataV51>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 52
    case 52:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v52::ModelFileDataV52>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 53
    case 53:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v53::ModelFileDataV53>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 54
    case 54:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v54::ModelFileDataV54>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 55
    case 55:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v55::ModelFileDataV55>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 56
    case 56:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v56::ModelFileDataV56>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 57
    case 57:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v57::ModelFileDataV57>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 58
    case 58:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v58::ModelFileDataV58>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 59
    case 59:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v59::ModelFileDataV59>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 60
    case 60:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v60::ModelFileDataV60>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 61
    case 61:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v61::ModelFileDataV61>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 62
    case 62:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v62::ModelFileDataV62>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 63
    case 63:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v63::ModelFileDataV63>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 64
    case 64:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v64::ModelFileDataV64>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 65
    case 65:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v65::ModelFileDataV65>(buf, b64);
#endif
#if MODL_MODL_MIN_VERSION <= 66
    case 66:
      return de::Deserializer<Config>::template Parse<
          MODL::MODL::v66::ModelFileDataV66>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
