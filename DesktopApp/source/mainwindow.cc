#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connectAll();
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

