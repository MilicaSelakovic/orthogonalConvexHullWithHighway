#ifndef SEGMENT_H
#define SEGMENT_H

#include <QLineF>
#include <QPointF>
#include <QVector3D>

/**
 * Klasa Segment, sadrzi informacije o duzi koji je granici klastera
 * takodje i o tacki u omotacu koja je povezana sa tim delom granice
 * na osnovu tacke i brzine konstruise se lako segment koji ce pripasi omotacu
 */

class Segment
{
public:

    Segment(QPointF point, float speed);

    /**
     * proverava li je tacka iznad segmenta
     * ako jeste onda treba da pripadne klasteru
     * ako ne prelazi se na sledeci segmet u granici
     */

    bool isInside(const QPointF& newPoint) const;

    /**
     * proverava da li vertikalna prava kroz newPoint ima presek sa
     * segmentom, ako ima menja mu pocetak
     *
     */
    bool intersect(const QPointF& newPoint);

    /**
     * pravi QLineF od segmenta
     */
    QLineF Line() const;

    /**
     * geter i seter metode
     */

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
