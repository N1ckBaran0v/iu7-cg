#include <cmath>
#include <iostream>
#include <algorithm>
#include <time.h>
#include "Line.hpp"

#define PI 3.1415927
#define EPS 5e-7
 
Line::Line(QColor &color, int way, Dot &start, Dot &end) : color(color), way(way),
                                                           start(start), end(end),
                                                           steps(1), dots(0),
                                                           lastTime(0) {}

Line::Line(QColor &color, int way, Dot &center, int lenght, int angle) : color(color), way(way), start(center),
                                                                         steps(1), dots(0), lastTime(0) {
    double rads = angle * PI / 180;
    int x0, y0;
    this->start.get(x0, y0);
    int x = x0 + int(round(lenght * cos(rads)));
    int y = y0 + int(round(lenght * sin(rads)));
    this->end.set(x, y);
}

void Line::draw(QPainter &pen, Dot &center) {
    //std::cout << this->way << '\n';
    clock_t start, end;
    if (this->way < 5) {
        if (this->way == 0) {
            this->drawDDA(center);
        }
        else if (this->way == 1) {
            this->drawBresenhamInt(center);
        }
        else if (this->way == 2) {
            this->drawBresenhamDouble(center);
        }
        else if (this->way == 3) {
            this->drawBresenhamGradation(center);
        }
        else {
            this->drawWu(center);
        }
        this->drawByDots(pen);
    }
    else {
        this->drawLibrary(pen, center);
    }
}

void Line::getSteps(int &s) {
    s = this->steps;
}

void Line::getWay(int &way) {
    way = this->way;
}

void Line::getPlace(int &x0, int &y0, int &x1, int &y1) {
    this->start.get(x0, y0);
    this->end.get(x1, y1);
}

void Line::getTime(int &time) {
    time = this->lastTime;
}

void Line::drawDDA(Dot &center) {
    //pen.setPen(QPen(this->color, 1));
    clock_t start, end;
    start = clock();
    this->dots.clear();
    this->steps = 1;
    int x0, y0, xl, yl;
    this->start.get(x0, y0);
    int x1, y1;
    this->end.get(x1, y1);
    int x, y;
    center.get(x, y);
    if (x0 == x1 && y0 == y1) {
        this->dots.push_back(Dot(x0 + x, y - y0));
        //pen.drawPoint(x0 + x, y - y0);
        return;
    }
    double dx = x1 - x0;
    double dy = y1 - y0;
    int l = fmax(fabs(dx), fabs(dy));
    dx /= l;
    dy /= l;
    double xi = x0 + x;
    double yi = y - y0;
    xl = x0 + x, yl = y - y0;
    for (size_t i = 0; i < l + 1; ++i) {
        this->dots.push_back(Dot((int)round(xi), (int)round(yi)));
        //pen.drawPoint((int)round(xi), (int)round(yi));
        if (fabs(xl - round(xi)) > EPS && fabs(yl - round(yi)) > EPS) {
            ++(this->steps);
            xl = int(round(xi));
            yl = int(round(yi));
        }
        xi += dx;
        yi -= dy;
    }
    end = clock();
    this->lastTime = 1000000 * (end - start) / CLOCKS_PER_SEC;
    //pen.drawLine(x0 + x, y0 + y, x1 + x, y1 + y);
}

void Line::drawBresenhamInt(Dot &center) {
    //pen.setPen(QPen(this->color, 1));
    clock_t start, end;
    start = clock();
    this->dots.clear();
    this->steps = 1;
    int x0, y0;
    this->start.get(x0, y0);
    int x1, y1;
    this->end.get(x1, y1);
    int x, y;
    center.get(x, y);
    int xi = x0 + x;
    int yi = y - y0;
    int dx = x1 - x0;
    int dy = y0 - y1;
    int sx = 0;
    if (dx != 0)
        sx = dx / abs(dx);
    int sy = 0;
    if (dy != 0)
        sy = dy / abs(dy);
    dx = abs(dx);
    dy = abs(dy);
    bool swapped = false;
    if (dy > dx) {
        swapped = true;
        std::swap(dx, dy);
    }
    int e = 2 * dy - dx;
    for (size_t i = 0; i < dx + 1; ++i) {
        this->dots.push_back(Dot(xi, yi));
        if (e >= 0) {
            if (!swapped)
                yi += sy;
            else
                xi += sx;
            if (i < dx)
                ++(this->steps);
            e -= 2 * dx;
        }
        if (swapped)
            yi += sy;
        else
            xi += sx;
        e += 2 * dy;
    }
    end = clock();
    this->lastTime = 1000000 * (end - start) / CLOCKS_PER_SEC;
}

void Line::drawBresenhamDouble(Dot &center) {
    //pen.setPen(QPen(this->color, 1));
    clock_t start, end;
    start = clock();
    this->dots.clear();
    this->steps = 1;
    int x0, y0;
    this->start.get(x0, y0);
    int x1, y1;
    this->end.get(x1, y1);
    int x, y;
    center.get(x, y);
    int xi = x0 + x;
    int yi = y - y0;
    int dx = x1 - x0;
    int dy = y0 - y1;
    int sx = 0;
    if (dx != 0)
        sx = dx / abs(dx);
    int sy = 0;
    if (dy != 0)
        sy = dy / abs(dy);
    dx = abs(dx);
    dy = abs(dy);
    bool swapped = false;
    if (dy > dx) {
        swapped = true;
        std::swap(dx, dy);
    }
    double m = double(dy) / dx;
    double e = m - 0.5;
    for (int i = 0; i < dx + 1; ++i) {
       this->dots.push_back(Dot(xi, yi));
        if (e >= 0) {
            if (!swapped)
                yi += sy;
            else
                xi += sx;
            if (i < dx)
                ++(this->steps);
            e -= 1;
        }
        if (swapped)
            yi += sy;
        else
            xi += sx;
        e += m;
    }
    end = clock();
    this->lastTime = 1000000 * (end - start) / CLOCKS_PER_SEC;
}

void Line::drawBresenhamGradation(Dot &center) {
    //pen.setPen(QPen(this->color, 1));
    clock_t start, end;
    start = clock();
    this->dots.clear();
    this->steps = 1;
    int x0, y0;
    this->start.get(x0, y0);
    int x1, y1;
    this->end.get(x1, y1);
    int x, y;
    center.get(x, y);
    if (x0 == x1 && y0 == y1) {
        this->dots.push_back(Dot(x0 + x, y - y0));
        return;
    }
    double I = 256;
    int xi = x0 + x;
    int yi = y - y0;
    int dx = x1 - x0;
    int dy = y0 - y1;
    int sx = 0;
    if (dx != 0)
        sx = dx / fabs((double)dx);
    int sy = 0;
    if (dy != 0)
        sy = dy / fabs((double)dy);
    dx = abs(dx);
    dy = abs(dy);
    double m = double(dy) / dx;
    bool swapped = false;
    if (m >= 1) {
        swapped = true;
        std::swap(dx, dy);
        m = 1 / m;
    }
    double f = I / 2;
    QColor tmpColor = this->color;
    m *= I;
    double w = I - m;
    //std::cout << m << ' ' << w << ' ' << f << '\n';
    //tmpColor.setAlpha(int(f));
    //pen.setPen(QPen(tmpColor, 1));
    this->dots.push_back(Dot(xi, yi, int(f)));
    for (int i = 0; i < dx + 1; ++i) {
        if (f < w) {
            if (swapped)
                yi += sy;
            else
                xi += sx;
            f += m;
        }
        else {
            yi += sy;
            xi += sx;
            if (i < dx)
                ++(this->steps);
            f -= w;
        }
        //tmpColor.setAlpha(int(f));
        //pen.setPen(QPen(tmpColor, 1));
        this->dots.push_back(Dot(xi, yi, int(f)));
    }
    end = clock();
    this->lastTime = 1000000 * (end - start) / CLOCKS_PER_SEC;
}

void Line::drawWu(Dot &center) {
    //pen.setPen(QPen(this->color, 1));
    clock_t start, end;
    start = clock();
    this->dots.clear();
    this->steps = 1;
    int x0, y0;
    this->start.get(x0, y0);
    int x1, y1;
    this->end.get(x1, y1);
    int x, y;
    center.get(x, y);
    int xi = x0 + x;
    int yi = y - y0;
    int dx = x1 - x0;
    int dy = y0 - y1;
    int sx = 0;
    if (dx != 0)
        sx = dx / abs(dx);
    int sy = 0;
    if (dy != 0)
        sy = dy / abs(dy);
    dx = abs(dx);
    dy = abs(dy);
    bool swapped = false;
    if (dy > dx) {
        swapped = true;
        std::swap(dx, dy);
    }
    double m = double(dy) / dx;
    m *= 255;
    double e = -255;
    //QColor tmpColor = this->color;
    for (int i = 0; i < dx + 1; ++i) {
        //tmpColor.setAlpha(int(-e));
        //pen.setPen(QPen(tmpColor, 1));
        this->dots.push_back(Dot(xi, yi, int(-e)));
        //tmpColor.setAlpha(int(255 + e));
        //pen.setPen(QPen(tmpColor, 1));
        this->dots.push_back(Dot(xi + sx * swapped, yi + sy * (!swapped), int(255 + e)));
        e += m;
        if (e >= 0) {
            if (!swapped)
                yi += sy;
            else
                xi += sx;
            if (i < dx)
                ++(this->steps);
            e -= 255;
        }
        if (swapped)
            yi += sy;
        else
            xi += sx;
    }
    end = clock();
    this->lastTime = 1000000 * (end - start) / CLOCKS_PER_SEC;
}

void Line::drawByDots(QPainter &pen) {
    QColor tmpColor = this->color;
    for (auto it = this->dots.begin(); it != this->dots.end(); ++it) {
        int x, y;
        it->get(x, y);
        int intensity = it->getIntencity();
        tmpColor.setAlpha(intensity);
        pen.setPen(QPen(tmpColor, 1));
        pen.drawPoint(x, y);
    }
}

void Line::drawLibrary(QPainter &pen, Dot &center) {
    pen.setPen(QPen(this->color, 1));
    int x0, y0;
    this->start.get(x0, y0);
    int x1, y1;
    this->end.get(x1, y1);
    int x, y;
    center.get(x, y);
    //std::cout << x0 + x << ' ' << y0 + y << ' ' << x1 + x << ' ' << y1 + y << '\n';
    pen.drawLine(x0 + x, y - y0, x1 + x, y - y1);
}