#ifndef BARRIERC_H
#define BARRIERC_H

#include "global.h"

class barrierC : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    barrierC();
    barrierC(qreal x, qreal y, QGraphicsRectItem *parent);
    barrierC(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent);
    virtual ~barrierC();

    // void mousePressEvent(QMouseEvent *event) override;
    // void mouseMoveEvent(QMouseEvent *event) override;
    // void dragEnterEvent(QDragEnterEvent *event) override;
    // void dropEvent(QDropEvent *event) override;
};
#endif