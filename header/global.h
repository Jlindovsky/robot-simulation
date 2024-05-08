#ifndef GLOBAL_H
#define GLOBAL_H

/**
 * @file
 * @brief Definitions of various sizes and coordinates used in the program.
 */

/**
 * @defgroup SizesAndCoordinates Sizes and Coordinates
 * @brief Definitions of sizes and coordinates used in the program.
 * @{
 */

/** @brief Size of the robot component */
#define SIZE_R 50

/** @brief Size of the barrier component */
#define SIZE_B 75

/**
 * @brief Sizes and coordinates of the playground area.
 * @{
 */
#define PLAY_X 174 /**< X coordinate of the playground */
#define PLAY_Y 0   /**< Y coordinate of the playground */
#define PLAY_W 850 /**< Width of the playground */
#define PLAY_H 650 /**< Height of the playground */
/** @} */

/**
 * @brief Sizes and coordinates of the InsertPanel.
 * @{
 */
#define IPANEL_X 0   /**< X coordinate of the InsertPanel */
#define IPANEL_Y 0   /**< Y coordinate of the InsertPanel */
#define IPANEL_W 174 /**< Width of the InsertPanel */
#define IPANEL_H 650 /**< Height of the InsertPanel */
/** @} */

/**
 * @brief Sizes and coordinates of the PlayStop panel.
 * @{
 */
#define PPANEL_X 0   /**< X coordinate of the PlayStop panel */
#define PPANEL_Y 650 /**< Y coordinate of the PlayStop panel */
#define PPANEL_W 174 /**< Width of the PlayStop panel */
#define PPANEL_H 168 /**< Height of the PlayStop panel */
/** @} */

/**
 * @brief Sizes and coordinates of the RC panel.
 * @{
 */
#define RPANEL_X 174 /**< X coordinate of the RC panel */
#define RPANEL_Y 650 /**< Y coordinate of the RC panel */
#define RPANEL_W 850 /**< Width of the RC panel */
#define RPANEL_H 168 /**< Height of the RC panel */
/** @} */

/**
 * @brief Spawn coordinates.
 * @{
 */
#define SPAWN_X 375 /**< X coordinate of the spawn point */
#define SPAWN_Y 275 /**< Y coordinate of the spawn point */
/** @} */

/** @} */

#include <QtWidgets>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QDrag>
#include <QMimeData>
#include <string>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <algorithm>
#include <QObject>
#include <QLineEdit>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QPen>
#include <QTimer>
#include <QList>
#include <QLocale>
#include <QTranslator>
#include <QIntValidator>
#include <QLabel>
#include <QHBoxLayout>
#include <QMessageBox>

// std libs
#include <vector>
#include <qvalidator.h>
#include <typeinfo>
#include <memory>

using namespace std;

#endif