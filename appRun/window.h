


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QList>

//UI controler
class window: public QGraphicsView{
    Q_OBJECT
public:
    window();
    ~window();
    void mainWindow();
    void editWindow();
    void playWindow();


public slots:
// void newGame();
//    void loadGame();
//    void chosenFile();
//    void playGame();

private:

    //scene atributes
    QGraphicsScene* scene;
    
};
