#ifndef CANVAS_H
#define CANVAS_H

#include <QMainWindow>
#include <iostream>
#include <QPushButton>

using namespace std;

namespace Ui {
class Canvas;
}

class Canvas : public QMainWindow
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent, int width, int height);
    ~Canvas();

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
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void paintPixel(QPushButton* button);

private:
    Ui::Canvas *ui;
    string currentColor = "black";
};

#endif // CANVAS_H
