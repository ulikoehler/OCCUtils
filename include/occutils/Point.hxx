#pragma once
#include <gp_Pnt.hxx>
#include <initializer_list>
#include <vector>

/**
 * Add the coordinates of two points.
 * Performs coordinate-wise addition.
 */
gp_Pnt operator+(const gp_Pnt &a, const gp_Pnt &b);
gp_Pnt operator+(const gp_Pnt &a, const gp_Vec &b);
gp_Pnt operator+(const gp_Pnt &a, const gp_XYZ &b);

/**
 * Subtract the coordinates of two points.
 * Performs coordinate-wise subtraction.
 */
gp_Pnt operator-(const gp_Pnt &a, const gp_Pnt &b);
gp_Pnt operator-(const gp_Pnt &a, const gp_Vec &b);
gp_Pnt operator-(const gp_Pnt &a, const gp_XYZ &b);

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
        gp_Pnt Midpoint(const std::initializer_list<gp_Pnt>& points);
        gp_Pnt Midpoint(const std::vector<gp_Pnt>& points);

        /**
         * Get the distance between pnt and axis,
         * strictly defined as the distance between pnt and the orthogonal
         * projection of pnt onto axis.
         */
        double Distance(const gp_Pnt& pnt, const gp_Ax1& axis);
    }
}