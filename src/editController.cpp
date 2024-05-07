#include "../header/editController.h"

void editController::buildRCREdit(QGraphicsItem *parent, QGraphicsScene *scene)
{
    RCSlot.name = new QGraphicsTextItem(QString("RC Robot"));
    RCSlot.name->setParent(dynamic_cast<QObject *>(parent));
    RCSlot.name->setPos(35, 320);
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

    RCSlot.buildRCRobot = new gameButton(QString("build RCRobot"), RCSlot.name->x(), RCSlot.name->y() + 120, 100, 30, parent);

    scene->addItem(RCSlot.name);
    scene->addItem(RCSlot.sensorText);
    scene->addWidget(RCSlot.sensorInput);
    // magic bracho
    scene->addItem(RCSlot.buildRCRobot);
}
void editController::buildAREdit(QGraphicsItem *parent, QGraphicsScene *scene)
{
    ASlot.name = new QGraphicsTextItem(QString("Automatic Robot"));
    ASlot.name->setParent(dynamic_cast<QObject *>(parent));
    ASlot.name->setPos(35, 0);
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
    // magic bracho
    scene->addItem(ASlot.buildARobot);
}
void editController::buildBAREdit(QGraphicsItem *parent, QGraphicsScene *scene)
{
    BARSlot.name = new QGraphicsTextItem(QString("Edit Barriers"));
    BARSlot.name->setParent(dynamic_cast<QObject *>(parent));
    BARSlot.name->setPos(35, 480);
    BARSlot.name->setDefaultTextColor(Qt::black);
    BARSlot.buildBarrier = new gameButton(QString("Open"), BARSlot.name->x(), BARSlot.name->y() + 40, 100, 30, parent);

    scene->addItem(BARSlot.name);
    // magic bracho
    scene->addItem(BARSlot.buildBarrier);
}

void editController::buildControlsEdit(QGraphicsItem *parent, QGraphicsScene *scene)
{
    bottomSlot.up = new gameButton(QString("up"), RPANEL_W - 130, 10, 50, 50, parent);
    bottomSlot.left = new gameButton(QString("left"), RPANEL_W - 190, 10, 50, 50, parent);
    bottomSlot.right = new gameButton(QString("right"), RPANEL_W - 70, 10, 50, 50, parent);

    bottomSlot.dlt = new gameButton("Delete", RPANEL_W - 190, 70, 170, 40, parent);
    QBrush brush(Qt::gray);
    bottomSlot.dlt->setBrush(brush);

    scene->addItem(bottomSlot.dlt);
    scene->addItem(bottomSlot.up);
    scene->addItem(bottomSlot.left);
    scene->addItem(bottomSlot.right);
}

void editController::gridRefresh(QGraphicsItem *parent, QGraphicsScene *scene)
{
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            gameButton *tmp = new gameButton(QString("add"), 3 + i * 50, 3 + j * 50, 44, 44, parent);
            scene->addItem(tmp);
            barGrid.push_back(tmp);
            placeBar(tmp, parent, scene);
        }
    }
}

void editController::addBar(QGraphicsItem *parent, QGraphicsScene *scene)
{
    QBrush brush(Qt::magenta);
    gameButton *clickedButton = qobject_cast<gameButton *>(sender());
    if (clickedButton)
    {

        clickedButton->setBrush(brush);
        QPointF pos = clickedButton->pos();
        barrierC *tmp = new barrierC(pos.x() - 3, pos.y() - 3, 50, 50, parent);
        tmp->setBrush(brush);
        scene->addItem(tmp);
        gridRefresh(parent, scene);
        BARSlot.bars.push_back(tmp);
    }
}

void editController::dltBar(barrierC *bar, QGraphicsItem *parent, QGraphicsScene *scene)
{
    auto it = remove_if(BARSlot.bars.begin(), BARSlot.bars.end(), [&](barrierC *b)
                        { return b == bar; });

    if (it != BARSlot.bars.end())
    {
        delete bar;
        BARSlot.bars.erase(it);
        gridRefresh(parent, scene);
    }
}

void editController::placeBar(gameButton *button, QGraphicsItem *parent, QGraphicsScene *scene)
{
    QList<QGraphicsItem *> colliding_items = button->collidingItems();
    bool hit = false;
    QBrush brush(Qt::magenta);
    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        barrierC *barrierItem = dynamic_cast<barrierC *>(colliding_items[i]);

        // Check if the dynamic_cast was successful and the object is a barrierC 
        if (barrierItem != nullptr)
        {
            button->changeText("dlt");
            brush.setColor(Qt::magenta);
            button->setBrush(brush);

            connect(button, &gameButton::clicked, this, [=]()
                    { dltBar(barrierItem, parent, scene); });
            return;
        }

        Robot *robotItem = dynamic_cast<Robot *>(colliding_items[i]);

        // Check if the dynamic_cast was successful and the object is a one of Robot's derived classes
        if (robotItem != nullptr)
        {
            button->changeText("NO!");

            QBrush brush(Qt::magenta);
            brush.setColor(Qt::red);
            button->setBrush(brush);
            return;
        }
    }

    connect(button, &gameButton::clicked, this, [=]()
            { addBar(parent, scene); });
}

void editController::deleteBarGrid()
{
    for (auto i : barGrid)
    {
        delete i;
    }
    barGrid.clear();
}

void editController::refresh(QGraphicsScene *scene)
{
    for (auto i : (bottomSlot.rcRobs))
    {
        delete i;
    }
    for (auto i : (bottomSlot.aRobs))
    {
        delete i;
    }
    bottomSlot.rcRobs.clear();
    bottomSlot.aRobs.clear();
    int offset_x = 0;
    int offset_y = 0;
    int shift = 60;
    for (size_t i = 0; i < rcRobots.size(); i++)
    {
        string robName = "RC" + to_string(i + 1);
        gameButton *tmp = new gameButton(QString::fromStdString(robName), 10 + offset_x, 10 + offset_y, 50, 50, rPanel);
        bottomSlot.rcRobs.push_back(tmp);
        scene->addItem(tmp);

        if (i % 2)
        {
            offset_y -= shift;
            offset_x += shift;
        }
        else
        {
            offset_y += shift;
        }
    }
}

void editController::refreshPause(QGraphicsScene *scene)
{
    for (auto i : (bottomSlot.rcRobs))
    {
        delete i;
    }
    bottomSlot.rcRobs.clear();
    for (auto i : (bottomSlot.aRobs))
    {
        delete i;
    }
    bottomSlot.aRobs.clear();

    int offset_x = 0;
    int offset_y = 0;
    int shift = 60;
    int j = 0;
    for (size_t i = 0; i < rcRobots.size(); i++)
    {
        string robName = "RC" + to_string(i + 1);
        gameButton *tmp = new gameButton(QString::fromStdString(robName), 10 + offset_x, 10 + offset_y, 50, 50, rPanel);
        bottomSlot.rcRobs.push_back(tmp);
        scene->addItem(tmp);

        if (j % 2)
        {
            offset_y -= shift;
            offset_x += shift;
        }
        else
        {
            offset_y += shift;
        }
        j++;
    }

    for (size_t i = 0; i < aRobots.size(); i++)
    {
        string robName = "Aut" + to_string(i + 1);
        gameButton *tmp = new gameButton(QString::fromStdString(robName), 10 + offset_x, 10 + offset_y, 50, 50, rPanel);
        bottomSlot.aRobs.push_back(tmp);
        scene->addItem(tmp);

        if (j % 2)
        {
            offset_y -= shift;
            offset_x += shift;
        }
        else
        {
            offset_y += shift;
        }
        j++;
    }
}
void editController::deleteRob(Robot *activeR)
{
    ARobot *aRobotToDelete = dynamic_cast<ARobot *>(activeR);
    RCRobot *rcRobotToDelete = dynamic_cast<RCRobot *>(activeR);

    if (aRobotToDelete)
    {
        auto it = find(aRobots.begin(), aRobots.end(), aRobotToDelete);
        if (it != aRobots.end())
        {
            aRobots.erase(it);
            delete aRobotToDelete;
            return;
        }
    }
    else if (rcRobotToDelete)
    {
        auto it = find(rcRobots.begin(), rcRobots.end(), rcRobotToDelete);
        if (it != rcRobots.end())
        {
            rcRobots.erase(it);
            delete rcRobotToDelete;
            return;
        }
    }
}

void editController::buildPlayEdit(QGraphicsItem *parent, QGraphicsScene *scene)
{
    playSlot.pause = new gameButton(QString("pause"), 10, 10, 50, 50, parent);
    playSlot.play = new gameButton(QString("play"), 65, 10, 50, 50, parent);
    playSlot.save = new gameButton(QString("save"), 120, 10, 50, 50, parent);
    QBrush brush(Qt::gray);
    playSlot.save->setBrush(brush);

    scene->addItem(playSlot.pause);
    scene->addItem(playSlot.play);
    scene->addItem(playSlot.save);
}

editController::editController(QGraphicsScene *scene)
{
    iPanel = new QGraphicsRectItem(0, 0, IPANEL_W, IPANEL_H);
    iPanel->setPos(IPANEL_X, IPANEL_Y);
    QBrush brush;
    QPen pen;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    iPanel->setBrush(brush);
    pen.setColor(Qt::white);
    iPanel->setPen(pen);
    scene->addItem(iPanel);

    pPanel = new QGraphicsRectItem(0, 0, PPANEL_W, PPANEL_H);
    pPanel->setPos(PPANEL_X, PPANEL_Y);
    brush.setStyle(Qt::SolidPattern);
    pPanel->setPen(pen);
    pPanel->setBrush(brush);
    scene->addItem(pPanel);

    rPanel = new QGraphicsRectItem(0, 0, RPANEL_W, RPANEL_H);
    rPanel->setPos(RPANEL_X, RPANEL_Y);
    brush.setStyle(Qt::SolidPattern);
    rPanel->setBrush(brush);
    rPanel->setPen(pen);
    scene->addItem(rPanel);

    buildRCREdit(iPanel, scene);
    buildAREdit(iPanel, scene);
    buildBAREdit(iPanel, scene);
    buildControlsEdit(rPanel, scene);
    buildPlayEdit(pPanel, scene);
}

void editController::buildARobot(QGraphicsRectItem *parent, QGraphicsScene *scene, int x, int y, int sensor, int directionOfSpin, int spin, QTimer *timer)
{
    if (aRobots.size() >= 10)
    {
        QDialog dialog;
        dialog.setModal(true);                                                 // Set modal to ensure it blocks interaction with the scene
        dialog.setWindowFlags(dialog.windowFlags() | Qt::FramelessWindowHint); // Hide window frame
        dialog.hide();                                                         // Hide the dialog

        // Create and show the message box
        QMessageBox::information(&dialog, "Can't add Robots", "You have reached the limit for number of robots");

        // Make sure the dialog is deleted after the message box is closed
        QObject::connect(&dialog, &QDialog::finished, &dialog, &QObject::deleteLater);

        // Re-parent the dialog to the scene's views to ensure it appears on top
        foreach (QWidget *widget, QApplication::topLevelWidgets())
        {
            if (widget->inherits("QGraphicsView"))
            {
                dialog.setParent(widget);
                break;
            }
        }

        // Center the dialog relative to the scene
        QPoint dialogPos = parent->scenePos().toPoint() - QPoint(dialog.width() / 2, dialog.height() / 2);
        dialog.move(dialogPos);
        dialog.exec(); // Show the message box
    }
    if (x > PLAY_W || x < PLAY_X || y > PLAY_H || y < PLAY_Y)
    {
        qDebug() << "Invalid position of Automatic Robot from file!\n";
        exit(EXIT_FAILURE);
    }
    QBrush brushRob(Qt::darkMagenta);
    ARobot *tmp = new ARobot(x, y, SIZE_R, parent, sensor, directionOfSpin, spin);
    tmp->setBrush(brushRob);
    aRobots.push_back(tmp);
    QObject::connect(timer, SIGNAL(timeout()), tmp, SLOT(move()));
    scene->addItem(tmp);
}

void editController::buildRCRobot(QGraphicsRectItem *parent, QGraphicsScene *scene, int x, int y, int sensorIn)
{
    if (rcRobots.size() >= 10)
    {
        QDialog dialog;
        dialog.setModal(true);                                                 // Set modal to ensure it blocks interaction with the scene
        dialog.setWindowFlags(dialog.windowFlags() | Qt::FramelessWindowHint); // Hide window frame
        dialog.hide();                                                         // Hide the dialog

        // Create and show the message box
        QMessageBox::information(&dialog, "Can't add Robots", "You have reached the limit for number of robots");

        // Make sure the dialog is deleted after the message box is closed
        QObject::connect(&dialog, &QDialog::finished, &dialog, &QObject::deleteLater);

        // Re-parent the dialog to the scene's views to ensure it appears on top
        foreach (QWidget *widget, QApplication::topLevelWidgets())
        {
            if (widget->inherits("QGraphicsView"))
            {
                dialog.setParent(widget);
                break;
            }
        }

        // Center the dialog relative to the scene
        QPoint dialogPos = parent->scenePos().toPoint() - QPoint(dialog.width() / 2, dialog.height() / 2);
        dialog.move(dialogPos);
        dialog.exec(); // Show the message box
    }
    if (x > PLAY_W || x < PLAY_X || y > PLAY_H || y < PLAY_Y)
    {
        qDebug() << "Invalid position of Remote Control Robot\n";
        exit(EXIT_FAILURE);
    }
    QBrush brushRob(Qt::white);
    RCRobot *tmp = new RCRobot(x, y, SIZE_R, parent, sensorIn);
    tmp->setBrush(brushRob);
    rcRobots.push_back(tmp);
    scene->addItem(tmp);
}

void editController::buildBar(QGraphicsRectItem *parent, QGraphicsScene *scene, int x, int y)
{
    if (x % 50 || y % 50 || x > PLAY_W || x < 0 || y > PLAY_H || y < 0)
    {
        qDebug() << "Invalid position of Barrier \n";
        exit(EXIT_FAILURE);
    }
    QBrush brush(Qt::magenta);
    barrierC *tmp = new barrierC(x, y, 50, 50, parent);
    tmp->setBrush(brush);
    BARSlot.bars.push_back(tmp);
    scene->addItem(tmp);
}
