#include "window.h"
#include <QLineEdit>
#include <QIntValidator>
#include <QLabel>
#include <QHBoxLayout>
#include <QMessageBox>

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
        QMessageBox::information(
            this,
            tr("Wrong Input"),
            tr("ERROR, Wrong input. Sensor length is from 0 to 100"));
        return;
    }
    if (QValidator::Acceptable != slot.directionValidator->validate(directionText, pos))
    {
        // popup wrong input
        QMessageBox::information(
            this,
            tr("Wrong Input"),
            tr("ERROR, Wrong input. Direction is -1 or 1"));
        return;
    }
    if (QValidator::Acceptable != slot.spinValidator->validate(spinText, pos))
    {
        // popup wrong input
        QMessageBox::information(
            this,
            tr("Wrong Input"),
            tr("ERROR, Wrong input. Spin is from 10 to 180"));
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

void window::checkRCRInput()
{
    auto slot = editBuilder->RCSlot;
    auto sensorText = slot.sensorInput->text();

    int pos = 0;
    if (QValidator::Acceptable != slot.sensorValidator->validate(sensorText, pos))
    {
        // popup wrong input
        QMessageBox::information(
            this,
            tr("Wrong Input"),
            tr("ERROR, Wrong input. Sensor length is from 0 to 100"));
        return;
    }

    RCRobot *tmp = new RCRobot(PLAY_X + 200, PLAY_Y + 200, SIZE_R, playground, (sensorText).toInt());
    QBrush brushRob(Qt::blue);
    brushRob.setColor(Qt::white);
    tmp->setBrush(brushRob);
    editBuilder->bottomSlot.activable.push_back(tmp);
    editScene->addItem(tmp);

    editBuilder->refresh(editScene);

    for (size_t i = 0; i < editBuilder->bottomSlot.activable.size(); i++)
    {
        connect(editBuilder->bottomSlot.robs[i], &gameButton::clicked, this, [=]()
                { setActiveRCR(editBuilder->bottomSlot.activable[i]); });
    }
}

void window::stopTimer()
{
    timer->stop();
}

void window::startTimer()
{
    timer->start(30);
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
    pen.setColor(Qt::white);
    pen.setWidth(4);
    playground->setPen(pen);
    editScene->addItem(playground);

    editBuilder = new editControler(editScene);
    connect(editBuilder->bottomSlot.up, SIGNAL(clicked()), this, SLOT(moveUpActive()));
    connect(editBuilder->bottomSlot.right, SIGNAL(clicked()), this, SLOT(rotateRightActive()));
    connect(editBuilder->bottomSlot.left, SIGNAL(clicked()), this, SLOT(rotateLeftActive()));
    connect(editBuilder->ASlot.buildARobot, SIGNAL(clicked()), this, SLOT(checkARInput()));
    connect(editBuilder->RCSlot.buildRCRobot, SIGNAL(clicked()), this, SLOT(checkRCRInput()));

    connect(editBuilder->playSlot.pause, SIGNAL(clicked()), this, SLOT(stopTimer()));
    connect(editBuilder->playSlot.play, SIGNAL(clicked()), this, SLOT(startTimer()));

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

    timer = new QTimer();

    timer->start(30);
}
