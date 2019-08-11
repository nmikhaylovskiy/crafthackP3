#ifndef LIST_ITEM_H_
#define LIST_ITEM_H_

#include <QWidget>
#include <QMessageBox>

#include <QPixmap>
#include <QString>

namespace Ui
{
    class ListItem;
}

class ListItem : public QWidget
{
    Q_OBJECT;

public:
    explicit ListItem(QWidget *parent = nullptr);
    ~ListItem() override;

    void setImage(const QPixmap &image);
    void setName(QString name);
    void setDescription(QString description);

    bool isChecked();

private:
    Ui::ListItem *ui;

    QString description;

    void connectAll();

private slots:
    void showDescription();
};

#endif // LIST_ITEM_H_

