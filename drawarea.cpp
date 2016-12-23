#include "drawarea.h"

#include <QPainter>
#include <QPen>
#include <QBrush>

#include <QFileDialog>

#include <iostream>
#include <QMessageBox>

DrawArea::DrawArea(QWidget *parent)
    : QWidget(parent) ,
      step(0),
      _execute(false),
      linethickness(6)
{

    hull = new TImeHull(3);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    _timer.start(1000, this);

}

QSize DrawArea::minimumSizeHint() const
{
    return QSize(100,100);
}

QSize DrawArea::sizeHint() const
{
    return QSize(400,200);
}

void DrawArea::generateHull(int number)
{
    hull->generateRandom(number, width() - 20, height()/2);
}

int DrawArea::numberOfPoints() const
{
    return hull->numberOfPoints();
}

void DrawArea::insertPoint(float x, float y)
{
    QPointF point(x, y);
    hull->addPoint(point);
}

void DrawArea::start()
{
    _execute = true;
    update();
}

void DrawArea::pause()
{
    _execute = false;
    update();
}

void DrawArea::stop()
{
    _execute = false;
    step = 0;

    emit moveSlider(step);

    hull ->clean();
    update();
}

void DrawArea::moveToStep(int i)
{
    _execute = false;
    step = i;
    update();
}

void DrawArea::setSpeed(double speed)
{
    hull->changeSpeed(speed);
}

void DrawArea::loadFromFile()
{

    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), ".", tr("Text files (*.txt)"));

    if(filePath.length()){
       bool succ =  hull->openFromFile(filePath);
       if(!succ){
            QMessageBox::information(this, tr("Error"), tr("Error while reading file.\nEach line should contain space separated coordinates (example of a line: \"42 6\")"));
       }
    }

}

void DrawArea::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QBrush brush(Qt::black);
    QPen pen(brush, linethickness);

    painter.drawText(0,height() - 40, 60, 20,0, tr("Highway"));


    /*pretvorimo koordinatni sistem u onaj koji smo navikli za crtanje*/
    painter.translate(0, height() - 20);

    painter.scale(1, -1);

    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(pen);
    painter.drawLine(QLineF(0, 0, width(), 0));

    if(hull != nullptr){

        bool isEnd = hull->HullL1(step);
        if(isEnd){
            emit end();
        }

        hull->paint(&painter, height() - 10, isEnd);
    }
}

void DrawArea::timerEvent(QTimerEvent *)
{
    if(_execute){
        step ++;
    }

    emit moveSlider(step);
    update();
}


