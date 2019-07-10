#include "occutils/Curve.hxx"
#include <BRep_Tool.hxx>
#include <GCPnts_AbscissaPoint.hxx>

GeomAdaptor_Curve OCCUtils::Curve::FromEdge(const TopoDS_Edge& edge) {
    Standard_Real umin, umax;
    // Get unbounded curve plus separate bounding parameters
    auto rawCurve = BRep_Tool::Curve(edge, umin, umax);
    return GeomAdaptor_Curve(rawCurve, umin, umax);
}

GeomAdaptor_Curve OCCUtils::Curve::FromTrimmedCurve(const Geom_TrimmedCurve &curve) {
    return GeomAdaptor_Curve(
            curve.BasisCurve(), curve.FirstParameter(), curve.LastParameter()
    );
}
    
double OCCUtils::Curve::Length(const GeomAdaptor_Curve& curve) {
    return GCPnts_AbscissaPoint::Length(curve);
}

double OCCUtils::Curve::Length(const Handle(Geom_Curve)& curve) {
    return Length(GeomAdaptor_Curve(curve));
}

double OCCUtils::Curve::Length(const Geom_TrimmedCurve &curve) {
    return Length(Curve::FromTrimmedCurve(curve));
}


bool OCCUtils::Curve::IsLine(const GeomAdaptor_Curve& curve) {
    return curve.GetType() == GeomAbs_Line;
}

bool OCCUtils::Curve::IsCircle(const GeomAdaptor_Curve& curve) {
    return curve.GetType() == GeomAbs_Circle;
}

bool OCCUtils::Curve::IsEllipse(const GeomAdaptor_Curve& curve) {
    return curve.GetType() == GeomAbs_Ellipse;
}

bool OCCUtils::Curve::IsHyperbola(const GeomAdaptor_Curve& curve) {
    return curve.GetType() == GeomAbs_Hyperbola;
}

bool OCCUtils::Curve::IsParabola(const GeomAdaptor_Curve& curve) {
    return curve.GetType() == GeomAbs_Parabola;
}

bool OCCUtils::Curve::IsBezier(const GeomAdaptor_Curve& curve) {
    return curve.GetType() == GeomAbs_BezierCurve;
}

bool OCCUtils::Curve::IsBSpline(const GeomAdaptor_Curve& curve) {
    return curve.GetType() == GeomAbs_BSplineCurve;
}

bool OCCUtils::Curve::IsOffsetCurve(const GeomAdaptor_Curve& curve) {
    return curve.GetType() == GeomAbs_OffsetCurve;
}

bool OCCUtils::Curve::IsOther(const GeomAdaptor_Curve& curve) {
    return curve.GetType() == GeomAbs_OtherCurve;
}


std::vector<GeomAdaptor_Curve> OCCUtils::Curves::Only(const std::vector<GeomAdaptor_Curve>& curves,
    GeomAbs_CurveType type) {
        return Filter(curves, [=](const GeomAdaptor_Curve& curve) {
            return curve.GetType () == type;
        });
    }

/**
 * Filter a list of curves: Get only curves for which the given predicate returns true
 */
std::vector<GeomAdaptor_Curve> OCCUtils::Curves::Filter(const std::vector<GeomAdaptor_Curve>& curves,
    std::function<bool(const GeomAdaptor_Curve& curve)> predicate) {
    std::vector<GeomAdaptor_Curve> ret;
    ret.reserve(curves.size());
    for(const auto& curve: curves) {
        if(predicate(curve)) {
            ret.push_back(curve);
        }
    }
    return ret;
}