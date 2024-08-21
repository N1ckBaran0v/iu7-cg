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
    QPushButton *outButton;
    QPushButton *fontColorButton;
    QPushButton *discardButton;
    QLineEdit *lineEditY1;
    QPushButton *addButton;
    QLabel *label_20;
    QPushButton *cutterColorButton;
    QPushButton *delDotButton;
    QPushButton *resultColorButton;
    QLineEdit *lineEditYC;
    QLineEdit *lineEditX1;
    QLineEdit *lineEditY0;
    QLabel *label_1;
    QLineEdit *lineEditX0;
    QLabel *label_17;
    QPushButton *delButton;
    QPushButton *discardAllButton;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_18;
    QLabel *label_0;
    QPushButton *cutterButton;
    QLabel *label_21;
    QLabel *label_6;
    QLabel *label_19;
    QPushButton *addDotButton;
    QPushButton *aboutButton;
    QPushButton *authorButton;
    QLabel *label_15;
    QLabel *label_7;
    QLabel *label_22;
    QLabel *label_16;
    QComboBox *cutterBox;
    QLabel *label_5;
    QComboBox *lineBox;
    QPushButton *lineColorButton;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *lineEditXC;
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
        outButton = new QPushButton(centralwidget);
        outButton->setObjectName(QString::fromUtf8("outButton"));
        outButton->setMinimumSize(QSize(171, 21));
        outButton->setMaximumSize(QSize(171, 21));
        outButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(outButton, 31, 0, 1, 3);

        fontColorButton = new QPushButton(centralwidget);
        fontColorButton->setObjectName(QString::fromUtf8("fontColorButton"));
        fontColorButton->setMinimumSize(QSize(51, 21));
        fontColorButton->setMaximumSize(QSize(51, 21));
        fontColorButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(fontColorButton, 4, 2, 1, 1);

        discardButton = new QPushButton(centralwidget);
        discardButton->setObjectName(QString::fromUtf8("discardButton"));
        discardButton->setMinimumSize(QSize(171, 21));
        discardButton->setMaximumSize(QSize(171, 21));
        discardButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(discardButton, 26, 0, 1, 3);

        lineEditY1 = new QLineEdit(centralwidget);
        lineEditY1->setObjectName(QString::fromUtf8("lineEditY1"));
        lineEditY1->setMinimumSize(QSize(111, 21));
        lineEditY1->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditY1, 10, 1, 1, 1);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setMinimumSize(QSize(171, 21));
        addButton->setMaximumSize(QSize(171, 21));
        addButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(addButton, 11, 0, 1, 3);

        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setEnabled(true);
        label_20->setMinimumSize(QSize(191, 21));
        label_20->setMaximumSize(QSize(191, 21));
        label_20->setAutoFillBackground(false);
        label_20->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_20, 5, 0, 1, 3);

        cutterColorButton = new QPushButton(centralwidget);
        cutterColorButton->setObjectName(QString::fromUtf8("cutterColorButton"));
        cutterColorButton->setMinimumSize(QSize(51, 21));
        cutterColorButton->setMaximumSize(QSize(51, 21));
        cutterColorButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(cutterColorButton, 2, 2, 1, 1);

        delDotButton = new QPushButton(centralwidget);
        delDotButton->setObjectName(QString::fromUtf8("delDotButton"));
        delDotButton->setMinimumSize(QSize(171, 21));
        delDotButton->setMaximumSize(QSize(171, 21));
        delDotButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(delDotButton, 24, 0, 1, 3);

        resultColorButton = new QPushButton(centralwidget);
        resultColorButton->setObjectName(QString::fromUtf8("resultColorButton"));
        resultColorButton->setMinimumSize(QSize(51, 21));
        resultColorButton->setMaximumSize(QSize(51, 21));
        resultColorButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(resultColorButton, 3, 2, 1, 1);

        lineEditYC = new QLineEdit(centralwidget);
        lineEditYC->setObjectName(QString::fromUtf8("lineEditYC"));
        lineEditYC->setMinimumSize(QSize(111, 21));
        lineEditYC->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditYC, 20, 1, 1, 1);

        lineEditX1 = new QLineEdit(centralwidget);
        lineEditX1->setObjectName(QString::fromUtf8("lineEditX1"));
        lineEditX1->setMinimumSize(QSize(111, 21));
        lineEditX1->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditX1, 9, 1, 1, 1);

        lineEditY0 = new QLineEdit(centralwidget);
        lineEditY0->setObjectName(QString::fromUtf8("lineEditY0"));
        lineEditY0->setMinimumSize(QSize(111, 21));
        lineEditY0->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditY0, 8, 1, 1, 1);

        label_1 = new QLabel(centralwidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setEnabled(true);
        label_1->setMinimumSize(QSize(131, 21));
        label_1->setMaximumSize(QSize(131, 21));
        label_1->setAutoFillBackground(false);
        label_1->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_1, 1, 0, 1, 2);

        lineEditX0 = new QLineEdit(centralwidget);
        lineEditX0->setObjectName(QString::fromUtf8("lineEditX0"));
        lineEditX0->setMinimumSize(QSize(111, 21));
        lineEditX0->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditX0, 7, 1, 1, 1);

        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setEnabled(true);
        label_17->setMinimumSize(QSize(191, 21));
        label_17->setMaximumSize(QSize(191, 21));
        label_17->setAutoFillBackground(false);
        label_17->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_17, 15, 0, 1, 3);

        delButton = new QPushButton(centralwidget);
        delButton->setObjectName(QString::fromUtf8("delButton"));
        delButton->setMinimumSize(QSize(171, 21));
        delButton->setMaximumSize(QSize(171, 21));
        delButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(delButton, 14, 0, 1, 3);

        discardAllButton = new QPushButton(centralwidget);
        discardAllButton->setObjectName(QString::fromUtf8("discardAllButton"));
        discardAllButton->setMinimumSize(QSize(171, 21));
        discardAllButton->setMaximumSize(QSize(171, 21));
        discardAllButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(discardAllButton, 27, 0, 1, 3);

        verticalSpacer = new QSpacerItem(168, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 28, 0, 1, 3);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(131, 21));
        label_2->setMaximumSize(QSize(131, 21));
        label_2->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_2, 2, 0, 1, 2);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setEnabled(true);
        label_4->setMinimumSize(QSize(21, 21));
        label_4->setMaximumSize(QSize(21, 21));
        label_4->setAutoFillBackground(false);
        label_4->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_4, 17, 0, 2, 1);

        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setEnabled(true);
        label_18->setMinimumSize(QSize(171, 21));
        label_18->setMaximumSize(QSize(171, 21));
        label_18->setAutoFillBackground(false);
        label_18->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_18, 6, 0, 1, 3);

        label_0 = new QLabel(centralwidget);
        label_0->setObjectName(QString::fromUtf8("label_0"));
        label_0->setEnabled(true);
        label_0->setMinimumSize(QSize(171, 21));
        label_0->setMaximumSize(QSize(171, 21));
        label_0->setAutoFillBackground(false);
        label_0->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_0, 0, 0, 1, 3);

        cutterButton = new QPushButton(centralwidget);
        cutterButton->setObjectName(QString::fromUtf8("cutterButton"));
        cutterButton->setMinimumSize(QSize(171, 21));
        cutterButton->setMaximumSize(QSize(171, 21));
        cutterButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(cutterButton, 25, 0, 1, 3);

        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setEnabled(true);
        label_21->setMinimumSize(QSize(191, 21));
        label_21->setMaximumSize(QSize(191, 21));
        label_21->setAutoFillBackground(false);
        label_21->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_21, 12, 0, 1, 3);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(131, 21));
        label_6->setMaximumSize(QSize(131, 21));
        label_6->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_6, 4, 0, 1, 2);

        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setEnabled(true);
        label_19->setMinimumSize(QSize(21, 21));
        label_19->setMaximumSize(QSize(21, 21));
        label_19->setAutoFillBackground(false);
        label_19->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_19, 8, 0, 1, 1);

        addDotButton = new QPushButton(centralwidget);
        addDotButton->setObjectName(QString::fromUtf8("addDotButton"));
        addDotButton->setMinimumSize(QSize(171, 21));
        addDotButton->setMaximumSize(QSize(171, 21));
        addDotButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(addDotButton, 21, 0, 1, 3);

        aboutButton = new QPushButton(centralwidget);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));
        aboutButton->setMinimumSize(QSize(171, 21));
        aboutButton->setMaximumSize(QSize(171, 21));
        aboutButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(aboutButton, 29, 0, 1, 3);

        authorButton = new QPushButton(centralwidget);
        authorButton->setObjectName(QString::fromUtf8("authorButton"));
        authorButton->setMinimumSize(QSize(171, 21));
        authorButton->setMaximumSize(QSize(171, 21));
        authorButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(authorButton, 30, 0, 1, 3);

        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setEnabled(true);
        label_15->setMinimumSize(QSize(21, 21));
        label_15->setMaximumSize(QSize(21, 21));
        label_15->setAutoFillBackground(false);
        label_15->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_15, 19, 0, 2, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setEnabled(true);
        label_7->setMinimumSize(QSize(21, 21));
        label_7->setMaximumSize(QSize(21, 21));
        label_7->setAutoFillBackground(false);
        label_7->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_7, 9, 0, 1, 1);

        label_22 = new QLabel(centralwidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setEnabled(true);
        label_22->setMinimumSize(QSize(21, 21));
        label_22->setMaximumSize(QSize(21, 21));
        label_22->setAutoFillBackground(false);
        label_22->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_22, 10, 0, 1, 1);

        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setEnabled(true);
        label_16->setMinimumSize(QSize(191, 21));
        label_16->setMaximumSize(QSize(191, 21));
        label_16->setAutoFillBackground(false);
        label_16->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_16, 22, 0, 1, 3);

        cutterBox = new QComboBox(centralwidget);
        cutterBox->addItem(QString());
        cutterBox->setObjectName(QString::fromUtf8("cutterBox"));
        cutterBox->setMinimumSize(QSize(171, 21));
        cutterBox->setMaximumSize(QSize(171, 21));

        gridLayout->addWidget(cutterBox, 23, 0, 1, 3);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setEnabled(true);
        label_5->setMinimumSize(QSize(21, 21));
        label_5->setMaximumSize(QSize(21, 21));
        label_5->setAutoFillBackground(false);
        label_5->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        lineBox = new QComboBox(centralwidget);
        lineBox->addItem(QString());
        lineBox->setObjectName(QString::fromUtf8("lineBox"));
        lineBox->setMinimumSize(QSize(171, 21));
        lineBox->setMaximumSize(QSize(171, 21));

        gridLayout->addWidget(lineBox, 13, 0, 1, 3);

        lineColorButton = new QPushButton(centralwidget);
        lineColorButton->setObjectName(QString::fromUtf8("lineColorButton"));
        lineColorButton->setMinimumSize(QSize(51, 21));
        lineColorButton->setMaximumSize(QSize(51, 21));
        lineColorButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(lineColorButton, 1, 2, 1, 1);

        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setEnabled(true);
        label_14->setMinimumSize(QSize(171, 21));
        label_14->setMaximumSize(QSize(171, 21));
        label_14->setAutoFillBackground(false);
        label_14->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_14, 16, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(744, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(true);
        label_3->setMinimumSize(QSize(131, 21));
        label_3->setMaximumSize(QSize(131, 21));
        label_3->setAutoFillBackground(false);
        label_3->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_3, 3, 0, 1, 2);

        lineEditXC = new QLineEdit(centralwidget);
        lineEditXC->setObjectName(QString::fromUtf8("lineEditXC"));
        lineEditXC->setMinimumSize(QSize(111, 21));
        lineEditXC->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditXC, 17, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260 8", nullptr));
        outButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        fontColorButton->setText(QString());
        discardButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\320\234\320\275\320\276\320\263\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        cutterColorButton->setText(QString());
        delDotButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        resultColorButton->setText(QString());
        label_1->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\276\321\202\321\200\320\265\320\267\320\272\320\276\320\262:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\201\320\265\320\272\320\260\321\202\320\265\320\273\321\214", nullptr));
        delButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        discardAllButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\276\321\202\321\201\320\265\320\272\320\260\321\202\320\265\320\273\321\217:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "x:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\276\321\202\321\200\320\265\320\267\320\272\320\260", nullptr));
        label_0->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\206\320\262\320\265\321\202\320\260", nullptr));
        cutterButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\201\320\265\321\207\321\214", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\276\321\202\321\200\320\265\320\267\320\272\320\260", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260:", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "y0:", nullptr));
        addDotButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        aboutButton->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        authorButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261 \320\260\320\262\321\202\320\276\321\200\320\265", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "y:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "x1:", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "y1:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \321\202\320\276\321\207\320\272\320\270", nullptr));
        cutterBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\260", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "x0:", nullptr));
        lineBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275", nullptr));

        lineColorButton->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\202\320\276\321\207\320\272\320\270", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
