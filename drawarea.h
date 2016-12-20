#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include <QTimerEvent>
#include <QBasicTimer>
#include "timehull.h"

class DrawArea : public QWidget
{
    Q_OBJECT
public:
    explicit DrawArea(QWidget *parent = 0);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void generateHull(int number, float speed);
    void destroyHull();

signals:

    void moveSlider(int i);
    void end();
    void theEnd();

public slots:

    void start();
    void pause();
    void stop();

    void moveToStep(int i);

    void setSpeed(double speed);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *);

private:
    TImeHull *hull;
    unsigned step;

    QBasicTimer _timer;

    bool _execute;

    int linethickness;
};

#endif // DRAWAREA_H
