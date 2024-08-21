#ifndef __CIRCLE_HPP__
#define __CIRCLE_HPP__

#include "Figure.hpp"
#include "2DPrimitives.hpp"

class Circle : public Figure {
public:
    Circle(const Dot &center, const double radius);
    ~Circle(void);
    void rotate(const Dot &center, const double angle);
    void scalingX(const Dot &center, const double scalingCoef);
    void scalingY(const Dot &center, const double scalingCoef);
    void draw(QPainter &p, const Dot &center, const paintParams &params) const;
private:
    Dot center;
    double radiusX;
    double radiusY;
};

#endif // __CIRCLE_HPP__
