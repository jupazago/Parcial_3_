#ifndef MISIL_H
#define MISIL_H
#include <math.h>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class Misil: public QGraphicsItem
{
    double posx;
    double posy;
    double vel;
    double ang;
    double velx;
    double vely;
    const double delta=0.020;
    const double g=9.8;
    int r=15;
public:
    Misil();
    Misil(double x, double y,double v, double a);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

    double getPosx() const;
    void setPosx(double value);
    double getPosy() const;
    void setPosy(double value);

    void ActualizarPosicion();
    void CalcularVelocidad();
};

#endif // MISIL_H
