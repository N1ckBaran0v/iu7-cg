#include <cmath>
#include <endian.h>
#include <iostream>

#include "line.h"

#define EPS 5e-7

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

Dot getNormal(const Dot &first, const Dot &second, const Dot &third);

Line::Line() : _first(), _second() {}

Line::Line(Dot &&first, Dot &&second) : _first(first), _second(second) {}

void Line::set(const Dot &first, const Dot &second) {
    _first = first;
    _second = second;
}

void Line::get(Dot &first, Dot &second) {
    first = _first;
    second = _second;
}

void Line::draw(QPainter &pen, int canvasX, int canvasY, QColor &lineColor, QColor &cutColor, Cutter *cutter) {
    int x1, x2, y1, y2, dx, dy, xi, yi;
    _first.get(x1, y1);
    _second.get(x2, y2);
    double xr0 = x1, xr1 = x1, yr0 = y1, yr1 = y1;
    QColor color = lineColor;
    if (cutter) {
        visible(*cutter, xr0, yr0, xr1, yr1);
    }
    x1 += canvasX;
    x2 += canvasX;
    y1 += canvasY;
    y2 += canvasY;
    xr0 += canvasX;
    xr1 += canvasX;
    yr0 += canvasY;
    yr1 += canvasY;
    xi = x1;
    yi = y1;
    dx = x2 - x1;
    dy = y2 - y1;
    int sx = 0;
    if (dx != 0)
        sx = dx / abs(dx);
    int sy = 0;
    if (dy != 0)
        sy = dy / abs(dy);
    dx = abs(dx);
    dy = abs(dy);
    bool swapped = false, needRet = false;
    if (dy > dx) {
        swapped = true;
        std::swap(dx, dy);
    }
    int e = 2 * dy - dx;
    pen.setPen(QPen(color, 1));
    for (size_t i = 0; i < dx + 1; ++i) {
        if (swapped) {
            if (fabs(yi - yr0) <= 0.5) {
                yr0 = y1;
                if (color == lineColor) {
                    color = cutColor;
                    pen.setPen(QPen(color, 1));
                }
                else if (xi == x1) {
                    color = lineColor;
                    pen.setPen(QPen(color, 1));
                }
                else {
                    needRet = true;
                }
            }
            if (fabs(yi - yr1) <= 0.5) {
                yr1 = y1;
                if (color == lineColor) {
                    color = cutColor;
                    pen.setPen(QPen(color, 1));
                }
                else if (xi == x1) {
                    color = lineColor;
                    pen.setPen(QPen(color, 1));
                }
                else {
                    needRet = true;
                }
            }
        }
        else {
            if (fabs(xi - xr0) <= 0.5) {
                xr0 = x1;
                if (color == lineColor) {
                    color = cutColor;
                    pen.setPen(QPen(color, 1));
                }
                else if (xi == x1) {
                    color = lineColor;
                    pen.setPen(QPen(color, 1));
                }
                else {
                    needRet = true;
                }
            }
            if (fabs(xi - xr1) <= 0.5) {
                xr1 = x1;
                if (color == lineColor) {
                    color = cutColor;
                    pen.setPen(QPen(color, 1));
                }
                else if (xi == x1) {
                    color = lineColor;
                    pen.setPen(QPen(color, 1));
                }
                else {
                    needRet = true;
                }
            }
        }
        pen.drawPoint(xi, yi);
        if (needRet) {
            needRet = false;
            color = lineColor;
            pen.setPen(QPen(color, 1));
        }
        if (e >= 0) {
            if (!swapped)
                yi += sy;
            else
                xi += sx;
            e -= 2 * dx;
        }
        if (swapped)
            yi += sy;
        else
            xi += sx;
        e += 2 * dy;
    }
}

bool Line::visible(Cutter &cutter, double &rx0, double &ry0, double &rx1, double &ry1) {
    bool answer = true;
    int x1, x2, y1, y2, xd, yd, xf, yf, xw, yw, xn = 0, yn = 0, ds, ws;
    _first.get(x1, y1);
    _second.get(x2, y2);
    double tb = 0, te = 1, t;
    Dot tmp;
    xd = x2 - x1;
    yd = y2 - y1;
    for (size_t i = 0; i < cutter.size(); ++i) {
        cutter[i].get(xf, yf);
        xw = x1 - xf;
        yw = y1 - yf;
        tmp = getNormal(cutter[i], cutter[i + 1], cutter[i + 2]);
        tmp.get(xn, yn);
        ds = xd * xn + yd * yn;
        ws = xw * xn + yw * yn;
        if (ds == 0) {
            if (ws < 0) {
                answer = false;
                break;
            }
            else {
                continue;
            }
        }
        t = double(-1 * ws) / ds;
        if (ds > 0) {
            if (t > 1 + EPS) {
                answer = false;
                break;
            }
            else {
                tb = MAX(tb, t);
            }
        } else {
            if (t < -EPS) {
                answer = false;
                break;
            }
            else {
                te = MIN(te, t);
            }
        }
    }
    if (answer && tb <= te) {
        rx0 = x1 + xd * tb;
        ry0 = y1 + yd * tb;
        rx1 = x1 + xd * te;
        ry1 = y1 + yd * te;
    }
    return answer;
}

Dot getNormal(const Dot &first, const Dot &second, const Dot &third) {
    int x0, y0, x1, y1, x2, y2, dx, dy;
    first.get(x0, y0);
    second.get(x1, y1);
    third.get(x2, y2);
    if ((x2 - x1) * (y0 - y1) + (y2 - y1) * (x1 - x0) < 0) {
        return Dot(y1 - y0, x0 - x1);
    }
    return Dot(y0 - y1, x1 - x0);
}
