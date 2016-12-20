#include "drawarea.h"

#include <QPainter>
#include <QPen>
#include <QBrush>

DrawArea::DrawArea(QWidget *parent)
    : QWidget(parent) ,
      step(0),
      _execute(false),
      hull(0),
      linethickness(6)
{

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

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

void DrawArea::generateHull(int number, float speed)
{
    hull = new TImeHull(number, speed, width() - 20, height()/2);
}

void DrawArea::start()
{
    _execute = true;
    update();
}

void DrawArea::pause()
{
    _execute = false;
    update();
}

void DrawArea::stop()
{
    _execute = false;
    step = 0;

    emit moveSlider(step);
    delete hull;

    hull = nullptr;
    emit theEnd();
    update();
}

void DrawArea::moveToStep(int i)
{
    _execute = false;
    step = i;
    update();
}

void DrawArea::setSpeed(double speed)
{
    linethickness = speed * 2;
}

void DrawArea::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QBrush brush(Qt::black);
    QPen pen(brush, linethickness);

    /*pretvorimo koordinatni sistem u onaj koji smo navikli za crtanje*/
    painter.translate(0, height() - 20);

    painter.scale(1, -1);

    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(pen);
    painter.drawLine(QLineF(0, 0, width(), 0));

//    QPointF niz[3] = {QPointF(100, 200), QPointF(200, 300), QPointF(100, 300)};
//    painter.drawPolygon(niz, 3);

    if(hull != nullptr){

        bool isEnd = hull->HullL1(step);
        if(isEnd){
            emit end();
        }

        hull->paint(&painter, height() - 10);
    }
}

void DrawArea::timerEvent(QTimerEvent *)
{
    if(_execute){
        step ++;
    }

    emit moveSlider(step);
    update();
}

