#ifndef __PIXEL_H__
#define __PIXEL_H__

#include <cstddef>
#include <vector>

enum pixelColor{FONT, LINE, EDGE, FILL};

class Pixel {
public:
    Pixel(void);
    void fill(void);
    void fillLine(bool invert = true);
    pixelColor getColor(void) const;
private:
    pixelColor _color;
};

#endif //__PIXEL_H__