#include "occutils/Shape.hxx"
#include <GProp_GProps.hxx>
#include <BRepGProp.hxx>
#include <algorithm>

bool OCCUtils::Shape::IsSolid(const TopoDS_Shape &shape) { return shape.ShapeType() == TopAbs_SOLID; }
bool OCCUtils::Shape::IsFace(const TopoDS_Shape &shape) { return shape.ShapeType() == TopAbs_FACE; }
bool OCCUtils::Shape::IsEdge(const TopoDS_Shape &shape) { return shape.ShapeType() == TopAbs_EDGE; }
bool OCCUtils::Shape::IsWire(const TopoDS_Shape &shape) { return shape.ShapeType() == TopAbs_WIRE; }
bool OCCUtils::Shape::IsVertex(const TopoDS_Shape &shape) { return shape.ShapeType() == TopAbs_VERTEX; }

double OCCUtils::Shape::Volume(const TopoDS_Shape& shape) {
    GProp_GProps gprops;
    BRepGProp::VolumeProperties(shape, gprops);
    return gprops.Mass();
}


std::vector<TopoDS_Shape> OCCUtils::Shapes::ToShapes(const std::vector<TopoDS_Solid>& solids) {
    // Create return vector
    std::vector<TopoDS_Shape> ret;
    ret.reserve(solids.size());
    // Do the copying
    std::copy(solids.begin(), solids.end(), std::back_inserter(ret));
    return ret;
}