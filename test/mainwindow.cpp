#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tapcard_window.h"
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>
#include <QtSql/QSqlDatabase>
#include <QFile>
#include <QTextStream>
#include <QThread>
#include <QDateTime>
#include <QVector>

#define BUTTON_COLOR "background-color:rgb(191, 210, 214); color:rgb(108, 167, 191); font-weight: bold;"
#define QMESSAGEBOX_STYLE "QLabel{color:rgb(108,167,191); font-weight:bold; font-size:20px; min-height:200px;} QPushButton{width:200 px; font-size:18px}"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/resources/img/Kain Wangi logo.png");
    ui->label_menuUtama->setPixmap(pix.scaled(380, 380, Qt::KeepAspectRatio));

    QPixmap mytag(":/resources/img/may_tag.png");
    ui->maytag_label->setPixmap(mytag.scaled(110, 110, Qt::KeepAspectRatio));
    ui->mytag_label2->setPixmap(mytag.scaled(110,110, Qt::KeepAspectRatio));

    ui->pushButton_ambilCucian->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_controlMesin->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_cuciKering->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_cuciLipat->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_cuciSetrika->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_addMemberCard->setStyleSheet(BUTTON_COLOR);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeChanged()));
    timer->start(1000);

    ui->timeLabel->setText("00:00");

    controlMesin = new ControlMesin(this);
//    tap = new TapCard_Window(this);
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

void MainWindow::onTimeChanged(){
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh:mm");
    if ((time.second() % 2) == 0){
        time_text[2] = ' ';
    }
    ui->timeLabel->setText(time_text);
}

void MainWindow::onStatusConnect(){
    if (!connectingElm.getStatus()){
//        QMessageBox::warning(this, "PERINGATAN..!", "GAGAL Menghubungkan GUI ke SERVER ELM!");
        QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "READER TIDAK TERHUBUNG!\n\nSilahkan matikan dan nyalakan kembali CASHIER!",
                           QMessageBox::Ok, this, Qt::FramelessWindowHint);
        msgBox.setStyleSheet(QMESSAGEBOX_STYLE);
        msgBox.exec();
        qDebug() << "Failed Connect to Server";
    } else {
//        tap->showFullScreen();
        cardReader->showFullScreen();
    }
}

void MainWindow::on_pushButton_cuciSetrika_clicked()
{
    QThread::sleep(1);
    paket = "1";
    connectingElm.StartConnection(paket);
    onStatusConnect();
}

void MainWindow::on_pushButton_cuciLipat_clicked()
{
    QThread::sleep(1);
    paket = "2";
    connectingElm.StartConnection(paket);
    onStatusConnect();
}

void MainWindow::on_pushButton_cuciKering_clicked()
{
    QThread::sleep(1);
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


QVector <QString> MainWindow::read_database_file(){
    //read file for database config
    QFile database_config("/var/elm/elm.conf");
    if (!database_config.exists()){
        QMessageBox::warning(this, "PERINGATAN!", "Failed read databaseconfig file(var/elm/elm.conf). error: " + database_config.errorString());
    } else {
        qDebug() << "Reading database ...";
    }

    QString line;
    QString hostName, port, userName, password, dbName;
    QVector <QString> db_setup;

    if (database_config.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&database_config);
        while(!stream.atEnd()){
            line = stream.readLine();
            if(line.split('=').first() == "PCDS_ADDRESS"){
                hostName = line.split('=').last();
                db_setup.append(hostName);
            }
            if(line.split('=').first() == "PCDS_PORT"){
                port = line.split('=').last();
                db_setup.append(port);
            }
            if(line.split('=').first() == "PCDS_DB"){
                dbName = line.split('=').last();
                db_setup.append(dbName);
            }
            if(line.split('=').first() == "PCDS_USER"){
                userName = line.split('=').last();
                db_setup.append(userName);
            }
            if(line.split('=').first() == "PCDS_PASSWD"){
                password = line.split('=').last();
                db_setup.append(password);
            }
        }
    }
    database_config.close();
    return db_setup;
}

void MainWindow::on_pushButton_controlMesin_clicked()
{
    //connect to database and get list mesin + list resi
    QVector <QString> db_setup;
    db_setup = read_database_file();
    if (!controlMesin->database_connect(db_setup[0], db_setup[1], db_setup[3], db_setup[4], db_setup[2])){
//        QMessageBox::warning(this, "PERINGATAN..!", "GAGAL Menghubungkan GUI ke DATABASE");
        QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "DATABASE TIDAK TERHUBUNG!\n\nSilahkan matikan dan nyalakan kembali CASHIER!",
                           QMessageBox::Ok, this, Qt::FramelessWindowHint);
        msgBox.setStyleSheet(QMESSAGEBOX_STYLE);
        msgBox.exec();
    } else {
        controlMesin->database_get_list_mesin();
        controlMesin->database_get_list_pending_transaksi();
        controlMesin->showFullScreen();
    }
}

void MainWindow::on_pushButton_addMemberCard_clicked()
{
    daftarWindow = new PendaftaranWindow(this);
    daftarWindow->showFullScreen();
}
