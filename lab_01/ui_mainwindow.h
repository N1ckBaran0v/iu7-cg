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
    QLabel *label;
    QLabel *labelY0;
    QLineEdit *lineEditX;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QLineEdit *lineEditY;
    QPushButton *addButton;
    QPushButton *delButton;
    QPushButton *delAllButton;
    QPushButton *solveButton;
    QPushButton *discardButton;
    QSpacerItem *verticalSpacer;
    QPushButton *aboutButton;
    QPushButton *authorButton;
    QPushButton *outButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelY1;
    QLabel *labelX0;
    QLabel *labelX1;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 640);
        MainWindow->setMinimumSize(QSize(1200, 640));
        MainWindow->setMouseTracking(false);
        MainWindow->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setMinimumSize(QSize(171, 16));
        label->setMaximumSize(QSize(171, 16));
        label->setAutoFillBackground(false);
        label->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        labelY0 = new QLabel(centralwidget);
        labelY0->setObjectName(QString::fromUtf8("labelY0"));
        labelY0->setEnabled(true);
        labelY0->setMaximumSize(QSize(151, 16));
        labelY0->setAutoFillBackground(false);
        labelY0->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(labelY0, 0, 4, 1, 1);

        lineEditX = new QLineEdit(centralwidget);
        lineEditX->setObjectName(QString::fromUtf8("lineEditX"));
        lineEditX->setMinimumSize(QSize(171, 30));
        lineEditX->setMaximumSize(QSize(171, 30));

        gridLayout->addWidget(lineEditX, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(138, 320, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 1, 4, 8, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(171, 16));
        label_2->setMaximumSize(QSize(171, 16));
        label_2->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEditY = new QLineEdit(centralwidget);
        lineEditY->setObjectName(QString::fromUtf8("lineEditY"));
        lineEditY->setMinimumSize(QSize(171, 30));
        lineEditY->setMaximumSize(QSize(171, 30));

        gridLayout->addWidget(lineEditY, 3, 0, 1, 1);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setMinimumSize(QSize(171, 41));
        addButton->setMaximumSize(QSize(171, 41));
        addButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(addButton, 4, 0, 1, 1);

        delButton = new QPushButton(centralwidget);
        delButton->setObjectName(QString::fromUtf8("delButton"));
        delButton->setMinimumSize(QSize(171, 41));
        delButton->setMaximumSize(QSize(171, 41));
        delButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(delButton, 5, 0, 1, 1);

        delAllButton = new QPushButton(centralwidget);
        delAllButton->setObjectName(QString::fromUtf8("delAllButton"));
        delAllButton->setMinimumSize(QSize(171, 41));
        delAllButton->setMaximumSize(QSize(171, 41));
        delAllButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(delAllButton, 6, 0, 1, 1);

        solveButton = new QPushButton(centralwidget);
        solveButton->setObjectName(QString::fromUtf8("solveButton"));
        solveButton->setMinimumSize(QSize(171, 41));
        solveButton->setMaximumSize(QSize(171, 41));
        solveButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(solveButton, 7, 0, 1, 1);

        discardButton = new QPushButton(centralwidget);
        discardButton->setObjectName(QString::fromUtf8("discardButton"));
        discardButton->setMinimumSize(QSize(171, 41));
        discardButton->setMaximumSize(QSize(171, 41));
        discardButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(discardButton, 8, 0, 1, 1);

        verticalSpacer = new QSpacerItem(168, 108, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 9, 0, 1, 1);

        aboutButton = new QPushButton(centralwidget);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));
        aboutButton->setMinimumSize(QSize(171, 41));
        aboutButton->setMaximumSize(QSize(171, 41));
        aboutButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(aboutButton, 10, 0, 1, 1);

        authorButton = new QPushButton(centralwidget);
        authorButton->setObjectName(QString::fromUtf8("authorButton"));
        authorButton->setMinimumSize(QSize(171, 41));
        authorButton->setMaximumSize(QSize(171, 41));
        authorButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(authorButton, 11, 0, 1, 1);

        outButton = new QPushButton(centralwidget);
        outButton->setObjectName(QString::fromUtf8("outButton"));
        outButton->setMinimumSize(QSize(171, 41));
        outButton->setMaximumSize(QSize(171, 41));
        outButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(outButton, 12, 0, 2, 1);

        horizontalSpacer_2 = new QSpacerItem(537, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 12, 2, 1, 1);

        labelY1 = new QLabel(centralwidget);
        labelY1->setObjectName(QString::fromUtf8("labelY1"));
        labelY1->setEnabled(true);
        labelY1->setMinimumSize(QSize(151, 16));
        labelY1->setMaximumSize(QSize(151, 16));
        labelY1->setAutoFillBackground(false);
        labelY1->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(labelY1, 12, 4, 1, 1);

        labelX0 = new QLabel(centralwidget);
        labelX0->setObjectName(QString::fromUtf8("labelX0"));
        labelX0->setEnabled(true);
        labelX0->setMinimumSize(QSize(151, 16));
        labelX0->setMaximumSize(QSize(151, 16));
        labelX0->setAutoFillBackground(false);
        labelX0->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout->addWidget(labelX0, 13, 1, 1, 1);

        labelX1 = new QLabel(centralwidget);
        labelX1->setObjectName(QString::fromUtf8("labelX1"));
        labelX1->setEnabled(true);
        labelX1->setMinimumSize(QSize(151, 16));
        labelX1->setMaximumSize(QSize(151, 16));
        labelX1->setAutoFillBackground(false);
        labelX1->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        labelX1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelX1, 13, 3, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260 1", nullptr));
#if QT_CONFIG(accessibility)
        centralwidget->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\203 x:", nullptr));
        labelY0->setText(QCoreApplication::translate("MainWindow", "tmp", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\203 y:", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\321\203", nullptr));
        delButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\321\203", nullptr));
        delAllButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \321\202\320\276\321\207\320\272\320\270", nullptr));
        solveButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\276\321\202\320\262\320\265\321\202", nullptr));
        discardButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        aboutButton->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        authorButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261 \320\260\320\262\321\202\320\276\321\200\320\265", nullptr));
        outButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        labelY1->setText(QCoreApplication::translate("MainWindow", "tmp", nullptr));
        labelX0->setText(QCoreApplication::translate("MainWindow", "tmp", nullptr));
        labelX1->setText(QCoreApplication::translate("MainWindow", "tmp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
