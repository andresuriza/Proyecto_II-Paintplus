#include "canvas.h"
#include "ui_canvas.h"

Canvas::Canvas(QWidget *parent, int width, int height) : QMainWindow(parent), ui(new Ui::Canvas)
{
    ui->setupUi(this);
}

Canvas::~Canvas()
{
    delete ui;
}
