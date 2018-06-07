#include "Health.H"

#include "MainWindow.H"

class MainWindow;

extern MainWindow *game;

#include <QDebug>
#include <QTimer>

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    health = 3;
    stoop = false;

    //draw the text
    setPlainText(QString("Health: ") + QString::number(health));
    setFont(QFont("Comic Sans MS", 18));
    setDefaultTextColor(Qt::white);
}

Health::~Health()
{

}

void Health::decrease()
{
    this->health--;

    if(health == 0)
    {
        stoop = true;
        game->lostText();
    }
    setPlainText(QString("Health: ") + QString::number(health));
}

void Health::increase()
{
    health++;
}
