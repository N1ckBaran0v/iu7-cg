/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_0;
    QSpacerItem *horizontalSpacer;
    QLabel *label_1;
    QPushButton *lineColorButton;
    QLabel *label_2;
    QPushButton *fontColorButton;
    QLabel *label_8;
    QComboBox *comboBox;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEditX0;
    QLabel *label_5;
    QLineEdit *lineEditY0;
    QLabel *label_6;
    QLineEdit *lineEditX1;
    QLabel *label_7;
    QLineEdit *lineEditY1;
    QPushButton *drawLineButton;
    QLabel *label_9;
    QLabel *label_13;
    QLineEdit *lineEditX;
    QLabel *label_12;
    QLineEdit *lineEditY;
    QLabel *label_10;
    QLineEdit *lineEditStep;
    QLabel *label_11;
    QLineEdit *lineEditLen;
    QPushButton *drawLinesButton;
    QPushButton *analyseButton;
    QPushButton *analyseButton_2;
    QPushButton *discardButton;
    QPushButton *discardAllButton;
    QSpacerItem *verticalSpacer;
    QPushButton *aboutButton;
    QPushButton *authorButton;
    QPushButton *outButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(960, 609);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(960, 560));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        MainWindow->setTabShape(QTabWidget::Triangular);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setContextMenuPolicy(Qt::NoContextMenu);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_0 = new QLabel(centralwidget);
        label_0->setObjectName(QString::fromUtf8("label_0"));
        label_0->setEnabled(true);
        label_0->setMinimumSize(QSize(171, 16));
        label_0->setMaximumSize(QSize(171, 16));
        label_0->setAutoFillBackground(false);
        label_0->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_0, 0, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(731, 444, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 4, 19, 1);

        label_1 = new QLabel(centralwidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setEnabled(true);
        label_1->setMinimumSize(QSize(111, 16));
        label_1->setMaximumSize(QSize(111, 16));
        label_1->setAutoFillBackground(false);
        label_1->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_1, 1, 0, 1, 3);

        lineColorButton = new QPushButton(centralwidget);
        lineColorButton->setObjectName(QString::fromUtf8("lineColorButton"));
        lineColorButton->setMinimumSize(QSize(51, 21));
        lineColorButton->setMaximumSize(QSize(51, 21));
        lineColorButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(lineColorButton, 1, 3, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(111, 16));
        label_2->setMaximumSize(QSize(111, 16));
        label_2->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_2, 2, 0, 1, 3);

        fontColorButton = new QPushButton(centralwidget);
        fontColorButton->setObjectName(QString::fromUtf8("fontColorButton"));
        fontColorButton->setMinimumSize(QSize(51, 21));
        fontColorButton->setMaximumSize(QSize(51, 21));
        fontColorButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(fontColorButton, 2, 3, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(171, 16));
        label_8->setMaximumSize(QSize(171, 16));
        label_8->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_8, 3, 0, 1, 4);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(171, 21));
        comboBox->setMaximumSize(QSize(171, 21));

        gridLayout->addWidget(comboBox, 4, 0, 1, 4);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(171, 16));
        label_3->setMaximumSize(QSize(171, 16));
        label_3->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_3, 5, 0, 1, 4);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setEnabled(true);
        label_4->setMinimumSize(QSize(31, 16));
        label_4->setMaximumSize(QSize(31, 16));
        label_4->setAutoFillBackground(false);
        label_4->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        lineEditX0 = new QLineEdit(centralwidget);
        lineEditX0->setObjectName(QString::fromUtf8("lineEditX0"));
        lineEditX0->setMinimumSize(QSize(111, 16));
        lineEditX0->setMaximumSize(QSize(111, 16));

        gridLayout->addWidget(lineEditX0, 6, 1, 1, 3);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setEnabled(true);
        label_5->setMinimumSize(QSize(31, 16));
        label_5->setMaximumSize(QSize(31, 16));
        label_5->setAutoFillBackground(false);
        label_5->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        lineEditY0 = new QLineEdit(centralwidget);
        lineEditY0->setObjectName(QString::fromUtf8("lineEditY0"));
        lineEditY0->setMinimumSize(QSize(111, 16));
        lineEditY0->setMaximumSize(QSize(111, 16));

        gridLayout->addWidget(lineEditY0, 7, 1, 1, 3);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setEnabled(true);
        label_6->setMinimumSize(QSize(31, 16));
        label_6->setMaximumSize(QSize(31, 16));
        label_6->setAutoFillBackground(false);
        label_6->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_6, 8, 0, 1, 1);

        lineEditX1 = new QLineEdit(centralwidget);
        lineEditX1->setObjectName(QString::fromUtf8("lineEditX1"));
        lineEditX1->setMinimumSize(QSize(111, 16));
        lineEditX1->setMaximumSize(QSize(111, 16));

        gridLayout->addWidget(lineEditX1, 8, 1, 1, 3);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setEnabled(true);
        label_7->setMinimumSize(QSize(31, 16));
        label_7->setMaximumSize(QSize(31, 16));
        label_7->setAutoFillBackground(false);
        label_7->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_7, 9, 0, 1, 1);

        lineEditY1 = new QLineEdit(centralwidget);
        lineEditY1->setObjectName(QString::fromUtf8("lineEditY1"));
        lineEditY1->setMinimumSize(QSize(111, 16));
        lineEditY1->setMaximumSize(QSize(111, 16));

        gridLayout->addWidget(lineEditY1, 9, 1, 1, 3);

        drawLineButton = new QPushButton(centralwidget);
        drawLineButton->setObjectName(QString::fromUtf8("drawLineButton"));
        drawLineButton->setMinimumSize(QSize(171, 21));
        drawLineButton->setMaximumSize(QSize(171, 21));
        drawLineButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(drawLineButton, 10, 0, 1, 4);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(171, 16));
        label_9->setMaximumSize(QSize(171, 16));
        label_9->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_9, 11, 0, 1, 4);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setEnabled(true);
        label_13->setMinimumSize(QSize(51, 16));
        label_13->setMaximumSize(QSize(51, 16));
        label_13->setAutoFillBackground(false);
        label_13->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_13, 12, 0, 1, 2);

        lineEditX = new QLineEdit(centralwidget);
        lineEditX->setObjectName(QString::fromUtf8("lineEditX"));
        lineEditX->setMinimumSize(QSize(111, 16));
        lineEditX->setMaximumSize(QSize(111, 16));

        gridLayout->addWidget(lineEditX, 12, 2, 1, 2);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setEnabled(true);
        label_12->setMinimumSize(QSize(51, 16));
        label_12->setMaximumSize(QSize(51, 16));
        label_12->setAutoFillBackground(false);
        label_12->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_12, 13, 0, 1, 2);

        lineEditY = new QLineEdit(centralwidget);
        lineEditY->setObjectName(QString::fromUtf8("lineEditY"));
        lineEditY->setMinimumSize(QSize(111, 16));
        lineEditY->setMaximumSize(QSize(111, 16));

        gridLayout->addWidget(lineEditY, 13, 2, 1, 2);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setEnabled(true);
        label_10->setMinimumSize(QSize(51, 16));
        label_10->setMaximumSize(QSize(51, 16));
        label_10->setAutoFillBackground(false);
        label_10->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_10, 14, 0, 1, 2);

        lineEditStep = new QLineEdit(centralwidget);
        lineEditStep->setObjectName(QString::fromUtf8("lineEditStep"));
        lineEditStep->setMinimumSize(QSize(111, 16));
        lineEditStep->setMaximumSize(QSize(111, 16));

        gridLayout->addWidget(lineEditStep, 14, 2, 1, 2);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setEnabled(true);
        label_11->setMinimumSize(QSize(51, 16));
        label_11->setMaximumSize(QSize(51, 16));
        label_11->setAutoFillBackground(false);
        label_11->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_11, 15, 0, 1, 2);

        lineEditLen = new QLineEdit(centralwidget);
        lineEditLen->setObjectName(QString::fromUtf8("lineEditLen"));
        lineEditLen->setMinimumSize(QSize(111, 16));
        lineEditLen->setMaximumSize(QSize(111, 16));

        gridLayout->addWidget(lineEditLen, 15, 2, 1, 2);

        drawLinesButton = new QPushButton(centralwidget);
        drawLinesButton->setObjectName(QString::fromUtf8("drawLinesButton"));
        drawLinesButton->setMinimumSize(QSize(171, 21));
        drawLinesButton->setMaximumSize(QSize(171, 21));
        drawLinesButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(drawLinesButton, 16, 0, 1, 4);

        analyseButton = new QPushButton(centralwidget);
        analyseButton->setObjectName(QString::fromUtf8("analyseButton"));
        analyseButton->setMinimumSize(QSize(171, 21));
        analyseButton->setMaximumSize(QSize(171, 21));
        analyseButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(analyseButton, 17, 0, 1, 4);

        analyseButton_2 = new QPushButton(centralwidget);
        analyseButton_2->setObjectName(QString::fromUtf8("analyseButton_2"));
        analyseButton_2->setMinimumSize(QSize(171, 21));
        analyseButton_2->setMaximumSize(QSize(171, 21));
        analyseButton_2->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(analyseButton_2, 18, 0, 1, 4);

        discardButton = new QPushButton(centralwidget);
        discardButton->setObjectName(QString::fromUtf8("discardButton"));
        discardButton->setMinimumSize(QSize(171, 21));
        discardButton->setMaximumSize(QSize(171, 21));
        discardButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(discardButton, 19, 0, 1, 4);

        discardAllButton = new QPushButton(centralwidget);
        discardAllButton->setObjectName(QString::fromUtf8("discardAllButton"));
        discardAllButton->setMinimumSize(QSize(171, 21));
        discardAllButton->setMaximumSize(QSize(171, 21));
        discardAllButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(discardAllButton, 20, 0, 1, 4);

        verticalSpacer = new QSpacerItem(145, 149, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 21, 0, 1, 4);

        aboutButton = new QPushButton(centralwidget);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));
        aboutButton->setMinimumSize(QSize(171, 21));
        aboutButton->setMaximumSize(QSize(171, 21));
        aboutButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(aboutButton, 22, 0, 1, 4);

        authorButton = new QPushButton(centralwidget);
        authorButton->setObjectName(QString::fromUtf8("authorButton"));
        authorButton->setMinimumSize(QSize(171, 21));
        authorButton->setMaximumSize(QSize(171, 21));
        authorButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(authorButton, 23, 0, 1, 4);

        outButton = new QPushButton(centralwidget);
        outButton->setObjectName(QString::fromUtf8("outButton"));
        outButton->setMinimumSize(QSize(171, 21));
        outButton->setMaximumSize(QSize(171, 21));
        outButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(outButton, 24, 0, 1, 4);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260 3", nullptr));
        label_0->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\206\320\262\320\265\321\202\320\260", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\276\321\202\321\200\320\265\320\267\320\272\320\276\320\262:", nullptr));
        lineColorButton->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260:", nullptr));
        fontColorButton->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\260", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\246\320\224\320\220", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274 (\321\206\320\265\320\273\321\213\320\265)", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274 (\320\264\320\265\320\271\321\201\321\202\320\262.)", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274 (\321\201 \321\203\321\201\321\202\321\200. \321\201\321\202.)", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "\320\222\321\203", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "\320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\321\207\320\275\321\213\320\271", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "\320\240\320\270\321\201\320\276\320\262\320\260\320\275\320\270\320\265 \320\276\321\202\321\200\320\265\320\267\320\272\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "x0:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "y0:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "x1:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "y1:", nullptr));
        drawLineButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\240\320\270\321\201\320\276\320\262\320\260\320\275\320\270\320\265 \321\201\320\277\320\265\320\272\321\202\321\200\320\260", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "x:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "y:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\260:", nullptr));
        drawLinesButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        analyseButton->setText(QCoreApplication::translate("MainWindow", "\320\220\320\275\320\260\320\273\320\270\320\267 \321\201\321\202\321\203\320\277\320\265\320\275\321\207\320\260\321\202\320\276\321\201\321\202\320\270", nullptr));
        analyseButton_2->setText(QCoreApplication::translate("MainWindow", "\320\220\320\275\320\260\320\273\320\270\320\267 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", nullptr));
        discardButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        discardAllButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        aboutButton->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        authorButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261 \320\260\320\262\321\202\320\276\321\200\320\265", nullptr));
        outButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
