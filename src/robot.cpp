#include "../header/robot.h"

/**
 * @brief Construct a new Robot:: Robot object
 * 
 * @param x 
 * @param y 
 * @param w 
 * @param parent 
 */
Robot::Robot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent)
    : QGraphicsEllipseItem(0, 0, w, w, parent)
{
    circumference = w / 2;
    angle = 270;
    this->setPos(mapToParent(x, y));
}

/**
 * @brief 
 * 
 * @param step1 
 */
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

/**
 * @brief 
 * 
 */
void Robot::move()
{
    qDebug() << "parent function";
}

/**
 * @brief 
 * 
 */
void Robot::moveUp()
{
    qDebug() << "parent function";
}

/**
 * @brief 
 * 
 */
void Robot::rotateLeft()
{
    qDebug() << "parent function";
}

/**
 * @brief 
 * 
 */
void Robot::rotateRight()
{
    qDebug() << "parent function";
}
