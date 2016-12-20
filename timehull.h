#ifndef TIMEHULL_H
#define TIMEHULL_H


#include <vector>
#include "cluster.h"
#include <iterator>

#include <queue>

/**
 * u okviru ove klase se generise pocetni skup tacaka
 * i konveksni omotac
 */

class TImeHull
{
public:
    TImeHull(int numberOfPoints, float speed, unsigned x, unsigned y);
    ~TImeHull();

    /**
     * na osnovu prvih n tacaka generise omotac
     */
    bool HullL1(unsigned n);

    /**
     *  jedan korak u algoritmu
     */
    void NextStep(QPointF &point);

    /**
     * iscrtavanje
     */
    void paint(QPainter *painter, qreal upperBound) const;


private:

    /**
     * copy konstruktor i operator dodele su privatni jer se ne korsite
     * a potrebni su jer je  implementiran destruktor
     */
    TImeHull(const TImeHull& hull);
    TImeHull& operator+=(const TImeHull& hull);

    std::vector<QPointF> _points; // pocetni skup tacaka, pri generisanju se i sortira
    float _v; // brzina na autoputu, da bi se uopste radio algortam mora da bude veca od 1
    std::vector<Cluster *> _clusters; // vektor svih klastera

    /**
     * metod u kome se generise numberOfPoints random tacaka i sortira
     */

    void generatePoints(int numberOfPoints);

    QColor hullColor; // boja konveksnog omotaca

    unsigned xBound, yBound; // granice widgeta u kome se crta omotac

    std::queue<QColor> colors;
};

#endif // TIMEHULL_H
