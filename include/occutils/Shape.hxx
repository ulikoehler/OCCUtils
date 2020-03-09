#pragma once
/**
 * Utilities for dissecting shapes into their components.
 */
#include <TopoDS_Shape.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_ListOfShape.hxx>
#include <initializer_list>
#include <gp_XYZ.hxx>
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

        /**
         * Compute the bounding box of the given shape,
         * represented by two corner coordinate vectors.
         * 
         * The first returned vector contains xmin, ymin & zmin
         * The second returned vector contains xmax, ymax & zmax
         */
        std::pair<gp_Vec, gp_Vec> BoundingBox(const TopoDS_Shape& shape);

        /**
         * Compute the shape of the bounding box for the given shape
         */
        gp_XYZ BoundingBoxSize(const TopoDS_Shape& shape);

        /**
         * Compute the volume of the bounding box of the given shape.
         */
        double BoundingBoxVolume(const TopoDS_Shape& shape);
    }


    namespace Shapes {
        /**
         * Convert a solid vector to a shape vector
         */
        std::vector<TopoDS_Shape> FromSolids(const std::vector<TopoDS_Solid>& solids);

        /**
         * Convert a face vector to a shape vector
         */
        std::vector<TopoDS_Shape> FromFaces(const std::vector<TopoDS_Face>& faces);
    }
}