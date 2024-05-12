#ifndef BARRIERC_H
#define BARRIERC_H

#include "global.h"

/**
 * @brief A class representing a barrier.
 * 
 * This class inherits from both QObject and QGraphicsRectItem to provide functionality
 * for creating barriers within a QGraphicsScene.
 * @authors Jan Lindovský (xlindo04) Marcel Mravec(xmrave02)
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