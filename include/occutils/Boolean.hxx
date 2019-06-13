#pragma once
/**
 * Boolean operation utilities
 */
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <vector>
#include <initializer_list>
#include <occutils/ListUtils.hxx>

namespace OCCUtils {
    namespace Boolean {
        /**
         * Boolean AND (Fuse) on two or more shapes.
         * Raises std::invalid_argument if there is only ONE arg
         * Examples:
         *      Fuse({shape1, shape2})
         *      Fuse({shape1, shape2, shape3})
         *      ...
         * You can call Fuse() with virtually any STL- or STL-like container.
         */

        /**
         * Fuse two or more shapes in an STL-like container
         */
        template<template<typename, typename> typename Container, typename Allocator>
        TopoDS_Shape Fuse(const Container<TopoDS_Shape, Allocator>& shapes) {
            return Fuse(OCCUtils::ListUtils::ToOCCList(shapes));
        }
        /**
         * Fuse two or more shapes in a OCC-style container
         */
        template<template<typename> typename Container>
        TopoDS_Shape Fuse(const Container<TopoDS_Shape>& shapes) {
            return Fuse(OCCUtils::ListUtils::ToOCCList(shapes));
        }
        
        TopoDS_Shape Fuse(const TopTools_ListOfShape& shapes);
        /**
         * Fuse with two lists of arguments.
         * For Fuse() this is equivalent to joining the lists.
         */
        TopoDS_Shape Fuse(const TopTools_ListOfShape& arguments, const TopTools_ListOfShape& tools);
    }
}