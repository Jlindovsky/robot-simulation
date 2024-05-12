#include "../header/barrierC.h"
/** 
 * @brief this file consists of barrierC method implementations
 * @authors Jan Lindovský (xlindo04) Marcel Mravec(xmrave02)
*/
/**
 * @brief Construct a new barrierC object.
 *
 * This constructor initializes a barrierC object with the specified position and parent.
 * It sets the position of the barrierC relative to its parent QGraphicsRectItem.
 *
 * @param x The x-coordinate of the barrierC's top-left corner.
 * @param y The y-coordinate of the barrierC's top-left corner.
 * @param parent The parent QGraphicsRectItem to which the barrierC belongs.
 */
barrierC::barrierC(qreal x, qreal y, QGraphicsRectItem *parent)
    : QGraphicsRectItem(0, 0, SIZE_B, SIZE_B, parent)
{
    this->setPos(mapToParent(x, y));
}

/**
 * @brief Construct a new barrierC object with specified dimensions.
 *
 * This constructor initializes a barrierC object with the specified position, width, height,
 * and parent. It sets the position of the barrierC relative to its parent QGraphicsItem and
 * sets its dimensions accordingly.
 *
 * @param x The x-coordinate of the barrierC's top-left corner.
 * @param y The y-coordinate of the barrierC's top-left corner.
 * @param w The width of the barrierC.
 * @param h The height of the barrierC.
 * @param parent The parent QGraphicsItem to which the barrierC belongs.
 */
barrierC::barrierC(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent)
    : QGraphicsRectItem(0, 0, w, h, parent)
{

    this->setPos(mapToParent(x, y));
}

/**
 * @brief Construct a new barrierC object with default size.
 *
 * This constructor initializes a barrierC object with the default size
 * and position at the origin (0, 0).
 */
barrierC::barrierC() : QGraphicsRectItem(0, 0, SIZE_B, SIZE_B) {}
