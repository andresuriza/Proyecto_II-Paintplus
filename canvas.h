#ifndef CANVAS_H
#define CANVAS_H

#include <QMainWindow>
#include <iostream>
#include <QPushButton>
#include <QGridLayout>
#include "PaintingArea.h"
#include <QColor>

using namespace std;

class Canvas;

namespace Ui {
class Canvas;
}

/**
 * Class that creates a UI that includes a canvas and other tools for drawing
 */
class Canvas : public QMainWindow
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent, int width, int height);
    ~Canvas() override;

private slots:
    void on_redButton_clicked();
    void on_orangeButton_clicked();
    void on_yellowButton_clicked();
    void on_limeButton_clicked();
    void on_greenButton_clicked();
    void on_cyanButton_clicked();
    void on_scarletButton_clicked();
    void on_brownButton_clicked();
    void on_goldButton_clicked();
    void on_pinkButton_clicked();
    void on_blackButton_clicked();
    void on_grayButton_clicked();
    void on_lightGrayButton_clicked();
    void on_whiteButton_clicked();
    void saveImage();
    void on_actionSave_triggered();

    void on_actionColor_Picked_triggered();

    void on_actionPaint_Fill_triggered();

    void on_actionPen_triggered();

private:
    Ui::Canvas *ui;
    string currentColor = "black";
    PaintingArea *paintingArea;
    QColor pickedColor;

protected:
};



#endif // CANVAS_H
