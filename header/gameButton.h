#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H

#include "global.h"

/**
 * @brief A class representing a game button.
 *
 * This class inherits from both QObject and QGraphicsRectItem to provide
 * functionality for creating interactive buttons within a QGraphicsScene.
 * @authors Jan Lindovský (xlindo04) Marcel Mravec(xmrave02)
 */
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
    void changeText(const char *textIn);
signals:
    void clicked();

private:
    QGraphicsTextItem *text;
};

#endif // GAMEBUTTON_H
