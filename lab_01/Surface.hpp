#ifndef __SURFACE_HPP__
#define __SURFACE_HPP__

#include <vector>
#include <unordered_map>
#include <cstddef>

#include "Dot.hpp"
#include "Circle.hpp"

#define MAX_DOTS_COUNT 100

class Surface {
public:
    Surface(void);
    void pushDot(double x, double y);
    void popDot(double x, double y);
    void clear(void);
    bool empty(void);
    bool maxDotsCount(void);
    bool canSolved(void);
    bool isExist(double, double);
    size_t dotsCount(void);
    std::vector <Dot> getDots(void);
    int getAnswer(Circle&);
    int getLimits(double&, double&, double&, double&);
private:
    std::vector <Dot> dots;
    Circle answer;
    bool isSolved;
};

#endif // __SURFACE_HPP__