#include "app_proj.h"
#include "window.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    window * game = new window;
    game->show();

    return a.exec();
}
