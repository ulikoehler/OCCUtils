#pragma once
#include <gp_Dir.hxx>
#include <gp_Dir2d.hxx>

gp_Vec operator*(const gp_Dir &a, double factor);

namespace OCCUtils {
    namespace Direction {
        /**
         * Get the global X axis direction
         */
        gp_Dir X();
        /**
         * Get the global Y axis direction
         */
        gp_Dir Y();
        /**
         * Get the global Z axis direction
         */
        gp_Dir Z();
        /**
         * Get the global -X axis direction
         */
        gp_Dir MinusX();
        /**
         * Get the global -Y axis direction
         */
        gp_Dir MinusY();
        /**
         * Get the global -Z axis direction
         */
        gp_Dir MinusZ();

        
        /**
         * Get the global 2D X axis direction
         */
        gp_Dir2d X2d();
        /**
         * Get the global 2D -X axis direction
         */
        gp_Dir2d MinusX2d();
        /**
         * Get the global 2D Y axis direction
         */
        gp_Dir2d Y2d();
        /**
         * Get the global 2D -Y axis direction
         */
        gp_Dir2d MinusY2d();

        /**
         * Get the direction that is orthogonal to both a and b.
         */
        gp_Dir Orthogonal(const gp_Dir& a, const gp_Dir& b);
    }
}