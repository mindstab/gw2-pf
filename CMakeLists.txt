cmake_minimum_required(VERSION 3.20)
project(gw2-pf LANGUAGES CXX)

file(GLOB ABIX_INC include/pf/formats/abix/*/*.hpp include/pf/formats/abix/*.hpp include/pf/formats/abix.hpp)
file(GLOB ABNK_INC include/pf/formats/abnk/*/*.hpp include/pf/formats/abnk/*.hpp include/pf/formats/abnk.hpp)
file(GLOB ACCT_INC include/pf/formats/acct/*/*.hpp include/pf/formats/acct/*.hpp include/pf/formats/acct.hpp)
file(GLOB AMAT_INC include/pf/formats/amat/*/*.hpp include/pf/formats/amat/*.hpp include/pf/formats/amat.hpp)
file(GLOB AMSP_INC include/pf/formats/amsp/*/*.hpp include/pf/formats/amsp/*.hpp include/pf/formats/amsp.hpp)
file(GLOB ANIC_INC include/pf/formats/anic/*/*.hpp include/pf/formats/anic/*.hpp include/pf/formats/anic.hpp)
file(GLOB ARMF_INC include/pf/formats/armf/*/*.hpp include/pf/formats/armf/*.hpp include/pf/formats/armf.hpp)
file(GLOB ASND_INC include/pf/formats/asnd/*/*.hpp include/pf/formats/asnd/*.hpp include/pf/formats/asnd.hpp)
file(GLOB CDHS_INC include/pf/formats/cdhs/*/*.hpp include/pf/formats/cdhs/*.hpp include/pf/formats/cdhs.hpp)
file(GLOB CHAR_INC include/pf/formats/char/*/*.hpp include/pf/formats/char/*.hpp include/pf/formats/char.hpp)
file(GLOB CINP_INC include/pf/formats/cinp/*/*.hpp include/pf/formats/cinp/*.hpp include/pf/formats/cinp.hpp)
file(GLOB CMAC_INC include/pf/formats/cmac/*/*.hpp include/pf/formats/cmac/*.hpp include/pf/formats/cmac.hpp)
file(GLOB CMPC_INC include/pf/formats/cmpc/*/*.hpp include/pf/formats/cmpc/*.hpp include/pf/formats/cmpc.hpp)
file(GLOB CNTC_INC include/pf/formats/cntc/*/*.hpp include/pf/formats/cntc/*.hpp include/pf/formats/cntc.hpp)
file(GLOB EMOC_INC include/pf/formats/emoc/*/*.hpp include/pf/formats/emoc/*.hpp include/pf/formats/emoc.hpp)
file(GLOB EULA_INC include/pf/formats/eula/*/*.hpp include/pf/formats/eula/*.hpp include/pf/formats/eula.hpp)
file(GLOB HVKC_INC include/pf/formats/hvkc/*/*.hpp include/pf/formats/hvkc/*.hpp include/pf/formats/hvkc.hpp)
file(GLOB LOCL_INC include/pf/formats/locl/*/*.hpp include/pf/formats/locl/*.hpp include/pf/formats/locl.hpp)
file(GLOB MAPC_INC include/pf/formats/mapc/*/*.hpp include/pf/formats/mapc/*.hpp include/pf/formats/mapc.hpp)
file(GLOB MMET_INC include/pf/formats/mmet/*/*.hpp include/pf/formats/mmet/*.hpp include/pf/formats/mmet.hpp)
file(GLOB MODL_INC include/pf/formats/modl/*/*.hpp include/pf/formats/modl/*.hpp include/pf/formats/modl.hpp)
file(GLOB MPSD_INC include/pf/formats/mpsd/*/*.hpp include/pf/formats/mpsd/*.hpp include/pf/formats/mpsd.hpp)
file(GLOB PIMG_INC include/pf/formats/pimg/*/*.hpp include/pf/formats/pimg/*.hpp include/pf/formats/pimg.hpp)
file(GLOB PRLT_INC include/pf/formats/prlt/*/*.hpp include/pf/formats/prlt/*.hpp include/pf/formats/prlt.hpp)
file(GLOB TXTM_INC include/pf/formats/txtm/*/*.hpp include/pf/formats/txtm/*.hpp include/pf/formats/txtm.hpp)
file(GLOB TXTV_INC include/pf/formats/txtv/*/*.hpp include/pf/formats/txtv/*.hpp include/pf/formats/txtv.hpp)
file(GLOB TXTV__INC include/pf/formats/txtv_/*/*.hpp include/pf/formats/txtv_/*.hpp include/pf/formats/txtv_.hpp)

set(INCLUDES
    include/pf/de/deserializer.hpp
    include/pf/de/error.hpp
    ${ABIX_INC}
    ${ABNK_INC}
    ${ACCT_INC}
    ${AMAT_INC}
    ${AMSP_INC}
    ${ANIC_INC}
    ${ARMF_INC}
    ${ASND_INC}
    ${CDHS_INC}
    ${CHAR_INC}
    ${CINP_INC}
    ${CMAC_INC}
    ${CMPC_INC}
    ${CNTC_INC}
    ${EMOC_INC}
    ${EULA_INC}
    ${HVKC_INC}
    ${LOCL_INC}
    ${MAPC_INC}
    ${MMET_INC}
    ${MODL_INC}
    ${MPSD_INC}
    ${PIMG_INC}
    ${PRLT_INC}
    ${TXTM_INC}
    ${TXTV_INC}
    ${TXTV__INC}
    include/pf/chunk.hpp
    include/pf/config.hpp
    include/pf/magic.hpp
    include/pf/packfile.hpp
    include/pf/reader.hpp
    include/pf/types.hpp
)

add_library(${PROJECT_NAME} INTERFACE ${INCLUDES})

target_include_directories(${PROJECT_NAME} INTERFACE include)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_23)

add_library(gw2::pf ALIAS ${PROJECT_NAME})