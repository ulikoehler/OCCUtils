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

/**
 * Internal converter function
 */
template<typename T>
std::vector<TopoDS_Shape> _ToShapes(const std::vector<T>& elems) {
    // Create return vector
    std::vector<TopoDS_Shape> ret;
    ret.reserve(elems.size());
    // Do the copying
    std::copy(elems.begin(), elems.end(), std::back_inserter(ret));
    return ret;
}

std::vector<TopoDS_Shape> OCCUtils::Shapes::FromSolids(const std::vector<TopoDS_Solid>& solids) {
    return _ToShapes(solids);
}

std::vector<TopoDS_Shape> OCCUtils::Shapes::FromFaces(const std::vector<TopoDS_Face>& faces) {
    return _ToShapes(faces);
}