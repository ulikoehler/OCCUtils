#pragma once
/**
 * Utilities for dissecting shapes into their components.
 */
#include <TopoDS_Shape.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Vertex.hxx>
#include <vector>
#include <optional>

namespace OCCUtils {
    namespace ShapeComponents {
        /**
         * Get all solids in a given shape
         * (not including the shape itself, if it is a solid)
         */
        std::vector<TopoDS_Solid> AllSolidsWithin(const TopoDS_Shape& shape);
        /**
         * Get all faces in a given shape
         * (not including the shape itself, if it is a face)
         */
        std::vector<TopoDS_Face> AllFacesWithin(const TopoDS_Shape& shape);
        /**
         * Get all edges in a given shape
         * (not including the shape itself, if it is a edge)
         */
        std::vector<TopoDS_Edge> AllEdgesWithin(const TopoDS_Shape& shape);
        /**
         * Get all wires in a given shape
         * (not including the shape itself, if it is a wire)
         */
        std::vector<TopoDS_Wire> AllWiresWithin(const TopoDS_Shape& shape);
        /**
         * Get all vertices in a given shape
         * (not including the shape itself, if it is a vertex)
         */
        std::vector<TopoDS_Vertex> AllVerticesWithin(const TopoDS_Shape& shape);

        /**
         * If [shape] is a solid, return shape.
         * Else, expects there to be a single solid within [shape].
         * If there are zero or 2+ solids within [shape], throws
         */
        std::optional<TopoDS_Solid> SingleSolidWithin (const TopoDS_Shape& shape);
        std::optional<TopoDS_Face> SingleFaceWithin (const TopoDS_Shape& shape);
        std::optional<TopoDS_Edge> SingleEdgeWithin (const TopoDS_Shape& shape);
        std::optional<TopoDS_Wire> SingleWireWithin (const TopoDS_Shape& shape);
        std::optional<TopoDS_Vertex> SingleVertexWithin (const TopoDS_Shape& shape);
    }
}