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
#include <QtWidgets/QSlider>
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
    QPushButton *fontColorButton;
    QLabel *label_2;
    QPushButton *surfaceColorButton;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_20;
    QLabel *label_5;
    QLineEdit *lineEditXmin;
    QLabel *label_19;
    QLineEdit *lineEditXmax;
    QLabel *label_7;
    QLineEdit *lineEditZmin;
    QLabel *label_22;
    QLineEdit *lineEditZmax;
    QLabel *label_18;
    QLabel *label_8;
    QLineEdit *lineEditDX;
    QLabel *label_23;
    QLineEdit *lineEditDZ;
    QLabel *label_24;
    QLabel *label_9;
    QSlider *sliderX;
    QLabel *labelOX;
    QLabel *label_11;
    QSlider *sliderY;
    QLabel *labelOY;
    QLabel *label_13;
    QSlider *sliderZ;
    QLabel *labelOZ;
    QLabel *label_26;
    QLabel *label_27;
    QLineEdit *lineEditXS;
    QLabel *label_28;
    QLineEdit *lineEditYS;
    QPushButton *setButton;
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
        MainWindow->resize(960, 560);
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
        label_0->setMinimumSize(QSize(171, 21));
        label_0->setMaximumSize(QSize(171, 21));
        label_0->setAutoFillBackground(false);
        label_0->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_0, 0, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(741, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 4, 2, 1);

        label_1 = new QLabel(centralwidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setEnabled(true);
        label_1->setMinimumSize(QSize(131, 21));
        label_1->setMaximumSize(QSize(131, 21));
        label_1->setAutoFillBackground(false);
        label_1->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_1, 1, 0, 1, 3);

        fontColorButton = new QPushButton(centralwidget);
        fontColorButton->setObjectName(QString::fromUtf8("fontColorButton"));
        fontColorButton->setMinimumSize(QSize(51, 21));
        fontColorButton->setMaximumSize(QSize(51, 21));
        fontColorButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(fontColorButton, 1, 3, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(141, 21));
        label_2->setMaximumSize(QSize(141, 21));
        label_2->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_2, 2, 0, 1, 3);

        surfaceColorButton = new QPushButton(centralwidget);
        surfaceColorButton->setObjectName(QString::fromUtf8("surfaceColorButton"));
        surfaceColorButton->setMinimumSize(QSize(51, 21));
        surfaceColorButton->setMaximumSize(QSize(51, 21));
        surfaceColorButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(surfaceColorButton, 2, 3, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(true);
        label_3->setMinimumSize(QSize(171, 21));
        label_3->setMaximumSize(QSize(171, 21));
        label_3->setAutoFillBackground(false);
        label_3->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_3, 3, 0, 1, 4);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(0, 21));
        comboBox->setMaximumSize(QSize(16777215, 21));

        gridLayout->addWidget(comboBox, 4, 0, 1, 4);

        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setEnabled(true);
        label_20->setMinimumSize(QSize(191, 21));
        label_20->setMaximumSize(QSize(191, 21));
        label_20->setAutoFillBackground(false);
        label_20->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_20, 5, 0, 1, 4);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setEnabled(true);
        label_5->setMinimumSize(QSize(51, 21));
        label_5->setMaximumSize(QSize(51, 21));
        label_5->setAutoFillBackground(false);
        label_5->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_5, 6, 0, 1, 2);

        lineEditXmin = new QLineEdit(centralwidget);
        lineEditXmin->setObjectName(QString::fromUtf8("lineEditXmin"));
        lineEditXmin->setMinimumSize(QSize(111, 21));
        lineEditXmin->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditXmin, 6, 2, 1, 2);

        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setEnabled(true);
        label_19->setMinimumSize(QSize(51, 21));
        label_19->setMaximumSize(QSize(51, 21));
        label_19->setAutoFillBackground(false);
        label_19->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_19, 7, 0, 1, 2);

        lineEditXmax = new QLineEdit(centralwidget);
        lineEditXmax->setObjectName(QString::fromUtf8("lineEditXmax"));
        lineEditXmax->setMinimumSize(QSize(111, 21));
        lineEditXmax->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditXmax, 7, 2, 1, 2);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setEnabled(true);
        label_7->setMinimumSize(QSize(51, 21));
        label_7->setMaximumSize(QSize(51, 21));
        label_7->setAutoFillBackground(false);
        label_7->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_7, 8, 0, 1, 2);

        lineEditZmin = new QLineEdit(centralwidget);
        lineEditZmin->setObjectName(QString::fromUtf8("lineEditZmin"));
        lineEditZmin->setMinimumSize(QSize(111, 21));
        lineEditZmin->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditZmin, 8, 2, 1, 2);

        label_22 = new QLabel(centralwidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setEnabled(true);
        label_22->setMinimumSize(QSize(51, 21));
        label_22->setMaximumSize(QSize(51, 21));
        label_22->setAutoFillBackground(false);
        label_22->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_22, 9, 0, 1, 2);

        lineEditZmax = new QLineEdit(centralwidget);
        lineEditZmax->setObjectName(QString::fromUtf8("lineEditZmax"));
        lineEditZmax->setMinimumSize(QSize(111, 21));
        lineEditZmax->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditZmax, 9, 2, 1, 2);

        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setEnabled(true);
        label_18->setMinimumSize(QSize(171, 21));
        label_18->setMaximumSize(QSize(171, 21));
        label_18->setAutoFillBackground(false);
        label_18->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_18, 10, 0, 1, 4);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setEnabled(true);
        label_8->setMinimumSize(QSize(51, 21));
        label_8->setMaximumSize(QSize(51, 21));
        label_8->setAutoFillBackground(false);
        label_8->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_8, 11, 0, 1, 2);

        lineEditDX = new QLineEdit(centralwidget);
        lineEditDX->setObjectName(QString::fromUtf8("lineEditDX"));
        lineEditDX->setMinimumSize(QSize(111, 21));
        lineEditDX->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditDX, 11, 2, 1, 2);

        label_23 = new QLabel(centralwidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setEnabled(true);
        label_23->setMinimumSize(QSize(51, 21));
        label_23->setMaximumSize(QSize(51, 21));
        label_23->setAutoFillBackground(false);
        label_23->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_23, 12, 0, 1, 2);

        lineEditDZ = new QLineEdit(centralwidget);
        lineEditDZ->setObjectName(QString::fromUtf8("lineEditDZ"));
        lineEditDZ->setMinimumSize(QSize(111, 21));
        lineEditDZ->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditDZ, 12, 2, 1, 2);

        label_24 = new QLabel(centralwidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setEnabled(true);
        label_24->setMinimumSize(QSize(191, 21));
        label_24->setMaximumSize(QSize(191, 21));
        label_24->setAutoFillBackground(false);
        label_24->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_24, 13, 0, 1, 4);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setEnabled(true);
        label_9->setMinimumSize(QSize(21, 21));
        label_9->setMaximumSize(QSize(21, 21));
        label_9->setAutoFillBackground(false);
        label_9->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_9, 14, 0, 1, 1);

        sliderX = new QSlider(centralwidget);
        sliderX->setObjectName(QString::fromUtf8("sliderX"));
        sliderX->setMinimum(-360);
        sliderX->setMaximum(360);
        sliderX->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderX, 14, 1, 1, 2);

        labelOX = new QLabel(centralwidget);
        labelOX->setObjectName(QString::fromUtf8("labelOX"));
        labelOX->setEnabled(true);
        labelOX->setMinimumSize(QSize(41, 21));
        labelOX->setMaximumSize(QSize(41, 21));
        labelOX->setAutoFillBackground(false);
        labelOX->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(labelOX, 14, 3, 1, 1);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setEnabled(true);
        label_11->setMinimumSize(QSize(21, 21));
        label_11->setMaximumSize(QSize(21, 21));
        label_11->setAutoFillBackground(false);
        label_11->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_11, 15, 0, 1, 1);

        sliderY = new QSlider(centralwidget);
        sliderY->setObjectName(QString::fromUtf8("sliderY"));
        sliderY->setMinimum(-360);
        sliderY->setMaximum(360);
        sliderY->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderY, 15, 1, 1, 2);

        labelOY = new QLabel(centralwidget);
        labelOY->setObjectName(QString::fromUtf8("labelOY"));
        labelOY->setEnabled(true);
        labelOY->setMinimumSize(QSize(41, 21));
        labelOY->setMaximumSize(QSize(41, 21));
        labelOY->setAutoFillBackground(false);
        labelOY->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(labelOY, 15, 3, 1, 1);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setEnabled(true);
        label_13->setMinimumSize(QSize(21, 21));
        label_13->setMaximumSize(QSize(21, 21));
        label_13->setAutoFillBackground(false);
        label_13->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_13, 16, 0, 1, 1);

        sliderZ = new QSlider(centralwidget);
        sliderZ->setObjectName(QString::fromUtf8("sliderZ"));
        sliderZ->setMinimum(-360);
        sliderZ->setMaximum(360);
        sliderZ->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderZ, 16, 1, 1, 2);

        labelOZ = new QLabel(centralwidget);
        labelOZ->setObjectName(QString::fromUtf8("labelOZ"));
        labelOZ->setEnabled(true);
        labelOZ->setMinimumSize(QSize(41, 21));
        labelOZ->setMaximumSize(QSize(41, 21));
        labelOZ->setAutoFillBackground(false);
        labelOZ->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(labelOZ, 16, 3, 1, 1);

        label_26 = new QLabel(centralwidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setEnabled(true);
        label_26->setMinimumSize(QSize(191, 21));
        label_26->setMaximumSize(QSize(191, 21));
        label_26->setAutoFillBackground(false);
        label_26->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_26, 17, 0, 1, 4);

        label_27 = new QLabel(centralwidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setEnabled(true);
        label_27->setMinimumSize(QSize(51, 21));
        label_27->setMaximumSize(QSize(51, 21));
        label_27->setAutoFillBackground(false);
        label_27->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_27, 18, 0, 1, 2);

        lineEditXS = new QLineEdit(centralwidget);
        lineEditXS->setObjectName(QString::fromUtf8("lineEditXS"));
        lineEditXS->setMinimumSize(QSize(111, 21));
        lineEditXS->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditXS, 18, 2, 1, 2);

        label_28 = new QLabel(centralwidget);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setEnabled(true);
        label_28->setMinimumSize(QSize(51, 21));
        label_28->setMaximumSize(QSize(51, 21));
        label_28->setAutoFillBackground(false);
        label_28->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_28, 19, 0, 1, 2);

        lineEditYS = new QLineEdit(centralwidget);
        lineEditYS->setObjectName(QString::fromUtf8("lineEditYS"));
        lineEditYS->setMinimumSize(QSize(111, 21));
        lineEditYS->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditYS, 19, 2, 1, 2);

        setButton = new QPushButton(centralwidget);
        setButton->setObjectName(QString::fromUtf8("setButton"));
        setButton->setMinimumSize(QSize(171, 21));
        setButton->setMaximumSize(QSize(171, 21));
        setButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(setButton, 20, 0, 1, 4);

        discardButton = new QPushButton(centralwidget);
        discardButton->setObjectName(QString::fromUtf8("discardButton"));
        discardButton->setMinimumSize(QSize(171, 21));
        discardButton->setMaximumSize(QSize(171, 21));
        discardButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(discardButton, 21, 0, 1, 4);

        discardAllButton = new QPushButton(centralwidget);
        discardAllButton->setObjectName(QString::fromUtf8("discardAllButton"));
        discardAllButton->setMinimumSize(QSize(171, 21));
        discardAllButton->setMaximumSize(QSize(171, 21));
        discardAllButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(discardAllButton, 22, 0, 1, 4);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 23, 2, 1, 1);

        aboutButton = new QPushButton(centralwidget);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));
        aboutButton->setMinimumSize(QSize(171, 21));
        aboutButton->setMaximumSize(QSize(171, 21));
        aboutButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(aboutButton, 24, 0, 1, 4);

        authorButton = new QPushButton(centralwidget);
        authorButton->setObjectName(QString::fromUtf8("authorButton"));
        authorButton->setMinimumSize(QSize(171, 21));
        authorButton->setMaximumSize(QSize(171, 21));
        authorButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(authorButton, 25, 0, 1, 4);

        outButton = new QPushButton(centralwidget);
        outButton->setObjectName(QString::fromUtf8("outButton"));
        outButton->setMinimumSize(QSize(171, 21));
        outButton->setMaximumSize(QSize(171, 21));
        outButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(outButton, 26, 0, 1, 4);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260 10", nullptr));
        label_0->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\206\320\262\320\265\321\202\320\260", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260:", nullptr));
        fontColorButton->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\277\320\276\320\262\320\265\321\200\321\205\320\275\320\276\321\201\321\202\320\270:", nullptr));
        surfaceColorButton->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\321\217", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "y = 0", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "y = sin(x)", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "y = x^2 * y^2", nullptr));

        label_20->setText(QCoreApplication::translate("MainWindow", "\320\223\321\200\320\260\320\275\320\270\321\206\321\213", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "xmin:", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "xmax:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "zmin:", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "zmax:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\320\250\320\260\320\263", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "dx:", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "dz:", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\276\321\202\320\275\320\276\321\201\320\270\321\202\320\265\320\273\321\214\320\275\320\276 \320\276\321\201\320\270", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "ox:", nullptr));
        labelOX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "oy:", nullptr));
        labelOY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "oz:", nullptr));
        labelOZ->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 x:", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 y:", nullptr));
        setButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214", nullptr));
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
