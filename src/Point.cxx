#include "occutils/Point.hxx"
#include "occutils/Axis.hxx"

#include <Geom2dAPI_ProjectPointOnCurve.hxx>
#include <Geom2d_Line.hxx>
#include <Geom_Line.hxx>
#include <GeomAPI_ProjectPointOnCurve.hxx>

gp_Pnt OCCUtils::Point::Origin() {
    return gp_Pnt();
}

gp_Pnt operator+(const gp_Pnt &a, const gp_Pnt &b){
    return gp_Pnt(a.X() + b.X(), a.Y() + b.Y(), a.Z() + b.Z());
}

gp_Pnt operator+(const gp_Pnt &a, const gp_Vec &b){
    return gp_Pnt(a.X() + b.X(), a.Y() + b.Y(), a.Z() + b.Z());
}

gp_Pnt operator+(const gp_Pnt &a, const gp_XYZ &b){
    return gp_Pnt(a.X() + b.X(), a.Y() + b.Y(), a.Z() + b.Z());
}

gp_Pnt operator-(const gp_Pnt &a, const gp_Pnt &b){
    return gp_Pnt(a.X() - b.X(), a.Y() - b.Y(), a.Z() - b.Z());
}

gp_Pnt operator-(const gp_Pnt &a, const gp_Vec &b){
    return gp_Pnt(a.X() - b.X(), a.Y() - b.Y(), a.Z() - b.Z());
}

gp_Pnt operator-(const gp_Pnt &a, const gp_XYZ &b){
    return gp_Pnt(a.X() - b.X(), a.Y() - b.Y(), a.Z() - b.Z());
}


gp_Pnt OCCUtils::Point::Midpoint(const std::initializer_list<gp_Pnt>& points) {
    double x = 0.0, y = 0.0, z = 0.0;
    for (const gp_Pnt &pnt : points) {
        x += pnt.X();
        y += pnt.Y();
        z += pnt.Z();
    }
    size_t size = points.size();
    return gp_Pnt(x / size, y / size, z / size);

}

gp_Pnt OCCUtils::Point::Midpoint(const std::vector<gp_Pnt>& points) {
    double x = 0.0, y = 0.0, z = 0.0;
    for (const gp_Pnt &pnt : points) {
        x += pnt.X();
        y += pnt.Y();
        z += pnt.Z();
    }
    size_t size = points.size();
    return gp_Pnt(x / size, y / size, z / size);
}

double OCCUtils::Point::Distance(const gp_Pnt& pnt, const gp_Ax1& axis) {
    return Axis::Distance(axis, pnt);
}

gp_Pnt OCCUtils::Point::OrthogonalProjectOnto(const gp_Pnt &pnt, const gp_Ax1 &ax) {
    Handle(Geom_Line) hax = new Geom_Line(ax);
    auto projector = GeomAPI_ProjectPointOnCurve(pnt, hax);
    projector.Perform(pnt);
    if (projector.NbPoints() == 0) {
        // TODO use more appropriate exception
        throw std::out_of_range("Projection of point onto curve failed");
    }
    return projector.NearestPoint();
}

gp_Pnt2d OCCUtils::Point::OrthogonalProjectOnto(const gp_Pnt2d &pnt, const gp_Ax2d &ax) {
    Handle(Geom2d_Line) hax = new Geom2d_Line(ax);
    auto projector = Geom2dAPI_ProjectPointOnCurve(pnt, hax);
    if (projector.NbPoints() == 0) {
        // TODO use more appropriate exception
        throw std::out_of_range("Projection of point onto axis failed");
    }
    return projector.NearestPoint();
}


gp_Pnt OCCUtils::Point::From2d(const gp_Pnt2d& pnt) {
    return gp_Pnt(pnt.X(), pnt.Y(), 0.0);
}

gp_Pnt OCCUtils::Point::From2d(double x, double y) {
    return gp_Pnt(x, y, 0.0);
}