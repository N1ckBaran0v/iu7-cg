#include <string>
#include <cmath>

#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), 
                                          ui(new Ui::MainWindow), 
                                          image(new Image("input.txt")),
                                          lastAct(NONE),
                                          lastNums(0, 0) {
    this->ui->setupUi(this);
    Dot center(0, 0);
    this->image->scalingX(center, 10);
    this->image->scalingY(center, 10);
    this->ui->lineEditX->setText(QString("0"));
    this->ui->lineEditY->setText(QString("0"));
    this->ui->lineEditX_2->setText(QString("0"));
    this->ui->lineEditY_2->setText(QString("0"));
    this->ui->lineEditX_3->setText(QString("0"));
    this->ui->lineEditY_3->setText(QString("0"));
    this->ui->lineEditAngle->setText(QString("0"));
    this->ui->lineEditDX->setText(QString("1"));
    this->ui->lineEditDY->setText(QString("1"));
    this->repaint();
}

MainWindow::~MainWindow(void) {
    delete this->ui;
    delete this->image;
}

void MainWindow::paintEvent(QPaintEvent *pEvent) {
    QPainter p(this);
    int canvasWidth = this->width() - 220;
    int canvasHeight = this->height();
    int canvasX = 220;
    int canvasY = 0;
    p.fillRect(canvasX, canvasY, canvasWidth, canvasHeight, Qt::white);

    int canvasCenterX = canvasX + canvasWidth / 2;
    int canvasCenterY = canvasY + canvasHeight / 2;
    double x0, y0;
    Dot center(0, 0);

    double minX = -canvasWidth / 2.0;
    double maxX = (double)canvasX + canvasWidth - canvasCenterX;
    double minY = -canvasHeight / 2.0;
    double maxY = (double)canvasY + canvasHeight - canvasCenterY;

    p.setPen(QPen(Qt::lightGray, 1));
    int itXGrid = canvasX - (int)(round(minX)) % 10;
    for (; itXGrid < canvasX + canvasWidth; itXGrid += 10)
        p.drawLine(itXGrid, canvasY, itXGrid, canvasY + canvasHeight);
    int itYGrid = ((int)(round(maxY)) % 10 + 10) % 10 + canvasY;
    for (; itYGrid < canvasY + canvasHeight; itYGrid += 10)
        p.drawLine(canvasX, itYGrid, canvasX + canvasWidth, itYGrid);

    p.setPen(QPen(Qt::gray, 2));
    itXGrid = canvasX - (int)(round(minX)) % 100;
    for (; itXGrid < canvasX + canvasWidth; itXGrid += 100)
        p.drawLine(itXGrid, canvasY, itXGrid, canvasY + canvasHeight);
    itYGrid = ((int)(round(maxY)) % 100 + 100) % 100 + canvasY;
    for (; itYGrid < canvasY + canvasHeight; itYGrid += 100)
        p.drawLine(canvasX, itYGrid, canvasX + canvasWidth, itYGrid);

    p.setPen(QPen(Qt::darkGray, 3));
    if (!(minX > 0 || maxX < 0)) {
        itXGrid = canvasX + (int)round(-minX);
        p.drawLine(itXGrid, canvasY, itXGrid, canvasY + canvasHeight);
    }
    if (!(minY > 0 || maxY < 0)) {
        itYGrid = canvasY + (int)round(maxY);
        p.drawLine(canvasX, itYGrid, canvasX + canvasWidth, itYGrid);
    }

    p.setPen(QPen(Qt::black, 4));
    paintParams params = {canvasCenterX, canvasCenterY};
    this->image->draw(p, params);

    p.fillRect(0, 0, canvasX, this->height(), Qt::black);
}

void MainWindow::on_moveButton_clicked(void) {
    double x, y;
    int ret = this->getOffset(x, y);
    if (ret)
        QMessageBox::critical(this, "Ошибка", "Неправильный формат входных данных.");
    else {
        Vector2D offset(x, y);
        this->image->move(offset);
        this->lastAct = MOVE;
        this->lastNums.first = x;
        this->lastNums.second = y;
        this->repaint();
    }
}

void MainWindow::on_rotateButton_clicked(void) {
    double x, y, angle;
    int ret = this->getRotate(x, y, angle);
    if (ret)
        QMessageBox::critical(this, "Ошибка", "Неправильный формат входных данных.");
    else {
        Dot center(x, y);
        this->image->rotate(center, angle);
        this->lastAct = ROTATE;
        this->lastNums.first = x;
        this->lastNums.second = y;
        this->lastNums2.first = angle;
        this->repaint();
    }
}

void MainWindow::on_scaleImageButton_clicked(void) {
    double x, y, dx, dy;
    int ret = this->getScaling(x, y, dx, dy);
    if (ret == -1)
        QMessageBox::critical(this, "Ошибка", "Неправильный формат входных данных.");
    else if (ret == -2)
        QMessageBox::critical(this, "Ошибка", "Неправильный диапазон входных данных.");
    else {
        Dot center(x, y);
        this->image->scalingX(center, dx);
        this->image->scalingY(center, dy);
        this->lastAct = SCALING;
        this->lastNums.first = x;
        this->lastNums.second = y;
        this->lastNums2.first = dx;
        this->lastNums2.second = dy;
        this->repaint();
    }
}

void MainWindow::on_discardButton_clicked(void) {
    if (this->lastAct == MOVE) {
        double x, y;
        x = this->lastNums.first;
        y = this->lastNums.second;
        Vector2D offset(-x, -y);
        this->image->move(offset);
    }
    if (this->lastAct == ROTATE) {
        double x, y, angle;
        x = this->lastNums.first;
        y = this->lastNums.second;
        angle = this->lastNums2.first;
        Dot center(x, y);
        this->image->rotate(center, -angle);
    }
    if (this->lastAct == SCALING) {
        double x, y, dx, dy;
        x = this->lastNums.first;
        y = this->lastNums.second;
        dx = this->lastNums2.first;
        dy = this->lastNums2.second;
        Dot center(x, y);
        this->image->scalingX(center, 1 / dx);
        this->image->scalingY(center, 1 / dy);
    }
    if (this->lastAct != NONE) {
        this->lastAct = NONE;
        this->repaint();
    }
}

void MainWindow::on_discardAllButton_clicked(void) {
    delete this->image;
    this->image = new Image("input.txt");
    Dot center(0, 0);
    this->image->scalingX(center, 10);
    this->image->scalingY(center, 10);
    this->repaint();
}

void MainWindow::on_aboutButton_clicked(void) {
    QMessageBox::about(this, "О программе", 
    "Условие: Нарисовать исходный рисунок (автомобиль), затем его перенести, промаштабировать, повернуть.\n"
    "Формат входных данных: при переносе вводится вектор перемещения, задающийся двумя координатами в формате чисел с плавающей точкой, "
    "при повороте вводятся координаты центра вращения и угол в градусах, поворот осуществляется против часовой стрелки, "
    "при масштабировании вводятся 2 числа dx и dy, в которые изменится размер рисунка по осям (нельзя вводить 0 или отрицательные числа).");
}

void MainWindow::on_authorButton_clicked(void) {
    QMessageBox::about(this, "Об авторе", "Автор: Баранов Николай, группа ИУ7-45Б.");
}

void MainWindow::on_outButton_clicked(void) {
    this->close();
}

int MainWindow::getOffset(double &x, double &y) {
    int rc = 0;
    QString sx = this->ui->lineEditX->text();
    QString sy = this->ui->lineEditY->text();
    double xt = 0;
    double yt = 0;
    bool okX = false;
    bool okY = false;
    xt = sx.toDouble(&okX);
    yt = sy.toDouble(&okY);
    if (!(okX) || !(okY)) 
        rc = -1;
    else {
        x = xt;
        y = yt;
    }
    return rc;
}

int MainWindow::getRotate(double &x, double &y, double &angle) {
    int rc = 0;
    QString sx = this->ui->lineEditX_2->text();
    QString sy = this->ui->lineEditY_2->text();
    QString sangle = this->ui->lineEditAngle->text();
    double xt = 0;
    double yt = 0;
    double anglet = 0;
    bool okX = false;
    bool okY = false;
    bool okAngle = false;
    xt = sx.toDouble(&okX);
    yt = sy.toDouble(&okY);
    anglet = sangle.toDouble(&okAngle);
    if (!(okX) || !(okY) || !(okAngle)) 
        rc = -1;
    else {
        x = xt;
        y = yt;
        angle = anglet;
    }
    return rc;
}
int MainWindow::getScaling(double &x, double &y, double &dx, double &dy) {
    int rc = 0;
    QString sx = this->ui->lineEditX_3->text();
    QString sy = this->ui->lineEditY_3->text();
    QString skx = this->ui->lineEditDX->text();
    QString sky = this->ui->lineEditDY->text();
    double xt = 0;
    double yt = 0;
    double xkt = 0;
    double ykt = 0;
    bool okX = false;
    bool okY = false;
    bool okXk = false;
    bool okYk = false;
    xt = sx.toDouble(&okX);
    yt = sy.toDouble(&okY);
    xkt = skx.toDouble(&okXk);
    ykt = sky.toDouble(&okYk);
    if (!(okX) || !(okY) || !(okXk) || !(okYk)) 
        rc = -1;
    else if (xkt == 0 || ykt == 0)
        rc = -2;
    else {
        x = xt;
        y = yt;
        dx = xkt;
        dy = ykt;
    }
    return rc;
}
