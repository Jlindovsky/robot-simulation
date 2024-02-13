#include "barrierC.h"

barrierC::barrierC(qreal x, qreal y, qreal w, qreal h, QGraphicsRectItem *parent)
    : QGraphicsRectItem(0, 0, w, h, parent)
{

    this->setPos(mapToParent(x, y));
    // hitbox = new Hitbox(this);
    // Additional initialization code specific to barrierC if needed
}
barrierC::~barrierC() {}
