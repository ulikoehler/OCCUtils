#include "occutils/Boolean.hxx"
#include "occutils/ListUtils.hxx"
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
