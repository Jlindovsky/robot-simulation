
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QList>
#include <QPen>
#include <QTimer>
#include "gameButton.h"
#include "barrier.h"
#include "robot.h"

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
    QGraphicsScene *welcomeScene;
    QGraphicsScene *editScene;

public slots:
    //      void newGame();
    //      void loadGame();
    //      void chosenFile();
    void editWindowSignal();
    //      void playGame();

private:
    // scene atributes
};
