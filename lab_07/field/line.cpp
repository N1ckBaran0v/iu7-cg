#include <cmath>
#include <iostream>

#include "line.h"

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

bool Line::visible(Square &cutter, Line &result) {
    int x1, x2, y1, y2, xl, yl, xh, yh, xt, yt;
    _first.get(x1, y1);
    _second.get(x2, y2);
    cutter.get(xl, yl, xh, yh);
    bool answer = false;
    Dot d1, d2, q = _first;
    double tan, x, y, xp, yp;
    int s1 = cutter.dotPos(_first);
    int s2 = cutter.dotPos(_second);
    if (s1 == 0 && s2 == 0) {
        answer = true;
        d1 = _first;
        d2 = _second;
    }
    else if ((s1 & s2) == 0){
        int i = 1;
        if (s1 == 0) {
            d1 = _first;
            q = _second;
            i = 2;
        }
        else if (s2 == 0) {
            d1 = _second;
            q = _first;
            i = 2;
        }
        for (; i < 3; ++i) {
            q.get(xt, yt);
            x = xt;
            y = yt;
            tan = 1e50;
            if (x2 != x1) {
                tan = double(y2 - y1) / (x2 - x1);
                if (x <= xl) {
                    yp = tan * (xl - x) + y;
                    if (yp >= yl && yp <= yh) {
                        if (i == 1) {
                            d1.set(xl, int(round(yp)));
                            q = _second;
                        }
                        else {
                            d2.set(xl, int(round(yp)));
                            answer = true;
                        }
                        continue;
                    }
                }
                if (x >= xh) {
                    yp = tan * (xh - x) + y;
                    if (yp >= yl && yp <= yh) {
                        if (i == 1) {
                            d1.set(xh, int(round(yp)));
                            q = _second;
                        }
                        else {
                            d2.set(xh, int(round(yp)));
                            answer = true;
                        }
                        continue;
                    }
                }
            }
            if (y2 == y1) {
                continue;
            }
            if (y <= yl) {
                xp = (yl - y) / tan + x;
                if (xp >= xl && xp <= xh) {
                    if (i == 1) {
                        d1.set(int(round(xp)), yl);
                        q = _second;
                    }
                    else {
                        d2.set(int(round(xp)), yl);
                        answer = true;
                    }
                    continue;
                }
            }
            if (y >= yh) {
                xp = (yh - y) / tan + x;
                if (xp >= xl && xp <= xh) {
                    if (i == 1) {
                        d1.set(int(round(xp)), yh);
                        q = _second;
                    }
                    else {
                        d2.set(int(round(xp)), yh);
                        answer = true;
                    }
                    continue;
                }
            }
            break;
        }
    }
    if (answer) {
        result.set(d1, d2);
    }
    return answer;
}