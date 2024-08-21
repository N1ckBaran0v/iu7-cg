#ifndef __FIGURE_H__
#define __FIGURE_H__

#include <cstddef>
#include <vector>

typedef std::pair<int, int> dot_t;

class Figure {
public:
    Figure(void) = default;
    ~Figure(void) = default;
    void add(const dot_t &dot);
    void add(dot_t &&dot);
    void remove(const size_t index);
    size_t size(void) const noexcept;
    size_t empty(void) const noexcept;
    dot_t &operator[](const size_t i) noexcept;
    const dot_t &operator[](const size_t i) const noexcept;
    Figure cut(const Figure &cutter) const;
    bool convex(void) const;
private:
    std::vector<dot_t> _dots;
};

#endif // __FIGURE_H__