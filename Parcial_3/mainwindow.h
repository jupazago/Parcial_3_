#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QTimer>
#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
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

    //Aqui obtenemos los valores para la simulacion
    void DisparoOfensivo();
    void DisparoDefensivo(float Limite_tiempo);
    void DisparoNeutral(float Limite_tiempo);

    //graficaremos los valores obtenidos anteriormente
    void imprimirVectores();
    void imprimirVectores2();
    void imprimirVectores3();

private:
    Ui::MainWindow *ui;

    struct Datos{
        double angulo;
        double velocidad;
    };

    QGraphicsScene *escena;
    QTimer *timer;
    QTimer *timer_ofe;
    QTimer *timer_defe;
    QTimer *timer_neutral;
    Misil *cuerpo;
    Canion *canion1;
    Canion *canion2;
    Misil *OFENSIVO;
    Misil *DEFENSIVO;
    QList<Misil*> Particulas;

    QVector<Datos> ofensivos3;
    QVector<Datos> defensivos3;
    QVector<Datos> neutrales9;


    int contador_ofensivo = 0;
    int contador_defensivo = 0;
    int contador_neutral = 0;
};
#endif // MAINWINDOW_H
