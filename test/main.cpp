#include "mainwindow.h"
#include <QApplication>
#include "socketconnectelm.h"
#include "dialogcardreader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;

    mainWindow.showFullScreen();
    mainWindow.show();
    return a.exec();
}
