#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>

class gameButton: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    // constructors
    gameButton(QString name, QGraphicsItem* parent=NULL);

    // public methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    // possible extras
    //void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    //void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem* text;
};

#endif // GAMEBUTTON_H
