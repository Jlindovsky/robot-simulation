#include "../header/robot.h"
/** 
 * @brief this file consists of Robot method implementations
 * @authors Jan Lindovský (xlindo04) Marcel Mravec(xmrave02)
*/
/**
 * @brief Construct a new Robot object.
 *
 * @param x The x-coordinate of the robot's position.
 * @param y The y-coordinate of the robot's position.
 * @param w The width (diameter) of the robot.
 * @param parent The parent item of the robot.
 *
 * This constructor initializes a new Robot object with the specified position and dimensions.
 * The robot is represented by an ellipse item with the given diameter.
 * The angle is initialized to 270 degrees (facing upwards), and the position is set relative to its parent item.
 */
Robot::Robot(qreal x, qreal y, qreal w, QGraphicsRectItem *parent)
    : QGraphicsEllipseItem(0, 0, w, w, parent)
{
    circumference = w / 2;
    angle = 270;
    this->setPos(mapToParent(x, y));
}

/**
 * @brief Calculate the new position based on the current angle and step size.
 *
 * @param step1 The step size to move the robot.
 *
 * This method calculates the new position of the robot based on its current angle of orientation
 * and the specified step size. It converts the angle to radians, then calculates the horizontal
 * and vertical displacement using trigonometric functions. Finally, it updates the position of the
 * robot accordingly.
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
