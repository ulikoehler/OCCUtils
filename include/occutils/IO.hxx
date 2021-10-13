#pragma once
#include <XSControl_Reader.hxx>
#include <TopoDS_Shape.hxx>
#include <string>
#include <memory>

namespace OCCUtils {
    namespace IO {
        /**
         * Read the given file and extract a shape from it.
         * STEP/IGES filetype is determined automatically by filename extension - see STEPorIGESReader().
         *
         * Returns:
         * - A null shape if empty
         * - If there is a single shape, that shape
         * - If there are multiple shapes, a TopoDS_Compound of that shape.
         *
         * This function basically works like this:
         * - IO::Reader::STEPorIGESReader(filename)
         * - IO::Reader::ReadFile(reader, filename)
         * - IO::Reader::ReadOneShape(reader)
         */
        TopoDS_Shape Read(const std::string& filename);

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

            /**
             * Make the given XSControl_Reader read the given file.
             * @throws OCCIOException in case of read error
             */
            void ReadFile(const std::shared_ptr<XSControl_Reader>& reader, const std::string& filename);

            /**
             * Read a single shape from the given reader:
             * - A null shape if empty
             * - If there is a single shape, that shape
             * - If there are multiple shapes, a TopoDS_Compound of that shape.
             *
             * Preconditions:
             * - Initialize correct reader type (STEP or IGES)
             * - Call ReadFile() to read the input
             */
            TopoDS_Shape ReadOneShape(const std::shared_ptr<XSControl_Reader>& reader);
        }
    }
}