#include "timehull.h"

#include <QTime>
#include <QFile>
#include <QTextStream>

#include <iostream>

TImeHull::TImeHull(float speed)
    : _v(speed)
{
    hullColor = QColor(200, 200, 255);
    _points = std::set<QPointF>();


}

TImeHull::~TImeHull()
{
    _clusters.clear();
}



bool TImeHull::HullL1(unsigned n)
{
    bool retVal = false;
    _clusters.clear();
    colors = std::queue<QColor>({
                                    Qt::blue,
                                    Qt::red,
                                    Qt::yellow,
                                    Qt::green,
                                    Qt::cyan,
                                    Qt::black,
                                    Qt::darkCyan,
                                    Qt::darkRed,
                                    Qt::darkYellow,
                                    Qt::magenta,
                                    Qt::darkGray
                                });
    if(n > _points.size()){
        retVal = true;
        n = _points.size();
    }
    unsigned i = 0;
    for(QPointF p : _points){
        if (i == n)
            break;
        NextStep(p);
        i++;

    }

    return retVal;

}

void TImeHull::NextStep(QPointF &point){
    bool makeNew = true;
    Segment* current = new Segment(point, _v);

    /*  prodjemo kroz sve klastere i proverimo da li se tacka nalazi u njihovim granicama
        ako da modifikujemo ga, ako ne dodajemo na kraj (odn vrh posto vektor prolazimo od kraja)
        novi klaster
    */
    for(auto cIter = _clusters.rbegin(); cIter != _clusters.rend(); cIter ++){
        bool changed = (*cIter)->checkCluster(point, _v);
        if(changed){
            makeNew = false;
            _clusters.erase(_clusters.end() - (cIter - _clusters.rbegin()), _clusters.end());

        }
    }

    if(makeNew){
        QColor col = colors.front();
        colors.pop();
        colors.push(col);
        _clusters.push_back(new Cluster(current, col));
    }
}

void TImeHull::generateRandom(unsigned numberOfPoints, int xBound, int yBound)
{
    _points.clear();
    QTime now = QTime::currentTime();

    qsrand(now.msec());


    for(unsigned i = 0; i<numberOfPoints; i++){
            /* +10 samo da ne bi bili u samom uglu kada se crtaju*/
         QPointF p(qrand()%(xBound) + 10, qrand()%(yBound));
         _points.insert(p);


    }

}

bool TImeHull::openFromFile(QString &filePath)
{
    std::set<QPointF> tmp;

    QFile inputFile(filePath);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          QStringList list = line.split(" ");
          if( list.size() != 2)
              return false;

          bool ind;
          float x = list.at(0).toFloat(&ind);
          if(!ind)
              return false;

          float y = list.at(1).toFloat(&ind);
          if(!ind)
              return false;

          tmp.insert(QPointF(x, y));
       }
       inputFile.close();
    } else{
        return false;
    }


    _points.swap(tmp);
    return true;

}

void TImeHull::addPoint(QPointF &point)
{
    _points.insert(point);
}

void TImeHull::paint(QPainter *painter, qreal upperBound) const
{

    /*iscrtamo klastere */
    for(Cluster *c : _clusters){
        c->paint(painter, hullColor, upperBound);
    }

    /*iscrtamo pocetni skup tacaka */
    QBrush brush(Qt::black);
    QPen pen(brush, 5);

    painter->setPen(pen);
    for(QPointF p : _points){
        painter->drawEllipse(p, 2,2);
    }
}

int TImeHull::numberOfPoints() const
{
    return _points.size();
}

void TImeHull::clean()
{
    _points.clear();
    _clusters.clear();
}

/**
 * definisemo operator manje da bi mogli da stavimo tacke u skup (drvo)
 */

bool operator <(const QPointF &v1, const QPointF &v2)
{
     return v1.x() == v2.x() ? v1.y() <= v2.y() : v1.x() < v2.x();
}
