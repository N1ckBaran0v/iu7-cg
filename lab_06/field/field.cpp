#include <ctime>
#include <iostream>

#include "field.h"
#include "mypixelmap.h"

static int min(int x, int y) {
    if (x > y)
        return y;
    return x;
}

static int max(int x, int y) {
    return x + y - min(x, y);
}

Field::Field(void) : figures() {}
void Field::addFigure(Dot &&dot) {
    figures.push_back(Figure(dot));
}

void Field::addDot(Dot &&dot, size_t fieldIndex) {
    if (fieldIndex >= figures.size()) {
        throw IndexOutOfRange("Invalid index to add dot.\n");
    }
    figures[fieldIndex].push(dot);
}

void Field::delDot(size_t dotIndex, size_t fieldIndex) {
    if (fieldIndex >= figures.size()) {
        throw IndexOutOfRange("Invalid field index to remove dot.\n");
    }
    if (dotIndex >= figures[fieldIndex].size()) {
        throw IndexOutOfRange("Invalid dot index to remove.\n");
    }

    figures[fieldIndex].pop(dotIndex);
    if (figures[fieldIndex].empty()) {
        for (size_t i = fieldIndex + 1; i < figures.size(); i++) {
            figures[i - 1] = figures[i];
        }
        figures.pop_back();
    }
}

double Field::draw(QImage &image, int x, int y, int xf, int yf, QColor &font, QColor &line, QColor &fill, bool needFill, int *dout) {
    clock_t start, end;
    start = clock();
    int x0 = 0, y0 = 0, x1 = x, y1 = y;
    findBorders(x0, y0, x1, y1);
    MyPixelMap pixelMap(x0, y0, x1 - x0, y1 - y0);
    pixelMap.drawFigures(figures);
    pixelMap.fill(xf, yf, needFill, dout);
    pixelMap.draw(image, x, y, font, line, fill);
    end = clock();
    return (double(end - start) / CLOCKS_PER_SEC) * 1000000;
}

Figure Field::operator[](size_t i) const {
    return (*this)[i];
}

Figure &Field::operator[](size_t i) {
    if (i >= figures.size()) {
        throw IndexOutOfRange("Invalid index of figure.\n");
    }
    return figures[i];
}

void Field::findBorders(int &minX, int &minY, int &maxX, int &maxY) const {
    int cx0, cy0, cx1, cy1;
    for (size_t i = 0; i < figures.size(); i++) {
        figures[i].getEdges(cx0, cy0, cx1, cy1);
        minX = min(cx0, minX);
        minY = min(cy0, minY);
        maxX = max(cx1 + 1, maxX);
        maxY = max(cy1 + 1, maxY);
    }
}