#ifndef AROBOT_H
#define AROBOT_H

#include "robot.h"
#include "global.h"


class ARobot : public Robot
{
public:
    ARobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent, int sensorIn, int directionOfSpinIn, int spinIn);
public slots:
    void move();
};

#endif