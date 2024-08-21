#include <stdexcept>
#include <cmath>

#include "figure.h"

#define EPS 5e-7

typedef std::pair<double, double> fdot_t;

static bool crossing(const dot_t &d1, const dot_t &d2, const fdot_t &f1, const fdot_t &f2) {
    bool cross = false;
    double v1 = (d1.first - f1.first) * (d2.second - f1.second) - (d2.first - f1.first) * (d1.second - f1.second);
    double v2 = (d1.first - f2.first) * (d2.second - f2.second) - (d2.first - f2.first) * (d1.second - f2.second);
    return (v1 > EPS && v2 < -EPS) || (v1 < -EPS && v2 > EPS);
}

static bool crossing(const dot_t &d1, const dot_t &d2, const dot_t &f1, const dot_t &f2) {
    bool cross = false;
    int v1 = (d1.first - f1.first) * (d2.second - f1.second) - (d2.first - f1.first) * (d1.second - f1.second);
    int v2 = (d1.first - f2.first) * (d2.second - f2.second) - (d2.first - f2.first) * (d1.second - f2.second);
    return (v1 > 0 && v2 < 0) || (v1 < 0 && v2 > 0);
}

static fdot_t crossingPoint(const dot_t &d1, const dot_t &d2, const fdot_t &f1, const fdot_t &f2) {
    fdot_t result;
    double a1 = double(d2.second - d1.second);
    double b1 = double(d1.first - d2.first);
    double c1 = -a1 * d1.first - b1 * d1.second;
    double a2 = f2.second - f1.second;
    double b2 = f1.first - f2.first;
    double c2 = -a2 * f1.first - b2 * f1.second;
    double det = a1 * b2 - a2 * b1;
    result.first = (b1 * c2 - b2 * c1) / det;
    result.second = (a2 * c1 - a1 * c2) / det;
    return result;
}

static dot_t getNormal(const dot_t &first, const dot_t &second, const dot_t &third) {
    int x0 = first.first;
    int y0 = first.second;
    int x1 = second.first;
    int y1 = second.second;
    int x2 = third.first;
    int y2 = third.second;
    if ((x2 - x1) * (y0 - y1) + (y2 - y1) * (x1 - x0) < 0) {
        return std::make_pair(y1 - y0, x0 - x1);
    }
    return std::make_pair(y0 - y1, x1 - x0);
}

void Figure::add(const dot_t &dot) {
    _dots.push_back(dot);
}

void Figure::add(dot_t &&dot) {
    _dots.push_back(dot);
}

void Figure::remove(const size_t index) {
    if (index >= _dots.size()) {
        throw std::runtime_error("Incorrect index");
    }

    for (size_t i = index + 1; i < _dots.size(); ++i) {
        _dots[i - 1] = _dots[i]; 
    }
    _dots.pop_back();
}

size_t Figure::size(void) const noexcept {
    return _dots.size();
}

size_t Figure::empty(void) const noexcept {
    return _dots.empty();
}

dot_t &Figure::operator[](const size_t i) noexcept { 
    return _dots[i % _dots.size()]; 
}

const dot_t &Figure::operator[](const size_t i) const noexcept {
    return _dots[i % _dots.size()];
}

Figure Figure::cut(const Figure &cutter) const {
    Figure ret;
    std::vector<fdot_t> p, q;
    for (auto dot : _dots) {
        p.push_back(std::make_pair<double, double>(double(dot.first), double(dot.second)));
    }
    fdot_t f, s;
    dot_t n;
    double xd, yd, xw, yw, sd, sw, t;
    for (size_t i = 0; i < cutter.size(); ++i) {
        f = p[0];
        n = getNormal(cutter[i], cutter[i + 1], cutter[i + 2]);
        for (size_t j = 0; j < p.size(); ++j) {
            xw = p[j].first - cutter[i].first;
            yw = p[j].second - cutter[i].second;
            sw = xw * n.first + yw * n.second;
            if (j) {
                if (crossing(cutter[i], cutter[i + 1], s, p[j])) {
                    //xd = p[j].first - s.first;
                    //yd = p[j].second - s.second;
                    //sd = xd * n.first + yd * n.second;
                    //t = -sw / sd;
                    //q.push_back(std::make_pair(s.first + xd * t, s.second + yd * t));
                    q.push_back(crossingPoint(cutter[i], cutter[i + 1], s, p[j]));
                }
            }
            s = p[j];
            if (sw > 0) {
                q.push_back(s);
            }
        }
        if (q.empty()) {
            break;
        }
        if (crossing(cutter[i], cutter[i + 1], s, f)) {
            //xw = f.first - cutter[i].first;
            //yw = f.second - cutter[i].second;
            //sw = xw * n.first + yw * n.second;
            //xd = f.first - s.first;
            //yd = f.second - s.second;
            //sd = xd * n.first + yd * n.second;
            //t = -sw / sd;
            //q.push_back(std::make_pair(s.first + xd * t, s.second + yd * t));
            q.push_back(crossingPoint(cutter[i], cutter[i + 1], s, f));
        }
        p = q;
        q.clear();
    }
    for (auto elem : p) {
        ret.add(std::make_pair<int, int>(int(round(elem.first)), int(round(elem.second))));
    }
    return ret;
}

bool Figure::convex(void) const {
    if (size() < 3) {
        return false;
    }
    int res = 0, tmp;
    int x0, y0, x1, y1, x2, y2;
    for (size_t i = 0; i < size(); ++i) {
        x0 = (*this)[i].first;
        y0 = (*this)[i].second;
        x1 = (*this)[i + 1].first;
        y1 = (*this)[i + 1].second;
        x2 = (*this)[i + 2].first;
        y2 = (*this)[i + 2].second;
        tmp = (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
        if (tmp == 0) {
            return false;
        }
        if (res == 0) {
            if (tmp < 0) {
                res = -1;
            }
            else {
                res = 1;
            }
        }
        else if (res == -1 && tmp > 0) {
            return false;
        }
        else if (res == 1 && tmp < 0) {
            return false;
        }
    }
    for (int i = 0; i < size() - 2; ++i) {
        for (int j = i + 2; j < size(); ++j) {
            if ((crossing((*this)[i], (*this)[i + 1], (*this)[j], (*this)[j + 1]))) {
                return false;
            }
        }
    }
    return true;
}
