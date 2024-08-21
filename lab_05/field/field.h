#ifndef __FIELD_H__
#define __FIELD_H__

#include <vector>
#include <memory>
#include <QImage>
#include <QColor>

#include "delayout.h"
#include "figure.h"
#include "dot.h"
#include "errors.h"

class Field {
public:
    Field(void);
    void addFigure(Dot &&dot);
    void addDot(Dot &&dot, size_t fieldIndex);
    void delDot(size_t dotIndex, size_t fieldIndex);
    double draw(QImage &image, int x, int y, QColor &font, QColor &line, QColor &fill, bool needFill = false, delayOut *dout = nullptr);
    Figure operator[](size_t i) const;
    Figure &operator[](size_t i);
private:
    std::vector<Figure> figures;
    void findBorders(int &minX, int &minY, int &maxX, int &maxY) const ;
};

#endif // __FIELD_H__