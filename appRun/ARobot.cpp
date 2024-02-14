#include "ARobot.h"

ARobot::ARobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent) : Robot(x, y, w, parent)
{
    sensor = 40;
    directionOfSpin = 1; // tmp
    spin = 35;           // tmp
    this->setPos(mapToParent(x, y));
}
