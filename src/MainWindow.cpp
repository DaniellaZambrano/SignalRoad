#include "MainWindow.H"


#include <QMenuBar>
#include <QBrush>

#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    //Create a Menu

    //Create tools
    file = menuBar()->addMenu(tr("&File")); //menu options

    newGame = file->addAction(tr("New Game"));    //into file
    newGame->setShortcut(tr("CTRL+N")); //new game shortcut
    quit = file->addAction(tr("Quit"));
    quit->setShortcut(tr("Q"));
    contin = file->addAction(tr("Continue"));
    contin->setShortcut(tr("W"));
    pause = file->addAction(tr("Pause"));
    pause->setShortcut(tr("S"));

    //QMenu *help = menuBar()->addMenu(tr("&Help"));

    //Draw the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); //default 800 x 600
    scene->setBackgroundBrush(QImage(":/pics/bg1.png"));

    view = new QGraphicsView(scene, this);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    //scene
    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //start
    text = new QGraphicsTextItem;
    text->setPlainText(QString("Press CTRL+N to start the game"));
    text->setFont(QFont("Tokyo, 100"));
    text->setPos(300, 300);
    text->setDefaultTextColor(Qt::cyan);
    scene->addItem(text);

    connect(newGame, SIGNAL(triggered(bool)), this, SLOT(launchGame()));
    connect(quit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));

    connect(pause, SIGNAL(triggered(bool)), this,SLOT(desactive()));

    setCentralWidget(view);
}

MainWindow::~MainWindow()
{

}

void MainWindow::startMenu()
{
    scene->clear();

    text = new QGraphicsTextItem;

    text->setPlainText(QString("Press CTRL+N to start the game"));
    text->setFont(QFont("Tokyo, 100"));
    text->setPos(300, 300);
    text->setDefaultTextColor(Qt::cyan);
    scene->addItem(text);
    
    connect(newGame, SIGNAL(triggered(bool)), this, SLOT(launchGame()));
}

void MainWindow::lostText()
{
    disconnect(contin, 0, 0, 0);
    player->clearFocus();


    lost = new QGraphicsTextItem;
    lost->setPlainText(QString("YOU LOST! (Press CTRL+N to start again)"));
    lost->setFont(QFont("Comic Sans MS", 18));

    lost->setDefaultTextColor(Qt::white);
    lost->setPos(150,300);

    scene->addItem(lost);

    connect(newGame, SIGNAL(triggered(bool)), this, SLOT(startMenu()));
}

void MainWindow::launchGame()
{
    disconnect(newGame,0,0,0);
    connect(contin, SIGNAL(triggered(bool)), this,SLOT(active()));
    scene->clear();

    //Draw health
    health = new Health();
    health->setPos(health->x()+10, scene->height()/6 + health->y());
    scene->addItem(health);

    //draw moving background
    back = new BackGround;
    scene->addItem(back);


    //Create player
    player = new Player;
    player->setPos((scene->width()) - (player->pixmap().width()),
                   (scene->height()/2) + (player->pixmap().height()/15));
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
    player->grabMouse();           

    //delay enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(emerge()));
    timer->start(2000);

}

void MainWindow::active()
{
    health->stoop = false;
    player->setFocus();
}

void MainWindow::desactive()
{
    health->stoop = true;
    player->clearFocus();
}

