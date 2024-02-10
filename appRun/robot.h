
#ifndef ROBOT_H
#define ROBOT_H
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QObject>
#include "barrier.h"
#include <QPen>

class Robot : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Robot(qreal x, qreal y, qreal w, qreal h, QGraphicsRectItem *parent);
    void calculateMove();
    void generateHitbox();
public slots:
    void move();

private:
    int circumference;
    int directionOfSpin; // ±1
    int angle;           // [0-360]
    int step;
    int spin;
    QGraphicsRectItem *hitbox;
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