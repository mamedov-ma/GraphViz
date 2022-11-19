#include "geometry.hh"

namespace graph_viz
{
 
Vec Point::operator-(const Point &P) const 
{
    return Vec(this->x - P.x, this->y - P.y);
}

Point& Point::operator+=(const Vec &V) 
{
    this->x += V.x;
    this->y += V.y;
    return *this;
}

Point& Point::operator-=(const Vec &V) 
{
    this->x -= V.x;
    this->y -= V.y;
    return *this;
}

Vec Vec::operator+(const Vec &V) const 
{
    return Vec(this->x + V.x, this->y + V.y);
}

Vec Vec::operator-(const Vec &V) const 
{
    return Vec(this->x - V.x, this->y - V.y);
}

Vec Vec::operator*(const double &c) const 
{ 
    return Vec(this->x * c, this->y * c); 
}

Vec& Vec::operator+=(const Vec &V) 
{
    this->x += V.x;
    this->y += V.y;
    return *this;
}

Vec& Vec::operator-=(const Vec &V) 
{
    this->x -= V.x;
    this->y -= V.y;
    return *this;
}

Vec& Vec::operator*=(const double &c) 
{
    this->x *= c;
    this->y *= c;
    return *this;
}

double Vec::getNorm() const 
{ 
    return sqrt(x * x + y * y); 
}

}  // namespace graph_viz
