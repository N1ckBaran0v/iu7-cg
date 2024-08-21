#ifndef __MYPIXELMAP_H__
#define __MYPIXELMAP_H__

#include <vector>
#include <unordered_map>
#include <QImage>

#include "errors.h"
#include "figure.h"
#include "dot.h"
#include "pixel.h"
#include "figure.h"
#include "delayout.h"

class MyPixelMap {
public:
    MyPixelMap(void) = delete;
    MyPixelMap(int x, int y, size_t x0, size_t y0);

    void drawFigures(const std::vector<Figure> &figures);

    bool drawFigureLines(const Figure &figure, size_t &cnt);

    void fill(int x0, int y0, bool needFill = false, int *dout = nullptr);

    void draw(QImage &image, int xi, int yi, const QColor &font, const QColor &line, const QColor &fill) const;
private:
    std::vector<std::vector<Pixel>> pixelMap;
    int x, y;  

    void drawDot(Dot &&dot);
    void drawLine(Dot &&start, Dot &&end);
};

#endif //__MYPIXELMAP_H__