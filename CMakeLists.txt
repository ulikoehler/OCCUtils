cmake_minimum_required(VERSION 3.5)

project(liboccutils)

# Typical OpenCASCADE install paths
include_directories (/usr/include/opencascade /usr/include/occt /usr/include/freetype2)

add_library(occutils SHARED
    src/Surface.cxx
    src/ShapeComponents.cxx
    src/Shape.cxx
    src/Plane.cxx
    src/Pipe.cxx
    src/IO.cxx
    src/Curve.cxx
    src/STEPExport.cxx
    src/Primitive.cxx
    src/Direction.cxx
    src/Boolean.cxx
    src/ExtendedSTEP.cxx
    src/PrintOCC.cxx
    src/Fillet.cxx
    src/Wire.cxx
    src/Edge.cxx
    src/Face.cxx
    src/Equality.cxx
    src/Axis.cxx
    src/Point.cxx
    src/Line.cxx
    src/Compound.cxx
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

#
# Compile test suite
#
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

add_executable(test_occutils
    tests/TestLine.cpp
)
target_include_directories(test_occutils PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")
target_compile_options(occutils PRIVATE -Werror)
target_compile_features(test_occutils PRIVATE cxx_std_17)

target_link_libraries(test_occutils
                      occutils
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      TKBO 
                      TKBRep
                      TKOffset
                      TKFeat 
                      TKFillet
                      TKXDESTEP
                      TKG2d 
                      TKG3d 
                      TKGeomAlgo 
                      TKGeomBase 
                      TKHLR 
                      TKIGES 
                      TKOffset 
                      TKPrim 
                      TKShHealing 
                      TKSTEP 
                      TKSTEP209 
                      TKSTEPAttr 
                      TKSTEPBase 
                      TKXSBase
                      TKSTL 
                      TKTopAlgo 
                      TKV3d
                      )
add_test(test_occutils test_occutils)
# make "make test" run the test program
add_custom_target(test
    DEPENDS test_occutils
    COMMAND ./test_occutils
)

#export (
#  TARGETS 
#    occutils
#  FILE
#    occutils.cmake
#)