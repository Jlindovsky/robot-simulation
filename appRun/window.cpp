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
void window::setActiveRCR(RCRobot *rob)
{
    qDebug() << "activate";
    QPen peero;
    peero.setColor(Qt::green);
    if (activeRCR != nullptr)
    {
        peero.setWidth(0);
        activeRCR->setPen(peero);
    }
    peero.setWidth(4);
    activeRCR = rob;
    activeRCR->setPen(peero);
}
void window::moveUpActive()
{
    if (activeRCR)
        activeRCR->moveUp();
}
void window::rotateLeftActive()
{
    if (activeRCR)
        activeRCR->rotateLeft();
}
void window::rotateRightActive()
{
    if (activeRCR)
        activeRCR->rotateRight();
}

void window::checkARInput()
{
    auto slot = editBuilder->ASlot;
    auto sensorText = slot.sensorInput->text();
    auto directionText = slot.directionInput->text();
    auto spinText = slot.spinInput->text();

    int pos = 0;
    if (QValidator::Acceptable != slot.sensorValidator->validate(sensorText, pos))
    {
        // popup wrong input
        return;
    }
    if (QValidator::Acceptable != slot.directionValidator->validate(directionText, pos))
    {
        // popup wrong input
        return;
    }
    if (QValidator::Acceptable != slot.spinValidator->validate(spinText, pos))
    {
        // popup wrong input
        return;
    }

    ARobot *tmp = new ARobot(PLAY_X + 200, PLAY_Y + 200, SIZE_R, playground, (sensorText).toInt(), (directionText).toInt(), (spinText).toInt());

    QBrush brushRob(Qt::blue);
    brushRob.setColor(Qt::darkMagenta);
    tmp->setBrush(brushRob);
    QObject::connect(timer, SIGNAL(timeout()), tmp, SLOT(move()));
    editScene->addItem(tmp);
    ARobotVec.push_back(tmp);
}

void window::editWindowSignal()
{
    // set up the scene
    editScene = new QGraphicsScene();
    editScene->clear();
    editScene->setSceneRect(0, 0, 1024, 768);
    setScene(editScene);

    playground = new QGraphicsRectItem(0, 0, PLAY_W, PLAY_H);
    playground->setPos(PLAY_X, PLAY_Y);
    QPen pen;
    pen.setColor(Qt::white); // Set the border color (replace with your desired color)
    pen.setWidth(4);         // Set the border width (replace with your desired width)
    playground->setPen(pen);
    editScene->addItem(playground);

    editBuilder = new editControler(editScene);
    connect(editBuilder->bottomSlot.up, SIGNAL(clicked()), this, SLOT(moveUpActive()));
    connect(editBuilder->bottomSlot.right, SIGNAL(clicked()), this, SLOT(rotateRightActive()));
    connect(editBuilder->bottomSlot.left, SIGNAL(clicked()), this, SLOT(rotateLeftActive()));
    connect(editBuilder->ASlot.buildARobot, SIGNAL(clicked()), this, SLOT(checkARInput()));

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

    // ARobot *rob2 = new ARobot(450, 450, 50, playground, 30, -1, 40);
    // brushRob.setColor(Qt::yellow);
    // rob2->setBrush(brushRob);

    // ARobot *rob3 = new ARobot(450, 100, 50, playground, 20, 1, 50);
    // brushRob.setColor(Qt::green);
    // rob3->setBrush(brushRob);

    RCRobot *RCrob1 = new RCRobot(250, 100, 50, playground, 20);
    brushRob.setColor(Qt::white);
    RCrob1->setBrush(brushRob);
    editBuilder->bottomSlot.activable.push_back(RCrob1);
    // connect rob button
    connect(editBuilder->bottomSlot.robs[0], &gameButton::clicked, this, [=]()
            { setActiveRCR(RCrob1); });

    RCRobot *RCrob2 = new RCRobot(20, 200, 50, playground, 20);
    brushRob.setColor(Qt::white);
    RCrob2->setBrush(brushRob);
    editBuilder->bottomSlot.activable.push_back(RCrob2);
    // connect rob button
    connect(editBuilder->bottomSlot.robs[1], &gameButton::clicked, this, [=]()
            { setActiveRCR(RCrob2); });

    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), rob1, SLOT(move()));
    // QObject::connect(timer, SIGNAL(timeout()), rob2, SLOT(move()));
    // QObject::connect(timer, SIGNAL(timeout()), rob3, SLOT(move()));
    timer->start(30);
    editScene->addItem(rob1);
    // editScene->addItem(rob2);
    // editScene->addItem(rob3);
    editScene->addItem(RCrob1);
    editScene->addItem(RCrob2);
}
