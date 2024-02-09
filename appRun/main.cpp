
#include "window.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    window * game = new window;
    game->show();
    game->mainWindow();
    return a.exec();
}
