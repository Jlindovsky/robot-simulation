#ifndef RCROBOT_H
#define RCROBOT_H

#include "robot.h"
#include <QKeyEvent>

class RCRobot : public Robot
{
public:
    RCRobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent, int sensorIN);
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
   // void keyPressEvent(QKeyEvent * event)override;
    void handleKeyPressEvent(QKeyEvent* event);
public slots:
    void move() override;

};

#endif