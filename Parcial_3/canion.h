#ifndef CANION_H
#define CANION_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <misil.h>

class Canion: public QGraphicsItem
{
    double posx;
    double posy;
    double r; //modificar tamanio del canion
public:
    Canion();
    Canion(double posx_, double posy_);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

    double getPosx() const;
    void setPosx(double value);
    double getPosy() const;
    void setPosy(double value);
};

#endif // CANION_H
