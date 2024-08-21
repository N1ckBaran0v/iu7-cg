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
    this->ui->lineEditX1->setText(QString("0"));
    this->ui->lineEditY1->setText(QString("0"));
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
    int x0, y0, x1, y1;
    Dot d1, d2;
    p.setPen(QPen(cutterColor, 1));
    for (size_t i = 0; i < cutter.size(); ++i) {
        d1 = cutter[i];
        d2 = cutter[i + 1];
        d1.get(x0, y0);
        d2.get(x1, y1);
        x0 += canvasX;
        y0 += canvasY;
        x1 += canvasX;
        y1 += canvasY;
        p.drawLine(x0, y0, x1, y1);
    }
    Cutter *cutptr = nullptr;
    if (needCut) {
        cutptr = &cutter;
    }
    for (auto line : lines) {
        line.draw(p, canvasX, canvasY, lineColor, resultColor, cutptr);
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
    int x0, y0, x1, y1;
    int rc = getLine(x0, y0, x1, y1);
    if (rc == -1) {
        QMessageBox::critical(this, "Ошибка", "Неправильный формат входных данных.");
        return;
    }
    saveState();
    if (needCut) {
        cutter = Cutter();
        QString tmp;
        tmp = ui->cutterBox->itemText(0);
        ui->cutterBox->clear();
        ui->cutterBox->addItem(tmp);
    }
    needCut = false;
    lines.push_back(Line(Dot(x0, y0), Dot(x1, y1)));
    QString tmp(std::string("[" + std::to_string(x0) + ", " + std::to_string(y0) + "] [" + 
                                  std::to_string(x1) + ", " + std::to_string(y1) + "]").c_str());
    ui->lineBox->addItem(tmp);
    repaint();
}

void MainWindow::on_delButton_clicked(void) {
    int ind = ui->lineBox->currentIndex();
    if (ind == 0) {
        QMessageBox::critical(this, "Ошибка", "Не выбрана линия для удаления.");
        return;
    }
    saveState();
    if (needCut) {
        cutter = Cutter();
        QString tmp;
        tmp = ui->cutterBox->itemText(0);
        ui->cutterBox->clear();
        ui->cutterBox->addItem(tmp);
    }
    needCut = false;
    for (size_t i = ind; i < lines.size(); ++i) {
        lines[i - 1] = lines[i];
    }
    lines.pop_back();
    ui->lineBox->removeItem(ind);
    if (ui->lineBox->count() == ind) {
        ind--;
    }
    ui->lineBox->setCurrentIndex(ind);
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
        cutter = Cutter();
        QString tmp;
        tmp = ui->cutterBox->itemText(0);
        ui->cutterBox->clear();
        ui->cutterBox->addItem(tmp);
    }
    needCut = false;
    Dot tmpdot(x, y);
    cutter.add(tmpdot);
    QString tmp(std::string("[" + std::to_string(x) + ", " + std::to_string(y) + "]").c_str());
    ui->cutterBox->addItem(tmp);
    repaint();
}

void MainWindow::on_delDotButton_clicked(void) {
    int ind = ui->cutterBox->currentIndex();
    if (ind == 0) {
        QMessageBox::critical(this, "Ошибка", "Не выбрана линия для удаления.");
        return;
    }
    saveState();
    if (needCut) {
        cutter = Cutter();
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
    int rc = cutter.check();
    if (rc == -1) {
        QMessageBox::critical(this, "Ошибка", "Нет отсекателя.");
        return;
    }
    if (rc == -2) {
        QMessageBox::critical(this, "Ошибка", "Одна точка не может быть отсекателем.");
        return;
    }
    if (rc == -3) {
        QMessageBox::critical(this, "Ошибка", "Отрезок не является отсекателем.");
        return;
    }
    if (rc == -4) {
        QMessageBox::critical(this, "Ошибка", "Отсекатель не выпуклый или содержит самопересечения.");
        return;
    }
    saveState();
    needCut = true;
    repaint();
}

void MainWindow::on_discardButton_clicked(void) {
    if (state.can) {
        state.can = false;
        lines = state.lines;
        cutter = state.cutter;
        needCut = state.needCut;
        boxesSet(state.cind0, state.cind1);
        repaint();
    }
}

void MainWindow::on_discardAllButton_clicked(void) {
    saveState();
    lines.clear();
    needCut = false;
    cutter = Cutter();
    boxesSet(0, 0);
    repaint();
}

void MainWindow::on_aboutButton_clicked(void) {
    QMessageBox::about(this, "О программе", 
    "Условие: Выполнить отсечение отрезков алгоритмом Кируса-Бека.\n"
    "Ограничение: Все числа целые (координаты задаются пикселями), отсекатель должен быть выпуклым и не должен содержать самопересечения.\n"
    "Нажатия мыши: ЛКМ - ввод первой точки отрезка, ПКМ - ввод второй токи отрезка и его отрисовка, колесо - добаление точки для отсекателя.");
}

void MainWindow::on_authorButton_clicked(void) {
    QMessageBox::about(this, "Об авторе", "Автор: Баранов Николай, группа ИУ7-45Б.");
}

void MainWindow::on_outButton_clicked(void) {
    this->close();
}

int MainWindow::getDot(int &x, int &y) {
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
            this->ui->lineEditX0->setText(tmpX);
            this->ui->lineEditY0->setText(tmpY);
        } 
        else if (event->button() == Qt::RightButton) {
            this->ui->lineEditX1->setText(tmpX);
            this->ui->lineEditY1->setText(tmpY);
            on_addButton_clicked();
        }
        else {
            this->ui->lineEditXC->setText(tmpX);
            this->ui->lineEditYC->setText(tmpY);
            on_addDotButton_clicked();
        }
    }
}

void MainWindow::saveState(void) {
    state.can = true;
    state.lines = lines;
    state.cutter = cutter;
    state.needCut = needCut;
    state.cind0 = ui->lineBox->currentIndex();
    state.cind1 = ui->cutterBox->currentIndex();
}

void MainWindow::boxesSet(int cind0, int cind1) {
    int x0, y0, x1, y1;
    Dot d1, d2;
    QString tmp = ui->lineBox->itemText(0);
    ui->lineBox->clear();
    ui->lineBox->addItem(tmp);
    for (auto line : lines) {
        line.get(d1, d2);
        d1.get(x0, y0);
        d2.get(x1, y1);
        tmp = QString(std::string("[" + std::to_string(x0) + ", " + std::to_string(y0) + "] [" + 
                              std::to_string(x1) + ", " + std::to_string(y1) + "]").c_str());
        ui->lineBox->addItem(tmp);
    }
    ui->lineBox->setCurrentIndex(cind0);
    tmp = ui->cutterBox->itemText(0);
    ui->cutterBox->clear();
    ui->cutterBox->addItem(tmp);
    for (size_t i = 0; i < cutter.size(); ++i) {
        cutter[i].get(x0, y0);
        tmp = QString(std::string("[" + std::to_string(x0) + ", " + std::to_string(y0) + "]").c_str());
        ui->cutterBox->addItem(tmp);
    }
    ui->cutterBox->setCurrentIndex(cind1);
}
