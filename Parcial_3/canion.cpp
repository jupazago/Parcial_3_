#include "canion.h"

double Canion::getPosx() const
{
    return posx;
}

void Canion::setPosx(double value)
{
    posx = value;
}

double Canion::getPosy() const
{
    return posy;
}

void Canion::setPosy(double value)
{
    posy = value;
}

Canion::Canion()
{

}

Canion::Canion(double posx_, double posy_)
{
    posx = posx_;
    posy = posy_;
    setPos(posx,-posy);
}

QRectF Canion::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void Canion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/Imagen/bola.png");
    painter->drawPixmap(-r,-r,2*r,2*r,pixmap);
}
