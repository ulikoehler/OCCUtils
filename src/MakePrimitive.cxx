#include "occutils/MakePrimitive.hxx"
#include "occutils/Directions.hxx"
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>

using namespace OCCUtils;

TopoDS_Solid OCCUtils::Primitives::MakeBox(
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

TopoDS_Solid OCCUtils::Primitives::MakeCylinder(
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
    gp_Dir axis = (orientation == Orientation::X ? Directions::X() : (orientation == Orientation::Y ? Directions::Y() : Directions::Z()));
    // Build primitive
    gp_Ax2 ax(origin, axis);
    BRepPrimAPI_MakeCylinder cyl(ax, diameter / 2.0, length);
    cyl.Build();
    return cyl.Solid();
}