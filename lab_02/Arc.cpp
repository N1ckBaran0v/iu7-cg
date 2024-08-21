#include <cmath>

#include "Arc.hpp"

Arc::Arc(const Dot &center, const double radius, 
         const double beginDegrees, const double endDegrees) : center(center), radius(radius),
                                                               beginDegrees(beginDegrees),
                                                               endDegrees(endDegrees) {}
                                                            
Arc::~Arc(void) {}

void Arc::rotate(const Dot &center, const double angle) {
    this->center.rotate(center, angle);
    this->beginDegrees += angle;
    this->endDegrees += angle;
}

void Arc::draw(QPainter &p, const Dot &center, const paintParams &params) const {
    Dot copyCircleCenter(this->center);
    copyCircleCenter.scaling(center, params.imageScale);
    double x, y;
    copyCircleCenter.get(x, y);
    int radius = round(this->radius * params.imageScale);
    int ix = params.centerX + round(x) - radius;
    int iy = params.centerY - round(y) - radius;
    radius *= 2;
    int startAngle = round(this->beginDegrees * 16);
    int spanAngle = round((this->endDegrees - this->beginDegrees) * 16);
    p.drawArc(ix, iy, radius, radius, startAngle, spanAngle);
}
