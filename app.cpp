#include <QApplication>
#include <QMainWindow>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow mainWindow;
    QPushButton button("Click me", &mainWindow);

    // Connect signals and slots, and implement your logic here

    mainWindow.show();

    return a.exec();
}
