#include "barrierC.h"

barrierC::barrierC(qreal x, qreal y, QGraphicsRectItem *parent)
    : QGraphicsRectItem(0, 0, SIZE_B, SIZE_B, parent)
{

    this->setPos(mapToParent(x, y));
    // hitbox = new Hitbox(this);
    // Additional initialization code specific to barrierC if needed
}
barrierC::barrierC(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent)
    : QGraphicsRectItem(0, 0, w, h, parent)
{

    this->setPos(mapToParent(x, y));
    // hitbox = new Hitbox(this);
    // Additional initialization code specific to barrierC if needed
}
barrierC::barrierC() : QGraphicsRectItem(0, 0, SIZE_B, SIZE_B) {}
barrierC::~barrierC() {}
