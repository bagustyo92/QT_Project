#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "readerdialog.h"
#include "controlmesin.h"
#include "socketconnectelm.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readerDialog = new ReaderDialog(this);
    controlMesin = new ControlMesin(this);
    this->setFixedSize(500, 500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

SocketConnectELM connectingElm;
QString paket;

void MainWindow::connectingToElm(QString paket){
    connectingElm.StartConnection(paket);
}

void MainWindow::on_pushButton_cuciSetrika_clicked()
{
    readerDialog->setLabelText("CUCI SETRIKA");
    paket = "cuci_setrika";
    connectingToElm(paket);
    readerDialog->exec();
}

void MainWindow::on_pushButton_cuciLipat_clicked()
{
    readerDialog->setLabelText("CUCI LIPAT");
    readerDialog->exec();
}

void MainWindow::on_pushButton_cuciKering_clicked()
{
    readerDialog->setLabelText("CUCI KERING");
    readerDialog->exec();
}

void MainWindow::on_pushButton_controlMesin_clicked()
{
    controlMesin->exec();
}
