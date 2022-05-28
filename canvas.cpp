#include <QPainter>
#include "canvas.h"
#include "ui_canvas.h"
#include <QMouseEvent>
#include <QPicture>
#include <QGridLayout>
#include "PaintingArea.h"

/**
 *
 * Constructor function
 *
 * @param parent
 * @param width
 * @param height
 */
Canvas::Canvas(QWidget *parent, int width, int height) : QMainWindow(parent),
ui(new Ui::Canvas), paintingArea(new PaintingArea(this))
{
    ui->setupUi(this);
    ui->canvasWidget->setFixedSize(width,height);
    ui->canvasWidget->SetDimensions(width, height);
}

// MAX CANVAS SIZE 1481x671

/**
 * Destructor function
 */
Canvas::~Canvas()
{
    delete ui;
}

/**
 * Action when redButton is clicked
 */
void Canvas::on_redButton_clicked()
{
    pickedColor.setRgb(255, 0, 0, 255);
    ui->canvasWidget->setPenColor(pickedColor, "red");
}

/**
 * Action when orangeButton is clicked
 */
void Canvas::on_orangeButton_clicked()
{
    pickedColor.setRgb(255, 121, 11, 255);
    ui->canvasWidget->setPenColor(pickedColor, "orange");
}

/**
 * Action when yellowButton is clicked
 */
void Canvas::on_yellowButton_clicked()
{
    pickedColor.setRgb(255, 239, 20, 255);
    ui->canvasWidget->setPenColor(pickedColor, "yellow");
}

/**
 * Action when limeButton is clicked
 */
void Canvas::on_limeButton_clicked()
{
    pickedColor.setRgb(0, 250, 0, 255);
    ui->canvasWidget->setPenColor(pickedColor, "lime");
}

/**
 * Action when greenButton is clicked
 */
void Canvas::on_greenButton_clicked()
{
    pickedColor.setRgb(2, 149, 2, 255);
    ui->canvasWidget->setPenColor(pickedColor, "green");
}

/**
 * Action when cyanButton is clicked
 */
void Canvas::on_cyanButton_clicked()
{
    pickedColor.setRgb(0, 255, 255, 255);
    ui->canvasWidget->setPenColor(pickedColor, "cyan");
}

/**
 * Action when scarletButton is clicked
 */
void Canvas::on_scarletButton_clicked()
{
    pickedColor.setRgb(184, 0, 0, 255);
    ui->canvasWidget->setPenColor(pickedColor, "scarlet");
}

/**
 * Action when brownButton is clicked
 */
void Canvas::on_brownButton_clicked()
{
    pickedColor.setRgb(170, 85, 0, 255);
    ui->canvasWidget->setPenColor(pickedColor, "brown");
}

/**
 * Action when goldButton is clicked
 */
void Canvas::on_goldButton_clicked()
{
    pickedColor.setRgb(230, 199, 87, 255);
    ui->canvasWidget->setPenColor(pickedColor, "gold");
}

/**
 * Action when pinkButton is clicked
 */
void Canvas::on_pinkButton_clicked()
{
    pickedColor.setRgb(233, 66, 255, 255);
    ui->canvasWidget->setPenColor(pickedColor, "pink");
}

/**
 * Action when blackButton is clicked
 */
void Canvas::on_blackButton_clicked()
{
    pickedColor.setRgb(0, 0, 0, 255);
    ui->canvasWidget->setPenColor(pickedColor, "black");
}

/**
 * Action when grayButton is clicked
 */
void Canvas::on_grayButton_clicked()
{
    pickedColor.setRgb(81, 81, 81, 255);
    ui->canvasWidget->setPenColor(pickedColor, "gray");
}

/**
 * Action when lightGrayButton is clicked
 */
void Canvas::on_lightGrayButton_clicked()
{
    pickedColor.setRgb(159, 159, 159, 255);
    ui->canvasWidget->setPenColor(pickedColor, "lightgray");
}

/**
 * Action when whiteButton is clicked
 */
void Canvas::on_whiteButton_clicked()
{
    pickedColor.setRgb(255, 255, 255, 255);
    ui->canvasWidget->setPenColor(pickedColor, "white");
}

/**
 * Calls a function to save the drawn BMP with the specified name
 */
void Canvas::saveImage()
{
    auto* outputFileName = (string*) "ui_made.bmp";
    ui->canvasWidget->SaveBMP(outputFileName);
    //art.GenerateImage(outputFileName);
}

/**
 * Action for the save button
 */
void Canvas::on_actionSave_triggered()
{
    saveImage();
}

void Canvas::on_actionColor_Picked_triggered()
{
    ui->canvasWidget->colorPicker = true;
}

