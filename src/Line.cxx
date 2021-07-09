#include "occutils/Line.hxx"
#include <BRepAlgoAPI_Cut.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <IntAna2d_AnaIntersection.hxx>

bool OCCUtils::Line::IsNormal(const gp_Lin &lin1, const gp_Lin &lin2, double angularTolerance) {
    // lin.Position() returns a gp_Ax1 that can be used to compute the normalness
    return lin1.Position().IsNormal(lin2.Position(), angularTolerance);
}

bool OCCUtils::Line::IsParallel(const gp_Lin &lin1, const gp_Lin &lin2, double angularTolerance) {   
    return lin1.Position().IsParallel(lin2.Position(), angularTolerance);
}

bool OCCUtils::Line::IsParallel(const gp_Lin2d &lin1, const gp_Lin2d &lin2, double angularTolerance) {   
    return lin1.Position().IsParallel(lin2.Position(), angularTolerance);
}

std::optional<gp_Pnt2d> OCCUtils::Line::Intersection(const gp_Lin2d &lin1, const gp_Lin2d &lin2) {
    auto intersector = IntAna2d_AnaIntersection(lin1, lin2);
    if(!intersector.IsDone()) { // Algorithm failure, returned as no intersection
        return std::nullopt;
    }
    if (intersector.NbPoints() == 0 || intersector.NbPoints() > 1) {
        return std::nullopt;
    }
    return intersector.Point(1).Value();
}