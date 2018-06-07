#include "Score.H"

#include "MainWindow.H"
class MainWindow;

extern MainWindow *game;

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //inicialize the score to 0
    score = 0;

    //draw the text
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::darkBlue);
    setFont(QFont("Comic Sans MS", 18));
}

Score::~Score()
{

}

void Score::increase(int inc)
{
    score += inc;
}

void Score::increase()
{
    if(!game->health->stoop)
    {
        score++;
        setPlainText(QString("Score: ") + QString::number(score));
    }
}
