#ifndef BARRIERC_H
#define BARRIERC_H

#include "global.h"

/**
 * @brief 
 * 
 */
class barrierC : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    barrierC();
    barrierC(qreal x, qreal y, QGraphicsRectItem *parent);
    barrierC(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent);
};

#endif