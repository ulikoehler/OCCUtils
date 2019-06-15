#pragma once
#include <GeomAdaptor_Curve.hxx>
#include <Geom_Curve.hxx>
#include <TopoDS_Edge.hxx>

namespace OCCUtils {
    namespace Curve {
        /**
         * Get a curve from the given edge.
         * If it fails, returnValue.Curve().IsNull() == true
         */
        GeomAdaptor_Curve FromEdge(const TopoDS_Edge& edge);
    }
}