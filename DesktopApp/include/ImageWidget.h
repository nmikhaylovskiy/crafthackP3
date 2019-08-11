#ifndef IMAGE_WIDGET_H_
#define IMAGE_WIDGET_H_

#include <QWidget>
#include <QPixmap>
#include <QPainter>

class ImageWidget : public QWidget
{
    Q_OBJECT;

public:
    explicit ImageWidget(QWidget *parent = nullptr, const QPixmap &image = QPixmap());
    ~ImageWidget() override;

    void setImage(const QPixmap &image);

protected:
    void paintEvent(QPaintEvent *e) override;

private:
    QPixmap image;
};

#endif // IMAGE_WIDGET_H_

