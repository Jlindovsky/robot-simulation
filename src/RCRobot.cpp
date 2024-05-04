#include "../header/RCRobot.h"

RCRobot::RCRobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent, int sensorIN)
    : Robot(x, y, w, parent)
{
    sensor = sensorIN;
    directionOfSpin = 1;
    spin = 30;
    step = sensorIN/2;
}

QJsonObject RCRobot::save()
{
    QJsonObject barObject;
    int x = this->x(); 
    int y = this->y(); 
    barObject["x"] = x;
    barObject["y"] = y;
    barObject["sensor"] = sensor;
    barObject["spin"] = spin;
    barObject["direction"] = directionOfSpin;
    barObject["type"] = "RC Robot"; 
    return barObject;
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
