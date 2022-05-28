#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

/**
 * Constructor function
 *
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/**
 * Destructor function
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * Calls canvas window with entered information
 */
void MainWindow::on_pushButton_clicked() {
    int heightVal = this->ui->heightTextEdit->text().toInt();
    int widthVal = this->ui->widthTextEdit->text().toInt();

    if (heightVal <= 671 && widthVal <= 1481 && heightVal > 0 && widthVal > 0) {
        auto *canvas = new Canvas(nullptr, widthVal, heightVal);
        canvas->show();
        hide();
    }
}
