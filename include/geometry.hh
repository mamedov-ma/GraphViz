#ifndef _INCLUDE_GEOMETRY_HH_
#define _INCLUDE_GEOMETRY_HH_

#include <cmath>

namespace graph_viz
{

struct Vec 
{
    Vec() : x(0), y(0) {}
    Vec(const double x, const double y) : x(x), y(y) {}
    Vec(const Vec &V) : x(V.x), y(V.y) {}
    
    Vec operator+(const Vec &V) const;
    Vec operator-(const Vec &V) const;
    Vec operator*(const double &c) const;
    Vec &operator+=(const Vec &V);
    Vec &operator-=(const Vec &V);
    Vec &operator*=(const double &c);
    double getNorm() const;

    double x, y;
};

struct Point 
{
    Point() : x(0), y(0) {}
    Point(const double x, const double y) : x(x), y(y) {}
    
    Vec operator-(const Point &P) const ;
    Point &operator+=(const Vec &V) ;
    Point &operator-=(const Vec &V); 
    
    double x, y;
};

} // namespace graph_viz

#endif 
