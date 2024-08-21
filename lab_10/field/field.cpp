#include <cmath>
#include <iostream>

#include "field.h"

#define EPS 5e-7

int min(int x, int y) {
    if (x > y) {
        return y;
    }
    return x;
}

int max(int x, int y) {
    if (x < y) {
        return y;
    }
    return x;
}

void Field::floatingHorizon(QPainter &pen, const ScreenParams &screen) const {
    double tx, ty, tz;
    double xp, yp, x0 = -1, y0 = -1;
    std::vector<double> bottom(screen.dx, screen.dy), top(screen.dx, -screen.dy);
    for (double z = zh; zl - z < EPS; z -= dz) {
        tx = xl;
        ty = func(xl, z);
        tz = z;
        transform(tx, ty, tz, screen);
        xp = tx;
        yp = ty;
        if (x0 != -1) {
            drawLine(xp, yp, x0, y0, top, bottom, pen, screen);
        }
        x0 = xp;;
        y0 = yp;
        for (double x = xl; x - xh < EPS; x += dx) {
            tx = x;
            ty = func(x, z);
            tz = z;
            transform(tx, ty, tz, screen);
            drawLine(xp, yp, tx, ty, top, bottom, pen, screen);
            xp = tx;
            yp = ty;
        }
        if (z - zl > EPS) {
            tx = xh;
            ty = func(xh, z - dz);
            tz = z - dz;
            transform(tx, ty, tz, screen);
            drawLine(xp, yp, tx, ty, top, bottom, pen, screen);
        }
    }
}

int Field::setX(const double xl, const double xh, const double dx) {
    if (dx < EPS) {
        return -1;
    }
    if (xh - xl < EPS) {
        return -2;
    }
    this->xl = xl;
    this->xh = xh;
    this->dx = dx;
    return 0;
}

int Field::setZ(const double zl, const double zh, const double dz) {
    if (dz < EPS) {
        return -1;
    }
    if (zh - zl < EPS) {
        return -2;
    }
    this->zl = zl;
    this->zh = zh;
    this->dz = dz;
    return 0;
}

void Field::setAngles(const double ax, const double ay, const double az) {
    this->ax = ax;
    this->ay = ay;
    this->az = az;
}

void Field::setScale(const double scaleX, const double scaleY) {
    scx = scaleX;
    scy = scaleY;
}

void Field::setFunc(Func3D func) {
    this->func = func;
}

static double radians(const double angle) {
    return angle * M_PI / 180;
}

void Field::transform(double &x, double &y, double &z, const ScreenParams &screen) const {
    double angle_rads = radians(ax);
    double sin_ang = sin(angle_rads);
    double cos_ang = cos(angle_rads);
    double x0 = x;
    double y0 = y * cos_ang - z * sin_ang;
    double z0 = y * sin_ang + z * cos_ang;

    angle_rads = radians(ay);
    sin_ang = sin(angle_rads);
    cos_ang = cos(angle_rads);
    double x1 = x0 * cos_ang + z0 * sin_ang;
    double y1 = y0;
    double z1 = z0 * cos_ang - z0 * sin_ang;

    angle_rads = radians(az);
    sin_ang = sin(angle_rads);
    cos_ang = cos(angle_rads);
    x = x1 * cos_ang - y1 * sin_ang;
    y = x1 * sin_ang + y1 * cos_ang;
    z = z1;

    x *= scx;
    y *= scy;
}

void Field::drawLine(double x0, double y0, double x1, double y1, std::vector<double> &top, std::vector<double> &bottom, 
                     QPainter &pen, const ScreenParams &screen) const {
    int x = int(round(x0));
    int y = int(round(y0));
    int dx = int(round(x1 - x0));
    int dy = int(round(y1 - y0));
    int sx = dx > 0 ? 1 : dx < 0 ? -1 : 0;
    int sy = dy > 0 ? 1 : dx < 0 ? -1 : 0;
    dx = abs(dx);
    dy = abs(dy);
    x += screen.cx;
    if (dx == 0 && dy == 0 && x >= 0 && x < screen.dx) {
        top[x] = max(top[x], y);
        bottom[x] = min(bottom[x], y);
        pen.drawPoint(x + 220, screen.cy - y);
        return;
    }
    if (x < 0 || x >= screen.dx) {
        return;
    }
    bool change = false;
    if (dy > dx) {
        std::swap(dx, dy);
        change = true;
    }

    int yMaxCur = top[x];
    int yMinCur = bottom[x];
    int e = 2 * dy - dx;

    for (int i = 1; i <= dx; ++i) {
        if (x >= 0 && x < screen.dx) {
            if (y >= top[x]) {
                if (y >= yMaxCur) {
                    yMaxCur = y;
                }
                pen.drawPoint(x + 220, screen.cy - y);
            }

            if (y <= bottom[x]) {
                if (y <= yMinCur) {
                    yMinCur = y;
                }
                pen.drawPoint(x + 220, screen.cy - y);
            }
        }

        if (x < 0 || x >= screen.dx) return;

        if (e > 0) {
            if (change) {
                if (x < 0 || x >= screen.dx) return;
                top[x] = yMaxCur;
                bottom[x] = yMinCur;

                x += sx;

                if (x < 0 || x >= screen.dx) return;
                yMaxCur = int(top[x]);
                yMinCur = int(bottom[x]);
            } else {
                y += sy;
            }

            e -= 2 * dx;
        }

        if (!change) {
            if (x < 0 || x >= screen.dx) return;
            top[x] = yMaxCur;
            bottom[x] = yMinCur;

            x += sx;

            if (x < 0 || x >= screen.dx) return;
            yMaxCur = int(top[x]);
            yMinCur = int(bottom[x]);
        } else {
            y += sy;
        }

        e += 2 * dy;
    }
}

bool Field::visible(double x, double y, std::vector<int> &top, std::vector<int> &bottom) const {
    if (x < 0 || x >= top.size() - 0.499999) {
        return false;
    }
    if (y > top[int(round(x))] || y < bottom[int(round(x))]) {
        return false;
    }
    return true;
}
