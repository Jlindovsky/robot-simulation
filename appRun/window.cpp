#include "window.h"
#include <QLineEdit>
#include <QIntValidator>
#include <QLabel>
#include <QHBoxLayout>

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
    delete editScene;
}

void window::mainWindow()
{
    gameButton *newGameButton = new gameButton(QString("new"), 400, 275, 200, 50);
    connect(newGameButton, SIGNAL(clicked()), this, SLOT(editWindowSignal()));
    welcomeScene->addItem(newGameButton);

    gameButton *loadGameButton = new gameButton(QString("new but blue"), 400, 475, 200, 50);
    QBrush brush(Qt::blue);
    loadGameButton->setBrush(brush);
    connect(loadGameButton, SIGNAL(clicked()), this, SLOT(editWindowSignal()));
    welcomeScene->addItem(loadGameButton);
}

void window::editWindowSignal()
{
    // set up the scene
    editScene = new QGraphicsScene();
    editScene->setSceneRect(0, 0, 1024, 768);
    setScene(editScene);

    QGraphicsRectItem *playground = new QGraphicsRectItem(0, 0, PLAY_W, PLAY_H);
    playground->setPos(PLAY_X, PLAY_Y);
    QPen pen;
    pen.setColor(Qt::white); // Set the border color (replace with your desired color)
    pen.setWidth(4);         // Set the border width (replace with your desired width)
    playground->setPen(pen);
    editScene->addItem(playground);

    editBuilder = new editControler(editScene);

    QBrush brush;

    barrierC *edgeTop = new barrierC(0, 0, PLAY_W, 1, playground);
    pen.setColor(Qt::black);
    edgeTop->setPen(pen);
    editScene->addItem(edgeTop);

    barrierC *edgeBottom = new barrierC(0, PLAY_H, PLAY_W, 1, playground);
    edgeBottom->setPen(pen);
    editScene->addItem(edgeBottom);

    barrierC *edgeLeft = new barrierC(0, 0, 1, PLAY_H, playground);

    edgeLeft->setPen(pen);
    editScene->addItem(edgeLeft);

    barrierC *edgeRight = new barrierC(PLAY_W, 0, 1, PLAY_H, playground);
    edgeRight->setPen(pen);
    editScene->addItem(edgeRight);

    barrierC *bar1 = new barrierC(250, 250, 100, 100, playground);
    pen.setColor(Qt::magenta);
    bar1->setPen(pen);
    editScene->addItem(bar1);

    barrierC *bar2 = new barrierC(50, 50, 100, 100, playground);
    bar2->setPen(pen);
    editScene->addItem(bar2);

    ARobot *rob1 = new ARobot(150, 150, 50, playground, 40, 1, 30);
    QBrush brushRob(Qt::blue);
    brushRob.setColor(Qt::darkMagenta);
    rob1->setBrush(brushRob);

    ARobot *rob2 = new ARobot(450, 450, 50, playground, 30, -1, 40);
    brushRob.setColor(Qt::yellow);
    rob2->setBrush(brushRob);

    ARobot *rob3 = new ARobot(450, 100, 50, playground, 20, 1, 50);
    brushRob.setColor(Qt::green);
    rob3->setBrush(brushRob);

    RCRobot *RCrob1 = new RCRobot(250, 100, 50, playground, 20);
    brushRob.setColor(Qt::green);
    RCrob1->setBrush(brushRob);

    RCRobot *RCrob2 = new RCRobot(20, 200, 50, playground, 20);
    brushRob.setColor(Qt::green);
    RCrob2->setBrush(brushRob);

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), rob1, SLOT(move()));
    QObject::connect(timer, SIGNAL(timeout()), rob2, SLOT(move()));
    QObject::connect(timer, SIGNAL(timeout()), rob3, SLOT(move()));
    timer->start(30);
    editScene->addItem(rob1);
    editScene->addItem(rob2);
    editScene->addItem(rob3);
    editScene->addItem(RCrob1);
    editScene->addItem(RCrob2);
}
