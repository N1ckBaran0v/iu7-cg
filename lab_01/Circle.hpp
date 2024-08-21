#ifndef __CIRCLE_HPP__
#define __CIRCLE_HPP__

#include "Dot.hpp"

enum DotPos{INSIDE, ON, OUTSIDE};

class Circle {
public:
    Circle(void);
    Circle(Dot, int);
    Circle(Dot&, Dot&, Dot&);
    DotPos calcPosition(Dot&);
    Dot getDot(void);
    double getRadius(void);
    static bool canInitCircle(Dot&, Dot&, Dot&);
private:
    Dot center;
    double radius;
};

#endif //__CIRCLE_HPP__