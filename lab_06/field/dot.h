#ifndef __DOT_H__
#define __DOT_H__

class Dot {
public:
    Dot(void);
    Dot(const int x, const int y);
    void set(int x, int y);
    void get(int &x, int &y) const;
    bool equal(int x, int y) const;
    bool equal(Dot &another) const;
private:
    int x;
    int y;
};

#endif //__DOT_H__