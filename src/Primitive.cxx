#include "occutils/Primitive.hxx"
#include "occutils/Direction.hxx"
#include "occutils/Point.hxx"
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepPrimAPI_MakeCone.hxx>

using namespace OCCUtils;

TopoDS_Solid OCCUtils::Primitive::MakeBox(
    double xSize, double ySize, double zSize,
    int center,
    gp_Pnt origin) {
    // Compute offsets based on centering
    if(center & CenterX) {
        origin.SetX(origin.X() - xSize / 2.0);
    }
    if(center & CenterY) {
        origin.SetY(origin.Y() - ySize / 2.0);
    }
    if(center & CenterZ) {
        origin.SetZ(origin.Z() - zSize / 2.0);
    }
    // Build primitive
    BRepPrimAPI_MakeBox box(origin, xSize, ySize, zSize);
    box.Build();
    return box.Solid();

}


TopoDS_Solid OCCUtils::Primitive::MakeBox(const gp_Pnt& a, const gp_Pnt& b) {
    BRepPrimAPI_MakeBox box(a, b.X() - a.X(), b.Y() - a.Y(), b.Z() - a.Z());
    box.Build();
    return box.Solid();
}

TopoDS_Solid OCCUtils::Primitive::MakeBox(const gp_Vec& a, const gp_Vec& b) {
    return MakeBox(gp_Pnt(a.X(), a.Y(), a.Z()), gp_Pnt(b.X(), b.Y(), b.Z()));
}

TopoDS_Solid OCCUtils::Primitive::MakeBox(const std::pair<gp_Pnt, gp_Pnt>& ab) {
    return MakeBox(ab.first, ab.second);
}

TopoDS_Solid OCCUtils::Primitive::MakeBox(const std::pair<gp_Vec, gp_Vec>& ab) {
    return MakeBox(ab.first, ab.second);
}

TopoDS_Solid OCCUtils::Primitive::MakeCylinder(
    double diameter, double length,
    Orientation orientation,
    int center,
    gp_Pnt origin) {
    // Compute offsets based on centering
    if(center & CenterL) {
        if(orientation == Orientation::X) {
            origin.SetX(origin.X() - diameter / 2.0);
        } else if(orientation == Orientation::Y) {
            origin.SetY(origin.Y() - diameter / 2.0);
        } else if(orientation == Orientation::Z) {
            origin.SetZ(origin.Z() - diameter / 2.0);
        }
    }
    // Which axis
    gp_Dir axis = (orientation == Orientation::X ? Direction::X() : (orientation == Orientation::Y ? Direction::Y() : Direction::Z()));
    // Build primitive
    gp_Ax2 ax(origin, axis);
    BRepPrimAPI_MakeCylinder cyl(ax, diameter / 2.0, length);
    cyl.Build();
    return cyl.Solid();
}

TopoDS_Solid OCCUtils::Primitive::MakeCube(
    double size, int center, gp_Pnt origin) {
    return MakeBox(size, size, size, center, origin);
}


TopoDS_Solid OCCUtils::Primitive::MakeCone(
    gp_Ax1 axis,
    double diameter1,
    double diameter2,
    double length,
    bool centerLength
) {
    BRepPrimAPI_MakeCone builder(
        gp_Ax2(
            centerLength ?
                axis.Location() - axis.Direction() * (length / 2)
                : axis.Location(),
            axis.Direction()
        ),
        diameter1, diameter2, length);
    return builder.Solid();
}