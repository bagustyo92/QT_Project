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
char *paket;

void MainWindow::connectingToElm(char *paket){
    connectingElm.StartConnection(paket);
}

void MainWindow::on_pushButton_cuciSetrika_clicked()
{
    paket = "cuci_setrika";
    connectingToElm(paket);

    readerDialog->setLabelText("CUCI SETRIKA", 1);
    readerDialog->exec();
}

void MainWindow::on_pushButton_cuciLipat_clicked()
{
    paket = "cuci_lipat";
    connectingToElm(paket);

    readerDialog->setLabelText("CUCI LIPAT", 1);
    readerDialog->exec();
}

void MainWindow::on_pushButton_cuciKering_clicked()
{
    paket = "cuci_kering";
    connectingToElm(paket);

    readerDialog->setLabelText("CUCI KERING", 1);
    readerDialog->exec();
}

void MainWindow::on_pushButton_controlMesin_clicked()
{
    controlMesin->exec();
}
