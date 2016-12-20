#include "cluster.h"
#include <QTime>

#include <QBrush>
#include <QPen>

Cluster::Cluster(Segment *segment, QColor colorCluster)
    :colorCluster(colorCluster)
{
    // at beginning in cluster we have just one segment

    segments = std::vector<Segment *>();
    _points = std::vector<QPointF> ();
    segments.push_back(segment);
    _points.push_back(segment->point());
/*
    qsrand (QTime::currentTime().msec());
    int red = qrand() % 255;
    int green = qrand() % 255;
    int blue = qrand() % 255;

    colorCluster = QColor(red, green, blue);
*/
}

bool Cluster::checkCluster(QPointF &newPoint, float speed)
{
    // return true if cluster is changed and false if it is not
    auto s = segments.rbegin();
    for(; s != segments.rend(); s++){
        if((*s)->isInside(newPoint)){
           break;
        }
    }

    if(s == segments.rend()){
        return false;
    }

    auto greater = _points.rbegin();

    /*nadjemo prvi levo koji je visi, ako takav postoji*/

    for(; greater != _points.rend(); greater ++){
        if( (*greater).y() >= newPoint.y())
            break;
    }

    if (greater == _points.rend()){

        auto r = std::max_element(_points.begin(), _points.end(),
                                   [] (const QPointF& v1, const QPointF& v2) { return v1.y() == v2.y() ? v1.x() <= v2.x() : v1.y() < v2.y(); });
        _points.erase(r + 1, _points.end());
        _points.push_back(newPoint);
    } else {
        _points.erase(_points.end() - (greater - _points.rbegin()) , _points.end());
        _points.push_back(newPoint);
    }

    Segment * newSegment = new Segment(newPoint, speed);

    for(; s != segments.rend(); s++)
    {

        if((*s)->intersect(newSegment->end())){


            int i = s - segments.rbegin();
            segments.erase(segments.end() - i , segments.end());
            segments.push_back(newSegment);


            return true;
        }
    }

    segments.clear();
    segments.push_back(newSegment);


    return true;

}

void Cluster::paint(QPainter *painter, QColor hullColor, qreal upperBound) const
{
    //QPointF clusterBound[segments.size() * 5 + 1];

    bool ind = true;

    QBrush brush(colorCluster);
    QPen pen(brush, 2);
    painter->setPen(pen);

    Segment * pervious;
    for(Segment *s : segments){
        if(ind){
            painter->drawLine(QLineF(s->end().x(), upperBound, s->end().x(), s->end().y()));
            pervious = s;
            ind = false;
        } else {
            painter->drawLine(QLineF(pervious->begin(), s->end()));
        }

        painter->drawLine(s->Line());

        pervious = s;

    }



    //QBrush brush1(hullColor);


    QBrush brush1(hullColor, Qt::SolidPattern);
    QPen pen1(Qt::darkBlue, 1);
    painter->setBrush(brush1);
    painter->setPen(pen1);

    QPointF polygon[_points.size()*2];

    auto iter = _points.begin();


    int j = 0;
    ind = true;
    QPointF perv;
    for(; iter != _points.end(); iter++){
        if(ind){
            polygon[j++] = QPointF((*iter).x() , 0);
            polygon[j++] = (*iter);
            perv = (*iter);
            ind = false;
        } else {
            QPointF connect = perv.y() < (*iter).y() ? QPointF((*iter).x(),perv.y()) : QPointF(perv.x(),(*iter).y());
            polygon[j++] = connect;
            polygon[j++] = (*iter);
            perv = (*iter);
        }
    }

    polygon[j++] = QPointF(perv.x(), 0);


    painter->drawPolygon(polygon, j, Qt::WindingFill);


}
