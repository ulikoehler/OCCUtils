#include "occutils/Curve.hxx"
#include <BRepTool.hxx>


GeomAdaptor_Curve OCCUtils::Curve::FromEdge(const TopoDS_Edge& edge) {
    Standard_Real umin, umax;
    // Get unbounded curve plus separate bounding parameters
    auto rawCurve = BRep_Tool::Curve(edge, umin, umax);
    return GeomAdaptor_Curve(rawCurve, umin, umax);
}