#pragma once
#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Edge.hxx>
#include <initializer_list>
#include <vector>
#include <optional>

namespace OCCUtils {
    namespace Face {
        /**
         * Construct a face from the given outer wire.
         * If wire.IsNull(), then result.IsNull() as well.
         */
        TopoDS_Face FromWire(const TopoDS_Wire& wire);
        /**
         * Construct an outer wire from the given edge
         * and construct a face from the outer wire.
         * If wire.IsNull(), then result.IsNull() as well.
         */
        TopoDS_Face FromEdge(const TopoDS_Edge& edge);
        /**
         * Construct an outer wire from the given edges
         * and construct a face from the outer wire.
         * If wire.IsNull(), then result.IsNull() as well.
         */
        TopoDS_Face FromEdges(const std::initializer_list<TopoDS_Edge>& edges);
        /**
         * Construct an outer wire from the given edges
         * and construct a face from the outer wire.
         */
        TopoDS_Face FromEdges(const std::vector<TopoDS_Edge>& edges);
        /**
         * Construct an outer wire from points, linearly connecting each point to the next.
         * The last point is automatically connected to the first point, unless they are equal.
         * Equivalent to calling Face::FromWire(Wire::FromPoints(points, true))
         */
        TopoDS_Face FromPoints(const std::vector<gp_Pnt>& points);

        /**
         * Compute the normal of a surface at the given U/V coordinates.
         * @param surf The surface
         * @param u The U coordinate
         * @param v The V coordinate
         * @param precision Affects computation speed.
         * @returns The gp_Ax1 of the point on the surface described by U/V coords and the normal direction, or nothing if the face does not have any surface
         */
        std::optional<gp_Ax1> Normal(const TopoDS_Face& face, double u = 0.0, double v = 0.0, double precision=1e-6);

        /**
         * Compute the normal direction of a surface at the given U/V coordinates.
         * @param surf The surface
         * @param u The U coordinate
         * @param v The V coordinate
         * @param precision Affects computation speed.
         */
        std::optional<gp_Dir> NormalDirection(const TopoDS_Face& face, double u = 0.0, double v = 0.0, double precision=1e-6);

    }
}