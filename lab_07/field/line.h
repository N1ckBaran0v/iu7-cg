#ifndef __LINE_H__
#define __LINE_H__

#include "square.h"

class Line {
public:
    Line();
    Line(Dot &&first, Dot &&second);
    void set(const Dot &first, const Dot &second);
    void get(Dot &first, Dot &second);
    bool visible(Square &cutter, Line &result);
private:
    Dot _first, _second;
};

#endif // __LINE_H__