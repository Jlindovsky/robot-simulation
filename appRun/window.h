
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QList>
#include <QPen>
#include <QTimer>

#include "editcontroler.h"
// lib refactor

#define SIZE_R 50
#define SIZE_B 75
// Playground sizes
#define PLAY_X 200
#define PLAY_Y 0
#define PLAY_W 824
#define PLAY_H 650
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

typedef struct inputData
{
    inputType which;
    union data
    {
        barrierC *bar;
        Robot *ar;
        Robot *rcr;
    };
} inputData;

// UI controler
class window : public QGraphicsView
{
    Q_OBJECT
public:
    window();
    ~window();
    void mainWindow();
    void editWindow();
    void playWindow();
    // void keyPressEvent(QKeyEvent*event)override; maybe some other time
    QGraphicsScene *welcomeScene;
    QGraphicsScene *editScene;

public slots:
    void editWindowSignal();
    void clickInEdit(inputData *, int, int);
    void moveUpActive();
    void rotateLeftActive();
    void rotateRightActive();
    void checkARInput();
    void stopTimer();
    void startTimer();
    void setActiveRCR(RCRobot *);
    //      void playGame();
private:
    editControler *editBuilder;
    RCRobot *activeRCR;
    vector<ARobot *> ARobotVec;
    QGraphicsRectItem *playground;
    QTimer *timer;
};
