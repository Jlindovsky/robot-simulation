#include "RCRobot.h"

RCRobot::RCRobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent, int sensorIN)
    : Robot(x, y, w, parent)
{
    sensor = sensorIN;
    directionOfSpin = 1;
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void RCRobot::moveWithKey(QKeyEvent *event)
{
    if (event->key() == UPARROW)
    {
        qDebug() << "moving up";
    }
    else if (event->key() == LARROW)
    {
        qDebug() << "rotate Left";
    }
    else if (event->key() == RARROW)
    {
        qDebug() << "rotate Right";
    }
    else
    {
        qDebug() << "jinej klic";
    }
}
void RCRobot::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setFocus();
    qDebug() << "cliked" << (this)->pos();
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

            angle = ((angle + (directionOfSpin * spin)) + 360) % 360;
            hit = true;
           // qDebug() << "Hit!" << ((colliding_items[i])) << Qt::endl;
        }
    }
    setPos(previousLocation);
}
void RCRobot::rotateLeft()
{
    angle += (spin+360)+360;
}
void RCRobot::rotateRight()
{
    angle -= (spin+360)+360;
}
