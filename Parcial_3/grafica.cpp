#include "grafica.h"

Grafica::Grafica()
{

}

Grafica::Grafica(double x, double y, double r_)
{
    posx = x;
    posy = y;
    r = r_;
    setPos(posx ,-posy);
}

QRectF Grafica::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void Grafica::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/bola2.png");
    painter->drawPixmap(-r,-r,2*r,2*r,pixmap);
}
