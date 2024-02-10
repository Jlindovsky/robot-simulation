#include "robot.h"

Robot::Robot(qreal x, qreal y, qreal w, qreal h, QGraphicsRectItem *parent)
    : QGraphicsEllipseItem(x, y, w, h, parent)
{
    circumference = 3;
}

void Robot::move()
{
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        //qDebug() <<"||" << "||"<<dynamic_cast<QObject*>(colliding_items[i]) <<"||"<<(this->parent());
        if (typeid(*(colliding_items[i])) == typeid(barrierC))
        {
            return;
        }
    }

    // if there was no collision with an Enemy, move the bullet forward
    setPos(x(), y() - 10);
    // if the bullet is off the screen, destroy it
    if (pos().y() + rect().height() < 0)
    {
       // editScene->removeItem(this);
        delete this;
    }
}