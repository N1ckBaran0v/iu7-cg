#include <stdexcept>
#include <iostream>

#include "cutter.h"

Cutter::Cutter(void) : _dots() {}

#define EPS 5e-7

static bool crossing(const Dot &d1, const Dot &d2, const Dot &d3, const Dot &d4) {
    bool cross = false;
    int x00, x01, x10, x11, y00, y01, y10, y11;
    d1.get(x00, y00);
    d2.get(x01, y01);
    d3.get(x10, y10);
    d4.get(x11, y11);
    int v1 = (x00 - x10) * (y01 - y10) - (x01 - x10) * (y00 - y10);
    int v2 = (x00 - x11) * (y01 - y11) - (x01 - x11) * (y00 - y11);
    return (v1 > 0 && v2 < 0) || (v1 < 0 && v2 > 0);
}

void Cutter::add(const Dot &dot) {
    _dots.push_back(dot);
}

Dot &Cutter::operator [](const int i) {
    return _dots[(i % _dots.size() + _dots.size()) % _dots.size()];
}

const Dot &Cutter::operator [](const int i) const {
    return _dots[(i % _dots.size() + _dots.size()) % _dots.size()];
}

void Cutter::remove(size_t num) {
    if (num < _dots.size()) {
        for (size_t i = num + 1; i < _dots.size(); ++i) {
            _dots[i - 1] = _dots[i];
        }
        _dots.pop_back();
    }
    else {
        throw std::runtime_error("Incorrect index.\n");
    }
}

size_t Cutter::size(void) {
    return _dots.size();
}

bool Cutter::empty(void) {
    return _dots.empty();
}

void Cutter::clear(void) {
    _dots.clear();
}

int Cutter::check(void) {
    if (_dots.size() < 1) {
        return -1;
    }
    if (_dots.size() == 1) {
        return -2;
    }
    if (_dots.size() == 2) {
        return -3;
    }
    int res = 0, tmp;
    int x0, y0, x1, y1, x2, y2;
    for (size_t i = 0; i < size(); ++i) {
        (*this)[i].get(x0, y0);
        (*this)[i + 1].get(x1, y1);
        (*this)[i + 2].get(x2, y2);
        tmp = (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
        if (tmp == 0) {
            return -4;
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
            return -4;
        }
        else if (res == 1 && tmp < 0) {
            return -4;
        }
    }
    for (int i = 0; i < size() - 2; ++i) {
        for (int j = i + 2; j < size(); ++j) {
            if ((crossing((*this)[i], (*this)[i + 1], (*this)[j], (*this)[j + 1]))) {
                return -4;
            }
        }
    }
    return 0;
}