#include "occutils/Face.hxx"
#include "occutils/Wire.hxx"

#include <BRepBuilderAPI_MakeFace.hxx>

using namespace OCCUtils;

TopoDS_Face OCCUtils::Face::FromWire(const TopoDS_Wire& wire) {
    if (wire.IsNull()) {
        return TopoDS_Face();
    }
	BRepBuilderAPI_MakeFace faceMaker(wire);
    return faceMaker.IsDone() ? faceMaker.Face() : TopoDS_Face();
}

TopoDS_Face OCCUtils::Face::FromEdges(const std::initializer_list<TopoDS_Edge>& edges) {
    return FromWire(Wire::FromEdges(edges));
}

TopoDS_Face OCCUtils::Face::FromEdges(const std::vector<TopoDS_Edge>& edges) {
    return FromWire(Wire::FromEdges(edges));
}
