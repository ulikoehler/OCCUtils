#pragma once
#include <gp_Dir.hxx>

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
    }
}