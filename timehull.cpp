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



void TImeHull::HullL1(unsigned n)
{
    if(n > _points.size())
        return;

    for(int i = 0 ; i < n; i++){
        NextStep(_points[i]);
    }

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

    for(QPointF p : _points){
        painter->drawEllipse(p, 2,2);
    }
    for(Cluster *c : _clusters){
        c->paint(painter, hullColor, upperBound);
    }
}

void TImeHull::generatePoints(int numberOfPoints)
{
    QTime now = QTime::currentTime();

    qsrand(now.msec());

    //std::cout << xBound << " " << yBound << std::endl;

    for(int i = 0; i<numberOfPoints; i++){

         QPointF p(qrand()%(xBound), qrand()%(yBound));
        _points.push_back(p);

    }

    std::sort(_points.begin(), _points.end(),
              [] (const QPointF& v1, const QPointF& v2) { return v1.x() == v2.x() ? v1.y() <= v2.y() : v1.x() < v2.x(); });


}
