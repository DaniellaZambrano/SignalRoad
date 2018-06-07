#include "MainWindow.H"


#include <QMenuBar>
#include <QBrush>

#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    //Create a Menu

    setWindowTitle(tr("Signal Road by DNAProgrammers"));

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

    help = menuBar()->addMenu(tr("&Help"));
    qHelp = help->addAction(tr("Help"));
    qHelp->setShortcut(tr("H"));

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
    text->setFont(QFont("Purisa, 100"));
    text->setPos(300, 300);
    text->setDefaultTextColor(Qt::cyan);
    text->setZValue(5);
    scene->addItem(text);

    //sound
    playList = new QMediaPlaylist();
    playList->addMedia(QUrl("qrc:/music/Intro.mp3"));

    music = new QMediaPlayer();
    music->setPlaylist(playList);
    music->play();

    playList->addMedia(QUrl("qrc:/music/h to help.mp3"));
    music->play();

    playList->addMedia(QUrl("qrc:/music/Ctrl+N.mp3"));
    music->play();

    connect(newGame, SIGNAL(triggered(bool)), this, SLOT(choicePlayer()));
    connect(qHelp, SIGNAL(triggered(bool)), this, SLOT(heelp()));
    connect(quit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));

    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete text;
    delete lost;
    delete health;
    delete score;
    delete back;
    delete player;
    delete music;
}

void MainWindow::reStartMenu()
{
    music->stop();
    connect(qHelp, SIGNAL(triggered(bool)), this, SLOT(heelp()));
    scene->clear();

    QMediaPlaylist *helpsM = new QMediaPlaylist();
    helpsM->addMedia(QUrl("qrc:/music/h to help.mp3"));
    music = new QMediaPlayer();
    music->setPlaylist(helpsM);
    music->play();

    helpsM->addMedia(QUrl("qrc:/music/Ctrl+N.mp3"));
    music->play();

    text = new QGraphicsTextItem;

    text->setPlainText(QString("Press CTRL+N to start the game"));
    text->setFont(QFont("Purisa, 100"));
    text->setPos(300, 300);
    text->setDefaultTextColor(Qt::cyan);
    text->setZValue(5);
    scene->addItem(text);

    connect(newGame, SIGNAL(triggered(bool)), this, SLOT(choicePlayer()));
}

void MainWindow::choicePlayer()
{
    disconnect(qHelp, 0,0,0);
    disconnect(newGame,0,0,0);
    music->stop();
    scene->clear();

    QMediaPlaylist *space = new QMediaPlaylist();
    space->addMedia(QUrl("qrc:/music/Space.mp3"));
    music = new QMediaPlayer;
    music->setPlaylist(space);
    music->play();

    buttonLeft = new Buttons();
    buttonLeft->setPixmap(QPixmap((":/pics/left.png")));
    buttonLeft->setPos(100,300);
    buttonLeft->setFlag(QGraphicsItem::ItemIsFocusable);
    buttonLeft->setFocus();
    scene->addItem(buttonLeft);
    buttonLeft->grabMouse();

    buttonRight = new QGraphicsPixmapItem;
    buttonRight->setPixmap(QPixmap(":/pics/right.png"));
    buttonRight->setPos(600,300);
    scene->addItem(buttonRight);

    newGame->setShortcut(tr(" "));

    connect(newGame, SIGNAL(triggered(bool)), this, SLOT(launchGame()));
}

void MainWindow::lostText()
{
    music->stop();
    disconnect(contin, 0, 0, 0);
    disconnect(pause,0,0,0);
    disconnect(timeS,0,0,0);
    player->clearFocus();

    lost = new QGraphicsTextItem;
    lost->setPlainText(QString("YOU LOST! (Press CTRL+N to start again)"));
    lost->setFont(QFont("Comic Sans MS", 18));

    //sound
    QMediaPlaylist *loseS = new QMediaPlaylist();
    loseS->addMedia(QUrl("qrc:/music/Lost.mp3"));
    music = new QMediaPlayer();
    music->setPlaylist(loseS);
    music->play();

    loseS->addMedia(QUrl("qrc:/music/Ctrl+N.mp3"));
    music->play();

    lost->setDefaultTextColor(Qt::white);
    lost->setPos(150,300);
    lost->setZValue(6);

    scene->addItem(lost);

    newGame->setShortcut(tr("CTRL+N"));
    connect(newGame, SIGNAL(triggered(bool)), this, SLOT(reStartMenu()));
}

void MainWindow::launchGame()
{
    music->stop();
    disconnect(newGame,0,0,0);
    connect(contin, SIGNAL(triggered(bool)), this,SLOT(active()));
    connect(pause, SIGNAL(triggered(bool)), this,SLOT(desactive()));

    showCar = buttonLeft->showCar;
    scene->clear();

    //sound
    QMediaPlaylist *start = new QMediaPlaylist();
    start->addMedia(QUrl("qrc:/music/Started.mp3"));
    music = new QMediaPlayer;
    music->setPlaylist(start);
    music->play();

    //Draw health
    health = new Health();
    health->setPos(health->x()+10, scene->height()/6 + health->y());
    scene->addItem(health);

    //draw score
    score = new Score();
    score->setPos(score->x()+10, scene->height()/5 + score->y()+8);
    scene->addItem(score);

    timeS = new QTimer();
    connect(timeS, SIGNAL(timeout()), score, SLOT(increase()));
    timeS->start(500);

    //draw moving background
    back = new BackGround;
    scene->addItem(back);


    //Create player
    player = new Player;
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
    player->grabMouse();

    //delay enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(emerge()));
    timer->start(2000);

    QTimer * timerB = new QTimer();
    QObject::connect(timerB,SIGNAL(timeout()),player,SLOT(bonus()));
    timerB->start(5333);
}

void MainWindow::active()
{
    QMediaPlaylist *sound = new QMediaPlaylist();
    sound->addMedia(QUrl("qrc:/music/continue.mp3"));
    music = new QMediaPlayer;
    music->setPlaylist(sound);
    music->play();

    health->stoop = false;
    player->setFocus();
}

void MainWindow::desactive()
{
    QMediaPlaylist *sound = new QMediaPlaylist();
    sound->addMedia(QUrl("qrc:/music/pause.mp3"));
    music = new QMediaPlayer;
    music->setPlaylist(sound);
    music->play();

    health->stoop = true;
    player->clearFocus();
}

void MainWindow::heelp()
{
    music->stop();
    scene->clear();

    text = new QGraphicsTextItem;
    text->setPlainText(QString("Help mode"));
    text->setFont(QFont("Purisa, 100"));
    text->setPos(300, 150);
    text->setDefaultTextColor(Qt::white);
    text->setZValue(5);
    scene->addItem(text);

    QMediaPlaylist *helpsM = new QMediaPlaylist();
    helpsM->addMedia(QUrl("qrc:/music/help mode.mp3"));
    music = new QMediaPlayer;
    music->setPlaylist(helpsM);
    music->play();

    //sound and text
    QGraphicsTextItem *ctrlT = new QGraphicsTextItem;
    ctrlT->setPlainText(QString("Press CTRL+N to start the game"));
    ctrlT->setFont(QFont("Purisa, 100"));
    ctrlT->setPos(300, 175);
    ctrlT->setDefaultTextColor(Qt::cyan);
    ctrlT->setZValue(5);
    scene->addItem(ctrlT);

    helpsM->addMedia(QUrl("qrc:/music/Ctrl+N.mp3"));
    music->play();

    QGraphicsTextItem *aydT = new QGraphicsTextItem;
    aydT->setPlainText(QString("With A y D you move your player"));
    aydT->setFont(QFont("Purisa, 100"));
    aydT->setPos(300, 200);
    aydT->setDefaultTextColor(Qt::cyan);
    aydT->setZValue(5);
    scene->addItem(aydT);

    helpsM->addMedia(QUrl("qrc:/music/A y d.mp3"));
    music->play();

    QGraphicsTextItem *cT = new QGraphicsTextItem;
    cT->setPlainText(QString("Press C to continue"));
    cT->setFont(QFont("Purisa, 100"));
    cT->setPos(300, 225);
    cT->setDefaultTextColor(Qt::cyan);
    cT->setZValue(5);
    scene->addItem(cT);

    helpsM->addMedia(QUrl("qrc:/music/C to continue.mp3"));
    music->play();

    QGraphicsTextItem *sT = new QGraphicsTextItem;
    sT->setPlainText(QString("Press S to stop"));
    sT->setFont(QFont("Purisa, 100"));
    sT->setPos(300, 250);
    sT->setDefaultTextColor(Qt::cyan);
    sT->setZValue(5);
    scene->addItem(sT);

    helpsM->addMedia(QUrl("qrc:/music/S to stop.mp3"));
    music->play();

    QGraphicsTextItem *quitT = new QGraphicsTextItem;
    quitT->setPlainText(QString("Press Q to quit"));
    quitT->setFont(QFont("Purisa, 100"));
    quitT->setPos(300, 275);
    quitT->setDefaultTextColor(Qt::cyan);
    quitT->setZValue(5);
    scene->addItem(quitT);

    helpsM->addMedia(QUrl("qrc:/music/Q to quit.mp3"));
    music->play();
}

