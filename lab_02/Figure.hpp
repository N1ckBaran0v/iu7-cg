#ifndef __FIGURE_HPP__
#define __FIGURE_HPP__

#include <QPainter>

#include "2DPrimitives.hpp"


class Figure {
public:
    virtual void rotate(const Dot &center, const double angle) = 0;
    virtual void scalingX(const Dot &center, const double scalingCoef) = 0;
    virtual void scalingY(const Dot &center, const double scalingCoef) = 0;
    virtual void draw(QPainter &p, const Dot &center, const paintParams &params) const = 0;
    virtual ~Figure(void);
};

#endif // __FIGURE_HPP__
