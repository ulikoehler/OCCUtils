#pragma once
#include <TopoDS_Edge.hxx>
#include <gp_Pnt.hxx>

namespace OCCUtils {
    namespace Edge {
        /**
         * Create a linear edge between two points
         */
        TopoDS_Edge FromPoints (const gp_Pnt& p1, const gp_Pnt& p2);
    }
}