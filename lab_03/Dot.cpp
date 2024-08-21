#include <cmath>

#include "Dot.hpp"

#ifndef EPS
#define EPS 5e-4
#endif

Dot::Dot(void) : x(0), y(0), intensity(255) {}

Dot::Dot(int x, int y, int intensity) : x(x), y(y), intensity(intensity){}

void Dot::set(int x, int y, int intensity) {
    this->x = x;
    this->y = y;
    this->intensity = intensity;
}

void Dot::get(int &x, int &y) {
    x = this->x;
    y = this->y;
}

int Dot::getIntencity(void) {
    return this->intensity;
}

bool Dot::equal(int x, int y) {
    return x == this->x && y == this->y;
}

bool Dot::equal(Dot &another) {
    return this->x == another.x && this->y == another.y;
}

/*Dot::Dot(void) : x(0), y(0), intensity(255) {}

Dot::Dot(int x, int y) : x(x), y(y) {}

void Dot::set(int x, int y) {
    this->x = x;
    this->y = y;
}

void Dot::get(int &x, int &y) {
    x = this->x;
    y = this->y;
}

bool Dot::equal(int x, int y) {
    return x == this->x && y == this->y;
}

bool Dot::equal(Dot &another) {
    return this->x == another.x && this->y == another.y;
}*/