#include <cmath>

#include "Segment.hpp"

Segment::Segment(const Dot &first, const Dot &second) : first(first), second(second) {}

Segment::~Segment(void) {}

void Segment::move(const Vector2D &offset) {
    this->first.move(offset);
    this->second.move(offset);
}

void Segment::scalingX(const Dot &center, const double scalingCoef) {
    this->first.scalingX(center, scalingCoef);
    this->second.scalingX(center, scalingCoef);
}

void Segment::scalingY(const Dot &center, const double scalingCoef) {
    this->first.scalingY(center, scalingCoef);
    this->second.scalingY(center, scalingCoef);
}

void Segment::rotate(const Dot &center, const double angle) {
    this->first.rotate(center, angle);
    this->second.rotate(center, angle);
}

void Segment::draw(QPainter &p, const paintParams &params) const {
    double x1, y1;
    this->first.get(x1, y1);
    double x2, y2;
    this->second.get(x2, y2);
    int ix1 = params.centerX + (int)round(x1);
    int iy1 = params.centerY - (int)round(y1);
    int ix2 = params.centerX + (int)round(x2);
    int iy2 = params.centerY - (int)round(y2);
    p.drawLine(ix1, iy1, ix2, iy2);
}
