#include "window.h"

window::window()
{
    // set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024, 768);

    // set up the scene
    welcomeScene = new QGraphicsScene();
    welcomeScene->setSceneRect(0, 0, 1024, 768);
    setScene(welcomeScene);
}

window::~window()
{
    delete welcomeScene;
}

void window::mainWindow()
{
    gameButton *newGameButton = new gameButton(QString("new"));
    int bxPos = this->width() / 2 - newGameButton->boundingRect().width() / 2;
    int byPos = 275;
    newGameButton->setPos(bxPos, byPos);
    connect(newGameButton, SIGNAL(clicked()), this, SLOT(editWindowSignal()));
    welcomeScene->addItem(newGameButton);

    gameButton *loadGameButton = new gameButton(QString("new"));
    bxPos = this->width() / 2 - loadGameButton->boundingRect().width() / 2;
    byPos = 475;
    loadGameButton->setPos(bxPos, byPos);
    connect(loadGameButton, SIGNAL(clicked()), this, SLOT(start()));
    welcomeScene->addItem(loadGameButton);
}
void window::editWindowSignal()
{
    // set up the scene
    editScene = new QGraphicsScene();
    editScene->setSceneRect(0, 0, 1024, 768);
    setScene(editScene);

    QGraphicsRectItem *playground = new QGraphicsRectItem(100, 100, 500, 500);
    playground->setPos(100,100);
    QPen pen;
    pen.setColor(Qt::white); // Set the border color (replace with your desired color)
    pen.setWidth(4);         // Set the border width (replace with your desired width)
    playground->setPen(pen);
    editScene->addItem(playground);

    QGraphicsRectItem *bar1 = new QGraphicsRectItem(0, 0, 30, 30, playground);
    bar1->setPos(playground->pos());
    pen.setColor(Qt::cyan);
    bar1->setPen(pen);
    pen.setColor(Qt::white);
    editScene->addItem(bar1);

    QGraphicsRectItem *bar2 = new QGraphicsRectItem(playground->x(), playground->y(), 20, 20, playground);
    bar2->setPos(200, 200);
    bar2->setPos(-100, -100);
    bar2->setPen(pen);
    editScene->addItem(bar2);

    QGraphicsRectItem *bar3 = new QGraphicsRectItem(playground->x(), playground->y(), 10, 10, playground);
    bar3->setPos(200, 40);
    pen.setColor(Qt::red);
    bar3->setPen(pen);
    editScene->addItem(bar3);

}
