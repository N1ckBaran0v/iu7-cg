#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unistd.h>
#include <stack>
#include <utility>

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

void MyPixelMap::drawFigures(const std::vector<Figure> &figures) {
    size_t num = 0;
    for (size_t i = 0; i < figures.size(); ++i) {
        drawFigureLines(figures[i], num);
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
        for (size_t i = 0; i < figure.size(); ++i) {
            this->drawLine(figure[i], figure[i + 1]);
        }
    }
    else {
        this->drawDot(figure[0]);
    }

    return ret;
}

void MyPixelMap::fill(int x0, int y0, bool needFill, int *dout) {
    //std::cout << x0 << ' ' << x << ' ' << y0 << ' ' << y << '\n';
    x0 -= x;
    y0 -= y;
    //std::cout << x0 << ' ' << y0 << '\n';
    if (x0 < 0 || y0 < 0 || x0 >= pixelMap.size() || y0 >= pixelMap[0].size()) {
        return;
    }

    std::stack<std::pair<int, int>> dots;
    pixelMap[x0][y0].fill(FILL);
    if (needFill) {
        dots.push(std::make_pair(x0, y0));
    }

    int xt, yt, x1, y1, xmin, xmax;
    std::pair<int, int> tmp;

    for (int i = 0; !(dots.empty()); ++i) {
        tmp = dots.top();
        dots.pop();
        xmin = xmax = xt = tmp.first;
        yt = tmp.second;
        pixelMap[xt][yt].fill(FILL);
        //std::cout <<xt << ' ' << yt << '\n';

        for (; xmin > 0 && pixelMap[xmin - 1][yt].getColor() == FONT; --xmin) {
            pixelMap[xmin - 1][yt].fill(FILL);
        }

        //std::cout << "OK1\n";

        for (; xmax + 1 < pixelMap.size() && pixelMap[xmax + 1][yt].getColor() == FONT; ++xmax) {
            pixelMap[xmax + 1][yt].fill(FILL);
        }

        //std::cout << "OK2\n";

        if (yt - 1 >= 0) {
            for (xt = xmin, x1 = xmin - 2, y1 = yt - 1; xt <= xmax; ++xt) {
                if (pixelMap[xt][y1].getColor() == FONT) {
                    if (x1 < xt - 1) {
                        dots.push(std::make_pair(xt, y1));
                    } 
                    x1 = xt;
                }
            }
        } 

        //std::cout << "OK3\n";

        if (yt + 1 < pixelMap[0].size()) {
            //std::cout << "OK3.5\n";
            for (xt = xmin, x1 = xmin - 2, y1 = yt + 1; xt <= xmax; ++xt) {
                if (pixelMap[xt][y1].getColor() == FONT) {
                    if (x1 < xt - 1) {
                        dots.push(std::make_pair(xt, y1));
                    } 
                    x1 = xt;
                }
            }
        } 

        //std::cout << "OK4\n";

        if (xmin == xmax) {
            --i;
            continue;
        }

        if (dout != nullptr) {
            if (i == *dout) {
                return;
            }
        }
    }

    if (dout != nullptr) {
        *dout = -1;
    }
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
            if (color == LINE) {
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
    pixelMap[xd][yd].fill(LINE);
}

void MyPixelMap::drawLine(Dot &&start, Dot &&end) {
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

    for (size_t i = 0; i < dx + 1; ++i) {
        pixelMap[xi][yi].fill(LINE);
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

