#include <QPainter>
#include "canvas.h"
#include "ui_canvas.h"
#include <QMouseEvent>
#include <QPicture>
#include <QGridLayout>
#include "scribblearea.h"
#include <QThread>

Canvas::Canvas(QWidget *parent, int width, int height) : QMainWindow(parent),
ui(new Ui::Canvas), scribbleArea(new ScribbleArea(this))
//, art(width, height)
{
    ui->setupUi(this);
    cout << width << endl;
    cout << height << endl;
    ui->canvasWidget->setFixedSize(height,width);
    ui->canvasWidget->setSize(width,height);
    //setCentralWidget(scribbleArea);
    //scribbleArea->resize(100,100);
    //PixelCreator();
}

// MAX CANVAS SIZE 1481x671

void Canvas::PixelCreator()
{
    QGridLayout* grid = new QGridLayout();
    grid->setVerticalSpacing(0);
    grid->setVerticalSpacing(0);
    int columns;

        for (int i = 0; i < 500; i++) {
            for (int j = 0; j < 500; j++) {
            }
        }
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
    currentColor = "lightGray";
}

void Canvas::on_whiteButton_clicked()
{
    currentColor = "white";
}

/*
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
        art.Paint("red", button->objectName().toStdString());
        button->setStyleSheet("background-color:rgb(255, 0, 0); border:none;");
    }

    if (currentColor == "orange")
    {
        art.Paint("orange", button->objectName().toStdString());
        button->setStyleSheet("background-color:rgb(255, 121, 11); border:none;");
    }

    if (currentColor == "yellow")
    {
        art.Paint("yellow", button->objectName().toStdString());
        button->setStyleSheet("background-color:rgb(255, 239, 20); border:none;");
    }

    if (currentColor == "lime")
    {
        art.Paint("lime", button->objectName().toStdString());
        button->setStyleSheet("background-color:rgb(0, 255, 0); border:none;");
    }

    if (currentColor == "green")
    {
        art.Paint("green", button->objectName().toStdString());
        button->setStyleSheet("background-color:rgb(2, 149, 2); border:none;");
    }

    if (currentColor == "cyan")
    {
        art.Paint("cyan", button->objectName().toStdString());
        button->setStyleSheet("background-color:rgb(0, 255, 255); border:none;");
    }

    if (currentColor == "scarlet")
    {
        art.Paint("scarlet", button->objectName().toStdString());
        button->setStyleSheet("background-color:rgb(184, 0, 0); border:none;");
    }

    if (currentColor == "brown")
    {
        art.Paint("brown", button->objectName().toStdString());
        button->setStyleSheet("background-color:rgb(170, 85, 0); border:none;");
    }

    if (currentColor == "gold")
    {
        art.Paint("gold", button->objectName().toStdString());
        button->setStyleSheet("background-color:rgb(230, 199, 87); border:none;");
    }

    if (currentColor == "pink")
    {
        art.Paint("pink", button->objectName().toStdString());
        button->setStyleSheet("background-color:rgb(233, 66, 255); border:none;");
    }

    if (currentColor == "black")
    {
        art.Paint("black", button->objectName().toStdString());
        button->setStyleSheet("background-color:rgb(0, 0, 0); border:none;");
    }

    if (currentColor == "gray")
    {
        art.Paint("gray", button->objectName().toStdString());
        button->setStyleSheet("background-color:rgb(81, 81, 81); border:none;");
    }

    if (currentColor == "lightGray")
    {
        art.Paint("lightGray", button->objectName().toStdString());
        button->setStyleSheet("background-color:rgb(159, 159, 159); border:none;");
    }

    if (currentColor == "white")
    {
        art.Paint("white", button->objectName().toStdString());
        button->setStyleSheet("background-color:rgb(255, 255, 255); border:none;");
    }
}

 */

void Canvas::saveImage()
{
    auto* outputFileName = (string*) "ui_made.bmp";
    ui->canvasWidget->saveBMP(outputFileName);
    //art.GenerateImage(outputFileName);
}

void Canvas::on_actionSave_triggered()
{
    saveImage();
}
