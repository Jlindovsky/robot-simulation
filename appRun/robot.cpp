#include "robot.h"

Robot::Robot(qreal x, qreal y, qreal w, qreal h, QGraphicsRectItem *parent)
    : QGraphicsEllipseItem(x, y, w, h, parent)
{
    circumference = 3;
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

Hitbox::Hitbox(Robot *r) : QGraphicsRectItem(0, 0, 60, 60, r)
{
    int offset = 10; // sensor sensitivity
    // welkej if else w a h
    // int hitboxX = x() - w / 2;
    // int hitboxY = y() - h / 2;
    setParent(r);
    QPen pen;
    pen.setWidth(4);
    pen.setColor(Qt::white);
    setPen(pen);
    setRotation(r->getAngle());
    setPos(mapToParent(0, 0));
}
void Hitbox::moveHitbox(Robot *r)
{
    double angleRadians = (90 - (int(r->getAngle()) % 90)) * M_PI / 180.0;

    // Calculate base and height
    double base = 1 * cos(angleRadians);
    double height = 1 * sin(angleRadians);
    if (r->getAngle() < 90 && r->getAngle() >= 0)
    {
        // setPos(x() + height, y() + base);
        setPos(mapToParent(height, base));
    }
    else if (r->getAngle() < 180 && r->getAngle() >= 90)
    {
        // setPos(x() - base, y() + height);
        setPos(mapToParent(0 - base, height));
    }
    else if (r->getAngle() < 270 && r->getAngle() >= 180)
    {
        // setPos(x() - height, y() - base);
        setPos(mapToParent(0 - height, 0 - base));
    }
    else
    {
        // setPos(x() + base, y() - height);
        setPos(mapToParent(base, 0 - height));
    }
}
void Robot::calculateMove()
{
    previousLocation = pos();
    // Convert angle to radians
    double angleRadians = (90 - (angle % 90)) * M_PI / 180.0;

    // Calculate base and height
    double base = step * cos(angleRadians);
    double height = step * sin(angleRadians);
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
    calculateMove();
    //  get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();
    bool hit = false;
    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(barrierC))
        {

            angle = ((angle + (directionOfSpin * spin)) + 360) % 360;
            hit = true;
            qDebug() << "Hit!"<<((colliding_items[i])) << Qt::endl;
        }
    }
    if (hit)
    {
        setPos(previousLocation);
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