#ifndef BARRIERC_H
#define BARRIERC_H
#include <QGraphicsRectItem>
#include <QObject>

class barrierC : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    barrierC(qreal x, qreal y, qreal w, qreal h, QGraphicsRectItem *parent);
    virtual ~barrierC();
};
#endif