#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
#include <iostream>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), 
                                          ui(new Ui::MainWindow),
                                          fontColor(Qt::white),
                                          lineColor(Qt::black),
                                          cutterColor(Qt::red),
                                          resultColor(Qt::green) {
    ui->setupUi(this);
    this->ui->lineEditX0->setText(QString("0"));
    this->ui->lineEditY0->setText(QString("0"));
    this->ui->lineEditX0_2->setText(QString("0"));
    this->ui->lineEditY0_2->setText(QString("0"));
    this->ui->lineEditX1->setText(QString("0"));
    this->ui->lineEditY1->setText(QString("0"));
    this->ui->lineEditX1_2->setText(QString("0"));
    this->ui->lineEditY1_2->setText(QString("0"));
    QString qss = QString("background-color: %1").arg(lineColor.name());
    ui->lineColorButton->setStyleSheet(qss);
    qss = QString("background-color: %1").arg(fontColor.name());
    ui->fontColorButton->setStyleSheet(qss);
    qss = QString("background-color: %1").arg(cutterColor.name());
    ui->cutterColorButton->setStyleSheet(qss);
    qss = QString("background-color: %1").arg(resultColor.name());
    ui->resultColorButton->setStyleSheet(qss);
    repaint();
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
    p.fillRect(canvasX, canvasY, canvasWidth, canvasHeight, fontColor);
    int x0, y0, x1, y1;
    Dot d1, d2;
    p.setPen(QPen(lineColor, 1));
    for (auto line : lines) {
        line.get(d1, d2);
        d1.get(x0, y0);
        d2.get(x1, y1);
        x0 += canvasX;
        y0 += canvasY;
        x1 += canvasX;
        y1 += canvasY;
        p.drawLine(x0, y0, x1, y1);
    }
    p.setPen(QPen(resultColor, 1));
    for (auto line : cuts) {
        line.get(d1, d2);
        d1.get(x0, y0);
        d2.get(x1, y1);
        x0 += canvasX;
        y0 += canvasY;
        x1 += canvasX;
        y1 += canvasY;
        p.drawLine(x0, y0, x1, y1);
    }
    int rc = getCutter(x0, y0, x1, y1);
    if (rc == 0) {
        p.setPen(QPen(cutterColor, 1));
        x0 += canvasX;
        y0 += canvasY;
        x1 += canvasX;
        y1 += canvasY;
        p.drawLine(x0, y0, x0, y1);
        p.drawLine(x0, y1, x1, y1);
        p.drawLine(x1, y1, x1, y0);
        p.drawLine(x1, y0, x0, y0);
    }
    p.fillRect(0, 0, canvasX, this->height(), Qt::black);
}

void MainWindow::on_lineColorButton_clicked(void) {
    QColorDialog* q = new QColorDialog();
    q->open();
    lineColor = q->getColor();
    QString qss = QString("background-color: %1").arg(lineColor.name());
    ui->lineColorButton->setStyleSheet(qss);
    delete q;
    repaint();
}

void MainWindow::on_resultColorButton_clicked(void) {
    QColorDialog* q = new QColorDialog();
    q->open();
    resultColor = q->getColor();
    QString qss = QString("background-color: %1").arg(resultColor.name());
    ui->resultColorButton->setStyleSheet(qss);
    delete q;
    repaint();
}

void MainWindow::on_cutterColorButton_clicked(void) {
    QColorDialog* q = new QColorDialog();
    q->open();
    cutterColor = q->getColor();
    QString qss = QString("background-color: %1").arg(cutterColor.name());
    ui->cutterColorButton->setStyleSheet(qss);
    delete q;
    repaint();
}

void MainWindow::on_fontColorButton_clicked(void) {
    QColorDialog* q = new QColorDialog();
    q->open();
    fontColor = q->getColor();
    QString qss = QString("background-color: %1").arg(fontColor.name());
    ui->fontColorButton->setStyleSheet(qss);
    delete q;
    repaint();
}

void MainWindow::on_addButton_clicked(void) {
    cuts.clear();
    int x0, y0, x1, y1;
    int rc = getLine(x0, y0, x1, y1);
    if (rc == -1) {
        QMessageBox::critical(this, "Ошибка", "Неправильный формат входных данных.");
        return;
    }
    saveState();
    lines.push_back(Line(Dot(x0, y0), Dot(x1, y1)));
    QString tmp(std::string("[" + std::to_string(x0) + ", " + std::to_string(y0) + "] [" + 
                                  std::to_string(x1) + ", " + std::to_string(y1) + "]").c_str());
    ui->figureBox->addItem(tmp);
    repaint();
}

void MainWindow::on_delButton_clicked(void) {
    cuts.clear();
    int ind = ui->figureBox->currentIndex();
    if (ind == 0) {
        QMessageBox::critical(this, "Ошибка", "Не выбрана фигура.");
        return;
    }
    saveState();
    for (int i = ind; i < lines.size(); ++i) {
        lines[i - 1] = lines[i];
    }
    lines.pop_back();
    ui->figureBox->removeItem(ind);
    ui->figureBox->setCurrentIndex(0);
    repaint();
}

void MainWindow::on_cutterButton_clicked(void)  {
    cuts.clear();
    int x0, y0, x1, y1;
    int rc = getCutter(x0, y0, x1, y1);
    if (rc == -1) {
        QMessageBox::critical(this, "Ошибка", "Неправильный формат входных данных.");
        return;
    }
    saveState();
    Line tmp;
    Square sq(x0, y0, x1, y1);
    for (auto line : lines) {
        if (line.visible(sq, tmp)) {
            cuts.push_back(tmp);
        }
    }
    repaint();
}

void MainWindow::on_discardButton_clicked(void) {
    if (state.can) {
        lines = state.lines;
        QString tmp = ui->figureBox->itemText(0);
        ui->figureBox->clear();
        ui->figureBox->addItem(tmp);
        int x0, y0, x1, y1;
        Dot d1, d2;
        for (auto line : lines) {
            line.get(d1, d2);
            d1.get(x0, y0);
            d2.get(x1, y1);
            tmp = QString(std::string("[" + std::to_string(x0) + ", " + std::to_string(y0) + "] [" + 
                                  std::to_string(x1) + ", " + std::to_string(y1) + "]").c_str());
            ui->figureBox->addItem(tmp);
        }
        ui->figureBox->setCurrentIndex(0);
        state.can = false;
        repaint();
    }
}

void MainWindow::on_discardAllButton_clicked(void) {
    saveState();
    lines.clear();
    QString tmp = ui->figureBox->itemText(0);
    ui->figureBox->clear();
    ui->figureBox->addItem(tmp);
    repaint();
}

void MainWindow::on_aboutButton_clicked(void) {
    QMessageBox::about(this, "О программе", 
    "Условие: Выполнить отсечение отрезков алгоритмом простого отсечения.\n"
    "Ограничение: Все числа целые (координаты задаются пикселями).\n"
    "Нажатия мыши: правая кнопка - первая точка, левая кнопка - вторая точка, нажатие колеса - переключение с ввода отрезков на ввод отсекателя и наоборот (по умолчанию сначала стоит ввод отрезков).");
}

void MainWindow::on_authorButton_clicked(void) {
    QMessageBox::about(this, "Об авторе", "Автор: Баранов Николай, группа ИУ7-45Б.");
}

void MainWindow::on_outButton_clicked(void) {
    this->close();
}

int MainWindow::getLine(int &x0, int &y0, int &x1, int &y1) {
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

int MainWindow::getCutter(int &x0, int &y0, int &x1, int &y1) {
    int rc = 0;
    QString sx0 = this->ui->lineEditX0_2->text();
    QString sy0 = this->ui->lineEditY0_2->text();
    QString sx1 = this->ui->lineEditX1_2->text();
    QString sy1 = this->ui->lineEditY1_2->text();
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

void MainWindow::mousePressEvent(QMouseEvent *event) {
    int canvasWidth = this->width() - 220;
    int canvasHeight = this->height();
    int canvasX = 220;
    int canvasY = 0;
    int cx = event->pos().x();
    int cy = event->pos().y();
    if (cx >= canvasX && cx <= canvasX + canvasWidth && 
        cy >= canvasY && cy <= canvasY + canvasHeight) {
        int posX = cx - canvasX;
        int posY = cy - canvasY;
        std::string tsx = std::to_string(posX);
        std::string tsy = std::to_string(posY);
        QString tmpX(tsx.c_str());
        QString tmpY(tsy.c_str());
        
        if (event->button() == Qt::LeftButton) {
            if (isCutter) {
                cuts.clear();
                this->ui->lineEditX0_2->setText(tmpX);
                this->ui->lineEditY0_2->setText(tmpY);
            }
            else {
                this->ui->lineEditX0->setText(tmpX);
                this->ui->lineEditY0->setText(tmpY);
            }
        } 
        else if (event->button() == Qt::RightButton) {
            if (isCutter) {
                cuts.clear();
                this->ui->lineEditX1_2->setText(tmpX);
                this->ui->lineEditY1_2->setText(tmpY);
            }
            else {
                this->ui->lineEditX1->setText(tmpX);
                this->ui->lineEditY1->setText(tmpY);
            }
        }
        else {
            isCutter = !(isCutter);
        }
    }
    repaint();
}

void MainWindow::saveState(void) {
    state.can = true;
    state.lines = lines;
    state.cuts = cuts;
}

