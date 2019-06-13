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
            CenterZ = 4
        };
        /**
         * Make a box that can be centered on 
         */
        TopoDS_Solid MakeBox(
            double xSize, double ySize, double zSize,
            int center=0,
            gp_Pnt origin=gp_Pnt());
    }
}