#ifndef __DOT_HPP__
#define __DOT_HPP__

class Dot {
public:
    Dot(void);
    Dot(double, double);
    void get(double&, double&);
    bool equal(double, double);
    bool equal(Dot&);
private:
    double x;
    double y;
};

#endif //__DOT_HPP__