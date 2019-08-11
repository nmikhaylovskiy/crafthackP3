#include <QApplication>
#include <QFile>
#include <QFont>
#include <QFontDatabase>

#include "mainwindow.h"

int main(int argc, char **argv)
{
    QFile styleSrc(":/base/MyTheme.qss");
    QApplication a(argc, argv);

    QFontDatabase::addApplicationFont(":/base/Roboto-Regular.ttf");

    QFont mainFont("Roboto Regular");
    mainFont.setPointSize(12);
    a.setFont(mainFont);

    QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles, true);
    styleSrc.open(QFile::ReadOnly);
    a.setStyleSheet(styleSrc.readAll());
    styleSrc.close();

    a.setWindowIcon(QIcon(":/base/ApplicationIcon.png"));

    MainWindow w;
    w.show();

    return a.exec();
}

