#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

#include <QVariantAnimation>
#include <QStateMachine>

#include <QGraphicsScene>
#include "Enemy.H"

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent *event);

    enum Movement {
       None = 0,
       Left,
       Right
    };

    int getSpeed()const;
    void setSpeed(int speed);

    enum Movement getDirection()const;
    void setDirection(Movement direction);

    void updateMovement();

private:
    int speed;
   // int ;   enemies
    Movement direction;

    //animation
    QVariantAnimation *movementAnimation;
    QAbstractAnimation *destroyAnimation;
    QStateMachine *machine;

public slots:
    void emerge();

};

#endif // PLAYER_H
