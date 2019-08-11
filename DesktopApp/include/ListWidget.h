#ifndef LIST_WIDGET_H
#define LIST_WIDGET_H

#include "ListItem.h"

#include <QList>
#include <QWidget>
#include <QScrollArea>
#include <QHBoxLayout>

class ListWidget : public QScrollArea
{
    Q_OBJECT;

public:
    explicit ListWidget(QWidget *parent = nullptr);
    ~ListWidget();

    int len();

    bool appendItem(ListItem *item);
    bool removeItem(ListItem *item);

    const QList<ListItem *> getItems();

private:
    QList<ListItem *> items;

    QHBoxLayout *spaceLayout;
    QWidget *spaceWidget;
};

#endif // LIST_WIDGET_H

