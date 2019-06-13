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
         * Fuse two or more shapes in a OCC-style container.
         * Raises std::invalid_argument if there is only ONE shape
         */
        TopoDS_Shape Fuse(const TopTools_ListOfShape& shapes);
        
        /**
         * Fuse with two lists of arguments.
         * For Fuse() this is equivalent to joining the lists.
         * Raises std::invalid_argument if there is only ONE shape
         */
        TopoDS_Shape Fuse(const TopTools_ListOfShape& arguments, const TopTools_ListOfShape& tools);

        /**
         * Fuse two or more shapes in an STL-like container
         * Raises std::invalid_argument if there is only ONE shape
         */
        template<template<typename, typename> typename Container, typename Allocator>
        TopoDS_Shape Fuse(const Container<TopoDS_Shape, Allocator>& shapes) {
            return Fuse(OCCUtils::ListUtils::ToOCCList(shapes));
        }

        /**
         * Fuse two or more shapes in a OCC-style container
         * Raises std::invalid_argument if there is only ONE shape
         */
        template<template<typename> typename Container>
        TopoDS_Shape Fuse(const Container<TopoDS_Shape>& shapes) {
            return Fuse(OCCUtils::ListUtils::ToOCCList(shapes));
        }

        /**
         * Fuse two or more shapes in a OCC-style container.
         * Convenience call function:
         *      Fuse({shape1, shape2})
         *      Fuse({shape1, shape2, shape3})
         * Raises std::invalid_argument if there is only ONE shape
         */
        TopoDS_Shape Fuse(const std::initializer_list<TopoDS_Shape>& shapes);
    }
}