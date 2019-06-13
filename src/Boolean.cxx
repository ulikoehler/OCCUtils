#include "occutils/Boolean.hxx"
#include "occutils/ShapeUtils.hxx"
#include <BRepAlgoAPI_Fuse.hxx>

using namespace OCCUtils::ShapeList;

TopoDS_Shape OCCUtils::Boolean::Fuse(const std::initializer_list<TopoDS_Shape>& shapes) {
    // NOTE: BRepAlgoAPI_Fuse constructor with two shapes is deprecated
    TopTools_ListOfShape shapeList = OCCUtils::ShapeList::ToListOfShape(shapes);
    return Fuse(shapeList);
}

TopoDS_Shape OCCUtils::Boolean::Fuse(const std::vector<TopoDS_Shape>& shapes) {
    TopTools_ListOfShape shapeList = OCCUtils::ShapeList::ToListOfShape(shapes);
    return Fuse(shapeList);
}

TopoDS_Shape OCCUtils::Boolean::Fuse(const TopTools_ListOfShape& shapes) {
    BRepAlgoAPI_Fuse fuse;
    fuse.SetArguments(shapes);
    fuse.Build();
    return fuse.Shape(); // Raises NotDone if not done.
}
