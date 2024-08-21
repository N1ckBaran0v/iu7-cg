#ifndef __MAINWINDOW_HPP__
#define __MAINWINDOW_HPP__

#include <QMainWindow>
#include <QPainter>
#include <QColor>
#include <QPaintEvent>
#include <QMessageBox>
#include <QColorDialog>
#include <QGraphicsScene>
#include <vector>

#include "../field/field.h"
#include "ui_mainwindow.h"

struct prev {
    bool can = false;
    Field field;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow(void);
    void paintEvent(QPaintEvent*);
private slots:
    void on_fontColorButton_clicked(void);
    void on_surfaceColorButton_clicked(void);
    void on_setButton_clicked(void);
    void on_discardButton_clicked(void);
    void on_discardAllButton_clicked(void);
    void on_aboutButton_clicked(void);
    void on_authorButton_clicked(void);
    void on_outButton_clicked(void);
    void on_sliderX_valueChanged(void);
    void on_sliderY_valueChanged(void);
    void on_sliderZ_valueChanged(void);
private:
    Ui::MainWindow *ui;
    QColor fontColor, surfaceColor;
    Field field;
    prev state;
    
    int getEdges(double &x0, double &x1, double &z0, double &z1);
    int getDiff(double &dx, double &dz);
    int getScale(double &xs, double &ys);
    prev saveState();
};

#endif //__MAINWINDOW_HPP__