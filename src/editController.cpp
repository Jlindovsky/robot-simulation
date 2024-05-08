#include "../header/editController.h"

/**
 * @brief Builds the interface for creating an Remote Control Robot(RCRobot).
 *
 * This function constructs the user interface elements for creation
 * of an Remote Control Robot(RCRobot).
 *
 * @param parent The parent item to which the interface elements will be added.
 * @param scene The QGraphicsScene where the interface elements will be displayed.
 */
void editController::buildRCREdit(QGraphicsItem *parent, QGraphicsScene *scene)
{
    RCSlot.name = new QGraphicsTextItem(QString("RC Robot"));
    RCSlot.name->setParent(dynamic_cast<QObject *>(parent));
    RCSlot.name->setPos(35, 320);
    RCSlot.name->setDefaultTextColor(Qt::black);

    RCSlot.sensorText = new QGraphicsTextItem(QString("Set sensor length"));
    RCSlot.sensorText->setParent(dynamic_cast<QObject *>(parent));
    RCSlot.sensorText->setPos(RCSlot.name->x(), RCSlot.name->y() + 40);
    RCSlot.sensorText->setDefaultTextColor(Qt::black);

    RCSlot.sensorInput = new QLineEdit;
    RCSlot.sensorInput->setPlaceholderText("  0 - 50");
    RCSlot.sensorValidator = new QIntValidator(0, 50);
    RCSlot.sensorInput->setValidator(RCSlot.sensorValidator);
    RCSlot.sensorInput->setGeometry(RCSlot.name->x(), RCSlot.name->y() + 80, 100, 30); // Adjust position and size as needed

    RCSlot.buildRCRobot = new gameButton(QString("Build RCRobot"), RCSlot.name->x(), RCSlot.name->y() + 120, 100, 30, parent);

    scene->addItem(RCSlot.name);
    scene->addItem(RCSlot.sensorText);
    scene->addWidget(RCSlot.sensorInput);
}

/**
 * @brief Builds the interface for creating an Automatic Robot(ARobot).
 *
 * This function constructs the user interface elements for creation
 * of an Automatic Robot(ARobot).
 *
 * @param parent The parent item to which the interface elements will be added.
 * @param scene The QGraphicsScene where the interface elements will be displayed.
 */
void editController::buildAREdit(QGraphicsItem *parent, QGraphicsScene *scene)
{
    ASlot.name = make_unique<QGraphicsTextItem>(QString("Automatic Robot"));
    ASlot.name->setParent(dynamic_cast<QObject *>(parent));
    ASlot.name->setPos(35, 0);
    ASlot.name->setDefaultTextColor(Qt::black);

    ASlot.sensorText = make_unique<QGraphicsTextItem>(QString("Set sensor length"));
    ASlot.sensorText->setParent(dynamic_cast<QObject *>(parent));
    ASlot.sensorText->setPos(ASlot.name->x(), ASlot.name->y() + 40);
    ASlot.sensorText->setDefaultTextColor(Qt::black);

    ASlot.sensorInput = make_unique<QLineEdit>();
    ASlot.sensorInput->setPlaceholderText("  0 - 50");
    ASlot.sensorValidator = make_unique<QIntValidator>(0, 50);
    // extract from unique pointer
    ASlot.sensorInput->setValidator(&*(ASlot.sensorValidator));
    ASlot.sensorInput->setGeometry(ASlot.name->x(), ASlot.name->y() + 80, 100, 30); // Adjust position and size as needed

    ASlot.directionText = make_unique<QGraphicsTextItem>(QString("  Set direction"));
    ASlot.directionText->setParent(dynamic_cast<QObject *>(parent));
    ASlot.directionText->setPos(ASlot.name->x(), ASlot.name->y() + 120);
    ASlot.directionText->setDefaultTextColor(Qt::black);

    ASlot.directionInput = make_unique<QLineEdit>();
    ASlot.directionInput->setPlaceholderText("  -1 or 1");
    ASlot.directionValidator = make_unique<QIntValidator>(-1, 1);
    // extract from unique pointer
    ASlot.directionInput->setValidator(&*(ASlot.directionValidator));
    ASlot.directionInput->setGeometry(ASlot.name->x(), ASlot.name->y() + 160, 100, 30);

    ASlot.spinText = make_unique<QGraphicsTextItem>(QString("  Set spin size"));
    ASlot.spinText->setParent(dynamic_cast<QObject *>(parent));
    ASlot.spinText->setPos(ASlot.name->x(), ASlot.name->y() + 200);
    ASlot.spinText->setDefaultTextColor(Qt::black);

    ASlot.spinInput = make_unique<QLineEdit>();
    ASlot.spinInput->setPlaceholderText("  10 - 180");
    ASlot.spinValidator = make_unique<QIntValidator>(10, 180);
    // extract from unique pointer
    ASlot.spinInput->setValidator(&*(ASlot.spinValidator));
    ASlot.spinInput->setGeometry(ASlot.name->x(), ASlot.name->y() + 240, 100, 30);

    ASlot.buildARobot = new gameButton(QString("Build ARobot"), ASlot.name->x(), ASlot.name->y() + 280, 100, 30, parent);

    // extracting from unique pointers and adding them to scene
    scene->addItem(&*(ASlot.name));
    scene->addItem(&*(ASlot.sensorText));
    scene->addWidget(&*(ASlot.sensorInput));
    scene->addItem(&*(ASlot.directionText));
    scene->addWidget(&*(ASlot.directionInput));
    scene->addItem(&*(ASlot.spinText));
    scene->addWidget(&*(ASlot.spinInput));
}

/**
 * @brief Builds the interface for creating an barrier(barrierC).
 *
 * This function constructs the user interface elements for creation
 * of an barrier(barrierC).
 *
 * @param parent The parent item to which the interface elements will be added.
 * @param scene The QGraphicsScene where the interface elements will be displayed.
 */
void editController::buildBAREdit(QGraphicsItem *parent, QGraphicsScene *scene)
{
    BARSlot.name = new QGraphicsTextItem(QString("Edit Barriers"));
    BARSlot.name->setParent(dynamic_cast<QObject *>(parent));
    BARSlot.name->setPos(35, 480);
    BARSlot.name->setDefaultTextColor(Qt::black);
    BARSlot.buildBarrier = new gameButton(QString("Open"), BARSlot.name->x(), BARSlot.name->y() + 40, 100, 30, parent);

    scene->addItem(BARSlot.name);
}

/**
 * @brief Builds the interface for controls.
 *
 * This function constructs the user interface elements for
 * RCRobot controls and delete button
 *
 * @param parent The parent item to which the interface elements will be added.
 * @param scene The QGraphicsScene where the interface elements will be displayed.(Redundant historic reasons)
 */
void editController::buildControlsEdit(QGraphicsItem *parent, QGraphicsScene *scene)
{
    bottomSlot.up = new gameButton(QString("up"), RPANEL_W - 130, 10, 50, 50, parent);
    bottomSlot.left = new gameButton(QString("left"), RPANEL_W - 190, 10, 50, 50, parent);
    bottomSlot.right = new gameButton(QString("right"), RPANEL_W - 70, 10, 50, 50, parent);

    bottomSlot.dlt = new gameButton("delete", RPANEL_W - 190, 70, 170, 40, parent);
    QBrush brush(Qt::gray);
    bottomSlot.dlt->setBrush(brush);
}

/**
 * @brief Builds the grid of buttons(gameButton) for creating an barrier(barrierC).
 *
 * buttons are connected externally
 *
 * @param parent The parent item to which the interface elements will be added.
 * @param scene The QGraphicsScene where the interface elements will be displayed.
 */
void editController::gridRefresh(QGraphicsItem *parent, QGraphicsScene *scene)
{
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            gameButton *tmp = new gameButton(QString("add"), 3 + i * 50, 3 + j * 50, 44, 44, parent);
            barGrid.push_back(tmp);
            placeBar(tmp, parent, scene);
        }
    }
}

/**
 * @brief
 *
 * @param parent
 * @param scene
 */
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

        gridRefresh(parent, scene);
        BARSlot.bars.push_back(tmp);
    }
}

/**
 * @brief Deletes the specified barrier item and refreshes the grid layout.
 *
 * @param bar Pointer to the barrier item to be deleted.
 * @param parent Pointer to the parent QGraphicsItem.
 * @param scene Pointer to the QGraphicsScene.
 */
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

/**
 * @brief Detects collisions between the given button and other items, adjusting its behavior accordingly.
 *
 * If the button collides with a barrierC item, it changes its text to "dlt" enabling deletion of the barrier item upon click.
 * If it collides with a Robot object or its derived classes it changes its text to "NO!" and leave button without action.
 * Otherwise, it connects the button to a slot for adding a barrier upon click.
 *
 * @param button Pointer to the gameButton object to be designed and/or connected.
 * @param parent Pointer to the parent QGraphicsItem.
 * @param scene Pointer to the QGraphicsScene.
 */

void editController::placeBar(gameButton *button, QGraphicsItem *parent, QGraphicsScene *scene)
{
    QList<QGraphicsItem *> colliding_items = button->collidingItems();
    QBrush brush(Qt::magenta);
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

/**
 * @brief deletes all grid buttons
 */
void editController::deleteBarGrid()
{
    for (auto i : barGrid)
    {
        delete i;
    }
    barGrid.clear();
}

/**
 * @brief Refreshes the graphics scene by clearing and updating robot buttons while game is running.
 *
 * @param scene Pointer to the QGraphicsScene.
 */
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

/**
 * @brief Refreshes the graphics scene by clearing and updating robot buttons while game is paused.
 *
 * @param scene Pointer to the QGraphicsScene.
 */
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
        string robName = "AR" + to_string(i + 1);
        gameButton *tmp = new gameButton(QString::fromStdString(robName), 10 + offset_x, 10 + offset_y, 50, 50, rPanel);
        bottomSlot.aRobs.push_back(tmp);

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
/**
 * @brief Deletes the specified robot from the appropriate container and deallocates memory.
 *
 * @param activeR Pointer to the robot to be deleted.
 */
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

/**
 * @brief Builds the buttons for controlling the play mode.
 *
 * @param parent Pointer to the parent QGraphicsItem.
 * @param scene Pointer to the QGraphicsScene where the buttons will be added.
 */
void editController::buildPlayEdit(QGraphicsItem *parent, QGraphicsScene *scene)
{
    playSlot.pause = new gameButton(QString("pause"), 10, 10, 50, 50, parent);
    playSlot.play = new gameButton(QString("play"), 65, 10, 50, 50, parent);
    playSlot.save = new gameButton(QString("save"), 120, 10, 50, 50, parent);
    QBrush brush(Qt::gray);
    playSlot.save->setBrush(brush);
}

/**
 * @brief Construct a new edit Controller::edit Controller object and fills all of its panels with corresponding buttons and texts
 *
 * @param scene
 */
editController::editController(QGraphicsScene *scene)
{
    iPanel = new QGraphicsRectItem(0, 0, IPANEL_W, IPANEL_H);
    iPanel->setPos(IPANEL_X, IPANEL_Y);
    QBrush brush(Qt::white);
    QPen pen(Qt::white);
    brush.setStyle(Qt::SolidPattern);
    iPanel->setBrush(brush);
    iPanel->setPen(pen);
    scene->addItem(iPanel);

    pPanel = new QGraphicsRectItem(0, 0, PPANEL_W, PPANEL_H);
    pPanel->setPos(PPANEL_X, PPANEL_Y);
    pPanel->setPen(pen);
    pPanel->setBrush(brush);
    scene->addItem(pPanel);

    rPanel = new QGraphicsRectItem(0, 0, RPANEL_W, RPANEL_H);
    rPanel->setPos(RPANEL_X, RPANEL_Y);
    rPanel->setBrush(brush);
    rPanel->setPen(pen);
    scene->addItem(rPanel);

    buildRCREdit(iPanel, scene);
    buildAREdit(iPanel, scene);
    buildBAREdit(iPanel, scene);
    buildControlsEdit(rPanel, scene);
    buildPlayEdit(pPanel, scene);
}
/**
 * @brief Verifies and builds a automatic robot(ARobot) at the specified position on the scene.
 *
 * @param parent Pointer to the parent QGraphicsRectItem.
 * @param scene Pointer to the QGraphicsScene where the robot will be added.
 * @param x The x-coordinate of the robot's position.
 * @param y The y-coordinate of the robot's position.
 * @param sensorIn The sensor length of the robot.
 */
void editController::buildARobot(QGraphicsRectItem *parent, QGraphicsScene *scene, int x, int y, int sensor, int directionOfSpin, int spin, QTimer *timer)
{
    if (aRobots.size() >= 10)
    {
        QMessageBox::information(nullptr, "Can't add Robots", "You have reached the limit for number of robots");
        return;
    }
    if (x > PLAY_W || x < 0 || y > PLAY_H || y < 0)
    {
        qDebug() << "Invalid position of Automatic Robot from file!\nPOS:" << x << " | " << y << "\n";
        return;
    }
    QBrush brushRob(Qt::darkMagenta);
    ARobot *tmp = new ARobot(x, y, SIZE_R, parent, sensor, directionOfSpin, spin);
    tmp->setBrush(brushRob);
    aRobots.push_back(tmp);

    connect(timer, &QTimer::timeout, tmp, [=]
            { tmp->move(); });
}

/**
 * @brief Verifies and builds a automatic robot(ARobot) at the specified position on the scene.
 *
 * @param parent Pointer to the parent QGraphicsRectItem.
 * @param scene Pointer to the QGraphicsScene where the robot will be added.
 * @param x The x-coordinate of the robot's position.
 * @param y The y-coordinate of the robot's position.
 * @param sensorIn The sensor length of the robot.
 * @param angle The spin of the robot.
 */
void editController::buildARobot(QGraphicsRectItem *parent, QGraphicsScene *scene, int x, int y, int sensor, int directionOfSpin, int spin, QTimer *timer, int angleIN)
{
    if (aRobots.size() >= 10)
    {
        QMessageBox::information(nullptr, "Can't add Robots", "You have reached the limit for number of robots");
        return;
    }
    if (x > PLAY_W || x < 0 || y > PLAY_H || y < 0 || angleIN < 0)
    {
        qDebug() << "Invalid position/angle of Automatic Robot from file!\nPOS:" << x << " | " << y << "\n";
        return;
    }
    QBrush brushRob(Qt::darkMagenta);
    ARobot *tmp = new ARobot(x, y, SIZE_R, parent, sensor, directionOfSpin, spin, angleIN);
    tmp->setBrush(brushRob);
    aRobots.push_back(tmp);

    connect(timer, &QTimer::timeout, tmp, [=]
            { tmp->move(); });
}

/**
 * @brief Verifies and builds a remote control robot(RCRobot) at the specified position on the scene.
 *
 * @param parent Pointer to the parent QGraphicsRectItem.
 * @param scene Pointer to the QGraphicsScene where the robot will be added.
 * @param x The x-coordinate of the robot's position.
 * @param y The y-coordinate of the robot's position.
 * @param sensorIn The sensor length of the robot.
 * @param angle The spin of the robot.
 */
void editController::buildRCRobot(QGraphicsRectItem *parent, QGraphicsScene *scene, int x, int y, int sensorIn, int angleIN)
{
    if (rcRobots.size() >= 10)
    {
        QMessageBox::information(nullptr, "Can't add Robots", "You have reached the limit for number of robots");
        return;
    }
    if (x > PLAY_W || x < 0 || y > PLAY_H || y < 0 || angleIN < 0)
    {
        qDebug() << "Invalid position/angle of Remote Control Robot\n";
        return;
    }
    QBrush brushRob(Qt::white);
    RCRobot *tmp = new RCRobot(x, y, SIZE_R, parent, sensorIn, angleIN % 360);
    tmp->setBrush(brushRob);
    rcRobots.push_back(tmp);
}
/**
 * @brief Verifies and builds a remote control robot(RCRobot) at the specified position on the scene.
 *
 * @param parent Pointer to the parent QGraphicsRectItem.
 * @param scene Pointer to the QGraphicsScene where the robot will be added.
 * @param x The x-coordinate of the robot's position.
 * @param y The y-coordinate of the robot's position.
 * @param sensorIn The sensor length of the robot.
 */
void editController::buildRCRobot(QGraphicsRectItem *parent, QGraphicsScene *scene, int x, int y, int sensorIn)
{
    if (rcRobots.size() >= 10)
    {
        QMessageBox::information(nullptr, "Can't add Robots", "You have reached the limit for number of robots");
        return;
    }
    if (x > PLAY_W || x < 0 || y > PLAY_H || y < 0)
    {
        qDebug() << "Invalid position of Remote Control Robot\n";
        return;
    }
    QBrush brushRob(Qt::white);
    RCRobot *tmp = new RCRobot(x, y, SIZE_R, parent, sensorIn);
    tmp->setBrush(brushRob);
    rcRobots.push_back(tmp);
}

/**
 * @brief Verifies and builds a barrier at the specified position on the scene .
 *
 * @param parent Pointer to the parent QGraphicsRectItem.
 * @param scene Pointer to the QGraphicsScene where the barrier will be added.
 * @param x The x-coordinate of the barrier's position.
 * @param y The y-coordinate of the barrier's position.
 */
void editController::buildBar(QGraphicsRectItem *parent, QGraphicsScene *scene, int x, int y)
{
    if (x % 50 || y % 50 || x > PLAY_W || x < 0 || y > PLAY_H || y < 0)
    {
        qDebug() << "Invalid position of Barrier \n";
        return;
    }
    QBrush brush(Qt::magenta);
    barrierC *tmp = new barrierC(x, y, 50, 50, parent);
    tmp->setBrush(brush);
    BARSlot.bars.push_back(tmp);
}
