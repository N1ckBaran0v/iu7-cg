#ifndef __DOT_HPP__
#define __DOT_HPP__

class Dot {
public:
    Dot(void);
    Dot(int x, int y, int intensity = 255);
    void set(int x, int y, int intensity = 255);
    void get(int &x, int &y);
    int getIntencity(void);
    bool equal(int x, int y);
    bool equal(Dot &another);
private:
    int x;
    int y;
    int intensity;
};

#endif //__DOT_HPP__