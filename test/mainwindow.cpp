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
    paket = "1";
    connectingElm.StartConnection(paket);
    cardReader->showFullScreen();
}

void MainWindow::on_pushButton_cuciLipat_clicked()
{
    paket = "2";
    connectingElm.StartConnection(paket);
    cardReader->showFullScreen();
}

void MainWindow::on_pushButton_cuciKering_clicked()
{
    paket = "3";
    connectingElm.StartConnection(paket);
    cardReader->showFullScreen();
}

QString MainWindow::getTitle(){
    QString title1;
    if (paket == "1"){
        title1 = "CUCI SETRIKA";
    } else if (paket == "2"){
        title1 = "CUCI LIPAT";
    } else {
        title1 = "CUCI KERING";
    }
    return title1;
}

void MainWindow::on_pushButton_controlMesin_clicked()
{
    controlMesin->showFullScreen();
}
