#pragma once
/**
 * Include this file for equality & inequality operators
 * for different datatypes where this makes sense.
 * 
 * All equalities are computed with Precision::Confusion()
 * as tolerance.
 */
#include <gp_Pnt.hxx>

// Close within tolerance
bool operator==(const gp_Pnt &a, const gp_Pnt &b);
bool operator!=(const gp_Pnt &a, const gp_Pnt &b);