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
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *LE_Posx;
    QLineEdit *LE_Vel;
    QLineEdit *lineEdit_4;
    QPushButton *btnSimular;
    QLineEdit *LE_Posy;
    QLabel *label_2;
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
        graphicsView->setGeometry(QRect(10, 0, 900, 700));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(930, 140, 47, 13));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(930, 100, 47, 13));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(930, 20, 47, 13));
        LE_Posx = new QLineEdit(centralwidget);
        LE_Posx->setObjectName(QString::fromUtf8("LE_Posx"));
        LE_Posx->setGeometry(QRect(982, 20, 91, 20));
        LE_Vel = new QLineEdit(centralwidget);
        LE_Vel->setObjectName(QString::fromUtf8("LE_Vel"));
        LE_Vel->setGeometry(QRect(980, 100, 91, 20));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(980, 140, 91, 20));
        btnSimular = new QPushButton(centralwidget);
        btnSimular->setObjectName(QString::fromUtf8("btnSimular"));
        btnSimular->setGeometry(QRect(960, 210, 75, 23));
        LE_Posy = new QLineEdit(centralwidget);
        LE_Posy->setObjectName(QString::fromUtf8("LE_Posy"));
        LE_Posy->setGeometry(QRect(980, 60, 91, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(930, 60, 47, 13));
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
        label_4->setText(QCoreApplication::translate("MainWindow", "Angulo", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Velocidad", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Posicion x", nullptr));
        btnSimular->setText(QCoreApplication::translate("MainWindow", "Simular", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Posicion y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
