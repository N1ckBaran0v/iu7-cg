#ifndef __PIXEL_H__
#define __PIXEL_H__

#include <cstddef>
#include <vector>

enum pixelColor{FONT, LINE, FILL};

class Pixel {
public:
    Pixel(void);
    void fill(pixelColor color = FILL);
    pixelColor getColor(void) const;
private:
    pixelColor _color;
};

#endif //__PIXEL_H__