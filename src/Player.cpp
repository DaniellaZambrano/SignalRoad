#include "Player.H"
#include <QKeyEvent>
#include <QList>
#include <typeinfo>


Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    //Draw player
    setPixmap(QPixmap(":/pics/car1.png"));
    setScale(0.15);

}

void Player::keyPressEvent(QKeyEvent *event)
{
    // move the player left and right
    if (event->key() == Qt::Key_Left)
    {
        if (pos().x() > 300)
            setPos(x()-130,y());
    }
    else if (event->key() == Qt::Key_Right)
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
    //create an enemy
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);


//    //Collide with the player
//    QList <QGraphicsItem *> collide = collidingItems();

//    for(int i = 0, n = collide.size(); i < n; i++)
//    {
//        if(typeid(*(collide[i])) == typeid (Enemy))
//        {
//            //decrease health
//            windowMain->health->decrease();

//            qDebug() << "collision";
//        }
//    }
}
