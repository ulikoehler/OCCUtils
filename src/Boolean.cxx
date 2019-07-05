#include "occutils/Boolean.hxx"
#include "occutils/ListUtils.hxx"
#include <BRepAlgoAPI_Cut.hxx>
#include <BRepAlgoAPI_Fuse.hxx>

using namespace OCCUtils;

TopoDS_Shape OCCUtils::Boolean::Fuse(const TopTools_ListOfShape& arguments, const TopTools_ListOfShape& tools) {
    if(arguments.Size() == 0) {
        throw std::invalid_argument("Fuse arguments must have at least one shape!");
    }
    if(tools.Size() == 0) {
        throw std::invalid_argument("Fuse tools must have at least one shape!");
    }
    // Configure fuse
    BRepAlgoAPI_Fuse fuse;
    fuse.SetArguments(arguments);
    fuse.SetTools(tools);
    // Run fuse
    fuse.Build();
    return fuse.Shape(); // Raises NotDone if not done.
}

TopoDS_Shape OCCUtils::Boolean::Fuse(const TopTools_ListOfShape& shapes) {
    // We need "tools" and "arguments".
    // For fuse, the exact split does not matter,
    // but each must be size >= 1!
    auto toolsAndArgs = ListUtils::SplitIntoHeadAndTail(shapes, 1);
    return Fuse(toolsAndArgs.second, toolsAndArgs.first);
}

TopoDS_Shape OCCUtils::Boolean::Fuse(const std::initializer_list<TopoDS_Shape>& shapes) {
    return Fuse(OCCUtils::ListUtils::ToOCCList(shapes));
}

TopoDS_Shape OCCUtils::Boolean::Cut(const TopTools_ListOfShape& positive, const TopTools_ListOfShape& negative) {
    if(positive.Size() == 0) {
        throw std::invalid_argument("Fuse positive must have at least one shape!");
    }
    if(negative.Size() == 0) {
        throw std::invalid_argument("Fuse negative must have at least one shape!");
    }
    // Configure fuse
    BRepAlgoAPI_Cut cut;
    cut.SetArguments(positive);
    cut.SetTools(negative);
    // Run cut
    cut.Build();
    return cut.Shape(); // Raises NotDone if not done.
}

TopoDS_Shape OCCUtils::Boolean::Cut(const TopoDS_Shape& positive, const TopoDS_Shape& negative) {
    return Cut(
        OCCUtils::ListUtils::ToOCCList({positive}),
        OCCUtils::ListUtils::ToOCCList({negative})
    );
}


TopoDS_Shape OCCUtils::Boolean::Cut(const TopoDS_Shape& positive, const TopTools_ListOfShape& negative) {
    return Cut(
        OCCUtils::ListUtils::ToOCCList({positive}),
        negative
    );
}