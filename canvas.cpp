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

void Canvas::on_redButton_clicked()
{
    currentColor = "red";
}

void Canvas::on_orangeButton_clicked()
{
    currentColor = "orange";
}

void Canvas::on_yellowButton_clicked()
{
    currentColor = "yellow";
}

void Canvas::on_limeButton_clicked()
{
    currentColor = "lime";
}

void Canvas::on_greenButton_clicked()
{
    currentColor = "green";
}

void Canvas::on_cyanButton_clicked()
{
    currentColor = "cyan";
}

void Canvas::on_scarletButton_clicked()
{
    currentColor = "scarlet";
}

void Canvas::on_brownButton_clicked()
{
    currentColor = "brown";
}

void Canvas::on_goldButton_clicked()
{
    currentColor = "gold";
}

void Canvas::on_pinkButton_clicked()
{
    currentColor = "pink";
}

void Canvas::on_blackButton_clicked()
{
    currentColor = "black";
}

void Canvas::on_grayButton_clicked()
{
    currentColor = "gray";
}

void Canvas::on_lightGrayButton_clicked()
{
    currentColor = "lightgray";
}

void Canvas::on_whiteButton_clicked()
{
    currentColor = "white";
}

void Canvas::on_pushButton_clicked()
{
    paintPixel(ui->pushButton);
}

void Canvas::on_pushButton_2_clicked()
{
    paintPixel(ui->pushButton_2);
}

void Canvas::on_pushButton_3_clicked()
{
    paintPixel(ui->pushButton_3);
}

void Canvas::on_pushButton_4_clicked()
{
    paintPixel(ui->pushButton_4);
}

void Canvas::paintPixel(QPushButton* button)
{
    if (currentColor == "red")
    {
        button->setStyleSheet("background-color:rgb(255, 0, 0); border:none;");
    }

    if (currentColor == "orange")
    {
        button->setStyleSheet("background-color:rgb(255, 121, 11); border:none;");
    }

    if (currentColor == "yellow")
    {
        button->setStyleSheet("background-color:rgb(255, 239, 20); border:none;");
    }

    if (currentColor == "lime")
    {
        button->setStyleSheet("background-color:rgb(0, 255, 0); border:none;");
    }

    if (currentColor == "green")
    {
        button->setStyleSheet("background-color:rgb(2, 149, 2); border:none;");
    }

    if (currentColor == "cyan")
    {
        button->setStyleSheet("background-color:rgb(0, 255, 255); border:none;");
    }

    if (currentColor == "scarlet")
    {
        button->setStyleSheet("background-color:rgb(184, 0, 0); border:none;");
    }

    if (currentColor == "brown")
    {
        button->setStyleSheet("background-color:rgb(170, 85, 0); border:none;");
    }

    if (currentColor == "gold")
    {
        button->setStyleSheet("background-color:rgb(230, 199, 87); border:none;");
    }

    if (currentColor == "pink")
    {
        button->setStyleSheet("background-color:rgb(233, 66, 255); border:none;");
    }

    if (currentColor == "black")
    {
        button->setStyleSheet("background-color:rgb(0, 0, 0); border:none;");
    }

    if (currentColor == "gray")
    {
        button->setStyleSheet("background-color:rgb(81, 81, 81); border:none;");
    }

    if (currentColor == "lightgray")
    {
        button->setStyleSheet("background-color:rgb(159, 159, 159); border:none;");
    }

    if (currentColor == "white")
    {
        button->setStyleSheet("background-color:rgb(255, 255, 255); border:none;");
    }
}