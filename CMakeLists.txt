cmake_minimum_required(VERSION 3.5)

project(occutil)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories (inc)
# Typical OpenCASCADE install paths
include_directories (/usr/include/opencascade /usr/include/occt /usr/include/freetype2)

add_library(occutil SHARED
    src/SurfaceUtils.cxx
)