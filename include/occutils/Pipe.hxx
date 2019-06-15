#pragma once
#include <TopoDS_Shape.hxx>
#include <TopoDS_Wire.hxx>

namespace OCCUtils {
    namespace Pipe {
        TopoDS_Shape FromSplineAndProfile(const TopoDS_Wire& wire, const TopoDS_Shape& profile); 
    }
}