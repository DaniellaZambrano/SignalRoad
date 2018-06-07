#include "Enemy.H"

#include <typeinfo>

#include "Player.H"
#include "MainWindow.H"

class MainWindow;

extern MainWindow *game;

#include "Sensor.H"

Enemy::Enemy()
{
    //random position
    int randomNum = rand() % 900;

    setZValue(3);

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

    game->player->s1->show();
    game->player->s2->show();
    game->player->s3->show();

    //pass the time
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

Enemy::~Enemy()
{

}

void Enemy::move()
{
    if(!game->health->stoop)
    {
        // move enemy down
        setPos(x(),y()+5);

        //destroy enemy when it goes out of the screen
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
                if(game->health->health > 1)
                {
                    playList = new QMediaPlaylist();
                    playList->addMedia(QUrl("qrc:/music/You crashed.mp3"));

                    music = new QMediaPlayer();
                    music->setPlaylist(playList);
                    music->play();
                }

                //decrease health
                game->health->decrease();
                scene()->removeItem(this);

                delete this;
            }
            else if(typeid(*(collide[i])) == typeid (Sensor))
            {
                if(collide[i] == game->player->s1)
                {
                    playList = new QMediaPlaylist();
                    playList->addMedia(QUrl("qrc:/music/Left.mp3"));

                    music = new QMediaPlayer();
                    music->setPlaylist(playList);
                    music->play();

                    game->player->s1->hide();
                }

                if(collide[i] == game->player->s2)
                {
                    playList = new QMediaPlaylist();
                    playList->addMedia(QUrl("qrc:/music/Front.mp3"));

                    music = new QMediaPlayer();
                    music->setPlaylist(playList);
                    music->play();

                    game->player->s2->hide();
                }
                if(collide[i] == game->player->s3)
                {
                    playList = new QMediaPlaylist();
                    playList->addMedia(QUrl("qrc:/music/Right.mp3"));

                    music = new QMediaPlayer();
                    music->setPlaylist(playList);
                    music->play();

                    game->player->s3->hide();
                }
            }
        }
    }
}
