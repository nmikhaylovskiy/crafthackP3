#ifndef LIST_ITEM_H_
#define LIST_ITEM_H_

#include <QWidget>

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

private:
    Ui::ListItem *ui;
};

#endif // LIST_ITEM_H_

