#include <cstddef>
#include <fstream>

#include "Image.hpp"

Image::Image(const char *filename) : details() { //, center(0, 0) {
    std::ifstream input(filename);
    double x1, y1, x2, y2;
    while (input >> x1 >> y1 >> x2 >> y2) {
        Dot first(x1, y1);
        Dot second(x2, y2);
        this->details.push_back(new Segment(first, second));
    }
    input.close();
}

Image::~Image(void) {
    for (size_t i = 0; i < this->details.size(); ++i)
        delete this->details[i];
}

void Image::move(const Vector2D &offset) {
    //this->center.move(offset);
    for (size_t i = 0; i < details.size(); ++i)
        this->details[i]->move(offset);
}

void Image::rotate(const Dot &center, const double angle) {
    for (size_t i = 0; i < details.size(); ++i)
        this->details[i]->rotate(center, angle);
}

void Image::scalingX(const Dot &center, const double scalingCoef) {
    for (size_t i = 0; i < details.size(); ++i)
        this->details[i]->scalingX(center, scalingCoef);
}

void Image::scalingY(const Dot &center, const double scalingCoef) {
    for (size_t i = 0; i < details.size(); ++i)
        this->details[i]->scalingY(center, scalingCoef);
}

void Image::draw(QPainter &p, paintParams &params) const {
    for (size_t i = 0; i < details.size(); ++i)
        this->details[i]->draw(p, params);
}
