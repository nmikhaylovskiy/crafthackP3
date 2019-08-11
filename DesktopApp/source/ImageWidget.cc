#include "ImageWidget.h"

ImageWidget::ImageWidget(QWidget *parent, const QPixmap &image) :
    QWidget(parent),
    image(image)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

ImageWidget::~ImageWidget()
{
}

void ImageWidget::paintEvent(QPaintEvent *e)
{
    QWidget::paintEvent(e);

    QPainter painter(this);

    painter.drawPixmap(0, 0, width(), height(), image.scaled(size()));
}

void ImageWidget::setImage(const QPixmap &image)
{
    this->image = image;

    setMinimumHeight(100);
    setMinimumWidth(100 / (double(image.height()) / image.width()));
}

