#pragma once
#include <TopoDS_Shape.hxx>
#include <string>

namespace OCCUtils {
    namespace STEP {
        /**
         * Export a shape to a file
         * Units: M, MM, KM, INCH, FT, MI, MIL, UM, CM, UIN
         */
        void ExportSTEP(
            const TopoDS_Shape& shape,
            const std::string& filename,
            const std::string& unit = "MM");
    }
}