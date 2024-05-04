#include "editcontroler.h"
#include "global.h"


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
    void checkRCRInput();
    void stopTimer();
    void startTimer();
    void setActiveRCR(RCRobot *);
    void clickGrid();
    void saveGame();

    //      void playGame();
private:
    editControler *editBuilder;
    RCRobot *activeRCR;
    vector<ARobot *> ARobotVec;
    QGraphicsRectItem *playground;
    QTimer *timer;
    bool loading;
};
