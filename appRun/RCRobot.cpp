#include "RCRobot.h"

RCRobot::RCRobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent,int sensorIN)
: Robot(x, y, w, parent)
{
    sensor = sensorIN;
    directionOfSpin = 1;
}

void RCRobot::move()
{

}