#include <cmath>

#include "Dot.hpp"

#ifndef EPS
#define EPS 5e-4
#endif

Dot::Dot(void) : x(0), y(0) {}

Dot::Dot(double x, double y) : x(x), y(y) {}

void Dot::get(double &x, double &y) {
    x = this->x;
    y = this->y;
}

bool Dot::equal(double x, double y) {
    return fabs(this->x - x) < EPS && fabs(this->y - y) < EPS;
}

bool Dot::equal(Dot &another) {
    return fabs(this->x - another.x) < EPS && fabs(this->y - another.y) < EPS;
}