#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>

#include <QGraphicsPixmapItem>

#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include <QList>

class Enemy : public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
public:
    Enemy();

public slots:
    void move();

};

#endif // ENEMY_H
