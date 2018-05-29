#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>
#include <QGraphicsView>

#include <QLayout>

#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
//#include <QMediaPlayer>
#include <QImage>
#include <QPushButton>
#include <QMenu>

#include "Player.H"
#include "Health.H"
#include "BackGround.H"

class MainWindow : public QMainWindow
{

Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void CenterandResize();
    void lostText();

    QGraphicsScene *scene;
    QGraphicsView *view;
    QPushButton *play;
    QGraphicsTextItem *text;
    QGraphicsTextItem *lost;
    Player *player;
    Health *health;
    BackGround *back;

    QMenu *file;
    QAction *newGame;
    QAction *quit;
    QAction *contin;
    QAction *pause;

public slots:
    void startMenu();
    void launchGame();
//    void show();
//    void hide();
    void active();
    void desactive();
};


#endif // MAINWINDOW_H
