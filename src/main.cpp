
#include "../header/window.h"
#include "../header/global.h"

window *game;

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new window;
    game->show();
    game->mainWindow();

    return a.exec();
}
