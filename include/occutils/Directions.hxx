#pragma once
#include <gp_Dir.hxx>

namespace OCCUtils {
    namespace Directions {
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
    }
}