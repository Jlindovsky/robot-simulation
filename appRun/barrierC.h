#ifndef BARRIERC_H
#define BARRIERC_H
#include <QGraphicsRectItem>
#include <QObject>
#include "global.h"

class barrierC : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    barrierC();
    barrierC(qreal x, qreal y, QGraphicsRectItem *parent);
    barrierC(qreal x, qreal y, qreal w, qreal h, QGraphicsRectItem *parent);
    virtual ~barrierC();
};
#endif