#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>
#include <QtSql/QSqlDatabase>
#include <QFile>
#include <QTextStream>
#include <QThread>

#define BUTTON_COLOR "background-color:rgb(191, 210, 214); color:white; font-weight: bold;"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/resources/img/Kain Wangi logo.png");
    ui->label_menuUtama->setPixmap(pix.scaled(380, 380, Qt::KeepAspectRatio));

    QPixmap mytag(":/resources/img/may_tag.png");
    ui->maytag_label->setPixmap(mytag.scaled(100, 100, Qt::KeepAspectRatio));

    ui->pushButton_ambilCucian->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_controlMesin->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_cuciKering->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_cuciLipat->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_cuciSetrika->setStyleSheet(BUTTON_COLOR);

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

void MainWindow::onStatusConnect(){
    if (!connectingElm.getStatus()){
//        QMessageBox::warning(this, "PERINGATAN..!", "GAGAL Menghubungkan GUI ke SERVER ELM!");
        QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "GAGAL Menghubungkan GUI ke SERVER ELM!",
                           QMessageBox::Ok, this, Qt::FramelessWindowHint);
        msgBox.exec();
        qDebug() << "Failed Connect to Server";
    } else {
        cardReader->showFullScreen();
    }
}

void MainWindow::on_pushButton_cuciSetrika_clicked()
{
    QThread::sleep(2);
    paket = "1";
    connectingElm.StartConnection(paket);
    onStatusConnect();
}

void MainWindow::on_pushButton_cuciLipat_clicked()
{
    QThread::sleep(2);
    paket = "2";
    connectingElm.StartConnection(paket);
    onStatusConnect();
}

void MainWindow::on_pushButton_cuciKering_clicked()
{
    QThread::sleep(2);
    paket = "3";
    connectingElm.StartConnection(paket);
    onStatusConnect();
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
    //read file for database config
    QFile database_config("/var/elm/elm.conf");
    if (!database_config.exists()){
        QMessageBox::warning(this, "PERINGATAN!", "Failed read databaseconfig file(var/elm/elm.conf). error: " + database_config.errorString());
    } else {
        qDebug() << "Reading database ...";
    }

    QString line, hostName, port, userName, password, dbName;

    if (database_config.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&database_config);
        while(!stream.atEnd()){
            line = stream.readLine();
            if(line.split('=').first() == "PCDS_ADDRESS"){
                hostName = line.split('=').last();
            }
            if(line.split('=').first() == "PCDS_PORT"){
                port = line.split('=').last();
            }
            if(line.split('=').first() == "PCDS_DB"){
                dbName = line.split('=').last();
            }
            if(line.split('=').first() == "PCDS_USER"){
                userName = line.split('=').last();
            }
            if(line.split('=').first() == "PCDS_PASSWD"){
                password = line.split('=').last();
            }
        }
    }
    database_config.close();


    //connect to database and get list mesin + list resi
    if (!controlMesin->database_connect(hostName, port, userName, password, dbName)){
//        QMessageBox::warning(this, "PERINGATAN..!", "GAGAL Menghubungkan GUI ke DATABASE");
        QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "GAGAL Menghubungkan GUI ke DATABASE!",
                           QMessageBox::Ok, this, Qt::FramelessWindowHint);
        msgBox.exec();
    } else {
        controlMesin->database_get_list_mesin();
        controlMesin->database_get_list_pending_transaksi();
        controlMesin->showFullScreen();
    }
}
