#ifndef CLUSTER_H
#define CLUSTER_H

#include <vector>
#include "segment.h"
#include <QVector3D>
#include <QVector4D>
#include <QColor>
#include <QPainter>

class Cluster
{
public:
    Cluster(Segment *segment, QColor colorCluster);

    bool checkCluster(QPointF & newPoint, float speed);
    void paint(QPainter *painter, QColor hullColor, qreal upperBound) const;

private:
    std::vector<Segment *> segments;
    std::vector<QPointF> _points;
    QColor colorCluster;

};

#endif // CLUSTER_H
