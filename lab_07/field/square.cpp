#include <iostream>
#include "square.h"

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

Square::Square(int x0, int y0, int x1, int y1) {
    this->set(x0, y0, x1, y1);
}
void Square::set(int x0, int y0, int x1, int y1) {
    _x0 = MIN(x0, x1);
    _y0 = MIN(y0, y1);
    _x1 = MAX(x0, x1);
    _y1 = MAX(y0, y1);
}

void Square::get(int &x0, int &y0, int &x1, int &y1) {
    x0 = _x0;
    y0 = _y0;
    x1 = _x1;
    y1 = _y1;
}

int Square::dotPos(const Dot &dot) {
    int res = 0;
    int x, y;
    dot.get(x, y);
    res |= (_x0 > x);
    res <<= 1;
    res |= (_x1 < x);
    res <<= 1;
    res |= (_y0 > y);
    res <<= 1;
    res |= (_y1 < y);
    return res;
}