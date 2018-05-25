#include "MainWindow.H"

#include <QMenu>
#include <QMenuBar>
#include <QBrush>

#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    //Create a Menu

    //Create tools
    QMenu *file = menuBar()->addMenu(tr("&File")); //menu options
    QAction *newGame = file->addAction(tr("New Game"));    //into file
    newGame->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N)); //new game shortcut
    QAction *quit = file->addAction(tr("Quit"));
    quit->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));
    connect(quit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));

    //QMenu *help = menuBar()->addMenu(tr("&Help"));

    //Draw the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); //default 800 x 600
    scene->setBackgroundBrush(QImage(":/pics/bg1.png"));

    //View
    view = new QGraphicsView(scene, this);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    //scene
    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Create player
    player = new Player;
    player->setPos((scene->width()) - (player->pixmap().width()),
                   (scene->height()/2) + (player->pixmap().height()/15));
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    //Draw health
    health = new Health();
    health->setPos(health->x()+10, scene->height()/6 + health->y());
    scene->addItem(health);

    //delay enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(emerge()));
    timer->start(2000);


    setCentralWidget(view);

}

MainWindow::~MainWindow()
{

}
