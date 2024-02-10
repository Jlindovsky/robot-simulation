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

    QGraphicsRectItem *playground = new QGraphicsRectItem(70, 100, 500, 500);
    playground->setPos(70, 100);
    QPen pen;
    pen.setColor(Qt::white); // Set the border color (replace with your desired color)
    pen.setWidth(4);         // Set the border width (replace with your desired width)
    playground->setPen(pen);
    editScene->addItem(playground);


    barrierC *edgeTop = new barrierC(playground->x(), playground->y(), 500, 1, playground);
    edgeTop->setPos(0,0);
    pen.setColor(Qt::cyan);
    edgeTop->setPen(pen);
    editScene->addItem(edgeTop);

    barrierC *edgeBottom = new barrierC(playground->x(), playground->y(), 500, 1, playground);
    edgeBottom->setPos(0, 500);
    edgeBottom->setPen(pen);
    editScene->addItem(edgeBottom);

    barrierC *edgeLeft = new barrierC(playground->x(), playground->y(), 1, 500, playground);
    edgeLeft->setPos(0, 0);
    pen.setColor(Qt::red);
    edgeLeft->setPen(pen);
    editScene->addItem(edgeLeft);

    barrierC *edgeRight = new barrierC(playground->x(), playground->y(), 1, 500, playground);
    edgeRight->setPos(500, 0);
    edgeRight->setPen(pen);
    editScene->addItem(edgeRight);

    Robot *rob1 = new Robot(playground->x(), playground->y(), 50, 50, playground);
    rob1->setPos(playground->x(), playground->y());
    QBrush brush(Qt::blue);
    brush.setColor(Qt::darkMagenta);
    rob1->setBrush(brush);

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), rob1, SLOT(move()));
    timer->start(70);

    editScene->addItem(rob1);
}
