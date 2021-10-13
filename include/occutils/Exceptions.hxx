#pragma once
#include <stdexcept>
/**
 * All OCCUtils exceptions derive from this
 */
struct OCCUtilsBaseException : std::invalid_argument {
    OCCUtilsBaseException(const char *msg) : invalid_argument(msg) {}
    OCCUtilsBaseException(const std::string &msg) : invalid_argument(msg) {}
};

/**
 * Baseclass for exceptions that directly relate to the
 * BRep topology.
 */
struct OCCConstructionFailedException : OCCUtilsBaseException {
    OCCConstructionFailedException(const char *msg) : OCCUtilsBaseException(msg) {}
    OCCConstructionFailedException(const std::string &msg) : OCCUtilsBaseException(msg) {}
};

/**
 * Exception occuring related to IO of data
 */
struct OCCIOException : OCCUtilsBaseException {
    OCCIOException(const char *msg) : OCCUtilsBaseException(msg) {}
    OCCIOException(const std::string &msg) : OCCUtilsBaseException(msg) {}
};

/**
 * Baseclass for exceptions that directly relate to the
 * BRep topology.
 */
struct OCCTopologyException : OCCUtilsBaseException {
    OCCTopologyException(const char *msg) : OCCUtilsBaseException(msg) {}
    OCCTopologyException(const std::string &msg) : OCCUtilsBaseException(msg) {}
};

/**
 * Thrown if there are either too many or too few
 * sub-topologies in a topology,
 * e.g. too many or too few edges in a face.
 * "Too many" or "Too few" is relative to what the calling code expects.
 */
struct OCCTopologyCountMismatchException : OCCTopologyException {
    OCCTopologyCountMismatchException(const char *msg) : OCCTopologyException(msg) {}
    OCCTopologyCountMismatchException(const std::string &msg) : OCCTopologyException(msg) {}
};
