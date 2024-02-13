
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QList>
#include <QPen>
#include <QTimer>
#include "gameButton.h"
#include "barrierC.h"
#include "robot.h"

typedef enum inputType
{
    BAR,
    AR,
    RCR,
    NTH
}inputType;

typedef struct inputData
{
    inputType which;
    union data
    {
        barrierC * bar;
        Robot * ar;
        Robot * rcr;
    };
}inputData;


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
    void clickInEdit(inputData *,int,int);
    //      void playGame();

private:
    // scene atributes
};
