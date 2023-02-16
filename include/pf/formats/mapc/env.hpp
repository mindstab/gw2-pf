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

#ifndef MAPC_ENV_MIN_VERSION
#define MAPC_ENV_MIN_VERSION 75
#endif

#include "env/env_v29.hpp"
#include "env/env_v30.hpp"
#include "env/env_v31.hpp"
#include "env/env_v32.hpp"
#include "env/env_v33.hpp"
#include "env/env_v34.hpp"
#include "env/env_v35.hpp"
#include "env/env_v36.hpp"
#include "env/env_v37.hpp"
#include "env/env_v38.hpp"
#include "env/env_v39.hpp"
#include "env/env_v40.hpp"
#include "env/env_v41.hpp"
#include "env/env_v42.hpp"
#include "env/env_v43.hpp"
#include "env/env_v44.hpp"
#include "env/env_v45.hpp"
#include "env/env_v46.hpp"
#include "env/env_v47.hpp"
#include "env/env_v48.hpp"
#include "env/env_v49.hpp"
#include "env/env_v50.hpp"
#include "env/env_v51.hpp"
#include "env/env_v52.hpp"
#include "env/env_v53.hpp"
#include "env/env_v54.hpp"
#include "env/env_v55.hpp"
#include "env/env_v56.hpp"
#include "env/env_v57.hpp"
#include "env/env_v58.hpp"
#include "env/env_v59.hpp"
#include "env/env_v60.hpp"
#include "env/env_v61.hpp"
#include "env/env_v62.hpp"
#include "env/env_v63.hpp"
#include "env/env_v64.hpp"
#include "env/env_v65.hpp"
#include "env/env_v66.hpp"
#include "env/env_v67.hpp"
#include "env/env_v68.hpp"
#include "env/env_v69.hpp"
#include "env/env_v70.hpp"
#include "env/env_v71.hpp"
#include "env/env_v72.hpp"
#include "env/env_v73.hpp"
#include "env/env_v74.hpp"
#include "env/env_v75.hpp"
#include "pf/chunk.hpp"
#include "pf/de/deserializer.hpp"
#include "pf/magic.hpp"

namespace pf {
namespace mapc::env {

using PackMapEnvironment = std::variant<std::monostate
#if MAPC_ENV_MIN_VERSION <= 29
                                        ,
                                        v29::PackMapEnvironmentV29
#endif
#if MAPC_ENV_MIN_VERSION <= 30
                                        ,
                                        v30::PackMapEnvironmentV30
#endif
#if MAPC_ENV_MIN_VERSION <= 31
                                        ,
                                        v31::PackMapEnvironmentV31
#endif
#if MAPC_ENV_MIN_VERSION <= 32
                                        ,
                                        v32::PackMapEnvironmentV32
#endif
#if MAPC_ENV_MIN_VERSION <= 33
                                        ,
                                        v33::PackMapEnvironmentV33
#endif
#if MAPC_ENV_MIN_VERSION <= 34
                                        ,
                                        v34::PackMapEnvironmentV34
#endif
#if MAPC_ENV_MIN_VERSION <= 35
                                        ,
                                        v35::PackMapEnvironmentV35
#endif
#if MAPC_ENV_MIN_VERSION <= 36
                                        ,
                                        v36::PackMapEnvironmentV36
#endif
#if MAPC_ENV_MIN_VERSION <= 37
                                        ,
                                        v37::PackMapEnvironmentV37
#endif
#if MAPC_ENV_MIN_VERSION <= 38
                                        ,
                                        v38::PackMapEnvironmentV38
#endif
#if MAPC_ENV_MIN_VERSION <= 39
                                        ,
                                        v39::PackMapEnvironmentV39
#endif
#if MAPC_ENV_MIN_VERSION <= 40
                                        ,
                                        v40::PackMapEnvironmentV40
#endif
#if MAPC_ENV_MIN_VERSION <= 41
                                        ,
                                        v41::PackMapEnvironmentV41
#endif
#if MAPC_ENV_MIN_VERSION <= 42
                                        ,
                                        v42::PackMapEnvironmentV42
#endif
#if MAPC_ENV_MIN_VERSION <= 43
                                        ,
                                        v43::PackMapEnvironmentV43
#endif
#if MAPC_ENV_MIN_VERSION <= 44
                                        ,
                                        v44::PackMapEnvironmentV44
#endif
#if MAPC_ENV_MIN_VERSION <= 45
                                        ,
                                        v45::PackMapEnvironmentV45
#endif
#if MAPC_ENV_MIN_VERSION <= 46
                                        ,
                                        v46::PackMapEnvironmentV46
#endif
#if MAPC_ENV_MIN_VERSION <= 47
                                        ,
                                        v47::PackMapEnvironmentV47
#endif
#if MAPC_ENV_MIN_VERSION <= 48
                                        ,
                                        v48::PackMapEnvironmentV48
#endif
#if MAPC_ENV_MIN_VERSION <= 49
                                        ,
                                        v49::PackMapEnvironmentV49
#endif
#if MAPC_ENV_MIN_VERSION <= 50
                                        ,
                                        v50::PackMapEnvironmentV50
#endif
#if MAPC_ENV_MIN_VERSION <= 51
                                        ,
                                        v51::PackMapEnvironmentV51
#endif
#if MAPC_ENV_MIN_VERSION <= 52
                                        ,
                                        v52::PackMapEnvironmentV52
#endif
#if MAPC_ENV_MIN_VERSION <= 53
                                        ,
                                        v53::PackMapEnvironmentV53
#endif
#if MAPC_ENV_MIN_VERSION <= 54
                                        ,
                                        v54::PackMapEnvironmentV54
#endif
#if MAPC_ENV_MIN_VERSION <= 55
                                        ,
                                        v55::PackMapEnvironmentV55
#endif
#if MAPC_ENV_MIN_VERSION <= 56
                                        ,
                                        v56::PackMapEnvironmentV56
#endif
#if MAPC_ENV_MIN_VERSION <= 57
                                        ,
                                        v57::PackMapEnvironmentV57
#endif
#if MAPC_ENV_MIN_VERSION <= 58
                                        ,
                                        v58::PackMapEnvironmentV58
#endif
#if MAPC_ENV_MIN_VERSION <= 59
                                        ,
                                        v59::PackMapEnvironmentV59
#endif
#if MAPC_ENV_MIN_VERSION <= 60
                                        ,
                                        v60::PackMapEnvironmentV60
#endif
#if MAPC_ENV_MIN_VERSION <= 61
                                        ,
                                        v61::PackMapEnvironmentV61
#endif
#if MAPC_ENV_MIN_VERSION <= 62
                                        ,
                                        v62::PackMapEnvironmentV62
#endif
#if MAPC_ENV_MIN_VERSION <= 63
                                        ,
                                        v63::PackMapEnvironmentV63
#endif
#if MAPC_ENV_MIN_VERSION <= 64
                                        ,
                                        v64::PackMapEnvironmentV64
#endif
#if MAPC_ENV_MIN_VERSION <= 65
                                        ,
                                        v65::PackMapEnvironmentV65
#endif
#if MAPC_ENV_MIN_VERSION <= 66
                                        ,
                                        v66::PackMapEnvironmentV66
#endif
#if MAPC_ENV_MIN_VERSION <= 67
                                        ,
                                        v67::PackMapEnvironmentV67
#endif
#if MAPC_ENV_MIN_VERSION <= 68
                                        ,
                                        v68::PackMapEnvironmentV68
#endif
#if MAPC_ENV_MIN_VERSION <= 69
                                        ,
                                        v69::PackMapEnvironmentV69
#endif
#if MAPC_ENV_MIN_VERSION <= 70
                                        ,
                                        v70::PackMapEnvironmentV70
#endif
#if MAPC_ENV_MIN_VERSION <= 71
                                        ,
                                        v71::PackMapEnvironmentV71
#endif
#if MAPC_ENV_MIN_VERSION <= 72
                                        ,
                                        v72::PackMapEnvironmentV72
#endif
#if MAPC_ENV_MIN_VERSION <= 73
                                        ,
                                        v73::PackMapEnvironmentV73
#endif
#if MAPC_ENV_MIN_VERSION <= 74
                                        ,
                                        v74::PackMapEnvironmentV74
#endif
#if MAPC_ENV_MIN_VERSION <= 75
                                        ,
                                        v75::PackMapEnvironmentV75
#endif
                                        >;

} // namespace mapc::env

template <> struct Chunk<FourCC::mapc, FourCC::env> {
  using Type = mapc::env::PackMapEnvironment;

  template <typename Config>
  [[nodiscard]] static de::Result<Type>
  Parse(uint16_t version, std::span<const std::byte> buf, bool b64) {
    switch (version) {
#if MAPC_ENV_MIN_VERSION <= 29
    case 29:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v29::PackMapEnvironmentV29>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 30
    case 30:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v30::PackMapEnvironmentV30>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 31
    case 31:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v31::PackMapEnvironmentV31>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 32
    case 32:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v32::PackMapEnvironmentV32>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 33
    case 33:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v33::PackMapEnvironmentV33>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 34
    case 34:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v34::PackMapEnvironmentV34>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 35
    case 35:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v35::PackMapEnvironmentV35>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 36
    case 36:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v36::PackMapEnvironmentV36>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 37
    case 37:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v37::PackMapEnvironmentV37>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 38
    case 38:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v38::PackMapEnvironmentV38>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 39
    case 39:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v39::PackMapEnvironmentV39>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 40
    case 40:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v40::PackMapEnvironmentV40>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 41
    case 41:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v41::PackMapEnvironmentV41>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 42
    case 42:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v42::PackMapEnvironmentV42>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 43
    case 43:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v43::PackMapEnvironmentV43>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 44
    case 44:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v44::PackMapEnvironmentV44>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 45
    case 45:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v45::PackMapEnvironmentV45>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 46
    case 46:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v46::PackMapEnvironmentV46>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 47
    case 47:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v47::PackMapEnvironmentV47>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 48
    case 48:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v48::PackMapEnvironmentV48>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 49
    case 49:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v49::PackMapEnvironmentV49>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 50
    case 50:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v50::PackMapEnvironmentV50>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 51
    case 51:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v51::PackMapEnvironmentV51>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 52
    case 52:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v52::PackMapEnvironmentV52>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 53
    case 53:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v53::PackMapEnvironmentV53>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 54
    case 54:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v54::PackMapEnvironmentV54>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 55
    case 55:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v55::PackMapEnvironmentV55>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 56
    case 56:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v56::PackMapEnvironmentV56>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 57
    case 57:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v57::PackMapEnvironmentV57>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 58
    case 58:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v58::PackMapEnvironmentV58>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 59
    case 59:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v59::PackMapEnvironmentV59>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 60
    case 60:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v60::PackMapEnvironmentV60>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 61
    case 61:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v61::PackMapEnvironmentV61>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 62
    case 62:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v62::PackMapEnvironmentV62>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 63
    case 63:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v63::PackMapEnvironmentV63>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 64
    case 64:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v64::PackMapEnvironmentV64>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 65
    case 65:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v65::PackMapEnvironmentV65>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 66
    case 66:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v66::PackMapEnvironmentV66>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 67
    case 67:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v67::PackMapEnvironmentV67>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 68
    case 68:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v68::PackMapEnvironmentV68>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 69
    case 69:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v69::PackMapEnvironmentV69>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 70
    case 70:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v70::PackMapEnvironmentV70>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 71
    case 71:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v71::PackMapEnvironmentV71>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 72
    case 72:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v72::PackMapEnvironmentV72>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 73
    case 73:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v73::PackMapEnvironmentV73>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 74
    case 74:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v74::PackMapEnvironmentV74>(buf, b64);
#endif
#if MAPC_ENV_MIN_VERSION <= 75
    case 75:
      return de::Deserializer<Config>::template Parse<
          mapc::env::v75::PackMapEnvironmentV75>(buf, b64);
#endif
    default:
      return std::unexpected(de::Error::kUnsupportedVersion);
    }
  }
};

} // namespace pf
