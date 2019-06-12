cmake_minimum_required(VERSION 3.5)

project(occutil)

include_directories (inc)
# Typical OpenCASCADE install paths
include_directories (/usr/include/opencascade /usr/include/occt /usr/include/freetype2)

add_library(occutil SHARED
    src/FaceUtils.cxx
)