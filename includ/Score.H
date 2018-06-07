#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QSignalTransition>
#include <QState>

class Score : public QGraphicsTextItem {
    Q_OBJECT
public:
    Score(QGraphicsItem *parent = 0);
    ~Score();

    void increase(int);


public slots:
    void increase();


private:

    int score;
};

#endif // SCORE_H
