#include "../header/window.h"

window::window()
{
    // set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024, 768);

    // set up the scene
    welcomeScene = new QGraphicsScene();
    welcomeScene->setSceneRect(0, 0, 1024, 768);
    setScene(welcomeScene);
    gridOpen = false;

    editBuilder = nullptr;
    activeRCR = nullptr;
    activeR = nullptr;
    playground = nullptr;
    timer = nullptr;
    spawn = nullptr;
}

window::~window()
{
    delete welcomeScene;
    delete editScene;
    delete editBuilder;
    delete activeRCR;
    delete activeR;
    delete playground;
    delete timer;
    delete spawn;
}

void window::mainWindow()
{
    gameButton *newGameButton = new gameButton(QString("new"), 400, 275, 200, 50);
    connect(newGameButton, SIGNAL(clicked()), this, SLOT(editWindowSignal()));
    welcomeScene->addItem(newGameButton);

    gameButton *loadGameButton = new gameButton(QString("new but blue"), 400, 475, 200, 50);
    QBrush brush(Qt::blue);
    loadGameButton->setBrush(brush);
    connect(loadGameButton, SIGNAL(clicked()), this, SLOT(loadFromFile()));
    welcomeScene->addItem(loadGameButton);
}
void window::setActiveRCR(RCRobot *rob)
{
    QPen pen;
    if (activeRCR != nullptr)
    {
        pen.setColor(Qt::black);
        pen.setWidth(0);
        activeRCR->setPen(pen);
    }
    pen.setColor(Qt::green);
    pen.setWidth(4);
    activeRCR = rob;
    activeRCR->setPen(pen);
}

void window::setActiveR(Robot *rob)
{
    qDebug() << "setting active";
    QPen pen;

    if (activeR != nullptr)
    {
        pen.setColor(Qt::black);
        pen.setWidth(0);
        activeR->setPen(pen);
    }
    pen.setColor(Qt::green);
    pen.setWidth(4);
    activeR = rob;
    activeR->setPen(pen);
}
void window::moveUpActive()
{
    if (activeRCR)
        activeRCR->moveUp();
}
void window::rotateLeftActive()
{
    if (activeRCR)
        activeRCR->rotateLeft();
}
void window::rotateRightActive()
{
    if (activeRCR)
        activeRCR->rotateRight();
}

void window::deleteBot()
{
    editBuilder->deleteRob(activeR);
    editBuilder->refreshPause(editScene);
    activeR = nullptr;
    for (size_t i = 0; i < editBuilder->bottomSlot.rcRobs.size(); i++)
    {
        connect(editBuilder->bottomSlot.rcRobs[i], &gameButton::clicked, this, [=]()
                { setActiveR(editBuilder->rcRobots[i]); });
    }
    for (size_t i = 0; i < editBuilder->bottomSlot.aRobs.size(); i++)
    {
        connect(editBuilder->bottomSlot.aRobs[i], &gameButton::clicked, this, [=]()
                { setActiveR(editBuilder->aRobots[i]); });
    }
}

void window::checkARInput()
{
    editSlotARobot *slot = &(editBuilder->ASlot);
    auto sensorText = slot->sensorInput->text();
    auto directionText = slot->directionInput->text();
    auto spinText = slot->spinInput->text();

    int pos = 0;
    if (QValidator::Acceptable != slot->sensorValidator->validate(sensorText, pos))
    {
        // popup wrong input
        QMessageBox::information(
            this,
            tr("Wrong Input"),
            tr("ERROR, Wrong input. Sensor length is from 0 to 50"));
        return;
    }
    if (QValidator::Acceptable != slot->directionValidator->validate(directionText, pos))
    {
        // popup wrong input
        QMessageBox::information(
            this,
            tr("Wrong Input"),
            tr("ERROR, Wrong input. Direction is -1 or 1"));
        return;
    }
    if (QValidator::Acceptable != slot->spinValidator->validate(spinText, pos))
    {
        // popup wrong input
        QMessageBox::information(
            this,
            tr("Wrong Input"),
            tr("ERROR, Wrong input. Spin is from 10 to 180"));
        return;
    }
    editBuilder->buildARobot(playground, editScene, SPAWN_X + 25, SPAWN_Y + 25, (sensorText).toInt(), (directionText).toInt(), (spinText).toInt(), timer);
    // if pause refresh buttons for deletion
    if (!timer->isActive())
    {
        editBuilder->refreshPause(editScene);
        for (size_t i = 0; i < editBuilder->bottomSlot.rcRobs.size(); i++)
        {
            connect(editBuilder->bottomSlot.rcRobs[i], &gameButton::clicked, this, [=]()
                    { setActiveR(editBuilder->rcRobots[i]); });
        }
        for (size_t i = 0; i < editBuilder->bottomSlot.aRobs.size(); i++)
        {
            connect(editBuilder->bottomSlot.aRobs[i], &gameButton::clicked, this, [=]()
                    { setActiveR(editBuilder->aRobots[i]); });
        }
    }
}
void window::checkRCRInput()
{
    auto slot = editBuilder->RCSlot;
    auto sensorText = slot.sensorInput->text();

    int pos = 0;
    if (QValidator::Acceptable != slot.sensorValidator->validate(sensorText, pos))
    {
        // popup wrong input
        QMessageBox::information(
            this,
            tr("Wrong Input"),
            tr("ERROR, Wrong input. Sensor length is from 0 to 50"));
        return;
    }
    editBuilder->buildRCRobot(playground, editScene, SPAWN_X + 25, SPAWN_Y + 25, (sensorText).toInt());
    if (timer->isActive())
    {
        editBuilder->refresh(editScene);
        for (size_t i = 0; i < editBuilder->rcRobots.size(); i++)
        {
            connect(editBuilder->bottomSlot.rcRobs[i], &gameButton::clicked, this, [=]()
                    { setActiveRCR(editBuilder->rcRobots[i]); });
        }
    }
    else
    {
        editBuilder->refreshPause(editScene);
        for (size_t i = 0; i < editBuilder->bottomSlot.rcRobs.size(); i++)
        {
            connect(editBuilder->bottomSlot.rcRobs[i], &gameButton::clicked, this, [=]()
                    { setActiveR(editBuilder->rcRobots[i]); });
        }
        for (size_t i = 0; i < editBuilder->bottomSlot.aRobs.size(); i++)
        {
            connect(editBuilder->bottomSlot.aRobs[i], &gameButton::clicked, this, [=]()
                    { setActiveR(editBuilder->aRobots[i]); });
        }
    }
}

void window::connectButtons()
{
    QBrush brush(Qt::darkCyan);
    editBuilder->bottomSlot.up->setBrush(brush);
    editBuilder->bottomSlot.right->setBrush(brush);
    editBuilder->bottomSlot.left->setBrush(brush);
    connect(editBuilder->bottomSlot.up, SIGNAL(clicked()), this, SLOT(moveUpActive()));
    connect(editBuilder->bottomSlot.right, SIGNAL(clicked()), this, SLOT(rotateRightActive()));
    connect(editBuilder->bottomSlot.left, SIGNAL(clicked()), this, SLOT(rotateLeftActive()));
    brush.setColor(Qt::gray);
    editBuilder->playSlot.save->setBrush(brush);
    disconnect(editBuilder->playSlot.save, SIGNAL(clicked()), this, SLOT(saveGame()));
    editBuilder->bottomSlot.dlt->setBrush(brush);
    disconnect(editBuilder->bottomSlot.dlt, SIGNAL(clicked()), this, SLOT(deleteBot()));
}

void window::disconnectButtons()
{
    QBrush brush(Qt::gray);
    editBuilder->bottomSlot.up->setBrush(brush);
    editBuilder->bottomSlot.right->setBrush(brush);
    editBuilder->bottomSlot.left->setBrush(brush);
    disconnect(editBuilder->bottomSlot.up, SIGNAL(clicked()), this, SLOT(moveUpActive()));
    disconnect(editBuilder->bottomSlot.right, SIGNAL(clicked()), this, SLOT(rotateRightActive()));
    disconnect(editBuilder->bottomSlot.left, SIGNAL(clicked()), this, SLOT(rotateLeftActive()));
    brush.setColor(Qt::darkCyan);
    editBuilder->playSlot.save->setBrush(brush);
    editBuilder->bottomSlot.dlt->setBrush(brush);
    connect(editBuilder->playSlot.save, SIGNAL(clicked()), this, SLOT(saveGame()));
    connect(editBuilder->bottomSlot.dlt, SIGNAL(clicked()), this, SLOT(deleteBot()));
}

void window::stopTimer()
{
    QPen pen;
    timer->stop();
    disconnectButtons();
    if (activeRCR != nullptr)
    {
        pen.setWidth(0);
        activeRCR->setPen(pen);
        activeRCR = nullptr;
    }
    editBuilder->refreshPause(editScene);
    for (size_t i = 0; i < editBuilder->bottomSlot.rcRobs.size(); i++)
    {
        connect(editBuilder->bottomSlot.rcRobs[i], &gameButton::clicked, this, [=]()
                { setActiveR(editBuilder->rcRobots[i]); });
    }
    for (size_t i = 0; i < editBuilder->bottomSlot.aRobs.size(); i++)
    {
        connect(editBuilder->bottomSlot.aRobs[i], &gameButton::clicked, this, [=]()
                { setActiveR(editBuilder->aRobots[i]); });
    }
}

void window::startTimer()
{

    if (!gridOpen)
    {
        if (activeR != nullptr)
        {
            QPen pen;
            pen.setColor(Qt::black);
            pen.setWidth(0);
            activeR->setPen(pen);
        }
        timer->start(30);
        connectButtons();

        editBuilder->refresh(editScene);
        for (size_t i = 0; i < editBuilder->rcRobots.size(); i++)
        {
            connect(editBuilder->bottomSlot.rcRobs[i], &gameButton::clicked, this, [=]()
                    { setActiveRCR(editBuilder->rcRobots[i]); });
        }
    }
}

void window::clickGrid()
{
    if (gridOpen)
    {
        gridOpen = false;
        editBuilder->BARSlot.buildBarrier->changeText("Open");
        editBuilder->deleteBarGrid();
        // bar grid is closed now we can delete robots
        QBrush brush(Qt::darkCyan);
        editBuilder->bottomSlot.dlt->setBrush(brush);
        editBuilder->ASlot.buildARobot->setBrush(brush);
        editBuilder->RCSlot.buildRCRobot->setBrush(brush);
        editBuilder->playSlot.pause->setBrush(brush);
        editBuilder->playSlot.play->setBrush(brush);
        connect(editBuilder->bottomSlot.dlt, SIGNAL(clicked()), this, SLOT(deleteBot()));
        connect(editBuilder->ASlot.buildARobot, SIGNAL(clicked()), this, SLOT(checkARInput()));
        connect(editBuilder->RCSlot.buildRCRobot, SIGNAL(clicked()), this, SLOT(checkRCRInput()));
        connect(editBuilder->playSlot.pause, SIGNAL(clicked()), this, SLOT(stopTimer()));
        connect(editBuilder->playSlot.play, SIGNAL(clicked()), this, SLOT(startTimer()));
    }
    else
    {
        stopTimer();
        gridOpen = true;
        editBuilder->BARSlot.buildBarrier->changeText("Close");
        // disconnect deletion of robots
        QBrush brush(Qt::gray);
        editBuilder->bottomSlot.dlt->setBrush(brush);
        editBuilder->ASlot.buildARobot->setBrush(brush);
        editBuilder->RCSlot.buildRCRobot->setBrush(brush);
        editBuilder->playSlot.pause->setBrush(brush);
        editBuilder->playSlot.play->setBrush(brush);
        disconnect(editBuilder->bottomSlot.dlt, SIGNAL(clicked()), this, SLOT(deleteBot()));
        disconnect(editBuilder->ASlot.buildARobot, SIGNAL(clicked()), this, SLOT(checkARInput()));
        disconnect(editBuilder->RCSlot.buildRCRobot, SIGNAL(clicked()), this, SLOT(checkRCRInput()));
        disconnect(editBuilder->playSlot.pause, SIGNAL(clicked()), this, SLOT(stopTimer()));
        disconnect(editBuilder->playSlot.play, SIGNAL(clicked()), this, SLOT(startTimer()));
        editBuilder->gridRefresh(playground, editScene);
    }
}

void window::saveGame()
{
    if (timer->isActive())
    {
        return;
    }

    QDir currentDir = QDir::current();
    QString examplesDirPath = currentDir.absoluteFilePath("examples");

    if (!currentDir.cd("examples"))
    {
        qDebug() << "Failed to access examples directory.";
        return;
    }

    QStringList filters;
    filters << "*.json";
    currentDir.setNameFilters(filters);
    currentDir.setFilter(QDir::Files | QDir::NoSymLinks);

    QFileInfoList fileList = currentDir.entryInfoList();
    bool jsonExists = !fileList.isEmpty();

    QString fileName;

    if (jsonExists)
    {
        QString promptMessage = "JSON file(s) found in the examples directory:\n";
        QStringList fileNames;
        for (const QFileInfo &fileInfo : fileList)
        {
            promptMessage += fileInfo.fileName() + "\n";
            fileNames << fileInfo.fileName();
        }
        int choice = QMessageBox::question(
            this,
            tr("JSON File Exists"),
            promptMessage + "Do you want to rewrite an existing JSON file?",
            QMessageBox::Yes | QMessageBox::No);

        if (choice == QMessageBox::Yes)
        {
            bool ok;
            QString selectedFileName = QInputDialog::getItem(
                this,
                tr("Select JSON File to Rewrite"),
                "Select the JSON file you want to rewrite:",
                fileNames,
                0,
                false,
                &ok);

            if (ok)
            {
                fileName = selectedFileName;
            }
            else
            {
                return; // Cancel the save operation
            }
        }
    }

    if (fileName.isEmpty())
    {
        fileName = QInputDialog::getText(
            this,
            tr("Save JSON File"),
            tr("Enter the name of the JSON file to save:"),
            QLineEdit::Normal,
            "game.json");
    }

    if (fileName.isEmpty())
        return; // Cancel the save operation

    QFile file(currentDir.absoluteFilePath(fileName));
    if (file.open(QIODevice::WriteOnly))
    {
        QJsonArray jsonArray;

        // Iterate over each barrierC object in BARSlot.bars vector
        for (const barrierC *bar : editBuilder->BARSlot.bars)
        {
            QJsonObject barObject;
            barObject["x"] = bar->x();
            barObject["y"] = bar->y();
            barObject["type"] = "Barrier";
            jsonArray.append(barObject);
        }

        for (RCRobot *rob : editBuilder->rcRobots)
        {
            jsonArray.append(rob->save());
        }

        for (ARobot *rob : editBuilder->aRobots)
        {
            jsonArray.append(rob->save());
        }

        QJsonDocument jsonDoc(jsonArray);
        file.write(jsonDoc.toJson());
        file.close();
        qDebug() << "Game data saved to" << file.fileName();
    }
    else
    {
        qDebug() << "Failed to open" << file.fileName() << "for writing:" << file.errorString();
    }

    qDebug() << "Current working directory:" << QDir::currentPath();
}

void window::loadFromFile()
{
    editWindowSignal();

    QDir currentDir = QDir::current();
    QString examplesDirPath = currentDir.absoluteFilePath("examples");

    if (!currentDir.cd("examples"))
    {
        qDebug() << "Failed to access examples directory.";
        return;
    }

    QStringList filters;
    filters << "*.json";
    currentDir.setNameFilters(filters);
    currentDir.setFilter(QDir::Files | QDir::NoSymLinks);

    QFileInfoList fileList = currentDir.entryInfoList();
    bool jsonExists = !fileList.isEmpty();

    QString fileName;

    if (jsonExists)
    {
        QString promptMessage = "JSON file(s) found in the examples directory:\n";
        QStringList fileNames;
        for (const QFileInfo &fileInfo : fileList)
        {
            promptMessage += fileInfo.fileName() + "\n";
            fileNames << fileInfo.fileName();
        }
        bool ok;
        QString selectedFileName = QInputDialog::getItem(
            this,
            tr("Select JSON File"),
            promptMessage + "Select the JSON file you want to load:",
            fileNames,
            0,
            false,
            &ok);

        if (ok)
        {
            fileName = selectedFileName;
        }
        else
        {
            return; // Cancel the load operation
        }
    }

    if (fileName.isEmpty())
    {
        qDebug() << "No JSON file selected for loading.";
        return; // Cancel the load operation
    }

    QFile file(currentDir.absoluteFilePath(fileName));

    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Failed to open" << fileName << "for reading:" << file.errorString();
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError)
    {
        qDebug() << "Failed to parse JSON:" << parseError.errorString();
        return;
    }

    if (!jsonDoc.isArray())
    {
        qDebug() << "JSON document is not an array";
        return;
    }

    QJsonArray jsonArray = jsonDoc.array();

    for (const QJsonValue &value : jsonArray)
    {
        QJsonObject obj = value.toObject();
        int x = obj["x"].toInt();
        int y = obj["y"].toInt();
        int sensor = obj["sensor"].toInt();

        int spin = obj["spin"].toInt();
        int directionOfSpin = obj["direction"].toInt();
        QString type = obj["type"].toString();

        if (type == "Barrier")
        {
            editBuilder->buildBar(playground, editScene, x, y);
        }
        else if (type == "RC Robot")
        {
            editBuilder->buildRCRobot(playground, editScene, x, y, sensor);
        }
        else if (type == "Automatic Robot")
        {
            editBuilder->buildARobot(playground, editScene, x, y, sensor, directionOfSpin, spin, timer);
        }
        else
        {
            qDebug() << "wrong type of item";
            exit(EXIT_FAILURE);
        }
    }
    editBuilder->refresh(editScene);

    for (size_t i = 0; i < editBuilder->rcRobots.size(); i++)
    {
        connect(editBuilder->bottomSlot.rcRobs[i], &gameButton::clicked, this, [=]()
                { setActiveRCR(editBuilder->rcRobots[i]); });
    }
}

void window::editWindowSignal()
{
    // set up the scene
    editScene = new QGraphicsScene();
    editScene->clear();
    editScene->setSceneRect(0, 0, 1024, 768);
    setScene(editScene);

    playground = new QGraphicsRectItem(0, 0, PLAY_W, PLAY_H);
    playground->setPos(PLAY_X, PLAY_Y);
    QPen pen;
    pen.setColor(Qt::white);
    pen.setWidth(4);
    playground->setPen(pen);
    editScene->addItem(playground);
    // has to be added for coordinations but returns repeated addition

    editBuilder = new editController(editScene);
    connect(editBuilder->bottomSlot.up, SIGNAL(clicked()), this, SLOT(moveUpActive()));
    connect(editBuilder->bottomSlot.right, SIGNAL(clicked()), this, SLOT(rotateRightActive()));
    connect(editBuilder->bottomSlot.left, SIGNAL(clicked()), this, SLOT(rotateLeftActive()));
    connect(editBuilder->ASlot.buildARobot, SIGNAL(clicked()), this, SLOT(checkARInput()));
    connect(editBuilder->RCSlot.buildRCRobot, SIGNAL(clicked()), this, SLOT(checkRCRInput()));
    connect(editBuilder->BARSlot.buildBarrier, SIGNAL(clicked()), this, SLOT(clickGrid()));
    connect(editBuilder->playSlot.pause, SIGNAL(clicked()), this, SLOT(stopTimer()));
    connect(editBuilder->playSlot.play, SIGNAL(clicked()), this, SLOT(startTimer()));

    QBrush brush;

    barrierC *edgeTop = new barrierC(0, -1, PLAY_W, 1, playground);
    pen.setColor(Qt::black);
    edgeTop->setPen(pen);
    edges.push_back(edgeTop);
    // editScene->addItem(edgeTop);

    barrierC *edgeBottom = new barrierC(0, PLAY_H, PLAY_W, 1, playground);
    edgeBottom->setPen(pen);
    edges.push_back(edgeBottom);
    // editScene->addItem(edgeBottom);

    barrierC *edgeLeft = new barrierC(-1, 0, 1, PLAY_H, playground);
    edgeLeft->setPen(pen);
    edges.push_back(edgeLeft);
    // editScene->addItem(edgeLeft);

    barrierC *edgeRight = new barrierC(PLAY_W, 0, 1, PLAY_H, playground);
    edgeRight->setPen(pen);
    edges.push_back(edgeRight);
    // editScene->addItem(edgeRight);

    spawn = new ARobot(SPAWN_X, SPAWN_Y, 100, playground, 0, 0, 0);
    editScene->addItem(spawn);

    timer = new QTimer();

    timer->start(30);
}
