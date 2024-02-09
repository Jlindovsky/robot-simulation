#include "app_proj.h"
#include "./ui_app_proj.h"

app_proj::app_proj(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::app_proj)
{
    ui->setupUi(this);
}

app_proj::~app_proj()
{
    delete ui;
}
