#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int heightVal = this->ui->heightTextEdit->text().toInt();
    int widthVal = this->ui->widthTextEdit->text().toInt();

    this->close();
    Canvas canvas;
    canvas.setModal(false);
    canvas.show();
    canvas.exec();
}
