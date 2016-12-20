#include "segment.h"



Segment::Segment(QPointF point, float speed)
    :_point(point)
{
    // highway is x axis

    _begin = QPointF(point.x(), 0);
    _end = QPointF(point.x() + point.y()/speed, point.y());
}


bool Segment::intersect(const QPointF &newPoint)
{
    // point is right of segment
    if(newPoint.x() > _end.x()){
        return false;
    }

    QPointF newBeginPoint = QPointF();
    Line().intersect(QLineF(newPoint.x(), newPoint.y(), newPoint.x(), 0), &newBeginPoint);

    _begin = newBeginPoint;

    return true;


}

bool Segment::isInside(const QPointF &newPoint) const
{
    if (newPoint.x() > _end.x()){
        return false;
    }

    // inace je unutar, jer da je levo bila obradjena u prethodnom segmentu

    if( Line().intersect(QLineF(newPoint.x(), newPoint.y(), newPoint.x(), 0), nullptr)  == QLineF::BoundedIntersection){
        return true;
    }
    return false;
}

//bool Segment::hasIntersect(const Segment & line, QPointF *intersection) const
//{
//    return Line().intersect(line.Line(), intersection) == QLineF::BoundedIntersection;
//}


QLineF Segment::Line() const{
    return QLineF(_begin, _end);
}

QPointF Segment::begin() const
{
    return _begin;
}

void Segment::setBegin(const QPointF &begin)
{
    _begin = begin;
}

QPointF Segment::end() const
{
    return _end;
}

void Segment::setEnd(const QPointF &end)
{
    _end = end;
}

QPointF Segment::point() const
{
    return _point;
}
