#pragma once
/**
 * Boolean operation utilities
 */
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Solid.hxx>
#include <TopTools_ListOfShape.hxx>
#include <vector>
#include <initializer_list>
#include <occutils/ListUtils.hxx>

namespace OCCUtils {
    namespace Boolean {

        /**
         * Fuse two or more shapes in a OCC-style container.
         * Returns a shape with IsNull() == true if there is no shape
         */
        TopoDS_Shape Fuse(const TopTools_ListOfShape& shapes);
        
        /**
         * Fuse with two lists of arguments.
         * For Fuse() this is equivalent to joining the lists.
         * Returns a shape with IsNull() == true if there is no shape
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
        TopoDS_Shape Fuse(const std::vector<TopoDS_Solid>& shapes);
        TopoDS_Shape Fuse(const std::initializer_list<TopoDS_Solid>& shapes);
        TopoDS_Shape Fuse(const std::vector<TopoDS_Face>& shapes);
        TopoDS_Shape Fuse(const std::initializer_list<TopoDS_Face>& shapes);


        /**
         * Boolean subtraction with two lists of arguments.
         * negative is subtracted from positive, i.e. tools is negative, arguments is positive
         */
        TopoDS_Shape Cut(const TopTools_ListOfShape& positive, const TopTools_ListOfShape& negative);

        /**
         * Boolean subtraction with two lists of arguments.
         * negative is subtracted from positive, i.e. tools is negative, arguments is positive
         */
        TopoDS_Shape Cut(const TopoDS_Shape& positive, const TopoDS_Shape& negative);

        /**
         * Boolean subtraction with two lists of arguments.
         * negative is subtracted from positive, i.e. tools is negative, arguments is positive
         */
        TopoDS_Shape Cut(const TopoDS_Shape& positive, const TopTools_ListOfShape& negative);
        

        /**
         * Boolean subtraction with two lists of arguments.
         * negative is subtracted from positive, i.e. tools is negative, arguments is positive
         */
        TopoDS_Shape Cut(const TopoDS_Shape& positive, const std::initializer_list<TopoDS_Shape>& negative);

        /**
         * Boolean subtraction with two lists of arguments.
         * negative is subtracted from positive, i.e. tools is negative, arguments is positive
         */
        template<template<typename, typename> typename Container, typename Allocator>
        TopoDS_Shape Cut(const TopoDS_Shape& positive, const Container<TopoDS_Shape, Allocator>& negative) {
            return Cut(OCCUtils::ListUtils::ToOCCList({positive}), OCCUtils::ListUtils::ToOCCList(negative));
        }

        /**
         * Boolean subtraction with two lists of arguments.
         * tools is subtracted from argument, i.e. tools is negative, arguments is positive
         */
        template<template<typename, typename> typename Container, typename Allocator1, typename Allocator2>
        TopoDS_Shape Cut(const Container<TopoDS_Shape, Allocator1>& positive, const Container<TopoDS_Shape, Allocator2>& negative) {
            return Cut(OCCUtils::ListUtils::ToOCCList(positive), OCCUtils::ListUtils::ToOCCList(negative));
        }

        /**
         * Boolean subtraction with two lists of TopoDS_Solids.
         * This is a common usecase, hence we provide a utility function.
         * tools is subtracted from argument, i.e. tools is negative, arguments is positive
         */
        TopoDS_Shape Cut(const std::vector<TopoDS_Solid>& positive, const std::vector<TopoDS_Solid>& negative);

        /**
         * Boolean subtraction with two lists of TopoDS_Solids.
         * This is a common usecase, hence we provide a utility function.
         * tools is subtracted from argument, i.e. tools is negative, arguments is positive
         */
        TopoDS_Shape Cut(const TopoDS_Solid& positive, const std::vector<TopoDS_Solid>& negative);

        /**
         * Boolean subtraction with two lists of TopoDS_Faces.
         * This is a common usecase, hence we provide a utility function.
         * tools is subtracted from argument, i.e. tools is negative, arguments is positive
         */
        TopoDS_Shape Cut(const std::vector<TopoDS_Face>& positive, const std::vector<TopoDS_Face>& negative);

        /**
         * Boolean subtraction with two lists of TopoDS_Faces.
         * This is a common usecase, hence we provide a utility function.
         * tools is subtracted from argument, i.e. tools is negative, arguments is positive
         */
        TopoDS_Shape Cut(const TopoDS_Face& positive, const std::vector<TopoDS_Face>& negative);
    }
}