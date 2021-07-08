#include "occutils/Line.hxx"
#include <BRepAlgoAPI_Cut.hxx>
#include <BRepAlgoAPI_Fuse.hxx>

bool OCCUtils::Line::IsNormal(const gp_Lin &lin1, const gp_Lin &lin2, double angularTolerance) {
    // lin.Position() returns a gp_Ax1 that can be used to compute the normalness
    return lin1.Position().IsNormal(lin2.Position(), angularTolerance);
}

bool OCCUtils::Line::IsParallel(const gp_Lin &lin1, const gp_Lin &lin2, double angularTolerance) {   
    return lin1.Position().IsParallel(lin2.Position(), angularTolerance);
}