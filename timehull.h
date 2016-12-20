#ifndef TIMEHULL_H
#define TIMEHULL_H


#include <vector>
#include "cluster.h"
#include <iterator>

#include <queue>



class TImeHull
{
public:
    TImeHull(int numberOfPoints, float speed, unsigned x, unsigned y);
    ~TImeHull();
    bool HullL1(unsigned n);

    void NextStep(QPointF &point);

    void paint(QPainter *painter, qreal upperBound) const;


private:

    TImeHull(const TImeHull& hull);
    TImeHull& operator+=(const TImeHull& hull);

    std::vector<QPointF> _points; // points in plane
    float _v; //HighWay speed
    std::vector<Cluster *> _clusters; // clusters

    std::vector<QPointF>::iterator iter;

    void generatePoints(int numberOfPoints);

    QColor hullColor;

    unsigned xBound, yBound;

    std::queue<QColor> colors;
};

#endif // TIMEHULL_H
