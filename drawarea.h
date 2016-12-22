#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include <QTimerEvent>
#include <QBasicTimer>
#include "timehull.h"


/*
    widget na kome se iscrtava generisanje konveksnog omotaca

*/

class DrawArea : public QWidget
{
    Q_OBJECT
public:
    explicit DrawArea(QWidget *parent = 0);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    /*
     * metod kojim se generise pocetni skup tacaka
     */
    void generateHull(int number);

    int numberOfPoints() const;

    void insertPoint(float x, float y);

signals:
    /*
     * signali koje saljemo kada treba pomeriti slajder traku i
     * kada je doslo do kraja izvrsavanja algoritma
     */
    void moveSlider(int i);
    void end();

public slots:

    /*
     * slotovi koji se konektuju sa start, stop i pause dugmetom
     */
    void start();
    void pause();
    void stop();

    /*
     * slot koji se konektuje sa signalom pomeranja slajder trake
     */
    void moveToStep(int i);

    /*
     * kada se promeni vrednost brzine po autoputu, povecamo debljinu linije koja predstavlja autoput
     * ta linija je fiksirano x osa
     */
    void setSpeed(double speed);

    void loadFromFile();


protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *);

private:
    unsigned step; // koliko je tacaka obradjeno do sad

    QBasicTimer _timer; // timer koji se okida na svaku sekundu radi lepseg prikaza animacije

    bool _execute; // promenljiva koja govori da li je pauziran algoritam ili ne

    TImeHull *hull; // pokazivac na omotac, u okviru klase se generise konveksni omotac od pocetnog skupa tacaka

    int linethickness; // debljina linije koja predstavlja autoput
};

#endif // DRAWAREA_H
