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

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *);

private:
    TImeHull *hull;
    unsigned step;

    QBasicTimer _timer;
};

#endif // DRAWAREA_H
