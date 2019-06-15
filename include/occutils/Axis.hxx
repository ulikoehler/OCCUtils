#pragma once
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>

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
    namespace Ax2 {
        /**
         * Initialize a gp_Ax2 from a gp_Ax1.
         * Note that the main direction is strictly defined,
         * but the "X" direction isn't. However for many use-cases
         * this is fine.
         */
        gp_Ax2 FromAx1(const gp_Ax1& axis);
        /**
         * Get the Ax1 with:
         *  - Location = origin point
         *  - Main axis = X axis
         *  - Normal: Automatically defined
         */
        gp_Ax2 OX();
        /**
         * Get the Ax1 with:
         *  - Location = origin point
         *  - Main axis = Y axis
         *  - Normal: Automatically defined
         */
        gp_Ax2 OY();
        /**
         * Get the Ax1 with:
         *  - Location = origin point
         *  - Main axis = Z axis
         *  - Normal: Automatically defined
         */
        gp_Ax2 OZ();
        /**
         * Get the Ax1 with:
         *  - Location = origin point
         *  - Main axis = negative X axis
         *  - Normal: Automatically defined
         */
        gp_Ax2 OMinusX();
        /**
         * Get the Ax1 with:
         *  - Location = origin point
         *  - Main axis = negative Y axis
         *  - Normal: Automatically defined
         */
        gp_Ax2 OMinusY();
        /**
         * Get the Ax1 with:
         *  - Location = origin point
         *  - Main axis = negative Z axis
         *  - Normal: Automatically defined
         */
        gp_Ax2 OMinusZ();
    }
}