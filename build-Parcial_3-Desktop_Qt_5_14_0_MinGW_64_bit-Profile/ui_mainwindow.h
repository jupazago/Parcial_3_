/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLabel *label;
    QLineEdit *LE_PosxO;
    QPushButton *btnSimular;
    QLineEdit *LE_PosyO;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *LE_PosyD;
    QLabel *label_3;
    QLineEdit *LE_PosxD;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1100, 745);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 1071, 500));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 550, 61, 16));
        LE_PosxO = new QLineEdit(centralwidget);
        LE_PosxO->setObjectName(QString::fromUtf8("LE_PosxO"));
        LE_PosxO->setGeometry(QRect(142, 550, 91, 20));
        LE_PosxO->setReadOnly(true);
        btnSimular = new QPushButton(centralwidget);
        btnSimular->setObjectName(QString::fromUtf8("btnSimular"));
        btnSimular->setGeometry(QRect(214, 630, 191, 41));
        QFont font;
        font.setPointSize(12);
        btnSimular->setFont(font);
        LE_PosyO = new QLineEdit(centralwidget);
        LE_PosyO->setObjectName(QString::fromUtf8("LE_PosyO"));
        LE_PosyO->setGeometry(QRect(140, 590, 91, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 590, 47, 13));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 520, 261, 21));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_5->setFont(font1);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(350, 520, 261, 21));
        label_6->setFont(font1);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(590, 510, 31, 51));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/escudoO.png")));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(240, 510, 31, 41));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/escudoOO.png")));
        LE_PosyD = new QLineEdit(centralwidget);
        LE_PosyD->setObjectName(QString::fromUtf8("LE_PosyD"));
        LE_PosyD->setGeometry(QRect(450, 590, 91, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(350, 550, 61, 16));
        LE_PosxD = new QLineEdit(centralwidget);
        LE_PosxD->setObjectName(QString::fromUtf8("LE_PosxD"));
        LE_PosxD->setGeometry(QRect(452, 550, 91, 20));
        LE_PosxD->setReadOnly(false);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(350, 590, 47, 13));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(550, 560, 101, 16));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(240, 590, 101, 16));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(550, 590, 101, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1100, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Posicion x", nullptr));
        LE_PosxO->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnSimular->setText(QCoreApplication::translate("MainWindow", "Ubicar Ca\303\261ones", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Posicion y", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Ubicaci\303\263n del ca\303\261\303\263n Ofensivo", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Ubicaci\303\263n del ca\303\261\303\263n Defensivo", nullptr));
        label_7->setText(QString());
        label_8->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Posicion x", nullptr));
        LE_PosxD->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Posicion y", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Rango: 300 a 900", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Rango: 0 a 450", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Rango: 0 a 300", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
