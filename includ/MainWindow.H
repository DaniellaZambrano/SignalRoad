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


#include "Player.H"
#include "Health.H"

class MainWindow : public QMainWindow
{

Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void CenterandResize();

    QGraphicsScene *scene;
    QGraphicsView *view;

    Player *player;
    Health * health;
};


#endif // MAINWINDOW_H
