#include "controlmesin.h"
#include "ui_controlmesin.h"
#include <QMessageBox>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

#define BUTTON_COLOR "background-color:rgb(191, 210, 214); color:white; font-weight: bold;"

#define GET_LIST_MESIN "SELECT * FROM get_list_mesin()"
#define GET_LIST_RESI "SELECT * FROM get_list_pending_transaksi()"

QVector <int> list_cuci_stat;
QVector <int> list_kering_stat;

ControlMesin::ControlMesin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControlMesin)
{
    ui->setupUi(this);

    QString dir = QCoreApplication::applicationDirPath();
    qDebug() << dir;

    QPixmap pix(":/resources/img/Kain Wangi logo.png");
    ui->image_label->setPixmap(pix.scaled(380, 380, Qt::KeepAspectRatio));

    ui->listNomerMesin->setStyleSheet(BUTTON_COLOR);
    ui->listResi->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_3->setStyleSheet(BUTTON_COLOR);

    ui->pushButton_cuci->setEnabled(false);
    ui->pushButton_kering->setEnabled(false);
}


bool ControlMesin::database_connect(QString hostName, QString port, QString userName, QString password,QString dbName){
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(hostName);
    db.setPort(port.toInt());
    db.setUserName(userName);
    db.setPassword(password);
    db.setDatabaseName(dbName);
    bool ok = db.open();
    if (ok){
        qDebug() << "connected to database";
        return true;
    }else{
        qDebug() << "Failed connect to database";
        db.close();
        return false;
    }
}

void ControlMesin::database_get_list_mesin(){
    ui->listNomerMesin->clear();
    QSqlQuery query;
    int total = 0;
//    query.exec(GET_LIST_MESIN);
    if (!query.exec(GET_LIST_MESIN)){
        qDebug() << "Query Statement get_list_mesin() error: " << query.lastError();
    }
    while(query.next()){
        total += 1;
        QString nomesin = query.value("nomesin").toString();
        QString ipmesin = query.value("ipmesin").toString();
        ui->listNomerMesin->addItem(nomesin);
    }
    qDebug() << "GET LIST MESIN";
    qDebug() << "total mesin: " << total;
}

void ControlMesin::database_control_mesin_action(int action){
    QSqlQuery query;
    query.prepare("SELECT control_mesin(:nomesin, :resi, :action)");
    query.bindValue(":nomesin", ui->listNomerMesin->currentText());
    query.bindValue(":resi", ui->listResi->currentText());
    query.bindValue(":action", action);
//    query.exec();
    if (!query.exec()){
        qDebug() << "Query Statement control_mesin() error: " << query.lastError();
    }
    while(query.next()){
        QString status = query.value(0).toString();
        qDebug() << "Status: " << status;
    }
}

void ControlMesin::database_get_list_pending_transaksi(){
    list_cuci_stat.clear();
    list_kering_stat.clear();
    ui->listResi->clear();
    QSqlQuery query;
    int total = 0;
//    query.exec(GET_LIST_RESI);
    if (!query.exec(GET_LIST_RESI)){
        qDebug() << "Query Statement get_list_pending_transaksi() error: " << query.lastError();
    }
    while(query.next()){
        total += 1;
        QString noresi = query.value("resi").toString();
        int cuci_stat = query.value("cuci").toInt();
        int kering_stat = query.value("kering").toInt();
        list_cuci_stat.append(cuci_stat);
        list_kering_stat.append(kering_stat);
        ui->listResi->addItem(noresi);
    }
    qDebug() << "GET LIST RESI";
    qDebug() << "total resi: " << total;
}

ControlMesin::~ControlMesin()
{
    delete ui;
}

void ControlMesin::on_pushButton_3_clicked()
{
    ui->pushButton_cuci->setDisabled(true);
    ui->pushButton_kering->setDisabled(true);
}

void ControlMesin::on_pushButton_kering_clicked()
{
//    some Action Here
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Konfirmasi Pengeringan " +
                                                              ui->listNomerMesin->currentText(),
                                                              "Apakah anda yakin ingin melakukan \nPENGERINGAN pada "
                                                              + ui->listNomerMesin->currentText() + "?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply==QMessageBox::Yes){
        //Some Action Here
        database_control_mesin_action(2);
        QMessageBox::information(this, "SUKSES!", "Berhasil Melakukan KERING!");
        close();
    } else {
        //Some Action Here
        qDebug() << "Cancel on button kering";
    }
}

void ControlMesin::on_pushButton_cuci_clicked()
{
//    some action here
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Konfirmasi Pencucian " +
                                                              ui->listNomerMesin->currentText(),
                                                              "Apakah anda yakin ingin melakukan \nPENCUCIAN pada "
                                                              + ui->listNomerMesin->currentText() + "?",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes){
        //Some Action Here
        database_control_mesin_action(1);
        QMessageBox::information(this, "SUKSES!", "Berhasil Melakukan CUCI!");
        close();
    } else {
        //Some Action Here
        qDebug() << "Cancel on button cuci";
    }
}

void ControlMesin::on_listResi_activated(const QString &arg1)
{
    if (list_cuci_stat[ui->listResi->currentIndex()] == 1){
        ui->pushButton_cuci->setEnabled(true);
    } else {
        ui->pushButton_cuci->setEnabled(false);
    }
    if (list_kering_stat[ui->listResi->currentIndex()] == 1){
        ui->pushButton_kering->setEnabled(true);
    } else {
        ui->pushButton_kering->setEnabled(false);
    }
}
