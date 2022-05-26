#include "mainwindow.h"
//#include "painterwindow.h"
#include <QApplication>
#include <iostream>
//#include "window.h"

using namespace std;

void GridTranslator(int width, int height)
{
    int matrix[2][2] = {{0,1},{2,3}};

    if (height > 2)
    {

    }

}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}