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

    if(game->showCar == 0)
    {
        setPixmap(QPixmap(":/pics/car1.png"));
        setPos(((game->scene->width()/2) - (pixmap().width())),
                       ((game->scene->height()/2) + (pixmap().height())));
    }
    if(game->showCar == 1)
    {
        setPixmap(QPixmap(":/pics/car2.png"));
        setPos(((game->scene->width()/2) - (pixmap().width())),
                       ((game->scene->height()/2) + (pixmap().height())));
    }
    if(game->showCar == -1)
    {
        setPixmap(QPixmap(":/pics/car4.png"));
        setPos(((game->scene->width()/2) - (pixmap().width())),
                       ((game->scene->height()/2) + (pixmap().height())));
    }

    s1 = new Sensor;
    s2 = new Sensor;
    s3 = new Sensor;

    s1->setPos((x()-110),(y()-200));
    s2->setPos((x()+10),(y()-200));
    s3->setPos((x()+150),(y()-200));

    s1->setPixmap(QPixmap(":/pics/G.png"));
    s2->setPixmap(QPixmap(":/pics/P.png"));
    s3->setPixmap(QPixmap(":/pics/Y.png"));

    s1->setScale(0.01);
    s2->setScale(0.01);
    s3->setScale(0.01);

    game->scene->addItem(s1);
    game->scene->addItem(s2);
    game->scene->addItem(s3);
}

Player::~Player()
{

}

void Player::keyPressEvent(QKeyEvent *event)
{
    // move the player left and right
    if (event->key() == Qt::Key_A)
    {
        if (pos().x() > 300)
        {
            setPos(x()-130,y());

            s1->setPos((x()-110),(y()-200));
            s2->setPos((x()+10),(y()-200));
            s3->setPos((x()+150),(y()-200));
        }

    }
    else if (event->key() == Qt::Key_D)
    {
        if (pos().x() + 100 < 600)
        {
            setPos(x()+130,y());

            s1->setPos((x()-110),(y()-200));
            s2->setPos((x()+10),(y()-200));
            s3->setPos((x()+150),(y()-200));
        }
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

void Player::emerge()
{
    if(!game->health->stoop)
    {
        //create an enemy
        Enemy *enemy = new Enemy();
        scene()->addItem(enemy);
    }
}

void Player::bonus()
{
    if(!game->health->stoop)
    {
       Upgrades *upg = new Upgrades;
       scene()->addItem(upg);
    }
}
