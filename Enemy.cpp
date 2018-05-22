#include "Enemy.H"

Enemy::Enemy()
{
    //random position
    int randomNum = rand() % 900;

    /*
     * Depends on the position the vibrations
     * will be activate
     */
    if(randomNum <= 225)
        setPos(260,0);
    else if (randomNum <= 450)
        setPos(390,0);
    else if (randomNum <= 675)
        setPos(520,0);
    else
        setPos(650,0);

    //Draw alternative cars
    int randCar = randomNum % 4;

    if(randCar == 0)
        setPixmap(QPixmap(":/pics/B.png"));
    else if(randCar == 1)
        setPixmap(QPixmap(":/pics/G.png"));
    else if(randCar == 2)
        setPixmap(QPixmap(":/pics/Y.png"));
    else
        setPixmap(QPixmap(":/pics/P.png"));

    setRotation(180);       //Reverse to the player

    //pass the time
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Enemy::move()
{
    // move enemy down
    setPos(x(),y()+5);

    //destroy enemy when it goes out of the screen
    if(pos().y() > 600)
    {
        scene()->removeItem(this);
        delete this;
    }
}
