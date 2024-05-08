#include "../header/RCRobot.h"

/**
 * @brief Construct a new RCRobot object.
 *
 * Initializes a new RCRobot object with the specified parameters.
 *
 * @param x The x-coordinate of the RCRobot's position.
 * @param y The y-coordinate of the RCRobot's position.
 * @param w The width of the RCRobot.
 * @param parent The parent QGraphicsRectItem of the RCRobot.
 * @param sensorIN The sensor input value for the RCRobot.
 */
RCRobot::RCRobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent, int sensorIN)
    : Robot(x, y, w, parent)
{
    sensor = sensorIN;
    directionOfSpin = 1;
    spin = 30;
    step = sensorIN / 2;
}
/**
 * @brief Construct a new RCRobot object.
 *
 * Initializes a new RCRobot object with the specified parameters.
 *
 * @param x The x-coordinate of the RCRobot's position.
 * @param y The y-coordinate of the RCRobot's position.
 * @param w The width of the RCRobot.
 * @param parent The parent QGraphicsRectItem of the RCRobot.
 * @param sensorIN The sensor input value for the RCRobot.
 */
RCRobot::RCRobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent, int sensorIN, int angleIN)
    : Robot(x, y, w, parent)
{
    sensor = sensorIN;
    directionOfSpin = 1;
    spin = 30;
    step = sensorIN / 2;
    angle = angleIN;
}

/**
 * @brief Save the current state of the RCRobot.
 *
 * This function saves the current state of the RCRobot as a QJsonObject,
 * including its position and sensor value. The saved data can be used to
 * restore the RCRobot's state later.
 *
 * @return QJsonObject representing the RCRobot's state.
 */
QJsonObject RCRobot::save()
{
    QJsonObject barObject;
    int x = this->x();
    int y = this->y();
    barObject["x"] = x;
    barObject["y"] = y;
    barObject["sensor"] = sensor;
    barObject["angle"] = angle;
    barObject["type"] = "RC Robot";
    return barObject;
}

/**
 * @brief Move the RCRobot up.
 *
 * This function moves the RCRobot upward by a distance determined by its sensor value.
 * It calculates collisions with barriers and prevents movement if a collision occurs.
 */
void RCRobot::moveUp()
{
    calculateHit(sensor);
    QList<QGraphicsItem *> colliding_items = collidingItems();
    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        barrierC *barrierItem = dynamic_cast<barrierC *>(colliding_items[i]);

        // Check if the dynamic_cast was successful and the object is a barrierC or its derived class
        if (barrierItem != nullptr && typeid(*barrierItem) == typeid(barrierC))
        {
            setPos(previousLocation);
            return;
        }
    }
}

/**
 * @brief Rotate the RCRobot to the left.
 *
 * This function rotates the RCRobot to the left by the specified spin angle.
 */
void RCRobot::rotateLeft()
{
    angle = (angle - spin + 360) % 360;
}

/**
 * @brief Rotate the RCRobot to the right.
 *
 * This function rotates the RCRobot to the right by the specified spin angle.
 */
void RCRobot::rotateRight()
{
    angle = (angle + spin + 360) % 360;
}
