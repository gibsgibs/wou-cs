#include <iostream>
#include <QApplication>
#include <ctime>
#include "DiceGameDialog.h"
#include <QMainWindow>


using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    srand(time(0));

    DiceGameDialog theGame;

    theGame.show();

    return app.exec();

}
