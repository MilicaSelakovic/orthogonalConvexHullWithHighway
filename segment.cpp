#include "segment.h"



Segment::Segment(QPointF point, float speed)
    :_point(point)
{
    /*
        ubacimo tacku i odredimo njen odgovarajuci segment
    */
    _begin = QPointF(point.x(), 0);
    float k = (1 - 1/speed)/2; /* koeficijent dela segmenta */
    _end = QPointF(point.x() + point.y()/k, point.y());
}


bool Segment::intersect(const QPointF &newPoint)
{
    /* tacka je desno od projekcije znaci nije iznad ovog segmenta */

    if(newPoint.x() > _end.x()){
        return false;
    }

     /*presek vertikalne prave i segmenta postoji, nadjemo ga i modifikujemo pocetak segmenta */

    QPointF newBeginPoint = QPointF();
    Line().intersect(QLineF(newPoint.x(), newPoint.y(), newPoint.x(), 0), &newBeginPoint);

    _begin = newBeginPoint;

    return true;


}

bool Segment::isInside(const QPointF &newPoint) const
{
    // tacka je desno
    if (newPoint.x() > _end.x()){
        return false;
    }

    // inace je unutar granica projekcije, jer da je levo bila obradjena u prethodnom segmentu
    // mozemo da utvrdimo da li je iznad ili ispod segmenta

    if( Line().intersect(QLineF(newPoint.x(), newPoint.y(), newPoint.x(), 0), nullptr)  == QLineF::BoundedIntersection){
        return true;
    }
    return false;
}


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
