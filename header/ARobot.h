#ifndef AROBOT_H
#define AROBOT_H

#include "robot.h"
#include "global.h"

/**
 * @brief 
 * 
 */
class ARobot : public Robot
{
public:
    ARobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent, int sensorIn, int directionOfSpinIn, int spinIn);
    QJsonObject save()override;
public slots:
    void move();//override;
};

#endif