#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QTimer>
#include <QMainWindow>
#include <QMessageBox>
#include <QList>
#include <misil.h>
#include <canion.h>
#define pi 3.141617

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
    //void Inicio_de_ataques();

    void DisparoOfensivo();
    void DisparoDefensivo(float Limite_tiempo);
    void DisparoNeutral(float Limite_tiempo);

private:
    Ui::MainWindow *ui;

    QGraphicsScene *escena;
    QTimer *timer;
    Misil *OFENSIVO;
    Misil *DEFENSIVO;
    Canion *canion1;
    Canion *canion2;
    QList<Misil*> Particulas;

};
#endif // MAINWINDOW_H
