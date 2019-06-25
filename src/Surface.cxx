#include "occutils/Surface.hxx"
#include <GProp_GProps.hxx>
#include <BRepGProp.hxx>
#include <BRepLib_FindSurface.hxx>
#include <algorithm>
#include "occutils/ShapeComponents.hxx"

using namespace std;

double OCCUtils::Surface::Area(const TopoDS_Shape& face) {
    GProp_GProps gprops;
    BRepGProp::SurfaceProperties(face, gprops);
    return gprops.Mass();
}

GeomAdaptor_Surface OCCUtils::Surface::FromFace(const TopoDS_Face& face) {
    BRepLib_FindSurface bfs(face);
    if (!bfs.Found()) {
        return GeomAdaptor_Surface();
    }
    return bfs.Surface();
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


std::vector<OCCUtils::Surfaces::SurfaceInfo> OCCUtils::Surfaces::FromShape(const TopoDS_Shape& shape) {
    auto faces = ShapeComponents::AllFacesWithin(shape);
    // Create return vector
    std::vector<OCCUtils::Surfaces::SurfaceInfo> ret;
    ret.reserve(faces.size());
    for(const auto& face : faces) {
        SurfaceInfo info;
        info.face = face;
        info.surface = Surface::FromFace(face);
        if(!info.surface.Surface().IsNull()) { // If we have found the surface
            ret.push_back(info); 
        }
    }
    return ret;
}


bool OCCUtils::Surface::IsPlane(const GeomAdaptor_Surface& surf) {
    return surf.GetType() == GeomAbs_Plane;
}

bool OCCUtils::Surface::IsCylinder(const GeomAdaptor_Surface& surf) {
    return surf.GetType() == GeomAbs_Cylinder;
}

bool OCCUtils::Surface::IsCone(const GeomAdaptor_Surface& surf) {
    return surf.GetType() == GeomAbs_Cone;
}

bool OCCUtils::Surface::IsSphere(const GeomAdaptor_Surface& surf) {
    return surf.GetType() == GeomAbs_Sphere;
}

bool OCCUtils::Surface::IsTorus(const GeomAdaptor_Surface& surf) {
    return surf.GetType() == GeomAbs_Torus;
}

bool OCCUtils::Surface::IsBezierSurface(const GeomAdaptor_Surface& surf) {
    return surf.GetType() == GeomAbs_BezierSurface;
}

bool OCCUtils::Surface::IsBSplineSurface(const GeomAdaptor_Surface& surf) {
    return surf.GetType() == GeomAbs_BSplineSurface;
}

bool OCCUtils::Surface::IsSurfaceOfRevolution(const GeomAdaptor_Surface& surf) {
    return surf.GetType() == GeomAbs_SurfaceOfRevolution;
}

bool OCCUtils::Surface::IsSurfaceOfExtrusion(const GeomAdaptor_Surface& surf) {
    return surf.GetType() == GeomAbs_SurfaceOfExtrusion;
}

bool OCCUtils::Surface::IsOffsetSurface(const GeomAdaptor_Surface& surf) {
    return surf.GetType() == GeomAbs_OffsetSurface;
}

bool OCCUtils::Surface::IsOtherSurface(const GeomAdaptor_Surface& surf) {
    return surf.GetType() == GeomAbs_OtherSurface;
}


std::vector<OCCUtils::Surfaces::SurfaceInfo> OCCUtils::Surfaces::Filter(const std::vector<SurfaceInfo>& surfaces,
    GeomAbs_SurfaceType type) {
    return Filter(surfaces, [&](const GeomAdaptor_Surface& surf) {
        return surf.GetType() == type;
    });
};

/**
 * Filter surfaces by a custom filter function
 */
std::vector<OCCUtils::Surfaces::SurfaceInfo> OCCUtils::Surfaces::Filter(const std::vector<SurfaceInfo>& surfaces,
    const std::function<bool(const GeomAdaptor_Surface& surf)>& filt) {
    // Create output vector
    std::vector<SurfaceInfo> ret;
    ret.reserve(surfaces.size());
    // Run algorithm
    std::copy_if(surfaces.begin(), surfaces.end(), std::back_inserter(ret), [&](const SurfaceInfo& surf) {
        return filt(surf.surface);
    });
    return ret;
}