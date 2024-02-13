#include "robot.h"

Robot::Robot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent)
    : QGraphicsEllipseItem(x, y, w, w, parent)
{
    sensor = 40;
    circumference = w/2;
    angle = 270;
    directionOfSpin = 1; // tmp
    step = 20;
    spin = 35; // tmp
    this->setPos(mapToParent(300, 300));
    // hitbox = new Hitbox(this);
}
qreal Robot::getAngle()
{
    return this->angle;
}

void Robot::calculateHit(int step1)
{
    previousLocation = pos();
    // Convert angle to radians
    double angleRadians = (90 - (angle % 90)) * M_PI / 180.0;

    // Calculate base and height
    double base = step1 * cos(angleRadians);
    double height = step1 * sin(angleRadians);
    if (angle < 90 && angle >= 0)
    {
        setPos(x() + height, y() + base);
    }
    else if (angle < 180 && angle >= 90)
    {
        setPos(x() - base, y() + height);
    }
    else if (angle < 270 && angle >= 180)
    {
        setPos(x() - height, y() - base);
    }
    else
    {
        setPos(x() + base, y() - height);
    }
}
void Robot::move()
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
            qDebug() << "Hit!" << ((colliding_items[i])) << Qt::endl;
        }
    }
    if (hit)
    {
        setPos(previousLocation);
    }
    else
    {

    }
    // scene()->removeItem(hitbox);
    // delete (hitbox);
    // hitbox = nullptr;
    // qDebug() << x() << y() << Qt::endl;

    // hitbox->setRotation(this->getAngle());
    // if (!hit)
    // {
    //     hitbox->moveHitbox(this);
    //     calculateMove();
    // }
    // qDebug() << x() << y() << angle << Qt::endl;
}