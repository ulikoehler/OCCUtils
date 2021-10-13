#include "occutils/IO.hxx"
#include "occutils/Exceptions.hxx"

#include <STEPControl_Reader.hxx>
#include <IGESControl_Reader.hxx>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost::algorithm;

std::shared_ptr<XSControl_Reader> OCCUtils::IO::Reader::STEPorIGESReader(const std::string& filename) {
    shared_ptr<XSControl_Reader> reader;
    // Automatically determine filename
    string lowercaseFilename = to_lower_copy(filename);
    if (ends_with(lowercaseFilename, ".step") || ends_with(lowercaseFilename, ".stp")) {
        reader = shared_ptr<XSControl_Reader>(dynamic_cast<XSControl_Reader*>(new STEPControl_Reader()));
    } else if (ends_with(lowercaseFilename, ".iges") || ends_with(lowercaseFilename, ".igs")) {
        reader = shared_ptr<XSControl_Reader>(dynamic_cast<XSControl_Reader*>(new IGESControl_Reader()));
    } else {
        throw OCCIOException("Unknown file extension (.stp/.step or .igs/.iges expected): " + filename);
    }
    return reader;
}

std::shared_ptr<XSControl_Reader> OCCUtils::IO::Reader::STEPReader() {
    return shared_ptr<XSControl_Reader>(dynamic_cast<XSControl_Reader*>(new STEPControl_Reader()));
}

std::shared_ptr<XSControl_Reader> OCCUtils::IO::Reader::IGESReader() {
    return shared_ptr<XSControl_Reader>(dynamic_cast<XSControl_Reader*>(new IGESControl_Reader()));
}