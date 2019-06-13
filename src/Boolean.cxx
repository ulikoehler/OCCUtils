#include "occutils/Boolean.hxx"
#include "occutils/ListUtils.hxx"
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

#include <iostream>
using namespace std;

TopoDS_Shape OCCUtils::Boolean::Fuse(const TopTools_ListOfShape& shapes) {
    // We need "tools" and "arguments".
    // For fuse, the exact split does not matter,
    // but each must be size >= 1!
    auto toolsAndArgs = ListUtils::SplitIntoHeadAndTail(shapes, 1);
    // Configure fuse
    BRepAlgoAPI_Fuse fuse;
    fuse.SetTools(toolsAndArgs.first);
    fuse.SetArguments(toolsAndArgs.second);
    // Run fuse
    fuse.Build();
    return fuse.Shape(); // Raises NotDone if not done.
}
