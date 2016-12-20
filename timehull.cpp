#include "timehull.h"

#include <QTime>

#include <iostream>

TImeHull::TImeHull(int numberOfPoints, float speed, unsigned x, unsigned y)
    : _v(speed), xBound(x), yBound(y)
{
    generatePoints(numberOfPoints);
    iter = _points.begin();

    hullColor = QColor(200, 200, 255);
}

TImeHull::~TImeHull()
{
    _clusters.clear();
}



bool TImeHull::HullL1(unsigned n)
{
    if(n > _points.size())
        return true;

    for(unsigned i = 0 ; i < n; i++){
        NextStep(_points[i]);
    }

    return false;

}

void TImeHull::NextStep(QPointF &point){
    bool makeNew = true;
    Segment* current = new Segment(point, _v);
    for(auto cIter = _clusters.rbegin(); cIter != _clusters.rend(); cIter ++){
        bool changed = (*cIter)->checkCluster(point, _v);
        if(changed){
            makeNew = false;
            _clusters.erase(_clusters.end() - (cIter - _clusters.rbegin()), _clusters.end());

        }
    }

    if(makeNew){
        _clusters.push_back(new Cluster(current));
    }
}

void TImeHull::paint(QPainter *painter, qreal upperBound) const
{

    for(Cluster *c : _clusters){
        c->paint(painter, hullColor, upperBound);
    }

    QBrush brush(Qt::black);
    QPen pen(brush, 5);

    painter->setPen(pen);
    for(QPointF p : _points){
        painter->drawEllipse(p, 2,2);
    }
}

void TImeHull::generatePoints(int numberOfPoints)
{
    QTime now = QTime::currentTime();

    qsrand(now.msec());

    //std::cout << xBound << " " << yBound << std::endl;

    for(int i = 0; i<numberOfPoints; i++){
            /*+10 samo da ne bi bili u samom uglu kada se crtaju*/
         QPointF p(qrand()%(xBound) + 10, qrand()%(yBound));
        _points.push_back(p);

    }

    std::sort(_points.begin(), _points.end(),
              [] (const QPointF& v1, const QPointF& v2) { return v1.x() == v2.x() ? v1.y() <= v2.y() : v1.x() < v2.x(); });


}
