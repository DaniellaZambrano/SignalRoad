#ifndef BUTTONS_H
#define BUTTONS_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Buttons : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Buttons(QGraphicsItem *parent = 0);
    ~Buttons();

    int showCar;

    void keyPressEvent(QKeyEvent *event);
    void moveLeft();
    void moveRight();

    QGraphicsPixmapItem *player;

private:

public slots:

};

#endif // BUTTONS_H
