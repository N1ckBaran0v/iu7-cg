#ifndef __FIGURE_H__
#define __FIGURE_H__

#include <vector>
#include <cstddef>

#include "errors.h"
#include "dot.h"

class Figure {
public:
    Figure(void);
    Figure(const Dot &start);
    Figure(Dot &&start);

    void push(const Dot &dot);
    void pop(size_t index);
    void getEdges(int &minX, int &minY, int &maxX, int &maxY) const;
    Dot operator[](int i) const;
    Dot &operator[](int i);
    size_t size(void) const;
    bool empty(void) const;
private:
    std::vector<Dot> dots;
};

#endif //__FIGURE_H__