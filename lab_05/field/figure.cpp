#include "figure.h"
#include "errors.h"

Figure::Figure(void) : dots() {}

Figure::Figure(const Dot &start) : dots(1, start) {}

Figure::Figure(Dot &&start) : dots(1, start) {}

void Figure::push(const Dot &dot) {
    dots.push_back(dot);
}
void Figure::pop(size_t index) {
    if (index >= dots.size()) {
        throw IndexOutOfRange("Trying to delete dot not in figure.\n");
    }
    for (size_t i = index + 1; i < dots.size(); ++i) {
        dots[i - 1] = dots[i];
    }
    dots.pop_back();
}

void Figure::getEdges(int &minX, int &minY, int &maxX, int &maxY) const {
    int x = 0, y = 0;
    for (size_t i = 0; i < dots.size(); ++i) {
        dots[i].get(x, y);
        if (i == 0) {
            minX = x;
            minY = y;
            maxX = x;
            maxY = y;
        }
        if (x < minX) {
            minX = x;
        }
        if (x > maxX) {
            maxX = x;
        }
        if (y < minY) {
            minY = y;
        }
        if (y > maxY) {
            maxY = y;
        }
    }
}

Dot Figure::operator[](int i) const {
    return dots[(i  + dots.size()) % dots.size()];
}

Dot &Figure::operator[](int i) {
    return dots[(i  + dots.size()) % dots.size()];
}

size_t Figure::size(void) const {
    return dots.size();
}

bool Figure::empty(void) const {
    return dots.empty();
}