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
    QLabel *label_3;
    QPushButton *resultColorButton;
    QLabel *label_2;
    QPushButton *cutterColorButton;
    QLabel *label_6;
    QPushButton *fontColorButton;
    QLabel *label_14;
    QLabel *label_4;
    QLineEdit *lineEditX0;
    QLabel *label_15;
    QLineEdit *lineEditY0;
    QLabel *label_8;
    QLineEdit *lineEditX1;
    QLabel *label_16;
    QLineEdit *lineEditY1;
    QPushButton *addButton;
    QLabel *label_7;
    QComboBox *figureBox;
    QPushButton *delButton;
    QLabel *label_17;
    QLabel *label_5;
    QLineEdit *lineEditX0_2;
    QLabel *label_19;
    QLineEdit *lineEditY0_2;
    QLabel *label_9;
    QLineEdit *lineEditX1_2;
    QLabel *label_18;
    QLineEdit *lineEditY1_2;
    QPushButton *cutterButton;
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

        gridLayout->addWidget(label_0, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(744, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        label_1 = new QLabel(centralwidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setEnabled(true);
        label_1->setMinimumSize(QSize(131, 21));
        label_1->setMaximumSize(QSize(131, 21));
        label_1->setAutoFillBackground(false);
        label_1->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_1, 1, 0, 1, 2);

        lineColorButton = new QPushButton(centralwidget);
        lineColorButton->setObjectName(QString::fromUtf8("lineColorButton"));
        lineColorButton->setMinimumSize(QSize(51, 21));
        lineColorButton->setMaximumSize(QSize(51, 21));
        lineColorButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(lineColorButton, 1, 2, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(true);
        label_3->setMinimumSize(QSize(131, 21));
        label_3->setMaximumSize(QSize(131, 21));
        label_3->setAutoFillBackground(false);
        label_3->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_3, 2, 0, 1, 2);

        resultColorButton = new QPushButton(centralwidget);
        resultColorButton->setObjectName(QString::fromUtf8("resultColorButton"));
        resultColorButton->setMinimumSize(QSize(51, 21));
        resultColorButton->setMaximumSize(QSize(51, 21));
        resultColorButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(resultColorButton, 2, 2, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(131, 21));
        label_2->setMaximumSize(QSize(131, 21));
        label_2->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_2, 3, 0, 1, 2);

        cutterColorButton = new QPushButton(centralwidget);
        cutterColorButton->setObjectName(QString::fromUtf8("cutterColorButton"));
        cutterColorButton->setMinimumSize(QSize(51, 21));
        cutterColorButton->setMaximumSize(QSize(51, 21));
        cutterColorButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(cutterColorButton, 3, 2, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(131, 21));
        label_6->setMaximumSize(QSize(131, 21));
        label_6->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_6, 4, 0, 1, 2);

        fontColorButton = new QPushButton(centralwidget);
        fontColorButton->setObjectName(QString::fromUtf8("fontColorButton"));
        fontColorButton->setMinimumSize(QSize(51, 21));
        fontColorButton->setMaximumSize(QSize(51, 21));
        fontColorButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(fontColorButton, 4, 2, 1, 1);

        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setEnabled(true);
        label_14->setMinimumSize(QSize(171, 21));
        label_14->setMaximumSize(QSize(171, 21));
        label_14->setAutoFillBackground(false);
        label_14->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_14, 5, 0, 1, 3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setEnabled(true);
        label_4->setMinimumSize(QSize(21, 21));
        label_4->setMaximumSize(QSize(21, 21));
        label_4->setAutoFillBackground(false);
        label_4->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        lineEditX0 = new QLineEdit(centralwidget);
        lineEditX0->setObjectName(QString::fromUtf8("lineEditX0"));
        lineEditX0->setMinimumSize(QSize(111, 21));
        lineEditX0->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditX0, 6, 1, 1, 1);

        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setEnabled(true);
        label_15->setMinimumSize(QSize(21, 21));
        label_15->setMaximumSize(QSize(21, 21));
        label_15->setAutoFillBackground(false);
        label_15->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_15, 7, 0, 1, 1);

        lineEditY0 = new QLineEdit(centralwidget);
        lineEditY0->setObjectName(QString::fromUtf8("lineEditY0"));
        lineEditY0->setMinimumSize(QSize(111, 21));
        lineEditY0->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditY0, 7, 1, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setEnabled(true);
        label_8->setMinimumSize(QSize(21, 21));
        label_8->setMaximumSize(QSize(21, 21));
        label_8->setAutoFillBackground(false);
        label_8->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_8, 8, 0, 1, 1);

        lineEditX1 = new QLineEdit(centralwidget);
        lineEditX1->setObjectName(QString::fromUtf8("lineEditX1"));
        lineEditX1->setMinimumSize(QSize(111, 21));
        lineEditX1->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditX1, 8, 1, 1, 1);

        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setEnabled(true);
        label_16->setMinimumSize(QSize(21, 21));
        label_16->setMaximumSize(QSize(21, 21));
        label_16->setAutoFillBackground(false);
        label_16->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_16, 9, 0, 1, 1);

        lineEditY1 = new QLineEdit(centralwidget);
        lineEditY1->setObjectName(QString::fromUtf8("lineEditY1"));
        lineEditY1->setMinimumSize(QSize(111, 21));
        lineEditY1->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditY1, 9, 1, 1, 1);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setMinimumSize(QSize(171, 21));
        addButton->setMaximumSize(QSize(171, 21));
        addButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(addButton, 10, 0, 1, 3);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setEnabled(true);
        label_7->setMinimumSize(QSize(171, 21));
        label_7->setMaximumSize(QSize(171, 21));
        label_7->setAutoFillBackground(false);
        label_7->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_7, 11, 0, 1, 3);

        figureBox = new QComboBox(centralwidget);
        figureBox->addItem(QString());
        figureBox->setObjectName(QString::fromUtf8("figureBox"));
        figureBox->setMinimumSize(QSize(171, 21));
        figureBox->setMaximumSize(QSize(171, 21));

        gridLayout->addWidget(figureBox, 12, 0, 1, 3);

        delButton = new QPushButton(centralwidget);
        delButton->setObjectName(QString::fromUtf8("delButton"));
        delButton->setMinimumSize(QSize(171, 21));
        delButton->setMaximumSize(QSize(171, 21));
        delButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(delButton, 13, 0, 1, 3);

        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setEnabled(true);
        label_17->setMinimumSize(QSize(171, 21));
        label_17->setMaximumSize(QSize(171, 21));
        label_17->setAutoFillBackground(false);
        label_17->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_17, 14, 0, 1, 3);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setEnabled(true);
        label_5->setMinimumSize(QSize(21, 21));
        label_5->setMaximumSize(QSize(21, 21));
        label_5->setAutoFillBackground(false);
        label_5->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_5, 15, 0, 1, 1);

        lineEditX0_2 = new QLineEdit(centralwidget);
        lineEditX0_2->setObjectName(QString::fromUtf8("lineEditX0_2"));
        lineEditX0_2->setMinimumSize(QSize(111, 21));
        lineEditX0_2->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditX0_2, 15, 1, 1, 1);

        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setEnabled(true);
        label_19->setMinimumSize(QSize(21, 21));
        label_19->setMaximumSize(QSize(21, 21));
        label_19->setAutoFillBackground(false);
        label_19->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_19, 16, 0, 1, 1);

        lineEditY0_2 = new QLineEdit(centralwidget);
        lineEditY0_2->setObjectName(QString::fromUtf8("lineEditY0_2"));
        lineEditY0_2->setMinimumSize(QSize(111, 21));
        lineEditY0_2->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditY0_2, 16, 1, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setEnabled(true);
        label_9->setMinimumSize(QSize(21, 21));
        label_9->setMaximumSize(QSize(21, 21));
        label_9->setAutoFillBackground(false);
        label_9->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_9, 17, 0, 1, 1);

        lineEditX1_2 = new QLineEdit(centralwidget);
        lineEditX1_2->setObjectName(QString::fromUtf8("lineEditX1_2"));
        lineEditX1_2->setMinimumSize(QSize(111, 21));
        lineEditX1_2->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditX1_2, 17, 1, 1, 1);

        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setEnabled(true);
        label_18->setMinimumSize(QSize(21, 21));
        label_18->setMaximumSize(QSize(21, 21));
        label_18->setAutoFillBackground(false);
        label_18->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_18, 18, 0, 1, 1);

        lineEditY1_2 = new QLineEdit(centralwidget);
        lineEditY1_2->setObjectName(QString::fromUtf8("lineEditY1_2"));
        lineEditY1_2->setMinimumSize(QSize(111, 21));
        lineEditY1_2->setMaximumSize(QSize(111, 21));

        gridLayout->addWidget(lineEditY1_2, 18, 1, 1, 1);

        cutterButton = new QPushButton(centralwidget);
        cutterButton->setObjectName(QString::fromUtf8("cutterButton"));
        cutterButton->setMinimumSize(QSize(171, 21));
        cutterButton->setMaximumSize(QSize(171, 21));
        cutterButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(cutterButton, 19, 0, 1, 3);

        discardButton = new QPushButton(centralwidget);
        discardButton->setObjectName(QString::fromUtf8("discardButton"));
        discardButton->setMinimumSize(QSize(171, 21));
        discardButton->setMaximumSize(QSize(171, 21));
        discardButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(discardButton, 20, 0, 1, 3);

        discardAllButton = new QPushButton(centralwidget);
        discardAllButton->setObjectName(QString::fromUtf8("discardAllButton"));
        discardAllButton->setMinimumSize(QSize(171, 21));
        discardAllButton->setMaximumSize(QSize(171, 21));
        discardAllButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(discardAllButton, 21, 0, 1, 3);

        verticalSpacer = new QSpacerItem(168, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 22, 0, 1, 3);

        aboutButton = new QPushButton(centralwidget);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));
        aboutButton->setMinimumSize(QSize(171, 21));
        aboutButton->setMaximumSize(QSize(171, 21));
        aboutButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(aboutButton, 23, 0, 1, 3);

        authorButton = new QPushButton(centralwidget);
        authorButton->setObjectName(QString::fromUtf8("authorButton"));
        authorButton->setMinimumSize(QSize(171, 21));
        authorButton->setMaximumSize(QSize(171, 21));
        authorButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(authorButton, 24, 0, 1, 3);

        outButton = new QPushButton(centralwidget);
        outButton->setObjectName(QString::fromUtf8("outButton"));
        outButton->setMinimumSize(QSize(171, 21));
        outButton->setMaximumSize(QSize(171, 21));
        outButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(outButton, 25, 0, 1, 3);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260 7", nullptr));
        label_0->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\206\320\262\320\265\321\202\320\260", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\276\321\202\321\200\320\265\320\267\320\272\320\276\320\262:", nullptr));
        lineColorButton->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\260:", nullptr));
        resultColorButton->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\276\321\202\321\201\320\265\320\272\320\260\321\202\320\265\320\273\321\217:", nullptr));
        cutterColorButton->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260:", nullptr));
        fontColorButton->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\276\321\202\321\200\320\265\320\267\320\272\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "x0:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "y0:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "x1:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "y1:", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\276\321\202\321\200\320\265\320\267\320\272\320\260", nullptr));
        figureBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275", nullptr));

        delButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\321\203\320\273\321\217\321\200\320\275\321\213\320\271 \320\276\321\202\321\201\320\265\320\272\320\260\321\202\320\265\320\273\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "x0:", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "y0:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "x1:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "y1:", nullptr));
        cutterButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\201\320\265\321\207\321\214", nullptr));
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
