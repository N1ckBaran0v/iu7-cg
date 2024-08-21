#ifndef __CUTTER_H__
#define __CUTTER_H__

#include <cstddef>
#include <vector>

#include "dot.h"

class Cutter {
public:
    Cutter(void);
    void add(const Dot &dot);
    Dot &operator [](const int i);
    const Dot &operator [](const int i) const;
    void remove(size_t num);
    size_t size(void);
    bool empty(void);
    void clear(void);
    int check(void);
private:
    std::vector<Dot> _dots;
};

#endif // __CUTTER_H__