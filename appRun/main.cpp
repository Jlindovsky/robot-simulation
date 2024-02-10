
#include "window.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
window * game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new window;
    game->show();
    game->mainWindow();
    return a.exec();
}
