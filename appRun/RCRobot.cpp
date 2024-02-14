#include "RCRobot.h"

RCRobot::RCRobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent,int sensorIN)
: Robot(x, y, w, parent)
{
    sensor = sensorIN;
    directionOfSpin = 1;
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void RCRobot::move()
{
    qDebug()<<"moving";
}
void RCRobot::handleKeyPressEvent(QKeyEvent*key)
{
//todo
}
void RCRobot::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    setFocus();
    qDebug()<<"cliked"<<(this)->pos();
}


