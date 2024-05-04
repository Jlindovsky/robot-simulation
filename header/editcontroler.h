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
    vector<barrierC *> bars;
    QGraphicsTextItem *name;
    gameButton *buildBarrier;
    barrierC *bar;
};

struct bSlot
{
    // active robots
    vector<RCRobot *> activable;
    vector<gameButton *> robs;
    gameButton *up;
    gameButton *left;
    gameButton *right;
};

struct pSlot
{
    gameButton *play;
    gameButton *pause;
    gameButton *save;
};

class editControler : public QObject
{
    Q_OBJECT
public:
    editControler(QGraphicsScene *scene);
    void buildAREdit(QGraphicsItem *parent, QGraphicsScene *scene);
    void buildRCREdit(QGraphicsItem *parent, QGraphicsScene *scene);
    void buildBAREdit(QGraphicsItem *parent, QGraphicsScene *scene);
    void buildControlsEdit(QGraphicsItem *parent, QGraphicsScene *scene);
    void buildPlayEdit(QGraphicsItem *parent, QGraphicsScene *scene);
    void buildBarGrid(QGraphicsItem *parent, QGraphicsScene *scene);
    void placeBar(gameButton *button, QGraphicsItem *parent, QGraphicsScene *scene);
    void deleteBarGrid();
    void gridRefresh(QGraphicsItem *parent, QGraphicsScene *scene);
    void refresh(QGraphicsScene *scene);

    editSlotARobot ASlot;
    editSlotRCRobot RCSlot;
    editSlotBarrier BARSlot;
    bSlot bottomSlot;
    pSlot playSlot;

    QGraphicsRectItem *iPanel;
    QGraphicsRectItem *rPanel;
    QGraphicsRectItem *pPanel;

    vector<gameButton *> barGrid;
    bool inBarEdit;

public slots:
    void addBar(QGraphicsItem *parent, QGraphicsScene *scene);
    void dltBar(barrierC *bar, QGraphicsItem *parent, QGraphicsScene *scene);
};

#endif // EDITCONTROLER_H
