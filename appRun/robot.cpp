#include "robot.h"

Robot::Robot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent)
    : QGraphicsEllipseItem(0, 0, w, w, parent)
{

    circumference = w / 2;
    angle = 270;
    this->setPos(mapToParent(x, y));
    // hitbox = new Hitbox(this);
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
    qDebug()<<"parent function";
}

void Robot::focusInEvent(QFocusEvent *event)
{
    qDebug() << "Item gained focus"<<event;
    QGraphicsItem::focusInEvent(event);
    // Set a flag or perform actions when the item gains focus
}
void Robot::focusOutEvent(QFocusEvent *event)
{
    QGraphicsItem::focusOutEvent(event);
    qDebug() << "Item lost focus";
    // Set a flag or perform actions when the item loses focus
}
