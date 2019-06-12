cmake_minimum_required(VERSION 3.5)

project(liboccutils)

# Typical OpenCASCADE install paths
include_directories (/usr/include/opencascade /usr/include/occt /usr/include/freetype2)

add_library(occutils SHARED
    src/SurfaceUtils.cxx
    src/ShapeComponents.cxx
)

#target_include_directories(occutils
#    PUBLIC
#        $<INSTALL_INTERFACE:include>
#        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#)

set_target_properties(occutils
  PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/include"
  INTERFACE_LINK_LIBRARIES "occutils"
)

target_include_directories(occutils PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")
target_compile_options(occutils PRIVATE -Werror)
target_compile_features(occutils PRIVATE cxx_std_17)

install(TARGETS occutils
  LIBRARY DESTINATION lib
  PUBLIC_HEADER DESTINATION include)
install(DIRECTORY
  "${CMAKE_CURRENT_LIST_DIR}/include/"
  DESTINATION include)
#export (
#  TARGETS 
#    occutils
#  FILE
#    occutils.cmake
#)