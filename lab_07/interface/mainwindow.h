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

#include "../field/line.h"
#include "../field/square.h"
#include "ui_mainwindow.h"

struct prev {
    bool can = false;
    std::vector<Line> lines, cuts;
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
    void on_resultColorButton_clicked(void);
    void on_cutterColorButton_clicked(void);
    void on_fontColorButton_clicked(void);
    void on_addButton_clicked(void);
    void on_delButton_clicked(void);
    void on_cutterButton_clicked(void);
    void on_discardButton_clicked(void);
    void on_discardAllButton_clicked(void);
    void on_aboutButton_clicked(void);
    void on_authorButton_clicked(void);
    void on_outButton_clicked(void);
private:
    Ui::MainWindow *ui;
    bool isCutter = false;
    std::vector<Line> lines;
    std::vector<Line> cuts;
    QColor fontColor, cutterColor, resultColor, lineColor;
    prev state;
    
    int getLine(int &x0, int &y0, int &x1, int &y1);
    int getCutter(int &x0, int &y0, int &x1, int &y1);
    void mousePressEvent(QMouseEvent *event);
    void saveState(void);
};

#endif //__MAINWINDOW_HPP__