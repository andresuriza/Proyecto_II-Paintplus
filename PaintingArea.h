#ifndef PAINTINGAREA_H
#define PAINTINGAREA_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>
#include "BitmapWriter.cpp"

/**
 * Class that manages user input to allow drawing
 */
class PaintingArea : public QWidget
{
Q_OBJECT

public:
    explicit PaintingArea(QWidget *parent = nullptr);

    bool OpenImage(const QString &fileName);
    void setPenColor(const QColor &newColor, string currentColor);
    void setPenWidth(int newWidth);

    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }
    void SetDimensions(int width, int height);

    void SaveBMP(string* name);

    bool colorPicker = false;
    bool paintFill = false;
    bool pen = false;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);

    bool scribbling = false;
    int myPenWidth = 1;
    QColor myPenColor;
    QImage image;
    QPoint lastPoint;
    Painter* p{};

    int widthCanvas{};
    int heightCanvas{};
    string bmpColor;
};

#endif
