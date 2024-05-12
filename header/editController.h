#ifndef EDITCONTROLLER_H
#define EDITCONTROLLER_H

#include "barrierC.h"
#include "robot.h"
#include "ARobot.h"
#include "RCRobot.h"
#include "gameButton.h"
#include "global.h"

/**
 * @brief Structures and class for controlling the editing interface.
 *
 * This header file defines several structures and a class responsible for managing
 * the editing interface of the application. It includes functionality for building
 * and editing different game elements such as robots, barriers, and controls.
 * @authors Jan Lindovský (xlindo04) Marcel Mravec(xmrave02)
 */
/**
 * @brief Structure for managing UI elements and data associated with editing properties of an ARobot.
 *
 * This structure contains pointers to UI elements such as QGraphicsTextItem and QLineEdit for displaying and editing
 * properties of an ARobot. It also includes a pointer to a gameButton for building the ARobot.
 *
 * The structure facilitates the organization and manipulation of UI components related to ARobot editing.
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
    ~editSlotARobot();
};

/**
 * @brief Structure for managing UI elements and data associated with editing properties of an RCRobot.
 *
 * This structure contains pointers to UI elements such as QGraphicsTextItem and QLineEdit for displaying and editing
 * properties of an RCRobot. It also includes a pointer to a gameButton for building the RCRobot.
 *
 * The structure facilitates the organization and manipulation of UI components related to RCRobot editing.
 */
struct editSlotRCRobot
{
    QGraphicsTextItem *name;

    QGraphicsTextItem *sensorText;
    QIntValidator *sensorValidator;
    QLineEdit *sensorInput;

    gameButton *buildRCRobot;

    RCRobot *rob;
    ~editSlotRCRobot();
};

/**
 * @brief Structure for managing UI elements and data associated with editing properties of barriers.
 *
 * This structure contains vectors of pointers to barriers and game buttons, as well as pointers to UI elements
 * such as QGraphicsTextItem for displaying barrier information.
 *
 * The structure facilitates the organization and manipulation of UI components related to barrier editing.
 */
struct editSlotBarrier
{
    vector<barrierC *> bars;
    QGraphicsTextItem *name;
    gameButton *buildBarrier;
    barrierC *bar;
    ~editSlotBarrier();
};

/**
 * @brief Structure for managing UI elements associated with bottom panel buttons.
 *
 * This structure contains vectors of pointers to game buttons for controlling different aspects of the game,
 * such as controlling robots and deleting elements. It also includes individual pointers to specific buttons.
 *
 * The structure facilitates the organization and manipulation of UI components related to bottom panel buttons.
 */
struct bSlot
{
    vector<gameButton *> rcRobs;
    vector<gameButton *> aRobs;
    gameButton *up;
    gameButton *left;
    gameButton *right;
    gameButton *dlt;
    ~bSlot();
};

/**
 * @brief Structure for managing UI elements associated with play panel buttons.
 *
 * This structure contains pointers to game buttons for controlling the play state of the game,
 * such as playing, pausing, and saving the game.
 *
 * The structure facilitates the organization and manipulation of UI components related to play panel buttons.
 */
struct pSlot
{
    gameButton *play;
    gameButton *pause;
    gameButton *save;
    ~pSlot();
};

/**
 * @brief Controller class for managing the editing interface.
 *
 * This class is responsible for managing the editing interface of the application.
 * It provides methods for building and editing different game elements such as robots, barriers, and controls.
 */
class editController : public QObject
{
    Q_OBJECT
public:
    editController(QGraphicsScene *scene);
    ~editController();
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
    void buildRCRobot(QGraphicsRectItem *parent, QGraphicsScene *scene, int x, int y, int sensorIn, int angleIN);
    void buildARobot(QGraphicsRectItem *parent, QGraphicsScene *scene, int x, int y, int sensor, int directionOfSpin, int spin, QTimer *timer, int angleIN);
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
