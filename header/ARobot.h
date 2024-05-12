#ifndef AROBOT_H
#define AROBOT_H

#include "robot.h"
#include "global.h"

/**
 * @brief A class representing an autonomous robot (ARobot).
 *
 * This class inherits from the Robot class and extends its functionality to include
 * methods for controlling an autonomous robot's movement.
 * @authors Jan Lindovský (xlindo04) Marcel Mravec(xmrave02)
 */
class ARobot : public Robot
{
public:
    ARobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent, int sensorIn, int directionOfSpinIn, int spinIn);
    ARobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent, int sensorIn, int directionOfSpinIn, int spinIn, int angleIN);
    QJsonObject save() override;
public slots:
    void move(); // override;
};

#endif