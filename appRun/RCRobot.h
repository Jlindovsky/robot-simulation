#ifndef RCROBOT_H
#define RCROBOT_H

#include "robot.h"
#include <QKeyEvent>

#define UPARROW 16777235
#define LARROW 16777234
#define RARROW 16777236

class RCRobot : public Robot
{
public:
    RCRobot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent, int sensorIN);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    // void keyPressEvent(QKeyEvent * event)override;

public slots:
    void moveWithKey(QKeyEvent *event);
    void moveUp();
    void rotateLeft();
    void rotateRight();
};

#endif