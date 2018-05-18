#include "pendaftaranwindow.h"
#include "ui_pendaftaranwindow.h"
#include "dialogcardreader.h"
#include <controlmesin.h>
#include <QDateEdit>
#include <QDebug>
#include <QMessageBox>
#include <WidgetKeyboard.h>
#include <QThread>

#define BUTTON_COLOR "background-color:rgb(191, 210, 214); color:rgb(108, 167, 191); font-weight: bold;"
#define QMESSAGEBOX_STYLE "QLabel{color:rgb(108,167,191); font-weight:bold; font-size:20px; min-height:200px;} QPushButton{width:200 px; font-size:18px}"

PendaftaranWindow::PendaftaranWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PendaftaranWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/resources/img/Kain Wangi logo.png");
    ui->pictureLabel->setPixmap(pix.scaled(250, 250, Qt::KeepAspectRatio));

    ui->backButton->setStyleSheet(BUTTON_COLOR);
    ui->nextButton->setStyleSheet(BUTTON_COLOR);

    QDateTime dt = QDateTime::currentDateTime();

    ui->dateEdit->setDisplayFormat("yyyy/MM/dd");
    ui->dateEdit->setDateTime(dt);

    ui->lineEdit_Name->setPlaceholderText("Nama");
    ui->lineEdit_Alamat->setPlaceholderText("Alamat");
    ui->lineEdit_email->setPlaceholderText("email@email.com");
    ui->lineEdit_kecamatan->setPlaceholderText("Kecamatan");
    ui->lineEdit_kelurahan->setPlaceholderText("Kelurahan");
    ui->lineEdit_nohape->setPlaceholderText("081234567890");
}

PendaftaranWindow::~PendaftaranWindow()
{
    delete ui;
}

QVector <QString> new_member;
QString nama,tglLahir, alamat, kelurahan, kecamatan, email, noHape;

void PendaftaranWindow::on_nextButton_clicked()
{
    nama = ui->lineEdit_Name->text();
    new_member.append(nama);
    tglLahir = ui->dateEdit->text();
    new_member.append(tglLahir);
    alamat = ui->lineEdit_Alamat->text();
    new_member.append(alamat);
    kelurahan = ui->lineEdit_kelurahan->text();
    new_member.append(kelurahan);
    kecamatan = ui->lineEdit_kecamatan->text();
    new_member.append(kecamatan);
    email = ui->lineEdit_email->text();
    new_member.append(email);
    noHape = ui->lineEdit_nohape->text();
    new_member.append(noHape);

    QRegExp regExp("\\d*"); //only number is allowed
    QRegExp noNumExp("\\D*"); //only word is allowed
    bool emailStat = false;

    if (nama == "" || tglLahir == "" || alamat == "" || kelurahan == "" || kecamatan == "" || email == "" || noHape == ""){
        QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "Seluruh kolom TIDAK BOLEH KOSONG!",
                           QMessageBox::Ok, this, Qt::FramelessWindowHint);
        msgBox.setStyleSheet(QMESSAGEBOX_STYLE);
        msgBox.exec();
        qDebug() << "All field must be NOT EMPTY!";
        emailStat = true;
    } else if (!noNumExp.exactMatch(nama) && emailStat == false){
        QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "Format NAMA yang anda masukan SALAH!\nFormat masukan TIDAK BOLEH ANGKA atau SIMBOL!",
                           QMessageBox::Ok, this, Qt::FramelessWindowHint);
        msgBox.setStyleSheet(QMESSAGEBOX_STYLE);
        msgBox.exec();
        qDebug() << "email field is wrong!";
    } else if (!email.contains("@") && emailStat == false){
        QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "Format E-MAIL yang anda masukan SALAH!",
                           QMessageBox::Ok, this, Qt::FramelessWindowHint);
        msgBox.setStyleSheet(QMESSAGEBOX_STYLE);
        msgBox.exec();
        qDebug() << "email field is wrong!";
    } else if (!email.contains(".") && emailStat == false){
        QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "Format E-MAIL yang anda masukan SALAH!",
                           QMessageBox::Ok, this, Qt::FramelessWindowHint);
        msgBox.setStyleSheet(QMESSAGEBOX_STYLE);
        msgBox.exec();
        qDebug() << "email field is wrong2!";
    } else if (!regExp.exactMatch(noHape) && emailStat == false){
        QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "Format NOMER HP yang anda masukan SALAH!\nFormat masukan HARUS ANGKA!",
                           QMessageBox::Ok, this, Qt::FramelessWindowHint);
        msgBox.setStyleSheet(QMESSAGEBOX_STYLE);
        msgBox.exec();
        qDebug() << "number field is wrong";
    } else {
        qDebug() << "Data Correct!";

        char *msg = "ADD_MEMBER";
        connectingElm = new SocketConnectELM(this);
        DialogCardReader *reader = new DialogCardReader(this);

        //KONFIRMASI DATA MASUKAN
        QMessageBox *msgBoxKonfirmasi = new QMessageBox (QMessageBox::Question, "Title", "Apakah data yang anda masukan telah VALID?",
                                                         QMessageBox::Yes | QMessageBox::No, this, Qt::FramelessWindowHint);
        msgBoxKonfirmasi->setStyleSheet(QMESSAGEBOX_STYLE);
        if (msgBoxKonfirmasi->exec() == QMessageBox::Yes){
            //sent MESSAGE TO SERVER
            connectingElm->StartConnection(msg);
            if (!connectingElm->getStatus()){
                QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "READER TIDAK TERHUBUNG!\nSilahkan matikan dan nyalakan kembali CASHIER!",
                                   QMessageBox::Ok, this, Qt::FramelessWindowHint);
                msgBox.setStyleSheet(QMESSAGEBOX_STYLE);
                msgBox.exec();
                qDebug() << "Failed Connect to Server";
            } else {
                reader->showFullScreen();
                close();
            }
        } else {
            qDebug() << "No Confirmation Data New Memeber";
        }
    }
}


QVector <QString> PendaftaranWindow::get_member_data(){
    return new_member;
}

