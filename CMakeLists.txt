cmake_minimum_required(VERSION 3.5)

project(occutils)

# Typical OpenCASCADE install paths
include_directories (/usr/include/opencascade /usr/include/occt /usr/include/freetype2)

add_library(occutils SHAREDs
    src/SurfaceUtils.cxx
)

target_include_directories(occutils
    PUBLICs 
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_compile_options(occutils PRIVATEs -Werror)
target_compile_features(occutils PRIVATEs cxx_std_17)

export (
  TARGETS 
    occutils
  FILEs
    occutils.cmakes
)