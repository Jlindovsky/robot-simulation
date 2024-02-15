#include "editcontroler.h"

void editControler::buildRCREdit(QGraphicsItem *parent, QGraphicsScene *scene)
{
    RCSlot.name = new QGraphicsTextItem(QString("Automatic Robot"));
    RCSlot.name->setParent(dynamic_cast<QObject *>(parent));
    RCSlot.name->setPos(50, 320);
    RCSlot.name->setDefaultTextColor(Qt::black);

    RCSlot.sensorText = new QGraphicsTextItem(QString("Set sensor lenght"));
    RCSlot.sensorText->setParent(dynamic_cast<QObject *>(parent));
    RCSlot.sensorText->setPos(RCSlot.name->x(), RCSlot.name->y() + 40);
    RCSlot.sensorText->setDefaultTextColor(Qt::black);

    RCSlot.sensorInput = new QLineEdit;
    RCSlot.sensorInput->setPlaceholderText("0-100");
    RCSlot.sensorValidator = new QIntValidator(0, 100);
    RCSlot.sensorInput->setValidator(RCSlot.sensorValidator);
    RCSlot.sensorInput->setGeometry(RCSlot.name->x(), RCSlot.name->y() + 80, 100, 30); // Adjust position and size as needed


    RCSlot.buildRCRobot = new gameButton(QString("build ARobot"), RCSlot.name->x(), RCSlot.name->y() + 120, 100, 30, parent);

    scene->addItem(RCSlot.name);
    scene->addItem(RCSlot.sensorText);
    scene->addWidget(RCSlot.sensorInput);
    //magic bracho
    scene->addItem(RCSlot.buildRCRobot);
}
void editControler::buildAREdit(QGraphicsItem *parent, QGraphicsScene *scene)
{
    ASlot.name = new QGraphicsTextItem(QString("Automatic Robot"));
    ASlot.name->setParent(dynamic_cast<QObject *>(parent));
    ASlot.name->setPos(50, 0);
    ASlot.name->setDefaultTextColor(Qt::black);

    ASlot.sensorText = new QGraphicsTextItem(QString("Set sensor lenght"));
    ASlot.sensorText->setParent(dynamic_cast<QObject *>(parent));
    ASlot.sensorText->setPos(ASlot.name->x(), ASlot.name->y() + 40);
    ASlot.sensorText->setDefaultTextColor(Qt::black);

    ASlot.sensorInput = new QLineEdit;
    ASlot.sensorInput->setPlaceholderText("0-100");
    ASlot.sensorValidator = new QIntValidator(0, 100);
    ASlot.sensorInput->setValidator(ASlot.sensorValidator);
    ASlot.sensorInput->setGeometry(ASlot.name->x(), ASlot.name->y() + 80, 100, 30); // Adjust position and size as needed

    ASlot.directionText = new QGraphicsTextItem(QString("Set direction"));
    ASlot.directionText->setParent(dynamic_cast<QObject *>(parent));
    ASlot.directionText->setPos(ASlot.name->x(), ASlot.name->y() + 120);
    ASlot.directionText->setDefaultTextColor(Qt::black);

    ASlot.directionInput = new QLineEdit;
    ASlot.directionInput->setPlaceholderText("-1 and 1");
    ASlot.directionValidator = new QIntValidator(-1, 1);
    ASlot.directionInput->setValidator(ASlot.directionValidator);
    ASlot.directionInput->setGeometry(ASlot.name->x(), ASlot.name->y() + 160, 100, 30);

    ASlot.spinText = new QGraphicsTextItem(QString("Set spin size"));
    ASlot.spinText->setParent(dynamic_cast<QObject *>(parent));
    ASlot.spinText->setPos(ASlot.name->x(), ASlot.name->y() + 200);
    ASlot.spinText->setDefaultTextColor(Qt::black);

    ASlot.spinInput = new QLineEdit;
    ASlot.spinInput->setPlaceholderText("10 - 180");
    ASlot.spinValidator = new QIntValidator(10, 180);
    ASlot.spinInput->setValidator(ASlot.spinValidator);
    ASlot.spinInput->setGeometry(ASlot.name->x(), ASlot.name->y() + 240, 100, 30);

    ASlot.buildARobot = new gameButton(QString("build ARobot"), ASlot.name->x(), ASlot.name->y() + 280, 100, 30, parent);

    scene->addItem(ASlot.name);
    scene->addItem(ASlot.sensorText);
    scene->addWidget(ASlot.sensorInput);
    scene->addItem(ASlot.directionText);
    scene->addWidget(ASlot.directionInput);
    scene->addItem(ASlot.spinText);
    scene->addWidget(ASlot.spinInput);
    //magic bracho
    scene->addItem(ASlot.buildARobot);

}
void editControler::buildBAREdit(QGraphicsItem *parent, QGraphicsScene *scene)
{
    BSlot.name = new QGraphicsTextItem(QString("Barrier"));
    BSlot.name->setParent(dynamic_cast<QObject *>(parent));
    BSlot.name->setPos(50, 480);
    BSlot.name->setDefaultTextColor(Qt::black);


    BSlot.buildBarrier = new gameButton(QString("build Barrier"), BSlot.name->x(), BSlot.name->y() + 40, 100, 30, parent);

    scene->addItem(BSlot.name);
    //magic bracho
    scene->addItem(BSlot.buildBarrier);
}
editControler::editControler(QGraphicsScene *scene)
{
    QGraphicsRectItem *iPanel = new QGraphicsRectItem(0, 0, IPANEL_W, IPANEL_H);
    iPanel->setPos(IPANEL_X, IPANEL_Y);
    QBrush brush;
    QPen pen;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    iPanel->setBrush(brush);
    pen.setColor(Qt::white);
    iPanel->setPen(pen);
    scene->addItem(iPanel);

    buildRCREdit(iPanel, scene);
    buildAREdit(iPanel, scene);
    buildBAREdit(iPanel, scene);
}
