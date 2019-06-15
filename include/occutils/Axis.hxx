#pragma once
#include <gp_Ax1.hxx>

namespace OCCUtils {
    namespace Ax1
    {
        /**
         * Get the Ax1 with:
         *  - Location = origin point
         *  - Direction = X axis
         */
        gp_Ax1 OX();
        /**
         * Get the Ax1 with:
         *  - Location = origin point
         *  - Direction = Y axis
         */
        gp_Ax1 OY();
        /**
         * Get the Ax1 with:
         *  - Location = origin point
         *  - Direction = Z axis
         */
        gp_Ax1 OZ();
        /**
         * Get the Ax1 with:
         *  - Location = origin point
         *  - Direction = negative X axis
         */
        gp_Ax1 OMinusX();
        /**
         * Get the Ax1 with:
         *  - Location = origin point
         *  - Direction = negative Y axis
         */
        gp_Ax1 OMinusY();
        /**
         * Get the Ax1 with:
         *  - Location = origin point
         *  - Direction = negative Z axis
         */
        gp_Ax1 OMinusZ();
    }
}