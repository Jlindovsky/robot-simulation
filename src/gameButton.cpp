#include "../header/gameButton.h"
/** 
 * @brief this file consists of gameButton method implementations
 * @authors Jan Lindovský (xlindo04) Marcel Mravec(xmrave02)
*/
/**
 * @brief Construct a new gameButton object.
 *
 * This constructor initializes a gameButton object with the specified name, position,
 * width, height, and parent QGraphicsItem. It sets up the appearance of the button
 * and positions the text label in the center.
 *
 * @param name The text displayed on the button.
 * @param x The x-coordinate of the button's top-left corner.
 * @param y The y-coordinate of the button's top-left corner.
 * @param w The width of the button.
 * @param h The height of the button.
 * @param parent The parent QGraphicsItem to which the button belongs.
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
 * @brief Destroy the gameButton object.
 *
 * This destructor is responsible for deallocating any resources
 * held by the gameButton object upon its destruction, particularly
 * the QGraphicsTextItem used for displaying the button's text.
 */
gameButton::~gameButton()
{
    delete text;
}

/**
 * @brief Change the text displayed on the gameButton.
 *
 * This function updates the text displayed on the gameButton to the provided text.
 *
 * @param textIn The new text to be displayed on the gameButton.
 */
void gameButton::changeText(const char *textIn)
{
    text->setPlainText(textIn);
}

/**
 * @brief Handle the mouse press event for the gameButton.
 *
 * This function is called when the mouse is pressed on the gameButton.
 * It emits the clicked() signal to indicate that the button has been clicked.
 *
 * @param event A pointer to the QGraphicsSceneMouseEvent object representing the mouse press event.
 */
void gameButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}
