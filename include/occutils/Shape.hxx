#pragma once
/**
 * Utilities for dissecting shapes into their components.
 */
#include <TopoDS_Shape.hxx>
#include <TopoDS_Solid.hxx>
#include <TopTools_ListOfShape.hxx>
#include <initializer_list>
#include <vector>

namespace OCCUtils {
    namespace Shape {
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

        /**
         * Compute the volume of the given shape.
         */
        double Volume(const TopoDS_Shape& shape);
    }


    namespace Shapes {
        /**
         * Convert a solid vector to a shape vector
         */
        std::vector<TopoDS_Shape> ToShapes(const std::vector<TopoDS_Solid>& solids);
    }
}