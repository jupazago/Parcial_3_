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

int Canion::getDistancia() const
{
    return distancia;
}

void Canion::setDistancia(int value)
{
    distancia = value;
}

void Canion::obtenerDistancia(int distancia_)
{
    distancia = abs(distancia - distancia_);
}

Canion::Canion(double posx_, double posy_, int figura, QObject *parent) : QObject(parent)
{
    posx = posx_;
    posy = posy_;
    setPos(posx,-posy);

    //dimensiones de cada imagen
    ancho = 30;
    alto = 500;

    filas = 0;
    columnas = 0;

    switch(figura)
    {
        case 1: pixmap = new QPixmap(":/canionO.png");
        break;

        case 2: pixmap = new QPixmap(":/canionD.png");
        break;

        default: pixmap = new QPixmap(":/canionD.png");
    }

}


QRectF Canion::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Canion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}
