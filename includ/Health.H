#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QSignalTransition>
#include <QState>

class Health : public QGraphicsTextItem{

    Q_OBJECT

public:

    Health(QGraphicsItem *parent = 0);
    ~Health();

    int health;

    void decrease();
    void increase();

    bool stoop;


};

#endif // HEALTH_H
