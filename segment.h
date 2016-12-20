#ifndef SEGMENT_H
#define SEGMENT_H

#include <QLineF>
#include <QPointF>
#include <QVector3D>


class Segment
{
public:

    Segment(QPointF point, float speed);

    bool isInside(const QPointF& newPoint) const;

    bool intersect(const QPointF& newPoint);

    QLineF Line() const;



    QPointF begin() const;
    void setBegin(const QPointF &begin);

    QPointF end() const;
    void setEnd(const QPointF &end);

    QPointF point() const;

private:
    QPointF _begin;
    QPointF _end;
    QPointF _point;
};

#endif // SEGMENT_H
