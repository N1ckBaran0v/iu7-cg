#ifndef __SEGMENT_HPP__
#define __SEGMENT_HPP__

#include <QPainter>

#include "2DPrimitives.hpp"

struct paintParams {
    int centerX;
    int centerY;
};

class Segment {
public:
    Segment(const Dot &first, const Dot &second);
    ~Segment(void);
    void move(const Vector2D &offset);
    void rotate(const Dot &center, const double angle);
    void scalingX(const Dot &center, const double scalingCoef);
    void scalingY(const Dot &center, const double scalingCoef);
    void draw(QPainter &p, const paintParams &params) const;
private:
    Dot first, second;
};

#endif //__SEGMENT_HPP__
