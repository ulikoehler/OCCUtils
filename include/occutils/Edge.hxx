#pragma once
#include <TopoDS_Edge.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <gp_Dir.hxx>

namespace OCCUtils {
    namespace Edge {
        /**
         * Create a linear edge between two points
         */
        TopoDS_Edge FromPoints (const gp_Pnt& p1, const gp_Pnt& p2);
        /**
         * Create a full circle edge at origin,
         * with the circle's normal pointing at the Z direction.
         */
        TopoDS_Edge FullCircle(double radius=1.0);
        /**
         * Create a full circle edge at origin,
         * with the circle's normal pointing in the given direction.
         */
        TopoDS_Edge FullCircle(const gp_Dir& direction, double radius=1.0);
        /**
         * Create a full circle edge at axis.Location(),
         * with the circle's normal pointing to axis.Direction().
         */
        TopoDS_Edge FullCircle(const gp_Ax1& axis, double radius=1.0);
        /**
         * Create a full circle edge at center
         * with the circle's normal pointing to direction.
         */
        TopoDS_Edge FullCircle(const gp_Pnt& center, const gp_Dir& direction, double radius=1.0);
        /**
         * Create a full circle edge at axis.Location(),
         * with the circle's normal pointing to axis.Direction().
         */
        TopoDS_Edge FullCircle(const gp_Ax2& axis, double radius=1.0);

        /**
         * Like FullCircle(), but creates a circle only from
         * p1 to p2.
         * Precondition: p1 and p2 must lie on the circle.
         */
        TopoDS_Edge CircleSegment(const gp_Ax2& axis, double radius,
            const gp_Pnt& p1, const gp_Pnt& p2);
        
        /**
         * Get the length of the given edge
         */
        double Length(const TopoDS_Edge& edge);
    }
}