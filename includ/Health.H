#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QSignalTransition>
#include <QState>

#include <QGraphicsScene>
class Health : public QGraphicsTextItem{
public:

    Health(QGraphicsItem *parent = 0);
    void decrease();

    bool stoop;

//protected:

private:
    int health;


public slots:
    void hideeen();
    void active();
};

#endif // HEALTH_H
