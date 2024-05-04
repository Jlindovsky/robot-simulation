
#ifndef ROBOT_H
#define ROBOT_H

#include "barrierC.h"

class Robot : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Robot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent);
    void calculateHit(int step);
public slots:
    virtual void move();
signals:
    void clicked();

protected:
    QPointF previousLocation;
    int circumference;
    int directionOfSpin; // ±1
    int angle;           // [0-360] actuall direction
    int step;
    int sensor;
    int spin;
    // public slots:
};

#endif

/*
 /
/alpha
_|_
 |
    if()
    0-90
    x+  y+
    elseif
    90-180
    x-  y+
    elseif
    180-270
    x-  y-
    else
    270-359
    x+ y-

    |
    |
----|
*/