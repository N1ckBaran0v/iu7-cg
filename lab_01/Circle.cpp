#include <cmath>

#include "Circle.hpp"

#ifndef EPS
#define EPS 5e-4
#endif

Circle::Circle(void) : center(), radius(0) {}

Circle::Circle(Dot center, int radius) : center(center), radius(radius) {}

Circle::Circle(Dot &first, Dot &second, Dot &third) {
    if (!(Circle::canInitCircle(first, second, third))) 
        throw "Cannot init circle with this dots";
    double x1, y1;
    first.get(x1, y1);
    double x2, y2;
    second.get(x2, y2);
    double x3, y3;
    third.get(x3, y3);
    double xs31 = pow(x3, 2) - pow(x1, 2);
    double ys31 = pow(y3, 2) - pow(y1, 2);
    double xs32 = pow(x3, 2) - pow(x2, 2);
    double ys32 = pow(y3, 2) - pow(y2, 2);
    double x31 = x3 - x1;
    double x32 = x3 - x2;
    double y31 = y3 - y1;
    double y32 = y3 - y2;
    double x0 = ((xs32 + ys32) * y31 - (xs31 + ys31) * y32) / (2 * (x32 * y31 - x31 * y32));
    double y0 = (xs32 + ys32 - 2 * x0 * x32) / (2 * y32);
    this->radius = sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2));
    this->center = Dot(x0, y0);
}

DotPos Circle::calcPosition(Dot &dot) {
    double x, y;
    dot.get(x, y);
    double xc, yc;
    this->center.get(xc, yc);
    double diff = sqrt((xc - x) * (xc - x) + (yc - y) * (yc - y)) - this->radius;
    DotPos pos;
    if (fabs(diff) < EPS)
        pos = ON;
    else if (diff > 0)
        pos = OUTSIDE;
    else
        pos = INSIDE;
    return pos;
}

Dot Circle::getDot(void) {
    return this->center;
}

double Circle::getRadius(void) {
    return this->radius;
}

bool Circle::canInitCircle(Dot &first, Dot &second, Dot &third) {
    double x1, y1;
    first.get(x1, y1);
    double x2, y2;
    second.get(x2, y2);
    double x3, y3;
    third.get(x3, y3);
    bool ret = true;
    if ((fabs(x1 - x2) < EPS && fabs(y1 - y2) < EPS) || 
        (fabs(x3 - x2) < EPS && fabs(y3 - y2) < EPS) || 
        (fabs(x1 - x3) < EPS && fabs(y1 - y3) < EPS))
        ret = false;
    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    if (fabs(a - b - c) < EPS || fabs(b - a - c) < EPS || fabs(c - a - b) < EPS)
        ret = false;
    return ret;
}