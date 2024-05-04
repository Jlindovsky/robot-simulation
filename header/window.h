#include "editController.h"
#include "global.h"

// UI controller
class window : public QGraphicsView
{
    Q_OBJECT
public:
    window();
    ~window();
    void mainWindow();
    void editWindow();
    void playWindow();

    QGraphicsScene *welcomeScene;
    QGraphicsScene *editScene;

public slots:
    void editWindowSignal();
    void loadFromFile();
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

private:
    editController *editBuilder;
    RCRobot *activeRCR;
    vector<ARobot *> ARobotVec;
    QGraphicsRectItem *playground;
    QTimer *timer;
    bool gridOpen;
};
