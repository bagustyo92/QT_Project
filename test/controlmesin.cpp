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

ControlMesin::ControlMesin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControlMesin)
{
    ui->setupUi(this);

    QString dir = QCoreApplication::applicationDirPath();
    qDebug() << dir;

    QPixmap pix(":/resources/img/Kain Wangi logo.png");
    ui->image_label->setPixmap(pix.scaled(380, 380, Qt::KeepAspectRatio));

    ui->pushButton_cuci->setDisabled(true);
    ui->pushButton_kering->setDisabled(true);

    ui->listNomerMesin->setStyleSheet(BUTTON_COLOR);
    ui->listResi->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_3->setStyleSheet(BUTTON_COLOR);
}

QSqlDatabase* ControlMesin::database_connect(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("172.16.2.200");
    db.setPort(5432);
    db.setUserName("enco");
    db.setPassword("encoreader14");
    db.setDatabaseName("dbenco");
    bool ok = db.open();
    if (ok){
        qDebug() << "connected to database";
        return &db;
    }else{
        qDebug() << "Failed connect to database";
        db.close();
    }
}

void ControlMesin::database_get_list_mesin(){
    QSqlQuery query;
    int total = 0;
    query.exec(GET_LIST_MESIN);
    if (!query.exec(GET_LIST_MESIN)){
        qDebug() << "Query Statement get_list_mesin() error: " << query.lastError();
    }
    while(query.next()){
        total += 1;
        QString nomesin = query.value("nomesin").toString();
        QString ipmesin = query.value("ipmesin").toString();
        qDebug() << "No: " << nomesin <<  " | Ip: " << ipmesin;
        ui->listNomerMesin->addItem(nomesin);
    }
    qDebug() << "total mesin: " << total;
}

void ControlMesin::database_control_mesin_action(int action){
    QSqlQuery query;
    query.prepare("SELECT control_mesin(:nomesin, :resi, :action)");
    query.bindValue(":nomesin", ui->listNomerMesin->currentText());
    query.bindValue(":resi", ui->listResi->currentText());
    query.bindValue(":action", action);
}

void ControlMesin::database_get_list_pending_transaksi(){
    QSqlQuery query;
    int total = 0;
    query.exec(GET_LIST_RESI);
    if (!query.exec(GET_LIST_RESI)){
        qDebug() << "Query Statement get_list_pending_transaksi() error: " << query.lastError();
    }
    while(query.next()){
        total += 1;
        QString noresi = query.value("resi").toString();
        int cuci_stat = query.value("cuci").toInt();
        int kering_stat = query.value("kering").toInt();
        qDebug() << "No Resi: " << noresi <<  " | cuci_status: " << cuci_stat << " | kering_status: " << kering_stat;
        ui->listResi->addItem(noresi);
    }
    qDebug() << "total resi: " << total;
}

ControlMesin::~ControlMesin()
{
    delete ui;
}


void ControlMesin::on_listNomerMesin_activated(const QString &arg1)
{
    ui->pushButton_cuci->setDisabled(false);
    ui->pushButton_kering->setDisabled(false);
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
    } else {
        //Some Action Here
        qDebug() << "Cancel on button cuci";
    }
}
