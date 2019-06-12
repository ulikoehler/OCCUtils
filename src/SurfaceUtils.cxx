#include "occutils/SurfaceUtils.hxx"
#include <GProp_GProps.hxx>
#include <BRepGProp.hxx>
#include <BRepLib_FindSurface.hxx>

using namespace std;

double OCCUtils::SurfaceUtils::Area(const TopoDS_Shape& face) {
    GProp_GProps gprops;
    BRepGProp::SurfaceProperties(face, gprops);
    return gprops.Mass();
}

std::optional<GeomAdaptor_Surface> OCCUtils::SurfaceUtils::SurfaceFromFace(const TopoDS_Face& face) {
    BRepLib_FindSurface bfs(face);
    if (!bfs.Found()) {
        return std::nullopt;
    }
    return make_optional(bfs.Surface());
}

gp_Pnt OCCUtils::SurfaceUtils::CenterOfMass(const TopoDS_Shape& face) {
    GProp_GProps gprops;
    BRepGProp::SurfaceProperties(face, gprops);
    return gprops.CentreOfMass();
}

std::pair<double, gp_Pnt> OCCUtils::SurfaceUtils::AreaAndCenterOfMass(const TopoDS_Shape& face) {
    GProp_GProps gprops;
    BRepGProp::SurfaceProperties(face, gprops);
    return std::make_pair(gprops.Mass(), gprops.CentreOfMass());
}
