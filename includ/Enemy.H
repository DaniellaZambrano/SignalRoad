#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>

#include <QGraphicsPixmapItem>

#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include <QList>

#include <QMediaPlayer>
#include <QMediaPlaylist>

class Enemy : public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
public:
    Enemy();
    ~Enemy();

    QMediaPlaylist *playList;
    QMediaPlayer *music;

public slots:
    void move();

};

#endif // ENEMY_H
