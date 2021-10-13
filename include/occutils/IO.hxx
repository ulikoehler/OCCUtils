#pragma once
#include <TopoDS_Shape.hxx>
#include <string>
#include <memory>

namespace OCCUtils {
    namespace IO {
        /**
         * Get the appropriate XSControl_Reader instance for the given filename.
         * - If filename ends with ".stp" or ".step" (case-insensitive), it will use STEPControl_Reader()
         * - If filename ends with ".iges" or ".igs" (case-insensitive), it will use IGESControl_Reader()
         * 
         * and subsequently call reader->ReadFile(filename) on it.
         * 
         * @throws OCCIOException in case of error (could not determine filename)
         */
        std::shared_ptr<XSControl_Reader> STEPorIGESReader(const std::string& filename);
    }
}