#include "ListWidget.h"
#include<QPushButton>
ListWidget::ListWidget(QWidget *parent) :
    QScrollArea(parent),

    spaceLayout(new QHBoxLayout),
    spaceWidget(new QWidget)
{
    spaceWidget->setLayout(spaceLayout);
    this->setWidget(spaceWidget);

    spaceWidget->setParent(this);

    setWidgetResizable(true);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

ListWidget::~ListWidget()
{
    delete spaceLayout;
    delete spaceWidget;
}

int ListWidget::len()
{
    return items.length();
}

bool ListWidget::appendItem(ListItem *item)
{
    items.append(item);
    spaceLayout->addWidget(item);

    return true;
}

bool ListWidget::removeItem(ListItem *item)
{
    items.removeAll(item);
    spaceLayout->removeWidget(item);

    return true;
}

const QList<ListItem *> ListWidget::getItems()
{
    return items;
}

