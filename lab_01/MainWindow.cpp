#include <string>
#include <cmath>
#include <iostream>

#include "MainWindow.hpp"

#define MAXSIZE 1000000000

#define EPS 5E-2

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), 
                                          ui(new Ui::MainWindow), 
                                          surface(),
                                          isSolved(false), lastAct(NONE),
                                          lastFlag(false), lastDots(),
                                          minX(-10), minY(-10),
                                          maxX(10), maxY(10) {
    this->ui->setupUi(this);
    this->repaint();
}

MainWindow::~MainWindow(void) {
    delete this->ui;
}

void MainWindow::paintEvent(QPaintEvent *pEvent) {
    QPainter p(this);
    int canvasWidth = this->width() - 350;
    int canvasHeight = this->height() - 50;
    int canvasX = 185;
    int canvasY = 0;
    p.fillRect(canvasX, canvasY, canvasWidth, canvasHeight, Qt::white);
    double minX = 0, minY = 0, maxX = 0, maxY = 0;
    this->surface.getLimits(minX, minY, maxX, maxY);
    double lenX = maxX - minX;
    double lenY = maxY - minY;
    double x0 = lenX / 2 + minX;
    double y0 = lenY / 2 + minY;
    if (fabs(lenX) < EPS) {
        minX -= 10;
        maxX += 10;
        lenX = 20;
    }
    if (fabs(lenY) < EPS) {
        minY -= 10;
        maxY += 10;
        lenY = 20;
    }
    lenX *= 1.1;
    lenY *= 1.1;
    if (lenX * canvasHeight < lenY * canvasWidth)
        lenX = (lenY * canvasWidth) / canvasHeight;
    else
        lenY = (lenX * canvasHeight) / canvasWidth;
    
    int canvasCenterX = canvasX + canvasWidth / 2;
    int canvasCenterY = canvasY + canvasHeight / 2;

    char tmpBuf[16];
    double scale = lenY / canvasHeight;
    minX = x0 - (canvasWidth / 2) * scale;
    sprintf(tmpBuf, "%10.6lf", minX);
    this->ui->labelX0->setText(QCoreApplication::translate("MainWindow", tmpBuf, nullptr));
    maxX = x0 + (canvasX + canvasWidth - canvasCenterX) * scale;
    sprintf(tmpBuf, "%10.6lf", maxX);
    this->ui->labelX1->setText(QCoreApplication::translate("MainWindow", tmpBuf, nullptr));
    minY = y0 - (canvasHeight / 2) * scale;
    sprintf(tmpBuf, "%10.6lf", minY);
    this->ui->labelY1->setText(QCoreApplication::translate("MainWindow", tmpBuf, nullptr));
    maxY = y0 + (canvasY + canvasHeight - canvasCenterY) * scale;
    sprintf(tmpBuf, "%10.6lf", maxY);
    this->ui->labelY0->setText(QCoreApplication::translate("MainWindow", tmpBuf, nullptr));

    p.setPen(QPen(Qt::lightGray, 1));
    double gridStep = 1;
    while (lenX / gridStep > 100)
        gridStep *= 10;
    while (lenX / gridStep <= 10)
        gridStep /= 10;
    double scaledStep = gridStep / scale;

    double startSearch = minX;
    double endSearch = minX + gridStep;
    double resultSearch = (endSearch + startSearch) / 2;
    double tmp;
    bool needSearch = true;
    while (needSearch) {
        tmp = resultSearch / gridStep;
        tmp = tmp - round(tmp);
        if (fabs(tmp) < EPS)
            needSearch = false;
        else if (tmp > 0)
            endSearch = resultSearch;
        else
            startSearch = resultSearch;
        if (needSearch)
            resultSearch = (endSearch + startSearch) / 2;
    }

    double itXGrid = canvasX + (int)round((resultSearch - minX) / scale);
    for (; round(itXGrid) < canvasX + canvasWidth; itXGrid += scaledStep)
        p.drawLine(static_cast<int>(round(itXGrid)), canvasY, static_cast<int>(round(itXGrid)), canvasY + canvasHeight);
    
    startSearch = maxY;
    endSearch = maxY - gridStep;
    resultSearch = (endSearch + startSearch) / 2;
    needSearch = true;
    while (needSearch) {
        tmp = resultSearch / gridStep;
        tmp = tmp - round(tmp);
        if (fabs(tmp) < EPS)
            needSearch = false;
        else if (tmp > 0)
            startSearch = resultSearch;
        else
            endSearch = resultSearch;
        if (needSearch)
            resultSearch = (endSearch + startSearch) / 2;
    }
    
    double itYGrid = canvasY + (int)round((maxY - resultSearch) / scale);
    for (; itYGrid < canvasY + canvasHeight; itYGrid += scaledStep)
        p.drawLine(canvasX, (int)round(itYGrid), canvasX + canvasWidth, (int)round(itYGrid));

    double x, y;
    int ix, iy;

    if (this->isSolved) {
        Circle tmp;
        if (!(this->surface.getAnswer(tmp))) {
            p.setPen(QPen(Qt::blue, 2));
            Dot center = tmp.getDot();
            center.get(x, y);
            double radius = round(tmp.getRadius() / scale);
            ix = round((x - minX) / scale) + canvasX;
            iy = round((maxY - y) / scale) + canvasY;
            p.drawEllipse(QPointF(ix, iy), radius, radius);
        }
    }

    if (!(this->getDot(x, y))) {
        p.setPen(QPen(Qt::red, 1));
        p.setBrush(QBrush(Qt::red));
        ix = round((x - minX) / scale) + canvasX;
        iy = round((maxY - y) / scale) + canvasY;
        p.drawEllipse(QPointF(ix, iy), 3, 3);
    }

    p.setPen(QPen(Qt::black, 1));
    p.setBrush(QBrush(Qt::black));
    std::vector <Dot> dots = this->surface.getDots();
    for (size_t i = 0; i < dots.size(); ++i) {
        dots[i].get(x, y);
        ix = round((x - minX) / scale) + canvasX;
        iy = round((maxY - y) / scale) + canvasY;
        p.drawEllipse(QPointF(ix, iy), 2, 2);
    }

    p.fillRect(0, 0, canvasX, this->height(), Qt::black);
    p.fillRect(canvasX + canvasWidth, 0, this->width(), this->height(), Qt::black);
    p.fillRect(canvasX, canvasY + canvasHeight, canvasX + canvasWidth, this->height(), Qt::black);
}

void MainWindow::on_addButton_clicked(void) {
    double x, y;
    int ret = this->getDot(x, y);
    if (ret == 0) {
        if (this->surface.maxDotsCount()) 
            QMessageBox::critical(this, "Ошибка", "Достигнуто максимальное количество точек.");
        else {
            this->lastFlag = this->isSolved;
            this->isSolved = false;
            this->surface.pushDot(x, y);
            this->lastAct = ADD_DOT;
            this->lastDots.clear();
            this->lastDots.push_back(Dot(x, y));
            this->repaint();
        }
    }
    else if (ret == -1)
        QMessageBox::critical(this, "Ошибка", "Неверный формат входных данных.");
    else 
        QMessageBox::critical(this, "Ошибка", "Неверный диапазон координат.");
}

void MainWindow::on_delButton_clicked(void) {
    double x, y;
    int ret = this->getDot(x, y);
    if (ret == 0) {
        if (this->surface.empty()) 
            QMessageBox::critical(this, "Ошибка", "Нет точек.");
        else if (!(this->surface.isExist(x, y)))
            QMessageBox::critical(this, "Ошибка", "Точка не найдена.");
        else {
            this->lastFlag = this->isSolved;
            this->isSolved = false;
            this->surface.popDot(x, y);
            this->lastAct = RM_DOT;
            this->lastDots.clear();
            this->lastDots.push_back(Dot(x, y));
        }
    }
    else if (ret == -1)
        QMessageBox::critical(this, "Ошибка", "Неверный формат входных данных.");
    else 
        QMessageBox::critical(this, "Ошибка", "Неверный диапазон координат.");
    this->repaint();
}

void MainWindow::on_delAllButton_clicked(void) {
    if (this->surface.empty()) 
        QMessageBox::critical(this, "Ошибка", "Нет точек.");
    else {
        this->lastFlag = this->isSolved;
        this->isSolved = false;
        this->lastDots = this->surface.getDots();
        this->surface.clear();
        this->lastAct = CLS;
        this->repaint();
    }
}

void MainWindow::on_discardButton_clicked(void) {
    bool changed = true;
    if (this->lastAct == ADD_DOT) {
        double x, y;
        this->lastDots[0].get(x, y);
        this->surface.popDot(x, y);
    }
    if (this->lastAct == RM_DOT) {
        double x, y;
        this->lastDots[0].get(x, y);
        this->surface.pushDot(x, y);
    }
    if (this->lastAct == CLS) {
        double x, y;
        for (size_t i = 0; i < this->lastDots.size(); ++i) {
            this->lastDots[i].get(x, y);
            this->surface.pushDot(x, y);
        }
    }
    if (this->lastAct == NONE)
        changed = false;
    if (changed) {
        this->isSolved = this->lastFlag;
        this->lastDots.clear();
        this->lastAct = NONE;
        this->repaint();
    }
}

void MainWindow::on_solveButton_clicked(void) {
    if (!(this->isSolved)) {
        Circle unused;
        if (this->surface.getAnswer(unused)) {
            QMessageBox::critical(this, "Ошибка", "Невозможно найти решение при таком расположении точек.");
        }
        else {
            this->lastFlag = false;
            this->isSolved = true;
            this->lastAct = SOLVE;
            this->lastDots.clear();
            this->repaint();
        }
    }
}

void MainWindow::on_aboutButton_clicked(void) {
    QMessageBox::about(this, "О программе", 
    "Условие: На плоскости задано множество из N точек. Определить радиус и центр такой окружности, проходящей через три различные точки заданного множества точек на плоскости, что минимальна разность количеств точек, лежащих внутри и вне окружности.\n");
}

void MainWindow::on_authorButton_clicked(void) {
    QMessageBox::about(this, "Об авторе", "Автор: Баранов Николай, группа ИУ7-45Б.");
}

void MainWindow::on_outButton_clicked(void) {
    this->close();
}

int MainWindow::getDot(double &x, double &y) {
    int rc = 0;
    QString sx = this->ui->lineEditX->text();
    QString sy = this->ui->lineEditY->text();
    double xt = 0;
    double yt = 0;
    bool okX = false;
    bool okY = false;
    xt = sx.toDouble(&okX);
    yt = sy.toDouble(&okY);
    if (!okX || !okY) 
        rc = -1;
    else {
        if (fabs(xt) > MAXSIZE || fabs(yt) > MAXSIZE)
            rc = -2;
        else {
            x = xt;
            y = yt;
        }
    }
    return rc;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        int canvasWidth = this->width() - 350;
        int canvasHeight = this->height() - 50;
        int canvasX = 185;
        int canvasY = 0;
        int cx = event->pos().x();
        int cy = event->pos().y();
        if (cx >= canvasX && cx <= canvasX + canvasWidth &&
            cy >= canvasY && cy <= canvasY + canvasHeight) {
            double minX = 0, minY = 0, maxX = 0, maxY = 0;
            this->surface.getLimits(minX, minY, maxX, maxY);
            double lenX = maxX - minX;
            double lenY = maxY - minY;
            double x0 = lenX / 2 + minX;
            double y0 = lenY / 2 + minY;
            if (fabs(lenX) < EPS) {
                minX -= 10;
                maxX += 10;
                lenX = 20;
            }
            if (fabs(lenY) < EPS) {
                minY -= 10;
                maxY += 10;
                lenY = 20;
            }
            lenX *= 1.1;
            lenY *= 1.1;
            if (lenX * canvasHeight < lenY * canvasWidth)
                lenX = (lenY * canvasWidth) / canvasHeight;
            else
                lenY = (lenX * canvasHeight) / canvasWidth;

            int canvasCenterX = canvasX + canvasWidth / 2;
            int canvasCenterY = canvasY + canvasHeight / 2;
            double scale = lenY / canvasHeight;
            double posX = x0 + (cx - canvasCenterX) * scale;
            double posY = y0 + (canvasCenterY - cy) * scale;
            std::string tmpStr = std::to_string(posX);
            for (size_t i = 0; i < tmpStr.size(); ++i)
                if (tmpStr[i] == ',')
                    tmpStr[i] = '.';
            QString tmpX(tmpStr.c_str());
            tmpStr = std::to_string(posY);
            for (size_t i = 0; i < tmpStr.size(); ++i)
                if (tmpStr[i] == ',')
                    tmpStr[i] = '.';
            QString tmpY(tmpStr.c_str());
            this->ui->lineEditX->setText(tmpX);
            this->ui->lineEditY->setText(tmpY);
        }
    }
    this->repaint();
}
