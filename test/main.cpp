#include "mainwindow.h"
#include <QApplication>
#include "socketconnectelm.h"
#include "dialogcardreader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;

    //baca file txt buat parameter database_connect

    //baca isi lempar ke database_connect di class control mesin

    mainWindow.showFullScreen();
    return a.exec();
}
