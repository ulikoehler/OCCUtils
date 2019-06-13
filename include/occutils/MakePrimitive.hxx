#pragma once
/**
 * Create boundary representation (BRep) primitives
 */
#include <cstdint>
#include <TopoDS_Solid.hxx>
#include <gp_Pnt.hxx>

namespace OCCUtils {
    namespace Primitives {
        /**
         * Configure how a primitive is centered in the coordinate system
         */
        enum PositionCentering : uint8_t {
            CenterX = 1,
            CenterY = 2,
            CenterZ = 4,
            CenterL = 8,
            CenterD = 16
        };

        /**
         * Make a box that can be centered on all axes individually.
         * @param xSize The dimension in the X dimension
         * @param ySize The dimension in the Y dimension
         * @param zSize The dimension in the Z dimension
         * @param center A bitwise-OR (|) combination of CenterX, CenterY & CenterZ.
         * A set flag causes the box to be center in that dimension on the origin
         * @param origin The point where to create the box. Default is (0,0,0)
         */
        TopoDS_Solid MakeBox(
            double xSize, double ySize, double zSize,
            int center=0,
            gp_Pnt origin=gp_Pnt());

        /**
         * Make a box that can be centered on 
         */
        TopoDS_Solid MakeCylinder(
            double diameter, double length,
            int center=0,
            gp_Pnt origin=gp_Pnt());
    }
}