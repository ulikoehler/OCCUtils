#include "occutils/ShapeUtils.hxx"

bool OCCUtils::ShapeUtils::IsSolid(const TopoDS_Shape &shape) { return shape.ShapeType() == TopAbs_SOLID; }
bool OCCUtils::ShapeUtils::IsFace(const TopoDS_Shape &shape) { return shape.ShapeType() == TopAbs_FACE; }
bool OCCUtils::ShapeUtils::IsEdge(const TopoDS_Shape &shape) { return shape.ShapeType() == TopAbs_EDGE; }
bool OCCUtils::ShapeUtils::IsWire(const TopoDS_Shape &shape) { return shape.ShapeType() == TopAbs_WIRE; }
bool OCCUtils::ShapeUtils::IsVertex(const TopoDS_Shape &shape) { return shape.ShapeType() == TopAbs_VERTEX; }
