#include <cmath>

#include "Circle.hpp"

Circle::Circle(const Dot &center, const double radius) : center(center), radius(radius) {}

Circle::~Circle(void) {}

void Circle::rotate(const Dot &center, const double angle) {
    this->center.rotate(center, angle);
}

void Circle::scalingX(const Dot &center, const double scalingCoef) {
    this->center.scalingX(center, scalingCoef);
    this->radiusX *= scalingCoef;
}

void Circle::scalingY(const Dot &center, const double scalingCoef) {
    this->center.scalingY(center, scalingCoef);
    this->radiusY *= scalingCoef;
}

void Circle::draw(QPainter &p, const Dot &center, const paintParams &params) const {
    double x, y;
    this->center.get(x, y);
    int ix = params.centerX + round(x);
    int iy = params.centerY - round(y);
    p.drawEllipse(QPointF(ix, iy), this->radiusX, this->radiusY);
}
