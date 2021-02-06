#include "misil.h"
#include <QGraphicsScene>

double Misil::getPosx() const
{
    return posx;
}

void Misil::setPosx(double value)
{
    posx = value;
}

double Misil::getPosy() const
{
    return posy;
}

void Misil::setPosy(double value)
{
    posy = value;
}

void Misil::ActualizarPosicion()
{
    CalcularVelocidad();
    posx=posx+velx*delta;
    posy=posy+vely*delta-(0.5*g*delta*delta);
    setPos(posx,-posy);
}

void Misil::CalcularVelocidad()
{
    velx=vel*cos(ang);
    vely=vel*sin(ang)-g*delta;
    ang=atan2(vely,velx);
    vel=sqrt(velx*velx+vely*vely);
}

double Misil::getVel() const
{
    return vel;
}

void Misil::setVel(double value)
{
    vel = value;
}

double Misil::getAng() const
{
    return ang;
}

void Misil::setAng(double value)
{
    ang = value;
}

double Misil::getVelx() const
{
    return velx;
}

void Misil::setVelx(double value)
{
    velx = value;
}

double Misil::getVely() const
{
    return vely;
}

void Misil::setVely(double value)
{
    vely = value;
}

int Misil::getR() const
{
    return r;
}

void Misil::setR(int value)
{
    r = value;
}

Misil::Misil()
{

}
Misil::Misil(double x, double y)
{
    posx=x;
    posy=y;
    setPos(posx,-posy);
}

Misil::Misil(double x, double y, double v, double a)
{
    posx=x;
    posy=y;
    vel=v;
    ang=a;
    setPos(posx,-posy);
}

QRectF Misil::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void Misil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/bola.png");
    painter->drawPixmap(-r,-r,2*r,2*r,pixmap);
}
