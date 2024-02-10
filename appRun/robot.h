
#ifndef ROBOT_H
#define ROBOT_H
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QObject>
#include "barrier.h"

class Robot : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Robot(qreal x, qreal y, qreal w, qreal h, QGraphicsRectItem *parent);
public slots:
    void move();

private:
    int circumference;
    // public slots:
};
#endif