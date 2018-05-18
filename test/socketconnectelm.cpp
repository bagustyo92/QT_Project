#include "socketconnectelm.h"
#include "mainwindow.h"
#include "dialogcardreader.h"
#include <QMessageBox>
#include "tapcard_window.h"

SocketConnectELM::SocketConnectELM(QObject *parent) : QObject(parent)
{

}

QString message;

void SocketConnectELM::StartConnection(const char *paket){
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64 bytes)), this, SLOT(bytesWritten(qint64 bytes)));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));


    qDebug() << "Connecting to the ELM ...";
    socket->connectToHost("localhost", 8888);

    if (socket->waitForConnected(3000)){
        socket->write(paket);
        qDebug() << "client said : " << paket;
    } else {
        qDebug() << "Error: " << socket->errorString();
    }
}

bool status;
void SocketConnectELM::connected(){
    qDebug() << "Connected to ELM!";
    status = true;
}

void SocketConnectELM::disconnected(){
    qDebug() << "Disconected to ELM!";
    status = false;
}

void SocketConnectELM::bytesWritten(qint64 bytes){
    qDebug() << "Number of byte write : " << bytes;
}

QString val;

void SocketConnectELM::readyRead(){
    qDebug() << "Reading Response from ELM ....";
    val = socket->readAll();
    qDebug() << "Server Said : " << val;

    //sent to main
    MainWindow mainWindow;
    mainWindow.onServerReply(val);

    //sent to cardDialog
    DialogCardReader cardReader;
    cardReader.onServerReply();
}

QString SocketConnectELM::getMessage(){
    return val;
}

bool SocketConnectELM::getStatus(){
    return status;
}
