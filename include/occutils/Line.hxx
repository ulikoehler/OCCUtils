#pragma once
/**
 * Utilities for analyzing lines
 */
#include <gp_Ax1.hxx>
#include <gp_Lin.hxx>
#include <gp_Lin2d.hxx>
#include <optional>

namespace OCCUtils {
    namespace Line {
        
        /**
         * @return true only if lin1 is normal to lin2 within angularTolerance
         */
        bool IsNormal(const gp_Lin &lin1, const gp_Lin &lin2, double angularTolerance=1e-6);


        /**
         * @return true if lin1 is parallel to lin2 to within angularTolerance
         */
        bool IsParallel(const gp_Lin &lin1, const gp_Lin &lin2, double angularTolerance=1e-6);

        /**
         * @return true if lin1 is parallel to lin2 to within angularTolerance
         */
        bool IsParallel(const gp_Lin2d &lin1, const gp_Lin2d &lin2, double angularTolerance=1e-6);

        /**
         * Comute the 2D intersection between two lines.
         * @returns nullopt if there is no intersection or the Algorithm fails, the 2D point else
         */
        std::optional<gp_Pnt2d> Intersection(const gp_Lin2d &lin1, const gp_Lin2d &lin2);

    }
}