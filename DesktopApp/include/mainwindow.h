#ifndef MAINWINDOW_H_
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    enum Page
    {
        Laboratory,
        Generating
    };

private:
    Ui::MainWindow *ui;

    void connectAll();

private slots:
    void setCurrentPage(int idx);
    void chooseDir();
};

#endif // MAINWINDOW_H_

