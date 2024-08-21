#ifndef __MAINWINDOW_HPP__
#define __MAINWINDOW_HPP__

#include <QMainWindow>
#include <QPainter>
#include <QColor>
#include <QPaintEvent>
#include <QMessageBox>
#include <QColorDialog>
#include <vector>

#include "Line.hpp"
#include "ui_mainwindow.h"

enum LastAct{NONE, LINE, SPECTRUM};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow(void);
    void paintEvent(QPaintEvent*);
private slots:
    void on_lineColorButton_clicked(void);
    void on_fontColorButton_clicked(void);
    void on_drawLineButton_clicked(void);
    void on_drawLinesButton_clicked(void);
    void on_discardButton_clicked(void);
    void on_analyseButton_clicked(void);
    void on_analyseButton_2_clicked(void);
    void on_discardAllButton_clicked(void);
    void on_aboutButton_clicked(void);
    void on_authorButton_clicked(void);
    void on_outButton_clicked(void);
private:
    Ui::MainWindow *ui;
    QColor fontColor, linesColor;
    std::vector<Line> lines;
    int LastCnt;
    int getSegment(int &x0, int &y0, int &x1, int &y1);
    int getSpectrum(int &x0, int &y0, int &angle, int &lenght);
    void mousePressEvent(QMouseEvent *event);
};

#endif //__MAINWINDOW_HPP__