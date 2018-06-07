#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class BackGround : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    BackGround();
    ~BackGround();

public slots:
    void move_up();
};

#endif // BACKGROUND_H
