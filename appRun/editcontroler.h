#ifndef EDITCONTROLER_H
#define EDITCONTROLER_H

#include <QObject>
#include <QLineEdit>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "barrierC.h"
#include "robot.h"
#include "ARobot.h"
#include "RCRobot.h"
#include "gameButton.h"
#include <vector>
#include <qvalidator.h>
using namespace std;

// InsertPanel sizes
#define IPANEL_X 0
#define IPANEL_Y 0
#define IPANEL_W 200
#define IPANEL_H 650
// PlayStop panel sizes
#define PPANEL_X 0
#define PPANEL_Y 650
#define PPANEL_W 200
#define PPANEL_H 168
// RC panel sizes
#define RPANEL_X 200
#define RPANEL_Y 650
#define RPANEL_W 824
#define RPANEL_H 168

enum inputType
{
    BAR,
    AR,
    RCR,
    NTH
};

struct editSlotARobot
{
    QGraphicsTextItem *name;

    QGraphicsTextItem *sensorText;
    QIntValidator *sensorValidator;
    QLineEdit *sensorInput;

    QGraphicsTextItem *directionText;
    QIntValidator *directionValidator;
    QLineEdit *directionInput;

    QGraphicsTextItem *spinText;
    QLineEdit *spinInput;
    QIntValidator *spinValidator;

    gameButton *buildARobot;

    ARobot *rob;
};

struct editSlotRCRobot
{
    QGraphicsTextItem *name;

    QGraphicsTextItem *sensorText;
    QIntValidator *sensorValidator;
    QLineEdit *sensorInput;

    gameButton *buildRCRobot;

    RCRobot *rob;
};

struct editSlotBarrier
{
    QGraphicsTextItem *name;
    gameButton *buildBarrier;
    barrierC *bar;
};

struct bottomSlot
{
    //active robots
    vector<RCRobot*> activable;
    gameButton *up;
    gameButton *left;
    gameButton *right;
};

struct playSlot
{
    gameButton *play;
    gameButton *pause;
    gameButton *save;
};

class editControler
{
public:
    editControler(QGraphicsScene *scene);
    void buildAREdit(QGraphicsItem *parent, QGraphicsScene *scene);
    void buildRCREdit(QGraphicsItem *parent, QGraphicsScene *scene);
    void buildBAREdit(QGraphicsItem *parent, QGraphicsScene *scene);

private:
    editSlotARobot ASlot;
    editSlotRCRobot RCSlot;
    editSlotBarrier BSlot;
};

#endif // EDITCONTROLER_H
