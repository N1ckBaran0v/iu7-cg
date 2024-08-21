#ifndef __MAINWINDOW_HPP__
#define __MAINWINDOW_HPP__

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QMessageBox>
#include <vector>

#include "Surface.hpp"
#include "ui_mainwindow.h"

enum LastAct{NONE, ADD_DOT, RM_DOT, CLS, SOLVE};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow(void);
    void paintEvent(QPaintEvent*);
private slots:
    void on_addButton_clicked(void);
    void on_delButton_clicked(void);
    void on_delAllButton_clicked(void);
    //void on_decrScaleButton_clicked(void);
    //void on_incrScaleButton_clicked(void);
    void on_discardButton_clicked(void);
    void on_solveButton_clicked(void);
    void on_aboutButton_clicked(void);
    void on_authorButton_clicked(void);
    void on_outButton_clicked(void);
private:
    Ui::MainWindow *ui;
    Surface surface;
    //int scale;
    bool isSolved;
    LastAct lastAct;
    bool lastFlag;
    std::vector <Dot> lastDots;
    double minX, minY, maxX, maxY;
    int getDot(double&, double&);
    void mousePressEvent(QMouseEvent*);
};

#endif //__MAINWINDOW_HPP__