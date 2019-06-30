#include "occutils/Point.hxx"
#include "occutils/Axis.hxx"

gp_Pnt OCCUtils::Point::Origin() {
    return gp_Pnt();
}

gp_Pnt operator+(const gp_Pnt &a, const gp_Pnt &b){
    return gp_Pnt(a.X() + b.X(), a.Y() + b.Y(), a.Z() + b.Z());
}

gp_Pnt operator-(const gp_Pnt &a, const gp_Pnt &b){
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