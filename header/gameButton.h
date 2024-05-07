#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H

#include "global.h"

class gameButton : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    // constructors
    gameButton(QString name, int x, int y, int w, int h, QGraphicsItem *parent = NULL);
    ~gameButton();
    // public methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    // possible extras
    // void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    // void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void changeText(const char * textIn);
signals:
    void clicked();

private:
    QGraphicsTextItem *text;
};

#endif // GAMEBUTTON_H
