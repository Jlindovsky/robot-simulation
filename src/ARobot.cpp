#include "../header/ARobot.h"

/**
 * @brief Construct a new ARobot::ARobot object.
 *
 * This constructor initializes an ARobot object with the specified position, dimensions,
 * and parent QGraphicsRectItem. It also sets the sensor length, direction of spin, spin,
 * and step size for the ARobot.
 *
 * @param x The x-coordinate of the ARobot's top-left corner.
 * @param y The y-coordinate of the ARobot's top-left corner.
 * @param w The width of the ARobot.
 * @param parent The parent QGraphicsRectItem to which the ARobot belongs.
 * @param sensorIn The length of the sensor of the ARobot.
 * @param directionOfSpinIn The direction of spin of the ARobot (temporary).
 * @param spinIn The spin of the ARobot (temporary).
 */
ARobot::ARobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent, int sensorIn, int directionOfSpinIn, int spinIn) : Robot(x, y, w, parent)
{
    sensor = sensorIn;
    directionOfSpin = directionOfSpinIn; // tmp
    spin = spinIn;                       // tmp
    step = sensorIn / 2;
}

/**
 * @brief Save function to serialize ARobot object into a JSON object.
 *
 * This function serializes the ARobot object into a QJsonObject, representing its state.
 * It includes the position (x, y), sensor length, spin, direction of spin, and type of the ARobot.
 *
 * @return QJsonObject The serialized representation of the ARobot.
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
 * @brief Move function to update the position of the ARobot.
 *
 * This function updates the position of the ARobot based on its current state. It calculates
 * the hit by calling the calculateHit function with the sensor length, checks for collisions
 * with other items, and adjusts the position accordingly. If a collision occurs with a barrierC
 * object, it updates the angle of the ARobot's movement. If no collision occurs, it continues
 * moving the ARobot based on its step size.
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
}