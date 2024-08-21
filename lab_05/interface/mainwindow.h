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
    bool needFill;
    std::vector<QString> vals;
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
    void on_fillColorButton_clicked(void);
    void on_fontColorButton_clicked(void);
    void on_addDotButton_clicked(void);
    void on_delDotButton_clicked(void);
    void on_fillButton_clicked(void);
    void on_analyseButton_clicked(void);
    void on_discardButton_clicked(void);
    void on_discardAllButton_clicked(void);
    void on_aboutButton_clicked(void);
    void on_authorButton_clicked(void);
    void on_outButton_clicked(void);
    void on_figureBox_currentIndexChanged(void);
private:
    Ui::MainWindow *ui;
    Field field;
    QColor fontColor, linesColor, fillColor;
    bool needFill;
    int needDelay = -1;
    int lastTime = -1;
    prev state;
    
    int getDot(int &x, int &y);
    void setDotBox(void);
    void mousePressEvent(QMouseEvent *event);
    void saveState(void);
};

#endif //__MAINWINDOW_HPP__