#ifndef CLUSTER_H
#define CLUSTER_H

#include <vector>
#include "segment.h"
#include <QVector3D>
#include <QVector4D>
#include <QColor>
#include <QPainter>


/*
    Ova klasa predstavlja jedan klaster
    Za klaster vazi da je najkraci put izmedju svake dve tacke iz klastera u klasteru
    dok ako tacke nisu u klasteru onda je najkraci put preko autoputa
*/

class Cluster
{
public:
    Cluster(Segment *segment, QColor colorCluster);

    /*
        ovim metodom se proverava da li sledeca tacka pripada klasteru ili ne
        tako sto odredi da li je ispod ili iznad granice
    */
    bool checkCluster(QPointF & newPoint, float speed);

    /*
        iscrtavanje klastera
        crta se deo konveksnog omotaca i granica klastera,
        boja omotaca je ista za sve klastere, dok je boja granice razlicita
    */
    void paint(QPainter *painter, QColor hullColor, qreal upperBound) const;

private:

    std::vector<Segment *> segments; // segmenti koji cine granicu klastera
    std::vector<QPointF> _points; // tacke koje se nalaze na granici konveksnog omotaca
    QColor colorCluster; // boja granice klastera

};

#endif // CLUSTER_H
