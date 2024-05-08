
#include "../header/window.h"
#include "../header/global.h"


window * game;

void handleKill(int num)
{
    if(num == SIGINT)
    {
        qDebug()<<"exiting..";
        delete game;
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new window;
    game->show();
    game->mainWindow();
    signal(SIGINT,handleKill);
    return a.exec();
}
