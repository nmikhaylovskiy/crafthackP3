#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDebug>
#include <QPixmap>
#include <QHBoxLayout>
#include "ListItem.h"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connectAll();

    for (int i = 0; i <  10; i++)
    {
        auto temp = new ListItem(this);
        temp->setImage(QPixmap("./test.jpg"));
        temp->setName("Бутылка");
        temp->setDescription("Никита - чмо");
        ui->listIngredient->appendItem(temp);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectAll()
{
    connect(ui->labBtn, &QPushButton::clicked, this, [this] { setCurrentPage(Laboratory); });
    connect(ui->genBtn, &QPushButton::clicked, this, [this] { setCurrentPage(Generating); });

    connect(ui->dirChooseBtn, &QPushButton::clicked, this, &MainWindow::chooseDir);
}

void MainWindow::setCurrentPage(int idx)
{
    ui->pages->setCurrentIndex(idx);
}

void MainWindow::chooseDir()
{
    QString dirpath = QFileDialog::getExistingDirectory(this);

    if (dirpath != "")
    {
        ui->dirPathEntry->setText(dirpath);
    }
}

