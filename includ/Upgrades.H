#ifndef UPGRADES_H
#define UPGRADES_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Upgrades : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Upgrades();
    ~Upgrades();

    void effect();

private:
    short typeUpg;

private slots:
    void move();

};

#endif // UPGRADES_H
