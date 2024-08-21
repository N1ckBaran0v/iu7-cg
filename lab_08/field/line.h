#ifndef __LINE_H__
#define __LINE_H__

#include <QPainter>
#include <QColor>

#include "cutter.h"

class Line {
public:
    Line();
    Line(Dot &&first, Dot &&second);
    void set(const Dot &first, const Dot &second);
    void get(Dot &first, Dot &second);
    void draw(QPainter &pen, int canvasX, int canvasY, QColor &lineColor, QColor &cutColor, Cutter *cutter = nullptr);
private:
    Dot _first, _second;
    bool visible(Cutter &cutter, double &rx0, double &ry0, double &rx1, double &ry1);
};

#endif // __LINE_H__