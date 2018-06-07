#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>
#include <QGraphicsView>

#include <QLayout>

#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlaylist>
#include <QImage>
#include <QPushButton>
#include <QMenu>

#include "Player.H"
#include "Health.H"
#include "BackGround.H"
#include "Score.H"
#include "Buttons.H"

class MainWindow : public QMainWindow
{

Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int showCar = 0;
    void lostText();

    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsTextItem *text;
    QGraphicsTextItem *lost;
    Player *player;
    Health *health;
    BackGround *back;
    Score *score;
    Buttons *buttonLeft;
    QGraphicsPixmapItem *buttonRight;
    QGraphicsPixmapItem *newPlayer;

    QMenu *file;
    QAction *newGame;
    QAction *quit;
    QAction *contin;
    QAction *pause;
    QTimer *timeS;
    QMenu *help;
    QAction *qHelp;

    QMediaPlaylist *playList;
    QMediaPlayer *music;

public slots:
    void reStartMenu();
    void choicePlayer();
    void launchGame();
    void active();
    void desactive();
    void heelp();
};


#endif // MAINWINDOW_H
