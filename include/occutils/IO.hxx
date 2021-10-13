#pragma once
#include <TopoDS_Shape.hxx>
#include <string>
#include <memory>

namespace OCCUtils {
    namespace IO {
        namespace Reader {
            /**
             * Get the appropriate XSControl_Reader instance for the given filename.
             * - If filename ends with ".stp" or ".step" (case-insensitive), it will use STEPControl_Reader()
             * - If filename ends with ".iges" or ".igs" (case-insensitive), it will use IGESControl_Reader()
             * 
             * NOTE: This does NOT actually read the file, just initialize an empty reader
             * 
             * @throws OCCIOException in case of error (could not determine filename)
             */
            std::shared_ptr<XSControl_Reader> STEPorIGESReader(const std::string& filename);
            /**
             * Like STEPorIGESReader(), but ignores the filename and always uses a STEPControl_Reader reader.
             */
            std::shared_ptr<XSControl_Reader> STEPReader();
            /**
             * Like STEPorIGESReader(), but ignores the filename and always uses a IGESControl_Reader reader.
             */
            std::shared_ptr<XSControl_Reader> IGESReader();
        }
    }
}