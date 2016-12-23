#ifndef TIMEHULL_H
#define TIMEHULL_H


#include <set>
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
    TImeHull(float speed);
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
     * generise niz od numberOf points radnom tacaka
     */
    void generateRandom(unsigned numberOfPoints, int xBound, int yBound);

    /**
     * cita tacke iz fajla
     */
    bool openFromFile(QString &filePath);

    /**
     * dodaje tacku
     */
    void addPoint(QPointF &point);

    /**
     * iscrtavanje
     */
    void paint(QPainter *painter, qreal upperBound, bool end) const;


    int numberOfPoints() const;

    void clean();

    void changeSpeed(float v);
private:

    /**
     * copy konstruktor i operator dodele su privatni jer se ne korsite
     * a potrebni su jer je  implementiran destruktor
     */
    TImeHull(const TImeHull& hull);
    TImeHull& operator+=(const TImeHull& hull);

    std::set<QPointF> _points; // pocetni skup tacaka, pri generisanju se i sortira
    float _v; // brzina na autoputu, da bi se uopste radio algortam mora da bude veca od 1
    std::vector<Cluster *> _clusters; // vektor svih klastera

    QColor hullColor; // boja konveksnog omotaca


    std::queue<QColor> colors;
};

#endif // TIMEHULL_H
