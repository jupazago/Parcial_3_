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
#include <grafica.h>
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

    //graficar
    void imprimirGraficos();

    //graficaremos los valores obtenidos anteriormente
    void imprimirVectores();
    void imprimirVectores2();
    void imprimirVectores3();

private:
    Ui::MainWindow *ui;

    //estructura que nos facilitará la caotura de los calculos
    struct Datos{
        double angulo;
        double velocidad;
    };

    QGraphicsScene *escena;

    //timers
    QTimer *timer;
    QTimer *timer_ofe;
    QTimer *timer_defe;
    QTimer *timer_neutral;
    QTimer *timer_graficos;

    //objetos necesarios
    Canion *canion1;
    Canion *canion2;
    Misil *OFENSIVO;
    Misil *DEFENSIVO;

    //listas para movimiento y graficar
    QList<Misil*> Particulas;
    QList<Grafica*> Particulas_graficadas;

    //vectores de almacenamiento de estructuras
    QVector<Datos> ofensivos3;
    QVector<Datos> defensivos3;
    QVector<Datos> neutrales9;

    //contadores auxiliares para graficar
    int contador_ofensivo = 0;
    int contador_defensivo = 0;
    int contador_neutral = 0;
};
#endif // MAINWINDOW_H
