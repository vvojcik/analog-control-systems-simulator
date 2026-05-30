#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("Analog Control Systems Simulator - Politechnika Gdańska");

    w.showMaximized();

    return QApplication::exec();
}