#include "BackGround.H"

#include "MainWindow.H"

class MainWindow;
extern MainWindow *game;

BackGround::BackGround()
{
    setPixmap(QPixmap(":/pics/bg1.png"));

    setPos(0,-600);
    setZValue(-1);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move_up()));

    timer->start(10);
}

BackGround::~BackGround()
{

}

void BackGround::move_up()
{
    if(!game->health->stoop)
    {
        //move up
        setPos(x(),y() + 5);

        if(pos().y() == -10)
        {
            BackGround * nback = new BackGround();
            scene()->addItem(nback);
        }

        if(pos().y() > 600)
        {
            scene()->removeItem(this);
            delete this;
        }

    }
}
