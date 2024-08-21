#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unistd.h>

#include "errors.h"
#include "mypixelmap.h"
#include "pixel.h"

static int min(int x, int y) {
    if (x > y)
        return y;
    return x;
}

static int max(int x, int y) {
    return x + y - min(x, y);
}

MyPixelMap::MyPixelMap(int x, int y, size_t x0, size_t y0) : x(x), y(y) {
    pixelMap.resize(x0);
    for (size_t i = 0; i < x0; ++i) {
        pixelMap[i].assign(y0, Pixel());
    }
}

void MyPixelMap::drawFigures(const std::vector<Figure> &figures, bool needFill, delayOut *dout) {
    size_t num = 0;
    for (size_t i = 0; i < figures.size(); ++i) {
        drawFigureLines(figures[i], num);
    }
    
    if (needFill) {
        for (size_t j = 0; j < pixelMap[0].size(); ++j) {
            if (dout) {
                (dout->curcnt)--;
                if (dout->curcnt <= 0) {
                    continue;
                }
            }
            bool flag = false;
            std::unordered_set<size_t> usedLines;
            for (size_t i = 0; i < pixelMap.size(); ++i) {
                pixelColor curr = pixelMap[i][j].getColor();
                if (curr == EDGE) {
                    flag = !(flag);
                }
                else if (curr == FONT && flag) {
                    pixelMap[i][j].fill();
                }
            }
        }
        if (dout) {
            (dout->maxcnt) -= int(pixelMap[0].size());
        }
    }
    
}

bool MyPixelMap::drawFigureLines(const Figure &figure, size_t &num) { 
    int xi, yi;
    for (size_t i = 0; i < figure.size(); ++i) {
        figure[i].get(xi, yi);
        xi -= x;
        yi -= y;
        if (xi < 0 || xi >= pixelMap.size() || yi < 0 || yi >= pixelMap[0].size()) {
            throw IndexOutOfRange("Dot out of pixel map\n");
        }
    }

    if (figure.size() == 0) {
        throw IncorrectValue("Empty figure\n");
    }

    bool ret = false;

    if (figure.size() > 1) {
        int x0, y0, x1, y1;
        for (size_t i = 0; !(ret) && i < figure.size(); ++i) {
            figure[i].get(x0, y0);
            if (i == 0) {
                y1 = y0;
            }
            else {
                ret = y1 != y0;
            }
        }
        if (!ret) {
            for (size_t i = 0; i < figure.size(); ++i) {
                this->drawLine(figure[i], figure[i + 1], false);
            }
        }
        else {
            int  x2, y2, it = 0, j;
            figure[it].get(x0, y0);
            figure[it + 1].get(x1, y1);
            for (; y0 == y1; ++it) {
                figure[it].get(x0, y0);
                figure[it + 1].get(x1, y1);
            }
            for (int i = it; i < figure.size() + it; ++i, ++num) {
                figure[i].get(x0, y0);
                figure[i + 1].get(x1, y1);
                figure[i + 2].get(x2, y2);
                j = i + 1;
                for (; y1 == y2; ++j) {
                    figure[j + 1].get(x2, y2);
                }
                drawLine(figure[i], figure[i + 1], 
                         (y0 > y1 && y1 < y2) || (y0 < y1 && y1 > y2));
                for (; i + 2 < j; ) {
                    ++i;
                    drawLine(figure[i], figure[i + 1], false);
                }
            }
        }
    }
    else {
        this->drawDot(figure[0]);
    }

    return ret;
}

void MyPixelMap::draw(QImage &image, int xi, int yi, const QColor &font, const QColor &line, const QColor &fill) const {
    pixelColor color;
    int i0 = max(0, -x);
    int j0 = max(0, -y);
    int in = min(pixelMap.size(), xi - x);
    int jn = min(pixelMap[0].size(), yi - y);

    for (int j = j0; j < jn; ++j) {
        for (int i = i0; i < in; ++i) {
            color = pixelMap[i][j].getColor();
            if (color == LINE || color == EDGE) {
                image.setPixelColor(x + i, y + j, line);
            }
            else if (color == FILL) {
                image.setPixelColor(x + i, y + j, fill);
            }
            else {
                image.setPixelColor(x + i, y + j, font);
            }
        }
    }
}

void MyPixelMap::drawDot(Dot &&dot) {
    int xd, yd;
    dot.get(xd, yd);
    xd -= x;
    yd -= y;
    pixelMap[xd][yd].fillLine(false);
}

void MyPixelMap::drawLine(Dot &&start, Dot &&end, bool drawLast) {
    int x0, y0;
    start.get(x0, y0);
    int x1, y1;
    end.get(x1, y1);
    int xi = x0 - x;
    int yi = y0 - y;

    int dx = x1 - x0;
    int dy = y1 - y0;
    int sx = 0;
    if (dx != 0) {
        sx = dx / abs(dx);
    }
    int sy = 0;
    if (dy != 0) {
        sy = dy / abs(dy);
    }

    dx = abs(dx);
    dy = abs(dy);
    bool swapped = false;
    if (dy > dx) {
        swapped = true;
        std::swap(dx, dy);
    }
    int e = 2 * dy - dx;
    y1 -= y;
    int ty = yi - 1;

    for (size_t i = 0; i < dx + 1; ++i) {
        pixelMap[xi][yi].fillLine((ty != yi) && (drawLast || yi != y1));
        ty = yi;
        if (e >= 0) {
            if (!swapped)
                yi += sy;
            else
                xi += sx;
            e -= 2 * dx;
        }
        if (swapped)
            yi += sy;
        else
            xi += sx;
        e += 2 * dy;
    }
}

