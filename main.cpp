//#include "mainwindow.h"
#include "BitmapWriter.cpp"
//#include <QApplication>
//#include <iostream>
//#include "window.h"

using namespace std;

int main(int argc, char *argv[])
{
    Painter p(2, 2);
    p.Paint("red", 0);
    p.Paint("red", 1);
    p.Paint("scarlet", 2);
    p.Paint("scarlet", 3);

    auto* outputFileName = (string*) "ejemplo.bmp";

    p.GenerateImage(outputFileName);

    //QApplication a(argc, argv);
    //Window window;
    //window.show();
    //MainWindow w;
    //w.show();
    //return a.exec();
}