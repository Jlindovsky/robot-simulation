#ifndef RCROBOT_H
#define RCROBOT_H

#include "robot.h"
#include "global.h"


#define UPARROW 16777235
#define LARROW 16777234
#define RARROW 16777236

class RCRobot : public Robot
{
public:
    RCRobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent, int sensorIN);
    // void keyPressEvent(QKeyEvent * event)override;
    void moveUp();
    void rotateLeft();
    void rotateRight();
};

#endif