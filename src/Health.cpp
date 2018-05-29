#include "Health.H"

#include "MainWindow.H"

class MainWindow;

extern MainWindow *game;

#include <QDebug>

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    health = 3;
    stoop = false;

    //draw the text
    setPlainText(QString("Health: ") + QString::number(health));
    setFont(QFont("Comic Sans MS", 18));
    setDefaultTextColor(Qt::white);
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

void Health::hideeen()
{
    hide();
}

void Health::active()
{
    stoop = false;
}
