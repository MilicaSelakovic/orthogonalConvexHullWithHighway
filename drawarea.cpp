#include "drawarea.h"

#include <QPainter>
#include <QPen>
#include <QBrush>

DrawArea::DrawArea(QWidget *parent) : QWidget(parent) ,step(0)
{

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);


    hull = new TImeHull(15, 3.6, 500, 400);
    _timer.start(1000, this);

}

QSize DrawArea::minimumSizeHint() const
{
    return QSize(100,100);
}

QSize DrawArea::sizeHint() const
{
    return QSize(400,200);
}

void DrawArea::paintEvent(QPaintEvent *)
{

    hull->HullL1(step);
    QPainter painter(this);
    QBrush brush(Qt::black);
    QPen pen(brush, 5);

    /*pretvorimo koordinatni sistem u onaj koji smo navikli za crtanje*/
    painter.translate(0, height() - 20);

    painter.scale(1, -1);

    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(pen);
    painter.drawLine(QLineF(0, 0, width(), 0));

    //painter.translate(0, - height() + 20);


    hull->paint(&painter, height() - 10);
}

void DrawArea::timerEvent(QTimerEvent *)
{
    step ++;
    update();
}

