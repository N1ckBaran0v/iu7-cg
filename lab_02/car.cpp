#include "car.hpp"

std::vector<Figure*> getCarDetails(void) {
    std::vector<Figure*> details;
    Dot first(0, 0), second(0, 0);
    Dot figureCenter(0, 0);

    figureCenter.set(-12, -6);
    details.push_back(new Circle(figureCenter, 6));
    details.push_back(new Circle(figureCenter, 3));
    details.push_back(new Arc(figureCenter, 7));

    figureCenter.set(10, -6);
    details.push_back(new Circle(figureCenter, 6));
    details.push_back(new Circle(figureCenter, 3));
    details.push_back(new Arc(figureCenter, 7));

    first.set(-5, -6);
    second.set(3, -6);
    details.push_back(new Segment(first, second));
    first.set(17, -6);
    second.set(20, -6);
    details.push_back(new Segment(first, second));
    first.set(20, 4);
    details.push_back(new Segment(first, second));
    second.set(16, 12);
    details.push_back(new Segment(first, second));
    first.set(-6, 12);
    details.push_back(new Segment(first, second));
    second.set(-12, 6);
    details.push_back(new Segment(first, second));
    first.set(-20, 6);
    details.push_back(new Segment(first, second));
    figureCenter.set(-20, 4);
    details.push_back(new Arc(figureCenter, 2, 90, 180));
    first.set(-22, 4);
    second.set(-22, 2.5);
    details.push_back(new Segment(first, second));
    first.set(-21.5, 2);
    details.push_back(new Segment(first, second));
    second.set(-21.5, -1.5);
    details.push_back(new Segment(first, second));
    first.set(-22, -2);
    details.push_back(new Segment(first, second));
    second.set(-22, -6);
    details.push_back(new Segment(first, second));
    first.set(-19, -6);
    details.push_back(new Segment(first, second));

    first.set(2, 6);
    second.set(-11, 6);
    details.push_back(new Segment(first, second));
    first.set(-6, 11);
    details.push_back(new Segment(first, second));
    second.set(2, 11);
    details.push_back(new Segment(first, second));
    first.set(2, 6);
    details.push_back(new Segment(first, second));

    first.set(3, 6);
    second.set(11, 6);
    details.push_back(new Segment(first, second));
    first.set(9, 11);
    details.push_back(new Segment(first, second));
    second.set(3, 11);
    details.push_back(new Segment(first, second));
    first.set(3, 6);
    details.push_back(new Segment(first, second));

    first.set(-4, -5);
    second.set(2, -5);
    details.push_back(new Segment(first, second));
    first.set(2, 5);
    details.push_back(new Segment(first, second));
    second.set(-11, 5);
    details.push_back(new Segment(first, second));
    first.set(-11, 2);
    details.push_back(new Segment(first, second));
    figureCenter.set(-12, -6);
    details.push_back(new Arc(figureCenter, 8.0622577, 7.2, 82.8));

    first.set(1, 4);
    second.set(-1, 4);
    details.push_back(new Segment(first, second));
    first.set(-1, 3.5);
    details.push_back(new Segment(first, second));
    second.set(1, 3.5);
    details.push_back(new Segment(first, second));
    first.set(1, 4);
    details.push_back(new Segment(first, second));

    first.set(20, -4);
    second.set(22, -4);
    details.push_back(new Segment(first, second));
    figureCenter.set(22, -2);
    details.push_back(new Arc(figureCenter, 2, -90, 0));
    first.set(24, -2);
    second.set(24, 6);
    details.push_back(new Segment(first, second));
    figureCenter.set(22, 6);
    details.push_back(new Arc(figureCenter, 2, 0, 90));
    first.set(22, 8);
    second.set(20, 8);
    details.push_back(new Segment(first, second));
    figureCenter.set(20, 6);
    details.push_back(new Arc(figureCenter, 2, 90, 142));

    first.set(-24, -12);
    second.set(24, -12);
    details.push_back(new Segment(first, second));
    
    return details;
}