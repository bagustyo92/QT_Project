#include "socketconnectelm.h"

SocketConnectELM::SocketConnectELM(QObject *parent) : QObject(parent)
{

}

void SocketConnectELM::StartConnection(QString paket){
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64 bytes)), this, SLOT(bytesWritten(qint64 bytes)));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    qDebug() << "Connecting to the ELM ...";
    socket->connectToHost("google.co.id", 80);

    if (socket->waitForConnected(3000)){
        socket->write("HEAD / HTTP/1.0\r\n\r\n");
//        qDebug() << "Error: " << socket->errorString();
    } else {
        qDebug() << "Error: " << socket->errorString();
    }
}

void SocketConnectELM::connected(){
    qDebug() << "Connected to ELM!";
}

void SocketConnectELM::disconnected(){
    qDebug() << "Disconected to ELM!";
}

void SocketConnectELM::bytesWritten(qint64 bytes){
    qDebug() << "Number of byte write : " << bytes;
}

void SocketConnectELM::readyRead(){
    qDebug() << "Reading Response from ELM ....";
    qDebug() << socket->readAll();
}
