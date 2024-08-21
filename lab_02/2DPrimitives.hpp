#ifndef __2DPRIMITIVES_HPP__
#define __2DPRIMITIVES_HPP__

class Dot;
class Vector2D;

class Dot {
public:
    Dot(const Dot &source);
    Dot(const double x, const double y);
    void rotate(const Dot &center, const double angle);
    void move(const Vector2D &offset);
    void scalingX(const Dot &center, const double scalingCoef);
    void scalingY(const Dot &center, const double scalingCoef);
    void set(const double x, const double y);
    void get(double &x, double &y) const;
private:
    double x, y;
};

class Vector2D {
public:
    Vector2D(const double x, const double y);
    Vector2D(const Dot &begin, const Dot &end);
    void scalingX(const double scalingCoef);
    void scalingY(const double scalingCoef);
    void rotate(const double angle);
    void getEndPos(const Dot &begin, Dot &end) const;
    void get(double &x, double &y) const;
private:
    double x, y;
};

#endif //__2DPRIMITIVES_HPP__
