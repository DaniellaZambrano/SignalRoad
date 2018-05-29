#include "Player.H"
#include <QKeyEvent>
#include <QList>
#include <typeinfo>

#include "MainWindow.H"
class MainWindow;

extern MainWindow *game;

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    //Draw player
    setPixmap(QPixmap(":/pics/car1.png"));
    setScale(0.15);

}

void Player::keyPressEvent(QKeyEvent *event)
{
    // move the player left and right
    if (event->key() == Qt::Key_A)
    {
        if (pos().x() > 300)
            setPos(x()-130,y());
    }
    else if (event->key() == Qt::Key_D)
    {
        if (pos().x() + 100 < 600)
            setPos(x()+130,y());
    }

}

int Player::getSpeed() const
{
    return this->speed;
}

void Player::setSpeed(int speed)
{
    this->speed = speed;
}

Player::Movement Player::getDirection() const
{
    return this->direction;
}

void Player::setDirection(Player::Movement direction)
{
    this->direction = direction;
}

//Emerge an enemy
void Player::emerge()
{
    if(!game->health->stoop)
    {
        //create an enemy
        Enemy *enemy = new Enemy();
        scene()->addItem(enemy);
    }
}
