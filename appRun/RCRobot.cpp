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
void RCRobot::handleKeyPressEvent(QKeyEvent *key)
{
    // todo
}
void RCRobot::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setFocus();
    qDebug() << "cliked" << (this)->pos();
}
