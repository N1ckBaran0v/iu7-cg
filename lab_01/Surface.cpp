#include <cmath>

#include "Surface.hpp"
#include "Circle.hpp"

#ifndef EPS
#define EPS 5e-4
#endif

Surface::Surface(void) : dots(), answer(), isSolved(false) {}

void Surface::pushDot(double x, double y) {
    if (!(this->isExist(x, y))) {
        if (this->maxDotsCount())
            throw "Dots count limit exceeded";
        this->dots.push_back(Dot(x, y));
        if (this->isSolved)
            this->isSolved = false;
    }
}

void Surface::popDot(double x, double y) {
    if (this->empty())
        throw "Surface doesn't contain dots";
    if (this->isExist(x, y)) {
        bool isDotFound = false;
        for (size_t i = 0; i < this->dots.size() - 1; ++i) {
            if (!isDotFound && this->dots[i].equal(x, y)) 
                isDotFound = true;
            if (isDotFound) 
                this->dots[i] = this->dots[i + 1];
        }
        this->dots.pop_back();
        if (this->isSolved)
            this->isSolved = false;
    }
    else
        throw "Dot not found";
}

void Surface::clear(void) {
    this->dots.clear();
    this->isSolved = false;
}

bool Surface::empty(void) {
    return this->dots.size() == 0;
}

bool Surface::maxDotsCount(void) {
    return this->dots.size() == MAX_DOTS_COUNT;
}

bool Surface::canSolved(void) {
    return this->dots.size() >= 3;
}

bool Surface::isExist(double x, double y) {
    bool ret = false;
    for (size_t i = 0; !ret && i < this->dots.size(); ++i)
        ret = dots[i].equal(x, y);
    return ret;
}

size_t Surface::dotsCount(void) {
    return this->dots.size();
}

std::vector <Dot> Surface::getDots(void) {
    return this->dots;
}

int Surface::getAnswer(Circle &answer) {
    int rc = 0;
    if (!(this->canSolved()))
        rc = -1;
    if (!(this->isSolved)) {
        int minDiff = 0, currDiff = 0;
        Circle currAnswer;
        DotPos currPos;
        for (size_t i0 = 0; i0 < this->dots.size(); i0++) {
            for (size_t i1 = 0; i1 < this->dots.size(); i1++) {
                for (size_t i2 = 0; i2 < this->dots.size(); i2++) {
                    if (Circle::canInitCircle(this->dots[i0], this->dots[i1], this->dots[i2])) {
                        currAnswer = Circle(this->dots[i0], this->dots[i1], this->dots[i2]);
                        currDiff = 0;
                        for (size_t i3 = 0; i3 < this->dots.size(); i3++) {
                            currPos = currAnswer.calcPosition(this->dots[i3]);
                            if (currPos == INSIDE)
                                currDiff++;
                            else if (currPos == OUTSIDE)
                                currDiff--;
                        }
                        if (!(this->isSolved) || abs(currDiff) < minDiff) {
                            this->isSolved = true;
                            minDiff = abs(currDiff);
                            this->answer = currAnswer;
                        }
                    }
                }
            }
        }
    }
    if (this->isSolved)
        answer = this->answer;
    else
        rc = -2;
    return rc;
}

int Surface::getLimits(double &minx, double &miny, double &maxx, double&maxy) {
    int ret = 0;
    if (this->dots.empty())
        ret = -1;
    else {
        double x, y;
        this->dots[0].get(x, y);
        minx = x;
        miny = y;
        maxx = x;
        maxy = y;
        for (size_t i = 1; i < this->dots.size(); ++i) {
            this->dots[i].get(x, y);
            if (minx > x)
                minx = x;
            if (miny > y)
                miny = y;
            if (maxx < x)
                maxx = x;
            if (maxy < y)
                maxy = y;
        }
    }
    return ret;
}