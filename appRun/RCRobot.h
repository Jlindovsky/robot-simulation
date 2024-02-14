#ifndef RCROBOT_H
#define RCROBOT_H

#include "robot.h"

class RCRobot : public Robot
{
public:
    RCRobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent, int sensorIN);
public slots:
    void move();
};

#endif