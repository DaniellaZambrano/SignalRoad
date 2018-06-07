#include "Upgrades.H"

#include "Player.H"
#include <typeinfo>

#include "MainWindow.H"
class MainWindow;

extern MainWindow *game;

Upgrades::Upgrades()
{
    //random position
    int randomNum = rand() % 900;

    setZValue(1);

    if(randomNum <= 225)
        setPos(260,0);
    else if (randomNum <= 450)
        setPos(390,0);
    else if (randomNum <= 675)
        setPos(520,0);
    else
        setPos(650,0);

    //Draw alternative bonuses
    int randBonus = randomNum % 4;

    typeUpg = randBonus;

    if(randBonus == 0)
        setPixmap(QPixmap(":/pics/health.png"));
    if(randBonus == 1)
        setPixmap(QPixmap(":/pics/score.png"));

    setScale(0.5);
    //pass the time
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

Upgrades::~Upgrades()
{

}

void Upgrades::move()
{
    if(!game->health->stoop)
    {
        setPos(x(),y()+5);

        if(pos().y() > 600)
        {
            scene()->removeItem(this);
            delete this;
        }

        //Collide with the player
        QList <QGraphicsItem *> collide = collidingItems();

        for(int i = 0, n = collide.size(); i < n; i++)
        {
            if(typeid(*(collide[i])) == typeid (Player))
            {
                effect();
                scene()->removeItem(this);

                delete this;
            }
        }
    }
}

void Upgrades::effect()
{
    if(typeUpg == 0 && game->health->health < 3)
    {
        game->health->increase();
    }

    if(typeUpg == 1)
    {
        game->score->increase(100);
    }

}

