#ifndef CANION_H
#define CANION_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QObject>


class Canion: public QObject, public QGraphicsItem
{
    Q_OBJECT
    double posx;
    double posy;
    int distancia;
public:
    explicit Canion(double posx_, double posy_, int figura, QObject *parent = nullptr);

    QPixmap *pixmap;
    float filas, columnas;
    float ancho, alto;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    double getPosx() const;
    void setPosx(double value);
    double getPosy() const;
    void setPosy(double value);
    int getDistancia() const;
    void setDistancia(int value);

    void obtenerDistancia(int distancia_);
};

#endif // CANION_H
