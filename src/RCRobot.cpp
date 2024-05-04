#include "../header/RCRobot.h"

RCRobot::RCRobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent, int sensorIN)
    : Robot(x, y, w, parent)
{
    sensor = sensorIN;
    directionOfSpin = 1;
    spin = 30;
    step = sensorIN/2;
}



void RCRobot::moveUp()
{
    calculateHit(sensor);
    QList<QGraphicsItem *> colliding_items = collidingItems();
    bool hit = false;
    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        barrierC *barrierItem = dynamic_cast<barrierC *>(colliding_items[i]);

        // Check if the dynamic_cast was successful and the object is a barrierC or its derived class
        if (barrierItem != nullptr && typeid(*barrierItem) == typeid(barrierC))
        {
            setPos(previousLocation);
            qDebug() << "Hit! wont move";
            return;
        }
    }
}
void RCRobot::rotateLeft()
{
    angle = (angle - spin + 360) % 360;
}
void RCRobot::rotateRight()
{
    angle = (angle + spin + 360) % 360;
}
