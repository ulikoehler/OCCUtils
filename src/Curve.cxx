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