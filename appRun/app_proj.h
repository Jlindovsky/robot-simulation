#ifndef APP_PROJ_H
#define APP_PROJ_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class app_proj;
}
QT_END_NAMESPACE

class app_proj : public QMainWindow
{
    Q_OBJECT

public:
    app_proj(QWidget *parent = nullptr);
    ~app_proj();

private:
    Ui::app_proj *ui;
};
#endif // APP_PROJ_H
