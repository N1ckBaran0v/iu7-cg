#include <cmath>

#include "dot.h"

Dot::Dot(void) : x(0), y(0) {}

Dot::Dot(const int x, const int y) : x(x), y(y) {}

void Dot::set(int x, int y) {
    this->x = x;
    this->y = y;
}

void Dot::get(int &x, int &y) const {
    x = this->x;
    y = this->y;
}

bool Dot::equal(int x, int y) const {
    return x == this->x && y == this->y;
}

bool Dot::equal(Dot &another) const {
    return this->x == another.x && this->y == another.y;
}
