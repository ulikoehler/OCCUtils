#pragma once
/**
 * Include this header to provide operator<< instances
 * for common OpenCASCADE types so that you can print them
 * using cout, cerr etc.
 */
#include <iostream>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir2d.hxx>
#include <gp_XY.hxx>
#include <gp_XYZ.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir.hxx>

std::ostream &operator<<(std::ostream &os, const gp_Pnt2d &xy);
std::ostream &operator<<(std::ostream &os, const gp_Pnt &xy);
std::ostream &operator<<(std::ostream &os, const gp_Dir2d &xy);
std::ostream &operator<<(std::ostream &os, const gp_Dir &xy);
std::ostream &operator<<(std::ostream &os, const gp_XY &xy);
std::ostream &operator<<(std::ostream &os, const gp_XYZ &xyz);
std::ostream &operator<<(std::ostream &os, const gp_Vec &vec);
