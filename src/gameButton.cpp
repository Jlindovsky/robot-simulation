#include "../header/gameButton.h"


/**
 * @brief Construct a new game Button::game Button object
 * 
 * @param name 
 * @param x 
 * @param y 
 * @param w 
 * @param h 
 * @param parent 
 */
gameButton::gameButton(QString name, int x, int y, int w, int h, QGraphicsItem *parent)
{
    setParentItem(parent);
    setRect(0, 0, w, h);
    setPos(mapToParent(x, y));
    QBrush brush(Qt::darkCyan);
    brush.setStyle(Qt::SolidPattern);
    setBrush(brush);
    setFlag(QGraphicsItem::ItemIsFocusable, false);
    // draw the text
    text = new QGraphicsTextItem(name, this);
    int xPos = rect().width() / 2 - text->boundingRect().width() / 2;
    int yPos = rect().height() / 2 - text->boundingRect().height() / 2;
    text->setPos(xPos, yPos);
}

/**
 * @brief Destroy the game Button::game Button object
 * 
 */
gameButton::~gameButton()
{
    delete text;
}

/**
 * @brief 
 * 
 * @param textIn 
 */
void gameButton::changeText(const char *textIn)
{
    text->setPlainText(textIn);
}

/**
 * @brief 
 * 
 * @param event 
 */
void gameButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}
