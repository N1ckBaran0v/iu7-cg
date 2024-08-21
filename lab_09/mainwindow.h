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

#include "figure.h"
#include "ui_mainwindow.h"

struct prev {
    bool can = false;
    Figure figure, cutter;
    bool needCut;
    int cind0, cind1;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow(void);
    void paintEvent(QPaintEvent*);
private slots:
    void on_lineColorButton_clicked(void);
    void on_cutterColorButton_clicked(void);
    void on_resultColorButton_clicked(void);
    void on_fontColorButton_clicked(void);
    void on_addDotButton_clicked(void);
    void on_delDotButton_clicked(void);
    void on_addDotCutterButton_clicked(void);
    void on_delDotCutterButton_clicked(void);
    void on_cutterButton_clicked(void);
    void on_discardButton_clicked(void);
    void on_discardAllButton_clicked(void);
    void on_aboutButton_clicked(void);
    void on_authorButton_clicked(void);
    void on_outButton_clicked(void);
private:
    Ui::MainWindow *ui;
    QColor fontColor, cutterColor, resultColor, lineColor;
    Figure figure, cutter;
    bool needCut;
    prev state;
    
    int getDot(int &x, int &y);
    int getDotCutter(int &x, int &y);
    void mousePressEvent(QMouseEvent *event);
    void saveState(void);
    void boxesSet(int cind0, int cind1);
};

#endif //__MAINWINDOW_HPP__