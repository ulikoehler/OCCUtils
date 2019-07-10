#include "occutils/Surface.hxx"
#include <GProp_GProps.hxx>
#include <BRepGProp.hxx>
#include <BRepLib_FindSurface.hxx>
#include <algorithm>
#include <GeomLProp_SLProps.hxx>
#include <sstream>
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


std::vector<OCCUtils::Surfaces::SurfaceInfo> OCCUtils::Surfaces::Only(const std::vector<SurfaceInfo>& surfaces,
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

void OCCUtils::Surfaces::SurfaceTypeStats::Add(GeomAbs_SurfaceType typ, size_t cnt) {
    if(count.count(typ) == 0) {
        count[typ] = cnt;
    } else {
        count[typ] = count[typ] + cnt;
    }
}

size_t OCCUtils::Surfaces::SurfaceTypeStats::Count(GeomAbs_SurfaceType typ) {
    if(count.count(typ) == 0) {
        return 0;
    } else {
        return count[typ];
    }
}

std::string OCCUtils::Surfaces::SurfaceTypeStats::Summary() {
    ostringstream ss;
    ss << "{\n";
    if (Count(GeomAbs_Plane)) {
        ss << "\tGeomAbs_Plane = " << Count(GeomAbs_Plane) << '\n';
    }
    if (Count(GeomAbs_Cylinder)) {
        ss << "\tGeomAbs_Cylinder = " << Count(GeomAbs_Cylinder) << '\n';
    }
    if (Count(GeomAbs_Cone)) {
        ss << "\tGeomAbs_Cone = " << Count(GeomAbs_Cone) << '\n';
    }
    if (Count(GeomAbs_Sphere)) {
        ss << "\tGeomAbs_Sphere = " << Count(GeomAbs_Sphere) << '\n';
    }
    if (Count(GeomAbs_Torus)) {
        ss << "\tGeomAbs_Torus = " << Count(GeomAbs_Torus) << '\n';
    }
    if (Count(GeomAbs_BezierSurface)) {
        ss << "\tGeomAbs_BezierSurface = " << Count(GeomAbs_BezierSurface) << '\n';
    }
    if (Count(GeomAbs_BSplineSurface)) {
        ss << "\tGeomAbs_BSplineSurface = " << Count(GeomAbs_BSplineSurface) << '\n';
    }
    if (Count(GeomAbs_SurfaceOfRevolution)) {
        ss << "\tGeomAbs_SurfaceOfRevolution = " << Count(GeomAbs_SurfaceOfRevolution) << '\n';
    }
    if (Count(GeomAbs_SurfaceOfExtrusion)) {
        ss << "\tGeomAbs_SurfaceOfExtrusion = " << Count(GeomAbs_SurfaceOfExtrusion) << '\n';
    }
    if (Count(GeomAbs_OffsetSurface)) {
        ss << "\tGeomAbs_OffsetSurface = " << Count(GeomAbs_OffsetSurface) << '\n';
    }
    if (Count(GeomAbs_OtherSurface)) {
        ss << "\tGeomAbs_OtherSurface = " << Count(GeomAbs_OtherSurface) << '\n';
    }
    ss << "}";
    return ss.str();
}

OCCUtils::Surfaces::SurfaceTypeStats OCCUtils::Surfaces::Statistics(const std::vector<SurfaceInfo>& surfaces) {
    SurfaceTypeStats stats;
    for(const auto& info : surfaces) {
        stats.Add(info.surface.GetType());
    }
    return stats;
}

gp_Ax1 OCCUtils::Surface::Normal(const GeomAdaptor_Surface& surf, const gp_Pnt2d& uv, double precision) {
    return Normal(surf, uv.X(), uv.Y(), precision);
}

gp_Ax1 OCCUtils::Surface::Normal(const GeomAdaptor_Surface& surf, const gp_XY& uv, double precision) {
    return Normal(surf, uv.X(), uv.Y(), precision);
}

gp_Ax1 OCCUtils::Surface::Normal(const GeomAdaptor_Surface& surf, double u, double v, double precision) {
    GeomLProp_SLProps props(surf.Surface(), u, v, 1 /* max 1 derivation */, precision);
    return gp_Ax1(props.Value(), props.Normal());
}

gp_Dir OCCUtils::Surface::NormalDirection(const GeomAdaptor_Surface& surf, double u, double v, double precision) {
    GeomLProp_SLProps props(surf.Surface(), u, v, 1 /* max 1 derivation */, precision);
    return props.Normal();
}

/**
 * Sample the point on the given surface at the given U/V coordinates.
 * The point represents the 0th derivative.
 */
gp_Pnt OCCUtils::Surface::PointAt(const GeomAdaptor_Surface& surf, double u, double v) {
    return surf.Value(u, v);
}

gp_Pnt OCCUtils::Surface::PointAt(const GeomAdaptor_Surface& surf, const gp_Pnt2d& uv) {
    return surf.Value(uv.X(), uv.Y());
}

gp_Pnt OCCUtils::Surface::PointAt(const GeomAdaptor_Surface& surf, const gp_XY& uv) {
    return surf.Value(uv.X(), uv.Y());
}

vector<gp_XY> OCCUtils::Surface::UniformUVSampleLocations(const GeomAdaptor_Surface& surf, size_t uSamples, size_t vSamples) {
    double u0 = surf.FirstUParameter();
    double v0 = surf.FirstVParameter();
    
    double uInterval = (surf.LastUParameter() - u0) / (uSamples - 1); // -1: include both end points
    double vInterval = (surf.LastVParameter() - v0) / (vSamples - 1); // -1: include both end points

    vector<gp_XY> ret;
    ret.reserve(uSamples * vSamples);
    for (size_t u = 0; u < uSamples; u++) {
        for (size_t v = 0; v < vSamples; v++) {
            ret.emplace_back(u0 + uInterval * u, v0 + vInterval * v);
        }
    }
    return ret;
}

vector<gp_XY> OCCUtils::Surface::UniformUVSampleLocationsWithin(const GeomAdaptor_Surface& surf, size_t uSamples, size_t vSamples) {
    double u0 = surf.FirstUParameter();
    double v0 = surf.FirstVParameter();
    
    double uInterval = (surf.LastUParameter() - u0) / (uSamples + 1);
    double vInterval = (surf.LastVParameter() - v0) / (vSamples + 1);

    vector<gp_XY> ret;
    ret.reserve(uSamples * vSamples);
    for (size_t u = 1; u < uSamples; u++) {
        for (size_t v = 1; v < vSamples; v++) {
            ret.emplace_back(u0 + uInterval * u, v0 + vInterval * v);
        }
    }
    return ret;
}
