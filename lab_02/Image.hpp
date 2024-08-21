#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__

#include <vector>
#include <functional>

#include "Segment.hpp"
#include "2DPrimitives.hpp"

class Image {
public:
    Image(const char *filename);
    ~Image(void);
    void move(const Vector2D &offset);
    void rotate(const Dot &center, const double angle);
    void scalingX(const Dot &center, const double scalingCoef);
    void scalingY(const Dot &center, const double scalingCoef);
    void draw(QPainter &p, paintParams &params) const;
private:
    std::vector<Segment*> details;
    //Dot center;
};

#endif // __IMAGE_HPP__
