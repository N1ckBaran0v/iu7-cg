#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
#include <iostream>

#include "qcustomplot.h"
//#include "Analyse.hpp"
#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), 
                                          ui(new Ui::MainWindow), 
                                          fontColor(Qt::white),
                                          linesColor(Qt::black),
                                          lines(),
                                          LastCnt(0) {
    this->ui->setupUi(this);
    this->ui->lineEditX0->setText(QString("0"));
    this->ui->lineEditY0->setText(QString("0"));
    this->ui->lineEditX1->setText(QString("0"));
    this->ui->lineEditY1->setText(QString("0"));
    this->ui->lineEditX->setText(QString("0"));
    this->ui->lineEditY->setText(QString("0"));
    this->ui->lineEditLen->setText(QString("0"));
    this->ui->lineEditStep->setText(QString("1"));
    QString qss = QString("background-color: %1").arg(this->linesColor.name());
    ui->lineColorButton->setStyleSheet(qss);
    qss = QString("background-color: %1").arg(this->fontColor.name());
    ui->fontColorButton->setStyleSheet(qss);
    this->repaint();
}

MainWindow::~MainWindow(void) {
    delete this->ui;
}

void MainWindow::paintEvent(QPaintEvent *pEvent) {
    QPainter p(this);
    int canvasWidth = this->width() - 220;
    int canvasHeight = this->height();
    int canvasX = 220;
    int canvasY = 0;
    p.fillRect(canvasX, canvasY, canvasWidth, canvasHeight, this->fontColor);

    int canvasCenterX = canvasX + canvasWidth / 2;
    int canvasCenterY = canvasY + canvasHeight / 2;
    double x0, y0;
    Dot center(0, 0);

    double minX = -canvasWidth / 2.0;
    double maxX = (double)canvasX + canvasWidth - canvasCenterX;
    double minY = -canvasHeight / 2.0;
    double maxY = (double)canvasY + canvasHeight - canvasCenterY;

    //p.setPen(QPen(Qt::lightGray, 1));
    int itXGrid = canvasX - (int)(round(minX)) % 10;
    //for (; itXGrid < canvasX + canvasWidth; itXGrid += 10)
    //    p.drawLine(itXGrid, canvasY, itXGrid, canvasY + canvasHeight);
    int itYGrid = ((int)(round(maxY)) % 10 + 10) % 10 + canvasY;
    /*for (; itYGrid < canvasY + canvasHeight; itYGrid += 10)
        p.drawLine(canvasX, itYGrid, canvasX + canvasWidth, itYGrid);

    p.setPen(QPen(Qt::gray, 2));
    itXGrid = canvasX - (int)(round(minX)) % 100;
    for (; itXGrid < canvasX + canvasWidth; itXGrid += 100)
        p.drawLine(itXGrid, canvasY, itXGrid, canvasY + canvasHeight);
    itYGrid = ((int)(round(maxY)) % 100 + 100) % 100 + canvasY;
    for (; itYGrid < canvasY + canvasHeight; itYGrid += 100)
        p.drawLine(canvasX, itYGrid, canvasX + canvasWidth, itYGrid);*/

    p.setPen(QPen(Qt::darkGray, 1));
    if (!(minX > 0 || maxX < 0)) {
        itXGrid = canvasX + (int)round(-minX);
        p.drawLine(itXGrid, canvasY, itXGrid, canvasY + canvasHeight);
    }
    if (!(minY > 0 || maxY < 0)) {
        itYGrid = canvasY + (int)round(maxY);
        p.drawLine(canvasX, itYGrid, canvasX + canvasWidth, itYGrid);
    }

    Dot screenCenter(canvasCenterX, canvasCenterY);
    for (auto it = lines.begin(); it != lines.end(); ++it)
        it->draw(p, screenCenter);
    /*
    if (this->LastCnt < 0) {
        Dot first(-100, -100);
        Dot second(100, 100);
        clock_t start, stop;
        double times[6] = {0};
        for (int i = 0; i < 6; ++i) {
            Line tmpLine(this->linesColor, i, first, second);
            for (size_t j = 0; j < 1; ++j) {
                start = clock();
                tmpLine.draw(p, screenCenter);
                stop = clock();
                times[i] += double(stop - start) / CLOCKS_PER_SEC;
            }
        }
        char buf[70] = {0};
        sprintf(buf, "%10.6f\n%10.6f\n%10.6f\n%10.6f\n%10.6f\n%10.6f\n", times[0], times[1], times[2],
                                                                                   times[3], times[4], times[5]);
        QMessageBox::about(this, "Результаты замеров", buf);
        this->LastCnt = 0;
    }*/

    p.fillRect(0, 0, canvasX, this->height(), Qt::black);
}

void MainWindow::on_lineColorButton_clicked(void) {
    QColorDialog* q = new QColorDialog();
    q->open();
    this->linesColor = q->getColor();
    QString qss = QString("background-color: %1").arg(this->linesColor.name());
    ui->lineColorButton->setStyleSheet(qss);
    delete q;
}

void MainWindow::on_fontColorButton_clicked(void)  {
    QColorDialog* q = new QColorDialog();
    q->open();
    this->fontColor = q->getColor();
    QString qss = QString("background-color: %1").arg(this->fontColor.name());
    ui->fontColorButton->setStyleSheet(qss);
    delete q;
    this->repaint();
}

/*void MainWindow::on_fcilcButton_clicked(void) {
    this->fontColor = this->linesColor;
    QString qss = QString("background-color: %1").arg(this->fontColor.name());
    ui->fontColorButton->setStyleSheet(qss);
    this->repaint();
}*/

void MainWindow::on_drawLineButton_clicked(void) {
    int x0, y0, x1, y1;
    int ret = this->getSegment(x0, y0, x1, y1);
    if (ret)
        QMessageBox::critical(this, "Ошибка", "Неправильный формат входных данных.");
    else {
        Dot start(x0, y0);
        Dot end(x1, y1);
        int alg = this->ui->comboBox->currentIndex();
        this->lines.push_back(Line(this->linesColor, alg, start, end));
        this->LastCnt = 1;
        this->repaint();
    }
}

void MainWindow::on_drawLinesButton_clicked(void) {
    int x0, y0, angle, length;
    int ret = this->getSpectrum(x0, y0, angle, length);
    if (ret == -1)
        QMessageBox::critical(this, "Ошибка", "Неправильный формат входных данных.");
    else if (ret == -2)
        QMessageBox::critical(this, "Ошибка", "Неправильный диапазон входных данных.");
    else {
        Dot center(x0, y0);
        int alg = this->ui->comboBox->currentIndex();
        this->LastCnt = 0;
        for (int itang = 0; itang < 360 && itang > -360; itang += angle) {
            this->lines.push_back(Line(this->linesColor, alg, center, length, itang));
            ++(this->LastCnt);
        }
        this->repaint();
    }
}

void MainWindow::on_analyseButton_clicked(void) {
    std::vector <double> steps;
    for (size_t i = 0; i < (int)this->lines.size(); ++i) {
        int way, step;
        this->lines[i].getWay(way);
        if (way < 5) {
            this->lines[i].getSteps(step);
            steps.push_back(step);
        }
    }
    if (steps.size() > 0) {
        QVector<double> x_s;
        QVector<double> y_s;
        for (size_t i = 0; i < steps.size(); ++i) {
            y_s.append(steps[i]);
            x_s.append(double(i + 1));
            //std::cout << i + 1 << ' ' << steps[i] << '\n';
        }
        double maxX = (double)steps.size() + 1;
        double maxY = *std::max_element(steps.begin(), steps.end()) + 1;
        QWidget *w = new QWidget();
        w->setWindowTitle("Анализ ступенчатости");
        QGridLayout *gridLayout = new QGridLayout(w);
        QCustomPlot *customPlot = new QCustomPlot();
        gridLayout->addWidget(customPlot, 1, 0, 1, 1);
        customPlot->addGraph();
        customPlot->graph(0)->setData(x_s, y_s);
        customPlot->xAxis->setLabel("Номер отрезка (в порядке отрисовки)");
        customPlot->xAxis->setRange(0, maxX);
        //customPlot->yAxis->setLabel("Количество ступеней");
        customPlot->yAxis->setRange(0, maxY);
        customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
        //QCPItemTracer *tracer = new QCPItemTracer(customPlot);
        //tracer->setGraph(customPlot->graph(0));
        customPlot->replot();
        w->setMinimumSize(QSize(400, 200));
        w->show();
    }
    else
        QMessageBox::critical(this, "Ошибка", "Нет отрезков, нарисованных не библиотечной функцией.");
}

void MainWindow::on_analyseButton_2_clicked(void) {
    std::vector <double> times;
    for (size_t i = 0; i < (int)this->lines.size(); ++i) {
        int x0, y0, x1, y1, way, step, time;
        this->lines[i].getWay(way);
        if (way < 5) {
            this->lines[i].getTime(time);
            times.push_back(time);
        }
    }
    if (times.size() > 0) {
        QVector<double> x_t;
        QVector<double> y_t;
        for (size_t i = 0; i < times.size(); ++i) {
            y_t.append(times[i]);
            x_t.append(double(i + 1));
            //std::cout << i + 1 << ' ' << times[i] << '\n';
        }
        double maxX = (double)times.size() + 1;
        double maxY = *std::max_element(times.begin(), times.end()) + 1;
        QWidget *w = new QWidget();
        w->setWindowTitle("Анализ времени работы (в мс)");
        QGridLayout *gridLayout = new QGridLayout(w);
        QCustomPlot *customPlot = new QCustomPlot();
        gridLayout->addWidget(customPlot, 1, 0, 1, 1);
        customPlot->addGraph();
        customPlot->graph(0)->setData(x_t, y_t);
        customPlot->xAxis->setLabel("Номер отрезка (в порядке отрисовки)");
        customPlot->xAxis->setRange(0, maxX);
        //customPlot->yAxis->setLabel("Количество ступеней");
        customPlot->yAxis->setRange(0, maxY);
        customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
        //QCPItemTracer *tracer = new QCPItemTracer(customPlot);
        //tracer->setGraph(customPlot->graph(0));
        customPlot->replot();
        w->setMinimumSize(QSize(400, 200));
        w->show();
    }
    else
        QMessageBox::critical(this, "Ошибка", "Нет отрезков, нарисованных не библиотечной функцией.");
}

void MainWindow::on_discardButton_clicked(void) {
    for (; this->LastCnt; --(this->LastCnt))
        this->lines.pop_back();
    this->repaint();
}

void MainWindow::on_discardAllButton_clicked(void) {
    this->LastCnt = 0;
    this->lines.clear();
    /*fontColor = Qt::white;
    linesColor = Qt::black;
    QString qss = QString("background-color: %1").arg(this->linesColor.name());
    ui->lineColorButton->setStyleSheet(qss);
    qss = QString("background-color: %1").arg(this->fontColor.name());
    ui->fontColorButton->setStyleSheet(qss);*/
    this->repaint();
}

void MainWindow::on_aboutButton_clicked(void) {
    QMessageBox::about(this, "О программе", 
    "Условие: Реализовать рисование одиночных отрезков (используя разные алгоритмы). Реализовать рисование спектра отрезков.\n"
    "Формат входных данных: Для одиночных задаются координаты концов, для спектра - координаты центра, длины отрезков и шаг изменения угла (в градусах) Такжеможно задать цвета отрезков и фона.\n "
    "Также точки можно задать нажтием (точки отрезка - ПКМ/ЛКМ, центр спектра - нажатие колесика мыши)\n"
    "Ограничения: Все числа целые (координаты задаются пикселями), длина не может быть меньше 0, угол не может быть равен 0.");
}

void MainWindow::on_authorButton_clicked(void) {
    QMessageBox::about(this, "Об авторе", "Автор: Баранов Николай, группа ИУ7-45Б.");
}

void MainWindow::on_outButton_clicked(void) {
    this->close();
}

int MainWindow::getSegment(int &x0, int &y0, int &x1, int &y1) {
    int rc = 0;
    QString sx0 = this->ui->lineEditX0->text();
    QString sy0 = this->ui->lineEditY0->text();
    QString sx1 = this->ui->lineEditX1->text();
    QString sy1 = this->ui->lineEditY1->text();
    int xt0 = 0;
    int yt0 = 0;
    int xt1 = 0;
    int yt1 = 0;
    bool okX0 = false;
    bool okY0 = false;
    bool okX1 = false;
    bool okY1 = false;
    xt0 = sx0.toInt(&okX0);
    yt0 = sy0.toInt(&okY0);
    xt1 = sx1.toInt(&okX1);
    yt1 = sy1.toInt(&okY1);
    if (!(okX0) || !(okY0) || !(okX1) || !(okY1)) 
        rc = -1;
    else {
        x0 = xt0;
        y0 = yt0;
        x1 = xt1;
        y1 = yt1;
    }
    return rc;
}

int MainWindow::getSpectrum(int &x0, int &y0, int &angle, int &lenght) {
    int rc = 0;
    QString sx0 = this->ui->lineEditX->text();
    QString sy0 = this->ui->lineEditY->text();
    QString sa = this->ui->lineEditStep->text();
    QString sl = this->ui->lineEditLen->text();
    int xt0 = 0;
    int yt0 = 0;
    int at = 0;
    int lt = 0;
    bool okX0 = false;
    bool okY0 = false;
    bool okA = false;
    bool okL = false;
    xt0 = sx0.toInt(&okX0);
    yt0 = sy0.toInt(&okY0);
    at = sa.toInt(&okA);
    lt = sl.toInt(&okL);
    if (!(okX0) || !(okY0) || !(okA) || !(okL)) 
        rc = -1;
    else if (at == 0 || lt < 0)
        rc = -2;
    else {
        x0 = xt0;
        y0 = yt0;
        angle = at;
        lenght = lt;
    }
    return rc;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    int canvasWidth = this->width() - 220;
    int canvasHeight = this->height();
    int canvasX = 220;
    int canvasY = 0;
    int cx = event->pos().x();
    int cy = event->pos().y();
    if (cx >= canvasX && cx <= canvasX + canvasWidth && 
        cy >= canvasY && cy <= canvasY + canvasHeight) {
        int canvasCenterX = canvasX + canvasWidth / 2;
        int canvasCenterY = canvasY + canvasHeight / 2;
        int posX = cx - canvasCenterX;
        int posY = canvasCenterY - cy;
        std::string tsx = std::to_string(posX);
        std::string tsy = std::to_string(posY);
        QString tmpX(tsx.c_str());
        QString tmpY(tsy.c_str());
        if (event->button() == Qt::LeftButton) {
            this->ui->lineEditX0->setText(tmpX);
            this->ui->lineEditY0->setText(tmpY);
        } else if (event->button() == Qt::RightButton) {
            this->ui->lineEditX1->setText(tmpX);
            this->ui->lineEditY1->setText(tmpY);
        } else if (event->button() == Qt::MiddleButton) {
            this->ui->lineEditX->setText(tmpX);
            this->ui->lineEditY->setText(tmpY);
        }
    }
}
