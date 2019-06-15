#pragma once
#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Edge.hxx>
#include <initializer_list>
#include <vector>

namespace OCCUtils {
    namespace Face {
        /**
         * Construct a face from the given outer wire.
         * If wire.IsNull(), then result.IsNull() as well.
         */
        TopoDS_Face FromWire(const TopoDS_Wire& wire);
        /**
         * Construct a face from an outer wire constructed from the given edges.
         * If wire.IsNull(), then result.IsNull() as well.
         */
        TopoDS_Face FromEdges(const std::initializer_list<TopoDS_Edge>& edges);
        TopoDS_Face FromEdges(const std::vector<TopoDS_Edge>& edges);
    }
}