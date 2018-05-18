#include "dialogcardreader.h"
#include "ui_dialogcardreader.h"
#include "mainwindow.h"
#include "controlmesin.h"
#include "pendaftaranwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QPixmap>
#include <QMovie>
#include <QThread>
#include <QVector>

#define BUTTON_COLOR "background-color:rgb(191, 210, 214); color:rgb(108, 167, 191); font-weight: bold;"
#define QMESSAGEBOX_REPLY_SIZE "QLabel{color:rgb(108,167,191); font-weight:bold; font-size:22px; min-height:300px;} QPushButton{width:200 px; font-size:18px}"
#define QMESSAGEBOX_STYLE "QLabel{color:rgb(108,167,191); font-weight:bold; font-size:20px; min-height:200px;} QPushButton{width:200 px; font-size:18px}"

DialogCardReader::DialogCardReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCardReader)
{
    ui->setupUi(this);
    ui->backButton->setStyleSheet(BUTTON_COLOR);

    QPixmap pix(":/resources/img/Kain Wangi logo.png");
    ui->image_label->setPixmap(pix.scaled(380, 380, Qt::KeepAspectRatio));

    ui->labelPicture->setText("SILAHKAN TEMPELKAN KARTU ANDA!");

    ui->nextButton->setEnabled(false);
    getConnection = new SocketConnectELM(this);
}

void DialogCardReader::show_server_reply(){
    QMessageBox *msgBox = new QMessageBox(QMessageBox::Information, "title", "STATUS TRANSAKSI :\n" + getConnection->getMessage(),
                                          QMessageBox::Ok, 0, Qt::FramelessWindowHint);
    msgBox->setStyleSheet(QMESSAGEBOX_REPLY_SIZE);
    if (msgBox->exec() == QMessageBox::Ok){
        this->close();
    }
}

void DialogCardReader::onServerReply(){
    PendaftaranWindow *newMember = new PendaftaranWindow(this);
    MainWindow *mainWindow = new MainWindow(this);
    ControlMesin *database = new ControlMesin(this);
    QString uid_card;
    QVector <QString> db_setup;
    QVector <QString> new_member_data;

    new_member_data = newMember->get_member_data();

    if (getConnection->getMessage() != "OK" && getConnection->getMessage() != ""){
        if (getConnection->getMessage() == "KARTU TIDAK DIKENAL"){
            QMessageBox reply (QMessageBox::Warning, "PERINGATAN..!", "Kartu yang Anda TAP TIDAK DIKENAL!\n\nSilahkan KEMBALI ke MENU UTAMA!",
                               QMessageBox::Ok, 0, Qt::FramelessWindowHint);
            reply.setStyleSheet(QMESSAGEBOX_STYLE);
            reply.exec();
        } else {
            if (getConnection->getMessage().split('=').first() == "SUKSES"){
                //get UID CARD
                uid_card = getConnection->getMessage().split('=').last();
                uid_card.rightJustified(10, '0');
                qDebug() << "UID_CARD: " << uid_card;
                new_member_data.insert(0, uid_card);

                //try connect to database
                db_setup = mainWindow->read_database_file();
                if (!database->database_connect(db_setup[0], db_setup[1], db_setup[3], db_setup[4], db_setup[2])){
                    QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "DATABASE TIDAK TERHUBUNG!\n\nSilahkan matikan dan nyalakan kembali CASHIER!",
                                       QMessageBox::Ok, 0, Qt::FramelessWindowHint);
                    msgBox.setStyleSheet(QMESSAGEBOX_STYLE);
                    msgBox.exec();
                } else {
                    QString status_database = database->database_set_new_member(new_member_data);
                    if (status_database == "OK INSERT"){
                        QMessageBox msgBox_newMember(QMessageBox::Information, "PERINGATAN..!", "SELAMAT!\n\nanda telah BERHASIL menambahkan MEMBER dan KARTU BARU!",
                                           QMessageBox::Ok, 0, Qt::FramelessWindowHint);
                        msgBox_newMember.setStyleSheet(QMESSAGEBOX_STYLE);
                        msgBox_newMember.exec();
                    } else if(status_database == "GAGAL INSERT") {
                        QMessageBox msgBox_newMember(QMessageBox::Warning, "PERINGATAN..!", "PERHATIAN!\n\nKARTU yang anda tap SUDAH TERDAFTAR atau DIKENAL!",
                                           QMessageBox::Ok, 0, Qt::FramelessWindowHint);
                        msgBox_newMember.setStyleSheet(QMESSAGEBOX_STYLE);
                        msgBox_newMember.exec();
                    } else {
                        QMessageBox msgBox_newMember(QMessageBox::Warning, "PERINGATAN..!", "GAGAL MENAMBAHKAN MEMBER BARU\n\nSilahkan matikan dan nyalakan kembali CASHIER!",
                                           QMessageBox::Ok, 0, Qt::FramelessWindowHint);
                        msgBox_newMember.setStyleSheet(QMESSAGEBOX_STYLE);
                        msgBox_newMember.exec();
                    }
                }
            } else {
                show_server_reply();
            }
        }
    }
}

DialogCardReader::~DialogCardReader()
{
    delete ui;
}

void DialogCardReader::on_backButton_clicked()
{
    char *val = "cancel";
    getConnection = new SocketConnectELM(this);
    getConnection->StartConnection(val);
    qDebug() << "cancel choosing packet";
}
