#pragma once
#include <TopoDS_Shape.hxx>

namespace OCCUtil {
    namespace FaceUtils {

        double SurfaceArea(const TopoDS_Shape& face);
    }
}