#include "occutils/Surface.hxx"
#include <GProp_GProps.hxx>
#include <BRepGProp.hxx>
#include <BRepLib_FindSurface.hxx>

using namespace std;

double OCCUtils::Surface::Area(const TopoDS_Shape& face) {
    GProp_GProps gprops;
    BRepGProp::SurfaceProperties(face, gprops);
    return gprops.Mass();
}

std::optional<GeomAdaptor_Surface> OCCUtils::Surface::FromFace(const TopoDS_Face& face) {
    BRepLib_FindSurface bfs(face);
    if (!bfs.Found()) {
        return std::nullopt;
    }
    return make_optional(bfs.Surface());
}

gp_Pnt OCCUtils::Surface::CenterOfMass(const TopoDS_Shape& face) {
    GProp_GProps gprops;
    BRepGProp::SurfaceProperties(face, gprops);
    return gprops.CentreOfMass();
}

std::pair<double, gp_Pnt> OCCUtils::Surface::AreaAndCenterOfMass(const TopoDS_Shape& face) {
    GProp_GProps gprops;
    BRepGProp::SurfaceProperties(face, gprops);
    return std::make_pair(gprops.Mass(), gprops.CentreOfMass());
}
