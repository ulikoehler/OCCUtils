#pragma once
#include <gp_Pnt.hxx>
#include <initializer_list>
#include <vector>

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

        /**
         * Get the point of mean X/Y/Z between the given points
         */
        gp_Pnt Middle(const std::initializer_list<gp_Pnt>& points);
        gp_Pnt Middle(const std::vector<gp_Pnt>& points);
    }
}