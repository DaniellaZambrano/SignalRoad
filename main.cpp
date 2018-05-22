#include "MainWindow.H"
#include <QApplication>

MainWindow *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new MainWindow();
    game->show();

    return a.exec();
}
