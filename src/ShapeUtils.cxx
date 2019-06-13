#include "occutils/ShapeUtils.hxx"

bool OCCUtils::ShapeUtils::IsSolid(const TopoDS_Shape &shape) { return shape.ShapeType() == TopAbs_SOLID; }
bool OCCUtils::ShapeUtils::IsFace(const TopoDS_Shape &shape) { return shape.ShapeType() == TopAbs_FACE; }
bool OCCUtils::ShapeUtils::IsEdge(const TopoDS_Shape &shape) { return shape.ShapeType() == TopAbs_EDGE; }
bool OCCUtils::ShapeUtils::IsWire(const TopoDS_Shape &shape) { return shape.ShapeType() == TopAbs_WIRE; }
bool OCCUtils::ShapeUtils::IsVertex(const TopoDS_Shape &shape) { return shape.ShapeType() == TopAbs_VERTEX; }


TopTools_ListOfShape OCCUtils::ShapeList::ToListOfShape(const std::initializer_list<TopoDS_Shape>& shapes) {
    TopTools_ListOfShape ret;
    for(const auto& shape : shapes) {
        ret.Append(shape);
    }
    return ret;
}

TopTools_ListOfShape OCCUtils::ShapeList::ToListOfShape(const std::vector<TopoDS_Shape>& shapes) {
    TopTools_ListOfShape ret;
    for(const auto& shape : shapes) {
        ret.Append(shape);
    }
    return ret;
}