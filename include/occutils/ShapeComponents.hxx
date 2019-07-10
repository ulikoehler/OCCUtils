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
        std::vector<TopoDS_Solid> AllSolidsWithin(const std::vector<TopoDS_Shape>& shapes);
        /**
         * Get all faces in a given shape
         * (not including the shape itself, if it is a face)
         */
        std::vector<TopoDS_Face> AllFacesWithin(const TopoDS_Shape& shape);
        std::vector<TopoDS_Face> AllFacesWithin(const std::vector<TopoDS_Shape>& shapes);
        /**
         * Get all edges in a given shape
         * (not including the shape itself, if it is an edge)
         */
        std::vector<TopoDS_Edge> AllEdgesWithin(const TopoDS_Shape& shape);
        std::vector<TopoDS_Edge> AllEdgesWithin(const std::vector<TopoDS_Shape>& shapes);
        /**
         * Get all wires in a given shape
         * (not including the shape itself, if it is a wire)
         */
        std::vector<TopoDS_Wire> AllWiresWithin(const TopoDS_Shape& shape);
        std::vector<TopoDS_Wire> AllWiresWithin(const std::vector<TopoDS_Shape>& shapes);
        /**
         * Get all vertices in a given shape
         * (not including the shape itself, if it is a vertex)
         */
        std::vector<TopoDS_Vertex> AllVerticesWithin(const TopoDS_Shape& shape);
        std::vector<TopoDS_Vertex> AllVerticesWithin(const std::vector<TopoDS_Shape>& shapes);
        /**
         * Get all vertex coordinates in a given shape.
         * Like AllVerticesWithin() but converts the TopoDS_Vertex instances
         * to gp_Pnts
         * (not including the shape itself, if it is a vertex)
         */
        std::vector<gp_Pnt> AllVertexCoordinatesWithin(const TopoDS_Shape& shape);
        std::vector<gp_Pnt> AllVertexCoordinatesWithin(const std::vector<TopoDS_Shape>& shapes);

        /**
         * If [shape] is a solid, return shape.
         * Else, if there is a single solid within [shape],
         * returns that solid. Else, returns no value.
         */
        std::optional<TopoDS_Solid> TryGetSingleSolid (const TopoDS_Shape& shape);
        /**
         * If [shape] is a face, return shape.
         * Else, if there is a single face within [shape],
         * returns that face. Else, returns no value.
         */
        std::optional<TopoDS_Face> TryGetSingleFace (const TopoDS_Shape& shape);
        /**
         * If [shape] is a edge, return shape.
         * Else, if there is a single edge within [shape],
         * returns that edge. Else, returns no value.
         */
        std::optional<TopoDS_Edge> TryGetSingleEdge (const TopoDS_Shape& shape);
        /**
         * If [shape] is a edge, return shape.
         * Else, if there is a single edge within [shape],
         * returns that edge. Else, returns no value.
         */
        std::optional<TopoDS_Wire> TryGetSingleWire (const TopoDS_Shape& shape);
        /**
         * If [shape] is a vertex, return shape.
         * Else, if there is a single vertex within [shape],
         * returns that vertex. Else, returns no value.
         */
        std::optional<TopoDS_Vertex> TryGetSingleVertex (const TopoDS_Shape& shape);
        
        /**
         * If [shape] is a solid, return shape.
         * Else, expects there to be a single solid within [shape].
         * If there are zero or 2+ solids within [shape], throws
         * OCCTopologyCountMismatchException().
         */
        TopoDS_Solid GetSingleSolid (const TopoDS_Shape& shape);
        /**
         * If [shape] is a face, return shape.
         * Else, expects there to be a single face within [shape].
         * If there are zero or 2+ faces within [shape], throws
         * OCCTopologyCountMismatchException().
         */
        TopoDS_Face GetSingleFace (const TopoDS_Shape& shape);
        /**
         * If [shape] is an edge, return shape.
         * Else, expects there to be a single edge within [shape].
         * If there are zero or 2+ edges within [shape], throws
         * OCCTopologyCountMismatchException().
         */
        TopoDS_Edge GetSingleEdge (const TopoDS_Shape& shape);
        /**
         * If [shape] is a wire, return shape.
         * Else, expects there to be a single wire within [shape].
         * If there are zero or 2+ wires within [shape], throws
         * OCCTopologyCountMismatchException().
         */
        TopoDS_Wire GetSingleWire (const TopoDS_Shape& shape);
        /**
         * If [shape] is an vertex, return shape.
         * Else, expects there to be a single vertex within [shape].
         * If there are zero or 2+ vertices within [shape], throws
         * OCCTopologyCountMismatchException().
         */
        TopoDS_Vertex GetSingleVertex (const TopoDS_Shape& shape);
    }
}