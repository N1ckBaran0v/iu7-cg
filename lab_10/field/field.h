#ifndef __FIELD_H__
#define __FIELD_H__

#include <QPainter>
#include <vector>

#include "functions.h"

struct ScreenParams {
    int dx, dy, cx, cy;
};

class Field {
public:
    Field(void) = default; 
    ~Field(void) = default; 
    void floatingHorizon(QPainter &pen, const ScreenParams &screen) const;
    int setX(const double xl, const double xh, const double dx);
    int setZ(const double zl, const double zh, const double dz);
    void setAngles(const double ax, const double ay, const double az);
    void setScale(const double scaleX, const double scaleY);
    void setFunc(Func3D func);
private:
    double xl, xh, dx;
    double zl, zh, dz;
    double ax, ay, az, scx, scy;
    Func3D func = nullptr;
    void transform(double &x, double &y, double &z, const ScreenParams &screen) const;
    void drawLine(double x0, double y0, double x1, double y1, std::vector<double> &top, std::vector<double> &bottom, QPainter &pen, const ScreenParams &screen) const;
    bool visible(double x, double y, std::vector<int> &top, std::vector<int> &bottom) const;
};

#endif // __FIELD_H__