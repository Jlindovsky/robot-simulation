
#ifndef ROBOT_H
#define ROBOT_H

#include "barrierC.h"
#include "global.h"

/**
 * @brief parent class for Robots
 * owns attributes and method for hit detection
 * 
 */
class Robot : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Robot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent);
    void calculateHit(int step);
    virtual QJsonObject save() = 0;
public slots:
    // virtual void move();
    // virtual void moveUp();
    // virtual void rotateLeft();
    // virtual void rotateRight();
signals:
    void clicked();

protected:
    QPointF previousLocation;
    int circumference;
    int directionOfSpin; // ±1
    int angle;           // [0-360] actual direction
    int step;
    int sensor;
    int spin;
    // public slots:
};

#endif
