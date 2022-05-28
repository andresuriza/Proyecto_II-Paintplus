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
    currentColor = "red";
}

/**
 * Action when redButton is clicked
 */
void Canvas::on_orangeButton_clicked()
{
    currentColor = "orange";
}

/**
 * Action when redButton is clicked
 */
void Canvas::on_yellowButton_clicked()
{
    currentColor = "yellow";
}

/**
 * Action when redButton is clicked
 */
void Canvas::on_limeButton_clicked()
{
    currentColor = "lime";
}

/**
 * Action when redButton is clicked
 */
void Canvas::on_greenButton_clicked()
{
    currentColor = "green";
}

/**
 * Action when redButton is clicked
 */
void Canvas::on_cyanButton_clicked()
{
    currentColor = "cyan";
}

/**
 * Action when redButton is clicked
 */
void Canvas::on_scarletButton_clicked()
{
    currentColor = "scarlet";
}

/**
 * Action when redButton is clicked
 */
void Canvas::on_brownButton_clicked()
{
    currentColor = "brown";
}

/**
 * Action when redButton is clicked
 */
void Canvas::on_goldButton_clicked()
{
    currentColor = "gold";
}

/**
 * Action when redButton is clicked
 */
void Canvas::on_pinkButton_clicked()
{
    currentColor = "pink";
}

/**
 * Action when redButton is clicked
 */
void Canvas::on_blackButton_clicked()
{
    currentColor = "black";
}

/**
 * Action when redButton is clicked
 */
void Canvas::on_grayButton_clicked()
{
    currentColor = "gray";
}

/**
 * Action when redButton is clicked
 */
void Canvas::on_lightGrayButton_clicked()
{
    currentColor = "lightGray";
}

/**
 * Action when redButton is clicked
 */
void Canvas::on_whiteButton_clicked()
{
    currentColor = "white";
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
