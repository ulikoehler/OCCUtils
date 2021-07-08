#pragma once
/**
 * Utilities for analyzing lines
 */
#include <gp_Ax1.hxx>
#include <gp_Lin.hxx>

namespace OCCUtils {
    namespace Line {
        
        /**
         * @return true only if lin1 is parallel to lin2
         */
        bool IsNormal(const gp_Lin &lin1, const gp_Lin &lin2, double angularTolerance=1e-6);


        /**
         * @return true if lin1 is parallel to lin2 to within angularTolerance
         */
        bool IsParallel(const gp_Lin &lin1, const gp_Lin &lin2, double angularTolerance=1e-6);
    }
}