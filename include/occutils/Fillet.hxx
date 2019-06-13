#pragma once
#include <TopoDS_Shape.hxx>

namespace OCCUtils {
    namespace Fillet {
        /**
         * Fillet all edges of the given shape using a single radius
         * and return the filleted shape.
         *
         * Usually the shape is a solid.
         */
        TopoDS_Shape FilletAll(const TopoDS_Shape& shape, double radius=1.0);
    }
}