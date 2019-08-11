#include "ListItem.h"
#include "ui_listitem.h"

ListItem::ListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListItem)
{
    ui->setupUi(this);

    connectAll();
}

ListItem::~ListItem()
{
    delete ui;
}

void ListItem::connectAll()
{
    connect(ui->descriptionBtn, SIGNAL(clicked()), this, SLOT(showDescription()));
}

void ListItem::setImage(const QPixmap &image)
{
    ui->imageDisplay->setImage(image);
}

void ListItem::setName(QString name)
{
    ui->nameLabel->setText(name);
}

void ListItem::setDescription(QString description)
{
    this->description = description;
}

void ListItem::showDescription()
{
    QMessageBox::information(this, ui->nameLabel->text(), this->description);
}

bool ListItem::isChecked()
{
    return ui->selectionBox->isChecked();
}

