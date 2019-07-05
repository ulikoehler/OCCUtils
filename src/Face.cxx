#include "occutils/Face.hxx"
#include "occutils/Wire.hxx"
#include "occutils/Surface.hxx"

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

TopoDS_Face OCCUtils::Face::FromEdge(const TopoDS_Edge& edge) {
    return Face::FromWire(Wire::FromEdges({edge}));
}


std::optional<gp_Ax1> OCCUtils::Face::Normal(const TopoDS_Face& face, double u, double v, double precision) {
    auto surface = Surface::FromFace(face);
    if(surface.Surface().IsNull()) {
        return std::nullopt;
    }
    return Surface::Normal(surface, u, v, precision);
}

std::optional<gp_Dir> OCCUtils::Face::NormalDirection(const TopoDS_Face& face, double u, double v, double precision) {
    auto surface = Surface::FromFace(face);
    if(surface.Surface().IsNull()) {
        return std::nullopt;
    }
    return Surface::NormalDirection(surface, u, v, precision);
}

TopoDS_Face OCCUtils::Face::FromPoints(const std::vector<gp_Pnt>& points) {
    return FromWire(Wire::FromPoints(points, true));
}