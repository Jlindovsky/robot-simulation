#include "../header/barrierC.h"

/**
 * @brief Construct a new barrier C::barrier C object
 *
 * @param x
 * @param y
 * @param parent
 */
barrierC::barrierC(qreal x, qreal y, QGraphicsRectItem *parent)
    : QGraphicsRectItem(0, 0, SIZE_B, SIZE_B, parent)
{

    this->setPos(mapToParent(x, y));
    // hitbox = new Hitbox(this);
    // Additional initialization code specific to barrierC if needed
}

/**
 * @brief Construct a new barrier C::barrier C object
 *
 * @param x
 * @param y
 * @param w
 * @param h
 * @param parent
 */
barrierC::barrierC(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent)
    : QGraphicsRectItem(0, 0, w, h, parent)
{

    this->setPos(mapToParent(x, y));
    // hitbox = new Hitbox(this);
    // Additional initialization code specific to barrierC if needed
}
/**
 * @brief Construct a new barrier C::barrier C object
 *
 */
barrierC::barrierC() : QGraphicsRectItem(0, 0, SIZE_B, SIZE_B) {}
/**
 * @brief Destroy the barrier C::barrier C object
 *
 */
barrierC::~barrierC() {}
