#ifndef GRAFICA_H
#define GRAFICA_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class Grafica: public QGraphicsItem
{
    double posx;
    double posy;
    int r;
public:
    Grafica();
    Grafica(double x, double y, double r_);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
};

#endif // GRAFICA_H
