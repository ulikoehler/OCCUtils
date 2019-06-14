#pragma once
#include <TopoDS_Wire.hxx>
#include <TopoDS_Edge.hxx>
#include <vector>

namespace OCCUtils {
    namespace Wire {
        /**
         * Create a wire from one or multiple edges.
         * Conveniece function to be used like this:
         *  Wire::FromEdges
         */
        TopoDS_Wire FromEdges(const std::initializer_list<TopoDS_Edge>& edges);
        TopoDS_Wire FromEdges(const std::vector<TopoDS_Edge>& edges);
    }
}