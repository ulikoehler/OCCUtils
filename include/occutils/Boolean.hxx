#pragma once
/**
 * Boolean operation utilities
 */
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <vector>
#include <initializer_list>

namespace OCCUtils {
    namespace Boolean {
        /**
         * Boolean AND (Fuse) on two or more shapes.
         * Raises std::invalid_argument if there is only ONE arg
         * Examples:
         *      Fuse({shape1, shape2})
         *      Fuse({shape1, shape2, shape3})
         *      ...
         */
        TopoDS_Shape Fuse(const std::initializer_list<TopoDS_Shape>& shapes);
        TopoDS_Shape Fuse(const std::vector<TopoDS_Shape>& shapes);
        TopoDS_Shape Fuse(const TopTools_ListOfShape& shapes);
        TopoDS_Shape Fuse(const TopTools_ListOfShape& arguments,
            const TopTools_ListOfShape& tools);
    }
}