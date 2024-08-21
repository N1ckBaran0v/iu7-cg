#ifndef __ARC_HPP__
#define __ARC_HPP__

#include "Figure.hpp"
#include "2DPrimitives.hpp"

class Arc : public Figure {
public:
    Arc(const Dot &center, const double radius, 
        const double beginDegrees = 0, const double endDegrees = 180);
    ~Arc(void);
    void rotate(const Dot &center, const double angle);
    void draw(QPainter &p, const Dot &center, const paintParams &params) const;
private:
    Dot center;
    double radius;
    double beginDegrees, endDegrees;
};

#endif // __ARC_HPP__
