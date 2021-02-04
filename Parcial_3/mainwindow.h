#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QTimer>
#include <QMainWindow>
#include <QList>
#include <misil.h>
#include <canion.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnSimular_clicked();
    void Mover();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *escena;
    QTimer *timer;
    Misil *cuerpo;
    QList<Misil*> Particulas;
};
#endif // MAINWINDOW_H
