#ifndef AROBOT_H
#define AROBOT_H

#include "robot.h"

class ARobot : public Robot
{
public:
    ARobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent);
};

#endif