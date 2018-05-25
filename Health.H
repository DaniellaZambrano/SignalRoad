#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QSignalTransition>
#include <QState>

//class MainWindow;

class Health : public QGraphicsTextItem{

public:

    Health(QGraphicsItem *parent = 0);

    int getHealth();
    void decrease();

private:

    int health;

    friend class UpdateScoreState;
    friend class UpdateScoreTransition;
};

class UpdateScoreState : public QState
{
public:
    UpdateScoreState(QState *parent);
};


class UpdateScoreTransition : public QSignalTransition
{
public:
   // UpdateScoreTransition(MainWindow *game,  Health *health, QAbstractState *target);

private:
    Health * health;
    //MainWindow * game;
};


#endif // HEALTH_H
