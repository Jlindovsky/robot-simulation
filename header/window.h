#include "editController.h"
#include "global.h"

/**
 * @brief 
 * 
 */
class window : public QGraphicsView
{
    Q_OBJECT
public:
    window();
    ~window();
    void mainWindow();
    void editWindow();
    void playWindow();
    void disconnectButtons();
    void connectButtons();

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
    void setActiveR(Robot *);
    void clickGrid();
    void saveGame();
    void deleteBot();

private:
    editController *editBuilder;
    RCRobot *activeRCR;
    Robot *activeR;
    QGraphicsRectItem *playground;
    QTimer *timer;
    bool gridOpen;
    vector<barrierC*> edges;
    ARobot * spawn;
};
