#ifndef SOCKETCONNECTELM_H
#define SOCKETCONNECTELM_H

#include <QObject>
#include <QDebug>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>

class SocketConnectELM : public QObject
{
    Q_OBJECT
public:
    explicit SocketConnectELM(QObject *parent = nullptr);
    void StartConnection(const char *paket);
    QString getMessage();

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

private:
    QTcpSocket *socket;
};

#endif // SOCKETCONNECTELM_H
