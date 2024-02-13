#include "gameButton.h"

gameButton::gameButton(QString name, int x, int y, int w, int h, QGraphicsItem *parent)
{
    setRect(0, 0, w, h);
    setPos(x, y);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
    setParentItem(parent);
    // draw the text
    text = new QGraphicsTextItem(name, this);
    int xPos = rect().width() / 2 - text->boundingRect().width() / 2;
    int yPos = rect().height() / 2 - text->boundingRect().height() / 2;
    text->setPos(xPos, yPos);
}

void gameButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}
