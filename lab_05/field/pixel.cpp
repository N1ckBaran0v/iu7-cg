#include "pixel.h"

Pixel::Pixel(void) : _color(FONT) {}

void Pixel::fill(void) {
    _color = FILL;
}

void Pixel::fillLine(bool invert) {
    if (_color != EDGE && _color != LINE) {
        _color = LINE;
    }
    if (invert) {
        if (_color == LINE) {
            _color = EDGE;
        }
        else {
            _color = LINE;
        }
    }
}

pixelColor Pixel::getColor(void) const {
    return _color;
}
