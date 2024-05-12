#include "editController.h"
#include "global.h"

/**
 * @brief A class representing the main window of the application.
 *
 * This class inherits from QGraphicsView and serves as the main graphical user interface for the application.
 * It contains functionality for displaying different windows, handling user input, managing game elements, and
 * connecting signals and slots for communication between objects.
 * @authors Jan Lindovský (xlindo04) Marcel Mravec(xmrave02)
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
    gameButton *newGameButton;
    gameButton *loadGameButton;
    editController *editBuilder;
    RCRobot *activeRCR;
    Robot *activeR;
    QGraphicsRectItem *playground;
    QTimer *timer;
    bool gridOpen;
    vector<barrierC *> edges;
    ARobot *spawn;
};
