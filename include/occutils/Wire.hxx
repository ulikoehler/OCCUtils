#pragma once
#include <TopoDS_Wire.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <vector>
#include <optional>
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
         * Make a TopoDS_Wire by linearly connecting all of the given points in order,
         * @param close If set to true, connect the last point to the first point.
         */
        TopoDS_Wire FromPoints(const std::vector<gp_Pnt>& edges, bool close=false);

        /**
         * Build a wire incrementally,
         * uses relative coordinates.
         * 
         * This is a convenience wrapper to
         * programmatically build wires.
         */
        class IncrementalBuilder {
        public:
            IncrementalBuilder(const gp_Pnt& pnt);

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
             * Get the current direction vector,
             * i.e. the end direction of the resulting edge.
             */
            std::optional<gp_Dir> Direction();
            /**
             * Get the current position
             */
            gp_Pnt Location();

            /**
             * Get the resulting wire.
             */
            TopoDS_Wire Wire();

            /**
             * Create a pipe from the wire using the given profile.
             */
            TopoDS_Shape Pipe(const TopoDS_Face& profile);
            /**
             * Create a pipe from the wire using a circular profile
             * of the given radius.
             */
            TopoDS_Shape PipeWithCircularProfile(double radius);

            // Current location
            gp_Pnt current;
            // Current direction
            std::optional<gp_Dir> currentDirection;
            std::vector<TopoDS_Edge> edges;
        };
    }
}