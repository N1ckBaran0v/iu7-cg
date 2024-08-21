#include "pixel.h"

Pixel::Pixel(void) : _color(FONT) {}

void Pixel::fill(pixelColor color) {
    _color = color;
}

pixelColor Pixel::getColor(void) const {
    return _color;
}
