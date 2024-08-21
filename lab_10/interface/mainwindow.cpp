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
                                          surfaceColor(Qt::black) {
    ui->setupUi(this);
    on_discardAllButton_clicked();
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
    p.setPen(QPen(surfaceColor, 1));
    ScreenParams screen = {canvasWidth, canvasHeight,canvasWidth / 2, canvasHeight / 2};
    field.floatingHorizon(p, screen);
    p.fillRect(0, 0, canvasX, this->height(), Qt::black);
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

void MainWindow::on_surfaceColorButton_clicked(void) {
    QColorDialog* q = new QColorDialog();
    q->open();
    surfaceColor = q->getColor();
    QString qss = QString("background-color: %1").arg(surfaceColor.name());
    ui->surfaceColorButton->setStyleSheet(qss);
    delete q;
    repaint();
}

void MainWindow::on_setButton_clicked(void) {
    double xmin, xmax, zmin, zmax;
    int rc = getEdges(xmin, xmax, zmin, zmax);
    if (rc == -1) {
        QMessageBox::critical(this, "Ошибка", "Неправильный формат входных данных.");
        return;
    }
    double dx, dz;
    rc = getDiff(dx, dz);
    if (rc == -1) {
        QMessageBox::critical(this, "Ошибка", "Неправильный формат входных данных.");
        return;
    }
    double xs, ys;
    rc = getScale(xs, ys);
    if (rc == -1) {
        QMessageBox::critical(this, "Ошибка", "Неправильный формат входных данных.");
        return;
    }
    prev tmp = saveState();
    rc = field.setX(xmin, xmax, dx);
    if (rc == -1) {
        QMessageBox::critical(this, "Ошибка", "dx слишком маленький, отрицательный или равен 0.");
        return;
    } 
    if (rc == -2) {
        QMessageBox::critical(this, "Ошибка", "xmin не может быть больше или равен xmax.");
        return;
    } 
    rc = field.setZ(zmin, zmax, dz);   
    if (rc == -1) {
        QMessageBox::critical(this, "Ошибка", "dz слишком маленький, отрицательный или равен 0.");
        return;
    } 
    if (rc == -2) {
        QMessageBox::critical(this, "Ошибка", "zmin не может быть больше или равен zmax.");
        return;
    } 
    state = tmp;
    field.setAngles(ui->sliderX->value(), ui->sliderY->value(), ui->sliderZ->value());
    field.setScale(xs, ys);
    const char *arr[] = {"flat", "sin", "x2z2"};
    field.setFunc(getFunc(arr[ui->comboBox->currentIndex()]));
    repaint();
}

void MainWindow::on_discardButton_clicked(void) {
    if (state.can) {
        state.can = false;
        field = state.field;
        repaint();
    }
}

void MainWindow::on_discardAllButton_clicked(void) {
    state = saveState();
    ui->lineEditXmin->setText(QString("-30"));
    ui->lineEditXmax->setText(QString("30"));
    ui->lineEditZmin->setText(QString("-20"));
    ui->lineEditZmax->setText(QString("20"));
    ui->lineEditDX->setText(QString("1"));
    ui->lineEditDZ->setText(QString("1"));
    ui->lineEditXS->setText(QString("10"));
    ui->lineEditYS->setText(QString("10"));
    QString qss = QString("background-color: %1").arg(fontColor.name());
    ui->fontColorButton->setStyleSheet(qss);
    qss = QString("background-color: %1").arg(surfaceColor.name());
    ui->surfaceColorButton->setStyleSheet(qss);
    ui->comboBox->setCurrentIndex(0);
    ui->sliderX->setValue(0);
    ui->sliderY->setValue(0);
    ui->sliderZ->setValue(0);
    on_setButton_clicked();
}

void MainWindow::on_aboutButton_clicked(void) {
    QMessageBox::about(this, "О программе", 
    "Условие: Разработать программу, позволяющую осуществлять ввод пределов и шага изменения координат x, z, выбора уравнения поверхности из заранее сформированного списка, построение поверхности. Должен быть обеспечен поворот поверхности вокруг каждой из трех координатных осей. Система коордиант должна быть неподвижной. Выполнить масштабирование для обеспечения размещения изображения целиком в пределах поля вывода.\n"
    "Ограничение: Все числа целые, либо с плавающей точкой, шаг не может быть 0 или отрицательным, минимальное значение должно быть меньше максимального.");
}

void MainWindow::on_authorButton_clicked(void) {
    QMessageBox::about(this, "Об авторе", "Автор: Баранов Николай, группа ИУ7-45Б.");
}

void MainWindow::on_outButton_clicked(void) {
    this->close();
}

void MainWindow::on_sliderX_valueChanged(void) {
    ui->labelOX->setText(QString(std::to_string(ui->sliderX->value()).c_str()));
}

void MainWindow::on_sliderY_valueChanged(void) {
    ui->labelOY->setText(QString(std::to_string(ui->sliderY->value()).c_str()));
}

void MainWindow::on_sliderZ_valueChanged(void) {
    ui->labelOZ->setText(QString(std::to_string(ui->sliderZ->value()).c_str()));
}

int MainWindow::getEdges(double &x0, double &x1, double &z0, double &z1) {
    int rc = 0;
    QString sx = this->ui->lineEditXmin->text();
    QString sy = this->ui->lineEditXmax->text();
    QString sz = this->ui->lineEditZmin->text();
    QString sw = this->ui->lineEditZmax->text();
    double xt = 0;
    double yt = 0;
    double zt = 0;
    double wt = 0;
    bool okX = false;
    bool okY = false;
    bool okZ = false;
    bool okW = false;
    xt = sx.toDouble(&okX);
    yt = sy.toDouble(&okY);
    zt = sz.toDouble(&okZ);
    wt = sw.toDouble(&okW);
    if (!(okX) || !(okY) || !(okZ) || !(okW)) 
        rc = -1;
    else {
        x0 = xt;
        x1 = yt;
        z0 = zt;
        z1 = wt;
    }
    return rc;
}

int MainWindow::getDiff(double &dx, double &dz) {
    int rc = 0;
    QString sx = this->ui->lineEditDX->text();
    QString sy = this->ui->lineEditDZ->text();
    double xt = 0;
    double yt = 0;
    bool okX = false;
    bool okY = false;
    xt = sx.toDouble(&okX);
    yt = sy.toDouble(&okY);
    if (!(okX) || !(okY)) 
        rc = -1;
    else {
        dx = xt;
        dz = yt;
    }
    return rc;
}

int MainWindow::getScale(double &xs, double &ys) {
    int rc = 0;
    QString sx = this->ui->lineEditXS->text();
    QString sy = this->ui->lineEditYS->text();
    double xt = 0;
    double yt = 0;
    bool okX = false;
    bool okY = false;
    xt = sx.toDouble(&okX);
    yt = sy.toDouble(&okY);
    if (!(okX) || !(okY)) 
        rc = -1;
    else {
        xs = xt;
        ys = yt;
    }
    return rc;
}

prev MainWindow::saveState() {
    prev ret;
    ret.can = true;
    ret.field = field;
    return ret;
}
