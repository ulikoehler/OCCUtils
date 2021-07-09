#pragma once
/**
 * Include this file for equality & inequality operators
 * for different datatypes where this makes sense.
 * 
 * All equalities are computed with Precision::Confusion()
 * as tolerance.
 */
#include <gp_Pnt.hxx>
#include <gp_XYZ.hxx>
#include <gp_Vec.hxx>

bool operator==(const gp_Pnt &a, const gp_Pnt &b);
bool operator!=(const gp_Pnt &a, const gp_Pnt &b);

bool operator==(const gp_XYZ &a, const gp_XYZ &b);
bool operator!=(const gp_XYZ &a, const gp_XYZ &b);

bool operator==(const gp_Pnt2d &a, const gp_Pnt2d &b);
bool operator!=(const gp_Pnt2d &a, const gp_Pnt2d &b);

bool operator==(const gp_XY &a, const gp_XY &b);
bool operator!=(const gp_XY &a, const gp_XY &b);

/**
 * Checks vector equality with:
 *  - Precision::Confusion() linear &
 *  - Precision::Angular() angular
 * tolerances using gpVec::IsEqual().
 */
bool operator==(const gp_Vec &a, const gp_Vec &b);
bool operator!=(const gp_Vec &a, const gp_Vec &b);