#ifndef __LINE_HPP__
#define __LINE_HPP__

#include <QPainter>
#include <QColor>
#include <vector>
#include "Dot.hpp"

class Line {
public:
    Line(QColor&, int, Dot&, Dot&);
    Line(QColor&, int, Dot&, int, int);
    void draw(QPainter&, Dot&);
    void getSteps(int &s);
    void getWay(int &way);
    void getPlace(int &x0, int &y0, int &x1, int &y1);
    void getTime(int &time);
private:
    Dot start, end;
    std::vector <Dot> dots;
    QColor color;
    int way;
    int steps;
    int lastTime;
    void drawDDA(Dot&);
    void drawBresenhamInt(Dot&);
    void drawBresenhamDouble(Dot&);
    void drawBresenhamGradation(Dot&);
    void drawWu(Dot&);
    void drawByDots(QPainter&);
    void drawLibrary(QPainter&, Dot&);
};

#endif //__LINE_HPP__