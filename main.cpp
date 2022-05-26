#include "mainwindow.h"
//#include "painterwindow.h"
#include <QApplication>
#include <iostream>
//#include "window.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}