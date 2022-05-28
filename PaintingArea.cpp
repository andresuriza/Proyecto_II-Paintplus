#include "PaintingArea.h"
#include <iostream>
#include <QMouseEvent>
#include <QPainter>

using namespace std;

/**
 *
 * Constructor function
 *
 * @param parent
 */
PaintingArea::PaintingArea(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
}

/**
 *
 * Method that allows telling the BMP painter function the dimensions of the canvas
 *
 * @param width
 * @param height
 */
void PaintingArea::SetDimensions(int width, int height)
{
    this->widthCanvas = width;
    this->heightCanvas = height;

    cout << width << endl;
    cout << height << endl;

    p = new Painter(width, height);
}

/**
 *
 * Method that creates a QImage to be drawn in the UI
 *
 * @param fileName
 * @return
 */
bool PaintingArea::OpenImage(const QString &fileName)
{
    QImage loadedImage;
    if (!loadedImage.load(fileName))
        return false;

    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    image = loadedImage;
    modified = false;
    update();
    return true;
}

/**
 *
 * Allows to change the drawing color
 *
 * @param newColor
 */
void PaintingArea::SetPenColor(const QColor &newColor)
{
    myPenColor = newColor;
}

/**
 *
 * Allows to change the tool width
 *
 * @param newWidth
 */
void PaintingArea::SetPenWidth(int newWidth)
{
    myPenWidth = newWidth;
}

/**
 *
 * Sets scribbling to true when clicking on canvas
 *
 * @param event
 */
void PaintingArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
        scribbling = true;

        //cout << event->pos().x() << endl;
       // cout << event->pos().y() << endl;
    }
}

/**
 *
 * Draws pixels when moving mouse and holding down left click
 *
 * @param event
 */
void PaintingArea::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton) && scribbling) {
        if (event->pos().x() <= 500 && event->pos().x() >= 0 && event->pos().y() <= 500 && event->pos().y() >= 0) {
            drawLineTo(event->pos());
            p->Paint("black", event->pos().y(), event->pos().x());
           // cout << event->pos().x() << endl;
           // cout << event->pos().y() << endl;
        }
    }
}

/**
 *
 * Draws a pixel when releasing the left click
 *
 * @param event
 */
void PaintingArea::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && scribbling) {
        if (event->pos().x() <= 500 && event->pos().x() >= 0 && event->pos().y() <= 500 && event->pos().y() >= 0) {
            drawLineTo(event->pos());
            scribbling = false;
            p->Paint("black", event->pos().y(), event->pos().x());
            //cout << event->pos().x() << endl;
            // cout << event->pos().y() << endl;
        }
    }
}

/**
 *
 * Creates a QPainter canvas to be drawn in the image
 *
 * @param event
 */
void PaintingArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

/**
 *
 * Allows resizing the canvas
 *
 * @param event
*/
void PaintingArea::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

/**
 *
 * Modifies the behavior of drawing in the canvas
 *
 * @param endPoint
 */
void PaintingArea::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::SquareCap,
                        Qt::BevelJoin));
    painter.drawLine(lastPoint, endPoint);
    modified = true;

    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized()
                   .adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}

/**
 *
 * Sets the dimensions of the canvas
 *
 * @param image
 * @param newSize
*/
void PaintingArea::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

/**
 *
 * Saves the BMP using the painter class
 *
 * @param name
 */
void PaintingArea::SaveBMP(string *name)
{
    p->GenerateImage(name);
}