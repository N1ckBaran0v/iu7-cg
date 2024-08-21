#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "dot.h"

class Square {
public:
    Square(int x0 = 0, int y0 = 0, int x1 = 0, int y1 = 0);
    void set(int x0 = 0, int y0 = 0, int x1 = 0, int y1 = 0);
    void get(int &x0, int &y0, int &x1, int &y1);
    int dotPos(const Dot &dot);
private:
    int _x0, _y0, _x1, _y1;
};

#endif // __SQUARE_H__