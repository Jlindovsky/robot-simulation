
#include "../header/window.h"
#include "../header/global.h"

/**
 * @brief Main function to initialize and run the application.
 *
 * This function initializes the Qt application, creates an instance of the window class,
 * shows the main window, and enters the Qt event loop by calling `a.exec()`. This allows
 * the application to handle events and respond to user interactions.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return int Exit code indicating the status of the application.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    window game;
    game.show();
    game.mainWindow();

    return a.exec();
}
