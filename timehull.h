#ifndef TIMEHULL_H
#define TIMEHULL_H


#include <vector>
#include "cluster.h"
#include <iterator>



class TImeHull
{
public:
    TImeHull(int numberOfPoints, float speed, unsigned x, unsigned y);
    void HullL1(unsigned n);

    void NextStep(QPointF &point);

    void paint(QPainter *painter, qreal upperBound) const;


private:
    std::vector<QPointF> _points; // points in plane
    float _v; //HighWay speed
    std::vector<Cluster *> _clusters; // clusters

    std::vector<QPointF>::iterator iter;

    void generatePoints(int numberOfPoints);

    QColor hullColor;

    unsigned xBound, yBound;
};

#endif // TIMEHULL_H
