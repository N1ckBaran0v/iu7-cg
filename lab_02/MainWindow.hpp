#ifndef __MAINWINDOW_HPP__
#define __MAINWINDOW_HPP__

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QMessageBox>
#include <vector>

#include "Image.hpp"
#include "ui_mainwindow.h"

enum LastAct{NONE, MOVE, ROTATE, SCALING};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow(void);
    void paintEvent(QPaintEvent*);
private slots:
    void on_moveButton_clicked(void);
    void on_rotateButton_clicked(void);
    void on_scaleImageButton_clicked(void);
    void on_discardButton_clicked(void);
    void on_discardAllButton_clicked(void);
    void on_aboutButton_clicked(void);
    void on_authorButton_clicked(void);
    void on_outButton_clicked(void);
private:
    Ui::MainWindow *ui;
    Image *image;
    LastAct lastAct;
    std::pair <double, double> lastNums;
    std::pair <double, double> lastNums2;
    int getOffset(double &x, double &y);
    int getRotate(double &x, double &y, double &angle);
    int getScaling(double &x, double &y, double &dx, double &dy);
};

#endif //__MAINWINDOW_HPP__