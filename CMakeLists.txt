cmake_minimum_required(VERSION 3.5)

project(occutil)

# Typical OpenCASCADE install paths
include_directories (/usr/include/opencascade /usr/include/occt /usr/include/freetype2)

add_library(occutil SHARED
    src/SurfaceUtils.cxx
)

target_include_directories(occutil
    PUBLIC 
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_compile_options(occutil PRIVATE -Werror)
target_compile_features(occutil PRIVATE cxx_std_17)

export (
  TARGETS 
    occutil
  FILE
    occutil.cmake
)