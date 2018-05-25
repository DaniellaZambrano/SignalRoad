#include "Health.H"

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    health = 3;

    //draw the text
    setPlainText(QString("Health: ") + QString::number(health));
    setFont(QFont("Comic Sans MS", 18));
    setDefaultTextColor(Qt::white);
}

int Health::getHealth()
{
    return health;
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}

