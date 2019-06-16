#pragma once
#include <gp_Pnt.hxx>

/**
 * Add the coordinates of two points.
 * Performs coordinate-wise addition.
 */
gp_Pnt operator+(const gp_Pnt &a, const gp_Pnt &b);

/**
 * Subtract the coordinates of two points.
 * Performs coordinate-wise subtraction.
 */
gp_Pnt operator-(const gp_Pnt &a, const gp_Pnt &b);

namespace OCCUtils {
    namespace Point {
        /**
         * Return the global coordinate system's origin:
         * (0,0,0)
         */
        gp_Pnt Origin();
    }
}