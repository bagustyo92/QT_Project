#include "controlmesin.h"
#include "ui_controlmesin.h"
#include <QMessageBox>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

#define BUTTON_COLOR "background-color:rgb(191, 210, 214); color:rgb(108, 167, 191); font-weight: bold;"
#define QMESSAGEBOX_STYLE "QLabel{color:rgb(108,167,191); font-weight:bold; font-size:20px; min-height:200px;} QPushButton{width:200 px; font-size:18px}"

#define GET_LIST_MESIN "SELECT * FROM get_list_mesin()"
#define GET_LIST_RESI "SELECT * FROM get_list_pending_transaksi()"

QVector <int> list_cuci_stat;
QVector <int> list_kering_stat;

ControlMesin::ControlMesin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControlMesin)
{
    ui->setupUi(this);

    ui->pushButton_cuci->setEnabled(false);
    ui->pushButton_kering->setEnabled(false);

    QString dir = QCoreApplication::applicationDirPath();
    qDebug() << dir;

    QPixmap pix(":/resources/img/Kain Wangi logo.png");
    ui->image_label->setPixmap(pix.scaled(380, 380, Qt::KeepAspectRatio));

    ui->listNomerMesin->setStyleSheet(BUTTON_COLOR);
    ui->listResi->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_3->setStyleSheet(BUTTON_COLOR);

    ui->listNomerMesin->addItem("SILAHKAN PILIH NOMER MESIN :");
    ui->listResi->addItem("SILAHKAN PILIH NOMER RESI :");
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

QString ControlMesin::database_user_login(QVector <QString> user_pwd){
    QSqlQuery query;
    QString status_action;

    query.prepare("SELECT login(:username, :password)");
    query.bindValue(":username", user_pwd[0]);
    query.bindValue(":password", user_pwd[1].toLocal8Bit().toHex());

    if (!query.exec()){
        qDebug() << "Query Statement login() error: " << query.lastError();
    }
    while(query.next()){
        status_action = query.value(0).toString();
        qDebug() << "Status: " << status_action;
    }
    return status_action;
}

QString ControlMesin::database_set_new_member(QVector <QString> new_member_data){
    qDebug() << "INSERTING DATA INTO insert_membercard_data() ...";

    QSqlQuery query;
    query.prepare("SELECT insert_membercard_data(:uid, :nama, :tgl_lahir, :alamat, :kelurahan, :kecamatan, :email, :noHP)");
    query.bindValue(":uid", new_member_data[0]);
    query.bindValue(":nama", new_member_data[1]);
    query.bindValue(":tgl_lahir", new_member_data[2]);
    query.bindValue(":alamat", new_member_data[3]);
    query.bindValue(":kelurahan", new_member_data[4]);
    query.bindValue(":kecamatan", new_member_data[5]);
    query.bindValue(":email", new_member_data[6]);
    query.bindValue(":noHP", new_member_data[7]);

    if (!query.exec()){
        qDebug() << "Query Statement insert_membercard_data() error: " << query.lastError();
    }
    QString status_action;
    while(query.next()){
        status_action = query.value(0).toString();
        qDebug() << "Status: " << status_action;
    }
    return status_action;
}

void ControlMesin::database_get_list_mesin(){
    ui->listNomerMesin->clear();
    QSqlQuery query;
    int total = 0;
//    query.exec(GET_LIST_MESIN);
    if (!query.exec(GET_LIST_MESIN)){
        qDebug() << "Query Statement get_list_mesin() error: " << query.lastError();
    }
//    ui->listNomerMesin->addItem("SILAHKAN PILIH MESIN :");
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
    QString status_action;
    while(query.next()){
        status_action = query.value(0).toString();
        qDebug() << "Status: " << status_action;
    }

    QString control_action;
    if (action == 1){
        control_action = "BERHASIL melakukan action CUCI!";
    } else if (action == 2){
        control_action = "BERHASIL melakukan action KERING!";
    }

    if (status_action == "OK CUCI" || status_action == "OK KERING"){ // <<==== What's the Reply Exactly?!
        QMessageBox info (QMessageBox::Information, "SUKSES!", control_action,
                          QMessageBox::Ok, this, Qt::FramelessWindowHint);
        info.setStyleSheet(QMESSAGEBOX_STYLE);
        info.exec();
        qDebug() << control_action;
        close();
    } else {
        QMessageBox info (QMessageBox::Information, "FAILED!", "Action Control GAGAL! Silahkan COBA LAGI!",
                          QMessageBox::Ok, this, Qt::FramelessWindowHint);
        info.setStyleSheet(QMESSAGEBOX_STYLE);
        info.exec();
        qDebug() << "FAILED to Action Control!";
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
//    ui->listResi->addItem("SILAHKAN PILIH RESI: ");
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
    QMessageBox *msgBox = new QMessageBox (QMessageBox::Question, "Konfirmasi PENGERINGAN Mesin " + ui->listNomerMesin->currentText(),
                       "Apakah anda yakin ingin melakukan \nPENGERINGAN pada MESIN-" + ui->listNomerMesin->currentText() +
                       "\nUntuk no. RESI-" + ui->listResi->currentText() + " ?", QMessageBox::Yes | QMessageBox::No,
                       this, Qt::FramelessWindowHint);
    msgBox->setStyleSheet(QMESSAGEBOX_STYLE);
    if (msgBox->exec() == QMessageBox::Yes){
        //Some Action Here
        database_control_mesin_action(2);

        ui->pushButton_cuci->setEnabled(false);
        ui->pushButton_kering->setEnabled(false);
//        close();
    } else {
        //Some Action Here
        qDebug() << "Cancel on button kering";
    }
}

void ControlMesin::on_pushButton_cuci_clicked()
{
//    some action here
//    QMessageBox::StandardButton reply = QMessageBox::Yes;
    QMessageBox *msgBox = new QMessageBox(QMessageBox::Question, "Konfirmasi PENCUCIAN Mesin " +
                       ui->listNomerMesin->currentText(), "Apakah anda yakin ingin melakukan \nPENCUCIAN pada MESIN-"
                       + ui->listNomerMesin->currentText() + "\nUntuk no. RESI-" + ui->listResi->currentText() + " ?",
                       QMessageBox::Yes | QMessageBox::No, this, Qt::FramelessWindowHint);
    msgBox->setStyleSheet(QMESSAGEBOX_STYLE);
    if (msgBox->exec() == QMessageBox::Yes){
        //Some Action Here
        database_control_mesin_action(1);

        ui->pushButton_cuci->setEnabled(false);
        ui->pushButton_kering->setEnabled(false);
//        close();
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
