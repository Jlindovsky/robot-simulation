
#ifndef ROBOT_H
#define ROBOT_H

#include "barrierC.h"
#include "global.h"

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
