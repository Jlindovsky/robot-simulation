#include "../header/ARobot.h"

/**
 * @brief Construct a new ARobot::ARobot object
 *
 * @param x
 * @param y
 * @param w
 * @param parent
 * @param sensorIn
 * @param directionOfSpinIn
 * @param spinIn
 */
ARobot::ARobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent, int sensorIn, int directionOfSpinIn, int spinIn) : Robot(x, y, w, parent)
{
    sensor = sensorIn;
    directionOfSpin = directionOfSpinIn; // tmp
    spin = spinIn;                       // tmp
    step = sensorIn / 2;
}

/**
 * @brief
 *
 * @return QJsonObject
 */
QJsonObject ARobot::save()
{
    QJsonObject barObject;
    int x = this->x();
    int y = this->y();
    barObject["x"] = x;
    barObject["y"] = y;
    barObject["sensor"] = sensor;
    barObject["spin"] = spin;
    barObject["direction"] = directionOfSpin;
    barObject["type"] = "Automatic Robot";
    return barObject;
}

/**
 * @brief
 *
 */
void ARobot::move()
{
    calculateHit(sensor);
    //  get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();
    bool hit = false;
    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        barrierC *barrierItem = dynamic_cast<barrierC *>(colliding_items[i]);

        // Check if the dynamic_cast was successful and the object is a barrierC or its derived class
        if (barrierItem != nullptr && typeid(*barrierItem) == typeid(barrierC))
        {

            angle = ((angle + (directionOfSpin * spin)) + 360) % 360;
            hit = true;
        }
    }
    setPos(previousLocation);
    if (!hit)
    {
        calculateHit(step);
    }
    // generate direction
}