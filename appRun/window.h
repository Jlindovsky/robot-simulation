

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QList>
#include <QPen>
#include "gameButton.h"
#include "barrier.h"

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

public slots:
    //      void newGame();
    //      void loadGame();
    //      void chosenFile();
    //      void playGame();
    void editWindowSignal();

private:
    // scene atributes
    QGraphicsScene *welcomeScene;
    QGraphicsScene *editScene;
};
