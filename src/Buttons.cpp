#include "Buttons.H"

#include <QGraphicsPixmapItem>

#include "MainWindow.H"
class MainWindow;

extern MainWindow *game;

Buttons::Buttons(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    showCar = 0;

    player = new QGraphicsPixmapItem;
    player->setPixmap(QPixmap(":/pics/car1.png"));
    player->setPos(300,300);
    game->scene->addItem(player);
}

Buttons::~Buttons()
{

}

void Buttons::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A)
    {
        moveLeft();
    }
    else if (event->key() == Qt::Key_D)
    {
       moveRight();
    }

}

void Buttons::moveLeft()
{

    if(showCar == 0)
    {
        player->setPixmap(QPixmap(":/pics/car4.png"));
        showCar = -1;

        return;
    }

    if(showCar == -1)
    {
        player->setPixmap(QPixmap(":/pics/car2.png"));
        showCar = 1;

        return;
    }

    if(showCar == 1)
    {
        player->setPixmap(QPixmap(":/pics/car1.png"));
        showCar = 0;

        return;
    }
}


void Buttons::moveRight()
{
    if(showCar == 0)
    {
        player->setPixmap(QPixmap(":/pics/car2.png"));
        showCar = 1;
        return;
    }

    if(showCar == 1)
    {
        player->setPixmap(QPixmap(":/pics/car4.png"));
        showCar = -1;

        return;
    }

    if(showCar == -1)
    {
        player->setPixmap(QPixmap(":/pics/car1.png"));
        showCar = 0;

        return;
    }
}
