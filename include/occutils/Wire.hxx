#pragma once
#include <TopoDS_Wire.hxx>
#include <TopoDS_Edge.hxx>
#include <vector>
#include <gp_Pnt.hxx>
#include <occutils/Direction.hxx>

namespace OCCUtils {
    namespace Wire {
        /**
         * Create a wire from one or multiple edges.
         * Conveniece function to be used like this:
         *  Wire::FromEdges
         */
        TopoDS_Wire FromEdges(const std::initializer_list<TopoDS_Edge>& edges);
        TopoDS_Wire FromEdges(const std::vector<TopoDS_Edge>& edges);

        /**
         * Build a wire incrementally,
         * uses relative coordinates.
         * 
         * This is a convenience wrapper to
         * programmatically build wires.
         */
        class IncrementalWireBuilder {
        public:
            IncrementalWireBuilder(const gp_Pnt& pnt);

            /**
             * Add a line segment
             */
            void Line(double dx, double dy, double dz);

            /**
             * ALPHA - API MAY CHANGE!
             * Create a 90° arc from the current position.
             */
            void Arc90(
                double dx, double dy, double dz,
                double centerDx, double centerDy, double centerDz,
                const gp_Dir& normal = Direction::Z());

            /**
             * Get the resulting wire.
             */
            TopoDS_Wire Wire();

            gp_Pnt current;
            std::vector<TopoDS_Edge> edges;
        };
    }
}