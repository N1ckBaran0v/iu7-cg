#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
#include <iostream>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), 
                                          ui(new Ui::MainWindow),
                                          field(),
                                          fontColor(Qt::white),
                                          linesColor(Qt::black),
                                          fillColor(Qt::gray),
                                          needFill(false)/*, 
                                          ,
                                          lines(),
                                          LastCnt(0)*/ {
    ui->setupUi(this);
    this->ui->lineEditX->setText(QString("0"));
    this->ui->lineEditY->setText(QString("0"));
    QString qss = QString("background-color: %1").arg(linesColor.name());
    ui->lineColorButton->setStyleSheet(qss);
    qss = QString("background-color: %1").arg(fontColor.name());
    ui->fontColorButton->setStyleSheet(qss);
    qss = QString("background-color: %1").arg(fillColor.name());
    ui->fillColorButton->setStyleSheet(qss);
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
    p.fillRect(canvasX, canvasY, canvasWidth, canvasHeight, this->fontColor);
    QImage img(canvasWidth, canvasHeight, QImage::Format_ARGB32);
    img.fill(fontColor);
    if (needDelay != -1) {
        delayOut dout;
        dout.curcnt = needDelay;
        dout.maxcnt = needDelay;
        field.draw(img, canvasWidth, canvasHeight, fontColor, linesColor, fillColor, needFill, &dout);
        if (dout.maxcnt >= 0) {
            needDelay = -1;
        }
        else {
            ++needDelay;
        }
    }
    else {
        double tmpTime = field.draw(img, canvasWidth, canvasHeight, fontColor, linesColor, fillColor, needFill);
        if (needFill) {
            lastTime = int(round(tmpTime));
        }
    }
    QPixmap pix;
    pix.convertFromImage(img);
    p.drawPixmap(canvasX, canvasY, pix);
    p.fillRect(0, 0, canvasX, this->height(), Qt::black);
}

void MainWindow::on_lineColorButton_clicked(void) {
    QColorDialog* q = new QColorDialog();
    q->open();
    linesColor = q->getColor();
    QString qss = QString("background-color: %1").arg(linesColor.name());
    ui->lineColorButton->setStyleSheet(qss);
    delete q;
}

void MainWindow::on_fillColorButton_clicked(void) {
    QColorDialog* q = new QColorDialog();
    q->open();
    fillColor = q->getColor();
    QString qss = QString("background-color: %1").arg(fillColor.name());
    ui->fillColorButton->setStyleSheet(qss);
    delete q;
}

void MainWindow::on_fontColorButton_clicked(void) {
    QColorDialog* q = new QColorDialog();
    q->open();
    fontColor = q->getColor();
    QString qss = QString("background-color: %1").arg(fontColor.name());
    ui->fontColorButton->setStyleSheet(qss);
    delete q;
}

void MainWindow::on_addDotButton_clicked(void) {
    needFill = false;
    int x, y;
    int rc = getDot(x, y);
    if (rc == -1) {
        QMessageBox::critical(this, "Ошибка", "Неправильный формат входных данных.");
        return;
    }
    saveState();
    if (ui->figureBox->currentIndex() == 0) {
        int ind = ui->figureBox->count();
        field.addFigure(Dot(x, y));
        std::string str = std::to_string(ind);
        QString qstr = str.c_str();
        ui->figureBox->addItem(qstr);
        ui->figureBox->setCurrentIndex(ind);
    }
    else {
        int ind = ui->figureBox->currentIndex() - 1;
        field.addDot(Dot(x, y), ind);
    }
    setDotBox();
    repaint();
}

void MainWindow::on_delDotButton_clicked(void) {
    needFill = false;
    int ind0 = ui->figureBox->currentIndex();
    if (ind0 == 0) {
        QMessageBox::critical(this, "Ошибка", "Не выбрана фигура.");
        return;
    }
    int ind1 = ui->dotBox->currentIndex();
    if (ind1 == 0) {
        QMessageBox::critical(this, "Ошибка", "Не выбрана точка.");
        return;
    }
    saveState();
    field.delDot(ind1 - 1, ind0 - 1);
    if (ui->dotBox->count() == 2) {
        ui->figureBox->removeItem(ind0);
        if (ui->figureBox->count() == ind0) {
            ind0--;
        }
        ui->figureBox->setCurrentIndex(ind0);
        ui->dotBox->setCurrentIndex(0);
    }
    else {
        setDotBox();
        if (ui->dotBox->count() == ind1) {
            ind1--;
        }
        ui->dotBox->setCurrentIndex(ind1);
    }
    repaint();
}

void MainWindow::on_fillButton_clicked(void) {
    saveState();
    needFill = true;
    if (ui->checkBox->checkState() == Qt::Checked) {
        needDelay = 1;
        while (needDelay != -1) {
            repaint();
        }
        return;
    }
    repaint();
}

void MainWindow::on_analyseButton_clicked(void) {
    if (lastTime == -1) {
        QMessageBox::critical(this, "Ошибка", "Фигура ни разу не заполнялась без задержки.");
        return;
    }
    std::string tmp = "Время последней отрисовки изображения: " + std::to_string(lastTime) + " мс";
    QMessageBox::about(this, "Измерение", tmp.c_str());
}

void MainWindow::on_discardButton_clicked(void) {
    if (state.can) {
        state.can = false;
        field = state.field;
        needFill = state.needFill;
        QString tmp = ui->figureBox->itemText(0);
        ui->figureBox->clear();
        ui->figureBox->addItem(tmp);
        for (const auto item : state.vals) {
            ui->figureBox->addItem(item);
        }
        ui->figureBox->setCurrentIndex(state.cind0);
        ui->dotBox->setCurrentIndex(state.cind1);
    }
    repaint();
}

void MainWindow::on_discardAllButton_clicked(void) {
    field = Field();
    needFill = false;
    QString tmp = ui->figureBox->itemText(0);
    ui->figureBox->clear();
    ui->figureBox->addItem(tmp);
    repaint();
}

void MainWindow::on_aboutButton_clicked(void) {
    QMessageBox::about(this, "О программе", 
    "Условие: Реализовать заполнение произвольного многоугольника с произвольным количеством отверстий алгоритмом заполнения со списком ребер и флагом.\n"
    "Ограничение: Все числа целые (координаты задаются пикселями).");
}

void MainWindow::on_authorButton_clicked(void) {
    QMessageBox::about(this, "Об авторе", "Автор: Баранов Николай, группа ИУ7-45Б.");
}

void MainWindow::on_outButton_clicked(void) {
    this->close();
}

void MainWindow::on_figureBox_currentIndexChanged(void) {
    setDotBox();
}

void MainWindow::setDotBox(void) {
    QString tmp = ui->dotBox->itemText(0);
    ui->dotBox->clear();
    ui->dotBox->addItem(tmp);
    if (ui->figureBox->count() == 0) {
        return;
    }
    int ind = ui->figureBox->currentIndex();
    if (ind != 0) {
        Figure curr = field[ind - 1];
        int x, y;
        for (size_t i = 0; i < curr.size(); ++i) {
            curr[i].get(x, y);
            tmp = std::string(std::to_string(x) + " " + std::to_string(y)).c_str();
            ui->dotBox->addItem(tmp);
        }
    }
    ind = ui->dotBox->count() - 1;
    ui->dotBox->setCurrentIndex(ind);
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
        if (event->button() == Qt::LeftButton || event->button() == Qt::RightButton) {
            QString prevX = ui->lineEditX->text();
            QString prevY = ui->lineEditY->text();
            this->ui->lineEditX->setText(tmpX);
            this->ui->lineEditY->setText(tmpY);
            if (event->button() == Qt::LeftButton) {
                on_addDotButton_clicked();
                this->ui->lineEditX->setText(prevX);
                this->ui->lineEditY->setText(prevY);
            }
        } 
    }
}

void MainWindow::saveState(void) {
    state.can = true;
    state.field = field;
    state.needFill = needFill;
    state.vals.clear();
    for (size_t i = 1; i < ui->figureBox->count(); ++i) {
        state.vals.push_back(ui->figureBox->itemText(i));
    }
    state.cind0 = ui->figureBox->currentIndex();
    state.cind1 = ui->dotBox->currentIndex();
}
