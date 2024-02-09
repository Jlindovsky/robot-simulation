/********************************************************************************
** Form generated from reading UI file 'app_proj.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_PROJ_H
#define UI_APP_PROJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_app_proj
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *app_proj)
    {
        if (app_proj->objectName().isEmpty())
            app_proj->setObjectName("app_proj");
        app_proj->resize(800, 600);
        centralwidget = new QWidget(app_proj);
        centralwidget->setObjectName("centralwidget");
        app_proj->setCentralWidget(centralwidget);
        menubar = new QMenuBar(app_proj);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        app_proj->setMenuBar(menubar);
        statusbar = new QStatusBar(app_proj);
        statusbar->setObjectName("statusbar");
        app_proj->setStatusBar(statusbar);

        retranslateUi(app_proj);

        QMetaObject::connectSlotsByName(app_proj);
    } // setupUi

    void retranslateUi(QMainWindow *app_proj)
    {
        app_proj->setWindowTitle(QCoreApplication::translate("app_proj", "app_proj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class app_proj: public Ui_app_proj {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_PROJ_H
