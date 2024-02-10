#include "robot.h"

Robot::Robot(qreal x, qreal y, qreal w, qreal h, QGraphicsRectItem *parent)
    : QGraphicsEllipseItem(x, y, w, h, parent)
{
    circumference = 3;
    angle = 270;
    directionOfSpin = 1; // tmp
    step = 20;
    spin = 90; // tmp
}
void Robot::calculateMove()
{
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
        qDebug() << "270 text" << base << height;
        setPos(x() + base, y() - height);
    }
}

void Robot::generateHitbox()
{
    qDebug() << "fger" << x() << y();
    // welkej if else w a h
    int w = 100, h = 100;
    int hitboxX = x() - w / 2;
    int hitboxY = y() - h / 2;
    hitbox = new QGraphicsRectItem(0, 0, w, h, this);//dynamic_cast<QGraphicsItem *>(this));
    hitbox->setPos(0,0);
    // hitbox->setPos(this->pos()); //podle toho kam cumis
    QPen pen;
    pen.setColor(Qt::white);
    hitbox->setPen(pen);
    scene()->addItem(hitbox);
}

void Robot::move()
{
    generateHitbox();
    //  get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = hitbox->collidingItems();
    bool hit = false;
    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        // qDebug() <<"||" << "||"<<dynamic_cast<QObject*>(colliding_items[i]) <<"||"<<(this->parent());
        if (typeid(*(colliding_items[i])) == typeid(barrierC)) // || typeid(*(colliding_items[i])) != typeid(QGraphicsRectItem) )
        {
            angle = ((angle + (directionOfSpin * spin)) + 360) % 360;
            hit = true;
        }
    }
    // scene()->removeItem(hitbox);
    // delete (hitbox);
    qDebug() << x() << y() << Qt::endl;
    // if (!hit)
    calculateMove();
    qDebug() << x() << y() << angle << Qt::endl;
}