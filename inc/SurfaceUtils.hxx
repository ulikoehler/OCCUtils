#pragma once
#include <TopoDS_Shape.hxx>

namespace OCCUtil {
    namespace SurfaceUtils {
        /**
         * Get the total surface area of a face, solid etc.
         */
        double SurfaceArea(const TopoDS_Shape& face);
    }
}