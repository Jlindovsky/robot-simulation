#ifndef EDITCONTROLLER_H
#define EDITCONTROLLER_H

#include "barrierC.h"
#include "robot.h"
#include "ARobot.h"
#include "RCRobot.h"
#include "gameButton.h"
#include "global.h"


/**
 * @brief
 *
 */
struct editSlotARobot
{
    unique_ptr<QGraphicsTextItem> name;

    unique_ptr<QGraphicsTextItem> sensorText;
    unique_ptr<QIntValidator> sensorValidator;
    unique_ptr<QLineEdit> sensorInput;

    unique_ptr<QGraphicsTextItem> directionText;
    unique_ptr<QIntValidator> directionValidator;
    unique_ptr<QLineEdit> directionInput;

    unique_ptr<QGraphicsTextItem> spinText;
    unique_ptr<QLineEdit> spinInput;
    unique_ptr<QIntValidator> spinValidator;

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
    vector<gameButton *> rcRobs;
    vector<gameButton *> aRobs;
    gameButton *up;
    gameButton *left;
    gameButton *right;
    gameButton *dlt;
};

struct pSlot
{
    gameButton *play;
    gameButton *pause;
    gameButton *save;
};

class editController : public QObject
{
    Q_OBJECT
public:
    editController(QGraphicsScene *scene);
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
    void refreshPause(QGraphicsScene *scene);
    void deleteRob(Robot *activeR);

    void buildRCRobot(QGraphicsRectItem *parent, QGraphicsScene *scene, int x, int y, int sensorIn);
    void buildARobot(QGraphicsRectItem *parent, QGraphicsScene *scene, int x, int y, int sensor, int directionOfSpin, int spin, QTimer *timer);
    void buildBar(QGraphicsRectItem *parent, QGraphicsScene *scene, int x, int y);

    editSlotARobot ASlot;
    editSlotRCRobot RCSlot;
    editSlotBarrier BARSlot;
    bSlot bottomSlot;
    pSlot playSlot;

    QGraphicsRectItem *iPanel;
    QGraphicsRectItem *rPanel;
    QGraphicsRectItem *pPanel;

    vector<gameButton *> barGrid;
    vector<ARobot *> aRobots;
    vector<RCRobot *> rcRobots;

public slots:
    void addBar(QGraphicsItem *parent, QGraphicsScene *scene);
    void dltBar(barrierC *bar, QGraphicsItem *parent, QGraphicsScene *scene);
};

#endif // EDITCONTROLLER_H
