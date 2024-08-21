#include <cmath>

#include "2DPrimitives.hpp"

#define PI 3.1415927
#define MAX_DEGREES 360

Dot::Dot(const Dot &source) {
    source.get(this->x, this->y);
}

Dot::Dot(const double x, const double y) : x(x), y(y) {}

void Dot::rotate(const Dot &center, const double angle) {
    Vector2D offset(center, *this);
    offset.rotate(angle);
    offset.getEndPos(center, *this);
}

void Dot::move(const Vector2D &offset) {
    double dx, dy;
    offset.get(dx, dy);
    this->x += dx;
    this->y += dy;
}

void Dot::scalingX(const Dot &center, const double scalingCoef) {
    Vector2D offset(center, *this);
    offset.scalingX(scalingCoef);
    offset.getEndPos(center, *this);
}

void Dot::scalingY(const Dot &center, const double scalingCoef) {
    Vector2D offset(center, *this);
    offset.scalingY(scalingCoef);
    offset.getEndPos(center, *this);
}

void Dot::set(double x, double y) {
    this->x = x;
    this->y = y;
}

void Dot::get(double &x, double &y) const {
    x = this->x;
    y = this->y;
}

Vector2D::Vector2D(const double x, const double y) : x(x), y(y) {}

Vector2D::Vector2D(const Dot &begin, const Dot &end) {
    double x0, y0, x1, y1;
    begin.get(x0, y0);
    end.get(x1, y1);
    this->x = x1 - x0;
    this->y = y1 - y0;
}

void Vector2D::scalingX(const double scalingCoef) {
    this->x *= scalingCoef;
}

void Vector2D::scalingY(const double scalingCoef) {
    this->y *= scalingCoef;
}

void Vector2D::rotate(const double angle) {
    double radians = angle * 2 * PI / MAX_DEGREES;
    double x0 = this->x;
    double y0 = this->y;
    this->x = x0 * cos(radians) - y0 * sin(radians);
    this->y = x0 * sin(radians) + y0 * cos(radians);
}

void Vector2D::getEndPos(const Dot &begin, Dot &end) const {
    double x0, y0;
    begin.get(x0, y0);
    end.set(x0 + this->x, y0 + this->y);
}

void Vector2D::get(double &x, double &y) const {
    x = this->x;
    y = this->y;
}
