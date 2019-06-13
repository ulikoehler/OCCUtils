#pragma once
/**
 * Utilities for dissecting shapes into their components.
 */
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <initializer_list>
#include <vector>

namespace OCCUtils {
    namespace ShapeUtils {
        /**
         * @return true if the given shape is a TopoDS_Solid
         */
        bool IsSolid(const TopoDS_Shape& shape);
        /**
         * @return true if the given shape is a TopoDS_Face
         */
        bool IsFace(const TopoDS_Shape& shape);
        /**
         * @return true if the given shape is a TopoDS_Edge
         */
        bool IsEdge(const TopoDS_Shape& shape);
        /**
         * @return true if the given shape is a TopoDS_Wire
         */
        bool IsWire(const TopoDS_Shape& shape);
        /**
         * @return true if the given shape is a TopoDS_Vertex
         */
        bool IsVertex(const TopoDS_Shape& shape);
    }
    namespace ShapeList {
        /**
         * Generate a shape list from one or multiple shapes
         * given as arguments. Examples:
         *      ToListOfShape({shape1})
         *      ToListOfShape({shape1, shape2})
         *      ToListOfShape({shape1, shape2, shape3})
         *      ...
         */
        TopTools_ListOfShape ToListOfShape(const std::initializer_list<TopoDS_Shape>& shapes);
        TopTools_ListOfShape ToListOfShape(const std::vector<TopoDS_Shape>& shapes);

        // TODO
        //std::vector<TopoDS_Shape>& ToShapeVector(const TopTools_ListOfShape& shapes);
    }
}