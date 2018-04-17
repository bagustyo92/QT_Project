#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readerDialog = new ReaderDialog(this);
    controlMesin = new ControlMesin(this);
    cardReader = new DialogCardReader(this);
    this->setFixedSize(500, 500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

SocketConnectELM connectingElm;
char *paket;
QString value;

void MainWindow::onServerReply(QString message){
    value = message;
}

void MainWindow::on_pushButton_cuciSetrika_clicked()
{
    paket = "cuci_setrika";
    connectingElm.StartConnection(paket);
    readerDialog->setLabelText(value, 2);
    readerDialog->setLabelText(value, 3);
    readerDialog->setLabelText("CUCI SETRIKA", 1);

    cardReader->exec();
//    readerDialog->exec();
}

void MainWindow::on_pushButton_cuciLipat_clicked()
{
    paket = "cuci_lipat";
    connectingElm.StartConnection(paket);
    readerDialog->setLabelText(value, 2);
    readerDialog->setLabelText(value, 3);
    readerDialog->setLabelText("CUCI LIPAT", 1);

    cardReader->exec();
//    readerDialog->exec();
}

void MainWindow::on_pushButton_cuciKering_clicked()
{
    paket = "cuci_kering";
    connectingElm.StartConnection(paket);
    readerDialog->setLabelText(value, 2);
    readerDialog->setLabelText(value, 3);
    readerDialog->setLabelText("CUCI KERING", 1);

    cardReader->exec();
//    readerDialog->exec();
}

void MainWindow::on_pushButton_controlMesin_clicked()
{
    controlMesin->exec();
}
