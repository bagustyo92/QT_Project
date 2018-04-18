#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    controlMesin = new ControlMesin(this);
    cardReader = new DialogCardReader(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString value;
void MainWindow::onServerReply(QString message){
    value = message;
}

SocketConnectELM connectingElm;
char *paket;

void MainWindow::on_pushButton_cuciSetrika_clicked()
{
    paket = "CUCI SETRIKA";
    connectingElm.StartConnection(paket);
    cardReader->showFullScreen();
}

void MainWindow::on_pushButton_cuciLipat_clicked()
{
    paket = "CUCI LIPAT";
    connectingElm.StartConnection(paket);
    cardReader->showFullScreen();
}

void MainWindow::on_pushButton_cuciKering_clicked()
{
    paket = "CUCI KERING";
    connectingElm.StartConnection(paket);
    cardReader->showFullScreen();
}

QString MainWindow::getTitle(){
    return paket;
}

void MainWindow::on_pushButton_controlMesin_clicked()
{
    controlMesin->showFullScreen();
}
