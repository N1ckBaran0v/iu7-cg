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
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *lineEditX;
    QLabel *label_2;
    QLineEdit *lineEditY;
    QPushButton *moveButton;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEditX_2;
    QLabel *label_9;
    QLineEdit *lineEditY_2;
    QLabel *label_6;
    QLineEdit *lineEditAngle;
    QPushButton *rotateButton;
    QLabel *label_4;
    QLabel *label_13;
    QLineEdit *lineEditX_3;
    QLabel *label_12;
    QLineEdit *lineEditY_3;
    QLabel *label_10;
    QLineEdit *lineEditDX;
    QLabel *label_11;
    QLineEdit *lineEditDY;
    QPushButton *scaleImageButton;
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
        MainWindow->resize(960, 540);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(960, 540));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        MainWindow->setTabShape(QTabWidget::Triangular);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setContextMenuPolicy(Qt::NoContextMenu);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setEnabled(true);
        label_5->setMinimumSize(QSize(171, 16));
        label_5->setMaximumSize(QSize(171, 16));
        label_5->setAutoFillBackground(false);
        label_5->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_5, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(731, 444, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 19, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setMinimumSize(QSize(91, 16));
        label->setMaximumSize(QSize(91, 16));
        label->setAutoFillBackground(false);
        label->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEditX = new QLineEdit(centralwidget);
        lineEditX->setObjectName(QString::fromUtf8("lineEditX"));
        lineEditX->setMinimumSize(QSize(111, 16));
        lineEditX->setMaximumSize(QSize(111, 16));

        gridLayout->addWidget(lineEditX, 1, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(91, 16));
        label_2->setMaximumSize(QSize(91, 16));
        label_2->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEditY = new QLineEdit(centralwidget);
        lineEditY->setObjectName(QString::fromUtf8("lineEditY"));
        lineEditY->setMinimumSize(QSize(111, 16));
        lineEditY->setMaximumSize(QSize(111, 16));

        gridLayout->addWidget(lineEditY, 2, 1, 1, 1);

        moveButton = new QPushButton(centralwidget);
        moveButton->setObjectName(QString::fromUtf8("moveButton"));
        moveButton->setMinimumSize(QSize(171, 21));
        moveButton->setMaximumSize(QSize(171, 21));
        moveButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(moveButton, 3, 0, 1, 2);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(171, 16));
        label_7->setMaximumSize(QSize(171, 16));
        label_7->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_7, 4, 0, 1, 2);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setEnabled(true);
        label_8->setMinimumSize(QSize(91, 16));
        label_8->setMaximumSize(QSize(91, 16));
        label_8->setAutoFillBackground(false);
        label_8->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        lineEditX_2 = new QLineEdit(centralwidget);
        lineEditX_2->setObjectName(QString::fromUtf8("lineEditX_2"));
        lineEditX_2->setMinimumSize(QSize(111, 16));
        lineEditX_2->setMaximumSize(QSize(111, 16));

        gridLayout->addWidget(lineEditX_2, 5, 1, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(91, 16));
        label_9->setMaximumSize(QSize(91, 16));
        label_9->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_9, 6, 0, 1, 1);

        lineEditY_2 = new QLineEdit(centralwidget);
        lineEditY_2->setObjectName(QString::fromUtf8("lineEditY_2"));
        lineEditY_2->setMinimumSize(QSize(111, 16));
        lineEditY_2->setMaximumSize(QSize(111, 16));

        gridLayout->addWidget(lineEditY_2, 6, 1, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(91, 16));
        label_6->setMaximumSize(QSize(91, 16));
        label_6->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        lineEditAngle = new QLineEdit(centralwidget);
        lineEditAngle->setObjectName(QString::fromUtf8("lineEditAngle"));
        lineEditAngle->setMinimumSize(QSize(111, 16));
        lineEditAngle->setMaximumSize(QSize(111, 16));

        gridLayout->addWidget(lineEditAngle, 7, 1, 1, 1);

        rotateButton = new QPushButton(centralwidget);
        rotateButton->setObjectName(QString::fromUtf8("rotateButton"));
        rotateButton->setMinimumSize(QSize(171, 21));
        rotateButton->setMaximumSize(QSize(171, 21));
        rotateButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(rotateButton, 8, 0, 1, 2);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(171, 16));
        label_4->setMaximumSize(QSize(171, 16));
        label_4->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_4, 9, 0, 1, 2);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setEnabled(true);
        label_13->setMinimumSize(QSize(91, 16));
        label_13->setMaximumSize(QSize(91, 16));
        label_13->setAutoFillBackground(false);
        label_13->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_13, 10, 0, 1, 1);

        lineEditX_3 = new QLineEdit(centralwidget);
        lineEditX_3->setObjectName(QString::fromUtf8("lineEditX_3"));
        lineEditX_3->setMinimumSize(QSize(111, 16));
        lineEditX_3->setMaximumSize(QSize(111, 16));

        gridLayout->addWidget(lineEditX_3, 10, 1, 1, 1);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(91, 16));
        label_12->setMaximumSize(QSize(91, 16));
        label_12->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_12, 11, 0, 1, 1);

        lineEditY_3 = new QLineEdit(centralwidget);
        lineEditY_3->setObjectName(QString::fromUtf8("lineEditY_3"));
        lineEditY_3->setMinimumSize(QSize(111, 16));
        lineEditY_3->setMaximumSize(QSize(111, 16));

        gridLayout->addWidget(lineEditY_3, 11, 1, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setEnabled(true);
        label_10->setMinimumSize(QSize(91, 16));
        label_10->setMaximumSize(QSize(91, 16));
        label_10->setAutoFillBackground(false);
        label_10->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_10, 12, 0, 1, 1);

        lineEditDX = new QLineEdit(centralwidget);
        lineEditDX->setObjectName(QString::fromUtf8("lineEditDX"));
        lineEditDX->setMinimumSize(QSize(111, 16));
        lineEditDX->setMaximumSize(QSize(111, 16));

        gridLayout->addWidget(lineEditDX, 12, 1, 1, 1);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(91, 16));
        label_11->setMaximumSize(QSize(91, 16));
        label_11->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_11, 13, 0, 1, 1);

        lineEditDY = new QLineEdit(centralwidget);
        lineEditDY->setObjectName(QString::fromUtf8("lineEditDY"));
        lineEditDY->setMinimumSize(QSize(111, 16));
        lineEditDY->setMaximumSize(QSize(111, 16));

        gridLayout->addWidget(lineEditDY, 13, 1, 1, 1);

        scaleImageButton = new QPushButton(centralwidget);
        scaleImageButton->setObjectName(QString::fromUtf8("scaleImageButton"));
        scaleImageButton->setMinimumSize(QSize(171, 21));
        scaleImageButton->setMaximumSize(QSize(171, 21));
        scaleImageButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(scaleImageButton, 14, 0, 1, 2);

        discardButton = new QPushButton(centralwidget);
        discardButton->setObjectName(QString::fromUtf8("discardButton"));
        discardButton->setMinimumSize(QSize(171, 21));
        discardButton->setMaximumSize(QSize(171, 21));
        discardButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(discardButton, 15, 0, 1, 2);

        discardAllButton = new QPushButton(centralwidget);
        discardAllButton->setObjectName(QString::fromUtf8("discardAllButton"));
        discardAllButton->setMinimumSize(QSize(171, 21));
        discardAllButton->setMaximumSize(QSize(171, 21));
        discardAllButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(discardAllButton, 16, 0, 1, 2);

        verticalSpacer = new QSpacerItem(145, 149, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 17, 0, 1, 2);

        aboutButton = new QPushButton(centralwidget);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));
        aboutButton->setMinimumSize(QSize(171, 21));
        aboutButton->setMaximumSize(QSize(171, 21));
        aboutButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(aboutButton, 18, 0, 1, 2);

        authorButton = new QPushButton(centralwidget);
        authorButton->setObjectName(QString::fromUtf8("authorButton"));
        authorButton->setMinimumSize(QSize(171, 21));
        authorButton->setMaximumSize(QSize(171, 21));
        authorButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(authorButton, 19, 0, 1, 2);

        outButton = new QPushButton(centralwidget);
        outButton->setObjectName(QString::fromUtf8("outButton"));
        outButton->setMinimumSize(QSize(171, 21));
        outButton->setMaximumSize(QSize(171, 21));
        outButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(outButton, 20, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260 2", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\241\320\264\320\262\320\270\320\263 \320\277\320\276 x:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\264\320\262\320\270\320\263 \320\277\320\276 y:", nullptr));
        moveButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "x \321\206\320\265\320\275\321\202\321\200\320\260:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "y \321\206\320\265\320\275\321\202\321\200\320\260:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273:", nullptr));
        lineEditAngle->setText(QString());
        rotateButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "x \321\206\320\265\320\275\321\202\321\200\320\260:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "y \321\206\320\265\320\275\321\202\321\200\320\260:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "dx:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "dy:", nullptr));
        scaleImageButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\274\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
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
