#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
#include <iostream>

#include "figure.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), 
                                          ui(new Ui::MainWindow),
                                          fontColor(Qt::white),
                                          lineColor(Qt::black),
                                          cutterColor(Qt::red),
                                          resultColor(Qt::green) {
    ui->setupUi(this);
    this->ui->lineEditX->setText(QString("0"));
    this->ui->lineEditY->setText(QString("0"));
    this->ui->lineEditXC->setText(QString("0"));
    this->ui->lineEditYC->setText(QString("0"));
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
    p.setPen(QPen(lineColor, 1));
    for (size_t i = 0; i < figure.size(); ++i) {
        p.drawLine(figure[i].first + canvasX, figure[i].second + canvasY, 
                   figure[i + 1].first + canvasX, figure[i + 1].second + canvasY);
    }
    p.setPen(QPen(cutterColor, 1));
    for (size_t i = 0; i < cutter.size(); ++i) {
        p.drawLine(cutter[i].first + canvasX, cutter[i].second + canvasY, 
                   cutter[i + 1].first + canvasX, cutter[i + 1].second + canvasY);
    }
    if (needCut) {
        p.setPen(QPen(resultColor, 1));
        Figure resultFigure = figure.cut(cutter);
        for (size_t i = 0; i < resultFigure.size(); ++i) {
            p.drawLine(resultFigure[i].first + canvasX, resultFigure[i].second + canvasY, 
                       resultFigure[i + 1].first + canvasX, resultFigure[i + 1].second + canvasY);
        }
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

void MainWindow::on_addDotButton_clicked(void) {
    int x, y;
    int rc = getDot(x, y);
    if (rc == -1) {
        QMessageBox::critical(this, "Ошибка", "Неправильный формат входных данных.");
        return;
    }
    saveState();
    if (needCut) {
        cutter = Figure();
        QString tmp;
        tmp = ui->cutterBox->itemText(0);
        ui->cutterBox->clear();
        ui->cutterBox->addItem(tmp);
    }
    needCut = false;
    std::pair<int, int> tmpPair;
    tmpPair.first = x;
    tmpPair.second = y;
    figure.add(tmpPair);
    QString tmp(std::string("[" + std::to_string(x) + ", " + std::to_string(y) + "]").c_str());
    ui->figureBox->addItem(tmp);
    repaint();
}

void MainWindow::on_delDotButton_clicked(void) {
    int ind = ui->figureBox->currentIndex();
    if (ind == 0) {
        QMessageBox::critical(this, "Ошибка", "Не выбрана точка для удаления.");
        return;
    }
    saveState();
    if (needCut) {
        cutter = Figure();
        QString tmp;
        tmp = ui->cutterBox->itemText(0);
        ui->cutterBox->clear();
        ui->cutterBox->addItem(tmp);
    }
    needCut = false;
    figure.remove(ind - 1);
    ui->figureBox->removeItem(ind);
    if (ui->figureBox->count() == ind) {
        ind--;
    }
    ui->figureBox->setCurrentIndex(ind);
    repaint();
}

void MainWindow::on_addDotCutterButton_clicked(void) {
    int x, y;
    int rc = getDotCutter(x, y);
    if (rc == -1) {
        QMessageBox::critical(this, "Ошибка", "Неправильный формат входных данных.");
        return;
    }
    saveState();
    if (needCut) {
        cutter = Figure();
        QString tmp;
        tmp = ui->cutterBox->itemText(0);
        ui->cutterBox->clear();
        ui->cutterBox->addItem(tmp);
    }
    needCut = false;
    std::pair<int, int> tmpPair;
    tmpPair.first = x;
    tmpPair.second = y;
    cutter.add(tmpPair);
    QString tmp(std::string("[" + std::to_string(x) + ", " + std::to_string(y) + "]").c_str());
    ui->cutterBox->addItem(tmp);
    repaint();
}

void MainWindow::on_delDotCutterButton_clicked(void) {
    int ind = ui->cutterBox->currentIndex();
    if (ind == 0) {
        QMessageBox::critical(this, "Ошибка", "Не выбрана точка для удаления.");
        return;
    }
    saveState();
    if (needCut) {
        cutter = Figure();
        QString tmp;
        tmp = ui->cutterBox->itemText(0);
        ui->cutterBox->clear();
        ui->cutterBox->addItem(tmp);
    }
    needCut = false;
    cutter.remove(ind - 1);
    ui->cutterBox->removeItem(ind);
    if (ui->cutterBox->count() == ind) {
        ind--;
    }
    ui->cutterBox->setCurrentIndex(ind);
    repaint();
}

void MainWindow::on_cutterButton_clicked(void) {
    if (cutter.empty()) {
        QMessageBox::critical(this, "Ошибка", "Нет отсекателя.");
        saveState();
        cutter = Figure();
        QString tmp;
        tmp = ui->cutterBox->itemText(0);
        ui->cutterBox->clear();
        ui->cutterBox->addItem(tmp);
        return;
    }
    if (cutter.size() == 1) {
        QMessageBox::critical(this, "Ошибка", "Одна точка не может быть отсекателем.");
        saveState();
        cutter = Figure();
        QString tmp;
        tmp = ui->cutterBox->itemText(0);
        ui->cutterBox->clear();
        ui->cutterBox->addItem(tmp);
        return;
    }
    if (cutter.size() == 2) {
        QMessageBox::critical(this, "Ошибка", "Отрезок не является отсекателем.");
        saveState();
        cutter = Figure();
        QString tmp;
        tmp = ui->cutterBox->itemText(0);
        ui->cutterBox->clear();
        ui->cutterBox->addItem(tmp);
        return;
    }
    if (!(cutter.convex())) {
        QMessageBox::critical(this, "Ошибка", "Отсекатель не выпуклый или есть самопересечения.");
        saveState();
        cutter = Figure();
        QString tmp;
        tmp = ui->cutterBox->itemText(0);
        ui->cutterBox->clear();
        ui->cutterBox->addItem(tmp);
        return;
    }
    saveState();
    needCut = true;
    repaint();
}

void MainWindow::on_discardButton_clicked(void) {
    if (state.can) {
        state.can = false;
        figure = state.figure;
        cutter = state.cutter;
        needCut = state.needCut;
        boxesSet(state.cind0, state.cind1);
        repaint();
    }
}

void MainWindow::on_discardAllButton_clicked(void) {
    saveState();
    figure = Figure();
    needCut = false;
    cutter = Figure();
    boxesSet(0, 0);
    repaint();
}

void MainWindow::on_aboutButton_clicked(void) {
    QMessageBox::about(this, "О программе", 
    "Условие: Выполнить отсечение многоугольника алгоритмом Сазерленда-Ходжмена.\n"
    "Ограничение: Все числа целые (координаты задаются пикселями), отсекатель должен быть выпуклым и не должно быть самопересечений.\n"
    "Нажатия мыши: ЛКМ - добавление точки для многоугольника, ПКМ - добаление точки для отсекателя.");
}

void MainWindow::on_authorButton_clicked(void) {
    QMessageBox::about(this, "Об авторе", "Автор: Баранов Николай, группа ИУ7-45Б.");
}

void MainWindow::on_outButton_clicked(void) {
    this->close();
}

int MainWindow::getDot(int &x, int &y) {
    int rc = 0;
    QString sx = this->ui->lineEditX->text();
    QString sy = this->ui->lineEditY->text();
    int xt = 0;
    int yt = 0;
    bool okX = false;
    bool okY = false;
    xt = sx.toInt(&okX);
    yt = sy.toInt(&okY);
    if (!(okX) || !(okY)) 
        rc = -1;
    else {
        x = xt;
        y = yt;
    }
    return rc;
}

int MainWindow::getDotCutter(int &x, int &y) {
    int rc = 0;
    QString sx = this->ui->lineEditXC->text();
    QString sy = this->ui->lineEditYC->text();
    int xt = 0;
    int yt = 0;
    bool okX = false;
    bool okY = false;
    xt = sx.toInt(&okX);
    yt = sy.toInt(&okY);
    if (!(okX) || !(okY)) 
        rc = -1;
    else {
        x = xt;
        y = yt;
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
            this->ui->lineEditX->setText(tmpX);
            this->ui->lineEditY->setText(tmpY);
            on_addDotButton_clicked();
        } 
        else if (event->button() == Qt::RightButton) {
            this->ui->lineEditXC->setText(tmpX);
            this->ui->lineEditYC->setText(tmpY);
            on_addDotCutterButton_clicked();
        }
    }
}

void MainWindow::saveState(void) {
    state.can = true;
    state.figure = figure;
    state.cutter = cutter;
    state.needCut = needCut;
    state.cind0 = ui->figureBox->currentIndex();
    state.cind1 = ui->cutterBox->currentIndex();
}

void MainWindow::boxesSet(int cind0, int cind1) {
    QString tmp = ui->figureBox->itemText(0);
    ui->figureBox->clear();
    ui->figureBox->addItem(tmp);
    for (size_t i = 0; i < figure.size(); ++i) {
        tmp = QString(std::string("[" + std::to_string(figure[i].first) + ", " + std::to_string(figure[i].second) + "]").c_str());
        ui->figureBox->addItem(tmp);
    }
    ui->figureBox->setCurrentIndex(cind0);
    tmp = ui->cutterBox->itemText(0);
    ui->cutterBox->clear();
    ui->cutterBox->addItem(tmp);
    for (size_t i = 0; i < cutter.size(); ++i) {
        tmp = QString(std::string("[" + std::to_string(cutter[i].first) + ", " + std::to_string(cutter[i].second) + "]").c_str());
        ui->cutterBox->addItem(tmp);
    }
    ui->cutterBox->setCurrentIndex(cind0);
}

